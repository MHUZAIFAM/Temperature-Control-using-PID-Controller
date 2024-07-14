#include <LCD-I2C.h>
#include <DHT11.h>

// Define the pin for DHT11 sensor
const int DHT_PIN = 2;
// MOTOR1 PINS
int ena = 5;
int in1 = 6;
int in2 = 7;

// Initialize DHT11 sensor
DHT11 dht11(DHT_PIN);

// Address 0x27 is typical for most PCF8574 modules, change according to your module
LCD_I2C lcd(0x27, 20, 4);

// PID controller parameters
double kp = 0.8; // Proportional gain
double ki = 0.20; // Integral gain
double kd = 0.001; // Derivative gain
double setpoint = 25.0; // Desired temperature setpoint

// Variables for PID controller
double dt, last_time;
double integral, previous, output = 0;

void setup() {
    Serial.begin(9600); // Initialize serial communication
    lcd.begin();
    lcd.display();
    lcd.backlight();
    pinMode(ena, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    // Initialize PID controller variables
    last_time = millis();
}

void loop() {
    int PIDd = 0;
    double now = millis();
    dt = (now - last_time) / 1000.0;
    last_time = now;

    // Read temperature data from DHT11 sensor
    int temperature = 0;
    int humidity = 0;
    int result = dht11.readTemperatureHumidity(temperature, humidity);

    // Calculate PID controller output based on temperature error
    double error = setpoint - temperature;
    double corr = pid(error);
    PIDd = temperature;
    output -= corr;

    // Clear the LCD screen
    lcd.clear();
    
    // Print temperature and humidity on LCD and serial monitor
    lcd.setCursor(0, 0);
    lcd.print("TEMPERATURE: ");
    lcd.print(temperature);
    lcd.print(" °C");
    lcd.setCursor(0, 1);
    lcd.print("HUMIDITY: ");
    lcd.print(humidity);
    lcd.print(" %");
    Serial.print("Temperature:");
    Serial.print(temperature);
    Serial.print("°C\tHumidity:");
    Serial.print(humidity);
    Serial.println("%");

    // Print PID controller output on serial monitor
    Serial.print("PID Output: ");
    Serial.println(output);

    // Motor control logic based on temperature
    if (PIDd == 31) {
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        analogWrite(ena, 0);
        lcd.setCursor(0, 2);
        lcd.print("AT OPTIMUM TEMP");
        lcd.setCursor(0, 3);
        lcd.print("MOTOR SPEED 0");
    } 
    else if (PIDd >= 32 && PIDd < 33) {
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        analogWrite(ena, 255);
        lcd.setCursor(0, 2);
        lcd.print("TEMP EXCEEDS");
        lcd.setCursor(0, 3);
        lcd.print("MOTOR SPEED HALF");
    } 
    else if (PIDd >= 33) {
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        analogWrite(ena, 255);
        lcd.setCursor(0, 2);
        lcd.print("TEMP EXCEEDS");
        lcd.setCursor(0, 3);
        lcd.print("MOTOR SPEED MAX");
    } 

    delay(2000); // Delay for 2000 milliseconds before next reading
}

// PID controller function
double pid(double error) {
    double proportional = kp * error;
    integral += ki * error * dt;
    double derivative = kd * (error - previous) / dt;
    previous = error;
    double output = proportional + integral + derivative;
    return output;
}
