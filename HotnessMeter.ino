const int sensor = A0;
const int LED1 = 5;
const int LED2 = 6;
const int LED3 = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode (sensor, INPUT);
  Serial.begin(9600);
  pinMode (LED1, OUTPUT);
  pinMode (LED2, OUTPUT);
  pinMode (LED3, OUTPUT);

    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorVal = analogRead(sensor);
  
  Serial.print("Sensor value is: ");
  Serial.print(sensorVal);


  float voltage = (sensorVal/1024.0) * 5.0;
  Serial.print(", Voltage is: ");
  Serial.print(voltage);

  float temp = (voltage - 0.5)*100;

  Serial.print(", temperature C: ");
  Serial.println(temp);  

  if(temp <=21){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    
  }

  else if(temp > 21 && temp < 23){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW);
    
  }
  else if(temp > 24){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    
  }
    delay(5);
  
}
