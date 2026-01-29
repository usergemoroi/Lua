# Keep native methods
-keepclasseswithmembernames class * {
    native <methods>;
}

-keepclasseswithmembernames class * {
    public static final int native_*;
}

# Keep ESP service classes
-keep class com.example.espapp.** { *; }

# Keep all native library references
-dontwarn android.**
