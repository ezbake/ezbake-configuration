# EzBake Configuration Java EE Support

This sub-project provides an integration point between EzBake Configuration and Java EE containers.

## Configuration Injector Bean

The configuration injector bean is an EJB that injects EzBake Configuration properties into Java EE applications as system properties when the application starts. This allows application writers to not explicitly pull in EzBake Configuration code and wait until runtime before depending on the package.

To use in JBoss or WildFly, add the module as a dependency to the application's `jboss-deployment-structure.xml`. A minimal `jboss-deployment-structure.xml` might appear like:

    <jboss-deployment-structure>
      <deployment>
        <dependencies>
          <module name="ezbake.configuration" annotations="true"/>
        </dependencies>
      </deployment>
    </jboss-deployment-structure>

The recommended way of using the bean is to have EzBake Deployer put a `jboss-deployment-structure.xml` into the application's war if the file does not exist already. A copy of the file exists in `ezbake-configuration-injector-ejb/doc/jboss-deployment-structure.xml`.

To configure the module in JBoss AS7, create a directory `${JBOSS_HOME}/modules/ezbake/configuration/main`. Copy the EJB and its EzBake dependencies to the directory. Create a file `module.xml` in the directory with the contents:

    <?xml version="1.0" encoding="UTF-8"?>

    <module xmlns="urn:jboss:module:1.1" name="ezbake.configuration">
        <resources>
            <resource-root path="commons-lang3-3.3.2.jar"/>
            <resource-root path="ezbake-common-2.0-SNAPSHOT.jar"/>
            <resource-root path="ezbake-configuration-api-2.0-SNAPSHOT.jar"/>
            <resource-root path="ezbake-configuration-constants-2.0-SNAPSHOT.jar"/>
            <resource-root path="ezbake-configuration-injector-ejb-2.0-SNAPSHOT.jar"/>
            <resource-root path="guava-17.0.jar"/>
            <resource-root path="jasypt-1.9.2.jar"/>
        </resources>

        <dependencies>
            <module name="javax.api"/>
            <module name="javax.ejb.api"/>
            <module name="org.slf4j"/>
        </dependencies>
    </module>

A copy of the file exists in `ezbake-configuration-injector-ejb/doc/jboss-module.xml`. This file, and the bean's dependencies, should be able to be generated automatically, but for the time being, we use `mvn dependency::copy-dependencies` to gather the required jars.

For WildFly, the destination directory is `${WILDFLY_HOME}/modules/system/layers/base/ezbake/configuration/main`.
