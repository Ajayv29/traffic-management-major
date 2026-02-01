

// Define pins for Ultrasonic Sensors and LEDs for each lane
const int trigPin1 = 12, echoPin1 = 13, greenLED1 = 4, redLED1 = 18;
const int trigPin2 = 14, echoPin2 = 25, greenLED2 = 16, redLED2 = 19;
const int trigPin3 = 27, echoPin3 = 33, greenLED3 = 17, redLED3 = 21;
const int trigPin4 = 26, echoPin4 = 32, greenLED4 = 5, redLED4 = 22;

#define STAY_TIME 3000 // 3 seconds in milliseconds

unsigned long startTime1 = 0, startTime2 = 0, startTime3 = 0, startTime4 = 0;

void freelane1();
void freelane2();
void freelane3();
void freelane4();

void stoplane1();
void stoplane2();
void stoplane3();
void stoplane4();

void blinkLED(int redLED, int greenLED)
{
    for (int i = 0; i < 3; i++)
    {
        digitalWrite(redLED, HIGH);
        digitalWrite(greenLED, LOW);
        delay(500);
        digitalWrite(redLED, LOW);
        digitalWrite(greenLED, HIGH);
        delay(500);
    }
}

void setup()
{
    Serial.begin(115200);

    // Set up ultrasonic sensors
    pinMode(trigPin1, OUTPUT);
    pinMode(echoPin1, INPUT);
    pinMode(trigPin2, OUTPUT);
    pinMode(echoPin2, INPUT);
    pinMode(trigPin3, OUTPUT);
    pinMode(echoPin3, INPUT);
    pinMode(trigPin4, OUTPUT);
    pinMode(echoPin4, INPUT);

    // Set up LEDs
    pinMode(greenLED1, OUTPUT);
    pinMode(redLED1, OUTPUT);
    pinMode(greenLED2, OUTPUT);
    pinMode(redLED2, OUTPUT);
    pinMode(greenLED3, OUTPUT);
    pinMode(redLED3, OUTPUT);
    pinMode(greenLED4, OUTPUT);
    pinMode(redLED4, OUTPUT);

    // Start with all red LEDs on
    digitalWrite(greenLED1, LOW);
    digitalWrite(redLED1, HIGH);
    digitalWrite(greenLED2, LOW);
    digitalWrite(redLED2, HIGH);
    digitalWrite(greenLED3, LOW);
    digitalWrite(redLED3, HIGH);
    digitalWrite(greenLED4, LOW);
    digitalWrite(redLED4, HIGH);
}

void loop()
{
    long distance1 = getDistance(trigPin1, echoPin1);
    long distance2 = getDistance(trigPin2, echoPin2);
    long distance3 = getDistance(trigPin3, echoPin3);
    long distance4 = getDistance(trigPin4, echoPin4);

    if (distance1 < 3 && distance2 >= 5 && distance3 >= 5 && distance4 >= 5)
    {
        if (startTime1 == 0)
        {
            startTime1 = millis(); // Start the timer
        }
        else if (millis() - startTime1 >= STAY_TIME)
        {
            freelane1();
            startTime1 = 0; // Reset the timer
        }
    }
    else
    {
        startTime1 = 0; // Reset the timer if the vehicle leaves
    }

    if (distance2 < 3 && distance1 >= 5 && distance3 >= 5 && distance4 >= 5)
    {
        if (startTime2 == 0)
        {
            startTime2 = millis(); // Start the timer
        }
        else if (millis() - startTime2 >= STAY_TIME)
        {
            freelane2();
            startTime2 = 0; // Reset the timer
        }
    }
    else
    {
        startTime2 = 0; // Reset the timer if the vehicle leaves
    }

    if (distance3 < 3 && distance2 >= 5 && distance1 >= 5 && distance4 >= 5)
    {
        if (startTime3 == 0)
        {
            startTime3 = millis(); // Start the timer
        }
        else if (millis() - startTime3 >= STAY_TIME)
        {
            freelane3();
            startTime3 = 0; // Reset the timer
        }
    }
    else
    {
        startTime3 = 0; // Reset the timer if the vehicle leaves
    }

    if (distance4 < 3 && distance1 >= 5 && distance2 >= 5 && distance3 >= 5)
    {
        if (startTime4 == 0)
        {
            startTime4 = millis(); // Start the timer
        }
        else if (millis() - startTime4 >= STAY_TIME)
        {
            freelane4();
            startTime4 = 0; // Reset the timer
        }
    }
    else
    {
        startTime4 = 0; // Reset the timer if the vehicle leaves
    }

    delay(200); // Small delay to reduce processing frequency
}

long getDistance(int trigPin, int echoPin)
{
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    long duration = pulseIn(echoPin, HIGH);
    long distance = duration * 0.034 / 2; // Distance in cm

    return distance;
}

void freelane1()
{
    stoplane1();
    digitalWrite(greenLED1, HIGH);
    delay(56000); // 56 seconds in milliseconds

    blinkLED(redLED1, greenLED1);
}

void freelane2()
{
    stoplane2();
    digitalWrite(greenLED2, HIGH);
    delay(56000); // 56 seconds in milliseconds

    blinkLED(redLED2, greenLED2);
}

void freelane3()
{
    stoplane3();
    digitalWrite(greenLED3, HIGH);
    delay(56000); // 56 seconds in milliseconds

    blinkLED(redLED3, greenLED3);
}

void freelane4()
{
    stoplane4();
    digitalWrite(greenLED4, HIGH);
    delay(56000); // 56 seconds in milliseconds

    blinkLED(redLED4, greenLED4);
}

void stoplane1()
{
    digitalWrite(redLED1, LOW);
    digitalWrite(redLED2, HIGH);
    digitalWrite(redLED3, HIGH);
    digitalWrite(redLED4, HIGH);
}

void stoplane2()
{
    digitalWrite(redLED1, HIGH);
    digitalWrite(redLED2, LOW);
    digitalWrite(redLED3, HIGH);
    digitalWrite(redLED4, HIGH);
}

void stoplane3()
{
    digitalWrite(redLED1, HIGH);
    digitalWrite(redLED2, HIGH);
    digitalWrite(redLED3, LOW);
    digitalWrite(redLED4, HIGH);
}

void stoplane4()
{
    digitalWrite(redLED1, HIGH);
    digitalWrite(redLED2, HIGH);
    digitalWrite(redLED3, HIGH);
    digitalWrite(redLED4, LOW);
}
