#!/bin/bash

# macOS用のX11セットアップスクリプト

echo "Setting up X11 forwarding for macOS..."

# XQuartzがインストールされているかチェック
if ! command -v xquartz &> /dev/null; then
    echo "XQuartz is not installed. Please install it first:"
    echo "brew install --cask xquartz"
    echo "After installation, log out and log back in."
    exit 1
fi

# X11転送を許可
echo "Allowing X11 forwarding..."
xhost +localhost

# DISPLAYを設定
export DISPLAY=:0

echo "X11 setup complete!"
echo "You can now run: docker-compose up --build"
echo ""
echo "To test X11 forwarding inside the container, try:"
echo "docker-compose exec so_long xeyes"
