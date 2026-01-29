# ESP App - Android Studio Project

Complete Android application project for the Standoff 2 ESP system.

## Overview

This is a fully-configured Android Studio project that wraps the existing C++ NDK ESP code into a user-friendly Android application. The app provides a simple interface to start/stop the ESP service and automatically handles process attachment and memory reading.

## Features

- ✅ Complete Android Studio project structure
- ✅ Material Design UI with start/stop buttons
- ✅ Background service for ESP operation
- ✅ JNI integration with C++ code
- ✅ TCP socket server on port 9557
- ✅ Automatic process detection and attachment
- ✅ Build scripts for easy compilation
- ✅ Multi-architecture support (x86, arm64-v8a)

## Quick Start

### Prerequisites
- Android Studio 2023.1+
- Android NDK r21+
- Android device or emulator with API 21+

### Build & Install

```bash
cd esp-app
./build.sh
./install.sh
```

Or open in Android Studio and click Run.

## Project Structure

```
esp-app/
├── app/
│   ├── build.gradle                  # App configuration
│   ├── src/main/
│   │   ├── AndroidManifest.xml       # App manifest
│   │   ├── java/                     # Java source code
│   │   │   └── com/example/espapp/
│   │   │       ├── MainActivity.java # Main UI activity
│   │   │       └── EspService.java   # Background service
│   │   ├── jni/                      # Native C++ code
│   │   │   ├── Android.mk            # NDK build config
│   │   │   ├── Application.mk        # NDK app config
│   │   │   └── src/                  # C++ sources
│   │   ├── res/                      # Android resources
│   │   └── assets/                   # App assets
├── build.gradle                      # Root build config
├── settings.gradle                   # Gradle settings
├── gradlew                           # Gradle wrapper (Unix)
├── build.sh                          # Build script
├── install.sh                        # Installation script
└── BUILD_GUIDE.md                    # Detailed build guide
```

## How It Works

1. **MainActivity**: Provides UI with Start/Stop buttons
2. **EspService**: Runs ESP in background thread
3. **Native Layer**: 
   - Finds Standoff 2 process
   - Attaches to process memory
   - Starts TCP server on port 9557
   - Continuously renders ESP data
4. **External Client**: Connects to port 9557 to receive ESP data

## Usage

1. Install the app on your Android device
2. Launch the app
3. Tap "Start ESP" button
4. The service will wait for Standoff 2 to launch
5. Once detected, it will start streaming ESP data on port 9557
6. Connect your overlay client to device IP on port 9557
7. Tap "Stop ESP" to stop the service

## Configuration

### Changing Port

Edit `app/src/main/jni/src/offsets.h` and change the port number, then rebuild.

### Changing Target Architectures

Edit `app/src/main/jni/Application.mk`:
```makefile
APP_ABI := x86 arm64-v8a  # Add/remove architectures
```

### Build Optimization

Edit `app/src/main/jni/Android.mk` to modify compiler flags:
```makefile
LOCAL_CFLAGS += -O2  # Change optimization level
```

## Building

### Using Build Script
```bash
./build.sh
```

### Using Gradle
```bash
./gradlew assembleDebug    # Debug build
./gradlew assembleRelease  # Release build
```

### Using Android Studio
1. Open project in Android Studio
2. Build > Build Bundle(s) / APK(s) > Build APK(s)

## Installation

### Using Install Script
```bash
./install.sh
```

### Using ADB
```bash
adb install -r app/build/outputs/apk/debug/app-debug.apk
```

### Using Android Studio
Click the Run button (green play icon)

## Debugging

### View Logs
```bash
# All ESP logs
adb logcat | grep ESP

# Native logs only
adb logcat | grep ESP_NATIVE

# Service logs only
adb logcat | grep ESP_SERVICE
```

### Check Service Status
```bash
adb shell dumpsys activity services | grep espapp
```

### Network Testing
```bash
# Check if port is listening
adb shell netstat | grep 9557

# Test connection
nc <device-ip> 9557
```

## Troubleshooting

### App crashes on start
- Check logcat: `adb logcat | grep ESP`
- Ensure NDK build succeeded
- Verify libcheat.so is in APK

### Cannot find process
- Ensure Standoff 2 is installed
- Check package name matches: com.axlebolt.standoff2

### Cannot connect to port
- Check firewall settings
- Verify port 9557 is not in use
- Ensure device is on same network

### Build fails
- Check NDK is installed
- Verify Gradle sync completed
- See BUILD_GUIDE.md for detailed troubleshooting

## Technical Details

### Native Library
- **Name**: libcheat.so
- **Build Type**: Shared library
- **STL**: c++_static
- **Optimization**: -O2
- **C++ Standard**: C++17

### JNI Methods
- `Java_com_example_espapp_EspService_startNativeEspServer`
- `Java_com_example_espapp_EspService_stopNativeEspServer`

### Permissions
- INTERNET
- ACCESS_NETWORK_STATE
- WRITE_EXTERNAL_STORAGE
- READ_EXTERNAL_STORAGE

## Development

### Adding New Features

1. **Java Side**: Edit MainActivity.java or EspService.java
2. **Native Side**: Edit files in jni/src/
3. **JNI Bridge**: Add methods to main.cpp with proper JNI signature
4. **Rebuild**: Run `./build.sh`

### Code Organization

- **Memory Layer**: jni/src/memory/
- **Network Layer**: jni/src/network/
- **ESP Logic**: jni/src/esp/
- **Game SDK**: jni/src/sdk/
- **Offsets**: jni/src/offsets.h

## Performance

- ESP render loop: 10ms interval
- TCP server: Multi-threaded client handling
- Memory reads: Optimized with pagemap validation
- Socket buffer: Mutex-protected shared memory

## Security

- Release builds use ProGuard for code obfuscation
- Native library symbols stripped in release
- No hardcoded credentials
- Local network only (no external connections)

## License

This project is for educational purposes only.

## Support

For detailed build instructions, see [BUILD_GUIDE.md](BUILD_GUIDE.md)
