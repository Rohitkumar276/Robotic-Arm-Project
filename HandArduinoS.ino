#include<Servo.h>
Servo Thumb, Index, Middle, Ring, Pinky;

#define numOfvalsRec 5
#define digitsPervalRec 1

int valsRec[numOfvalsRec]={1,1,1,1,1};
int stringLength = digitsPervalRec*numOfvalsRec + 1;
int counter = 0;
bool counterStart = false;
String receivedString;


void setup() {
Serial.begin(9600);
Thumb.attach(3);
Index.attach(4);
Middle.attach(5);
Ring.attach(6);
Pinky.attach(7);



  for(int j=3; j<8; j++)
  {
  pinMode(j,OUTPUT);
  }
}


void receivedData();

void loop()
{
  receivedData();
  if(valsRec[0]==1){Thumb.write(180); } if(valsRec[0]==0){Thumb.write(0); }
  if(valsRec[1]==1){Index.write(180); } if(valsRec[1]==0){Index.write(0); }
  if(valsRec[2]==1){Middle.write(0);}   if(valsRec[2]==0){Middle.write(180);}
  if(valsRec[3]==1){Ring.write(0);  }   if(valsRec[3]==0){Ring.write(180);  }
  if(valsRec[4]==1){Pinky.write(0); }   if(valsRec[4]==0){Pinky.write(180); }

}

void receivedData() 
{ 
  while(Serial.available())
  {
   char c= Serial.read();
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
