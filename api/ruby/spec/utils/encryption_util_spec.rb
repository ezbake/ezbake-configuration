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

util = EzBakeConfiguration::Utils::EncryptionUtil.new PASSWORD

describe 'EncryptionUtil' do
  it "encrypts #{DECRYPTED_FOO} to #{WRAPPED_ENCRYPTED_FOO} when the password is '#{PASSWORD}'" do
    util.encrypt_value(DECRYPTED_FOO).should == WRAPPED_ENCRYPTED_FOO
  end

  it "decrypts #{WRAPPED_ENCRYPTED_FOO} to #{DECRYPTED_FOO} when the password is '#{PASSWORD}'" do
    util.decrypt_value(WRAPPED_ENCRYPTED_FOO).should == DECRYPTED_FOO
  end

  it "encrypts #{DECRYPTED_KING_OF_THE_NORTH} to #{WRAPPED_ENCRYPTED_KING_OF_THE_NORTH} when the password is '#{PASSWORD}'" do
    util.encrypt_value(DECRYPTED_KING_OF_THE_NORTH).should == WRAPPED_ENCRYPTED_KING_OF_THE_NORTH
  end

  it "decrypts #{WRAPPED_ENCRYPTED_KING_OF_THE_NORTH} to #{DECRYPTED_KING_OF_THE_NORTH} when the password is '#{PASSWORD}'" do
    util.decrypt_value(WRAPPED_ENCRYPTED_KING_OF_THE_NORTH).should == DECRYPTED_KING_OF_THE_NORTH
  end

  it "reads #{WRAPPED_ENCRYPTED_FOO} as being encrypted" do
    util.encrypted?(WRAPPED_ENCRYPTED_FOO).should == true
  end

  it "reads #{DECRYPTED_FOO} as being not encrypted" do
    util.encrypted?(DECRYPTED_FOO).should == false
  end
end