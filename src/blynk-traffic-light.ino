#define BLYNK_TEMPLATE_ID "TMPL3G2oYPIC9"
#define BLYNK_TEMPLATE_NAME "ESP8266 Traffic and Environment"
#define BLYNK_AUTH_TOKEN "YOUR-AUTH-TOKEN"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

char ssid[] = "YOUR-WIFI-NAME";
char pass[] = "YOUR-WIFI-PASSWORD";

#define RED 5
#define YELLOW 4
#define GREEN 14

#define DHTPIN 12
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

BlynkTimer timer;

void sendSensorData() {

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (!isnan(temperature)) {
    Blynk.virtualWrite(V0, temperature);
  }

  if (!isnan(humidity)) {
    Blynk.virtualWrite(V1, humidity);
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.println("-------------------------");
}


// PHONE → RED LIGHT
BLYNK_WRITE(V2) {

  int value = param.asInt();

  digitalWrite(RED, value);

  Serial.print("RED = ");
  Serial.println(value);
}


// PHONE → YELLOW LIGHT
BLYNK_WRITE(V3) {

  int value = param.asInt();

  digitalWrite(YELLOW, value);

  Serial.print("YELLOW = ");
  Serial.println(value);
}


// PHONE → GREEN LIGHT
BLYNK_WRITE(V4) {

  int value = param.asInt();

  digitalWrite(GREEN, value);

  Serial.print("GREEN = ");
  Serial.println(value);
}


BLYNK_CONNECTED() {

  Serial.println("Blynk Connected!");

  Blynk.syncVirtual(V2);
  Blynk.syncVirtual(V3);
  Blynk.syncVirtual(V4);
}


void setup() {

  Serial.begin(115200);

  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);

  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, LOW);

  dht.begin();

  Serial.println("Connecting to Blynk...");

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  timer.setInterval(2000L, sendSensorData);
}


void loop() {

  Blynk.run();

  timer.run();
}   