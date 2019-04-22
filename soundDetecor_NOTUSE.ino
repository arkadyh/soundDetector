
//these define the pin connections
//TODO sendiing signal into mqtt
const int microphonePin= 0; //the microphone positive terminal will connect to analog pin A0 to be read
const int ledPin=2; //the code will flash the LED connected to pin 13

int sample; //the variable that will hold the value read from the microphone each time

const int threshold= 800;//the microphone threshold sound level at which the LED will turn on

void setup() {
pinMode (ledPin, OUTPUT);//sets digital pin 13 as output
Serial.begin(9600); //sets the baud rate at 9600 so we can check the values the microphone is obtaining on the Serial Monitor
}

void loop(){
sample= analogRead(microphonePin); //the arduino takes continuous readings from the microphone
Serial.println(sample);
if (sample > threshold)
{
digitalWrite (ledPin, LOW); //if the reading is greater than the threshold value, LED turns on
delay (1500); //LED stays on for a half a second
digitalWrite (ledPin, HIGH); //LED turns off
}
else
{
digitalWrite(ledPin, HIGH);
}
} 
