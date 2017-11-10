volatile int val = 0;
#define duty 90 //input a percentage 0->100
#define dir LOW //direction of motor.


void setup() {
  // put your setup code here, to run once:
  noInterrupts();
  pinMode(5,OUTPUT);
  pinMode(7,OUTPUT);
  digitalWrite(7, dir);
  Serial.begin(9600);
  int tmp=int(duty*256/100);
  OCR0B = tmp;
  TCCR0A = _BV(COM0B1) | _BV(WGM01) | _BV(WGM00);
  TIMSK0 |= (1<<OCIE0B);
  setPwmFrequency(5,1);
  interrupts();
}
ISR(_VECTOR(14)){
  digitalWrite(5,val);
  val++;
  val = val%2;
}

void setPwmFrequency(int pin, int divisor) {
  byte mode;
  if(pin == 5 || pin == 6 || pin == 9 || pin == 10) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 64: mode = 0x03; break;
      case 256: mode = 0x04; break;
      case 1024: mode = 0x05; break;
      default: return;
    }
    if(pin == 5 || pin == 6) {
      TCCR0B = TCCR0B & 0b11111000 | mode;
    } else {
      TCCR1B = TCCR1B & 0b11111000 | mode;
    }
  } else if(pin == 3 || pin == 11) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 32: mode = 0x03; break;
      case 64: mode = 0x04; break;
      case 128: mode = 0x05; break;
      case 256: mode = 0x06; break;
      case 1024: mode = 0x07; break;
      default: return;
    }
    TCCR2B = TCCR2B & 0b11111000 | mode;
  }
}
void loop() {}
