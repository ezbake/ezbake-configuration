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

describe 'PropertiesConfigurationLoader' do
  it 'should be loadable' do
    loader = EzBakeConfiguration::PropertiesConfigurationLoader.new
    loader.loadable?.should == true
  end

  it 'should load an empty hash if no properties were passed in' do
    loader = EzBakeConfiguration::PropertiesConfigurationLoader.new
    props = loader.load_configuration
    props.class.should == Hash
    props.length.should == 0
  end

  it 'should return the passed in properties when load_configuration is called' do
    loader = EzBakeConfiguration::PropertiesConfigurationLoader.new(PROPERTIES)
    props = loader.load_configuration
    props.class.should == Hash
    props.length.should == 2
    props['foo'].should == 'bar'
    props['ned.stark'].should == 'Warden of the North'
  end
end