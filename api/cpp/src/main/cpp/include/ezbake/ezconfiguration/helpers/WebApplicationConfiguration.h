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
 * WebApplicationConfiguration.h
 *
 *  Created on: Mar 31, 2014
 *      Author: oarowojolu
 */

#ifndef EZBAKE_EZCONFIGURATION_HELPERS_WEBAPPLICATIONCONFIGURATION_H_
#define EZBAKE_EZCONFIGURATION_HELPERS_WEBAPPLICATIONCONFIGURATION_H_

#include <ezbake/ezconfiguration/helpers/BaseConfiguration.h>

namespace ezbake { namespace ezconfiguration { namespace helpers {

class WebApplicationConfiguration: public BaseConfiguration {
public:
    static const ::std::string WEB_APPLICATION_EXTERNAL_DOMAIN_KEY;
    static const ::std::string WEB_APPLICATION_METRICS_ENDPOINT_KEY;
    static const ::std::string WEB_APPLICATION_METRICS_SITEID_KEY;

public:
    ::std::string getExternalFacingDomain() {
        return ezConfiguration.getString(parseKey(WEB_APPLICATION_EXTERNAL_DOMAIN_KEY), "");
    }

    ::std::string getMetricsRESTEndpoint() {
        return ezConfiguration.getString(parseKey(WEB_APPLICATION_METRICS_ENDPOINT_KEY), "");
    }

    ::std::string getMetricsSiteId() {
        return ezConfiguration.getString(parseKey(WEB_APPLICATION_METRICS_SITEID_KEY), "");
    }

    static ::boost::shared_ptr<WebApplicationConfiguration> fromConfiguration(const ::ezbake::ezconfiguration::EZConfiguration& configuration,
            const ::std::string& namespacePrefix = "") {
        ::boost::shared_ptr<WebApplicationConfiguration> p(new WebApplicationConfiguration(configuration, namespacePrefix));
        return p;
    }

    virtual ~WebApplicationConfiguration() {}

private:
    WebApplicationConfiguration(const ::ezbake::ezconfiguration::EZConfiguration& configuration,
            const ::std::string& namespacePrefix)
        : BaseConfiguration(configuration, namespacePrefix) {}
};

}}} // namespace ::ezbake::ezconfiguration::helpers

#endif /* EZBAKE_EZCONFIGURATION_HELPERS_WEBAPPLICATIONCONFIGURATION_H_ */
