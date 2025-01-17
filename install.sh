#!/bin/bash

#  install.sh
#  macRogAuraCore
#
#  Created by Nick on 7/22/20.
#  Copyright 2020 Nick. All rights reserved.

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"
BUILD_DIR="$DIR/build/Release"

# Create the directory if not present already
if [[ ! -d /usr/local/bin ]]; then 
    mkdir -p /usr/local/bin
fi

echo "Installing macRogAuraCore..."

# Remove existing binary if it exists
rm /usr/local/bin/macRogAuraCore 2>/dev/null

# Copy from build directory to destination
cp "$BUILD_DIR/macRogAuraCore" /usr/local/bin/
chmod +x /usr/local/bin/macRogAuraCore

echo "Installation complete. macRogAuraCore is now available in /usr/local/bin."
