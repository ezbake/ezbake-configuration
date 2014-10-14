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
 * FlumeConfiguration.h
 *
 *  Created on: Mar 31, 2014
 *      Author: oarowojolu
 */

#ifndef EZBAKE_EZCONFIGURATION_HELPERS_FLUMECONFIGURATION_H_
#define EZBAKE_EZCONFIGURATION_HELPERS_FLUMECONFIGURATION_H_

#include <ezbake/ezconfiguration/helpers/BaseConfiguration.h>
#include <boost/tokenizer.hpp>
#include <boost/foreach.hpp>

namespace ezbake { namespace ezconfiguration { namespace helpers {

class FlumeConfiguration: public BaseConfiguration {
public:
    static const ::std::string KEY_BATCH_SIZE;
    static const ::std::string KEY_MAX_EVENTS;
    static const ::std::string KEY_MAX_BACKOFF;
    static const ::std::string KEY_MAX_ATTEMPTS;
    static const ::std::string KEY_HEADERS;
    static const ::std::string KEY_AGENT_TYPE;
    static const ::std::string KEY_HOSTS;
    static const ::std::string KEY_HOST_SELECTOR;
    static const ::std::string KEY_RUN_INTERVAL;
    static const ::std::string KEY_SLEEP_INTERVAL;
    static const ::std::string KEY_CONNECT_ATTEMPTS;
    static const ::std::string KEY_CONNECT_TIMEOUT;
    static const ::std::string KEY_REQUEST_TIMEOUT;
    static const ::std::string KEY_BACK_OFF;

private:
    static const int DEFAULT_BATCH_SIZE = 100;
    static const int DEFAULT_MAX_EVENTS = 10000;
    static const int DEFAULT_MAX_ATTEMPTS = 2;
    static const int DEFAULT_CONNECT_ATTEMPTS = 10;

    static const long long DEFAULT_RUN_INTERVAL = 1000;
    static const long long DEFAULT_SLEEP_INTERVAL = 3000;
    static const long long DEFAULT_CONNECT_TIMEOUT = 20000;
    static const long long DEFAULT_REQUEST_TIMEOUT = 20000;
    static const long long DEFAULT_MAX_BACKOFF = 0;

    static const ::std::string DEFAULT_HEADERS;
    static const ::std::string DEFAULT_AGENT_TYPE;
    static const ::std::string DEFAULT_HOSTS;
    static const ::std::string DEFAULT_HOST_SELECTOR;

    static const bool DEFAULT_BACK_OFF = false;

public:
    inline int getBatchSize() {
        return ezConfiguration.getInt(parseKey(KEY_BATCH_SIZE), DEFAULT_BATCH_SIZE);
    }

    inline int getMaxEvents() {
        return ezConfiguration.getInt(parseKey(KEY_MAX_EVENTS), DEFAULT_MAX_EVENTS);
    }

    inline int getMaxAttempts() {
        return ezConfiguration.getInt(parseKey(KEY_MAX_ATTEMPTS), DEFAULT_MAX_ATTEMPTS);
    }

    inline int getConnectAttempts() {
        return ezConfiguration.getInt(parseKey(KEY_CONNECT_ATTEMPTS), DEFAULT_CONNECT_ATTEMPTS);
    }

    inline long long getRunInterval() {
        return ezConfiguration.getLong(parseKey(KEY_RUN_INTERVAL), DEFAULT_RUN_INTERVAL);
    }

    inline long long getSleepInterval() {
        return ezConfiguration.getLong(parseKey(KEY_SLEEP_INTERVAL), DEFAULT_SLEEP_INTERVAL);
    }

    inline long long getConnectTimeout() {
        return ezConfiguration.getLong(parseKey(KEY_CONNECT_TIMEOUT), DEFAULT_CONNECT_TIMEOUT);
    }

    inline long long getRequestTimeout() {
        return ezConfiguration.getLong(parseKey(KEY_REQUEST_TIMEOUT), DEFAULT_REQUEST_TIMEOUT);
    }

    inline long long getMaxBackoff() {
        return ezConfiguration.getLong(parseKey(KEY_MAX_BACKOFF), DEFAULT_MAX_BACKOFF);
    }

    inline ::std::string getHeaders() {
        return ezConfiguration.getString(parseKey(KEY_HEADERS), DEFAULT_HEADERS);
    }

    inline ::std::string getAgentType() {
        return ezConfiguration.getString(parseKey(KEY_AGENT_TYPE), DEFAULT_AGENT_TYPE);
    }

    inline ::std::string getHosts() {
        return ezConfiguration.getString(parseKey(KEY_HOSTS), DEFAULT_HOSTS);
    }

    inline ::std::string getHostSelector() {
        return ezConfiguration.getString(parseKey(KEY_HOST_SELECTOR), DEFAULT_HOST_SELECTOR);
    }

    inline bool getBackoff() {
        return ezConfiguration.getBoolean(parseKey(KEY_BACK_OFF), DEFAULT_BACK_OFF);
    }

    inline ::ezbake::ezconfiguration::util::PropertiesUtil::Properties getHostProperties() {
        return _hostProperties;
    }

    void setHostProperties(const ::std::string& sHosts) {
        ::boost::tokenizer< ::boost::char_separator<char> > hostTokens(sHosts, ::boost::char_separator<char>(" "));
        BOOST_FOREACH(const ::std::string& host, hostTokens) {
            ::std::string propName = "hosts." + host;
            _hostProperties[host] = ezConfiguration.getString(parseKey(propName), "");
        }
    }

    ::ezbake::ezconfiguration::util::PropertiesUtil::Properties getProperties() {
        _properties[KEY_BATCH_SIZE] = getBatchSize();
        _properties[KEY_MAX_EVENTS] = getMaxEvents();
        _properties[KEY_MAX_ATTEMPTS] = getMaxAttempts();
        _properties[KEY_CONNECT_ATTEMPTS] = getConnectAttempts();

        _properties[KEY_RUN_INTERVAL] = getRunInterval();
        _properties[KEY_SLEEP_INTERVAL] = getSleepInterval();
        _properties[KEY_CONNECT_TIMEOUT] = getConnectTimeout();
        _properties[KEY_REQUEST_TIMEOUT] = getRequestTimeout();
        _properties[KEY_MAX_BACKOFF] = getMaxBackoff();

        _properties[KEY_HEADERS] = getHeaders();
        _properties[KEY_AGENT_TYPE] = getAgentType();
        _properties[KEY_HOSTS] = getHosts();
        _properties[KEY_HOST_SELECTOR] = getHostSelector();

        _properties[KEY_BACK_OFF] = getBackoff();

        setHostProperties(getHosts());
        return _properties;
    }

    static ::boost::shared_ptr<FlumeConfiguration> fromConfiguration(const ::ezbake::ezconfiguration::EZConfiguration& configuration,
            const ::std::string& namespacePrefix = "") {
        ::boost::shared_ptr<FlumeConfiguration> p(new FlumeConfiguration(configuration, namespacePrefix));
        return p;
    }

    virtual ~FlumeConfiguration() {}

private:
    FlumeConfiguration(const ::ezbake::ezconfiguration::EZConfiguration& configuration,
            const ::std::string& namespacePrefix)
        : BaseConfiguration(configuration, namespacePrefix) {}

    static ::ezbake::ezconfiguration::util::PropertiesUtil::Properties _properties;
    static ::ezbake::ezconfiguration::util::PropertiesUtil::Properties _hostProperties;
};

}}} // namespace ::ezbake::ezconfiguration::helpers

#endif /* EZBAKE_EZCONFIGURATION_HELPERS_FLUMECONFIGURATION_H_ */
