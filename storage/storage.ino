#include <FS.h>           // Filesystem library
#include <LittleFS.h>     // LittleFS library for ESP8266

void setup() {
//  Serial.begin(115200);
//
//  // Initialize LittleFS
//  if (!LittleFS.begin()) {
//    Serial.println("Failed to mount file system");
//    return;
//  }
//
//  // Verify if the .wav file exists
//  if (!LittleFS.exists("/test.wav")) {
//    Serial.println(".wav file not found!");
//    return;
//  }
//
//  // Read and print the .wav file content
//  File file = LittleFS.open("/test.wav", "r");
//  if (!file) {
//    Serial.println("Failed to open file for reading");
//    return;
//  }
//
//  Serial.println("Reading .wav file:");
//  while (file.available()) {
//    Serial.write(file.read());  // Print file data to the Serial Monitor
//  }
//  file.close();
Serial.begin(115200);

  // Initialize LittleFS
  if (!LittleFS.begin()) {
    Serial.println("Failed to mount LittleFS");
    return;
  }

  Serial.println("LittleFS mounted successfully.");
  Serial.println("Files in Flash Storage:");

  // List all files in the LittleFS filesystem
  listFiles("/");
}


void loop() {
  // put your main code here, to run repeatedly:
}

// Function to list all files in LittleFS
void listFiles(const char* dirname) {
  Dir dir = LittleFS.openDir(dirname);

  while (dir.next()) {
    Serial.print("File: ");
    Serial.print(dir.fileName());
    Serial.print("\tSize: ");
    Serial.println(dir.fileSize());
  }
}
