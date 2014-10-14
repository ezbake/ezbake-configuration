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
 * ApplicationConfiguration.h
 *
 *  Created on: Mar 21, 2014
 *      Author: oarowojolu
 */

#ifndef EZBAKE_EZCONFIGURATION_HELPERS_APPLICATIONCONFIGURATION_H_
#define EZBAKE_EZCONFIGURATION_HELPERS_APPLICATIONCONFIGURATION_H_

#include <ezbake/ezconfiguration/helpers/BaseConfiguration.h>

namespace ezbake { namespace ezconfiguration { namespace helpers {

class ApplicationConfiguration: public BaseConfiguration {
public:
    static const ::std::string APPLICATION_NAME_KEY;
    static const ::std::string APPLICATION_VERSION_KEY;
    static const ::std::string SERVICE_NAME_KEY;
    static const ::std::string SECURITY_ID_KEY;
    static const ::std::string CERTIFICATES_DIRECTORY_KEY;

private:
    static const char APPLICATION_SERVICE_SEPERATOR = '_';

public:
    inline ::std::string getApplicationName() {
        return ezConfiguration.getString(parseKey(APPLICATION_NAME_KEY), "");
    }

    inline ::std::string getApplicationVersion() {
        return ezConfiguration.getString(parseKey(APPLICATION_VERSION_KEY), "");
    }

    inline ::std::string getServiceName() {
        return ezConfiguration.getString(parseKey(SERVICE_NAME_KEY), "");
    }

    inline ::std::string getSecurityID() {
        return ezConfiguration.getString(parseKey(SECURITY_ID_KEY), "");
    }

    inline ::std::string getCertificatesDir() {
        return ezConfiguration.getString(parseKey(CERTIFICATES_DIRECTORY_KEY), "");
    }

    inline static ::std::string getApplicationServiceName(const ::std::string& applicationName, const ::std::string& serviceName) {
        return applicationName + APPLICATION_SERVICE_SEPERATOR + serviceName;
    }

    static ::boost::shared_ptr<ApplicationConfiguration> fromConfiguration(const ::ezbake::ezconfiguration::EZConfiguration& configuration,
            const ::std::string& namespacePrefix = "") {
        ::boost::shared_ptr<ApplicationConfiguration> p(new ApplicationConfiguration(configuration, namespacePrefix));
        return p;
    }

    virtual ~ApplicationConfiguration() {}

private:
    ApplicationConfiguration(const ::ezbake::ezconfiguration::EZConfiguration& configuration,
            const ::std::string& namespacePrefix)
        : BaseConfiguration(configuration, namespacePrefix) {}

};

}}} // namespace ::ezbake::ezconfiguration::helpers

#endif /* EZBAKE_EZCONFIGURATION_HELPERS_APPLICATIONCONFIGURATION_H_ */
