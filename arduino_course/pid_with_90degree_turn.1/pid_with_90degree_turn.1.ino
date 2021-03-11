float kp = 0.8, ki = 0.68, kd = 1;
float p = 0, i = 0, d = 0; //will differ, change the values according to the arena
float pid;
int e = 0, pe = 0;
int lmt1 = 3, lmt2 = 5, rmt1 = 11, rmt2 = 6; // change these values if the motors are going reverse
int init_speed = 100;
int lmsv, lsv, csv, rsv, rmsv;
int lmspeed;
int rmspeed;
int s1, s2;
int xval = 0, yval = 0;

void setup() {
  pinMode(6, INPUT);
  pinMode(7, INPUT);

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
  s1 = digitalRead(6);
  s2 = digitalRead(7);

  lmsv = digitalRead(A0);
  lsv = digitalRead(A1);
  csv = digitalRead(A2);
  rsv = digitalRead(A3);
  rmsv = digitalRead(A4);

  if (s1 == 0 && s2 == 0) {
    xval = 1;
    yval = 0;
    while (1) {
      lmsv = digitalRead(A0);
      lsv = digitalRead(A1);
      csv = digitalRead(A2);
      rsv = digitalRead(A3);
      rmsv = digitalRead(A4);

      if (lmsv == xval && rmsv == xval) {
        sense();
        pid_val();
        mcontrol();
      }

      else if (lmsv == yval && rmsv == xval) {
        analogWrite(lmt1, 0);
        analogWrite(lmt2, 255);
        analogWrite(rmt1, 255);
        analogWrite(rmt2, 0);
      }

      else if (lmsv == xval && rmsv == yval) {
        analogWrite(lmt1, 255);
        analogWrite(lmt2, 0);
        analogWrite(rmt1, 0);
        analogWrite(rmt2, 255);
      }
    }
  }
  else {
    xval = 0;
    yval = 1;

    if (lmsv == xval && rmsv == xval) {
      sense();
      pid_val();
      mcontrol();
    }

    else if (lmsv == yval && rmsv == xval) {
      analogWrite(lmt1, 0);
      analogWrite(lmt2, 255);
      analogWrite(rmt1, 255);
      analogWrite(rmt2, 0);
    }

    else if (lmsv == xval && rmsv == yval) {
      analogWrite(lmt1, 255);
      analogWrite(lmt2, 0);
      analogWrite(rmt1, 0);
      analogWrite(rmt2, 255);
    }
  }
}


void sense() {
  lsv = digitalRead(A1);
  csv = digitalRead(A2);
  rsv = digitalRead(A3);

  if (lsv == yval && csv == xval && rsv == xval) {
    e = 2;
  }

  else  if (lsv == yval && csv == yval && rsv == xval) {
    e = 1;
  }

  else  if (lsv == xval && csv == yval && rsv == xval) {
    e = 0;
  }

  else  if (lsv == xval && csv == yval && rsv == yval) {
    e = -1;
  }

  else  if (lsv == xval && csv == xval && rsv == yval) {
    e = -2;
  }
  else  if (lsv == xval && csv == xval && rsv == xval) {
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
