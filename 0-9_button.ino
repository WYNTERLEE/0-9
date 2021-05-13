byte seven_seg_digits[10][7] = { { 0,0,0,0,0,0,1 },  // = 0
                                 { 1,0,0,1,1,1,1 },  // = 1
                                 { 0,0,1,0,0,1,0 },  // = 2
                                 { 0,0,0,0,1,1,0 },  // = 3
                                 { 1,0,0,1,1,0,0 },  // = 4
                                 { 0,1,0,0,1,0,0 },  // = 5
                                 { 0,1,0,0,0,0,0 },  // = 6
                                 { 0,0,0,1,1,1,1 },  // = 7
                                 { 0,0,0,0,0,0,0 },  // = 8
                                 { 0,0,0,1,1,0,0 },  // = 9
                             };
byte pin_numbers[7] = {2,3,4,5,6,7,8};
const int buttonPin = 9;
int buttonState = 0;
int oldbtn =0;
int num = 0;

void setup() {   
  Serial.begin(9600);            
  pinMode(2, OUTPUT);  
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(buttonPin,INPUT);
  sevenSegWrite(num);
}

void sevenSegWrite(byte digit) {
  for (byte seg = 0; seg < 7; seg++) {
    digitalWrite(pin_numbers[seg], seven_seg_digits[digit][seg]);
   
  }
}

void loop() {
     buttonState = digitalRead(buttonPin);
     if (buttonState == HIGH && oldbtn == 0){
      Serial.println(num);
      num++;
      if(num > 9){num = 0;}
      sevenSegWrite(num);
      }
   oldbtn = buttonState;
 delay(2);

}


