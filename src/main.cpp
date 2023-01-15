#include <Arduino.h>
#include <Wire.h>
#include <WiFi.h>
#include <OWMAdafruit_ADS1015.h>
#include <74HC40520.h>
#include <VH400.h>
#include <Teros10.h>
#include <GenericPH.h>
#include <Atlas_Gravity_pH.h>

Adafruit_ADS1115 ads;
Teros10 t10;
VH400 vh;
MUX_74HC40520 mux;
//GenericPH ph;
AtlasGravitypH ph;


const int D3 = 26;

void setup(){

  Serial.begin(115200);
  Wire.begin();

  delay(1000);

  pinMode(D3, OUTPUT);
  digitalWrite(D3, HIGH);

  mux.setPins(4, 15, 12);


  Serial.println("------------------------------");
  Serial.println("------------------------------");

  Serial.println("Grove4Ch16BitADC Test");

  Serial.println("------------------------------");
  Serial.println("------------------------------");
  Serial.println();

  ads.begin();

}

void loop(){
  bool pwr_en = true;

  digitalWrite(D3, pwr_en);
  Serial.printf("MAC Address: %s\n", WiFi.macAddress().c_str());
  Serial.println("========================================");

  mux.select(0);
  int16_t ad0 = ads.readADC_SingleEnded(0); // Teros 10 #1
  Serial.println("MUX_X-------------------------");
  Serial.print("\tCH#0 [VWC], ");
  Serial.print("VWC=");
  Serial.print(t10.getVWC(t10.SOILLESS, float(ad0)*0.0001875));
  //Serial.print(vh.getVWC());
  Serial.print("%, ");
  Serial.print(double(ad0) * 0.0001875);
  Serial.print("V, ad0=0x");
  Serial.println(ad0, HEX);

  mux.select(1);
  ad0 = ads.readADC_SingleEnded(0);
  Serial.print("\tCH#1 [VWC], ");
  Serial.print("VWC=");
  Serial.print(t10.getVWC(t10.SOILLESS, float(ad0)*0.0001875));
  Serial.print("%, ");
  Serial.print(double(ad0) * 0.0001875);
  Serial.print("V, ad0=0x");
  Serial.println(ad0, HEX);

  mux.select(2);
  ad0 = ads.readADC_SingleEnded(0);
  Serial.print("\tCH#2 [VWC], ");
  Serial.print("VWC=");
  Serial.print(t10.getVWC(t10.SOILLESS, float(ad0)*0.0001875));
  Serial.print("%, ");
  Serial.print(double(ad0) * 0.0001875);
  Serial.print("V, ad0=0x");
  Serial.println(ad0, HEX);

  mux.select(3);
  ad0 = ads.readADC_SingleEnded(0);
  Serial.print("\tCH#3 [PH], ");
  Serial.print(ph.getpH(ad0 * 0.0001875));
  Serial.print(" pH, ");
  Serial.print(double(ad0) * 0.0001875);
  Serial.print("V, ad0=0x");
  Serial.println(ad0, HEX);

  Serial.println("MUX_Y-------------------------");
  ad0 = ads.readADC_SingleEnded(1);
  Serial.print("\tCH#0, ");
  Serial.print(double(ad0) * 0.0001875);
  Serial.print("V, ad0=0x");
  Serial.println(ad0, HEX);

  Serial.println("BATT+-------------------------");
  ad0 = ads.readADC_SingleEnded(2);
  Serial.print(double(ad0) * 0.0001875);
  Serial.print("V, ad0=0x");
  Serial.println(ad0, HEX);

  Serial.println("AIN3--------------------------");
  ad0 = ads.readADC_SingleEnded(3); // Teros 10 #1
  Serial.print(double(ad0) * 0.0001875);
  Serial.print("V, ad0=0x");
  Serial.println(ad0, HEX);

  Serial.println("========================================\n\n");

  delay(1000);
}
