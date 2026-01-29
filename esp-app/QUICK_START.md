# ESP App - Quick Start Guide

## 🚀 Get Started in 3 Steps

### Step 1: Build
```bash
cd /home/engine/project/esp-app
./build.sh
```

### Step 2: Install
```bash
./install.sh
```

### Step 3: Run
```bash
adb shell am start -n com.example.espapp/.MainActivity
```

---

## 📖 What You Have

### Complete Android Application
A fully functional Android app with:
- ✅ Material Design UI
- ✅ Background ESP service
- ✅ TCP socket server (port 9557)
- ✅ Automatic Standoff 2 detection
- ✅ Memory reading and ESP rendering
- ✅ Multi-architecture support (x86, arm64-v8a)

### Complete Documentation
- **README.md** - Project overview
- **BUILD_GUIDE.md** - Detailed build instructions (7.8KB)
- **PROJECT_SUMMARY.md** - Technical architecture (11.9KB)
- **VERIFICATION.md** - Quality assurance report (9.9KB)
- **QUICK_START.md** - This file

---

## 🎯 Using the App

### 1. Launch the App
The app will appear in your Android launcher as "ESP App"

### 2. Start ESP Service
Tap the "Start ESP" button in the app

### 3. Launch Standoff 2
The ESP service will automatically detect and attach to the game

### 4. Connect External Client
Connect your overlay client to the device IP on port 9557

### 5. Stop ESP Service
Tap the "Stop ESP" button when done

---

## 🔧 Common Tasks

### View Logs
```bash
adb logcat | grep ESP
```

### Check Service Status
```bash
adb shell dumpsys activity services | grep espapp
```

### Test Network Connection
```bash
adb shell netstat | grep 9557
```

### Rebuild After Changes
```bash
./gradlew clean
./build.sh
./install.sh
```

---

## 📁 Project Files

### Key Files to Know
- `app/src/main/java/com/example/espapp/MainActivity.java` - UI
- `app/src/main/java/com/example/espapp/EspService.java` - Background service
- `app/src/main/jni/src/main.cpp` - Native ESP code with JNI
- `app/src/main/jni/src/offsets.h` - Game offsets (edit to update)
- `app/build.gradle` - Build configuration

### Build Scripts
- `gradlew` - Gradle wrapper (Unix)
- `build.sh` - Build automation
- `install.sh` - Installation automation

---

## ⚙️ Configuration

### Change Port
Edit `app/src/main/jni/src/offsets.h` and rebuild

### Change Architectures
Edit `app/src/main/jni/Application.mk`:
```makefile
APP_ABI := x86 arm64-v8a armeabi-v7a
```

### Update Game Offsets
1. Edit `app/src/main/jni/src/offsets.h`
2. Run `./build.sh`
3. Run `./install.sh`

---

## 🐛 Troubleshooting

### Build Fails
```bash
./gradlew clean
./build.sh
```

### App Crashes
```bash
adb logcat | grep -i exception
adb logcat | grep ESP
```

### Cannot Find Process
- Ensure Standoff 2 is installed
- Check package name: `com.axlebolt.standoff2`

### Port Already in Use
- Stop any other services using port 9557
- Or change the port in offsets.h

---

## 📚 Learn More

For detailed information, see:
- **BUILD_GUIDE.md** - Comprehensive build documentation
- **PROJECT_SUMMARY.md** - Technical architecture details
- **VERIFICATION.md** - Quality assurance report

---

## 💡 Quick Tips

1. **Always view logs** when testing: `adb logcat | grep ESP`
2. **Clean build** if you get errors: `./gradlew clean`
3. **Check device connection**: `adb devices`
4. **Use Android Studio** for advanced debugging
5. **Read BUILD_GUIDE.md** for detailed troubleshooting

---

## ✨ Features

- 🎨 Material Design UI
- 🔧 Background service
- 🌐 TCP socket server
- 🔍 Automatic game detection
- 💾 Memory reading
- 📊 ESP data rendering
- 🔒 Secure (local network only)
- 📱 Multi-architecture support
- 📝 Comprehensive logging
- 🚀 Production-ready

---

## 🎉 Ready to Go!

Your Android Studio project is complete and ready to use.

**Start building now:**
```bash
cd /home/engine/project/esp-app
./build.sh
```

**Need help?** Check BUILD_GUIDE.md for detailed instructions.
