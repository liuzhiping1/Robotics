#include <Robot.h>

Robot lt(3, 5, 11, 6);

int lmsv, lsv, csv, rsv , rmsv;
int s1, s2, s3;
int n;
String ldir = "left";
char dir [1000] = {};
int x = 100;
int a = 0, b = 0, c = 0, d = 0, e = 0, j = 0;




void setup() {
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
}




void loop() {
  s1 = digitalRead(7);
  s2 = digitalRead(8);
  if ( s1 == 0 && s2 == 1) {
    trial();
  }
  else if (s1 == 1 && s2 == 0) {
    real();
  }
  else {
    simplify();
    lt.Move('S', 150, 0);
  }
}




void trial() {
  lmsv = digitalRead(A0);
  lsv = digitalRead(A1);
  csv = digitalRead(A2);
  rsv = digitalRead(A3);
  rmsv = digitalRead(A4);
  if (lmsv == 0 && rmsv == 0) {
    if (lsv == 1 && csv == 0 && rsv == 0) {
      x = 100;
      ldir = "left";
      lt.Move('l', 150, 30);
    }
    else if (lsv == 1 && csv == 1 && rsv == 0 ) {
      lt.Move('l', x, 25);
      if (x == 200) {
        x = 100;
      }
      else {
        x++;
      }
    }
    else if (lsv == 0 && csv == 1 && rsv == 0) {
      lt.Move('F', x, 0);
      if (x == 200) {
        x = 100;
      }
      else {
        x++;
      }
    }
    else if (lsv == 0 && csv == 1 && rsv == 1) {
      lt.Move('r', x, 25);
      if (x == 200) {
        x = 100;
      }
      else {
        x++;
      }
    }
    else if (lsv == 0 && csv == 0 && rsv == 1) {
      x = 100;
      ldir = "right";
      lt.Move('r', 150, 50);
    }
    else if (lsv == 0 && csv == 0 && rsv == 0)  {
      x = 100;
      if (ldir == "left") {
        lt.Move('L', 150, 0);
      }
      else {
        lt.Move('R', 150, 0);
      }
      dir [a] = 'U';
      a++;
    }
  }

  else if (lmsv == 1 && rmsv == 1) {
    dir[a] = 'L';
    a++;
    while (lmsv == 1 && rmsv == 1 && lsv == 1) {
      lt.Move('L', 125, 0);
      lmsv = digitalRead(A0);
      lsv = digitalRead(A1);
      csv = digitalRead(A2);
      rsv = digitalRead(A3);
      rmsv = digitalRead(A4);
    }
  }
  else if (lmsv == 1 && lsv == 0 && csv == 0 && rsv == 0 && rmsv == 0) {
    ldir = "left";
    lt.Move('L', 125, 0);
  }
  else if (lmsv == 0 && lsv == 0 && csv == 0 && rsv == 0 && rmsv == 1) {
    ldir = "right";
    lt.Move('R', 125, 0);
  }
  else if (lmsv == 0 && lsv == 1 && csv == 1 && rsv == 1 && rmsv == 1) {
    ldir = "right";
    while (1) {
      lt.Move('F', 150, 0);
      delay(300);
      lt.Move('S', 0, 0);
      lmsv = digitalRead(A0);
      lsv = digitalRead(A1);
      csv = digitalRead(A2);
      rsv = digitalRead(A3);
      rmsv = digitalRead(A4);
      if (lmsv == 0 && lsv == 0 && csv == 0 && rsv == 0 && rmsv == 0) {
        dir[a] = 'R';
        a++;
        break;
      }
      else if (csv == 1 || lsv == 1 || rsv == 1) {
        dir[a] = 'F';
        a++;
        break;
      }
    }
  }
  else if (lmsv == 1 && lsv == 1 && csv == 1 && rsv == 1 && rmsv == 0) {
    dir[a] = "L";
    a++;
    ldir = "left";
    lt.Move('L', 125, 0);
  }
}

void real() {
  lmsv = digitalRead(A0);
  lsv = digitalRead(A1);
  csv = digitalRead(A2);
  rsv = digitalRead(A3);
  rmsv = digitalRead(A4);
  if (lmsv == 0 && rmsv == 0) {
    if (lsv == 1 && csv == 0 && rsv == 0) {
      x = 100;
      ldir = "left";
      lt.Move('F', 150, 0);
    }
    else if (lsv == 1 && csv == 1 && rsv == 0 ) {
      lt.Move('l', x, 25);
      if (x == 200) {
        x = 100;
      }
      else {
        x++;
      }
    }
    else if (lsv == 0 && csv == 1 && rsv == 0) {
      lt.Move('F', x, 0);
      if (x == 200) {
        x = 100;
      }
      else {
        x++;
      }
    }
    else if (lsv == 0 && csv == 1 && rsv == 1) {
      lt.Move('r', x, 25);
      if (x == 200) {
        x = 100;
      }
      else {
        x++;
      }
    }
    else if (lsv == 0 && csv == 0 && rsv == 1) {
      x = 100;
      ldir = "right";
      lt.Move('r', 150, 50);
    }
    else if (lsv == 0 && csv == 0 && rsv == 0)  {
      x = 100;
      if (ldir == "left") {
        lt.Move('L', 150, 0);
      }
      else {
        lt.Move('R', 150, 0);
      }
    }
  }

  else if (lmsv == 1 && rmsv == 1) {
    if (dir[d] == 'L') {
      d++;
      while (lmsv == 1 && rmsv == 1) {
        lt.Move('L', 150, 0);
        lmsv = digitalRead(A0);
        lsv = digitalRead(A1);
        csv = digitalRead(A2);
        rsv = digitalRead(A3);
        rmsv = digitalRead(A4);
      }
    }
    else if (dir[d] == 'R') {
      d++;
      while (lmsv == 1 && rmsv == 1) {
        lt.Move('R', 150, 0);
        lmsv = digitalRead(A0);
        lsv = digitalRead(A1);
        csv = digitalRead(A2);
        rsv = digitalRead(A3);
        rmsv = digitalRead(A4);
      }
    }
    else if (dir[d] == 'F') {
      d++;
      lt.Move('F', 150, 0);
    }
    else {
      d++;
      if (ldir == "left") {
        while (lmsv == 1 && lsv == 1 && csv == 1 && rsv == 1 && rmsv == 1) {
          lt.Move('L', 150, 0);
          lmsv = digitalRead(A0);
          lsv = digitalRead(A1);
          csv = digitalRead(A2);
          rsv = digitalRead(A3);
          rmsv = digitalRead(A4);
        }
      }
      else {
        while (lmsv == 1 && lsv == 1 && csv == 1 && rsv == 1 && rmsv == 1) {
          lt.Move('R', 150, 0);
          lmsv = digitalRead(A0);
          lsv = digitalRead(A1);
          csv = digitalRead(A2);
          rsv = digitalRead(A3);
          rmsv = digitalRead(A4);
        }
      }
    }
  }
  else if (lmsv == 1 && lsv == 0 && csv == 0 && rsv == 0 && rmsv == 0) {
    ldir = "left";
    lt.Move('L', 125, 0);
  }
  else if (lmsv == 0 && lsv == 0 && csv == 0 && rsv == 0 && rmsv == 1) {
    ldir = "right";
    lt.Move('R', 125, 0);
  }
  else if (lmsv == 0 && lsv == 1 && csv == 1 && rsv == 1 && rmsv == 1) {
    ldir = "right";
    if (dir[d] == 'F') {
      d++;
      lt.Move('F', 150, 0);
    }
    else if (dir[d] == 'R') {
      d++;
      while (rmsv == 1) {
        lt.Move('R', 150, 0);
        rmsv = digitalRead(A4);
      }
    }
    else if (dir[d] == 'L') {
      d++;
      while (rmsv == 1) {
        lt.Move('L', 150, 0);
        rmsv = digitalRead(A4);
      }
    }
    else {
      d++;
      if (ldir == "right") {
        while (lsv == 1 && csv == 1 && rsv == 1 && rmsv == 1) {
          lt.Move('R', 150, 0);
          lsv = digitalRead(A1);
          csv = digitalRead(A2);
          rsv = digitalRead(A3);
          rmsv = digitalRead(A4);
        }
      }
      else {
        while (lsv == 1 && csv == 1 && rsv == 1 && rmsv == 1) {
          lt.Move('L', 150, 0);
          lsv = digitalRead(A1);
          csv = digitalRead(A2);
          rsv = digitalRead(A3);
          rmsv = digitalRead(A4);
        }
      }
    }
  }
  else if (lmsv == 1 && lsv == 1 && csv == 1 && rsv == 1 && rmsv == 0) {
    ldir = "left";
    if (dir[d] == 'L') {
      d++;
      while (lmsv == 1) {
        lt.Move('L', 125, 0);
        lmsv = digitalRead(A0);
      }
    }
    else if (dir[d] == 'R') {
      d++;
      while (lmsv == 1) {
        lt.Move('R', 150, 0);
        lmsv = digitalRead(A0);
      }
    }
    else if (dir[d] == 'F') {
      d++;
      lt.Move('F', 150, 0);
      delay(200);
      lt.Move('S', 150, 0);
    }
    else {
      d++;
      if (ldir == "right") {
        while (lmsv == 1 && lsv == 1 && csv == 1 && rsv == 1) {
          lt.Move('R', 150, 0);
          lmsv = digitalRead(A0);
          lsv = digitalRead(A1);
          csv = digitalRead(A2);
          rsv = digitalRead(A3);
        }
      }
      else {
        while (lmsv == 1 && lsv == 1 && csv == 1 && rsv == 1) {
          lt.Move('L', 150, 0);
          lmsv = digitalRead(A0);
          lsv = digitalRead(A1);
          csv = digitalRead(A2);
          rsv = digitalRead(A3);
        }
      }
    }
  }
}



void simplify() {
  b = a;
  for (int i = 0; i < b; i++) {
    int change = 0;
    if (dir[i] == 'L' && dir[i + 1] == 'U' && dir[i + 2] == 'L') {
      dir[i] = 'S';
      for (int j = i + 1; (j + 2) < n; j++) {
        dir[j] = dir[j + 2];
      }
      b = j;
      change = 1;
    }

    else if (dir[i] == 'R' && dir[i + 1] == 'U' && dir[i + 2] == 'R') {
      dir[i] = 'S';
      for (int j = i + 1; (j + 2) < n; j++) {
        dir[j] = dir[j + 2];
      }
      b = j;
      change = 1;
    }

    else if (dir[i] == 'S' && dir[i + 1] == 'U' && dir[i + 2] == 'L') {
      dir[i] = 'R';
      for (int j = i + 1; (j + 2) < n; j++) {
        dir[j] = dir[j + 2];
      }
      b = j;
      change = 1;
    }

    else if (dir[i] == 'L' && dir[i + 1] == 'U' && dir[i + 2] == 'S') {
      dir[i] = 'R';
      for (int j = i + 1; (j + 2) < n; j++) {
        dir[j] = dir[j + 2];
      }
      b = j;
      change = 1;
    }

    else if (dir[i] == 'S' && dir[i + 1] == 'U' && dir[i + 2] == 'R') {
      dir[i] = 'L';
      for (int j = i + 1; (j + 2) < n; j++) {
        dir[j] = dir[j + 2];
      }
      b = j;
      change = 1;
    }

    else if (dir[i] == 'R' && dir[i + 1] == 'U' && dir[i + 2] == 'S') {
      dir[i] = 'L';
      for (int j = i + 1; (j + 2) < n; j++) {
        dir[j] = dir[j + 2];
      }
      b = j;
      change = 1;
    }

    else if (dir[i] == 'R' && dir[i + 1] == 'U' && dir[i + 2] == 'L') {
      dir[i] = 'U';
      ldir = "right";
      for (int j = i + 1; (j + 2) < n; j++) {
        dir[j] = dir[j + 2];
      }
      b = j;
      change = 1;
    }

    else if (dir[i] == 'L' && dir[i + 1] == 'U' && dir[i + 2] == 'R') {
      dir[i] = 'U';
      ldir = "left";
      for (int j = i + 1; (j + 2) < n; j++) {
        dir[j] = dir[j + 2];
      }
      b = j;
      change = 1;
    }

    else if (dir[i] == 'L' && dir[i + 1] == 'S' && dir[i + 2] == 'U' && dir[i + 3] == 'S' && dir[i + 4] == 'L') {
      dir[i] = 'S';
      for (int j = i + 1; (j + 4) < n; j++) {
        dir[j] = dir[j + 4];
      }
      b = j;
      change = 1;
    }

    else if (dir[i] == 'R' && dir[i + 1] == 'S' && dir[i + 2] == 'U' && dir[i + 3] == 'S' && dir[i + 4] == 'R') {
      dir[i] = 'S';
      for (j = i + 1; (j + 4) < n; j++) {
        dir[j] = dir[j + 4];
      }
      b = j;
      change = 1;
    }


    if (change == 1) {
      i = (-1);
    }
  }
}
