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

/**
*  Template rendered constants
**/

module.exports = {

	// Accumulo Constants
	// (type: string) Property which represents the name of the accumulo instance
	ACCUMULO_INSTANCE_NAME:"accumulo.instance.name",
	// (type: string) Property which represents the namespace in accumulo we are working in
	ACCUMULO_NAMESPACE:"accumulo.namespace",
	// (type: string) Encrypted Property which represents the password for the user to connect to the database with
	ACCUMULO_PASSWORD:"accumulo.password",
	// (type: boolean) Property used to indicate whether our connector is in mock mode
	ACCUMULO_USE_MOCK:"accumulo.use.mock",
	// (type: string) Property which is the username we connect to the database with
	ACCUMULO_USERNAME:"accumulo.username",
	// (type: string) Property which is a CSV of zookeeper connection strings (host:port) which are the zookeeper servers that accumulo users
	ACCUMULO_ZOOKEEPERS:"accumulo.zookeepers",
	// (type: int) Property which specifies the port of the accumulo proxy
	ACCUMULO_PROXY_PORT:"accumulo.proxy.port",
	// (type: string) Property which specifies the hostname of the accumulo proxy
	ACCUMULO_PROXY_HOST:"accumulo.proxy.host",
	// (type: boolean) Property which specifies if accumulo clients should use SSL
	ACCUMULO_USE_SSL:"accumulo.use.ssl",
	// (type: string) Property which specifies the path to the accumulo truststore
	ACCUMULO_SSL_TRUSTSTORE_PATH:"accumulo.ssl.truststore.path",
	// (type: string) Property which specifies the type of the accumulo truststore
	ACCUMULO_SSL_TRUSTSTORE_TYPE:"accumulo.ssl.truststore.type",
	// (type: string) Property which specifies the password for the accumulo truststore
	ACCUMULO_SSL_TRUSTSTORE_PASSWORD:"accumulo.ssl.truststore.password",

	// Application Constants
	// (type: string) Property which represents the name of the application
	EZBAKE_APPLICATION_NAME:"application.name",
	// (type: string) Property which represents the version of the application
	EZBAKE_APPLICATION_VERSION:"ezbake.application.version",

	// Azkaban Constants
	// (type: string) Property which represents url for azkaban
	AZKABAN_URL:"azkaban.url",
	// (type: string) Property which represents azkaban password
	AZKABAN_PASSWORD:"azkaban.password",
	// (type: string) Property which represents azkaban username
	AZKABAN_USERNAME:"azkaban.username",

	// Common Services Constants
	// (type: string) Property which represents capco service
	CAPCO:"CapcoService",
	// (type: string) Property which represents datawarehouse service
	DATAWAREHOUSE:"warehaus",
	// (type: string) Property which represents document extraction service
	DOCUMENT_EXTRACTION:"docextract",
	// (type: string) Property which represents entity extraction service
	ENTITY_EXTRACTION:"entityextract",
	// (type: string) Property which represents ezdeployer service
	EZDEPLOYER:"ezdeployer",
	// (type: string) Property which represents ezsecurity service
	EZSECURITY:"EzbakeSecurityService",
	// (type: string) Property which represents ezsecurity registration service
	EZSECURITY_REGISTRATION:"EzSecurityRegistration",
	// (type: string) Property which represents geospatial extraction service
	GEOSPATIAL_EXTRACTION:"geosvc",
	// (type: string) Property which represents image indexer service
	IMAGE_INDEXER:"imageindexingservice",
	// (type: string) Property which represents image metadata extraction service
	IMAGE_METADATA_EXTRACTION:"imagemetadataextractionservice",
	// (type: string) Property which represents internal name service
	INTERNAL_NAME_SERVICE:"ins",
	// (type: string) Property which represents selector extraction service
	SELECTOR_EXTRACTION:"selext",
	// (type: string) Property which represents ssr service
	SSR:"ssrService",
	// (type: string) Property which represents temporal normalizer service
	TEMPORAL_NORMALIZER:"temporalsvc",

	// Elastic Search Constants
	// (type: string) Property which represents elastic search cluster name key in ezconfig
	ELASTICSEARCH_CLUSTER_NAME:"elastic.cluster.name",
	// (type: string) Property which represents elastic search force refresh key in ezconfig
	ELASTICSEARCH_FORCE_REFRESH_ON_PUT:"elastic.force.refresh",
	// (type: string) Property which represents elastic search host name key in ezconfig
	ELASTICSEARCH_HOST:"elastic.host.name",
	// (type: string) Property which represents elastic search port key in ezconfig
	ELASTICSEARCH_PORT:"elastic.port",

	// Hadoop Constants
	// (type: string) Property which represents ezconfig string to get default filesystem name
	HADOOP_FILESYSTEM_NAME:"fs.default.name",
	// (type: string) Property which represents ezconfig string to get hdfs implementation
	HADOOP_FILESYSTEM_IMPL:"fs.hdfs.impl",
	// (type: string) Property which represents ezconfig string to get filesystem use local value
	HADOOP_FILESYSTEM_USE_LOCAL:"fs.use.local",

	// Flume Constants
	// (type: string) Property which represents flume key for agent type
	FLUME_AGENT_TYPE:"flume.agent.type",
	// (type: string) Property which represents flume key for backoff
	FLUME_BACK_OFF:"flume.backoff",
	// (type: string) Property which represents flume key for batch size
	FLUME_BATCH_SIZE:"flume.batch.size",
	// (type: string) Property which represents flume key for connect attempts
	FLUME_CONNECT_ATTEMPTS:"flume.connect.attempts",
	// (type: string) Property which represents flume key for connect timeout
	FLUME_CONNECT_TIMEOUT:"flume.connect.timeout",
	// (type: string) Property which represents flume key for headers
	FLUME_HEADERS:"flume.headers",
	// (type: string) Property which represents flume key for host selector
	FLUME_HOST_SELECTOR:"flume.host.selector",
	// (type: string) Property which represents flume key for hosts
	FLUME_HOSTS:"flume.hosts",
	// (type: string) Property which represents flume key for max attempts
	FLUME_MAX_ATTEMPTS:"flume.max.attempts",
	// (type: string) Property which represents flume key for max backoff
	FLUME_MAX_BACKOFF:"flume.max.backoff",
	// (type: string) Property which represents flume key for max events
	FLUME_MAX_EVENTS:"flume.max.events",
	// (type: string) Property which represents flume key for request timeout
	FLUME_REQUEST_TIMEOUT:"flume.request.timeout",
	// (type: string) Property which represents flume key for run interval
	FLUME_RUN_INTERVAL:"flume.run.interval",
	// (type: string) Property which represents flume key for sleep interval
	FLUME_SLEEP_INTERVAL:"flume.sleep.interval",

	// Kafka Constants
	// (type: string) Property which represents kafka zookeeper connection string
	KAFKA_ZOOKEEPER:"kafka.zookeeper.connect",
	// (type: string) Property which represents kafka broker list ezconfig property
	KAFKA_BROKER_LIST:"kafka.metadata.broker.list",
	// (type: int) Property which represents the time that messages stay in memory before flushed to Kafka if using an async producer (in milliseconds)
	KAFKA_QUEUE_TIME:"kafka.queue.time",
	// (type: string) Property which represents the amount of messages that are queued in memory before flushing to Kafka if using an async producer
	KAFKA_QUEUE_SIZE:"kafka.queue.size",
	// (type: string) Property which represents the type of producer (sync or async) used by Kafka
	KAFKA_PRODUCER_TYPE:"kafka.producer.type",
	// (type: int) Property which represents the zookeeper timeout for Kafka consumers
	KAFKA_ZOOKEEPER_SESSION_TIMEOUT:"kafka.zk.sessiontimeout.ms",

	// Mongo Configuration Constants
	// (type: string) Property which represents mongo db host name ezconfig key
	MONGODB_HOST_NAME:"mongodb.host.name",
	// (type: int) Property which represents mongo db port number key
	MONGODB_PORT:"mongodb.port",
	// (type: string) Property which represents mongo db database name ezconfig key
	MONGODB_DB_NAME:"mongodb.database.name",
	// (type: string) Property which represents mongo db user name ezconfig key
	MONGODB_USER_NAME:"mongodb.user.name",
	// (type: string) Property which represents mongo db password ezconfig key
	MONGODB_PASSWORD:"mongodb.password",
	// (type: string) Property which represents mongo db use ssl ezconfig key
	MONGODB_USE_SSL:"mongodb.use.ssl",
	// (type: string) Property which represents the connection string that can be used to access mongo
	MONGODB_CONNECTION_STRING:"mongodb.connection.string",

	// Postgres Constants
	// (type: string) Property which represents postgres db ezconfig key
	POSTGRES_DB:"postgres.db",
	// (type: string) Property which represents postgres host ezconfig key
	POSTGRES_HOST:"postgres.host",
	// (type: string) Property which represents postgres password ezconfig key
	POSTGRES_PASSWORD:"postgres.password",
	// (type: string) Property which represents postgres port ezconfig key
	POSTGRES_PORT:"postgres.port",
	// (type: string) Property which represents postgres username ezconfig key
	POSTGRES_USERNAME:"postgres.username",
	// (type: string) Property which represents whether postgres connection uses ssl ezconfig key
	POSTGRES_USE_SSL:"postgres.use.ssl",

	// Redis Constants
	// (type: int) Property which represents redis host ezconfig key
	REDIS_HOST:"redis.host",
	// (type: string) Property which represents redis post ezconfig key
	REDIS_PORT:"redis.port",
	// (type: int) Property which represents redis db index ezconfig key
	REDIS_DB_INDEX:"redis.db.index",

	// Security Constants
	// (type: string) Property which represents the security id
	EZBAKE_SECURITY_ID:"ezbake.security.app.id",
	// (type: string) Property which represents cache type ezconfig key
	EZBAKE_USER_CACHE_TYPE:"ezbake.security.cache.type",
	// (type: string) Property which represents cache ttl ezconfig key
	EZBAKE_USER_CACHE_TTL:"ezbake.security.cache.ttl",
	// (type: string) Property which represents cache size ezconfig key
	EZBAKE_USER_CACHE_SIZE:"ezbake.security.cache.size",
	// (type: string) Property which represents request expiration ezconfig key
	EZBAKE_REQUEST_EXPIRATION:"ezbake.security.request.expiration",
	// (type: string) Property which represents token expiration ezconfig key
	EZBAKE_TOKEN_EXPIRATION:"ezbake.security.token.ttl",
	// (type: int) How long after being issued a proxy token should be valid
	EZBAKE_SECURITY_PROXYTOKEN_TTL:"ezbake.security.proxytoken.ttl",
	// (type: int) How long after expiration a token can be re-issued
	EZBAKE_SECURITY_TOKEN_REFRESH_LIMIT:"ezbake.security.token.refresh.limit",
	// (type: string) Property which represents app registration implementation ezconfig key
	EZBAKE_APP_REGISTRATION_IMPL:"ezbake.security.app.service.impl",
	// (type: string) Property which represents admins file ezconfig key
	EZBAKE_ADMINS_FILE:"ezbake.security.admins.file",
	// (type: string) Property which represents service implementation ezconfig key
	EZBAKE_USER_SERVICE_IMPL:"ezbake.security.user.service.impl",
	// (type: string) Property which represents mock server ezconfig key
	EZBAKE_SECURITY_SERVICE_MOCK_SERVER:"ezbake.security.server.mock",
	// (type: string) Property which represents use forward proxy ezconfig key
	EZBAKE_USE_FORWARD_PROXY:"ezbake.frontend.use.forward.proxy",
	// (type: string) Property which represents ssl protocol ezconfig key
	EZBAKE_SSL_PROTOCOL_KEY:"ezbake.ssl.protocol",
	// (type: string) Property which represents ssl ciphers ezconfig key
	EZBAKE_SSL_CIPHERS_KEY:"ezbake.ssl.ciphers",
	// (type: string) Property which represents peer validation ezconfig key
	EZBAKE_SSL_PEER_AUTH_REQUIRED:"ezbake.ssl.peer.validation",
	// (type: boolean) Property which tells us if we are using the default ssl key
	EZBAKE_SSL_USE_DEFAULT_SSL_KEY:"ezbake.security.default.ssl",
	// (type: string) Property which represents the trusted certificates file
	EZBAKE_APPLICATION_TRUSTED_CERT:"ezbake.ssl.trustedcert.file",
	// (type: string) Property which represents the private key file
	EZBAKE_APPLICATION_PRIVATE_KEY_FILE:"ezbake.ssl.privatekey.file",
	// (type: string) Property which represents the certificates file
	EZBAKE_APPLICATION_CERT_FILE:"ezbake.ssl.certificate.file",
	// (type: string) Property which represents the public key file for a service
	EZBAKE_APPLICATION_PUBLIC_KEY_FILE:"ezbake.ssl.servicekey.file",

	// SSL Constants
	// (type: string) Property which represents the path to the system keystore
	SYSTEM_KEYSTORE_PATH:"system.keystore.path",
	// (type: string) Property which represents the type of the system keystore
	SYSTEM_KEYSTORE_TYPE:"system.keystore.type",
	// (type: string) Property which represents the password for the system keystore
	SYSTEM_KEYSTORE_PASSWORD:"system.keystore.password",
	// (type: string) Property which represents the path to the system truststore
	SYSTEM_TRUSTSTORE_PATH:"system.truststore.path",
	// (type: string) Property which represents the type of the system truststore
	SYSTEM_TRUSTSTORE_TYPE:"system.truststore.type",
	// (type: string) Property which represents the password for the system truststore
	SYSTEM_TRUSTSTORE_PASSWORD:"system.truststore.password",
	// (type: string) Property which represents keystore file ezconfig key
	EZBAKE_APPLICATION_KEYSTORE_FILE:"ezbake.ssl.keystore.file",
	// (type: string) Property which represents keystore type ezconfig key
	EZBAKE_APPLICATION_KEYSTORE_TYPE:"ezbake.ssl.keystore.type",
	// (type: string) Property which represents keystore password ezconfig key
	EZBAKE_APPLICATION_KEYSTORE_PASS:"ezbake.ssl.keystore.pass",
	// (type: string) Property which represents truststore file ezconfig key
	EZBAKE_APPLICATION_TRUSTSTORE_FILE:"ezbake.ssl.truststore.file",
	// (type: string) Property which represents truststore type ezconfig key
	EZBAKE_APPLICATION_TRUSTSTORE_TYPE:"ezbake.ssl.truststore.type",
	// (type: string) Property which represents truststore password ezconfig key
	EZBAKE_APPLICATION_TRUSTSTORE_PASS:"ezbake.ssl.truststore.pass",

	// Service Constants
	// (type: string) Property representing the location to the certificates directory
	EZBAKE_CERTIFICATES_DIRECTORY:"ezbake.security.ssl.dir",
	// (type: string) Property which represents the name of the service
	EZBAKE_SERVICE_NAME:"service.name",

	// Storm Constants
	// (type: string) Property representing the nimbus host
	STORM_NIMBUS_HOST:"storm.nimbus.host",
	// (type: int) Property representing the nimbus port
	STORM_NIMBUS_THRIFT_PORT:"storm.nimbus.thrift.port",

	// System Constants
	// (type: string) Property which represents ezbake admin application deployment ezconfig key
	EZBAKE_ADMIN_APPLICATION_DEPLOYMENT:"ezbake.system.admin.application.deployment",
	// (type: string) Property which represents ezbake log directory ezconfig key
	EZBAKE_LOG_DIRECTORY:"ezbake.log.directory",
	// (type: string) Property which represents ezbake log standard out ezconfig key
	EZBAKE_LOG_TO_STDOUT:"ezbake.log.stdout",
	// (type: string) Property which represents the environment variable for the shared secret
	EZBAKE_SHARED_SECRET_ENVIRONMENT_VARIABLE:"ezbake.shared.secret.environment.variable",

	// System Services Constants
	// (type: string) Property which represents frontend service
	FRONTEND:"ezfrontend",

	// Thrift Constants
	// (type: string) Property which represents thrifts max idle clients ezconfig key
	THRIFT_MAX_IDLE_CLIENTS:"thrift.max.idle.clients",
	// (type: string) Property which represents thrifts max pool clients ezconfig key
	THRIFT_MAX_POOL_CLIENTS:"thrift.max.pool.clients",
	// (type: string) Property which represents thrifts milliseconds between client eviction checks ezconfig key
	THRIFT_MILLIS_BETWEEN_CLIENT_EVICTION_CHECKS:"thrift.millis.between.client.eviction.checks",
	// (type: string) Property which represents thrifts milliseconds before client eviction ezconfig key
	THRIFT_MILLIS_IDLE_BEFORE_EVICTION:"thrift.millis.idle.before.eviction",
	// (type: string) Property which represents thrifts server mode ezconfig key
	THRIFT_SERVER_MODE:"thrift.server.mode",
	// (type: string) Property which represents thrifts test pool on borrow ezconfig key
	THRIFT_TEST_ON_BORROW:"thrift.test.pool.on.borrow",
	// (type: string) Property which represents thrifts test while idle ezconfig key
	THRIFT_TEST_WHILE_IDLE:"thrift.test.pool.while.idle",
	// (type: string) Property which represents thrifts use ssl ezconfig key
	THRIFT_USE_SSL:"thrift.use.ssl",
	// (type: boolean) Property which represents if the client pool should block on exhaustion or throw an exception
	THRIFT_BLOCK_WHEN_EXHAUSTED:"thrift.block.when.exhausted",
	// (type: boolean) Property which tells us to actually pool clients or not
	THRIFT_ACTUALLY_POOL_CLIENTS:"thrift.actually.pool.clients",
	// (type: boolean) Log a stack trace whenever an object is abandonded from the pool
	THRIFT_LOG_ABANDONDED:"thrift.pool.log.abandoned",
	// (type: boolean) Whether to abandon objects if they exceed the abandon timeout when borrow is called
	THRIFT_ABANDON_ON_BORROW:"thrift.pool.abandon.on.borrow",
	// (type: boolean) Whether to abandon objects if they exceed the abandon timeout when the evictor runs
	THRIFT_ABANDON_ON_MAINTENANCE:"thrift.pool.abandon.on.maintenance",
	// (type: string) Timeout in seconds before an abandoned object is removed
	THRIFT_ABANDON_TIMEOUT:"thrift.pool.abandon.timeout",

	// Web Application Constants
	// (type: string) Property which represents web application external domain ezconfig key
	EZBAKE_WEB_APPLICATION_EXTERNAL_DOMAIN:"web.application.external.domain",
	// (type: string) Property which represents web application metrics endpoint ezconfig key
	EZBAKE_WEB_APPLICATION_METRICS_ENDPOINT:"web.application.metrics.endpoint",
	// (type: string) Property which represents web application metrics siteid ezconfig key
	EZBAKE_WEB_APPLICATION_METRICS_SITEID:"web.application.metrics.siteid",
	// (type: string) Property which represents security description banner: text
	EZBAKE_WEB_APPLICATION_BANNER_TEXT:"web.application.security.banner.text",
	// (type: string) Property which represents security description banner: background color
	EZBAKE_WEB_APPLICATION_BANNER_BGCOLOR:"web.application.security.banner.background.color",
	// (type: string) Property which represents security description banner: text color
	EZBAKE_WEB_APPLICATION_BANNER_TEXTCOLOR:"web.application.security.banner.text.color",

	// Zookeeper Constants
	// (type: string) Property which is a CSV of zookeeper servers (host:port)
	ZOOKEEPER_CONNECTION_STRING:"zookeeper.connection.string",

	// MonetDB Constants
	// (type: string) The MonetDB Username
	MONETDB_USERNAME:"monetdb.username",
	// (type: string) The MonetDB Password
	MONETDB_PASSWORD:"monetdb.password",
	// (type: string) The hostname of the MonetDB server
	MONETDB_HOSTNAME:"monetdb.hostname",
	// (type: int) The port number that MonetDB is running on
	MONETDB_PORT:"monetdb.port",
}
