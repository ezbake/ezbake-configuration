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
 * SecurityConfiguration.h
 *
 *  Created on: Mar 21, 2014
 *      Author: oarowojolu
 */

#ifndef EZBAKE_EZCONFIGURATION_HELPERS_SECURITYCONFIGURATION_H_
#define EZBAKE_EZCONFIGURATION_HELPERS_SECURITYCONFIGURATION_H_

#include <boost/shared_ptr.hpp>
#include <openssl/evp.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <ezbake/ezconfiguration/helpers/ApplicationConfiguration.h>
#include <ezbake/ezconfiguration/helpers/SystemConfiguration.h>
#include <ezbake/ezconfiguration/util/CryptoUtil.h>

namespace ezbake { namespace ezconfiguration { namespace helpers {

class SecurityConfiguration: public BaseConfiguration {
public:
    class UserCacheType {
    friend class SecurityConfiguration;
    public:
        virtual ~UserCacheType() {}

        inline const ::std::string& toString() const {
            return _name;
        }

        inline bool operator==(const UserCacheType& rhs) const {
            return (_name == rhs._name);
        }

        inline bool operator!=(const UserCacheType& rhs) const {
            return !(*this == rhs);
        }

        static UserCacheType valueOf(const ::std::string& val) {
            UserCacheType mode = MEMORY;
            if (REDIS._name == val) {
                mode = REDIS;
            } else if (MEMORY._name != val){
                BOOST_THROW_EXCEPTION(std::invalid_argument(val + " is not a supported user cache mode"));
            }
            return mode;
        }

    private:
        UserCacheType(const ::std::string& name) : _name(name) {}
        ::std::string _name;
    };
    friend class UserCacheType;


public:
    static const UserCacheType MEMORY;
    static const UserCacheType REDIS;


    /** SSL properties **/
    static const ::std::string SSL_PEER_AUTH_REQUIRED;
    static const ::std::string SSL_PROTOCOL_KEY;
    static const ::std::string SSL_CIPHERS_KEY;

    /** Application SSL Key properties **/
    static const ::std::string APPLICATION_TRUSTED_CERT;
    static const ::std::string APPLICATION_PRIVATE_KEY_FILE;
    static const ::std::string APPLICATION_CERT_FILE;
    static const ::std::string APPLICATION_PUBLIC_KEY_FILE;

    /** Security Cache properties **/
    static const ::std::string USER_CACHE_TYPE_KEY;
    static const ::std::string USER_CACHE_TTL_KEY;
    static const ::std::string USER_CACHE_SIZE_KEY;

    /** EzFrontend properties **/
    static const ::std::string USE_FORWARD_PROXY;


    /** default values **/
    static const ::std::string DEFAULT_SSL_PROTOCOLS;
    static const ::std::string DEFAULT_SSL_CIPHERS;
    static const ::std::string DEFAULT_TURSTED_SSL_CERTS;
    static const ::std::string DEFAULT_SSL_CERT;
    static const ::std::string DEFAULT_PRIVATE_KEY;
    static const ::std::string DEFAULT_SERVICE_PUBLIC_KEY;

public:
    inline bool isPeerAuthRequired() const {
        return ezConfiguration.getBoolean(parseKey(SSL_PEER_AUTH_REQUIRED), true);
    }

    inline bool useForwardProxy() const {
        return ezConfiguration.getBoolean(parseKey(USE_FORWARD_PROXY), false);
    }

    inline UserCacheType getCacheType() const {
        return UserCacheType::valueOf(ezConfiguration.getString(parseKey(USER_CACHE_TYPE_KEY), MEMORY.toString()));
    }

    inline long getUserCacheTTL() const {
        return ezConfiguration.getLong(parseKey(USER_CACHE_TTL_KEY), 43200);
    }

    inline int getUserCacheSize() const {
        return ezConfiguration.getInt(parseKey(USER_CACHE_SIZE_KEY), 1000);
    }

    inline ::std::string getCertificatesDir() const {
        return ApplicationConfiguration::fromConfiguration(ezConfiguration, namespacePrefix)->getCertificatesDir();
    }

    inline ::std::string getSecurityId() const {
        return ApplicationConfiguration::fromConfiguration(ezConfiguration, namespacePrefix)->getSecurityID();
    }

    inline ::std::string getSslCiphers() const {
        return ezConfiguration.getString(parseKey(SSL_CIPHERS_KEY), DEFAULT_SSL_CIPHERS);
    }

    inline ::std::string getSslProtocols() const {
        return ezConfiguration.getString(parseKey(SSL_PROTOCOL_KEY), DEFAULT_SSL_PROTOCOLS);
    }

    inline ::std::string trustedCert(const ::std::string& serviceName="") const {
        return ezConfiguration.getString(
                parseServiceKey(parseKey(APPLICATION_TRUSTED_CERT), serviceName),
                DEFAULT_TURSTED_SSL_CERTS);
    }

    inline ::std::string privateKey(const ::std::string& serviceName="") const {
        return ezConfiguration.getString(
                parseServiceKey(parseKey(APPLICATION_PRIVATE_KEY_FILE), serviceName),
                DEFAULT_PRIVATE_KEY);
    }

    inline ::std::string certificate(const ::std::string& serviceName="") const {
        return ezConfiguration.getString(
                parseServiceKey(parseKey(APPLICATION_CERT_FILE), serviceName),
                DEFAULT_SSL_CERT);
    }

    inline ::std::string servicePublicKey(const ::std::string& serviceName="") const {
        return ezConfiguration.getString(
                parseServiceKey(parseKey(APPLICATION_PUBLIC_KEY_FILE), serviceName),
                DEFAULT_SERVICE_PUBLIC_KEY);
    }

    inline ::std::string getPrivateKey(const ::std::string& serviceName="") const {
        return getCertificatesDir() + SystemConfiguration::FILE_SEPERATOR + privateKey(serviceName);
    }

    ::std::string getTrustedSslCerts(const ::std::string& serviceName="") const {
        return getCertificatesDir() + SystemConfiguration::FILE_SEPERATOR + trustedCert(serviceName);
    }

    ::std::string getSslCertificate(const ::std::string& serviceName="") const {
        return getCertificatesDir() + SystemConfiguration::FILE_SEPERATOR + certificate(serviceName);
    }

    ::std::string getServicePublicKey(const ::std::string& serviceName="") const {
        return getCertificatesDir() + SystemConfiguration::FILE_SEPERATOR + servicePublicKey(serviceName);
    }

    void setPrivateKey(const ::std::string& serviceName="") {
        FILE * pk = fopen(getPrivateKey(serviceName).c_str(), "rb");
        if (NULL == pk) {
            BOOST_THROW_EXCEPTION(std::runtime_error("Error in opening private key file"));
        }
        _privateKey.reset(PEM_read_RSAPrivateKey(pk,NULL,NULL,NULL));
        fclose(pk);

        if (NULL == _privateKey.get()) {
            BOOST_THROW_EXCEPTION(std::runtime_error("Error in reading private key: PEM_read_RSAPrivateKey returned NULL"));
        }
    }

    void setPublicKey(const ::std::string& serviceName="") {
        FILE * pk = fopen(getServicePublicKey(serviceName).c_str(), "rb");
        if (NULL == pk) {
            BOOST_THROW_EXCEPTION(std::runtime_error("Error in opening public key file"));
        }
        //_publicKey.reset(PEM_read_RSAPublicKey(pk,NULL,NULL,NULL));
        _publicKey.reset(PEM_read_RSA_PUBKEY(pk,NULL,NULL,NULL));
        fclose(pk);

        if (NULL == _publicKey.get()) {
            //BOOST_THROW_EXCEPTION(std::runtime_error("Error in reading public key: PEM_read_RSAPublicKey returned NULL"));
            BOOST_THROW_EXCEPTION(std::runtime_error("Error in reading public key: PEM_read_RSA_PUBKEY returned NULL"));
        }
    }

    void setKeys() {
        FILE * pk = fopen(getPrivateKey().c_str(), "rb");
        if (NULL == pk) {
            BOOST_THROW_EXCEPTION(std::runtime_error("Error in opening private key file"));
        }
        _privateKey.reset(PEM_read_RSAPrivateKey(pk,NULL,NULL,NULL));
        fclose(pk);

        pk = fopen(getServicePublicKey().c_str(), "rb");
        if (NULL == pk) {
            BOOST_THROW_EXCEPTION(std::runtime_error("Error in opening public key file"));
        }
        //_publicKey.reset(PEM_read_RSAPublicKey(pk,NULL,NULL,NULL));
        _publicKey.reset(PEM_read_RSA_PUBKEY(pk,NULL,NULL,NULL));
        fclose(pk);

        if (NULL == _privateKey.get()) {
            BOOST_THROW_EXCEPTION(std::runtime_error("Error in reading private key: PEM_read_RSAPrivateKey returned NULL"));
        }
        if (NULL == _publicKey.get()) {
            //BOOST_THROW_EXCEPTION(std::runtime_error("Error in reading public key: PEM_read_RSAPublicKey returned NULL"));
            BOOST_THROW_EXCEPTION(std::runtime_error("Error in reading public key: PEM_read_RSA_PUBKEY returned NULL"));
        }
    }

    bool hasPrivateKeySet() const {
        return (_privateKey.get() != NULL);
    }

    bool hasPublicKeySet() const {
        return (_publicKey.get() != NULL);
    }

    bool hasKeysSet() const {
        return (hasPrivateKeySet() && hasPublicKeySet());
    }

    ::std::string sign(const ::std::string& serializedData) const {
        if (!hasPrivateKeySet()) {
            BOOST_THROW_EXCEPTION(std::runtime_error("Cannot sign data. Private key has not been set. Did you call setPrivateKey/setKeys?"));
        }

        try {
            ::std::string digest = generateDigest(serializedData);

            unsigned int rawSigLength = 0;
            unsigned char *rawSig = new unsigned char [RSA_size(_privateKey.get())];

            RSA_sign(EVP_MD_type(_ALGORITHM), reinterpret_cast<unsigned char*>(const_cast<char*>(digest.c_str())),
                    static_cast<unsigned int>(digest.length()), rawSig, &rawSigLength, _privateKey.get());

            ::std::string signature = ::ezbake::ezconfiguration::util::CryptoUtil::encode(reinterpret_cast<const char*>(rawSig),
                                                                                        rawSigLength);
            delete[] rawSig;
            return signature;
        } catch (std::exception &e) {
            BOOST_THROW_EXCEPTION(std::runtime_error(::std::string("Error in signing data: ") + e.what()));
        }
        return "";
    }

    bool verify(const ::std::string& data, const ::std::string& base64Signature) const {
        if (!hasPublicKeySet()) {
            BOOST_THROW_EXCEPTION(std::runtime_error("Cannot verify data. Public key has not been set. Did you call setPublicKey/setKeys?"));
        }

        try {
            ::std::string digest = generateDigest(data);
            ::std::string signature = ::ezbake::ezconfiguration::util::CryptoUtil::decode(base64Signature);

            return RSA_verify(EVP_MD_type(_ALGORITHM),
                    reinterpret_cast<unsigned char*>(const_cast<char *>(digest.c_str())),
                    static_cast<unsigned int>(digest.length()),
                    reinterpret_cast<unsigned char*>(const_cast<char *>(signature.data())), 
                    static_cast<unsigned int>(signature.length()),
                    _publicKey.get());

        } catch (std::exception &e) {
            BOOST_THROW_EXCEPTION(std::runtime_error(::std::string("Error in verifying data: ") + e.what()));
        }
        return false;
    }

    static boost::shared_ptr<SecurityConfiguration> fromConfiguration(const ::ezbake::ezconfiguration::EZConfiguration& configuration,
            const ::std::string& namespacePrefix = "") {
        boost::shared_ptr<SecurityConfiguration> p(new SecurityConfiguration(configuration, namespacePrefix));
        return p;
    }

    static ::std::string parseServiceKey(const ::std::string& key, const ::std::string& serviceName) {
        if (::std::string::npos != serviceName.find_first_not_of(' ')) {
            return key + "." + serviceName;
        }
        return key;
    }

    virtual ~SecurityConfiguration() {}

private:
    ::std::string generateDigest(const ::std::string& data) const {
        EVP_MD_CTX *ctx = EVP_MD_CTX_create();
        unsigned char md[EVP_MAX_MD_SIZE];
        unsigned int mdLength = 0;
        EVP_add_digest(_ALGORITHM);
        if (!EVP_DigestInit_ex(ctx, _ALGORITHM, NULL) ||
            !EVP_DigestUpdate(ctx, data.data(), data.length()) ||
            !EVP_DigestFinal_ex(ctx, md, &mdLength)) {
            EVP_MD_CTX_destroy(ctx);
            BOOST_THROW_EXCEPTION(std::runtime_error("Error in generating digest"));
        }
        EVP_MD_CTX_destroy(ctx);

        return ::std::string(reinterpret_cast<char *>(md), mdLength);
    }

    SecurityConfiguration(const ::ezbake::ezconfiguration::EZConfiguration& configuration,
            const ::std::string& namespacePrefix)
        : BaseConfiguration(configuration, namespacePrefix) {}

private:
    static const EVP_MD * _ALGORITHM;

    ::boost::shared_ptr<RSA> _publicKey;
    ::boost::shared_ptr<RSA> _privateKey;
};

}}} // namespace ::ezbake::ezconfiguration::helpers

#endif /* EZBAKE_EZCONFIGURATION_HELPERS_SECURITYCONFIGURATION_H_ */
