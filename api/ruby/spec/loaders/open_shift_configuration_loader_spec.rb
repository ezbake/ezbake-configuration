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

describe 'OpenShiftConfigurationLoader' do
  it 'should not be loadable when no OpenShift environment variable is set' do
    current_env_value = ENV.delete(EzBakeConfiguration::EzConfigurationLoader::EzConfigurationLoaderConstants::OPENSHIFT_REPO_DIR_ENV_VAR)
    loader = EzBakeConfiguration::OpenShiftConfigurationLoader.new
    ENV[EzBakeConfiguration::EzConfigurationLoader::EzConfigurationLoaderConstants::OPENSHIFT_REPO_DIR_ENV_VAR] = current_env_value
    loader.properties.should.nil?.should == false
    loader.dir.should == nil
    loader.loadable?.should == false
  end

  it "should set the directory to the #{EzBakeConfiguration::EzConfigurationLoader::EzConfigurationLoaderConstants::OPENSHIFT_REPO_DIR_ENV_VAR}
      environment variable value and append it with #{EzBakeConfiguration::EzConfigurationLoader::EzConfigurationLoaderConstants::OPENSHIFT_PROPERTIES_DIR}" do
    current_env_value = ENV.delete(EzBakeConfiguration::EzConfigurationLoader::EzConfigurationLoaderConstants::OPENSHIFT_REPO_DIR_ENV_VAR)
    data_dir = File.join(File.dirname(__FILE__), '../data')
    ENV[EzBakeConfiguration::EzConfigurationLoader::EzConfigurationLoaderConstants::OPENSHIFT_REPO_DIR_ENV_VAR] = data_dir
    loader = EzBakeConfiguration::OpenShiftConfigurationLoader.new
    ENV[EzBakeConfiguration::EzConfigurationLoader::EzConfigurationLoaderConstants::OPENSHIFT_REPO_DIR_ENV_VAR] = current_env_value
    loader.properties.should.nil?.should == false
    loader.dir.should == File.join(data_dir, EzBakeConfiguration::EzConfigurationLoader::EzConfigurationLoaderConstants::OPENSHIFT_PROPERTIES_DIR)
    loader.loadable?.should == true
  end

  it 'should load all the properties files of the given directory' do
    current_env_value = ENV.delete(EzBakeConfiguration::EzConfigurationLoader::EzConfigurationLoaderConstants::OPENSHIFT_REPO_DIR_ENV_VAR)
    data_dir = File.join(File.dirname(__FILE__), '../data')
    ENV[EzBakeConfiguration::EzConfigurationLoader::EzConfigurationLoaderConstants::OPENSHIFT_REPO_DIR_ENV_VAR] = data_dir
    loader = EzBakeConfiguration::OpenShiftConfigurationLoader.new
    ENV[EzBakeConfiguration::EzConfigurationLoader::EzConfigurationLoaderConstants::OPENSHIFT_REPO_DIR_ENV_VAR] = current_env_value
    res = loader.load_configuration
    res.class.should == Hash
    res.length.should == 9
  end

  it "should ignore properties that start with a #{EzBakeConfiguration::EzConfigurationLoader::EzConfigurationLoaderConstants::EZCONFIGURATION_PROPERTY_FILE_COMMENT_CHARACTER}" do
    current_env_value = ENV.delete(EzBakeConfiguration::EzConfigurationLoader::EzConfigurationLoaderConstants::OPENSHIFT_REPO_DIR_ENV_VAR)
    data_dir = File.join(File.dirname(__FILE__), '../data')
    ENV[EzBakeConfiguration::EzConfigurationLoader::EzConfigurationLoaderConstants::OPENSHIFT_REPO_DIR_ENV_VAR] = data_dir
    loader = EzBakeConfiguration::OpenShiftConfigurationLoader.new
    ENV[EzBakeConfiguration::EzConfigurationLoader::EzConfigurationLoaderConstants::OPENSHIFT_REPO_DIR_ENV_VAR] = current_env_value
    res = loader.load_configuration
    res['test.prop'].should == nil
  end

  it "should ignore files that do not end in #{EzBakeConfiguration::EzConfigurationLoader::EzConfigurationLoaderConstants::EZCONFIGURATION_PROPERTY_FILE_EXTENSION}" do
    current_env_value = ENV.delete(EzBakeConfiguration::EzConfigurationLoader::EzConfigurationLoaderConstants::OPENSHIFT_REPO_DIR_ENV_VAR)
    data_dir = File.join(File.dirname(__FILE__), '../data')
    ENV[EzBakeConfiguration::EzConfigurationLoader::EzConfigurationLoaderConstants::OPENSHIFT_REPO_DIR_ENV_VAR] = data_dir
    loader = EzBakeConfiguration::OpenShiftConfigurationLoader.new
    ENV[EzBakeConfiguration::EzConfigurationLoader::EzConfigurationLoaderConstants::OPENSHIFT_REPO_DIR_ENV_VAR] = current_env_value
    res = loader.load_configuration
    res['skip.this.property'].should == nil
  end

  it 'should overwrite a property if it is also found in a later file' do
    current_env_value = ENV.delete(EzBakeConfiguration::EzConfigurationLoader::EzConfigurationLoaderConstants::OPENSHIFT_REPO_DIR_ENV_VAR)
    data_dir = File.join(File.dirname(__FILE__), '../data')
    ENV[EzBakeConfiguration::EzConfigurationLoader::EzConfigurationLoaderConstants::OPENSHIFT_REPO_DIR_ENV_VAR] = data_dir
    loader = EzBakeConfiguration::OpenShiftConfigurationLoader.new
    ENV[EzBakeConfiguration::EzConfigurationLoader::EzConfigurationLoaderConstants::OPENSHIFT_REPO_DIR_ENV_VAR] = current_env_value
    res = loader.load_configuration
    res['stark.ned'].should == 'Warden of the North'
  end
end