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
 * AccumuloConfiguration.h
 *
 *  Created on: Mar 21, 2014
 *      Author: oarowojolu
 */

#ifndef EZBAKE_EZCONFIGURATION_HELPERS_ACCUMULOCONFIGURATION_H_
#define EZBAKE_EZCONFIGURATION_HELPERS_ACCUMULOCONFIGURATION_H_

#include <ezbake/ezconfiguration/helpers/BaseConfiguration.h>

namespace ezbake { namespace ezconfiguration { namespace helpers {

class AccumuloConfiguration: public BaseConfiguration {
public:
    static const ::std::string ACCUMULO_INSTANCE_NAME_KEY;
    static const ::std::string ACCUMULO_ZOOKEEPERS_KEY;
    static const ::std::string ACCUMULO_USE_MOCK_KEY;
    static const ::std::string ACCUMULO_USERNAME_KEY;
    static const ::std::string ACCUMULO_PASSWORD_KEY;
    static const ::std::string ACCUMULO_USE_SSL;
    static const ::std::string ACCUMULO_SSL_TRUSTSTORE_PATH;
    static const ::std::string ACCUMULO_SSL_TRUSTSTORE_TYPE;
    static const ::std::string ACCUMULO_SSL_TRUSTSTORE_PASSWORD;

public:
    inline ::std::string getAccumuloInstance() {
        return ezConfiguration.getString(parseKey(ACCUMULO_INSTANCE_NAME_KEY), "");
    }

    inline ::std::string getZookeepers() {
        return ezConfiguration.getString(parseKey(ACCUMULO_ZOOKEEPERS_KEY), "");
    }

    inline bool useMock() {
        return ezConfiguration.getBoolean(parseKey(ACCUMULO_USE_MOCK_KEY), false);
    }

    inline ::std::string getUsername() {
        return ezConfiguration.getString(parseKey(ACCUMULO_USERNAME_KEY), "");
    }

    inline ::std::string getPassword() {
        return ezConfiguration.getString(parseKey(ACCUMULO_PASSWORD_KEY), "");
    }

    static ::boost::shared_ptr<AccumuloConfiguration> fromConfiguration(const ::ezbake::ezconfiguration::EZConfiguration& configuration,
            const ::std::string& namespacePrefix = "") {
        ::boost::shared_ptr<AccumuloConfiguration> p(new AccumuloConfiguration(configuration, namespacePrefix));
        return p;
    }

    virtual ~AccumuloConfiguration() {}

private:
    AccumuloConfiguration(const ::ezbake::ezconfiguration::EZConfiguration& configuration,
            const ::std::string& namespacePrefix)
        : BaseConfiguration(configuration, namespacePrefix) {}
};

}}} // namespace ::ezbake::ezconfiguration::helpers

#endif /* EZBAKE_EZCONFIGURATION_HELPERS_ACCUMULOCONFIGURATION_H_ */
