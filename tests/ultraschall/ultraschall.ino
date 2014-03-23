#define ULTRA_ECHO 29                                   // Ultraschallsensor (Echo)
#define ULTRA_TRIG 31                                   // Ultraschallsensor (Trig)
#define ULTRA_DIST 2.8                                  // Distance zwischen Sender und Empfänger (in cm)
#define TEMPERATUR 18.6
#define PI 3.1415926535
#include <math.h>


long double distance_single(double temp) // Ultraschall-Abstandssensor | Rückgabewert in cm
{
  long double duration;
  digitalWrite(ULTRA_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(ULTRA_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(ULTRA_TRIG, LOW);
  duration = pulseIn(ULTRA_ECHO, HIGH);
  
  long double c = sqrt((28987/72)  * (temp + 273.15)) * 100; // in cm/s
  
  long double s =  c * duration * 0.000001;
  long double fi = (180* acos( ULTRA_DIST/(s)  ) / PI);
  return (s/2) * sin(PI*fi/180);
}

long double distance_avg(double temp)
{
  long double dist = 0;
  long double dist_ = 0;
  long double dist__ = 0;
  unsigned short int i, k, j;
  for(j=0; j<5;j++)
  {
    for(k = 0; k<5; k++)
    {
      for(i = 0; i<5; i++)
      {
        dist += distance_single(temp);
      }
      dist_ += dist / i;
      dist = 0;
    }
    
  dist__ += dist_ / k;
  dist_ = 0;
  }
  return dist__ / j;
}

void setup() {
  pinMode(ULTRA_ECHO, INPUT);
  pinMode(ULTRA_TRIG, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  if (Serial.available() > 0){
  char r = Serial.read();
  
  if (r=='r'){
    Serial.println("");
    Serial.print("Vormessung: ");
    Serial.println(analogRead(ULTRA_ECHO));
    Serial.print("Währenddessen: ");
    digitalWrite(ULTRA_TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(ULTRA_TRIG, HIGH);
    delayMicroseconds(10);
    Serial.println(analogRead(ULTRA_ECHO));
    Serial.println(analogRead(ULTRA_ECHO));
    digitalWrite(ULTRA_TRIG, LOW);
  }else{
    Serial.println("");
    Serial.print("Eingang: ");
    Serial.println(analogRead(ULTRA_ECHO));
    delay(1);
    Serial.print("Abstand in cm: ");
    Serial.println(double(distance_avg(TEMPERATUR)));       // Ultraschall-Abstandssensor abfragen
    Serial.read();
  }
  }
}
