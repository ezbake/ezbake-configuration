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

describe 'DirectoryConfigurationLoader' do
  it "should set default to the directory to #{EzBakeConfiguration::EzConfigurationLoader::EzConfigurationLoaderConstants::EZCONFIGURATION_DEFAULT_DIR}" do
    current_env_value = ENV.delete(EzBakeConfiguration::EzConfigurationLoader::EzConfigurationLoaderConstants::EZ_CONFIGURATION_ENV_VAR)
    dir_loader = EzBakeConfiguration::DirectoryConfigurationLoader.new
    ENV[EzBakeConfiguration::EzConfigurationLoader::EzConfigurationLoaderConstants::EZ_CONFIGURATION_ENV_VAR] = current_env_value
    dir_loader.properties.should.nil?.should == false
    dir_loader.dir.should == EzBakeConfiguration::EzConfigurationLoader::EzConfigurationLoaderConstants::EZCONFIGURATION_DEFAULT_DIR
  end

  it "should set the directory to the environment variable if no directory is passed in and the environment variable is set" do
    current_env_value = ENV.delete(EzBakeConfiguration::EzConfigurationLoader::EzConfigurationLoaderConstants::EZ_CONFIGURATION_ENV_VAR)
    data_dir = File.join(File.dirname(__FILE__), '../data/config')
    ENV[EzBakeConfiguration::EzConfigurationLoader::EzConfigurationLoaderConstants::EZ_CONFIGURATION_ENV_VAR] = data_dir
    dir_loader = EzBakeConfiguration::DirectoryConfigurationLoader.new
    ENV[EzBakeConfiguration::EzConfigurationLoader::EzConfigurationLoaderConstants::EZ_CONFIGURATION_ENV_VAR] = current_env_value
    dir_loader.properties.should.nil?.should == false
    dir_loader.dir.should == data_dir
  end

  it 'should set the directory to the path passed in' do
    data_dir = File.join(File.dirname(__FILE__), '../data/config')
    dir_loader = EzBakeConfiguration::DirectoryConfigurationLoader.new data_dir
    dir_loader.properties.should.nil?.should == false
    dir_loader.dir.should == data_dir
  end

  it 'should be loadable if the directory set exists' do
    data_dir = File.join(File.dirname(__FILE__), '../data/config')
    dir_loader = EzBakeConfiguration::DirectoryConfigurationLoader.new data_dir
    dir_loader.loadable?.should == true
  end

  it 'should not be loadable if the directory set does not exists' do
    data_dir = File.join(File.dirname(__FILE__), '../data/config/foo')
    dir_loader = EzBakeConfiguration::DirectoryConfigurationLoader.new data_dir
    dir_loader.loadable?.should == false
  end

  it 'should return an empty hash if load_configuration is called on an empty directory' do
    data_dir = File.join(File.dirname(__FILE__), '../data/config/empty')
    dir_loader = EzBakeConfiguration::DirectoryConfigurationLoader.new data_dir
    res = dir_loader.load_configuration
    res.class.should == Hash
    res.length.should == 0
  end

  it 'should load all the properties files of the given directory' do
    data_dir = File.join(File.dirname(__FILE__), '../data/config')
    dir_loader = EzBakeConfiguration::DirectoryConfigurationLoader.new data_dir
    res = dir_loader.load_configuration
    res.class.should == Hash
    res.length.should == 9
  end

  it "should ignore properties that start with a #{EzBakeConfiguration::EzConfigurationLoader::EzConfigurationLoaderConstants::EZCONFIGURATION_PROPERTY_FILE_COMMENT_CHARACTER}" do
    data_dir = File.join(File.dirname(__FILE__), '../data/config')
    dir_loader = EzBakeConfiguration::DirectoryConfigurationLoader.new data_dir
    res = dir_loader.load_configuration
    res['test.prop'].should == nil
  end

  it "should ignore files that do not end in #{EzBakeConfiguration::EzConfigurationLoader::EzConfigurationLoaderConstants::EZCONFIGURATION_PROPERTY_FILE_EXTENSION}" do
    data_dir = File.join(File.dirname(__FILE__), '../data/config')
    dir_loader = EzBakeConfiguration::DirectoryConfigurationLoader.new data_dir
    res = dir_loader.load_configuration
    res['skip.this.property'].should == nil
  end

  it 'should overwrite a property if it is also found in a later file' do
      data_dir = File.join(File.dirname(__FILE__), '../data/config')
      dir_loader = EzBakeConfiguration::DirectoryConfigurationLoader.new data_dir
      res = dir_loader.load_configuration
      res['stark.ned'].should == 'Warden of the North'
  end
end