#include <Arduino.h>

const int ledPin = 32; 
const int freq = 5000;
const int ledChannel = 0; // Wir suchen uns Kanal 0 aus
const int resolution = 8;
const int MAX_SAFE_DUTY = 127; // Deine 50% Grenze
int dutyCycle = 0;

void setup() {
  Serial.begin(115200);

  // 1. Den Kanal konfigurieren (Frequenz und Auflösung)
  ledcSetup(ledChannel, freq, resolution);

  // 2. Den physikalischen Pin an diesen Kanal binden
  ledcAttachPin(ledPin, ledChannel);
  
//   Serial.println("PWM Hardware v2.x bereit.");
}

void loop() {
    if(Serial.available() > 0){
        char key = Serial.read();
        if(key == '+'){
            dutyCycle+=25;
        }
        else if(key == '-'){
            dutyCycle-=25;
        }
        if(dutyCycle > MAX_SAFE_DUTY){
            dutyCycle = MAX_SAFE_DUTY;
        }
        else if(dutyCycle < 0){
            dutyCycle = 0;
        }


        ledcWrite(ledChannel, dutyCycle); 
    }
  // Zum Testen am Multimeter:
  // ledcWrite(ledChannel, 0);   // Sollte 0V zeigen
  // delay(2000);
  // ledcWrite(ledChannel, 127); // Sollte ca. 1,6V zeigen
  // delay(2000);
}