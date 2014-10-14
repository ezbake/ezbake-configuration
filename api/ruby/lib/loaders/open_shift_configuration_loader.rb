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

require_relative './directory_configuration_loader'
module EzBakeConfiguration
  class OpenShiftConfigurationLoader < DirectoryConfigurationLoader
    def initialize
      @properties = {}
      @dir = ENV[EzConfigurationLoaderConstants::OPENSHIFT_REPO_DIR_ENV_VAR]
      @dir += EzConfigurationLoaderConstants::OPENSHIFT_PROPERTIES_DIR unless @dir.nil?
    end
  end
end