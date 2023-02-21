#include <RFID.h>

/*
* Read a card using a mfrc522 reader on your SPI interface
* Pin layout should be as follows (on Arduino Uno):
* MOSI: Pin 11 / ICSP-4
* MISO: Pin 12 / ICSP-1
* SCK: Pin 13 / ISCP-3
* SS/SDA: Pin 10
* RST: Pin 9
*/

#include <SPI.h>
#include <RFID.h>

#define SS_PIN 10
#define RST_PIN 9

RFID rfid(SS_PIN,RST_PIN);

//{5,117,21,219,190}

int cardsLeft[][5] = {
 {67, 70, 34 ,191 ,152},
 {46, 160, 130 ,205 ,193},
 {238, 56, 105 ,205 ,114},
 {254, 131, 158 ,205 ,46},
 {254, 128, 119 ,205 ,196},
 {190, 99, 146 ,205 ,130},
 {158, 211, 152 ,205 ,24},
 {110, 120, 158 ,205 ,69},
 {110, 49, 155 ,205 ,9},
 {174, 171, 153 ,205 ,81},
 {83, 126, 50 ,192 ,223},
 {126, 100, 151 ,205 ,64},
 {35, 225, 56 ,191 ,69},
 {94, 90, 156 ,205 ,85},
 {94, 148, 54 ,205 ,49},
 {195, 189, 75 ,191 ,138},
 {158, 149, 159 ,205 ,89},
 {67, 170, 63 ,191 ,105},
 {62, 171, 116 ,205 ,44},
 {3, 76, 54 ,191 ,198}
  
};

int cardsRight[][5] = {
  {254, 1, 151 ,205 ,165},
  {174, 138, 114 ,205 ,155},
  {67, 65, 74 ,191 ,247},
  {3, 120, 56 ,191 ,252},
  {83, 192, 48 ,191 ,28},
  {99, 205, 26 ,194 ,118},
  {19, 187, 68 ,191 ,83},
  {99, 131, 34 ,192 ,2},
  {206, 173, 160 ,205 ,14},
  {67, 172, 45 ,191 ,125},
  {30, 81, 160 ,205 ,34},
  {14, 48, 145 ,205 ,98},
  {174, 227, 149 ,205 ,21},
  {126, 160, 146 ,205 ,129},
  {46, 140, 161 ,205 ,206},
  {46, 94, 154 ,205 ,39},
  {62, 9, 151 ,205 ,109},
  {158, 161, 159 ,205 ,109},
  {147, 109, 33 ,194 ,29},
  {62, 127, 156 ,205 ,16}
  
};

int cardsForward[][5] = {
  {243, 204, 234, 193, 20},
  {51, 133, 28 ,194 ,104},
  {131, 141, 43 ,194 ,231},
  {67, 250, 67 ,194 ,56},
  {163, 247, 30 ,194 ,136},
  {19, 100, 35 ,194 ,150},
  {131, 73, 224 ,193 ,235},
  {19, 23, 236 ,193 ,41},
  {19, 0, 40 ,194 ,249},
  {179, 196, 28 ,194 ,169},
  {30, 10, 161 ,205 ,120},
  {222, 37, 157 ,205 ,171},
  {62, 37, 71 ,205 ,145},
  {190, 8, 147 ,205 ,232},
  {30, 181, 156 ,205 ,250},
  {46, 96, 156 ,205 ,31},
  {254, 38, 160 ,205 ,181},
  {62, 250, 145 ,205 ,152},
  {254, 74, 147 ,205 ,234},
  {126, 183, 143 ,205 ,139}
};

int led = 7;
int power = 8; 
int serNum[5];
int cards[][5] = {
  {5,117,21,219,190}
  
};
int pinled = 6;
bool access = false;

void setup(){

    Serial.begin(9600);
    SPI.begin();
    rfid.init();

    pinMode(led, OUTPUT);
    pinMode(pinled, OUTPUT);
  
    digitalWrite(led, LOW);
   
}

void loop(){
    
    if(rfid.isCard()){
    
        if(rfid.readCardSerial()){
            Serial.print("{");
            Serial.print(rfid.serNum[0]);
            Serial.print(",");
            Serial.print(" ");
            Serial.print(rfid.serNum[1]);
            Serial.print(",");
            Serial.print(" ");
            Serial.print(rfid.serNum[2]);
            Serial.print(" ");
            Serial.print(",");
            Serial.print(rfid.serNum[3]);
            Serial.print(" ");
            Serial.print(",");
            Serial.print(rfid.serNum[4]);
            Serial.print("}");
            Serial.println("");
            
            for(int x = 0; x < sizeof(cards); x++){
              for(int i = 0; i < sizeof(rfid.serNum); i++ ){
                  if(rfid.serNum[i] != cards[x][i]) {
                      access = false;
                      digitalWrite(pinled, HIGH);   // turn the LED on 
                       delay(1000);               // wait for a second
                      digitalWrite(pinled, LOW); 
                      break;
                  } else {
                      access = true;
                  }
              }
              if(access) break;
            }
           
        }
        
       if(access){
          Serial.println("Welcome!");
           digitalWrite(led, HIGH); 
           delay(1000);
           digitalWrite(led, LOW);
           digitalWrite(power, HIGH);
           delay(1000);
           digitalWrite(power, LOW);
           
      } else {
           Serial.println("Not allowed!"); 
           digitalWrite(led, HIGH);
           delay(500);
           digitalWrite(led, LOW); 
           delay(500);
           digitalWrite(led, HIGH);
           delay(500);
           digitalWrite(led, LOW);         
       }        
    }
    
    
    
    rfid.halt();

}
