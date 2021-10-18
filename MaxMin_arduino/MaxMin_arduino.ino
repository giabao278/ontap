void ledInit(void);
void ledUpdate(byte lByte);

void setup() 
{
  //ledInit();
  for(int i=2;i<=9;i++)
  {
     pinMode(i, OUTPUT);
  }

  for(int i=2;i<=9;i++)
  {
    digitalWrite(i, HIGH);
  }
  
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  
  Serial.begin(9600);
}

void loop() 
{
  if(Serial.available())
  {
    byte rxByte = Serial.read();
    //ledUpdate(rxByte);
    for(int i=2;i<=9;i++)
    {
      digitalWrite(i, (rxByte>>(i-2))&0x01);
    }
  }
  
  if(digitalRead(11) == LOW)
  {
    delay(50); //debounce
    //while(digitalRead(11) == LOW);
    Serial.print('a');
  }
  
  if(digitalRead(10) == LOW)
  {
    delay(50); //debounce
    while(digitalRead(10) == LOW);
    Serial.print('b');
  }
}

void ledInit()
{
  for(int i=2;i<=9;i++)
  {
     pinMode(i, OUTPUT);
  }
  /*
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  */
  for(int i=2;i<=9;i++)
  {
    digitalWrite(i, HIGH);
  }
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
}

void ledUpdate(byte lByte)
{
  for(int i=2;i<=9;i++)
  {
    digitalWrite(i, (lByte>>(i-2))&0x01);
  }
  /*
  digitalWrite(2,~lByte&0x01);
  digitalWrite(3,~(lByte>>1)&0x01);
  digitalWrite(4,~(lByte>>2)&0x01);
  digitalWrite(5,~(lByte>>3)&0x01);
  digitalWrite(6,~(lByte>>4)&0x01);
  digitalWrite(7,~(lByte>>5)&0x01);
  digitalWrite(8,~(lByte>>6)&0x01);
  digitalWrite(9,~(lByte>>7)&0x01);
  */
}
