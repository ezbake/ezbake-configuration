Gem::Specification.new do |gem|
  gem.name          = 'ez_bake_configuration'
  gem.version       = '0.0.1'
  gem.summary       = %q{ez-bake-configuration-api allows configuration values to be loaded from multiple sources depending on applications and their deployment environments.}
  gem.description   = <<-EOF
  ez-bake-configuration-api allows configuration values to be loaded from multiple sources
  depending on applications and their deployment environments.
  EOF
  gem.license       = "apache2"
  gem.authors       = ["Steven Stapleton"]
  gem.email         = "sstapleton@42six.com"
  gem.homepage      = "http://www.42six.com"
  gem.files 	      = Dir['lib/**/*.rb']
  #gem.executables   = gem.files.grep(%r{^bin/}).map{ |f| File.basename(f) }
  gem.test_files    = gem.files.grep(%r{^(test|spec|features)/})
  gem.require_paths = ['lib']

  # Not used yet
  # gem.extensions    = ['extconf.rb']

  gem.add_development_dependency 'bundler', '~> 1.0'
  gem.add_development_dependency 'rspec',  '~> 2.14'
end