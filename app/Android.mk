LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := awesome-native

LOCAL_SRC_FILES := $(LOCAL_PATH)/src/main/cpp/awesome-native.cpp

LOCAL_CPPFLAGS := -std=c++17

LOCAL_LDLIBS := -llog

include $(BUILD_SHARED_LIBRARY)