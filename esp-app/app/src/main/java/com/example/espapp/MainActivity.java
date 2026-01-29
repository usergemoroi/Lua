package com.example.espapp;

import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    private static final String TAG = "ESP_APP";
    private TextView statusText;
    private Button startButton;
    private Button stopButton;
    
    static {
        try {
            System.loadLibrary("cheat");
            Log.d(TAG, "libcheat.so loaded successfully");
        } catch (UnsatisfiedLinkError e) {
            Log.e(TAG, "Failed to load libcheat.so: " + e.getMessage(), e);
        }
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        statusText = findViewById(R.id.status_text);
        startButton = findViewById(R.id.start_button);
        stopButton = findViewById(R.id.stop_button);
        
        startButton.setOnClickListener(v -> startEspService());
        stopButton.setOnClickListener(v -> stopEspService());
        
        updateStatus("Ready");
    }

    private void startEspService() {
        Intent intent = new Intent(this, EspService.class);
        startService(intent);
        updateStatus("ESP Service Started");
        Log.d(TAG, "ESP Service started");
    }

    private void stopEspService() {
        Intent intent = new Intent(this, EspService.class);
        stopService(intent);
        updateStatus("ESP Service Stopped");
        Log.d(TAG, "ESP Service stopped");
    }

    private void updateStatus(String message) {
        statusText.setText(message);
    }
}
