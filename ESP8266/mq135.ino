#include <MQ135.h>
#define ANALOGPIN A0

int PPMStatus = 0;
int PPMStatusOld = 0;

float  airTemperature, airHumidity, ppm, ppmbalanced, rzero;
int initStep=1;                 // 1 = Connection in progress / 2 = Connection Done 

MQ135 gasSensor = MQ135(ANALOGPIN);

void setup() {
  Serial.begin(9600);
}

void loop() {

  // 當時室內大約的溫度跟濕度，讓 getCorrectPPM進行校正
  airTemperature = 28;
  airHumidity = 50;

  rzero = gasSensor.getRZero(); //取得rzero 校準值
  Serial.print("RZero=");
  Serial.println(rzero);    // 持續顯示 rzero 值
   
  ppm = gasSensor.getPPM(); // 取得 ppm 值
  Serial.print("PPM=");
  Serial.println(ppm); 
  
  ppmbalanced = gasSensor.getCorrectedPPM(airTemperature, airHumidity);  // 取得修正的 ppm 值
  Serial.print("PPM Corrected=");
  Serial.println(ppmbalanced); 
  Serial.println();

  delay(5000);
  }
