const int ledPin =  13;
int ledState = LOW;
int num1, num2, num3, num4, digit1, digit2, digit3, digit4;   
int key1;
int key2;
int key3;
int key4;

void setup() { 
  pinMode(ledPin, OUTPUT); 
  delay(1000);
} 

void loop() {
  Keyboard.press(KEY_SPACE);
  Keyboard.release(KEY_SPACE);
  delay(1000);
  Keyboard.press(KEY_SPACE);
  Keyboard.release(KEY_SPACE);
  delay(1000);
  for (int startingdigit=0; startingdigit <= 9999; startingdigit++){
    flash();
  
    num1 = startingdigit / 1000;
    num2 = (startingdigit - (num1 * 1000)) / 100;
    num3 = (startingdigit - (num1 * 1000) - (num2 * 100)) / 10;
    num4 = (startingdigit - (num1 * 1000) - (num2 * 100) - (num3 * 10));
    
    key1 = setKey(num1);  
    Keyboard.press(key1);
    Keyboard.release(key1);
    key2 = setKey(num2); 
    Keyboard.press(key2);
    Keyboard.release(key2);
    key3 = setKey(num3); 
    Keyboard.press(key3);
    Keyboard.release(key3);
    key4 = setKey(num4); 
    Keyboard.press(key4);
    Keyboard.release(key4);
    delay(100);
    
    Keyboard.press(KEY_BACKSPACE);
    Keyboard.release(KEY_BACKSPACE);
    Keyboard.press(KEY_BACKSPACE);
    Keyboard.release(KEY_BACKSPACE);
    Keyboard.press(KEY_BACKSPACE);
    Keyboard.release(KEY_BACKSPACE);
    Keyboard.press(KEY_BACKSPACE);
    Keyboard.release(KEY_BACKSPACE);
    //delay(200);
  }
  exit(0);
}

void flash() {
  if (ledState == LOW)
    ledState = HIGH;
  else
    ledState = LOW;
  digitalWrite(ledPin, ledState);
}

int setKey(int num) {
  int key;
  switch (num) {
    case 0:
      key = KEY_0;
      break;
    case 1:
      key = KEY_1;
      break;
    case 2:
      key = KEY_2;
      break;
    case 3:
      key = KEY_3;
      break; 
    case 4:
      key = KEY_4;
      break; 
    case 5:
      key = KEY_5;
      break;
    case 6:
      key = KEY_6;
      break;
    case 7:
      key = KEY_7;
      break;
    case 8:
      key = KEY_8;
      break; 
    case 9:
      key = KEY_9;
      break;
    default: 
      //ERROR
      exit(0);
    break;
  }
  return key;
}



