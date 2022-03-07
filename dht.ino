DHT dht(DHTPIN, DHTTYPE);

void setup() {
Serial.begin(9600);
Serial.println(F("DHTxx test!"));

dht.begin();
}

void loop() {
// Wait a few seconds between measurements.
delay(2000);

// Reading temperature or humidity takes about 250 milliseconds!
// Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
float h = dht.readHumidity();
// Read temperature as Celsius (the default)
float t = dht.readTemperature();
// Read temperature as Fahrenheit (isFahrenheit = true)
float f = dht.readTemperature(true);

// Check if any reads failed and exit early (to try again).
if (isnan(h) || isnan(t) || isnan(f)) {
Serial.println(F("Failed to read from DHT sensor!"));
return;
}

// Compute heat index in Fahrenheit (the default)
float hif = dht.computeHeatIndex(f, h);
// Compute heat index in Celsius (isFahreheit = false)
float hic = dht.computeHeatIndex(t, h, false);

Serial.print(F("Humidity: "));  // ‘시리얼 플로터’ 사용위해 이 부분 주석 필요
Serial.print(h);   // 습도 값 출력
Serial.print(F("% Temperature: ")); // ‘시리얼 플로터’ 사용위해 이 부분 주석 필요
Serial.print(t);   // 온도 값 출력 
Serial.print(F("°C "));
Serial.print(f);
Serial.print(F("°F Heat index: "));
Serial.print(hic);
Serial.print(F("°C "));
Serial.print(hif);
Serial.println(F("°F"));
}
