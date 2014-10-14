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

require_relative '../spec_helper'

describe 'EncryptedProperties' do
  it 'should merge the passed in properties to its self' do
    hash = EzBakeConfiguration::Utils::EncryptedProperties.new PROPERTIES
    hash.length.should == 2
    hash['foo'].should == 'bar'
    hash['ned.stark'].should == 'Warden of the North'
  end

  it 'should be able to reference the hash with a symbol instead of a string' do
    hash = EzBakeConfiguration::Utils::EncryptedProperties.new PROPERTIES
    hash[:foo].should == 'bar'
  end

  it 'should be able to assign a new property' do
    hash = EzBakeConfiguration::Utils::EncryptedProperties.new
    hash[:foo] = 'bar'
    hash['foo'].should == 'bar'
  end

  it 'should return the encrypted values if no key is given' do
    hash = EzBakeConfiguration::Utils::EncryptedProperties.new ENCRYPTED_PROPERTIES
    hash.length.should == 2
    hash['foo'].should == WRAPPED_ENCRYPTED_FOO
    hash['ned.stark'].should == WRAPPED_ENCRYPTED_KING_OF_THE_NORTH
  end

  it 'should return decrypted values if a key is given' do
    hash = EzBakeConfiguration::Utils::EncryptedProperties.new ENCRYPTED_PROPERTIES, PASSWORD
    hash.length.should == 2
    hash['foo'].should == DECRYPTED_FOO
    hash['ned.stark'].should == DECRYPTED_KING_OF_THE_NORTH
  end

  it 'should accept an optional encryption implementation' do
    hash = EzBakeConfiguration::Utils::EncryptedProperties.new ENCRYPTED_PROPERTIES, PASSWORD, EzBakeConfiguration::Utils::PbeWithMd5AndDes
    hash.length.should == 2
    hash['foo'].should == DECRYPTED_FOO
    hash['ned.stark'].should == DECRYPTED_KING_OF_THE_NORTH
  end

  it 'should store an encrypted property as its decrypted value if cache_decrypted_values is set to true' do
    hash = EzBakeConfiguration::Utils::EncryptedProperties.new ENCRYPTED_PROPERTIES, PASSWORD, EzBakeConfiguration::Utils::PbeWithMd5AndDes, true
    hash.length.should == 2
    base_hash = {}.merge(hash)
    base_hash.length.should == 2
    base_hash['foo'].should == WRAPPED_ENCRYPTED_FOO
    hash['foo']
    base_hash = {}.merge(hash)
    base_hash.length.should == 2
    base_hash['foo'].should == DECRYPTED_FOO
  end

  it 'should properly set the cache_decrypted_values flag when no encryption implementation is given' do
    hash = EzBakeConfiguration::Utils::EncryptedProperties.new ENCRYPTED_PROPERTIES, PASSWORD, true
    hash.length.should == 2
    base_hash = {}.merge(hash)
    base_hash.length.should == 2
    base_hash['foo'].should == WRAPPED_ENCRYPTED_FOO
    hash['foo']
    base_hash = {}.merge(hash)
    base_hash.length.should == 2
    base_hash['foo'].should == DECRYPTED_FOO
  end

  it 'should set the value encrypted if set encrypted is called when initialized with a key' do
    hash = EzBakeConfiguration::Utils::EncryptedProperties.new({}, PASSWORD)
    hash.set_encrypted 'foo', DECRYPTED_FOO
    base_hash = {}.merge(hash)
    base_hash['foo'].should == WRAPPED_ENCRYPTED_FOO
  end
end