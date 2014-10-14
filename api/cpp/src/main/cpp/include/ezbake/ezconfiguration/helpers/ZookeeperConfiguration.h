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
 * ZookeeperConfiguration.h
 *
 *  Created on: Mar 19, 2014
 *      Author: oarowojolu
 */

#ifndef EZBAKE_EZCONFIGURATION_HELPERS_ZOOKEEPERCONFIGURATION_H_
#define EZBAKE_EZCONFIGURATION_HELPERS_ZOOKEEPERCONFIGURATION_H_

#include <ezbake/ezconfiguration/helpers/BaseConfiguration.h>

namespace ezbake { namespace ezconfiguration { namespace helpers {

class ZookeeperConfiguration : public BaseConfiguration {
public:
    static const ::std::string ZOOKEEPER_CONNECTION_KEY;

public:
    ::std::string getZookeeperConnectionString() {
        return ezConfiguration.getString(parseKey(ZOOKEEPER_CONNECTION_KEY), "");
    }

    static ::boost::shared_ptr<ZookeeperConfiguration> fromConfiguration(const ::ezbake::ezconfiguration::EZConfiguration& configuration,
            const ::std::string& namespacePrefix = "") {
        ::boost::shared_ptr<ZookeeperConfiguration> p(new ZookeeperConfiguration(configuration, namespacePrefix));
        return p;
    }

    virtual ~ZookeeperConfiguration() {}

private:
    ZookeeperConfiguration(const ::ezbake::ezconfiguration::EZConfiguration& configuration,
            const ::std::string& namespacePrefix)
        : BaseConfiguration(configuration, namespacePrefix) {}
};

}}} // namespace ::ezbake::ezconfiguration::helpers

#endif /* EZBAKE_EZCONFIGURATION_HELPERS_ZOOKEEPERCONFIGURATION_H_ */
