package com.daiwei.learnndkbuild;

import android.util.Log;

final class AwesomeNative {

    private static final String TAG = AwesomeNative.class.getSimpleName();

    static {
        System.loadLibrary("awesome-native");
    }

    AwesomeNative() {}

    void callNative() {
        Log.d(TAG, "call native");
        sayHello();
        Log.d(TAG, "call native end");
    }

    void sayGoodBye() {
        Log.d(TAG, "Good bye");
    }

    native void sayHello();
}
