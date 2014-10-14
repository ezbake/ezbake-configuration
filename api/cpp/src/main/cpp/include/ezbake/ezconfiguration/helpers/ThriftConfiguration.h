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
 * ThriftConfiguration.h
 *
 *  Created on: Mar 21, 2014
 *      Author: oarowojolu
 */

#ifndef EZBAKE_EZCONFIGURATION_HELPERS_THRIFTCONFIGURATION_H_
#define EZBAKE_EZCONFIGURATION_HELPERS_THRIFTCONFIGURATION_H_

#include <ezbake/ezconfiguration/helpers/BaseConfiguration.h>

namespace ezbake { namespace ezconfiguration { namespace helpers {

class ThriftConfiguration: public BaseConfiguration {
public:
    class ThriftServerMode {
    friend class ThriftConfiguration;
    public:
        virtual ~ThriftServerMode() {}

        bool isBlocking() const {
            return _isBlocking;
        }

        const ::std::string& toString() const {
            return _name;
        }

        bool operator==(const ThriftServerMode& rhs) const {
            return ((_isBlocking == rhs._isBlocking) && (_name == rhs._name));
        }

        bool operator!=(const ThriftServerMode& rhs) const {
            return !(*this == rhs);
        }

        static ThriftServerMode valueOf(const ::std::string& val) {
            ThriftServerMode mode = Simple;
            if (HsHa._name == val) {
                mode = HsHa;
            } else if (ThreadedPool._name == val) {
                mode = ThreadedPool;
            } else if (Simple._name != val){
                BOOST_THROW_EXCEPTION(std::invalid_argument(val + " is not a supported thrift server mode"));
            }
            return mode;
        }

    private:
        ThriftServerMode(const ::std::string& name, bool isBlocking)
            : _name(name), _isBlocking(isBlocking) {}
        ::std::string _name;
        bool _isBlocking;
    };
    friend class ThriftServerMode;

public:
    static const ::std::string USE_SSL;
    static const ::std::string SERVER_MODE;
    static const ::std::string MAX_IDLE_CLIENTS;
    static const ::std::string MAX_POOL_CLIENTS;
    static const ::std::string MILLIS_BETWEEN_CLIENT_EVICTION_CHECKS;
    static const ::std::string MILLIS_IDLE_BEFORE_EVICTION;
    static const ::std::string TEST_ON_BORROW;
    static const ::std::string TEST_WHILE_IDLE;

    static const ThriftServerMode Simple;
    static const ThriftServerMode HsHa;
    static const ThriftServerMode ThreadedPool;

public:

    inline bool useSSL() {
        return ezConfiguration.getBoolean(USE_SSL, true);
    }

    inline ThriftServerMode getServerMode() {
        return ThriftServerMode::valueOf(ezConfiguration.getString(SERVER_MODE, "Simple"));
    }

    inline int getMaxIdleClients() {
        return ezConfiguration.getInt(MAX_IDLE_CLIENTS, 10);
    }

    inline long getMillisBetweenClientEvictionChecks() {
        return ezConfiguration.getLong(MILLIS_BETWEEN_CLIENT_EVICTION_CHECKS, 30*1000);
    }

    inline long getMillisIdleBeforeEviction() {
        return ezConfiguration.getLong(MILLIS_IDLE_BEFORE_EVICTION, 2*60*1000);
    }

    inline int getMaxPoolClients() {
        return ezConfiguration.getInt(MAX_POOL_CLIENTS, 10);
    }

    inline bool getTestOnBorrow() {
        return ezConfiguration.getBoolean(TEST_ON_BORROW, false);
    }

    inline bool getTestWhileIdle() {
        return ezConfiguration.getBoolean(TEST_WHILE_IDLE, false);
    }

    static boost::shared_ptr<ThriftConfiguration> fromConfiguration(const ::ezbake::ezconfiguration::EZConfiguration& configuration,
            const ::std::string& namespacePrefix = "") {
        boost::shared_ptr<ThriftConfiguration> p(new ThriftConfiguration(configuration, namespacePrefix));
        return p;
    }

    virtual ~ThriftConfiguration() {}

private:
    ThriftConfiguration(const ::ezbake::ezconfiguration::EZConfiguration& configuration,
            const ::std::string& namespacePrefix)
        : BaseConfiguration(configuration, namespacePrefix) {}
};

}}} // namespace ezbake::ezconfiguration::helpers

#endif /* EZBAKE_EZCONFIGURATION_HELPERS_THRIFTCONFIGURATION_H_ */
