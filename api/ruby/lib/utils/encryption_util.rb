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

module EzBakeConfiguration
  module Utils
    module EncryptionConstants
      ENCRYPTED_VALUE_PREFIX = 'ENC~('
      ENCRYPTED_VALUE_POSTFIX = ')~'
    end
    class EncryptionUtil
      def initialize key, encryption_implementation=PbeWithMd5AndDes
        @key = key
        @encryption_implementation = encryption_implementation
      end

      def encrypted? payload
        payload.start_with?(EncryptionConstants::ENCRYPTED_VALUE_PREFIX) && payload.end_with?(EncryptionConstants::ENCRYPTED_VALUE_POSTFIX)
      end

      def encrypt_value payload
        wrap_encrypted_value @encryption_implementation.encrypt(@key, payload)
      end

      def decrypt_value payload
        return payload unless encrypted? payload
        @encryption_implementation.decrypt @key, unwrap_encrypted_value(payload)
      end

      private
      def wrap_encrypted_value payload
        EncryptionConstants::ENCRYPTED_VALUE_PREFIX + payload + EncryptionConstants::ENCRYPTED_VALUE_POSTFIX
      end

      def unwrap_encrypted_value payload
        payload.gsub(/^#{Regexp.escape(EncryptionConstants::ENCRYPTED_VALUE_PREFIX)}/, '').gsub(/#{Regexp.escape(EncryptionConstants::ENCRYPTED_VALUE_POSTFIX)}$/, '')
      end

    end
  end
end