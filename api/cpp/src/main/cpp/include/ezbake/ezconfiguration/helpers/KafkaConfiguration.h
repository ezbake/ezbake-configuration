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
 * KafkaConfiguration.h
 *
 *  Created on: Mar 31, 2014
 *      Author: oarowojolu
 */

#ifndef EZBAKE_EZCONFIGURATION_HELPERS_KAFKACONFIGURATION_H_
#define EZBAKE_EZCONFIGURATION_HELPERS_KAFKACONFIGURATION_H_

#include <ezbake/ezconfiguration/helpers/BaseConfiguration.h>

namespace ezbake { namespace ezconfiguration { namespace helpers {

class KafkaConfiguration: public BaseConfiguration {
public:
    static const ::std::string KAFKA_7_ZOOKEEPER_PROP;
    static const ::std::string KAFKA_8_ZOOKEEPER_PROP;
    static const ::std::string KAFKA_CONSUMER_TIMEOUT_PROP;
    static const ::std::string KAFKA_BROKER_LIST_PROP;

public:
    typedef enum {
        KAFKA_7,
        KAFKA_8
    }KafkaVersion;

public:
    inline ::std::string getZookeepers(KafkaVersion kaftaVersion) {
        return ((kaftaVersion == KAFKA_7) ? ezConfiguration.getString(parseKey(KAFKA_7_ZOOKEEPER_PROP), "") :
                                            ezConfiguration.getString(parseKey(KAFKA_8_ZOOKEEPER_PROP), ""));
    }

    inline ::std::string getBrokerList() {
        return ezConfiguration.getString(parseKey(KAFKA_BROKER_LIST_PROP), "");
    }

    inline ::std::string getConsumerTimeout() {
        return ezConfiguration.getString(parseKey(KAFKA_CONSUMER_TIMEOUT_PROP), "");
    }

    static ::boost::shared_ptr<KafkaConfiguration> fromConfiguration(const ::ezbake::ezconfiguration::EZConfiguration& configuration,
            const ::std::string& namespacePrefix = "") {
        ::boost::shared_ptr<KafkaConfiguration> p(new KafkaConfiguration(configuration, namespacePrefix));
        return p;
    }

    virtual ~KafkaConfiguration() {}

private:
    KafkaConfiguration(const ::ezbake::ezconfiguration::EZConfiguration& configuration,
            const ::std::string& namespacePrefix)
        : BaseConfiguration(configuration, namespacePrefix) {}
};

}}} //namespace ::ezbake::ezconfiguration::helpers

#endif /* EZBAKE_EZCONFIGURATION_HELPERS_KAFKACONFIGURATION_H_ */
