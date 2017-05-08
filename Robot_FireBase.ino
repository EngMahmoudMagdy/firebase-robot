#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "iffr-cf346.firebaseio.com" // firebase link
#define FIREBASE_AUTH "d9l8GP2AhJK68QDSoTwb8WrfRB2EbXHJD3iUSsUX" // firebase password or secret
#define WIFI_SSID "LINKDSL-Salah" // wifi name
//#define WIFI_SSID "Aya" // wifi name
#define WIFI_PASSWORD "M@7m0udM@9dy" // password
//#define WIFI_PASSWORD "123456789adm" // password
//, down , right , left , stopped ;
int data = 0; 
//////////////////////////  Motor 1 : 
const int pinRight1 = 12;//  Pin Right 1
const int pinLeft1 = 14; // pin Left 1 

//////////////////////////  Motor  : 
const int pinRight2 =2;//  Pin Right 2
const int pinLeft2 = 4;// pin Left 2

void setup() {
  Serial.begin(9600);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
 /* down = false ;
  right = false ;
  left = false ;
  stopped = true;*/
  
  pinMode(pinRight1,OUTPUT);
  pinMode(pinLeft1,OUTPUT);
  pinMode(pinRight2,OUTPUT);
  pinMode(pinLeft2,OUTPUT);
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}


void loop() {
  // get value
 data = Firebase.getInt("data"); 
  // handle error
  if (Firebase.failed()) {
      Serial.print("getting data failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(5);
 if(data == 0 )
 {
  analogWrite(pinRight1,0);
  analogWrite(pinLeft1,0);
  analogWrite(pinRight2,0);
  analogWrite (pinLeft2,0);
  Serial.println("Stopped");
  
  }
  else
  {
    if(data == 1)
    {
      analogWrite(pinRight1,750); // speed from 0 to 1023 and I choose 750 as average
      analogWrite(pinLeft1,0);
      analogWrite(pinRight2,750);
      analogWrite(pinLeft2,0);
      Serial.println("Up");
      
      }
    if(data == 2)
    {
      analogWrite(pinRight1,0);
      analogWrite(pinLeft1,750);
      analogWrite(pinRight2,0);
      analogWrite(pinLeft2,750);
      Serial.println("Down");
      }
    if(data == 3 )
    {
      analogWrite(pinRight1,0);
      analogWrite(pinLeft1,750);
      analogWrite(pinRight2,750);
      analogWrite(pinLeft2,0);
      Serial.println("Right");
      }
    if(data == 4 )
    {
      analogWrite(pinRight1,750);
      analogWrite(pinLeft1,0);
      analogWrite(pinRight2,0);
      analogWrite(pinLeft2,750);
      Serial.println("Left");
      }
    
    }
    
    delay(5);
}
