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
 * CommonServices.h
 *
 *  Created on: Mar 21, 2014
 *      Author: oarowojolu
 */

#ifndef EZBAKE_EZCONFIGURATION_HELPERS_COMMONSERVICES_H_
#define EZBAKE_EZCONFIGURATION_HELPERS_COMMONSERVICES_H_

namespace ezbake { namespace ezconfiguration { namespace helpers {

/**
 * A set of common services names
 */
class CommonServices {
public:
    static const ::std::string DATAWAREHOUSE;
    static const ::std::string INTERNAL_NAME_SERVICE;
    static const ::std::string EZSECURITY;
    static const ::std::string EZSECURITY_REGISTRATION;
    static const ::std::string SSR;
    static const ::std::string CAPCO;
    static const ::std::string DOCUMENT_EXTRACTION;
    static const ::std::string ENTITY_EXTRACTION;
    static const ::std::string GEOSPATIAL_EXTRACTION;
    static const ::std::string SELECTOR_EXTRACTION;
    static const ::std::string TEMPORAL_NORMALIZER;
    static const ::std::string IMAGE_METADATA_EXTRACTION;
    static const ::std::string IMAGE_INDEXER;

public:
    virtual ~CommonServices() {}
};

}}} // namespace ::ezbake::ezconfiguration::helpers

#endif /* EZBAKE_EZCONFIGURATION_HELPERS_COMMONSERVICES_H_ */
