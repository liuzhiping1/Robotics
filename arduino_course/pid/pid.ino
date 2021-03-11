float kp = 0, ki = 0, kd = 0;
float p = 0, i = 0, d = 0;
float pid;
int e = 0, pe = 0;
int lmt1 = 3, lmt2 = 5, rmt1 = 6, rmt2 = 11;
int init_speed = 100;
int lmsv, lsv, csv, rsv, rmsv;
int lmspeed;
int rmspeed;

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);

  pinMode(lmt1, OUTPUT);
  pinMode(lmt2, OUTPUT);
  pinMode(rmt1, OUTPUT);
  pinMode(rmt2, OUTPUT);
}

void loop() {
  lmsv = digitalRead(A0);
  lsv = digitalRead(A1);
  csv = digitalRead(A2);
  rsv = digitalRead(A3);
  rmsv = digitalRead(A4);

  if (lmsv == 0 && rmsv == 0) {
    sense();
    pid_val();
    mcontrol();
  }

  else if (lmsv == 1 && rmsv == 0) {
    analogWrite(lmt1, 0);
    analogWrite(lmt2, 255);
    analogWrite(rmt1, 255);
    analogWrite(rmt2, 0);
  }

  else if (lmsv == 0 && rmsv == 1) {
    analogWrite(lmt1, 255);
    analogWrite(lmt2, 0);
    analogWrite(rmt1, 0);
    analogWrite(rmt2, 255);
  }
}


void sense() {
  lsv = digitalRead(A1);
  csv = digitalRead(A2);
  rsv = digitalRead(A3);

  if (lsv == 1 && csv == 0 && rsv == 0) {
    e = 2;
  }

  else  if (lsv == 1 && csv == 1 && rsv == 0) {
    e = 1;
  }

  else  if (lsv == 0 && csv == 1 && rsv == 0) {
    e = 0;
  }

  else  if (lsv == 0 && csv == 1 && rsv == 1) {
    e = -1;
  }

  else  if (lsv == 0 && csv == 0 && rsv == 2) {
    e = -2;
  }
  else  if (lsv == 0 && csv == 0 && rsv == 0) {
    if (e == -4) {
      e = -5;
    }
    else {
      e = 5;
    }
  }
}

void pid_val() {
  p = e;
  i = i + e;
  d = pe - e;

  pid = (kp * p) + (ki * i) + (kd * d);

  pe = e;
}


void mcontrol() {
  lmspeed = init_speed - pid;
  rmspeed = init_speed + pid;

  constrain(lmspeed, 0, 255);
  constrain(rmspeed, 0, 255);

  analogWrite(lmt1, lmspeed);
  analogWrite(rmt1, rmspeed);

  digitalWrite(lmt2, LOW);
  digitalWrite(rmt2, LOW);
}
