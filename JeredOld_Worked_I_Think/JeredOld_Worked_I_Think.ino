int hall0;
int hall1;
int hall2;
int prev0;
int prev1;
int prev2;
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

    if ((hall0 != prev0) || (hall1 != prev1) || (hall2 != prev2))
    {
      digitalWrite(3, LOW); digitalWrite(5, LOW); digitalWrite(7, LOW);
      digitalWrite(4, HIGH); digitalWrite(6, HIGH); digitalWrite(8, HIGH);  
    }
    
    if (hall0 == 0)
    {
      if (hall1 == 0) 
      {
        if (hall2 == 1)
        {
          // Hall 001
          digitalWrite(3, HIGH); digitalWrite(5, LOW); digitalWrite(7, LOW);
          digitalWrite(4, LOW); digitalWrite(6, HIGH); digitalWrite(8, LOW); 
        }
      }

      else
      {
        if (hall2 == 1)
        {
          // Hall 011
          digitalWrite(3, LOW); digitalWrite(5, HIGH); digitalWrite(7, LOW);
          digitalWrite(4, LOW); digitalWrite(6, LOW); digitalWrite(8, HIGH);
        }
        else
        {
          // Hall 010
          digitalWrite(3, LOW); digitalWrite(5, LOW); digitalWrite(7, HIGH);
          digitalWrite(4, HIGH); digitalWrite(6, LOW); digitalWrite(8, LOW);
        }
      }
    }

    else
    {
      if (hall1 == 1)
      {
        if (hall2 == 0)
        {
          // Hall 110
          digitalWrite(3, HIGH); digitalWrite(5, LOW); digitalWrite(7, LOW);
          digitalWrite(4, LOW); digitalWrite(6, HIGH); digitalWrite(8, LOW); 
        }
      }
      else
      {
        if (hall2 == 0)
        {
          // Hall 100
          digitalWrite(3, LOW); digitalWrite(5, HIGH); digitalWrite(7, LOW);
          digitalWrite(4, LOW); digitalWrite(6, LOW); digitalWrite(8, HIGH);
        }
        else
        {
          // Hall 101
          digitalWrite(3, LOW); digitalWrite(5, LOW); digitalWrite(7, HIGH);
          digitalWrite(4, HIGH); digitalWrite(6, LOW); digitalWrite(8, LOW);
        }
      }
    }

    Serial.print(digitalRead(hall0));
    Serial.print(digitalRead(hall1));
    Serial.println(digitalRead(hall2));
    
    prev0 = hall0;
    prev1 = hall1;
    prev2 = hall2;
  }
}

     
void loop(){
  digitalWrite(3, LOW); digitalWrite(5, LOW); digitalWrite(7, LOW);
  digitalWrite(4, LOW); digitalWrite(6, LOW); digitalWrite(8, LOW);
  fwd();
}
