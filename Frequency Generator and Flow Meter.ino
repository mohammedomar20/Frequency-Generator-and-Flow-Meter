#include <LiquidCrystal.h>

int x;
int State;
int LastState;

const int inputPin = A2; // Analog input pin for the signal
int test=0;
unsigned long myTime;
int k=0;
int c=0;
int z=0;
float u=0;
float y=0;
float delay_time=0;
int stop_generation =0;
int S;
void genrate_frequency(float frequency, float timee);
void calculatePulseFrequency();
const int pin_RS = 8; 
const int pin_EN = 9; 
const int pin_d4 = 4; 
const int pin_d5 = 5; 
const int pin_d6 = 6; 
const int pin_d7 = 7; 
const int pin_BL = 10; 
LiquidCrystal lcd( pin_RS,  pin_EN,  pin_d4,  pin_d5,  pin_d6,  pin_d7);
float frequenccy[]={0,200,0,0,500};
int number_of_turns=1;
int time[]={4,3,5,6,3};

float flow=0;
float volume=0;
const int pulsePin = A2; // Pin to read pulses
float frequencycalc=0;
float period=0;
int n=0;
float frequency[5];
unsigned long previousMillis = 0;
unsigned long pulseCount = 0;
int anymode=0;
float minf=9999;

float N=9999;

void setup() {
  Serial.begin(9600);
pinMode(pulsePin, INPUT);
lcd.begin(16, 2);
lcd.setCursor(0, 0);
  lcd.print("mazen abdelaziem");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("fatema ahmed");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("martina ashraf");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("mazen nasr");
  delay(1000);
  
lcd.clear();
lcd.setCursor(0,0);
lcd.print("up for test") ;
lcd.setCursor(0,1);
lcd.print("down for meter");
Serial.begin(9600);
while(1)
{

int x =analogRead(A0);
 if(x<200 && x>60)
{
  anymode=1;
  lcd.clear();
lcd.setCursor(0,0);
  lcd.print("press select");
  delay(500);
}
 else if(x<400 && x>200){
  anymode=2;
  lcd.clear();
lcd.setCursor(0,0);
  lcd.print("press select");
  delay(500);
}
else if (x<800 && x>600)
{
lcd.clear();
lcd.setCursor(0,0);
  lcd.print("now go to code");
  delay(500);
  break;
}
/*for(int i=0 ; i <5 ; i++)
{
  N[i]=31/frequenccy[i];

}

}*/
for(int i =0; i < 5; i++)
{
  if(minf>frequenccy[i]&&frequenccy[i]!=0)
  {
    minf=frequenccy[i];
  }
  
  N=32/minf;

}

for (int i = 0; i < 5; i++) {
   frequency[i]= frequenccy[i] * N ;
  }
   S= 5*number_of_turns;

}
}
//______________________________________________________
void loop() {
    x=analogRead(A0);          
      if(x<400 && x>200)
      {
       volume=0.00000000;
        lcd.setCursor(0, 1);
         lcd.print("volume = ");
       lcd.print(volume);
       
    }
  if(anymode==1){
   
          for(int i=0; i<5;i++){
    if(frequenccy[i]>=1){
  genrate_frequency(frequency[i],time[i]);}
  calculatePulseFrequency();
  period=1/(frequencycalc*0.5/N);
    stop_generation+=1;
  for(unsigned long t= millis();millis()-t<time[i]*1000;){
//while((frequencycalc*0.5/N)>0){
calculatePulseFrequency();

                flow=0.2*(frequencycalc*0.5/N);
              if(c%2==0){
                  u=millis();
                  c+=1;
                  delay_time=u-y;

                }
                else
                {
                   y=millis();
                     c+=1;
                     delay_time=y-u;
                }  
                 
                 if (z==0)
                {z=1;}
                else
                {
                volume+=flow*(delay_time)/60000;}

                lcd.clear();
                lcd.setCursor(0, 0);
                  lcd.print("flow = ");
                  lcd.print(flow,3);
                  lcd.setCursor(0, 1);
                  lcd.print("volume = ");
                  lcd.print(volume,3);
                delay(2*period*1000);
             
                
       x=analogRead(A0);          
      if(x<400 && x>200)
      {
       volume=0.00000000;
        lcd.setCursor(0, 1);
         lcd.print("volume = ");
       lcd.print(volume);
       
      }
  // }
  }
   }
    
   }
   //____________________________________________________
   else if(anymode==2)
   {
    while(1)
    {
      if(test==0){
    genrate_frequency(100,21);
    test=1;
      }
      
      //generating a const freq for testing
        calculatePulseFrequency();
        flow=0.2*(frequencycalc*0.5);
          period=1/(frequencycalc*0.5);
                if(c%2==0){
                  u=millis();
                  c+=1;
                  delay_time=u-y;

                }
                else
                {
                   y=millis();
                     c+=1;
                     delay_time=y-u;
                }  
                 
                 if (z==0)
                {z=1;}
                else
                {
                volume+=flow*(delay_time)/60000;}
                lcd.clear();
                lcd.setCursor(0, 0);
                  lcd.print("flow = ");
                  lcd.print(flow);
                  lcd.setCursor(0, 1);
                  lcd.print("volume = ");
                  lcd.print(volume);
                delay(period*1000);
             
                
       x=analogRead(A0);          
      if(x<400 && x>200)
      {
       volume=0.00000000;
        lcd.setCursor(0, 1);
         lcd.print("volume = ");
       lcd.print(volume);
       
      }
   }
 
}
}
//__________________
void calculatePulseFrequency() {
  pulseCount = pulseIn(pulsePin, HIGH); // Read pulse duration
  frequencycalc = pulseCount > 0 ? 1000000.0 / pulseCount : 0; // Calculate frequency (in Hz)
}
 

//___________________
void genrate_frequency(float frequency, float timee)
{

 if(stop_generation<S)

  tone(3, frequency ,timee*1000);
  
}