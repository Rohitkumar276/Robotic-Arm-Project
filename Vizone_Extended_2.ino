#include"ServoTimer2.h"

#include <SD.h> 
#define SD_ChipSelectPin 10
#include <TMRpcm.h>  


#define numOfvalsRec 5
#define digitsPervalRec 1

ServoTimer2 Thumb, Index, Middle, Ring, Pinky,elbow;
int state = HIGH;
int valsRec[numOfvalsRec]={0,0,1,0,1};
int stringLength = digitsPervalRec*numOfvalsRec + 1;
int counter = 0;
bool counterStart = false;
String receivedString;
unsigned long TimeStart,Interval;
int count=0;
int ToggleState = LOW,ToggleState1=LOW;
char c;
TMRpcm tmrpcm; 
int vicFlag=0,BeautyFlag=0,Natures_call=0,ungli=0,three=0,four=0,stopa=0,Swag=0,Spiderman=0,BOL=0,LCIT=0,ts1=0,ts2=0,fck=0,sorry=0,playstop=0,callme=0,unit=0;
void setup() {
  Serial.begin(9600);
  tmrpcm.speakerPin = 9;
  if (!SD.begin(SD_ChipSelectPin)) {  // see if the card is present and can be initialized:
    Serial.println("SD fail");  
    return;   // don't do anything more if not
  }
  Serial.println("Pass");   

  Thumb.attach(3);
  Index.attach(4);
  Middle.attach(5);
  Ring.attach(6);
  Pinky.attach(7);
  pinMode(8,INPUT);
  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(A2,INPUT);
  pinMode(A3,OUTPUT);
  pinMode(A4,OUTPUT);
  pinMode(A5,OUTPUT);
  pinMode(9,OUTPUT);
  for(int j=3; j<8; j++)
  {
    pinMode(j,OUTPUT);
  } 
  tmrpcm.play("intro.wav");
  delay(12000);
}

void copy_Mode();
void copywithCmd();
void Activation();
void receivedData();

void loop(){ 
  
  
  //Activation();
//  if(digitalRead(A2)){
//    
//    ToggleState1 = ~ToggleState1;
//    Serial.println(ToggleState1);
//  }
  
//  if(digitalRead(8)==HIGH){
//
//    ToggleState=LOW;
//      } 

//
//   else if(digitalRead(8)== LOW){
//        if(digitalRead(A2)==HIGH){
//
//          ToggleState = ~ToggleState;
//        }
        if(digitalRead(8)== HIGH){
         ts1=0;
         ts2++;
         if(ts2== 2)
           { tmrpcm.play("act.wav");
               Thumb.write(2280);   ///1
    Index.write(2280); ///1
    Middle.write(750);  ///1
    Ring.write(750);  ///1 
    Pinky.write(750); ///1 
           delay(3000);
             }
             receivedData();
           digitalWrite(A0,LOW);//Green//
           digitalWrite(A1,HIGH);
             copywithCmd();
           }
         else if(digitalRead(8)== LOW) {
             ts1++;
             ts2=0;
             if(ts1== 2)
               { tmrpcm.play("Normal.wav"); 
                   Thumb.write(2280);   ///1
    Index.write(2280); ///1
    Middle.write(750);  ///1
    Ring.write(750);  ///1 
    Pinky.write(750);  delay(3000);}
               receivedData();
           digitalWrite(A0,HIGH); //BLUE//
           digitalWrite(A1,LOW); 
  if(valsRec[0]==1){Thumb.write(2280);   }   if(valsRec[0]==0){Thumb.write(750);    }
  if(valsRec[1]==1){Index.write(2280);   }   if(valsRec[1]==0){Index.write(750);    }
  if(valsRec[2]==1){Middle.write(750);    }   if(valsRec[2]==0){Middle.write(2280); }
  if(valsRec[3]==1){Ring.write(750);      }   if(valsRec[3]==0){Ring.write(2280);   }
  if(valsRec[4]==1){Pinky.write(750);     }   if(valsRec[4]==0){Pinky.write(2280);  }
         }             
         
         delay(50);
         Serial.println(digitalRead(A2));

       }

       void receivedData() 
       { 
        while(Serial.available())
        {
          c= Serial.read();
          if(c=='$')
          {
            counterStart = true; 
   }///if $
   if(counterStart)
   {
    if(counter< stringLength)
    {
      receivedString = String(receivedString+c);
      counter++;
      }//counter
      if(counter >= stringLength)
        { for(int i=0 ; i<numOfvalsRec ;i++)
          { int num = (i*digitsPervalRec)+1;
            valsRec[i] = receivedString.substring(num,num + digitsPervalRec).toInt();
          }
          receivedString = "";
          counter =0;
          counterStart =false;
        }
   }//counter start

}//while
}
/////Copy Mode////

////copy with Command///
void copywithCmd(){
  ///Victory////
  if(valsRec[0]==0 && valsRec[1]==1 && valsRec[2] == 1 && valsRec[3]==0 && valsRec[4]==0){
    BeautyFlag=0;
    callme=0;unit=0;
    vicFlag++ ;
    fck=0;
    playstop=0;
    Natures_call=0; 
    ungli=0;
    sorry=0;
    three=0;
    four=0;
    stopa=0;
    Swag=0;
    Spiderman=0;
    BOL=0;
    LCIT=0;
    Thumb.write(750);   ///0
    Index.write(2280); ///1
    Middle.write(750);  ///1
    Ring.write(2280);  ///0 
    Pinky.write(2280); ///0 
    if(vicFlag== 2)
      { tmrpcm.play("victory.wav"); }
      else if(vicFlag == 50)
      { tmrpcm.play("bore.wav"); }
      
    delay(20);
    
  }
  /// Beautiful ///
  else if(valsRec[0]==0 && valsRec[1]==0 && valsRec[2] == 1 && valsRec[3]==1 && valsRec[4]==1){
    BeautyFlag++;
    vicFlag = 0 ;
    fck=0;
    sorry=0;
    Natures_call=0; 
     callme=0;unit=0;
    ungli=0;
    three=0;
    four=0;
    playstop=0;
    stopa=0;
    Swag=0;
    Spiderman=0;
    BOL=0;
    LCIT=0;
    Thumb.write(750);   ///0
    Index.write(750); ///0
    Middle.write(750);  ///1
    Ring.write(750);  ///1 
    Pinky.write(750); ///1   
    if(BeautyFlag== 2)
      { tmrpcm.play("bea.wav"); }
      else if(BeautyFlag == 50)
      { tmrpcm.play("bore.wav"); }
    delay(20); 
  }
  
  /// Nature's Call ///
  else if(valsRec[0]== 0 && valsRec[1]== 0 && valsRec[2] == 0 && valsRec[3]==0 && valsRec[4]==1){
    BeautyFlag=0;
    vicFlag = 0 ;
    fck=0;
     callme=0;unit=0;
    Natures_call++; 
    ungli=0;
    three=0;
    four=0;
    stopa=0;
    playstop=0;
    Swag=0;
    Spiderman=0;
    BOL=0;
     callme=0;unit=0;
    sorry=0;
    LCIT=0;
    Thumb.write(750);   ///0
    Index.write(750); ///0
    Middle.write(2280);  ///0
    Ring.write(2280);  ///0 
    Pinky.write(750); ///1   
    if(Natures_call== 2)
      { tmrpcm.play("nc.wav"); }
      else if(Natures_call == 50)
      { tmrpcm.play("bore.wav"); }
    delay(20); 
  }
    /// ungli ///
  else if(valsRec[0]==0 && valsRec[1]==1 && valsRec[2] == 0 && valsRec[3]==0 && valsRec[4]==0){
    BeautyFlag=0;
    vicFlag = 0 ;
    fck=0;
     callme=0;unit=0;
    Natures_call=0; 
    ungli++;
    three=0;
    playstop=0;
    four=0;
    stopa=0;
    sorry=0;
    Swag=0;
    Spiderman=0;
    BOL=0;
    LCIT=0;
    Thumb.write(750);   ///0
    Index.write(2280); ///1
    Middle.write(2280);  ///0
    Ring.write(2280);  ///0 
    Pinky.write(2280); ///0   
    if(ungli == 2)
      { tmrpcm.play("ungli.wav"); }
      else if(ungli == 50)
      { tmrpcm.play("bore.wav"); }
      
    delay(20); 
  }
   /// three ///
  else if(valsRec[0]==0 && valsRec[1]==1 && valsRec[2] == 1 && valsRec[3]==1 && valsRec[4]==0){
    BeautyFlag=0;
    fck=0;
    vicFlag = 0 ;
    Natures_call=0; 
    ungli=0;
     callme=0;unit=0;
    playstop=0;
    three++;
    sorry=0;
    four=0;
    stopa=0;
    Swag=0;
    Spiderman=0;
    BOL=0;
    LCIT=0;
    Thumb.write(750);   ///0
    Index.write(2280); ///1
    Middle.write(750);  ///1
    Ring.write(750);  ///1 
    Pinky.write(2280); ///0   
    if(three == 2)
      { tmrpcm.play("three.wav"); }
      else if(three == 50)
      { tmrpcm.play("bore.wav"); }
    delay(20); 
  }
 /////four////
  else if(valsRec[0]==0 && valsRec[1]==1 && valsRec[2] == 1 && valsRec[3]==1 && valsRec[4]==1){
    BeautyFlag=0;
    vicFlag = 0 ;
    fck=0;
    Natures_call=0; 
    ungli=0;
    sorry=0;
    three=0;
     callme=0;unit=0;
    playstop=0;
    four++;
    stopa=0;
    Swag=0;
    Spiderman=0;
    BOL=0;
    LCIT=0;
    Thumb.write(750);   ///0
    Index.write(2280); ///1
    Middle.write(750);  ///1
    Ring.write(750);  ///1 
    Pinky.write(750); ///1   
    if(four == 2)
      { tmrpcm.play("four.wav"); }
      else if(four == 50)
      { tmrpcm.play("bore.wav"); }
    delay(20); 
  }
  /////stop////
  else if(valsRec[0]==1 && valsRec[1]==1 && valsRec[2] == 1 && valsRec[3]==1 && valsRec[4]==1){
    BeautyFlag=0;
    fck=0;
    vicFlag = 0 ;
    Natures_call=0; 
    ungli=0;
    three=0;
    four=0;
     callme=0;unit=0;
    stopa++;
    sorry=0;
    playstop=0;
    Swag=0;
    Spiderman=0;
    BOL=0;
    LCIT=0;
    Thumb.write(2280);   ///1
    Index.write(2280); ///1
    Middle.write(750);  ///1
    Ring.write(750);  ///1 
    Pinky.write(750); ///1   
    if(stopa == 2)
      { tmrpcm.play("stopa.wav"); }
      else if(stopa == 50)
      { tmrpcm.play("bore.wav"); }
    delay(20); 
  }
  ///F*ck///
  else if(valsRec[0]==0 && valsRec[1]==0 && valsRec[2] == 1 && valsRec[3]==0 && valsRec[4]==0){
    BeautyFlag=0;
    fck++;
    vicFlag = 0 ;
     callme=0;unit=0;
    Natures_call=0; 
    ungli=0;
    three=0;
    four=0;
    stopa=0;
    Swag++;
    playstop=0;
    Spiderman=0;
    BOL=0;
    sorry=0;
    LCIT=0;
    Thumb.write(750);   ///0
    Index.write(750); ///0
    Middle.write(750);  ///1
    Ring.write(2280);  ///0 
    Pinky.write(2280); ///0   
    if(fck == 2)
      { tmrpcm.play("fck.wav"); }
      else if(fck == 50)
      { tmrpcm.play("bore.wav"); }
    delay(20); 
  }
  ///Swag///
  else if(valsRec[0]==0 && valsRec[1]==1 && valsRec[2] == 0 && valsRec[3]==0 && valsRec[4]==1){
    BeautyFlag=0;
    vicFlag = 0 ;
    Natures_call=0; 
    ungli=0;
    three=0;
     callme=0;unit=0;
    playstop=0;
    sorry=0;
    four=0;
    stopa=0;
    Swag++;
    Spiderman=0;
    BOL=0;
    LCIT=0;
    Thumb.write(750);   ///0
    Index.write(2280); ///1
    Middle.write(2280);  ///0
    Ring.write(2280);  ///0 
    Pinky.write(750); ///1   
    if(Swag == 2)
      { tmrpcm.play("Swag.wav"); }
      else if(Swag == 50)
      { tmrpcm.play("bore.wav"); }
    delay(20); 
  }
  ///Spiderman///
  else if(valsRec[0]==1 && valsRec[1]==1 && valsRec[2] == 0 && valsRec[3]==0 && valsRec[4]==1){
    BeautyFlag=0;
    vicFlag = 0 ;
    Natures_call=0; 
    ungli=0;
    three=0;
     callme=0;unit=0;
    four=0;
    sorry=0;
    stopa=0;
    playstop=0;
    Swag=0;
    Spiderman++;
    BOL=0;
    LCIT=0;
    Thumb.write(2280);   ///1
    Index.write(2280); ///1
    Middle.write(2280);  ///0
    Ring.write(2280);  ///0 
    Pinky.write(750); ///1   
    if(Spiderman == 2)
      { tmrpcm.play("victory1.wav"); }
      else if(Spiderman == 50)
      { tmrpcm.play("bore.wav"); }
    delay(20); 
  }
  ///Best of Luck///
  else if(valsRec[0]==1 && valsRec[1]==0 && valsRec[2] == 0 && valsRec[3]==0 && valsRec[4]==0){
    BeautyFlag=0;
    vicFlag = 0 ;
    Natures_call=0; 
    ungli=0;
    three=0;
    playstop=0;
    four=0;
     callme=0;unit=0;
    stopa=0;
    sorry=0;
    Swag=0;
    Spiderman=0;
    BOL++;
    LCIT=0;
    Thumb.write(2280);   ///1
    Index.write(750); ///0
    Middle.write(2280);  ///0
    Ring.write(2280);  ///0 
    Pinky.write(2280); ///0   
    if(BOL == 2)
      { tmrpcm.play("BOL.wav"); }
     else if(BOL == 50)
      { tmrpcm.play("bore.wav"); }
    delay(20); 
  }
  ///We love LCIT///
  else if(valsRec[0]==1 && valsRec[1]==1 && valsRec[2] == 0 && valsRec[3]==0 && valsRec[4]==0){
    BeautyFlag=0;
    vicFlag = 0 ;
    Natures_call=0; 
    ungli=0;
    three=0;
    playstop=0;
    sorry=0;
    four=0;
     callme=0;unit=0;
    stopa=0;
    Swag=0;
    Spiderman=0;
    BOL=0;
    LCIT++;
    Thumb.write(2280);   ///1
    Index.write(2280); ///1
    Middle.write(2280);  ///0
    Ring.write(2280);  ///0 
    Pinky.write(2280); ///0   
    if(LCIT == 2)
      { tmrpcm.play("lcit.wav"); }
      else if(LCIT == 50)
      { tmrpcm.play("bore.wav"); }
    delay(20); 
  }///Initial State
  else if(valsRec[0]==0 && valsRec[1]==0 && valsRec[2] == 1 && valsRec[3]==0 && valsRec[4]==1){
    BeautyFlag=0;
    vicFlag = 0 ;
    Natures_call=0; 
    ungli=0;
    three=0;
    playstop=0;
    sorry=0;
    four=0;
     callme=0;unit=0;
    stopa=0;
    Swag=0;
    Spiderman=0;
    BOL=0;
    LCIT++;
    Thumb.write(2280);   ///0
    Index.write(2280); ///0
    Middle.write(750);  ///1
    Ring.write(750);  ///0 
    Pinky.write(750); //1
//    if(LCIT == 2)
//      { tmrpcm.play("lcit.wav"); }
    delay(20); 
  }///unite//
  else if(valsRec[0]==0 && valsRec[1]==0 && valsRec[2] == 0 && valsRec[3]==0 && valsRec[4]==0){
    BeautyFlag=0;
    fck=0;
    vicFlag = 0 ;
    Natures_call=0; 
    ungli=0;
    three=0;
    four=0;
     callme=0;unit++;
    stopa++;
    sorry=0;
    playstop=0;
    Swag=0;
    Spiderman=0;
    BOL=0;
    LCIT=0;
    Thumb.write(750);   ///0
    Index.write(750); ///0
    Middle.write(2280);  ///0
    Ring.write(2280);  ///0 
    Pinky.write(2280); ///0   
    if(unit == 2)
      { tmrpcm.play("unit.wav"); }
      else if(unit == 50)
      { tmrpcm.play("bore.wav"); }
      
    delay(20); 
  }////Call me///
    else if(valsRec[0]==1 && valsRec[1]==0 && valsRec[2] == 0 && valsRec[3]==0 && valsRec[4]==1){
    BeautyFlag=0;
    fck=0;
    vicFlag = 0 ;
    Natures_call=0; 
    ungli=0;
    three=0;
    four=0;
     callme++;unit=0;
    stopa++;
    sorry=0;
    playstop=0;
    Swag=0;
    Spiderman=0;
    BOL=0;
    LCIT=0;
    Thumb.write(750);   ///1
    Index.write(2280); ///1
    Middle.write(750);  ///1
    Ring.write(750);  ///1 
    Pinky.write(2280); ///1   
    if(callme == 2)
      { tmrpcm.play("callme.wav"); }
      else if(callme == 50)
      { tmrpcm.play("bore.wav"); }
    delay(20); 
  }
  else {
    sorry++;
    BeautyFlag=0;
    fck=0;
    callme=0;unit=0;
    vicFlag = 0 ;
    Natures_call=0; 
    ungli=0;
    three=0;
    four=0;
    stopa=0;
    Swag=0;
    playstop=0;
    Spiderman=0;
    BOL=0;
    LCIT=0;
    if(sorry == 2)
      { tmrpcm.play("sorry.wav"); }
  if(valsRec[0]==1){Thumb.write(2280);   }   if(valsRec[0]==0){Thumb.write(750);    }
  if(valsRec[1]==1){Index.write(2280);   }   if(valsRec[1]==0){Index.write(750);    }
  if(valsRec[2]==1){Middle.write(750);    }   if(valsRec[2]==0){Middle.write(2280); }
  if(valsRec[3]==1){Ring.write(750);      }   if(valsRec[3]==0){Ring.write(2280);   }
  if(valsRec[4]==1){Pinky.write(750);     }   if(valsRec[4]==0){Pinky.write(2280);  }
    }
}

////Mode Switching////
//void Activation(){
//  if(valsRec[0]==0 && valsRec[1]==1 && valsRec[2] == 1 && valsRec[3]==0 && valsRec[4]==0){
//    count++;
//    Thumb.write(0);   ///0
//    Index.write(180); ///1
//    Middle.write(0);  ///1
//    Ring.write(180);  ///0 
//    Pinky.write(180); ///0 
//    if(count>500)
//      { state=~state; count=0;}
//    Serial.println(count); 
//
//  }  
//}
