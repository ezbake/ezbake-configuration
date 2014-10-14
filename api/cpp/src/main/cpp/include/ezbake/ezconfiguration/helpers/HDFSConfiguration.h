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
 * HDFSConfiguration.h
 *
 *  Created on: Mar 31, 2014
 *      Author: oarowojolu
 */

#ifndef EZBAKE_EZCONFIGURATION_HELPERS_HDFSCONFIGURATION_H_
#define EZBAKE_EZCONFIGURATION_HELPERS_HDFSCONFIGURATION_H_

#include <ezbake/ezconfiguration/helpers/BaseConfiguration.h>

namespace ezbake { namespace ezconfiguration { namespace helpers {

class HDFSConfiguration: public BaseConfiguration {
public:
    static const ::std::string FILESYSTEM_NAME;
    static const ::std::string FILESYSTEM_IMPL;
    static const ::std::string FILESYSTEM_USE_LOCAL;

public:
    inline ::boost::optional< ::std::string> getFileSystemName() {
        return get(FILESYSTEM_NAME);
    }

    inline ::std::string getFileSystemNameWithDefault() {
        return ezConfiguration.getString(parseKey(FILESYSTEM_NAME), "hdfs://127.0.0.1:8020");
    }

    inline bool getUseLocal() {
        return ezConfiguration.getBoolean(parseKey(FILESYSTEM_USE_LOCAL), false);
    }

    inline ::std::string getFileSystemImpl() {
        return ezConfiguration.getString(parseKey(FILESYSTEM_IMPL), "org.apache.hadoop.hdfs.DistributedFileSystem");
    }

    static ::boost::shared_ptr<HDFSConfiguration> fromConfiguration(const ::ezbake::ezconfiguration::EZConfiguration& configuration,
            const ::std::string& namespacePrefix = "") {
        ::boost::shared_ptr<HDFSConfiguration> p(new HDFSConfiguration(configuration, namespacePrefix));
        return p;
    }

    virtual ~HDFSConfiguration() {}

private:
    HDFSConfiguration(const ::ezbake::ezconfiguration::EZConfiguration& configuration,
            const ::std::string& namespacePrefix)
        : BaseConfiguration(configuration, namespacePrefix) {}
};

}}} // namespace ::ezbake::ezconfiguration::helpers

#endif /* EZBAKE_EZCONFIGURATION_HELPERS_HDFSCONFIGURATION_H_ */
