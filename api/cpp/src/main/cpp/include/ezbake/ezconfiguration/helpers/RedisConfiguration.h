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
 * RedisConfiguration.h
 *
 *  Created on: Mar 31, 2014
 *      Author: oarowojolu
 */

#ifndef EZBAKE_EZCONFIGURATION_HELPERS_REDISCONFIGURATION_H_
#define EZBAKE_EZCONFIGURATION_HELPERS_REDISCONFIGURATION_H_

#include <ezbake/ezconfiguration/helpers/BaseConfiguration.h>

namespace ezbake { namespace ezconfiguration { namespace helpers {

class RedisConfiguration: public BaseConfiguration {
public:
    static const ::std::string REDIS_HOST_KEY;
    static const ::std::string REDIS_PORT_KEY;

private:
    static const int DEFAULT_REDIS_PORT = 6379;

public:
    inline ::std::string getRedisHost() {
        return ezConfiguration.getString(parseKey(REDIS_HOST_KEY), "");
    }

    inline int getRedisPort() {
        return ezConfiguration.getInt(parseKey(REDIS_PORT_KEY), DEFAULT_REDIS_PORT);
    }

    static ::boost::shared_ptr<RedisConfiguration> fromConfiguration(const ::ezbake::ezconfiguration::EZConfiguration& configuration,
            const ::std::string& namespacePrefix = "") {
        ::boost::shared_ptr<RedisConfiguration> p(new RedisConfiguration(configuration, namespacePrefix));
        return p;
    }

    virtual ~RedisConfiguration() {}

private:
    RedisConfiguration(const ::ezbake::ezconfiguration::EZConfiguration& configuration,
            const ::std::string& namespacePrefix)
        : BaseConfiguration(configuration, namespacePrefix) {}
};

}}} // namespace ezbake::ezconfiguration::helpers

#endif /* EZBAKE_EZCONFIGURATION_HELPERS_REDISCONFIGURATION_H_ */
