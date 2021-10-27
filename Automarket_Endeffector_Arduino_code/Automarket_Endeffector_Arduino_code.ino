/*
 Name:		Automarket_end_effector_2.ino
 Created:	8/10/2021 2:23:51 PM
 Author:	cslaw
*/

int rightSwitch = 2;
int leftSwitch = 3;
int built_in_led = 13;
int closedR = 0;
int closedL = 0;

void setup()
{
    Serial.begin(9600);
    pinMode(rightSwitch, INPUT);
    pinMode(leftSwitch, INPUT);
    pinMode(built_in_led, OUTPUT);
}

void loop()
{

//if (Serial.available > 0) {
//  int inByte = Serial.read();
//  
//}

//////////Right Switch
    if ((digitalRead(rightSwitch) == LOW) && (closedR == 0))
    {
        Serial.println("right switch is closed");
        closedR = 1;
        delay(20);
    }

    if ((digitalRead(rightSwitch) == HIGH) && (closedR == 1))
    {
        Serial.println("right switch is opened");
        closedR = 0;
        delay(20);
    }

    digitalWrite(rightSwitch, HIGH);


////////////////////Left switch
    if ((digitalRead(leftSwitch) == LOW) && (closedL == 0))
    {
        Serial.println("left switch is closed");
        closedL = 1;
        delay(20);
    }

    if ((digitalRead(leftSwitch) == HIGH) && (closedL == 1))
    {
        Serial.println("left switch is opened");
        closedL = 0;
        delay(20);
    }

    if ((closedL || closedR) == 1)
      digitalWrite(built_in_led, LOW);
    else
      digitalWrite(built_in_led, HIGH);

    digitalWrite(leftSwitch, HIGH);
}
