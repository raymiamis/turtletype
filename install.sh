#!/bin/bash

set -e

BINARY_NAME="turtletype"
INSTALL_PATH="/usr/local/bin"

echo "Checking GCC Installation..."
if ! command -v gcc &> /dev/null; then
    echo -e "\e[31mGCC is not installed.\e[0m Please install GCC and try again."
fi

echo "Compiling $BINARY_NAME..."
gcc -o $BINARY_NAME main.c

echo "Installing to $INSTALL_PATH... (requires sudo)"
sudo cp "$BINARY_NAME" "$INSTALL_PATH"

echo "\e[32mInstallation complete!\e[0m"
echo ""
echo "Use the typing tutor everywhere you want with:"
echo "   \e[36m$BINARY_NAME\e[0m"