void setup() {
  // Initialize serial communication for XBee and Serial Monitor
  Serial.begin(9600);  // Same serial for both XBee and Serial Monitor
  
  delay(2000);  // Wait for XBee to initialize
}

void loop() {
  // Send a simple message to the receiver via XBee (TX pin on Arduino)
  String message = "Hello from Arduino!";
  Serial.println(message);  // Send message via the same serial port
  
  // Output message to Serial Monitor for debugging
  Serial.println("Message Sent: " + message);
  
  // Wait for 2 seconds before sending the next message
  delay(2000);
}
