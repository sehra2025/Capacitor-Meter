// C++ code
//
int analogpin =0;
int chargepin = 8;
int dischargepin = 9;
int resistorvalue = 10000;

unsigned long starttime;
unsigned long elapsetime;

float microfarad;
float nanofarad;

void setup()
{
  pinMode(chargepin, OUTPUT);
  digitalWrite(chargepin,LOW);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(chargepin, HIGH);
  starttime = millis();
  while(analogRead(analogpin)<610){
  
  }
  unsigned long nowtime = millis();
  elapsetime = nowtime -starttime;
  microfarad = ((float)elapsetime/resistorvalue)*1000;
  Serial.print(elapsetime);
  Serial.print(" ms   ");
  if(microfarad >1){
   Serial.print((long)microfarad);
   Serial.println("microfarads");
  }
  else{
  nanofarad = microfarad*1000.0;
   Serial.print((long)nanofarad);
   Serial.println("nanaofarads");
    delay(500);
    
  }
 
  digitalWrite(chargepin, LOW);
  pinMode(dischargepin,OUTPUT);
  digitalWrite(dischargepin,LOW);
  while(analogRead(analogpin)>0){
  }
 pinMode(dischargepin,INPUT);
  
}