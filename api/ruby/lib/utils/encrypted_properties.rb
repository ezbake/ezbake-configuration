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
     class EncryptedProperties < Hash
       def initialize properties={}, key=nil, encryption_implementation=nil, cache_decrypted_values=false
         self.merge! properties
         @encryption_util = nil
         if !encryption_implementation.nil? && encryption_implementation.is_a?(TrueClass) # allows for cache_decrypted_values to be set with out an encryption implementation being set
           cache_decrypted_values = true
           encryption_implementation = nil
         end
         unless key.nil?
           @encryption_util = encryption_implementation.nil? ? EncryptionUtil.new(key) : EncryptionUtil.new(key, encryption_implementation)
         end
         @cache_decrypted_values = cache_decrypted_values
         self
       end

       def[] property_key
         value = super property_key.to_s
         if !@encryption_util.nil? && @encryption_util.encrypted?(value)
           value = @encryption_util.decrypt_value value
           self[property_key] = value if @cache_decrypted_values
         end
         value
       end

       def[]= property_key, property_value
         super property_key.to_s, property_value #ensure all keys are strings
       end

       def set_encrypted property_key, property_value
         self[property_key] = @encryption_util.nil? ? property_value : @encryption_util.encrypt_value(property_value)
       end
     end
  end
end