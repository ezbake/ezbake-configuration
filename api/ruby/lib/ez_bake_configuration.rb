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

Dir.glob('./lib/**/*.rb').each {|file| require file }

module EzBakeConfiguration
  class EzConfiguration
    attr_reader :properties
    def initialize *loaders
      if loaders.length == 0
        loaders = [DirectoryConfigurationLoader.new, OpenShiftConfigurationLoader.new] #Default loaders
      end
      @properties = {}
      loaders.each do |loader|
        @properties.merge! loader.load_configuration if loader.loadable?
      end
    end
  end
end