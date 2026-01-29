#!/bin/bash

APK_PATH="app/build/outputs/apk/debug/app-debug.apk"

if [ ! -f "$APK_PATH" ]; then
    echo "Error: APK not found at $APK_PATH"
    echo "Please build first: ./build.sh"
    exit 1
fi

echo "Installing $APK_PATH..."
adb install -r "$APK_PATH"

if [ $? -eq 0 ]; then
    echo "✓ Installation successful!"
    echo ""
    echo "To run the app:"
    echo "  adb shell am start -n com.example.espapp/.MainActivity"
else
    echo "✗ Installation failed!"
    exit 1
fi
