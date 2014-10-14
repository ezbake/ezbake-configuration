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
 * ConfigurationConstants.cpp
 *
 *  Created on: Mar 21, 2014
 *      Author: oarowojolu
 */

#include <ezbake/ezconfiguration/helpers/all.h>

namespace ezbake { namespace ezconfiguration { namespace helpers {

const ::std::string AccumuloConfiguration::ACCUMULO_INSTANCE_NAME_KEY = "accumulo.instance.name";
const ::std::string AccumuloConfiguration::ACCUMULO_ZOOKEEPERS_KEY = "accumulo.zookeepers";
const ::std::string AccumuloConfiguration::ACCUMULO_USE_MOCK_KEY = "accumulo.use.mock";
const ::std::string AccumuloConfiguration::ACCUMULO_USERNAME_KEY = "accumulo.username";
const ::std::string AccumuloConfiguration::ACCUMULO_PASSWORD_KEY = "accumulo.password";
// (type: boolean) Property which specifies if accumulo clients should use SSL
const ::std::string AccumuloConfiguration::ACCUMULO_USE_SSL = "accumulo.use.ssl";
// (type: string) Property which specifies the path to the accumulo truststore
const ::std::string AccumuloConfiguration::ACCUMULO_SSL_TRUSTSTORE_PATH = "accumulo.ssl.truststore.path";
// (type: string) Property which specifies the type of the accumulo truststore
const ::std::string AccumuloConfiguration::ACCUMULO_SSL_TRUSTSTORE_TYPE = "accumulo.ssl.truststore.type";
// (type: string) Property which specifies the password for the accumulo truststore
const ::std::string AccumuloConfiguration::ACCUMULO_SSL_TRUSTSTORE_PASSWORD = "accumulo.ssl.truststore.password";


const ::std::string ApplicationConfiguration::APPLICATION_NAME_KEY = "application.name";
const ::std::string ApplicationConfiguration::APPLICATION_VERSION_KEY = "application.version";
const ::std::string ApplicationConfiguration::SERVICE_NAME_KEY = "service.name";
const ::std::string ApplicationConfiguration::SECURITY_ID_KEY = "ezbake.security.app.id";
const ::std::string ApplicationConfiguration::CERTIFICATES_DIRECTORY_KEY = "ezbake.security.ssl.dir";


const ::std::string CommonServices::DATAWAREHOUSE = "warehaus";
const ::std::string CommonServices::INTERNAL_NAME_SERVICE = "ins";
const ::std::string CommonServices::EZSECURITY = "EzbakeSecurityService";
const ::std::string CommonServices::EZSECURITY_REGISTRATION = "EzSecurityRegistration";
const ::std::string CommonServices::SSR = "ssrService";
const ::std::string CommonServices::CAPCO = "CapcoService";
const ::std::string CommonServices::DOCUMENT_EXTRACTION = "docextract";
const ::std::string CommonServices::ENTITY_EXTRACTION = "entityextract";
const ::std::string CommonServices::GEOSPATIAL_EXTRACTION = "geosvc";
const ::std::string CommonServices::SELECTOR_EXTRACTION = "selext";
const ::std::string CommonServices::TEMPORAL_NORMALIZER = "temporalsvc";
const ::std::string CommonServices::IMAGE_METADATA_EXTRACTION = "imagemetadataextractionservice";
const ::std::string CommonServices::IMAGE_INDEXER = "imageindexingservice";


const ::std::string ElasticsearchConfiguration::ELASTICSEARCH_HOST = "elastic.host.name";
const ::std::string ElasticsearchConfiguration::ELASTICSEARCH_PORT = "elastic.port";
const ::std::string ElasticsearchConfiguration::ELASTICSEARCH_CLUSTER_NAME = "elastic.cluster.name";
const ::std::string ElasticsearchConfiguration::ELASTICSEARCH_FORCE_REFRESH_ON_PUT = "elastic.force.refresh";


const ::std::string FlumeConfiguration::KEY_BATCH_SIZE = "batch-size";
const ::std::string FlumeConfiguration::KEY_MAX_EVENTS = "max-events";
const ::std::string FlumeConfiguration::KEY_MAX_BACKOFF = "max-backoff";
const ::std::string FlumeConfiguration::KEY_MAX_ATTEMPTS = "max-attempts";
const ::std::string FlumeConfiguration::KEY_HEADERS = "headers";
const ::std::string FlumeConfiguration::KEY_AGENT_TYPE = "agent-type";
const ::std::string FlumeConfiguration::KEY_HOSTS = "hosts";
const ::std::string FlumeConfiguration::KEY_HOST_SELECTOR = "host-selector";
const ::std::string FlumeConfiguration::KEY_RUN_INTERVAL = "run-interval";
const ::std::string FlumeConfiguration::KEY_SLEEP_INTERVAL = "sleep-interval";
const ::std::string FlumeConfiguration::KEY_CONNECT_ATTEMPTS = "connect-attempts";
const ::std::string FlumeConfiguration::KEY_CONNECT_TIMEOUT = "connect-timeout";
const ::std::string FlumeConfiguration::KEY_REQUEST_TIMEOUT = "request-timeout";
const ::std::string FlumeConfiguration::KEY_BACK_OFF = "backoff";
const ::std::string FlumeConfiguration::DEFAULT_HEADERS = "";
const ::std::string FlumeConfiguration::DEFAULT_AGENT_TYPE = "SINGLE";
const ::std::string FlumeConfiguration::DEFAULT_HOSTS = "logAgent00 logAgent01";
const ::std::string FlumeConfiguration::DEFAULT_HOST_SELECTOR = "ROUND_ROBIN";


const ::std::string HDFSConfiguration::FILESYSTEM_NAME = "fs.default.name";
const ::std::string HDFSConfiguration::FILESYSTEM_IMPL = "fs.hdfs.impl";
const ::std::string HDFSConfiguration::FILESYSTEM_USE_LOCAL = "fs.use.local";


const ::std::string KafkaConfiguration::KAFKA_7_ZOOKEEPER_PROP = "zk.connect";
const ::std::string KafkaConfiguration::KAFKA_8_ZOOKEEPER_PROP = "zookeeper.connect";
const ::std::string KafkaConfiguration::KAFKA_CONSUMER_TIMEOUT_PROP = "consumer.timeout.ms";
const ::std::string KafkaConfiguration::KAFKA_BROKER_LIST_PROP = "metadata.broker.list";


const ::std::string MongoDBConfiguration::MONGODB_HOST_NAME_KEY = "mongodb.host.name";
const ::std::string MongoDBConfiguration::MONGODB_DB_NAME_KEY = "mongodb.database.name";
const ::std::string MongoDBConfiguration::MONGODB_USER_NAME_KEY = "mongodb.user.name";
const ::std::string MongoDBConfiguration::MONGODB_PASSWORD_KEY = "mongodb.password";
const ::std::string MongoDBConfiguration::MONGODB_USE_SSL_KEY = "mongodb.use.ssl";


const OpenShiftConfiguration OpenShiftConfiguration::OPENSHIFT_APP_DNS = OpenShiftConfiguration("OPENSHIFT_APP_DNS");
const OpenShiftConfiguration OpenShiftConfiguration::OPENSHIFT_APP_NAME = OpenShiftConfiguration("OPENSHIFT_APP_NAME");
const OpenShiftConfiguration OpenShiftConfiguration::OPENSHIFT_APP_UUID = OpenShiftConfiguration("OPENSHIFT_APP_UUID");
const OpenShiftConfiguration OpenShiftConfiguration::OPENSHIFT_DATA_DIR = OpenShiftConfiguration("OPENSHIFT_DATA_DIR");
const OpenShiftConfiguration OpenShiftConfiguration::OPENSHIFT_GEAR_DNS = OpenShiftConfiguration("OPENSHIFT_GEAR_DNS");
const OpenShiftConfiguration OpenShiftConfiguration::OPENSHIFT_GEAR_NAME = OpenShiftConfiguration("OPENSHIFT_GEAR_NAME");
const OpenShiftConfiguration OpenShiftConfiguration::OPENSHIFT_GEAR_UUID = OpenShiftConfiguration("OPENSHIFT_GEAR_UUID");
const OpenShiftConfiguration OpenShiftConfiguration::OPENSHIFT_HOMEDIR = OpenShiftConfiguration("OPENSHIFT_HOMEDIR");
const OpenShiftConfiguration OpenShiftConfiguration::OPENSHIFT_REPO_DIR = OpenShiftConfiguration("OPENSHIFT_REPO_DIR");
const OpenShiftConfiguration OpenShiftConfiguration::OPENSHIFT_TMP_DIR = OpenShiftConfiguration("OPENSHIFT_TMP_DIR");
const OpenShiftConfiguration OpenShiftConfiguration::OPENSHIFT_JAVA_THRIFTRUNNER_IP = OpenShiftConfiguration("OPENSHIFT_JAVA_THRIFTRUNNER_IP");
const OpenShiftConfiguration OpenShiftConfiguration::OPENSHIFT_JAVA_THRIFTRUNNER_TCP_PORT = OpenShiftConfiguration("OPENSHIFT_JAVA_THRIFTRUNNER_TCP_PORT");
const OpenShiftConfiguration OpenShiftConfiguration::OPENSHIFT_JAVA_THRIFTRUNNER_TCP_PROXY_PORT = OpenShiftConfiguration("OPENSHIFT_JAVA_THRIFTRUNNER_TCP_PROXY_PORT");


const ::std::string PostgresConfiguration::POSTGRES_HOST = "postgres.host";
const ::std::string PostgresConfiguration::POSTGRES_PORT = "postgres.port";
const ::std::string PostgresConfiguration::POSTGRES_USERNAME = "postgres.username";
const ::std::string PostgresConfiguration::POSTGRES_PASSWORD = "postgres.password";
const ::std::string PostgresConfiguration::POSTGRES_DB = "postgres.db";


const ::std::string RedisConfiguration::REDIS_HOST_KEY = "redis.host";
const ::std::string RedisConfiguration::REDIS_PORT_KEY = "redis.port";


const SecurityConfiguration::UserCacheType SecurityConfiguration::MEMORY = SecurityConfiguration::UserCacheType("MEMORY");
const SecurityConfiguration::UserCacheType SecurityConfiguration::REDIS = SecurityConfiguration::UserCacheType("REDIS");

const ::std::string SecurityConfiguration::SSL_PEER_AUTH_REQUIRED = "ezbake.security.validate.peer";
const ::std::string SecurityConfiguration::SSL_PROTOCOL_KEY = "ezbake.ssl.protocol";
const ::std::string SecurityConfiguration::SSL_CIPHERS_KEY = "ezbake.ssl.ciphers";
const ::std::string SecurityConfiguration::APPLICATION_TRUSTED_CERT = "ezbake.ssl.trustedcert.file";
const ::std::string SecurityConfiguration::APPLICATION_PRIVATE_KEY_FILE = "ezbake.ssl.privatekey.file";
const ::std::string SecurityConfiguration::APPLICATION_CERT_FILE = "ezbake.ssl.certificate.file";
const ::std::string SecurityConfiguration::APPLICATION_PUBLIC_KEY_FILE = "ezbake.ssl.servivekey.file";
const ::std::string SecurityConfiguration::USER_CACHE_TYPE_KEY = "ezbake.security.cache.type";
const ::std::string SecurityConfiguration::USER_CACHE_TTL_KEY = "ezbake.security.cache.ttl";
const ::std::string SecurityConfiguration::USER_CACHE_SIZE_KEY = "ezbake.security.cache.size";
const ::std::string SecurityConfiguration::USE_FORWARD_PROXY= "ezbake.frontend.use.forward.proxy";

const ::std::string SecurityConfiguration::DEFAULT_SSL_PROTOCOLS = "TLSv1";
const ::std::string SecurityConfiguration::DEFAULT_SSL_CIPHERS = "HIGH:!DSS:!aNULL@STRENGTH";
const ::std::string SecurityConfiguration::DEFAULT_TURSTED_SSL_CERTS = "ezbakeca.crt";
const ::std::string SecurityConfiguration::DEFAULT_SSL_CERT = "application.crt";
const ::std::string SecurityConfiguration::DEFAULT_PRIVATE_KEY = "application.priv";
const ::std::string SecurityConfiguration::DEFAULT_SERVICE_PUBLIC_KEY = "ezbakesecurityservice.pub";

const EVP_MD* SecurityConfiguration::_ALGORITHM = EVP_sha256();


const ::std::string SystemConfiguration::EZBAKE_LOG_DIRECTORY = "ezbake.log.directory";
const ::std::string SystemConfiguration::EZBAKE_LOG_TO_STDOUT = "ezbake.log.stdout";
const ::std::string SystemConfiguration::EZBAKE_ADMIN_APPLICATION_DEPLOYMENT = "ezbake.system.admin.application.deployment";
const ::std::string SystemConfiguration::FILE_SEPERATOR = "/";


const ::std::string ThriftConfiguration::USE_SSL = "thrift.use.ssl";
const ::std::string ThriftConfiguration::SERVER_MODE = "thrift.server.mode";
const ::std::string ThriftConfiguration::MAX_IDLE_CLIENTS = "thrift.max.idle.clients";
const ::std::string ThriftConfiguration::MAX_POOL_CLIENTS = "thrift.max.pool.clients";
const ::std::string ThriftConfiguration::MILLIS_BETWEEN_CLIENT_EVICTION_CHECKS = "thrift.millis.between.client.eviction.checks";
const ::std::string ThriftConfiguration::MILLIS_IDLE_BEFORE_EVICTION = "thrift.millis.idle.before.eviction";
const ::std::string ThriftConfiguration::TEST_ON_BORROW = "thrift.test.pool.on.borrow";
const ::std::string ThriftConfiguration::TEST_WHILE_IDLE = "thrift.test.pool.while.idle";

const ThriftConfiguration::ThriftServerMode ThriftConfiguration::Simple = ThriftConfiguration::ThriftServerMode("Simple", true);
const ThriftConfiguration::ThriftServerMode ThriftConfiguration::HsHa = ThriftConfiguration::ThriftServerMode("HsHa", false);
const ThriftConfiguration::ThriftServerMode ThriftConfiguration::ThreadedPool = ThriftConfiguration::ThriftServerMode("ThreadedPool", true);


const ::std::string WebApplicationConfiguration::WEB_APPLICATION_EXTERNAL_DOMAIN_KEY = "web.application.external.domain";
const ::std::string WebApplicationConfiguration::WEB_APPLICATION_METRICS_ENDPOINT_KEY = "web.application.metrics.endpoint";
const ::std::string WebApplicationConfiguration::WEB_APPLICATION_METRICS_SITEID_KEY = "web.application.metrics.siteid";


const ::std::string ZookeeperConfiguration::ZOOKEEPER_CONNECTION_KEY = "zookeeper.connection.string";

}}} // namespace ::ezbake::ezconfiguration::helpers
