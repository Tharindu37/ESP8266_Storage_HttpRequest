#include <ESP8266HTTPClient.h>  // Include the correct HTTP client for ESP8266

#include <ESP8266WiFi.h>  // For ESP8266
#include <WiFiClient.h>

// Replace with your network credentials
const char* ssid = "THARINDU-VIVOBO 4924";  
const char* password = "12345678";  

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {  // Ensure WiFi is connected
//    WiFiClient client;  // Create a WiFiClient instance
    WiFiClientSecure client;  // Create a WiFiClientSecure instance

    client.setInsecure();  // Skip certificate validation (use only for testing)
    HTTPClient http;    // Create an HTTPClient instance

    // Use the new API: pass the WiFiClient object and URL
    http.begin(client, "https://jsonplaceholder.typicode.com/todos/1");

    // Send the GET request and check for success
    int httpCode = http.GET();

    if (httpCode > 0) {  // Check if GET request is successful
      Serial.printf("HTTP GET request successful. Code: %d\n", httpCode);
      String payload = http.getString();
      Serial.println("Response: ");
      Serial.println(payload);
    } else {
      Serial.printf("HTTP GET request failed. Code: %d\n", httpCode);
    }

    // End the HTTP request
    http.end();
  } else {
    Serial.println("WiFi not connected!");
  }

  // Wait for 30 seconds before sending the next request
  delay(30000);
}
