int hall0;
int hall1;
int hall2;

int halla = 11;
int hallb = 12;
int hallc = 13 ;
  
void setup(){
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

int fwd(/*int hall1,int hall2, int hall0*/){
  digitalWrite(3, LOW); digitalWrite(5, LOW); digitalWrite(7, LOW);
  digitalWrite(4, HIGH); digitalWrite(6, HIGH); digitalWrite(8, HIGH);
  
  while(1){
    hall0 = digitalRead(halla);
    hall1 = digitalRead(hallb);
    hall2 = digitalRead(hallc);

    int a = hall0;
    int b = hall1;
    int c = hall2;

    int d = (~a & ~b & c) | (a & b & ~c);
    int e = (~b & c) | (b & ~c);
    int f = (~a & b & ~c) | (a & ~b & c);
    int g = (~a & b) | (a & ~b);
    int h = (~a & b & c) | (a & ~b & ~c);
    int i = (~a & c) | (a & ~c);
    
    digitalWrite(3, d); digitalWrite(5, f); digitalWrite(7, h);
    digitalWrite(4, e); digitalWrite(6, g); digitalWrite(8, i);
        
    Serial.print(digitalRead(hall0));
    Serial.print(digitalRead(hall1));
    Serial.println(digitalRead(hall2));

  }
}

     
void loop(){
//  digitalWrite(3, LOW); digitalWrite(5, LOW); digitalWrite(7, LOW);
//  digitalWrite(4, LOW); digitalWrite(6, LOW); digitalWrite(8, LOW);
  fwd();
}
