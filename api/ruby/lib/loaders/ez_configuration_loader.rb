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
  module EzConfigurationLoader
    module EzConfigurationLoaderConstants
      EZ_CONFIGURATION_ENV_VAR='EZCONFIGURATION_DIR'
      EZCONFIGURATION_DEFAULT_DIR='/etc/sysconfig/ezbake'
      EZCONFIGURATION_PROPERTY_FILE_EXTENSION='.properties'
      EZCONFIGURATION_PROPERTY_FILE_COMMENT_CHARACTER='#'
      OPENSHIFT_REPO_DIR_ENV_VAR='OPENSHIFT_REPO_DIR'
      OPENSHIFT_PROPERTIES_DIR='/config'
    end
    def load_configuration
      throw 'Unimplemented Method'
    end

    def isLoadable
      false
    end
  end
end