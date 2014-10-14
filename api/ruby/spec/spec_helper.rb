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

require 'rspec'
require 'rspec/expectations'

require 'ez_bake_configuration'

ENCRYPTED_FOO = 'uZmGXbIofro='
WRAPPED_ENCRYPTED_FOO = "ENC~(#{ENCRYPTED_FOO})~"
DECRYPTED_FOO = 'foo'

ENCRYPTED_KING_OF_THE_NORTH = 'eitre2mNCN+VVR5aN4EIhg=='
WRAPPED_ENCRYPTED_KING_OF_THE_NORTH = "ENC~(#{ENCRYPTED_KING_OF_THE_NORTH})~"
DECRYPTED_KING_OF_THE_NORTH = 'KingOfTheNorth'

PROPERTIES = { 'foo' => 'bar', 'ned.stark' => 'Warden of the North'}
ENCRYPTED_PROPERTIES = { 'foo' => WRAPPED_ENCRYPTED_FOO, 'ned.stark' => WRAPPED_ENCRYPTED_KING_OF_THE_NORTH}
PASSWORD = 'password'