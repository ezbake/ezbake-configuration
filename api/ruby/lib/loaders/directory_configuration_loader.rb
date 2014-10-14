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

require_relative './ez_configuration_loader'
module EzBakeConfiguration
  class DirectoryConfigurationLoader
  include EzBakeConfiguration::EzConfigurationLoader
    attr_reader :properties, :dir

    def initialize directory=nil
      @properties = {}
      @dir = directory
      if @dir.nil?
        @dir = ENV[EzConfigurationLoaderConstants::EZ_CONFIGURATION_ENV_VAR] || EzConfigurationLoaderConstants::EZCONFIGURATION_DEFAULT_DIR
      end
    end

    def loadable?
      !@dir.nil? && !@dir.empty? && File.directory?(@dir)
    end

    def load_configuration
      return @properties if !loadable?
      Dir.glob(File.join(@dir,'/*.properties')) do |prop_file|
        next if !File.file? prop_file
        File.readlines(prop_file).each do |property|
          next if property.start_with? EzConfigurationLoaderConstants::EZCONFIGURATION_PROPERTY_FILE_COMMENT_CHARACTER
          property_key, property_value = property.split('=', 2)
          @properties[property_key] = property_value.to_s.gsub /\n$/, ''#remove newline from end of value
        end
      end
      @properties
    end
  end
end