class TrafficLightSystem {
  public:
    int greenLed;
    int yellowLed;
    int redLed;
    int ped_greedLed;
    int ped_redLed;
    int pushButton;

    long t_green;
    long t_yellow;
    long t_red;
    long t_pedestrianGreen;

    int currentState;
    long previousMillis;
    bool ispedestrianRequest;

    TrafficLightSystem() {
      greenLed = 8;
      yellowLed = 9;
      redLed = 10;
      ped_greedLed = 2;
      ped_redLed = 3;
      pushButton = 4;

      t_green = 20000;
      t_yellow = 3000;
      t_red = 20000;

      currentState = 0;
      previousMillis = 0;
      ispedestrianRequest = false;
    }

    void setup() {
      pinMode(greenLed, OUTPUT);
      pinMode(yellowLed, OUTPUT);
      pinMode(redLed, OUTPUT);
      pinMode(ped_greedLed, OUTPUT);
      pinMode(ped_redLed, OUTPUT);
      Serial.begin(9600);
      
      pinMode(pushButton, INPUT_PULLUP);

      digitalWrite(greenLed, HIGH);
      digitalWrite(yellowLed, LOW);
      digitalWrite(redLed, LOW);

      Serial.write('g');
      Serial.write('R'); 
    }

    void update() {
      unsigned long currentMillis = millis();
      
      if (digitalRead(pushButton) == LOW) {
        ispedestrianRequest = true;  
      }

      switch (currentState) {
        case 0:  
          if (ispedestrianRequest || currentMillis - previousMillis >= t_green) {
            currentState = 1;  
            previousMillis = currentMillis;
          }
          digitalWrite(greenLed, HIGH);
          digitalWrite(yellowLed, LOW);
          digitalWrite(redLed, LOW);
        
        Serial.write('g');
        Serial.write('R');
        break;

        case 1:  
          if (currentMillis - previousMillis >= t_yellow) {
            currentState = 2;
            previousMillis = currentMillis;
          }
          digitalWrite(greenLed, LOW);
          digitalWrite(yellowLed, HIGH);
          digitalWrite(redLed, LOW);
        	Serial.write('g');
        	Serial.write('R');
          break;

        case 2:  
          if (currentMillis - previousMillis >= t_red) {
            currentState = 3;
            previousMillis = currentMillis;
          }
          digitalWrite(greenLed, LOW);
          digitalWrite(yellowLed, LOW);
          digitalWrite(redLed, HIGH);
          
		Serial.write('r');
        Serial.write('G');
        break;

        case 3:  
          if (currentMillis - previousMillis >= t_pedestrianGreen) {
            currentState = 4;  
            ispedestrianRequest = false;  
            previousMillis = currentMillis;
          }
          digitalWrite(greenLed, LOW);
          digitalWrite(yellowLed, LOW);
          digitalWrite(redLed, HIGH);
          
          Serial.write('r');
          Serial.write('G');
          break;

        case 4:  
          if (currentMillis - previousMillis >= t_yellow) {
            currentState = 0;
            previousMillis = currentMillis;
          }
          digitalWrite(greenLed, LOW);
          digitalWrite(yellowLed, HIGH);
          digitalWrite(redLed, LOW);
          
        Serial.write('g');
        Serial.write('R');
          break;
      }
    }
};

TrafficLightSystem trafficLight;

void setup() {
  trafficLight.setup();
}

void loop() {
  trafficLight.update();
}
