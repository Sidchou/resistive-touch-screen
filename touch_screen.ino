/*=================================
This code demostrates 4-Wire Touch screen 
interfacing with Arduino

blog.circuits4you.com
www.circuits4you.com



4- Wire Touchscreen Connections
A0=====X+
A1=====X-
A2=====Y+
A3=====Y-
=================================*/
//Define your Touch screen connections
const int X1 = A3;
const int X2 = A1;
const int Y1 = A0;
const int Y2 = A2;
//Define your screen resolution as per your Touch screen (Max: 1024)
#define Xresolution 100 //128
#define Yresolution 100 //64

int tempX[10];
int tempY[10];
const int motor = 9;
 long timer = 0;
 

boolean swiftLeft();
boolean swiftRight();
boolean swiftUp();
boolean swiftDown();

void setup()
{
  pinMode(motor, OUTPUT);
   Serial.begin(9600);
   timer = millis();
//resetArray();
}

void loop(){
  
  //"push" and "splice" array
  for (int i = 8; i >= 0; i--) {
//    if (i<3){
//    Serial.print("X = ");  
//   Serial.print (tempX[i]);
//   Serial.print(" Y = ");
//   Serial.print(tempY[i]);
//    }
tempX[i + 1] = tempX[i];
tempY[i + 1] = tempY[i];
}
//Serial.println("");
  int X,Y; //Touch Coordinates are stored in X,Y variable
   pinMode(Y1,INPUT);
   pinMode(Y2,INPUT);  
   digitalWrite(Y2,LOW);
   pinMode(X1,OUTPUT);
   digitalWrite(X1,HIGH);
   pinMode(X2,OUTPUT);
   digitalWrite(X2,LOW);
   X = (analogRead(Y1)); //Reads X axis touch position
   pinMode(X1,INPUT);
   pinMode(X2,INPUT);
   digitalWrite(X2,LOW);
   pinMode(Y1,OUTPUT);
   digitalWrite(Y1,HIGH);
   pinMode(Y2,OUTPUT);
   digitalWrite(Y2,LOW);
   Y = (analogRead(X1)); //Reads Y axis touch position
  //Display X and Y on Serial Monitor
   
//add first element
   tempX[0] = X;
   tempY[0] = Y;

//    Serial.print("X = ");  
//   Serial.print (tempX[0]);
//   Serial.print(" Y = ");
//   Serial.print(tempY[0]);
   delay(30);

if (swiftLeft()){
//  Serial.println("Left");
  Serial.write(1);
   timer = millis();
      }
if(swiftRight()){
//  Serial.println("Right");
  Serial.write(2);
     timer = millis();

  
  }
  if (swiftUp()){
//  Serial.println("Up");
  Serial.write(3);
     timer = millis();

      }
if(swiftDown()){
//  Serial.println("Down");
  Serial.write(4);
     timer = millis();

  }

  vibration();

}

boolean swiftRight(){
  int beginPoint = 3; 
  int range = 3; 
  int trueCount = 0;
  int falseCount = 0;
  for (int j = beginPoint; j<beginPoint+range; j++){
    bool goodShit = true;
    for (int i = 0; i < j ; i ++){
      if (tempX[i]-tempX[i+1]<10){
        falseCount++;
        goodShit = false; 
        break;
      } 
    }
    if (goodShit){
      trueCount++;
    } 
  }
  if (trueCount > falseCount){
    return true;  
  }
  return false;
 } 

//
boolean swiftLeft(){
  int beginPoint = 3; 
  int range = 3; 
  int trueCount = 0;
  int falseCount = 0;
  for (int j = beginPoint; j<beginPoint+range; j++){
    bool goodShit = true;
    for (int i = 0; i < j ; i ++){
      if (tempX[i+1]-tempX[i]<10){
        falseCount++;
        goodShit = false; 
        break;
      } 
    }
    if (goodShit){
      trueCount++;
    } 
  }
  if (trueCount > falseCount){
    return true;  
  }
  return false;
  }

  
boolean swiftUp(){
  int beginPoint = 3; 
  int range = 3; 
  int trueCount = 0;
  int falseCount = 0;
  for (int j = beginPoint; j<beginPoint+range; j++){
    bool goodShit = true;
    for (int i = 0; i < j ; i ++){
      if (tempY[i]-tempY[i+1]<10){
        falseCount++;
        goodShit = false; 
        break;
      } 
    }
    if (goodShit){
      trueCount++;
    } 
  }
  if (trueCount > falseCount){
    return true;  
  }
  return false;
 } 

//
boolean swiftDown(){
  int beginPoint = 3; 
  int range = 3; 
  int trueCount = 0;
  int falseCount = 0;
  for (int j = beginPoint; j<beginPoint+range; j++){
    bool goodShit = true;
    for (int i = 0; i < j ; i ++){
      if (tempY[i+1]-tempY[i]<10){
        falseCount++;
        goodShit = false; 
        break;
      } 
    }
    if (goodShit){
      trueCount++;
    } 
  }
  if (trueCount > falseCount){
    return true;  
  }
  return false;
  }

  void resetArray(){
       for (int i = 9; i >= 0; i--) {
tempX[i] = -10;
//tempY[i] = -10;
}
    }

    void vibration(){
      if (millis()-timer < 300){
      digitalWrite(motor,HIGH);
      }else if (millis()-timer < 400){
      digitalWrite(motor,LOW);
      }else if (millis()-timer < 700){
      digitalWrite(motor,HIGH);
      }else{
      digitalWrite(motor,LOW);
      }
      }

    
