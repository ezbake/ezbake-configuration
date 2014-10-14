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
 * SystemConfiguration.h
 *
 *  Created on: Mar 21, 2014
 *      Author: oarowojolu
 */

#ifndef EZBAKE_EZCONFIGURATION_HELPERS_SYSTEMCONFIGURATION_H_
#define EZBAKE_EZCONFIGURATION_HELPERS_SYSTEMCONFIGURATION_H_

#include <ezbake/ezconfiguration/helpers/ApplicationConfiguration.h>

namespace ezbake { namespace ezconfiguration { namespace helpers {

class SystemConfiguration: public BaseConfiguration {
public:
    static const ::std::string EZBAKE_LOG_DIRECTORY;
    static const ::std::string EZBAKE_LOG_TO_STDOUT;
    static const ::std::string EZBAKE_ADMIN_APPLICATION_DEPLOYMENT;
    static const ::std::string FILE_SEPERATOR;

public:
    inline ::std::string getLogDirectory() {
        return get(EZBAKE_LOG_DIRECTORY).get_value_or("/tmp");
    }

    ::std::string getLogFilePath(const ::std::string& applicationName, const ::std::string& serviceName) {
        if (serviceName.find_first_not_of(' ') == ::std::string::npos) {
            BOOST_THROW_EXCEPTION(std::invalid_argument("serviceName must not be blank!!"));
        }

        const ::std::string logext = ".log";
        ::std::string fileName, path = getLogDirectory();

        if (applicationName.find_first_not_of(' ') != ::std::string::npos) {
            path += FILE_SEPERATOR + applicationName;
            fileName = ApplicationConfiguration::getApplicationServiceName(applicationName, serviceName) + logext;
        } else {
            path += FILE_SEPERATOR + serviceName;
            fileName = serviceName + logext;
        }

        return path + FILE_SEPERATOR + fileName;
    }

    inline bool shouldLogToStdOut() {
        return ezConfiguration.getBoolean(parseKey(EZBAKE_LOG_TO_STDOUT), false);
    }

    inline bool isAdminApplicationDeployment() {
        return ezConfiguration.getBoolean(parseKey(EZBAKE_ADMIN_APPLICATION_DEPLOYMENT), false);
    }

    static boost::shared_ptr<SystemConfiguration> fromConfiguration(const ::ezbake::ezconfiguration::EZConfiguration& configuration,
            const ::std::string& namespacePrefix = "") {
        boost::shared_ptr<SystemConfiguration> p(new SystemConfiguration(configuration, namespacePrefix));
        return p;
    }

    virtual ~SystemConfiguration() {}

private:
    SystemConfiguration(const ::ezbake::ezconfiguration::EZConfiguration& configuration,
            const ::std::string& namespacePrefix)
        : BaseConfiguration(configuration, namespacePrefix) {}
};

}}} // namespace ::ezbake::ezconfiguration::helpers

#endif /* EZBAKE_EZCONFIGURATION_HELPERS_SYSTEMCONFIGURATION_H_ */
