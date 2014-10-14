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
 * ElasticsearchConfiguration.h
 *
 *  Created on: Mar 31, 2014
 *      Author: oarowojolu
 */

#ifndef EZBAKE_EZCONFIGURATION_HELPERS_ELASTICSEARCHCONFIGURATION_H_
#define EZBAKE_EZCONFIGURATION_HELPERS_ELASTICSEARCHCONFIGURATION_H_

#include <ezbake/ezconfiguration/helpers/BaseConfiguration.h>

namespace ezbake { namespace ezconfiguration { namespace helpers {

class ElasticsearchConfiguration: public BaseConfiguration {
public:
    static const ::std::string ELASTICSEARCH_HOST;
    static const ::std::string ELASTICSEARCH_PORT;
    static const ::std::string ELASTICSEARCH_CLUSTER_NAME;
    static const ::std::string ELASTICSEARCH_FORCE_REFRESH_ON_PUT;

public:
    ::std::string getElasticsearchHost() {
        return ezConfiguration.getString(parseKey(ELASTICSEARCH_HOST), "");
    }

    int getElasticsearchPort() {
        return ezConfiguration.getInt(parseKey(ELASTICSEARCH_PORT), 9200);
    }

    ::std::string getElasticsearchClusterName() {
        return ezConfiguration.getString(parseKey(ELASTICSEARCH_CLUSTER_NAME), "");
    }

    bool getForceRefresh() {
        return ezConfiguration.getBoolean(parseKey(ELASTICSEARCH_FORCE_REFRESH_ON_PUT), false);
    }

    static ::boost::shared_ptr<ElasticsearchConfiguration> fromConfiguration(const ::ezbake::ezconfiguration::EZConfiguration& configuration,
            const ::std::string& namespacePrefix = "") {
        ::boost::shared_ptr<ElasticsearchConfiguration> p(new ElasticsearchConfiguration(configuration, namespacePrefix));
        return p;
    }

    virtual ~ElasticsearchConfiguration() {}

private:
    ElasticsearchConfiguration(const ::ezbake::ezconfiguration::EZConfiguration& configuration,
            const ::std::string& namespacePrefix)
        : BaseConfiguration(configuration, namespacePrefix) {}
};

}}} // namespace ::ezbake::ezconfiguration::helpers

#endif /* EZBAKE_EZCONFIGURATION_HELPERS_ELASTICSEARCHCONFIGURATION_H_ */
