#include <SoftwareSerial.h>

static const int RXPin = 3, TXPin = 4;

SoftwareSerial ss(RXPin, TXPin);

void setup() {
  Serial.begin(9600);
  ss.begin(9600);

  delay(1000);
  Serial.println("Calling...");

  //Call this function to execute the call
  makeCall();
  delay(1000);

}

void loop() {
  // Empty loop, as we only want to make call once during setup
}
void makeCall() {
  Serial.println("Making a call...");
  ss.println("ATD+1234567890;"); // Replace +1234567890 with the phone number you want to call
  delay(10000); // You can adjust the delay according to your requirements (5 seconds here)
  ss.println("ATH"); // Hang up the call
  Serial.println("Call ended.");
}
