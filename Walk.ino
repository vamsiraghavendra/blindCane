void setup() {
  // put your setup code here, to run once:
  // Initalize the Ultrasonic Sensor
  //https://www.arduino.cc/reference/en/language/functions/digital-io/digitalwrite/ Pin as 5V
  //https://forum.arduino.cc/index.php?topic=186587.0 Pin as 5V
  
  
  pinMode(13,OUTPUT);//Trig
  pinMode(12,INPUT);//Echo ( Vcc = 5V is used. GRD1 is used.)

  pinMode(11,OUTPUT); // Trig2
  pinMode(10,INPUT); //Echo2 (Vcc = Vin is used) (GRD2 as GRD)
  
  pinMode(9, INPUT);//IR(Power from Vin, Digital IO is 9,8 is GRD)
  
  pinMode(A0, INPUT);//LDR -- LDR is Broken.(Could work with digital IO as 5V)(A0 and needs power) (Could be connected to 5V)
  
  pinMode(7, OUTPUT);// Buzzer(6 as GRD)
  pinMode(5,OUTPUT);// Buzzer2(4 as GRD)
  
  pinMode(3, OUTPUT);// LED (2 as GRD)
  
 
  Serial.begin(9600);

  //Extra Grounds.
  pinMode(6, OUTPUT);
  digitalWrite(6, LOW);
  
  pinMode(4, OUTPUT);
  digitalWrite(4, LOW);
  
  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);

  pinMode(8, OUTPUT);
  digitalWrite(8, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  
int ldr_value=analogRead(A0);//LDR

int ir_value=digitalRead(9); //IR Value.
  
int duration, distance;
digitalWrite(13, HIGH);
delay(50);
digitalWrite(13, LOW);
duration = pulseIn(12, HIGH);
distance =(duration/2) * 0.0343;;//Ultrasonic Sensor 1

int duration1, distance1;
digitalWrite(11, HIGH);
delay(50);
digitalWrite(11, LOW);
duration1 = pulseIn(10, HIGH);
distance1 =(duration1/2) * 0.0343; //Ultrasonic Sensor 2
  
Serial.print("U1 is is");
Serial.println(distance);
Serial.print("U2 is is");
Serial.println(distance1);
Serial.print("LDR is is");
Serial.println(ldr_value);
Serial.print("IR Value is is");
Serial.println(ir_value);
delay(1000);


if (ir_value == LOW)
{
  if ((distance <=10) || (distance1 <=10))
  {
    digitalWrite(7, HIGH);
    digitalWrite(5, HIGH);
  }
  else if ((distance > 10) && (distance <= 25)) 
  {
    digitalWrite(7, HIGH);
  }
  else if ((distance1 > 10) && (distance1 <=25))
  {
    digitalWrite(5, HIGH);
  }
  else
  {
    digitalWrite(7, LOW);
    digitalWrite(5, LOW);
  }
}
else
{
  digitalWrite(7, LOW);
  digitalWrite(5, LOW);
}
if (ldr_value < 1020)
  digitalWrite(3, HIGH);
else
  digitalWrite(3, LOW);
}
