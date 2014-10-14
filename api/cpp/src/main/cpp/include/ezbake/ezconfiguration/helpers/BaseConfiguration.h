/*   Copyright (C) 2013-2014 Computer Sciences Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License. */

/*
 * BaseConfiguration.h
 *
 *  Created on: Mar 19, 2014
 *      Author: oarowojolu
 */

#ifndef EZBAKE_EZCONFIGURATION_HELPERS_BASECONFIGURATION_H_
#define EZBAKE_EZCONFIGURATION_HELPERS_BASECONFIGURATION_H_

#include <ezbake/ezconfiguration/EZConfiguration.h>
#include <boost/format.hpp>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <iostream>


namespace ezbake { namespace ezconfiguration { namespace helpers {

class BaseConfiguration : public boost::noncopyable {
public:
    BaseConfiguration(const ::ezbake::ezconfiguration::EZConfiguration& configuration,
            const ::std::string& namespacePrefix = "")
        : ezConfiguration(configuration), namespacePrefix(namespacePrefix) {}

    virtual ~BaseConfiguration() {}

    ::boost::optional< ::std::string> get(const ::std::string& key) const {
        return ezConfiguration.get(parseKey(key));
    }

protected:
    ::std::string parseKey(const ::std::string& key) const {
        return (namespacePrefix.find_first_not_of(' ') == ::std::string::npos) ? key :
                (::boost::format("%s.%s") % namespacePrefix % key).str();
    }

protected:
    ::ezbake::ezconfiguration::EZConfiguration ezConfiguration;
    ::std::string namespacePrefix;
};

}}} // namespace ::ezbake::ezconfiguration::helpers

#endif /* EZBAKE_EZCONFIGURATION_HELPERS_BASECONFIGURATION_H_ */
