//
class pedestrianlight{
  public:
  	int ped_greenLed;
    int ped_redLed;
	
	pedestrianlight(){
    	ped_greenLed = 2;
    	ped_redLed = 3; 
    }
  void setup(){
    
		pinMode(ped_greenLed, OUTPUT);
   	 	pinMode(ped_redLed, OUTPUT);
    	
    	Serial.begin(9600);
  }
  void pedestrianRedOn(){
  	digitalWrite(ped_redLed,HIGH);
  
  }
  void pedestrianRedOff(){
  	digitalWrite(ped_redLed,LOW);
    
  }
  void pedestrianGreenOn(){
  	digitalWrite(ped_greenLed,HIGH);
  
  }
  void pedestrianGreenOff(){
  	digitalWrite(ped_greenLed,LOW);
  }
};

//object
pedestrianlight signal;

void setup()
{
  signal.setup();
}
void loop()
{
   char data = Serial.read();
  switch(data){
  	case 'R':
    	signal.pedestrianRedOn();
    	break;
    case 'r':
    	signal.pedestrianRedOff();
    	break;
    case 'G':
    	signal.pedestrianGreenOn();
    	break;
    case 'g':
    	signal.pedestrianGreenOff();
    	break;
    default:
    	break;
  }
}