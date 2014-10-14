# EzBake Configuration bash API

## Build

A constants file must be generated using `ezconfiguration_constants_generator`:

    python ezconfiguration_constants_generator.py constants.txt bash

## Installation

Copy the constants file to `/etc/sysconfig/ezbake/ezbake.constants`. It would probably be helpful to copy `ezbake_configuration_functions` and `ezbake_configuration` to a system directory like `/etc/sysconfig/ezbake` or `/usr/local/libexec/ezbake` or something.

## No-installation

Build the constants file as above, but change the variable `EZBAKE_CONFIGURATION_CONSTANTS` in `ezbake_configuration_functions` to the location of the constants file.

## Usage

If `ezbake_configuration_functions` and `ezbake_configuration` are in the local directory (rather than in `/etc` or `/usr/local/libexec` as above):

    source ezbake_configuration

Loads all EzBake configuration properties into the namespace as shell variables.

For more control over the loading process, use `ezbake_env`. `ezbake_env` Loads properties from one or more files given as arguments. If no arguments are given, then all of the properties files in `$EZBAKE_CONFIGURATION_DIR` are loaded. For example,

    source ezbake_configuration_functions
    ezbake_env foo.props bar.props    # Loads from foo.props and bar.props
    ezbake_env                        # Loads from $EZBAKE_CONFIGURATION_DIR

The variable assignments can then be placed into the local namespace by using `eval`. For example:

    source ezbake_configuration_functions
    eval $(ezbake_env)

This is exactly the operation that `source ezbake_configuration` performs.
