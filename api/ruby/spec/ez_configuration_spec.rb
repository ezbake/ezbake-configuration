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

require 'spec_helper'

describe 'EzConfiguration' do
  it 'should load the default loaders if no loaders are given' do
    current_env_value = ENV.delete(EzBakeConfiguration::EzConfigurationLoader::EzConfigurationLoaderConstants::EZ_CONFIGURATION_ENV_VAR)
    data_dir = File.join(File.dirname(__FILE__), './data/config')
    ENV[EzBakeConfiguration::EzConfigurationLoader::EzConfigurationLoaderConstants::EZ_CONFIGURATION_ENV_VAR] = data_dir
    conf = EzBakeConfiguration::EzConfiguration.new
    ENV[EzBakeConfiguration::EzConfigurationLoader::EzConfigurationLoaderConstants::EZ_CONFIGURATION_ENV_VAR] = current_env_value
    conf.properties.length.should == 9
  end

  it 'should load properties of the given loader if a loader is passed in' do
    loader = EzBakeConfiguration::PropertiesConfigurationLoader.new({'foo'=> '1', 'bar' => '2'})
    conf = EzBakeConfiguration::EzConfiguration.new loader
    conf.properties.length.should == 2
    conf.properties['foo'].should == '1'
    conf.properties['bar'].should == '2'
  end

  it 'should override properties from the first loader with properties from the second loader' do
    loader = EzBakeConfiguration::PropertiesConfigurationLoader.new({'foo'=> '1', 'bar' => '2'})
    loader2 = EzBakeConfiguration::PropertiesConfigurationLoader.new({'baz'=> '4', 'bar' => '3'})
    conf = EzBakeConfiguration::EzConfiguration.new loader, loader2
    conf.properties.length.should == 3
    conf.properties['foo'].should == '1'
    conf.properties['bar'].should == '3'
    conf.properties['baz'].should == '4'
  end
end