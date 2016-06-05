/*
Breathalyzer Halloween costume
JJ Graham - 10/23/2012
*/

int sV;
int ledOff = LOW; 
int ledOn = HIGH;

int t = 2;
int tr = 3;
int m = 4;
int br = 5;
int b = 6;
int bl = 7;
int tl = 8;

int point = 13;

int toggle = 10;

int onesDigit = 11;
int tensDigit = 12;

int BAC = 0; // Full BAC
int BAC1 = 0; // First digit of BAC
int BAC2 = 0; // Second digit of BAC

void setup()
{
  pinMode(t, OUTPUT);
  pinMode(tr, OUTPUT);
  pinMode(m, OUTPUT);
  pinMode(br, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(bl, OUTPUT);
  pinMode(tl, OUTPUT);
  
  pinMode(point, OUTPUT);
  
  pinMode(toggle, INPUT);
  
  pinMode(onesDigit, OUTPUT);
  pinMode(tensDigit, OUTPUT);
  
  // For troubleshooting
  Serial.begin(9600);      // sets the serial port to 9600
}

void loop()
{
  digitalWrite(onesDigit, ledOff);
  digitalWrite(tensDigit, ledOff);
  digitalWrite(point, ledOff);
      
  sV = analogRead(0);  // read alcohol sensor in analog 0
  Serial.println(sV);  // prints the value read
  delay(1000);          // wait 1s for next reading

  while(digitalRead(toggle) == HIGH)
  {
    digitalWrite(point, ledOn);
    sV = analogRead(0);  // read alcohol sensor in analog 0
    Serial.println(sV);  // prints the value read
    delay(10);

    // If BAC is going to be > 0
    if(sV > 795)
    {
      // If linear equation needs to be used
      if(sV < 830)
      {
        // Equation 1
        BAC = -542.254 + (0.691*sV);
      }
      // Else use quadratic equation
      else
      {
        // Equation 2
        BAC = (0.00351372*(sV^2))  +  (-5.62804*sV) + 2282.46;
      } 
      
      // Ones digit of BAC
      BAC1 = BAC/100;
      // Tens digit of BAC
      BAC2 = (BAC - (BAC1*100))/10;
      
      // Print ones digit for troubleshooting
      Serial.println(BAC1);
      // Print tens digit for troubleshooting
      Serial.println(BAC2);
    }
    else
    {
      BAC1 = 0;
      BAC2 = 0;
    }
    
    // LED TEST
    if (digitalRead(tensDigit) == LOW)
    {
      setLEDs(BAC2);
      digitalWrite(onesDigit, ledOff);
      digitalWrite(tensDigit, ledOn);
    }
    else
    {
      setLEDs(BAC1);
      digitalWrite(tensDigit, ledOff);
      digitalWrite(onesDigit, ledOn);
    }
  }
}

void setLEDs(int x)
{
  switch(x) {
    case 0:
      digitalWrite(t, ledOn);
      digitalWrite(tr, ledOff);
      digitalWrite(m, ledOn);
      digitalWrite(br, ledOn);
      digitalWrite(b, ledOn);
      digitalWrite(bl, ledOn);
      digitalWrite(tl, ledOn);
      break;
    case 1:
      digitalWrite(t, ledOff);
      digitalWrite(tr, ledOn);
      digitalWrite(m, ledOff);
      digitalWrite(br, ledOn);
      digitalWrite(b, ledOff);
      digitalWrite(bl, ledOff);
      digitalWrite(tl, ledOff);
      break;
    case 2:
      digitalWrite(t, ledOn);
      digitalWrite(tr, ledOn);
      digitalWrite(m, ledOn);
      digitalWrite(br, ledOff);
      digitalWrite(b, ledOn);
      digitalWrite(bl, ledOn);
      digitalWrite(tl, ledOff);
      break;
    case 3:
      digitalWrite(t, ledOn);
      digitalWrite(tr, ledOn);
      digitalWrite(m, ledOn);
      digitalWrite(br, ledOn);
      digitalWrite(b, ledOn);
      digitalWrite(bl, ledOff);
      digitalWrite(tl, ledOff);
      break;
    case 4:
      digitalWrite(t, ledOff);
      digitalWrite(tr, ledOn);
      digitalWrite(m, ledOn);
      digitalWrite(br, ledOn);
      digitalWrite(b, ledOff);
      digitalWrite(bl, ledOff);
      digitalWrite(tl, ledOn);
      break;
    case 5:
      digitalWrite(t, ledOn);
      digitalWrite(tr, ledOff);
      digitalWrite(m, ledOn);
      digitalWrite(br, ledOn);
      digitalWrite(b, ledOn);
      digitalWrite(bl, ledOff);
      digitalWrite(tl, ledOn);
      break;
    case 6:
      digitalWrite(t, ledOn);
      digitalWrite(tr, ledOff);
      digitalWrite(m, ledOn);
      digitalWrite(br, ledOn);
      digitalWrite(b, ledOn);
      digitalWrite(bl, ledOn);
      digitalWrite(tl, ledOn);
      break;
    case 7:
      digitalWrite(t, ledOn);
      digitalWrite(tr, ledOn);
      digitalWrite(m, ledOff);
      digitalWrite(br, ledOn);
      digitalWrite(b, ledOff);
      digitalWrite(bl, ledOff);
      digitalWrite(tl, ledOff);
      break;
    case 8:
      digitalWrite(t, ledOn);
      digitalWrite(tr, ledOn);
      digitalWrite(m, ledOn);
      digitalWrite(br, ledOn);
      digitalWrite(b, ledOn);
      digitalWrite(bl, ledOn);
      digitalWrite(tl, ledOn);
      break;
    case 9:
      digitalWrite(t, ledOn);
      digitalWrite(tr, ledOn);
      digitalWrite(m, ledOn);
      digitalWrite(br, ledOn);
      digitalWrite(b, ledOn);
      digitalWrite(bl, ledOff);
      digitalWrite(tl, ledOn);
      break;
  }
}
