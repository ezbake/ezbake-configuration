/*   Copyright (C) 2013-2014 Computer Sciences Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License. */

var BaseConfiguration = require('./baseConfiguration');

ZookeeperConfiguration.prototype = new BaseConfiguration();
ZookeeperConfiguration.prototype.constructor = ZookeeperConfiguration;

function ZookeeperConfiguration(ezConfiguration, namespace){
  BaseConfiguration.call(this, ezConfiguration, namespace);
}
ZookeeperConfiguration.prototype.getConnectionString = function(){
  return this.get(this.constants.ZOOKEEPER.CONNECTION_STRING);
};

module.exports = ZookeeperConfiguration;