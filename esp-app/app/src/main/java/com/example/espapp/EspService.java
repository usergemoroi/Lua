package com.example.espapp;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;
import android.util.Log;

public class EspService extends Service {
    private static final String TAG = "ESP_SERVICE";
    private boolean isRunning = false;
    private Thread espThread;
    
    public EspService() {
    }

    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        Log.d(TAG, "Service onStartCommand called");
        
        if (!isRunning) {
            isRunning = true;
            startEspThread();
        }
        
        return START_STICKY;
    }

    @Override
    public IBinder onBind(Intent intent) {
        return null;
    }

    @Override
    public void onDestroy() {
        Log.d(TAG, "Service destroyed");
        stopNativeEspServer();
        isRunning = false;
        
        if (espThread != null) {
            espThread.interrupt();
            espThread = null;
        }
        
        super.onDestroy();
    }

    private void startEspThread() {
        espThread = new Thread(() -> {
            try {
                Log.d(TAG, "Starting native ESP server...");
                startNativeEspServer();
            } catch (Exception e) {
                Log.e(TAG, "Error in ESP thread: " + e.getMessage(), e);
            }
        });
        espThread.start();
    }

    // Native methods
    private native void startNativeEspServer();
    private native void stopNativeEspServer();
}
