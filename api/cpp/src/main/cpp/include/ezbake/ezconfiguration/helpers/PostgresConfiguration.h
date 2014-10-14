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
 * PostgresConfiguration.h
 *
 *  Created on: Mar 31, 2014
 *      Author: oarowojolu
 */

#ifndef EZBAKE_EZCONFIGURATION_HELPERS_POSTGRESCONFIGURATION_H_
#define EZBAKE_EZCONFIGURATION_HELPERS_POSTGRESCONFIGURATION_H_

#include <ezbake/ezconfiguration/helpers/BaseConfiguration.h>
#include <map>

extern "C" {
extern char **environ;
}


namespace ezbake { namespace ezconfiguration { namespace helpers {

class PostgresConfiguration: public BaseConfiguration {
public:
    static const ::std::string POSTGRES_HOST;
    static const ::std::string POSTGRES_PORT;
    static const ::std::string POSTGRES_USERNAME;
    static const ::std::string POSTGRES_PASSWORD;
    static const ::std::string POSTGRES_DB;


public:
    inline ::std::string getHost() {
        return lookup(POSTGRES_HOST, "OPENSHIFT_POSTGRESQL_DB_HOST");
    }

    inline ::std::string getPort() {
        return lookup(POSTGRES_PORT, "OPENSHIFT_POSTGRESQL_DB_PORT");
    }

    inline ::std::string getUsername() {
        return lookup(POSTGRES_USERNAME, "OPENSHIFT_POSTGRESQL_DB_USERNAME");
    }

    inline ::std::string getPassword() {
        return lookup(POSTGRES_PASSWORD, "OPENSHIFT_POSTGRESQL_DB_PASSWORD");
    }

    inline ::std::string getDatabase() {
        return lookup(POSTGRES_DB, "PGDATABASE");
    }

    inline ::std::string getConnectionUrl() {
        return "postgresql://" + getHost() + ":" + getPort();
    }

    static ::boost::shared_ptr<PostgresConfiguration> fromConfiguration(const ::ezbake::ezconfiguration::EZConfiguration& configuration,
            const ::std::string& namespacePrefix = "") {
        ::boost::shared_ptr<PostgresConfiguration> p(new PostgresConfiguration(configuration, namespacePrefix));
        return p;
    }

    virtual ~PostgresConfiguration() {}


protected:
    inline void setEnvironment(::std::map< ::std::string, ::std::string>& environment) {
        _environment = environment;
    }


private:
    ::std::string lookup(const ::std::string& ezKey, const ::std::string& envVar) {
        ::boost::optional< ::std::string> value = get(ezKey);
        if (value) {
            return value.get();
        }

        //get the value from environment, if value doesn't exist, create blank value and return
        return _environment[envVar];
    }

    PostgresConfiguration(const ::ezbake::ezconfiguration::EZConfiguration& configuration,
            const ::std::string& namespacePrefix)
        : BaseConfiguration(configuration, namespacePrefix) {
        for (char **itr = environ; *itr; itr++) {
            ::std::string env(*itr);
            size_t delim = env.find("=");
            if (delim != ::std::string::npos) {
                _environment[env.substr(0, delim)] = env.substr(delim + 1);
            }
        }
    }

private:
    ::std::map< ::std::string, ::std::string> _environment;
};

}}} // namespace ::ezbake::ezconfiguration::ezconfiguration

#endif /* EZBAKE_EZCONFIGURATION_HELPERS_POSTGRESCONFIGURATION_H_ */
