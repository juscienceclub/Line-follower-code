int left_motor_forward=0;
int left_motor_backward=0;
int right_motor_forward=0;
int right_motor_backward=0;
int ir_sensors[6];
int ir_pins[]={8,9,10,11,12,13};
void setup(){
  int pins;
  for(pins=0;pins<6;pins++)
    pinMode(ir_pins[pins],OUTPUT);
  Serial.begin(9600);
}
void goAhead(){
  digitalWrite(left_motor_forward,HIGH);
  digitalWrite(right_motor_forward,HIGH);
  digitalWrite(left_motor_backward,LOW);
  digitalWrite(right_motor_backward,LOW);
}

void turnLeft(){
  digitalWrite(left_motor_forward,LOW);
  digitalWrite(right_motor_forward,HIGH);
  digitalWrite(left_motor_backward,HIGH);
  digitalWrite(right_motor_backward,LOW);
}

void turnRight(){
  digitalWrite(left_motor_forward,HIGH);
  digitalWrite(right_motor_forward,LOW);
  digitalWrite(left_motor_backward,LOW);
  digitalWrite(right_motor_backward,HIGH);
}
void Stop(){
  digitalWrite(left_motor_forward,LOW);
  digitalWrite(right_motor_forward,LOW);
  digitalWrite(left_motor_backward,LOW);
  digitalWrite(right_motor_backward,LOW);
}
void loop(){
  int i;
  for(i=0;i<6;i++){
    ir_sensors[i]=digitalRead(ir_pins[i]);
  }
  int first_low=0;
  int last_low=0;
  int c=0;
  int pos=0;
  for(i=0;i<5;i++){
    if(ir_sensors[i]==0){
      c++;
      pos=i;
    if(c==1)
    first_low=i;
    }
  }
  last_low=pos;
  float mean= float(first_low+last_low)/2;
  if(mean>1 && mean <3){
    goAhead();
    Serial.println("Go ahead");
  }
  else if(mean<=1){
    turnLeft();
    Serial.println("Turning left");
  }
  else if(mean>=3)
  {
    turnRight();
    Serial.println("Turning right");
  }
  else if(mean==0){
    Stop();
    Serial.println("Stopped");
  }
}
  


