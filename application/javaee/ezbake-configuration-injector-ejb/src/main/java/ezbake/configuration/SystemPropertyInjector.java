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

package ezbake.configuration;

import ezbake.configuration.EzConfiguration;
import ezbake.configuration.EzConfigurationLoaderException;

import java.util.Properties;
import javax.annotation.PostConstruct;
import javax.ejb.PostActivate;
import javax.ejb.Singleton;
import javax.ejb.Startup;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

@Singleton
@Startup
@SuppressWarnings("unused")
public class SystemPropertyInjector {

    private final Logger logger = LoggerFactory.getLogger(SystemPropertyInjector.class);

    @PostConstruct
    public void startup() {
        EzConfiguration configuration;
        try {
            configuration = new EzConfiguration();
        } catch(EzConfigurationLoaderException e) {
            logger.error("Unable to load properties from EzConfiguration", e);
            // If we can't load from ezconfiguration then we do not want to continue
            throw new RuntimeException(e);
        }
        Properties properties = configuration.getProperties();

        // Add EzBake properties to the system properties. Don't call
        // System.setProperties since that replaces all of the existing system
        // properties with our own, even the ones that aren't overridden.
        for (String name : properties.stringPropertyNames()) {
            System.setProperty(name, properties.getProperty(name));
        }
    }
}
