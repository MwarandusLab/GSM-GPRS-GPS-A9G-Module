#include <SoftwareSerial.h>

static const int RXPin = 3, TXPin = 4;
String phoneNumber = "+1234567890"; // Replace this with the recipient's phone number
String message = "Hello, this is a test SMS from A9G!";

SoftwareSerial ss(RXPin, TXPin);

void setup() {
  Serial.begin(9600);
  ss.begin(9600);

  delay(1000);
  Serial.println("Starting...");

  delay(1000);
  // Enable SMS text mode
  ss.println("AT+CMGF=1");
  delay(100);

  // Set SMS recipient phone number
  ss.print("AT+CMGS=\"");
  ss.print(phoneNumber);
  ss.println("\"");
  delay(100);

  // Send the SMS message
  ss.print(message);
  ss.write(26); // ASCII code for CTRL+Z (message termination)
  delay(1000);
}

void loop() {
  // Empty loop, as we only want to send the SMS once during setup
}
