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
 * MongoDBConfiguration.h
 *
 *  Created on: Mar 31, 2014
 *      Author: oarowojolu
 */

#ifndef EZBAKE_EZCONFIGURATION_HELPERS_MONGODBCONFIGURATION_H_
#define EZBAKE_EZCONFIGURATION_HELPERS_MONGODBCONFIGURATION_H_

#include <ezbake/ezconfiguration/helpers/BaseConfiguration.h>

namespace ezbake { namespace ezconfiguration { namespace helpers {

class MongoDBConfiguration: public BaseConfiguration {
public:
    static const ::std::string MONGODB_HOST_NAME_KEY;
    static const ::std::string MONGODB_DB_NAME_KEY;
    static const ::std::string MONGODB_USER_NAME_KEY;
    static const ::std::string MONGODB_PASSWORD_KEY;
    static const ::std::string MONGODB_USE_SSL_KEY;

public:
    inline ::std::string getMongoDBHostName() {
        return ezConfiguration.getString(parseKey(MONGODB_HOST_NAME_KEY), "");
    }

    inline ::std::string getMongoDBDatabaseName() {
        return ezConfiguration.getString(parseKey(MONGODB_DB_NAME_KEY), "");
    }

    inline ::std::string getMongoDBUserName() {
        return ezConfiguration.getString(parseKey(MONGODB_USER_NAME_KEY), "");
    }

    inline ::std::string getMongoDBPassword() {
        return ezConfiguration.getString(parseKey(MONGODB_PASSWORD_KEY), "");
    }

    inline bool useMongoDBSSL() {
        return ezConfiguration.getBoolean(parseKey(MONGODB_USE_SSL_KEY), false);
    }

    static ::boost::shared_ptr<MongoDBConfiguration> fromConfiguration(const ::ezbake::ezconfiguration::EZConfiguration& configuration,
            const ::std::string& namespacePrefix = "") {
        ::boost::shared_ptr<MongoDBConfiguration> p(new MongoDBConfiguration(configuration, namespacePrefix));
        return p;
    }

    virtual ~MongoDBConfiguration() {}

private:
    MongoDBConfiguration(const ::ezbake::ezconfiguration::EZConfiguration& configuration,
            const ::std::string& namespacePrefix)
        : BaseConfiguration(configuration, namespacePrefix) {}
};

}}} // namespace ::ezbake::ezconfiguration::helpers

#endif /* EZBAKE_EZCONFIGURATION_HELPERS_MONGODBCONFIGURATION_H_ */
