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

import sys
import jinja2
import glob
import os
import argparse
from collections import OrderedDict
import abc
from shutil import copyfile, rmtree

EXTENSIONS = {'python' : 'py', 'documentation' : 'html'}
TYPES = ["boolean", "float", "long", "string", "int", "double", "array"]

class Constant(object):

	def __init__(self, variableName, propertyName, type, description, defaultValue=None):
		self.variableName = variableName
		self.propertyName = propertyName
		if type in TYPES:
			self.type = type
		else:
			raise Exception("Type '" + type + "' not supported in " + variableName)
		self.defaultValue = defaultValue
		self.description = description
		
	def __str__(self):
		return self.variableName + "|" + self.propertyName + "|" + self.type + \
		("|" + self.defaultValue if self.defaultValue else '') + "|" + self.description

class HelperPlugin(object):
	__metaclass__ = abc.ABCMeta

	@abc.abstractmethod
	def generate(self, group, constants):
		return

def main(argv):

    #Get templates from templates/ folder, and build our allowed gen languages from that
    genTypes = []
    for template in glob.glob("templates/*.template"):
        gen = os.path.basename(template).split('.template')[0]
    	genTypes.append(gen) 
    genTypes += [file for file in os.listdir('templates') if os.path.isdir("templates/" + file)]

    parser = argparse.ArgumentParser(description="Generate constants in different languages from a constants file")
    parser.add_argument("constants_file", metavar="constants-file", help="Required: Location of constants template file")
    parser.add_argument("gen", help="Required: The type of constants to generate", choices=genTypes)
    parser.add_argument("-o", "--output-dir", help="The output location, defaults to gen-(gen).(gen)", default=None)
    parser.add_argument("-H", "--helper", nargs="*", metavar="GROUP", help="Runs helper.main(group, constants[group])", default=None)
    
    parameters = parser.parse_args()

    gen = parameters.gen
    constantsFile = parameters.constants_file
    output = parameters.output_dir if parameters.output_dir else "gen-" + gen + "." + (EXTENSIONS.get(gen) if EXTENSIONS.get(gen) else gen)
    # template = gen + ".template"
    
    constants = processConstantsFile(constantsFile)

    if parameters.helper:
    	try:
    		import helper
    	except (NameError, ImportError) as e:
    		raise NameError("Error importing helper file: " + str(e))
    	for group in parameters.helper:
    		groupCons = constants.get(group)
    		if groupCons == None:
    			raise Exception("Constant group " + group + " does not exist or has no constants")
	    	helper.Helper().generate(group, constants[group])

    processTemplate(constants, output, gen)

def processConstantsFile(inputFile):
	"""
	Process constants from a file, and returns a dictionary of the constants
	"""
	constants = OrderedDict() #To keep order in constants file
	text = open(inputFile).readlines()
	lastGroup = ''
	for line in text:
		line = line.split('#', 1)[0].strip()
		if len(line) == 0:
			continue
		elif line.startswith('[') and line.endswith(']'):
			lastGroup = line[1:-1]
			constants[lastGroup] = []
		else:
			split = line.split('|')
			if len(split) == 5:
				cons = Constant(split[0], split[1], split[2], split[4], split[3])
				constants[lastGroup].append(cons)
			elif len(split) == 4: 
				cons = Constant(split[0], split[1], split[2], split[3])
				constants[lastGroup].append(cons)
			else:
				raise Exception("Not enough arguments: " + line)

	return OrderedDict(constants.items()) #Reverses dict

def processTemplate(constants, output, gen):
	if os.path.isfile("templates/" + gen + ".template"):
		if os.path.exists(gen):
			raise Exception("Can't have " + gen +".template and " + gen + "directory in templates/")
		jinja = jinja2.Environment(trim_blocks=True, loader=jinja2.PackageLoader('ezconfiguration_constants_generator', 'templates'))
		if os.path.isdir(output):
			rmtree(output)
		out = open(output, 'w')
		template = jinja.get_template(gen + ".template")
		out.write(template.render(constants=constants))
		out.close()
	elif os.path.exists("templates/" + gen):
		output = os.path.splitext(output)[0]
		if os.path.exists(output):
			rmtree(output)
		processTemplateDirectory(constants, output , "templates/"+gen, )
	else:
		raise Exception("error finding template")

def processTemplateDirectory(constants, output, directory):
	files = [f for f in os.listdir(directory) if f[0] != '.']
	if not os.path.isdir(output):
		os.makedirs(output)
	for file in files:
		src = os.path.join(directory, file)
		dst = os.path.join(output, file)
		if os.path.isdir(src):
			processTemplateDirectory(constants, dst, src)
		elif src.endswith(".template"):
			jinja = jinja2.Environment(trim_blocks=True, loader=jinja2.FileSystemLoader(os.path.dirname(src)))
			out = open(dst.split(".template")[0], 'w')
			template = jinja.get_template(os.path.basename(src))
			out.write(template.render(constants=constants))
			out.close
		else:
			copyfile(src, dst)

if __name__ == "__main__": 
	main(sys.argv)