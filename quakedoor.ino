#include <SoftwareSerial.h> //using BlueTooth Serials.
int sp = 10;                // buzz or speaker pin Number
int vibSensor = 12;         // SW-420 vibrationSensorModul pin
int humSensor = 11;         // IR Detecting sensor pin
int sw =1;                  // tect Switch analog Pin
int gasSensor =0;           // MQ-9 gas Sensor Analog Pin 

SoftwareSerial BT(3,2); //BlueTooth (Tx,Rx)

int count = 0;             //judge valuable numbr whather earthquake is ccontinuous 

void setup() {
    pinMode(sp, OUTPUT);
    
    pinMode(vibSensor, INPUT);
    pinMode(humSensor, INPUT);
                                  //set pinmode
    Serial.begin(9600);
    BT.begin(9600);               //set serial comunication rate 
}

void loop() { 
  long measurement = vibMeasure();
  bool human = humanDetect();
  int gasMeasurement = gasMeasure();
   
                                  //INPUT sensor velue   
   Serial.print( "Vib = ");
   Serial.println(measurement);
   Serial.print("Gas = ");
   Serial.println(gasMeasurement);
   Serial.print("Is human here? = ");
   Serial.println(human);
   Serial.print("count = ");
   Serial.println(count);
   Serial.println("=========================================");
                                    //primt sensor velue to serialMonitor 
   if (measurement >50000){         //when earthqake happen, count =+1
     count++;
   }
    // the earthquale is continuous and near by human exist or Gas leak detect
   if((count>6 & human) | gasMeasurement >400) {
    tone(sp, 2965); //Ring tone 2965Hz
    while(true){
      int swVal = analogRead(sw);
      BT.println("1"); // bluetooth send serial print "1"
      delay(100);
      if(swVal > 200){
        count = 0; //when push the tect swithc, reset system;
        break;
        }
      }
   }
   else noTone(sp);


    
}

long vibMeasure(){
  long measurement = pulseIn (vibSensor, HIGH);
  return measurement;
}

bool humanDetect(){
  int humanSensorVal= digitalRead(humSensor);
  if(humanSensorVal == HIGH) return true;
  else return false;
  }

int gasMeasure(){
  int gasVal = analogRead(gasSensor);
  return gasVal;
}


