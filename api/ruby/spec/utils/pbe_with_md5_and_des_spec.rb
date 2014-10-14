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

describe 'PbeWithMd5AndDes' do
  it "encrypts #{DECRYPTED_FOO} to #{ENCRYPTED_FOO} when the password is '#{PASSWORD}'" do
    EzBakeConfiguration::Utils::PbeWithMd5AndDes.encrypt(PASSWORD, DECRYPTED_FOO).should == ENCRYPTED_FOO
  end

  it "decrypts #{ENCRYPTED_FOO} to #{DECRYPTED_FOO} when the password is '#{PASSWORD}'" do
    EzBakeConfiguration::Utils::PbeWithMd5AndDes.decrypt(PASSWORD, ENCRYPTED_FOO).should == DECRYPTED_FOO
  end

  it "encrypts #{DECRYPTED_KING_OF_THE_NORTH} to #{ENCRYPTED_KING_OF_THE_NORTH} when the password is '#{PASSWORD}'"do
    EzBakeConfiguration::Utils::PbeWithMd5AndDes.encrypt(PASSWORD, DECRYPTED_KING_OF_THE_NORTH).should == ENCRYPTED_KING_OF_THE_NORTH
  end

  it "decrypts #{ENCRYPTED_KING_OF_THE_NORTH} to #{DECRYPTED_KING_OF_THE_NORTH} when the password is '#{PASSWORD}'" do
    EzBakeConfiguration::Utils::PbeWithMd5AndDes.decrypt(PASSWORD, ENCRYPTED_KING_OF_THE_NORTH).should == DECRYPTED_KING_OF_THE_NORTH
  end
end