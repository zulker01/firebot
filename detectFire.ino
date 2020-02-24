const int tempSensor=A1; 
float tempc; 
float tempf; 
float vout; 

int flame_sensor = 2;
int flame_detected;

int MQ2pin = A0;
float sensorValue; 
int led =4;

// sonar 
const int trigPin = 6;
const int echoPin = 5;
// defines variables
long duration;
int distance;
int sonarled = 3;
void setup()
{

  pinMode(tempSensor,INPUT); 
  pinMode(flame_sensor, INPUT);
  pinMode(led, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(sonarled, OUTPUT);
  Serial.begin(9600);

}

void loop() {

  digitalWrite(led,LOW);
  //read temparature 
  vout=analogRead(tempSensor); 
  
  vout=(vout*500)/1023;

  tempc=vout; 

  tempf=(vout*1.8)+32; // Converting to Fahrenheit

  Serial.print("Temparature  DegreeC=");

  Serial.print(" ");

  Serial.print(tempc);

  Serial.print(" ");

  Serial.print("in Fahrenheit=");

  Serial.print(" ");

  Serial.print(tempf);

  Serial.println();

  //read flame sensor
  flame_detected = digitalRead(flame_sensor);
  Serial.print(flame_detected);
  
  

  // gas sensor 
   sensorValue = analogRead(MQ2pin); // read analog input pin 0
  
  Serial.print("Gas Sensor Value: ");
  Serial.print(sensorValue);
  
  
  if (flame_detected == 0 || sensorValue > 550 || tempc >80  )
  {
    Serial.println("  Fire detected...! take action immediately.");
    Serial.print(flame_detected);
    digitalWrite(led,HIGH);
     digitalWrite(LED_BUILTIN, HIGH);
    
  }
  else
  {
    Serial.println("  No flame detected. stay cool "+flame_detected);
   Serial.print(flame_detected);
  }
  Serial.println("");
   digitalWrite(LED_BUILTIN, LOW);

   // sonar 
   // Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
if(distance <20 ){
Serial.print("fuck");
digitalWrite(sonarled,HIGH);
//delay(200);
}
else
digitalWrite(sonarled,LOW);
  delay(500); //Delay of 1 second for ease of viewing 

}
