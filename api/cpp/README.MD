EzConfiguration (c++)
=================

Our c++ EzConfiguration implementation

Dependencies
------------
* boost libraries
* log4cxx
* openssl (ssl & crypto)

Maven Integration
-----------------
This module uses the [NAR Maven plugin](http://maven-nar.github.io/index.html). This pulgin enables the use of Maven for handling dependencies (automatically including other library {.so, .o, .a, etc} files that were build with the maven plugin) and continous integration.


Building with MAVEN
-------------------
```
mvn build
```
- build and compile all sources in src/main/c++

```
make test
```
- build and compile all sources in src/main/c++
- build and compile all test sources in src/test/c++
- link all object (shared, static) files and create a binary app
- run the test app (utapp)

Importing
---------
Options in including this library in your project:

1. Using maven
Add this module's libary as a dependency to your module

```
<dependencies>
	<dependency>
		<groupId>ezbake</groupId>
    	<artifactId>ezConfiguration</artifactId>
        <version>${ezbake.version}</version>
        <type>nar</type>
    </dependency>
</dependencies>
```




