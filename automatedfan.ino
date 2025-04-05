#include <DHT.h>

#define DHTPIN 2       // DHT sensor connected to pin D2
#define DHTTYPE DHT11  // DHT11 or DHT22
#define FANPIN 3       // Fan connected to pin D3

DHT dht(DHTPIN, DHTTYPE);

void setup() {
    pinMode(FANPIN, OUTPUT);
    dht.begin();
}

void loop() {
    float temperature = dht.readTemperature(); // Read temperature in Celsius
    
    if (temperature > 30) { // Threshold temperature
        digitalWrite(FANPIN, HIGH); // Turn fan ON
    } else {
        digitalWrite(FANPIN, LOW); // Turn fan OFF
    }
    
    delay(2000); // Wait 2 seconds before next reading
}
