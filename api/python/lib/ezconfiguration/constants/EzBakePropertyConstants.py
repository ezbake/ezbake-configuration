#   Copyright (C) 2013-2014 Computer Sciences Corporation
#
#   Licensed under the Apache License, Version 2.0 (the "License");
#   you may not use this file except in compliance with the License.
#   You may obtain a copy of the License at
#
#       http://www.apache.org/licenses/LICENSE-2.0
#
#   Unless required by applicable law or agreed to in writing, software
#   distributed under the License is distributed on an "AS IS" BASIS,
#   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#   See the License for the specific language governing permissions and
#   limitations under the License.

def constant(f):
    def fset(self, value):
        raise SyntaxError('Unable to change constants')
    def fget(self):
        return f()
    return property(fget, fset)

class __EzBakePropertyConstants(object):

    # [Accumulo Constants]
    @constant    # (type: string) Property which represents the name of the accumulo instance
    def ACCUMULO_INSTANCE_NAME():
        return "accumulo.instance.name"
    @constant    # (type: string) Property which represents the namespace in accumulo we are working in
    def ACCUMULO_NAMESPACE():
        return "accumulo.namespace"
    @constant    # (type: string) Encrypted Property which represents the password for the user to connect to the database with
    def ACCUMULO_PASSWORD():
        return "accumulo.password"
    @constant    # (type: boolean) Property used to indicate whether our connector is in mock mode
    def ACCUMULO_USE_MOCK():
        return "accumulo.use.mock"
    @constant    # (type: string) Property which is the username we connect to the database with
    def ACCUMULO_USERNAME():
        return "accumulo.username"
    @constant    # (type: string) Property which is a CSV of zookeeper connection strings (host:port) which are the zookeeper servers that accumulo users
    def ACCUMULO_ZOOKEEPERS():
        return "accumulo.zookeepers"
    @constant    # (type: int) Property which specifies the port of the accumulo proxy
    def ACCUMULO_PROXY_PORT():
        return "accumulo.proxy.port"
    @constant    # (type: string) Property which specifies the hostname of the accumulo proxy
    def ACCUMULO_PROXY_HOST():
        return "accumulo.proxy.host"
    @constant    # (type: boolean) Property which specifies if accumulo clients should use SSL
    def ACCUMULO_USE_SSL():
        return "accumulo.use.ssl"
    @constant    # (type: string) Property which specifies the path to the accumulo truststore
    def ACCUMULO_SSL_TRUSTSTORE_PATH():
        return "accumulo.ssl.truststore.path"
    @constant    # (type: string) Property which specifies the type of the accumulo truststore
    def ACCUMULO_SSL_TRUSTSTORE_TYPE():
        return "accumulo.ssl.truststore.type"
    @constant    # (type: string) Property which specifies the password for the accumulo truststore
    def ACCUMULO_SSL_TRUSTSTORE_PASSWORD():
        return "accumulo.ssl.truststore.password"

    # [Application Constants]
    @constant    # (type: string) Property which represents the name of the application
    def EZBAKE_APPLICATION_NAME():
        return "application.name"
    @constant    # (type: string) Property which represents the version of the application
    def EZBAKE_APPLICATION_VERSION():
        return "ezbake.application.version"

    # [Azkaban Constants]
    @constant    # (type: string) Property which represents url for azkaban
    def AZKABAN_URL():
        return "azkaban.url"
    @constant    # (type: string) Property which represents azkaban password
    def AZKABAN_PASSWORD():
        return "azkaban.password"
    @constant    # (type: string) Property which represents azkaban username
    def AZKABAN_USERNAME():
        return "azkaban.username"

    # [Common Services Constants]
    @constant    # (type: string) Property which represents capco service
    def CAPCO():
        return "CapcoService"
    @constant    # (type: string) Property which represents datawarehouse service
    def DATAWAREHOUSE():
        return "warehaus"
    @constant    # (type: string) Property which represents document extraction service
    def DOCUMENT_EXTRACTION():
        return "docextract"
    @constant    # (type: string) Property which represents entity extraction service
    def ENTITY_EXTRACTION():
        return "entityextract"
    @constant    # (type: string) Property which represents ezdeployer service
    def EZDEPLOYER():
        return "ezdeployer"
    @constant    # (type: string) Property which represents ezsecurity service
    def EZSECURITY():
        return "EzbakeSecurityService"
    @constant    # (type: string) Property which represents ezsecurity registration service
    def EZSECURITY_REGISTRATION():
        return "EzSecurityRegistration"
    @constant    # (type: string) Property which represents geospatial extraction service
    def GEOSPATIAL_EXTRACTION():
        return "geosvc"
    @constant    # (type: string) Property which represents image indexer service
    def IMAGE_INDEXER():
        return "imageindexingservice"
    @constant    # (type: string) Property which represents image metadata extraction service
    def IMAGE_METADATA_EXTRACTION():
        return "imagemetadataextractionservice"
    @constant    # (type: string) Property which represents internal name service
    def INTERNAL_NAME_SERVICE():
        return "ins"
    @constant    # (type: string) Property which represents selector extraction service
    def SELECTOR_EXTRACTION():
        return "selext"
    @constant    # (type: string) Property which represents ssr service
    def SSR():
        return "ssrService"
    @constant    # (type: string) Property which represents temporal normalizer service
    def TEMPORAL_NORMALIZER():
        return "temporalsvc"

    # [Elastic Search Constants]
    @constant    # (type: string) Property which represents elastic search cluster name key in ezconfig
    def ELASTICSEARCH_CLUSTER_NAME():
        return "elastic.cluster.name"
    @constant    # (type: string) Property which represents elastic search force refresh key in ezconfig
    def ELASTICSEARCH_FORCE_REFRESH_ON_PUT():
        return "elastic.force.refresh"
    @constant    # (type: string) Property which represents elastic search host name key in ezconfig
    def ELASTICSEARCH_HOST():
        return "elastic.host.name"
    @constant    # (type: string) Property which represents elastic search port key in ezconfig
    def ELASTICSEARCH_PORT():
        return "elastic.port"

    # [Hadoop Constants]
    @constant    # (type: string) Property which represents ezconfig string to get default filesystem name
    def HADOOP_FILESYSTEM_NAME():
        return "fs.default.name"
    @constant    # (type: string) Property which represents ezconfig string to get hdfs implementation
    def HADOOP_FILESYSTEM_IMPL():
        return "fs.hdfs.impl"
    @constant    # (type: string) Property which represents ezconfig string to get filesystem use local value
    def HADOOP_FILESYSTEM_USE_LOCAL():
        return "fs.use.local"

    # [Flume Constants]
    @constant    # (type: string) Property which represents flume key for agent type
    def FLUME_AGENT_TYPE():
        return "flume.agent.type"
    @constant    # (type: string) Property which represents flume key for backoff
    def FLUME_BACK_OFF():
        return "flume.backoff"
    @constant    # (type: string) Property which represents flume key for batch size
    def FLUME_BATCH_SIZE():
        return "flume.batch.size"
    @constant    # (type: string) Property which represents flume key for connect attempts
    def FLUME_CONNECT_ATTEMPTS():
        return "flume.connect.attempts"
    @constant    # (type: string) Property which represents flume key for connect timeout
    def FLUME_CONNECT_TIMEOUT():
        return "flume.connect.timeout"
    @constant    # (type: string) Property which represents flume key for headers
    def FLUME_HEADERS():
        return "flume.headers"
    @constant    # (type: string) Property which represents flume key for host selector
    def FLUME_HOST_SELECTOR():
        return "flume.host.selector"
    @constant    # (type: string) Property which represents flume key for hosts
    def FLUME_HOSTS():
        return "flume.hosts"
    @constant    # (type: string) Property which represents flume key for max attempts
    def FLUME_MAX_ATTEMPTS():
        return "flume.max.attempts"
    @constant    # (type: string) Property which represents flume key for max backoff
    def FLUME_MAX_BACKOFF():
        return "flume.max.backoff"
    @constant    # (type: string) Property which represents flume key for max events
    def FLUME_MAX_EVENTS():
        return "flume.max.events"
    @constant    # (type: string) Property which represents flume key for request timeout
    def FLUME_REQUEST_TIMEOUT():
        return "flume.request.timeout"
    @constant    # (type: string) Property which represents flume key for run interval
    def FLUME_RUN_INTERVAL():
        return "flume.run.interval"
    @constant    # (type: string) Property which represents flume key for sleep interval
    def FLUME_SLEEP_INTERVAL():
        return "flume.sleep.interval"

    # [Kafka Constants]
    @constant    # (type: string) Property which represents kafka zookeeper connection string
    def KAFKA_ZOOKEEPER():
        return "kafka.zookeeper.connect"
    @constant    # (type: string) Property which represents kafka broker list ezconfig property
    def KAFKA_BROKER_LIST():
        return "kafka.metadata.broker.list"
    @constant    # (type: int) Property which represents the time that messages stay in memory before flushed to Kafka if using an async producer (in milliseconds)
    def KAFKA_QUEUE_TIME():
        return "kafka.queue.time"
    @constant    # (type: string) Property which represents the amount of messages that are queued in memory before flushing to Kafka if using an async producer
    def KAFKA_QUEUE_SIZE():
        return "kafka.queue.size"
    @constant    # (type: string) Property which represents the type of producer (sync or async) used by Kafka
    def KAFKA_PRODUCER_TYPE():
        return "kafka.producer.type"
    @constant    # (type: int) Property which represents the zookeeper timeout for Kafka consumers
    def KAFKA_ZOOKEEPER_SESSION_TIMEOUT():
        return "kafka.zk.sessiontimeout.ms"

    # [Mongo Configuration Constants]
    @constant    # (type: string) Property which represents mongo db host name ezconfig key
    def MONGODB_HOST_NAME():
        return "mongodb.host.name"
    @constant    # (type: int) Property which represents mongo db port number key
    def MONGODB_PORT():
        return "mongodb.port"
    @constant    # (type: string) Property which represents mongo db database name ezconfig key
    def MONGODB_DB_NAME():
        return "mongodb.database.name"
    @constant    # (type: string) Property which represents mongo db user name ezconfig key
    def MONGODB_USER_NAME():
        return "mongodb.user.name"
    @constant    # (type: string) Property which represents mongo db password ezconfig key
    def MONGODB_PASSWORD():
        return "mongodb.password"
    @constant    # (type: string) Property which represents mongo db use ssl ezconfig key
    def MONGODB_USE_SSL():
        return "mongodb.use.ssl"
    @constant    # (type: string) Property which represents the connection string that can be used to access mongo
    def MONGODB_CONNECTION_STRING():
        return "mongodb.connection.string"

    # [Postgres Constants]
    @constant    # (type: string) Property which represents postgres db ezconfig key
    def POSTGRES_DB():
        return "postgres.db"
    @constant    # (type: string) Property which represents postgres host ezconfig key
    def POSTGRES_HOST():
        return "postgres.host"
    @constant    # (type: string) Property which represents postgres password ezconfig key
    def POSTGRES_PASSWORD():
        return "postgres.password"
    @constant    # (type: string) Property which represents postgres port ezconfig key
    def POSTGRES_PORT():
        return "postgres.port"
    @constant    # (type: string) Property which represents postgres username ezconfig key
    def POSTGRES_USERNAME():
        return "postgres.username"
    @constant    # (type: string) Property which represents whether postgres connection uses ssl ezconfig key
    def POSTGRES_USE_SSL():
        return "postgres.use.ssl"

    # [Redis Constants]
    @constant    # (type: int) Property which represents redis host ezconfig key
    def REDIS_HOST():
        return "redis.host"
    @constant    # (type: string) Property which represents redis post ezconfig key
    def REDIS_PORT():
        return "redis.port"
    @constant    # (type: int) Property which represents redis db index ezconfig key
    def REDIS_DB_INDEX():
        return "redis.db.index"

    # [Security Constants]
    @constant    # (type: string) Property which represents the security id
    def EZBAKE_SECURITY_ID():
        return "ezbake.security.app.id"
    @constant    # (type: string) Property which represents cache type ezconfig key
    def EZBAKE_USER_CACHE_TYPE():
        return "ezbake.security.cache.type"
    @constant    # (type: string) Property which represents cache ttl ezconfig key
    def EZBAKE_USER_CACHE_TTL():
        return "ezbake.security.cache.ttl"
    @constant    # (type: string) Property which represents cache size ezconfig key
    def EZBAKE_USER_CACHE_SIZE():
        return "ezbake.security.cache.size"
    @constant    # (type: string) Property which represents request expiration ezconfig key
    def EZBAKE_REQUEST_EXPIRATION():
        return "ezbake.security.request.expiration"
    @constant    # (type: string) Property which represents token expiration ezconfig key
    def EZBAKE_TOKEN_EXPIRATION():
        return "ezbake.security.token.ttl"
    @constant    # (type: int) How long after being issued a proxy token should be valid
    def EZBAKE_SECURITY_PROXYTOKEN_TTL():
        return "ezbake.security.proxytoken.ttl"
    @constant    # (type: int) How long after expiration a token can be re-issued
    def EZBAKE_SECURITY_TOKEN_REFRESH_LIMIT():
        return "ezbake.security.token.refresh.limit"
    @constant    # (type: string) Property which represents app registration implementation ezconfig key
    def EZBAKE_APP_REGISTRATION_IMPL():
        return "ezbake.security.app.service.impl"
    @constant    # (type: string) Property which represents admins file ezconfig key
    def EZBAKE_ADMINS_FILE():
        return "ezbake.security.admins.file"
    @constant    # (type: string) Property which represents service implementation ezconfig key
    def EZBAKE_USER_SERVICE_IMPL():
        return "ezbake.security.user.service.impl"
    @constant    # (type: string) Property which represents mock server ezconfig key
    def EZBAKE_SECURITY_SERVICE_MOCK_SERVER():
        return "ezbake.security.server.mock"
    @constant    # (type: string) Property which represents use forward proxy ezconfig key
    def EZBAKE_USE_FORWARD_PROXY():
        return "ezbake.frontend.use.forward.proxy"
    @constant    # (type: string) Property which represents ssl protocol ezconfig key
    def EZBAKE_SSL_PROTOCOL_KEY():
        return "ezbake.ssl.protocol"
    @constant    # (type: string) Property which represents ssl ciphers ezconfig key
    def EZBAKE_SSL_CIPHERS_KEY():
        return "ezbake.ssl.ciphers"
    @constant    # (type: string) Property which represents peer validation ezconfig key
    def EZBAKE_SSL_PEER_AUTH_REQUIRED():
        return "ezbake.ssl.peer.validation"
    @constant    # (type: boolean) Property which tells us if we are using the default ssl key
    def EZBAKE_SSL_USE_DEFAULT_SSL_KEY():
        return "ezbake.security.default.ssl"
    @constant    # (type: string) Property which represents the trusted certificates file
    def EZBAKE_APPLICATION_TRUSTED_CERT():
        return "ezbake.ssl.trustedcert.file"
    @constant    # (type: string) Property which represents the private key file
    def EZBAKE_APPLICATION_PRIVATE_KEY_FILE():
        return "ezbake.ssl.privatekey.file"
    @constant    # (type: string) Property which represents the certificates file
    def EZBAKE_APPLICATION_CERT_FILE():
        return "ezbake.ssl.certificate.file"
    @constant    # (type: string) Property which represents the public key file for a service
    def EZBAKE_APPLICATION_PUBLIC_KEY_FILE():
        return "ezbake.ssl.servicekey.file"

    # [SSL Constants]
    @constant    # (type: string) Property which represents the path to the system keystore
    def SYSTEM_KEYSTORE_PATH():
        return "system.keystore.path"
    @constant    # (type: string) Property which represents the type of the system keystore
    def SYSTEM_KEYSTORE_TYPE():
        return "system.keystore.type"
    @constant    # (type: string) Property which represents the password for the system keystore
    def SYSTEM_KEYSTORE_PASSWORD():
        return "system.keystore.password"
    @constant    # (type: string) Property which represents the path to the system truststore
    def SYSTEM_TRUSTSTORE_PATH():
        return "system.truststore.path"
    @constant    # (type: string) Property which represents the type of the system truststore
    def SYSTEM_TRUSTSTORE_TYPE():
        return "system.truststore.type"
    @constant    # (type: string) Property which represents the password for the system truststore
    def SYSTEM_TRUSTSTORE_PASSWORD():
        return "system.truststore.password"
    @constant    # (type: string) Property which represents keystore file ezconfig key
    def EZBAKE_APPLICATION_KEYSTORE_FILE():
        return "ezbake.ssl.keystore.file"
    @constant    # (type: string) Property which represents keystore type ezconfig key
    def EZBAKE_APPLICATION_KEYSTORE_TYPE():
        return "ezbake.ssl.keystore.type"
    @constant    # (type: string) Property which represents keystore password ezconfig key
    def EZBAKE_APPLICATION_KEYSTORE_PASS():
        return "ezbake.ssl.keystore.pass"
    @constant    # (type: string) Property which represents truststore file ezconfig key
    def EZBAKE_APPLICATION_TRUSTSTORE_FILE():
        return "ezbake.ssl.truststore.file"
    @constant    # (type: string) Property which represents truststore type ezconfig key
    def EZBAKE_APPLICATION_TRUSTSTORE_TYPE():
        return "ezbake.ssl.truststore.type"
    @constant    # (type: string) Property which represents truststore password ezconfig key
    def EZBAKE_APPLICATION_TRUSTSTORE_PASS():
        return "ezbake.ssl.truststore.pass"

    # [Service Constants]
    @constant    # (type: string) Property representing the location to the certificates directory
    def EZBAKE_CERTIFICATES_DIRECTORY():
        return "ezbake.security.ssl.dir"
    @constant    # (type: string) Property which represents the name of the service
    def EZBAKE_SERVICE_NAME():
        return "service.name"

    # [Storm Constants]
    @constant    # (type: string) Property representing the nimbus host
    def STORM_NIMBUS_HOST():
        return "storm.nimbus.host"
    @constant    # (type: int) Property representing the nimbus port
    def STORM_NIMBUS_THRIFT_PORT():
        return "storm.nimbus.thrift.port"

    # [System Constants]
    @constant    # (type: string) Property which represents ezbake admin application deployment ezconfig key
    def EZBAKE_ADMIN_APPLICATION_DEPLOYMENT():
        return "ezbake.system.admin.application.deployment"
    @constant    # (type: string) Property which represents ezbake log directory ezconfig key
    def EZBAKE_LOG_DIRECTORY():
        return "ezbake.log.directory"
    @constant    # (type: string) Property which represents ezbake log standard out ezconfig key
    def EZBAKE_LOG_TO_STDOUT():
        return "ezbake.log.stdout"
    @constant    # (type: string) Property which represents the environment variable for the shared secret
    def EZBAKE_SHARED_SECRET_ENVIRONMENT_VARIABLE():
        return "ezbake.shared.secret.environment.variable"

    # [System Services Constants]
    @constant    # (type: string) Property which represents frontend service
    def FRONTEND():
        return "ezfrontend"

    # [Thrift Constants]
    @constant    # (type: string) Property which represents thrifts max idle clients ezconfig key
    def THRIFT_MAX_IDLE_CLIENTS():
        return "thrift.max.idle.clients"
    @constant    # (type: string) Property which represents thrifts max pool clients ezconfig key
    def THRIFT_MAX_POOL_CLIENTS():
        return "thrift.max.pool.clients"
    @constant    # (type: string) Property which represents thrifts milliseconds between client eviction checks ezconfig key
    def THRIFT_MILLIS_BETWEEN_CLIENT_EVICTION_CHECKS():
        return "thrift.millis.between.client.eviction.checks"
    @constant    # (type: string) Property which represents thrifts milliseconds before client eviction ezconfig key
    def THRIFT_MILLIS_IDLE_BEFORE_EVICTION():
        return "thrift.millis.idle.before.eviction"
    @constant    # (type: string) Property which represents thrifts server mode ezconfig key
    def THRIFT_SERVER_MODE():
        return "thrift.server.mode"
    @constant    # (type: string) Property which represents thrifts test pool on borrow ezconfig key
    def THRIFT_TEST_ON_BORROW():
        return "thrift.test.pool.on.borrow"
    @constant    # (type: string) Property which represents thrifts test while idle ezconfig key
    def THRIFT_TEST_WHILE_IDLE():
        return "thrift.test.pool.while.idle"
    @constant    # (type: string) Property which represents thrifts use ssl ezconfig key
    def THRIFT_USE_SSL():
        return "thrift.use.ssl"
    @constant    # (type: boolean) Property which represents if the client pool should block on exhaustion or throw an exception
    def THRIFT_BLOCK_WHEN_EXHAUSTED():
        return "thrift.block.when.exhausted"
    @constant    # (type: boolean) Property which tells us to actually pool clients or not
    def THRIFT_ACTUALLY_POOL_CLIENTS():
        return "thrift.actually.pool.clients"
    @constant    # (type: boolean) Log a stack trace whenever an object is abandonded from the pool
    def THRIFT_LOG_ABANDONDED():
        return "thrift.pool.log.abandoned"
    @constant    # (type: boolean) Whether to abandon objects if they exceed the abandon timeout when borrow is called
    def THRIFT_ABANDON_ON_BORROW():
        return "thrift.pool.abandon.on.borrow"
    @constant    # (type: boolean) Whether to abandon objects if they exceed the abandon timeout when the evictor runs
    def THRIFT_ABANDON_ON_MAINTENANCE():
        return "thrift.pool.abandon.on.maintenance"
    @constant    # (type: string) Timeout in seconds before an abandoned object is removed
    def THRIFT_ABANDON_TIMEOUT():
        return "thrift.pool.abandon.timeout"

    # [Web Application Constants]
    @constant    # (type: string) Property which represents web application external domain ezconfig key
    def EZBAKE_WEB_APPLICATION_EXTERNAL_DOMAIN():
        return "web.application.external.domain"
    @constant    # (type: string) Property which represents web application metrics endpoint ezconfig key
    def EZBAKE_WEB_APPLICATION_METRICS_ENDPOINT():
        return "web.application.metrics.endpoint"
    @constant    # (type: string) Property which represents web application metrics siteid ezconfig key
    def EZBAKE_WEB_APPLICATION_METRICS_SITEID():
        return "web.application.metrics.siteid"
    @constant    # (type: string) Property which represents security description banner: text
    def EZBAKE_WEB_APPLICATION_BANNER_TEXT():
        return "web.application.security.banner.text"
    @constant    # (type: string) Property which represents security description banner: background color
    def EZBAKE_WEB_APPLICATION_BANNER_BGCOLOR():
        return "web.application.security.banner.background.color"
    @constant    # (type: string) Property which represents security description banner: text color
    def EZBAKE_WEB_APPLICATION_BANNER_TEXTCOLOR():
        return "web.application.security.banner.text.color"

    # [Zookeeper Constants]
    @constant    # (type: string) Property which is a CSV of zookeeper servers (host:port)
    def ZOOKEEPER_CONNECTION_STRING():
        return "zookeeper.connection.string"

    # [MonetDB Constants]
    @constant    # (type: string) The MonetDB Username
    def MONETDB_USERNAME():
        return "monetdb.username"
    @constant    # (type: string) The MonetDB Password
    def MONETDB_PASSWORD():
        return "monetdb.password"
    @constant    # (type: string) The hostname of the MonetDB server
    def MONETDB_HOSTNAME():
        return "monetdb.hostname"
    @constant    # (type: int) The port number that MonetDB is running on
    def MONETDB_PORT():
        return "monetdb.port"

EzBakePropertyConstants = __EzBakePropertyConstants()
