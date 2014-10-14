#   Copyright (C) 2013-2014 Computer Sciences Corporation
#
#   Licensed under the Apache License, Version 2.0 (the "License");
#   you may not use this file except in compliance with the License.
#   You may obtain a copy of the License at
#
#       http://www.apache.org/licenses/LICENSE-2.0
#
#   Unless required by applicable law or agreed to in writing, software
#   distributed under the License is distributed on an "AS IS" BASIS,
#   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#   See the License for the specific language governing permissions and
#   limitations under the License.

import getopt
import traceback

class Parameter(object):
    
    def __init__(self, programName, options=None, additonalUsage=None):
    # opts[key] = [ 0 short name, 1 long name, 2 help message, 3 argument needed, 4 required ]
        self.__programName = programName
        self.__options = options
        self.__additonalUssage = additonalUsage
        if self.__options is  None:
            self.__options = {}
        if "help" not in self.__options:
            opts["help"] = [ "h", "help", "Prints help message.", False, False]
            
    def addOption(self, shortArgument, longArgument, helpMsg, takesAnArgumnet, optional):
        self.__options[longArgument] = [ shortArgument, longArgument, helpMsg, takesAnArgumnet, not optional]


    def checkArgs(self):
        checker = []
        for key in self.__options:
            o = self.__options[key]
            if o[0] in checker or o[1] in checker:
                print "Repeat argument: " + o[0] + " and/or " + o[1]
            checker.append(o[0])
            checker.append(o[1])

    def printUsage(self, returnValue=0):
        print "USAGE: " + self.__programName + " [options]"
        print "\nOptions:"
            
        key1 = sorted(filter(lambda x: self.__options[x][4], self.__options.keys()))
        key2 = sorted(filter(lambda x: not self.__options[x][4], self.__options.keys()))
        for key in key1 + key2:
            opt = self.__options[key]
            print "\t-" + opt[0] + " --" + opt[1] +  ("\t\t(optional) " if not opt[4] else "\t\t") + opt[2]
        if self.__additonalUssage is not None:
            self.__additonalUssage()

        return returnValue

    def setArguments(self, argv):
        shortOption= "".join(map(lambda x: x[0] + (lambda y: ":" if y else "")(x[3]), self.__options.values()))
        longOption = map(lambda x: x[1] + (lambda y: "=" if y else "")(x[3]), self.__options.values())

        try:
            options, args = getopt.getopt(argv, shortOption, longOption)
        except:
            print "Incorrect option presented"
            #traceback.print_exc()
            return self.printUsage(1)

        for o in filter(lambda x: not self.__options[x][3], self.__options):
            setattr(self, o, False)
        for o in filter(lambda x:  self.__options[x][3], self.__options):
            setattr(self, o, None)

        for opt, arg in options:
            opt = (lambda x: x[1:] if len(x) == 2 else x[2:])(opt)
            if opt in self.__options['help'][:2]:
                setattr(self, 'help', True)
                return self.printUsage()
            for key in self.__options:
                if opt in self.__options[key][:2]:
                    if self.__options[key][3]:
                        setattr(self, key, arg)
                    else:
                        setattr(self, key, True)


