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
 * OpenShiftConfiguration.h
 *
 *  Created on: Mar 21, 2014
 *      Author: oarowojolu
 */

#ifndef EZBAKE_EZCONFIGURATION_HELPERS_OPENSHIFTCONFIGURATION_H_
#define EZBAKE_EZCONFIGURATION_HELPERS_OPENSHIFTCONFIGURATION_H_

#include <ezbake/ezconfiguration/helpers/BaseConfiguration.h>
#include <cstdlib>

namespace ezbake { namespace ezconfiguration { namespace helpers {

class OpenShiftConfiguration {
public:
    static const OpenShiftConfiguration OPENSHIFT_APP_DNS;
    static const OpenShiftConfiguration OPENSHIFT_APP_NAME;
    static const OpenShiftConfiguration OPENSHIFT_APP_UUID;
    static const OpenShiftConfiguration OPENSHIFT_DATA_DIR;
    static const OpenShiftConfiguration OPENSHIFT_GEAR_DNS;
    static const OpenShiftConfiguration OPENSHIFT_GEAR_NAME;
    static const OpenShiftConfiguration OPENSHIFT_GEAR_UUID;
    static const OpenShiftConfiguration OPENSHIFT_HOMEDIR;
    static const OpenShiftConfiguration OPENSHIFT_REPO_DIR;
    static const OpenShiftConfiguration OPENSHIFT_TMP_DIR;
    static const OpenShiftConfiguration OPENSHIFT_JAVA_THRIFTRUNNER_IP;
    static const OpenShiftConfiguration OPENSHIFT_JAVA_THRIFTRUNNER_TCP_PORT;
    static const OpenShiftConfiguration OPENSHIFT_JAVA_THRIFTRUNNER_TCP_PROXY_PORT;

public:
    virtual ~OpenShiftConfiguration() {}

    inline ::std::string getEnvName() const {
        return _name;
    }

    inline ::std::string getEnvValue(const ::std::string& defaultValue = "") const {
        char * envPtr = std::getenv(_name.c_str());
        return envPtr ? envPtr : defaultValue;
    }

private:
    OpenShiftConfiguration(const ::std::string& name)
        : _name(name) {}

    ::std::string _name;
};

}}} // namespace ::ezbake::ezconfiguration::helpers

#endif /* EZBAKE_EZCONFIGURATION_HELPERS_OPENSHIFTCONFIGURATION_H_ */
