#!/bin/bash
set -e

PROJECT_DIR=$(pwd)

echo "========================================="
echo "ESP App - Full Build Script"
echo "========================================="

echo ""
echo "Step 1: Cleaning previous builds..."
./gradlew clean

echo ""
echo "Step 2: Building with Gradle..."
./gradlew assembleDebug

echo ""
echo "Step 3: Build completed!"
echo "APK location: app/build/outputs/apk/debug/app-debug.apk"
echo ""
echo "To install on device:"
echo "  adb install -r app/build/outputs/apk/debug/app-debug.apk"
echo ""
echo "========================================="
