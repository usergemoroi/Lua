# ESP App - Build Guide

## Prerequisites

Before building the ESP App, ensure you have the following installed:

- **Android Studio**: Version 2023.1 or newer
- **Android NDK**: r21 or newer
- **Gradle**: Version 8.1 or newer (included with wrapper)
- **JDK**: Version 11 or newer
- **Android SDK**: API Level 21-34

### Setting up Android SDK and NDK

1. Install Android Studio from https://developer.android.com/studio
2. Open Android Studio > SDK Manager
3. Install:
   - Android SDK Platform 34
   - Android SDK Platform-Tools
   - Android NDK (Side by side)
4. Set environment variables (optional):
   ```bash
   export ANDROID_HOME=$HOME/Android/Sdk
   export PATH=$PATH:$ANDROID_HOME/tools
   export PATH=$PATH:$ANDROID_HOME/platform-tools
   ```

## Project Structure

```
esp-app/
├── gradle/                   # Gradle wrapper files
├── app/
│   ├── build.gradle          # App-level build configuration
│   ├── proguard-rules.pro    # ProGuard rules
│   └── src/
│       └── main/
│           ├── AndroidManifest.xml
│           ├── java/         # Java source code
│           ├── jni/          # C++ NDK code
│           ├── res/          # Android resources
│           └── assets/       # App assets
├── build.gradle              # Root build configuration
├── settings.gradle           # Project settings
├── build.sh                  # Build script
├── install.sh                # Installation script
└── BUILD_GUIDE.md            # This file
```

## Building the Project

### Option 1: Using Android Studio (Recommended for Development)

1. **Open the project:**
   - Launch Android Studio
   - Select `File > Open`
   - Navigate to the `esp-app` folder and open it

2. **Wait for Gradle sync:**
   - Android Studio will automatically sync Gradle
   - Wait until "Gradle build finished" appears in the status bar

3. **Configure NDK (if needed):**
   - File > Project Structure > SDK Location
   - Set Android NDK location if not auto-detected

4. **Build the APK:**
   - Build > Build Bundle(s) / APK(s) > Build APK(s)
   - Or click the "Build" button in the toolbar

5. **Output location:**
   - Debug APK: `app/build/outputs/apk/debug/app-debug.apk`
   - Release APK: `app/build/outputs/apk/release/app-release.apk`

### Option 2: Using Command Line

#### Debug Build

```bash
cd esp-app
./gradlew assembleDebug
```

#### Release Build

```bash
cd esp-app
./gradlew assembleRelease
```

#### Clean Build

```bash
cd esp-app
./gradlew clean assembleDebug
```

### Option 3: Using Build Script

```bash
cd esp-app
chmod +x build.sh
./build.sh
```

This script will:
1. Clean previous builds
2. Build debug APK
3. Show output location and installation instructions

## Installation

### Method 1: Using Install Script

```bash
cd esp-app
chmod +x install.sh
./install.sh
```

### Method 2: Using ADB directly

1. **Connect your Android device:**
   - Enable Developer Options and USB Debugging
   - Connect via USB

2. **Verify device connection:**
   ```bash
   adb devices
   ```

3. **Install the APK:**
   ```bash
   adb install -r app/build/outputs/apk/debug/app-debug.apk
   ```

4. **Launch the app:**
   ```bash
   adb shell am start -n com.example.espapp/.MainActivity
   ```

### Method 3: Using Android Studio

1. Connect your device or start an emulator
2. Click the "Run" button (green play icon)
3. Select your device from the list
4. Android Studio will build and install automatically

## Troubleshooting

### Problem: NDK not found

**Solution:**
Create or edit `local.properties` in the project root:
```properties
sdk.dir=/path/to/android-sdk
ndk.dir=/path/to/android-ndk
```

### Problem: Gradle sync failed

**Solution:**
1. Check internet connection (Gradle needs to download dependencies)
2. Clear Gradle cache:
   ```bash
   rm -rf ~/.gradle/caches
   ./gradlew clean
   ```
3. Invalidate caches in Android Studio:
   - File > Invalidate Caches / Restart

### Problem: Build fails with "No toolchains found"

**Solution:**
1. Install NDK through Android Studio SDK Manager
2. Or set NDK path in `local.properties`:
   ```properties
   ndk.dir=/path/to/ndk
   ```

### Problem: Port 9557 already in use

**Solution:**
The ESP server uses port 9557 by default. If you need to change it:
1. Edit `app/src/main/jni/src/offsets.h`
2. Change the port number
3. Rebuild the project

### Problem: App crashes on launch

**Solution:**
1. Check logcat for errors:
   ```bash
   adb logcat | grep ESP
   ```
2. Ensure Standoff 2 is installed (com.axlebolt.standoff2)
3. Grant necessary permissions in device settings

### Problem: Native library not found

**Solution:**
1. Clean and rebuild:
   ```bash
   ./gradlew clean
   ./gradlew assembleDebug
   ```
2. Check that NDK build completed successfully in build logs
3. Verify `libcheat.so` exists in APK:
   ```bash
   unzip -l app/build/outputs/apk/debug/app-debug.apk | grep libcheat
   ```

### Problem: Device not authorized

**Solution:**
1. Check device screen for USB debugging authorization prompt
2. If not appearing, revoke USB debugging authorizations:
   - Developer Options > Revoke USB debugging authorizations
3. Reconnect device

## Build Variants

### Debug Build
- Debuggable: Yes
- Optimization: Disabled
- ProGuard: Disabled
- Signing: Debug keystore

```bash
./gradlew assembleDebug
```

### Release Build
- Debuggable: No
- Optimization: Enabled (-O2)
- ProGuard: Enabled
- Signing: Requires release keystore

```bash
./gradlew assembleRelease
```

**Note:** Release builds require signing configuration in `app/build.gradle`.

## Advanced Configuration

### Changing Target Architectures

Edit `app/src/main/jni/Application.mk`:
```makefile
APP_ABI := x86 arm64-v8a armeabi-v7a
```

Supported ABIs:
- `x86` - Intel/AMD 32-bit
- `x86_64` - Intel/AMD 64-bit
- `armeabi-v7a` - ARM 32-bit
- `arm64-v8a` - ARM 64-bit (default)

### Changing Min SDK Version

Edit `app/build.gradle`:
```gradle
defaultConfig {
    minSdk 21  // Change this value
}
```

### Adding ProGuard Rules

Edit `app/proguard-rules.pro` to add custom ProGuard rules for release builds.

## Verifying the Build

### Check APK contents:
```bash
unzip -l app/build/outputs/apk/debug/app-debug.apk
```

### Check native libraries:
```bash
unzip -l app/build/outputs/apk/debug/app-debug.apk | grep "\.so$"
```

Expected output should include:
```
lib/x86/libcheat.so
lib/arm64-v8a/libcheat.so
```

### Check APK size:
```bash
ls -lh app/build/outputs/apk/debug/app-debug.apk
```

## Development Workflow

1. **Make changes** to Java or C++ code
2. **Build**: `./gradlew assembleDebug`
3. **Install**: `./install.sh` or use Android Studio
4. **Debug**: Use `adb logcat` to view logs
5. **Iterate**: Repeat as needed

### Viewing Logs

```bash
# All logs
adb logcat

# ESP-specific logs
adb logcat | grep ESP

# Native logs
adb logcat | grep ESP_NATIVE

# Service logs
adb logcat | grep ESP_SERVICE

# Clear logs
adb logcat -c
```

## Performance Tips

1. **Use Release builds for performance testing**
   - Release builds have optimization enabled
   - Debug builds are slower but easier to debug

2. **Profile with Android Studio**
   - Use CPU Profiler to identify bottlenecks
   - Use Memory Profiler to check for leaks

3. **Test on real devices**
   - Emulators may not accurately represent performance
   - Test on target device models

## Support

For issues or questions:
1. Check the troubleshooting section above
2. Review logcat output for error messages
3. Verify prerequisites are met
4. Check Android Studio build output for detailed errors

## Additional Resources

- [Android NDK Documentation](https://developer.android.com/ndk)
- [Gradle Documentation](https://docs.gradle.org)
- [Android Studio Guide](https://developer.android.com/studio/intro)
- [ADB Documentation](https://developer.android.com/studio/command-line/adb)
