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

package ezbake.configuration.constants;

public class EzBakePropertyConstants{

	// Accumulo Constants
	// (type: string) Property which represents the name of the accumulo instance
	public final static String ACCUMULO_INSTANCE_NAME = "accumulo.instance.name";
	// (type: string) Property which represents the namespace in accumulo we are working in
	public final static String ACCUMULO_NAMESPACE = "accumulo.namespace";
	// (type: string) Encrypted Property which represents the password for the user to connect to the database with
	public final static String ACCUMULO_PASSWORD = "accumulo.password";
	// (type: boolean) Property used to indicate whether our connector is in mock mode
	public final static String ACCUMULO_USE_MOCK = "accumulo.use.mock";
	// (type: string) Property which is the username we connect to the database with
	public final static String ACCUMULO_USERNAME = "accumulo.username";
	// (type: string) Property which is a CSV of zookeeper connection strings (host:port) which are the zookeeper servers that accumulo users
	public final static String ACCUMULO_ZOOKEEPERS = "accumulo.zookeepers";
	// (type: int) Property which specifies the port of the accumulo proxy
	public final static String ACCUMULO_PROXY_PORT = "accumulo.proxy.port";
	// (type: string) Property which specifies the hostname of the accumulo proxy
	public final static String ACCUMULO_PROXY_HOST = "accumulo.proxy.host";
	// (type: boolean) Property which specifies if accumulo clients should use SSL
	public final static String ACCUMULO_USE_SSL = "accumulo.use.ssl";
	// (type: string) Property which specifies the path to the accumulo truststore
	public final static String ACCUMULO_SSL_TRUSTSTORE_PATH = "accumulo.ssl.truststore.path";
	// (type: string) Property which specifies the type of the accumulo truststore
	public final static String ACCUMULO_SSL_TRUSTSTORE_TYPE = "accumulo.ssl.truststore.type";
	// (type: string) Property which specifies the password for the accumulo truststore
	public final static String ACCUMULO_SSL_TRUSTSTORE_PASSWORD = "accumulo.ssl.truststore.password";

	// Application Constants
	// (type: string) Property which represents the name of the application
	public final static String EZBAKE_APPLICATION_NAME = "application.name";
	// (type: string) Property which represents the version of the application
	public final static String EZBAKE_APPLICATION_VERSION = "ezbake.application.version";

	// Azkaban Constants
	// (type: string) Property which represents url for azkaban
	public final static String AZKABAN_URL = "azkaban.url";
	// (type: string) Property which represents azkaban password
	public final static String AZKABAN_PASSWORD = "azkaban.password";
	// (type: string) Property which represents azkaban username
	public final static String AZKABAN_USERNAME = "azkaban.username";

	// Common Services Constants
	// (type: string) Property which represents capco service
	public final static String CAPCO = "CapcoService";
	// (type: string) Property which represents datawarehouse service
	public final static String DATAWAREHOUSE = "warehaus";
	// (type: string) Property which represents document extraction service
	public final static String DOCUMENT_EXTRACTION = "docextract";
	// (type: string) Property which represents entity extraction service
	public final static String ENTITY_EXTRACTION = "entityextract";
	// (type: string) Property which represents ezdeployer service
	public final static String EZDEPLOYER = "ezdeployer";
	// (type: string) Property which represents ezsecurity service
	public final static String EZSECURITY = "EzbakeSecurityService";
	// (type: string) Property which represents ezsecurity registration service
	public final static String EZSECURITY_REGISTRATION = "EzSecurityRegistration";
	// (type: string) Property which represents geospatial extraction service
	public final static String GEOSPATIAL_EXTRACTION = "geosvc";
	// (type: string) Property which represents image indexer service
	public final static String IMAGE_INDEXER = "imageindexingservice";
	// (type: string) Property which represents image metadata extraction service
	public final static String IMAGE_METADATA_EXTRACTION = "imagemetadataextractionservice";
	// (type: string) Property which represents internal name service
	public final static String INTERNAL_NAME_SERVICE = "ins";
	// (type: string) Property which represents selector extraction service
	public final static String SELECTOR_EXTRACTION = "selext";
	// (type: string) Property which represents ssr service
	public final static String SSR = "ssrService";
	// (type: string) Property which represents temporal normalizer service
	public final static String TEMPORAL_NORMALIZER = "temporalsvc";

	// Elastic Search Constants
	// (type: string) Property which represents elastic search cluster name key in ezconfig
	public final static String ELASTICSEARCH_CLUSTER_NAME = "elastic.cluster.name";
	// (type: string) Property which represents elastic search force refresh key in ezconfig
	public final static String ELASTICSEARCH_FORCE_REFRESH_ON_PUT = "elastic.force.refresh";
	// (type: string) Property which represents elastic search host name key in ezconfig
	public final static String ELASTICSEARCH_HOST = "elastic.host.name";
	// (type: string) Property which represents elastic search port key in ezconfig
	public final static String ELASTICSEARCH_PORT = "elastic.port";

	// Hadoop Constants
	// (type: string) Property which represents ezconfig string to get default filesystem name
	public final static String HADOOP_FILESYSTEM_NAME = "fs.default.name";
	// (type: string) Property which represents ezconfig string to get hdfs implementation
	public final static String HADOOP_FILESYSTEM_IMPL = "fs.hdfs.impl";
	// (type: string) Property which represents ezconfig string to get filesystem use local value
	public final static String HADOOP_FILESYSTEM_USE_LOCAL = "fs.use.local";

	// Flume Constants
	// (type: string) Property which represents flume key for agent type
	public final static String FLUME_AGENT_TYPE = "flume.agent.type";
	// (type: string) Property which represents flume key for backoff
	public final static String FLUME_BACK_OFF = "flume.backoff";
	// (type: string) Property which represents flume key for batch size
	public final static String FLUME_BATCH_SIZE = "flume.batch.size";
	// (type: string) Property which represents flume key for connect attempts
	public final static String FLUME_CONNECT_ATTEMPTS = "flume.connect.attempts";
	// (type: string) Property which represents flume key for connect timeout
	public final static String FLUME_CONNECT_TIMEOUT = "flume.connect.timeout";
	// (type: string) Property which represents flume key for headers
	public final static String FLUME_HEADERS = "flume.headers";
	// (type: string) Property which represents flume key for host selector
	public final static String FLUME_HOST_SELECTOR = "flume.host.selector";
	// (type: string) Property which represents flume key for hosts
	public final static String FLUME_HOSTS = "flume.hosts";
	// (type: string) Property which represents flume key for max attempts
	public final static String FLUME_MAX_ATTEMPTS = "flume.max.attempts";
	// (type: string) Property which represents flume key for max backoff
	public final static String FLUME_MAX_BACKOFF = "flume.max.backoff";
	// (type: string) Property which represents flume key for max events
	public final static String FLUME_MAX_EVENTS = "flume.max.events";
	// (type: string) Property which represents flume key for request timeout
	public final static String FLUME_REQUEST_TIMEOUT = "flume.request.timeout";
	// (type: string) Property which represents flume key for run interval
	public final static String FLUME_RUN_INTERVAL = "flume.run.interval";
	// (type: string) Property which represents flume key for sleep interval
	public final static String FLUME_SLEEP_INTERVAL = "flume.sleep.interval";

	// Kafka Constants
	// (type: string) Property which represents kafka zookeeper connection string
	public final static String KAFKA_ZOOKEEPER = "kafka.zookeeper.connect";
	// (type: string) Property which represents kafka broker list ezconfig property
	public final static String KAFKA_BROKER_LIST = "kafka.metadata.broker.list";
	// (type: int) Property which represents the time that messages stay in memory before flushed to Kafka if using an async producer (in milliseconds)
	public final static String KAFKA_QUEUE_TIME = "kafka.queue.time";
	// (type: string) Property which represents the amount of messages that are queued in memory before flushing to Kafka if using an async producer
	public final static String KAFKA_QUEUE_SIZE = "kafka.queue.size";
	// (type: string) Property which represents the type of producer (sync or async) used by Kafka
	public final static String KAFKA_PRODUCER_TYPE = "kafka.producer.type";
	// (type: int) Property which represents the zookeeper timeout for Kafka consumers
	public final static String KAFKA_ZOOKEEPER_SESSION_TIMEOUT = "kafka.zk.sessiontimeout.ms";

	// Mongo Configuration Constants
	// (type: string) Property which represents mongo db host name ezconfig key
	public final static String MONGODB_HOST_NAME = "mongodb.host.name";
	// (type: int) Property which represents mongo db port number key
	public final static String MONGODB_PORT = "mongodb.port";
	// (type: string) Property which represents mongo db database name ezconfig key
	public final static String MONGODB_DB_NAME = "mongodb.database.name";
	// (type: string) Property which represents mongo db user name ezconfig key
	public final static String MONGODB_USER_NAME = "mongodb.user.name";
	// (type: string) Property which represents mongo db password ezconfig key
	public final static String MONGODB_PASSWORD = "mongodb.password";
	// (type: string) Property which represents mongo db use ssl ezconfig key
	public final static String MONGODB_USE_SSL = "mongodb.use.ssl";
	// (type: string) Property which represents the connection string that can be used to access mongo
	public final static String MONGODB_CONNECTION_STRING = "mongodb.connection.string";

	// Postgres Constants
	// (type: string) Property which represents postgres db ezconfig key
	public final static String POSTGRES_DB = "postgres.db";
	// (type: string) Property which represents postgres host ezconfig key
	public final static String POSTGRES_HOST = "postgres.host";
	// (type: string) Property which represents postgres password ezconfig key
	public final static String POSTGRES_PASSWORD = "postgres.password";
	// (type: string) Property which represents postgres port ezconfig key
	public final static String POSTGRES_PORT = "postgres.port";
	// (type: string) Property which represents postgres username ezconfig key
	public final static String POSTGRES_USERNAME = "postgres.username";
	// (type: string) Property which represents whether postgres connection uses ssl ezconfig key
	public final static String POSTGRES_USE_SSL = "postgres.use.ssl";

	// Redis Constants
	// (type: int) Property which represents redis host ezconfig key
	public final static String REDIS_HOST = "redis.host";
	// (type: string) Property which represents redis post ezconfig key
	public final static String REDIS_PORT = "redis.port";
	// (type: int) Property which represents redis db index ezconfig key
	public final static String REDIS_DB_INDEX = "redis.db.index";

	// Security Constants
	// (type: string) Property which represents the security id
	public final static String EZBAKE_SECURITY_ID = "ezbake.security.app.id";
	// (type: string) Property which represents cache type ezconfig key
	public final static String EZBAKE_USER_CACHE_TYPE = "ezbake.security.cache.type";
	// (type: string) Property which represents cache ttl ezconfig key
	public final static String EZBAKE_USER_CACHE_TTL = "ezbake.security.cache.ttl";
	// (type: string) Property which represents cache size ezconfig key
	public final static String EZBAKE_USER_CACHE_SIZE = "ezbake.security.cache.size";
	// (type: string) Property which represents request expiration ezconfig key
	public final static String EZBAKE_REQUEST_EXPIRATION = "ezbake.security.request.expiration";
	// (type: string) Property which represents token expiration ezconfig key
	public final static String EZBAKE_TOKEN_EXPIRATION = "ezbake.security.token.ttl";
	// (type: int) How long after being issued a proxy token should be valid
	public final static String EZBAKE_SECURITY_PROXYTOKEN_TTL = "ezbake.security.proxytoken.ttl";
	// (type: int) How long after expiration a token can be re-issued
	public final static String EZBAKE_SECURITY_TOKEN_REFRESH_LIMIT = "ezbake.security.token.refresh.limit";
	// (type: string) Property which represents app registration implementation ezconfig key
	public final static String EZBAKE_APP_REGISTRATION_IMPL = "ezbake.security.app.service.impl";
	// (type: string) Property which represents admins file ezconfig key
	public final static String EZBAKE_ADMINS_FILE = "ezbake.security.admins.file";
	// (type: string) Property which represents service implementation ezconfig key
	public final static String EZBAKE_USER_SERVICE_IMPL = "ezbake.security.user.service.impl";
	// (type: string) Property which represents mock server ezconfig key
	public final static String EZBAKE_SECURITY_SERVICE_MOCK_SERVER = "ezbake.security.server.mock";
	// (type: string) Property which represents use forward proxy ezconfig key
	public final static String EZBAKE_USE_FORWARD_PROXY = "ezbake.frontend.use.forward.proxy";
	// (type: string) Property which represents ssl protocol ezconfig key
	public final static String EZBAKE_SSL_PROTOCOL_KEY = "ezbake.ssl.protocol";
	// (type: string) Property which represents ssl ciphers ezconfig key
	public final static String EZBAKE_SSL_CIPHERS_KEY = "ezbake.ssl.ciphers";
	// (type: string) Property which represents peer validation ezconfig key
	public final static String EZBAKE_SSL_PEER_AUTH_REQUIRED = "ezbake.ssl.peer.validation";
	// (type: boolean) Property which tells us if we are using the default ssl key
	public final static String EZBAKE_SSL_USE_DEFAULT_SSL_KEY = "ezbake.security.default.ssl";
	// (type: string) Property which represents the trusted certificates file
	public final static String EZBAKE_APPLICATION_TRUSTED_CERT = "ezbake.ssl.trustedcert.file";
	// (type: string) Property which represents the private key file
	public final static String EZBAKE_APPLICATION_PRIVATE_KEY_FILE = "ezbake.ssl.privatekey.file";
	// (type: string) Property which represents the certificates file
	public final static String EZBAKE_APPLICATION_CERT_FILE = "ezbake.ssl.certificate.file";
	// (type: string) Property which represents the public key file for a service
	public final static String EZBAKE_APPLICATION_PUBLIC_KEY_FILE = "ezbake.ssl.servicekey.file";

	// SSL Constants
	// (type: string) Property which represents the path to the system keystore
	public final static String SYSTEM_KEYSTORE_PATH = "system.keystore.path";
	// (type: string) Property which represents the type of the system keystore
	public final static String SYSTEM_KEYSTORE_TYPE = "system.keystore.type";
	// (type: string) Property which represents the password for the system keystore
	public final static String SYSTEM_KEYSTORE_PASSWORD = "system.keystore.password";
	// (type: string) Property which represents the path to the system truststore
	public final static String SYSTEM_TRUSTSTORE_PATH = "system.truststore.path";
	// (type: string) Property which represents the type of the system truststore
	public final static String SYSTEM_TRUSTSTORE_TYPE = "system.truststore.type";
	// (type: string) Property which represents the password for the system truststore
	public final static String SYSTEM_TRUSTSTORE_PASSWORD = "system.truststore.password";
	// (type: string) Property which represents keystore file ezconfig key
	public final static String EZBAKE_APPLICATION_KEYSTORE_FILE = "ezbake.ssl.keystore.file";
	// (type: string) Property which represents keystore type ezconfig key
	public final static String EZBAKE_APPLICATION_KEYSTORE_TYPE = "ezbake.ssl.keystore.type";
	// (type: string) Property which represents keystore password ezconfig key
	public final static String EZBAKE_APPLICATION_KEYSTORE_PASS = "ezbake.ssl.keystore.pass";
	// (type: string) Property which represents truststore file ezconfig key
	public final static String EZBAKE_APPLICATION_TRUSTSTORE_FILE = "ezbake.ssl.truststore.file";
	// (type: string) Property which represents truststore type ezconfig key
	public final static String EZBAKE_APPLICATION_TRUSTSTORE_TYPE = "ezbake.ssl.truststore.type";
	// (type: string) Property which represents truststore password ezconfig key
	public final static String EZBAKE_APPLICATION_TRUSTSTORE_PASS = "ezbake.ssl.truststore.pass";

	// Service Constants
	// (type: string) Property representing the location to the certificates directory
	public final static String EZBAKE_CERTIFICATES_DIRECTORY = "ezbake.security.ssl.dir";
	// (type: string) Property which represents the name of the service
	public final static String EZBAKE_SERVICE_NAME = "service.name";

	// Storm Constants
	// (type: string) Property representing the nimbus host
	public final static String STORM_NIMBUS_HOST = "storm.nimbus.host";
	// (type: int) Property representing the nimbus port
	public final static String STORM_NIMBUS_THRIFT_PORT = "storm.nimbus.thrift.port";

	// System Constants
	// (type: string) Property which represents ezbake admin application deployment ezconfig key
	public final static String EZBAKE_ADMIN_APPLICATION_DEPLOYMENT = "ezbake.system.admin.application.deployment";
	// (type: string) Property which represents ezbake log directory ezconfig key
	public final static String EZBAKE_LOG_DIRECTORY = "ezbake.log.directory";
	// (type: string) Property which represents ezbake log standard out ezconfig key
	public final static String EZBAKE_LOG_TO_STDOUT = "ezbake.log.stdout";
	// (type: string) Property which represents the environment variable for the shared secret
	public final static String EZBAKE_SHARED_SECRET_ENVIRONMENT_VARIABLE = "ezbake.shared.secret.environment.variable";

	// System Services Constants
	// (type: string) Property which represents frontend service
	public final static String FRONTEND = "ezfrontend";

	// Thrift Constants
	// (type: string) Property which represents thrifts max idle clients ezconfig key
	public final static String THRIFT_MAX_IDLE_CLIENTS = "thrift.max.idle.clients";
	// (type: string) Property which represents thrifts max pool clients ezconfig key
	public final static String THRIFT_MAX_POOL_CLIENTS = "thrift.max.pool.clients";
	// (type: string) Property which represents thrifts milliseconds between client eviction checks ezconfig key
	public final static String THRIFT_MILLIS_BETWEEN_CLIENT_EVICTION_CHECKS = "thrift.millis.between.client.eviction.checks";
	// (type: string) Property which represents thrifts milliseconds before client eviction ezconfig key
	public final static String THRIFT_MILLIS_IDLE_BEFORE_EVICTION = "thrift.millis.idle.before.eviction";
	// (type: string) Property which represents thrifts server mode ezconfig key
	public final static String THRIFT_SERVER_MODE = "thrift.server.mode";
	// (type: string) Property which represents thrifts test pool on borrow ezconfig key
	public final static String THRIFT_TEST_ON_BORROW = "thrift.test.pool.on.borrow";
	// (type: string) Property which represents thrifts test while idle ezconfig key
	public final static String THRIFT_TEST_WHILE_IDLE = "thrift.test.pool.while.idle";
	// (type: string) Property which represents thrifts use ssl ezconfig key
	public final static String THRIFT_USE_SSL = "thrift.use.ssl";
	// (type: boolean) Property which represents if the client pool should block on exhaustion or throw an exception
	public final static String THRIFT_BLOCK_WHEN_EXHAUSTED = "thrift.block.when.exhausted";
	// (type: boolean) Property which tells us to actually pool clients or not
	public final static String THRIFT_ACTUALLY_POOL_CLIENTS = "thrift.actually.pool.clients";
	// (type: boolean) Log a stack trace whenever an object is abandonded from the pool
	public final static String THRIFT_LOG_ABANDONDED = "thrift.pool.log.abandoned";
	// (type: boolean) Whether to abandon objects if they exceed the abandon timeout when borrow is called
	public final static String THRIFT_ABANDON_ON_BORROW = "thrift.pool.abandon.on.borrow";
	// (type: boolean) Whether to abandon objects if they exceed the abandon timeout when the evictor runs
	public final static String THRIFT_ABANDON_ON_MAINTENANCE = "thrift.pool.abandon.on.maintenance";
	// (type: string) Timeout in seconds before an abandoned object is removed
	public final static String THRIFT_ABANDON_TIMEOUT = "thrift.pool.abandon.timeout";

	// Web Application Constants
	// (type: string) Property which represents web application external domain ezconfig key
	public final static String EZBAKE_WEB_APPLICATION_EXTERNAL_DOMAIN = "web.application.external.domain";
	// (type: string) Property which represents web application metrics endpoint ezconfig key
	public final static String EZBAKE_WEB_APPLICATION_METRICS_ENDPOINT = "web.application.metrics.endpoint";
	// (type: string) Property which represents web application metrics siteid ezconfig key
	public final static String EZBAKE_WEB_APPLICATION_METRICS_SITEID = "web.application.metrics.siteid";
	// (type: string) Property which represents security description banner: text
	public final static String EZBAKE_WEB_APPLICATION_BANNER_TEXT = "web.application.security.banner.text";
	// (type: string) Property which represents security description banner: background color
	public final static String EZBAKE_WEB_APPLICATION_BANNER_BGCOLOR = "web.application.security.banner.background.color";
	// (type: string) Property which represents security description banner: text color
	public final static String EZBAKE_WEB_APPLICATION_BANNER_TEXTCOLOR = "web.application.security.banner.text.color";

	// Zookeeper Constants
	// (type: string) Property which is a CSV of zookeeper servers (host:port)
	public final static String ZOOKEEPER_CONNECTION_STRING = "zookeeper.connection.string";

	// MonetDB Constants
	// (type: string) The MonetDB Username
	public final static String MONETDB_USERNAME = "monetdb.username";
	// (type: string) The MonetDB Password
	public final static String MONETDB_PASSWORD = "monetdb.password";
	// (type: string) The hostname of the MonetDB server
	public final static String MONETDB_HOSTNAME = "monetdb.hostname";
	// (type: int) The port number that MonetDB is running on
	public final static String MONETDB_PORT = "monetdb.port";
}
