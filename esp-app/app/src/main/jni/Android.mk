LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := cheat

LOCAL_SRC_FILES := \
    src/main.cpp \
    src/globals.cpp \
    src/memory/memory.cpp \
    src/network/socket_server.cpp \
    src/esp/esp.cpp \
    src/sdk/player/player.cpp \
    src/sdk/game/game.cpp

LOCAL_C_INCLUDES := src

LOCAL_LDLIBS := -llog

LOCAL_CFLAGS += \
    -O2 \
    -fvisibility=hidden \
    -ffunction-sections \
    -fdata-sections

LOCAL_LDFLAGS += \
    -Wl,--gc-sections \
    -Wl,--exclude-libs,ALL

include $(BUILD_SHARED_LIBRARY)
