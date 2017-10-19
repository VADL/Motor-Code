int hall0;
int hall1;
int hall2;
int prev0;
int prev1;
int prev2;
int halla = 11;
int hallb = 12;
int hallc = 13 ;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(halla, INPUT);
  pinMode(hallb, INPUT);
  pinMode(hallc, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(3, LOW); digitalWrite(5, LOW); digitalWrite(7, LOW);
  digitalWrite(4, HIGH); digitalWrite(6, HIGH); digitalWrite(8, HIGH); 
  delay(1000);
  
  digitalWrite(3, HIGH); digitalWrite(5, LOW); digitalWrite(7, LOW);
  digitalWrite(4, HIGH); digitalWrite(6, LOW); digitalWrite(8, HIGH);
  delay(1000);

  digitalWrite(3, LOW); digitalWrite(5, LOW); digitalWrite(7, LOW);
  digitalWrite(4, HIGH); digitalWrite(6, HIGH); digitalWrite(8, HIGH); 
  delay(1000);
  
  digitalWrite(3, LOW); digitalWrite(5, LOW); digitalWrite(7, HIGH);
  digitalWrite(4, LOW); digitalWrite(6, HIGH); digitalWrite(8, HIGH);
  delay(1000);

  digitalWrite(3, LOW); digitalWrite(5, LOW); digitalWrite(7, LOW);
  digitalWrite(4, HIGH); digitalWrite(6, HIGH); digitalWrite(8, HIGH); 
  delay(1000);
  
  digitalWrite(3, LOW); digitalWrite(5, HIGH); digitalWrite(7, LOW);
  digitalWrite(4, HIGH); digitalWrite(6, HIGH); digitalWrite(8, LOW);
  delay(1000);
}
