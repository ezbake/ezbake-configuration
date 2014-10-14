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

require 'openssl'
require 'base64'
module EzBakeConfiguration
  module Utils
    module EncryptionConstants
      SALT = 'bouncycastle'
      ITERATIONS = 1000
      BYTES_FOR_SALT = 8
    end

    module PbeWithMd5AndDes
      def PbeWithMd5AndDes.encrypt key, payload
        cipher = OpenSSL::Cipher::Cipher.new('DES')
        cipher.encrypt
        cipher.pkcs5_keyivgen key, EncryptionConstants::SALT[0,EncryptionConstants::BYTES_FOR_SALT], EncryptionConstants::ITERATIONS
        encypted_payload = cipher.update(payload)
        encypted_payload << cipher.final
        Base64.encode64(encypted_payload).gsub /\n/, '' #removes newline characters added by encoding
      end

      def PbeWithMd5AndDes.decrypt key, encrypted_payload
        cipher = OpenSSL::Cipher::Cipher.new('DES')
        base_64_code = Base64.decode64(encrypted_payload)
        cipher.decrypt
        cipher.pkcs5_keyivgen key, EncryptionConstants::SALT[0,EncryptionConstants::BYTES_FOR_SALT], EncryptionConstants::ITERATIONS
        payload = cipher.update base_64_code
        payload << cipher.final
        payload
      end
    end
  end
end