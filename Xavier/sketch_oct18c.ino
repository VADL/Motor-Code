int32_t frequency = 20000; //pwm frequency in Hz
unsigned int n = 0, timer2_initial_value, s = 0;
  int hall0 = 11;
  int hall1 = 12;
  int hall2 = 13 ;
  
void setup(){
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(hall0, INPUT);
  pinMode(hall1, INPUT);
  pinMode(hall2, INPUT);

}

void loop(){
  int s = 0;
  digitalWrite(8,0);digitalWrite(7,1);digitalWrite(6,0);
  digitalWrite(5,0);digitalWrite(4,1);digitalWrite(3,0);
  delay(s);
  digitalWrite(8,0);digitalWrite(7,0);digitalWrite(6,1);
  digitalWrite(5,0);digitalWrite(4,0);digitalWrite(3,1);
  delay(s);
  digitalWrite(8,1);digitalWrite(7,0);digitalWrite(6,0);
  digitalWrite(5,1);digitalWrite(4,0);digitalWrite(3,0);
  delay(s);

  Serial.print(digitalRead(hall0));
  Serial.print(digitalRead(hall1));
  Serial.println(digitalRead(hall2));
 
}
