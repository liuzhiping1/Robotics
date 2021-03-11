//********************************************************************
// VARIABLES VARIABLES VARIABLES VARIABLES VARIABLES VARIABLES VARIABL
//********************************************************************
const int RIGHT_MOTOR = 11;
const int LEFT_MOTOR = 10;
const int RIGHT_FORWARD = 2;
const int RIGHT_REVERSE = 3;
const int LEFT_FORWARD = 4;
const int LEFT_REVERSE = 5;
int right_speed = 0;
int left_speed = 0;
long sensors[] = {0, 0, 0, 0, 0};
long sensors_average = 0;
int sensors_sum = 0;
boolean sensors_flag = false;
int line_count = 0;
int position = 0;
int proportional = 0;
long integral = 0;
int derivative = 0;
int last_proportional = 0;
int control_value = 0;
int max_difference = 222;
float Kp = .111;
float Ki = 0;
float Kd = 1;

//********************************************************************
// SETUP FUNCTION SETUP FUNCTION SETUP FUNCTION SETUP FUNCTION SETUP F
//********************************************************************
void setup()
{
  // TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST TEST
  Serial.begin(9600);
  
  // Setup motor direction control pins
  pinMode(RIGHT_FORWARD, OUTPUT);
  pinMode(RIGHT_REVERSE, OUTPUT);
  pinMode(LEFT_FORWARD, OUTPUT);
  pinMode(LEFT_REVERSE, OUTPUT);
  
  // Initialize both motors to forward
  digitalWrite(RIGHT_FORWARD, HIGH);
  digitalWrite(RIGHT_REVERSE, LOW);
  digitalWrite(LEFT_FORWARD, HIGH);
  digitalWrite(LEFT_REVERSE, LOW);
}

//********************************************************************
// LOOP FUNCTION LOOP FUNCTION LOOP FUNCTION LOOP FUNCTION LOOP FUNCTI
//********************************************************************
void loop()
{
  read_sensors();
  get_average();
  get_sum();
  get_flags();
  process_flags();
  get_position();
  get_proportional();
  get_integral();
  get_derivative();
  get_control();
  process_control();
  set_motors(right_speed, left_speed);
}

//********************************************************************
// READ_SENSORS FUNCTION READ_SENSORS FUNCTION READ_SENSORS FUNCTION R
//********************************************************************
void read_sensors()
{
  // Take a reading from each of the five line sensors
  for (int i = 0; i < 5; i++)
  {
    sensors[i] = analogRead(i);
    
    // Round readings less than two hundred fifty down to zero to filter
    // out surface noise
    if (sensors[i] < 250)
    {
      sensors[i] = 0;
    }
  }
}

//********************************************************************
// GET_AVERAGE FUNCTION GET_AVERAGE FUNCTION GET_AVERAGE FUNCTION GET_
//********************************************************************
void get_average()
{
  // Zero the sensors_average variable
  sensors_average = 0;
  
  // Generate the weighted sensor average starting at sensor one to
  // keep from doing a needless multiplicaiton by zero which will
  // always discarded any value read by sensor zero
  for (int i = 1; i < 5; i ++)
  {
    sensors_average += sensors[i] * i * 1000;
  }
}

//********************************************************************
// GET_SUM FUNCTION GET_SUM FUNCTION GET_SUM FUNCTION GET_SUM FUNCTION
//********************************************************************
void get_sum()
{
  // Zero the sensors_sum variable
  sensors_sum = 0;
  
  // Sum the total of all the sensor readings
  for (int i = 0; i < 5; i++)
  {
    sensors_sum += int(sensors[i]);
  }
}

//********************************************************************
// GET_FLAGS FUNCTION GET_FLAGS FUNCTION GET_FLAGS FUNCTION GET_FLAGS 
//********************************************************************
void get_flags()
{
  // If a perpendicular line was read set the sensors_flag and
  // increment the line count
  if (sensors_sum > 4450)
  {
    sensors_flag = true;
    line_count++;
  }
}

//********************************************************************
// PROCESS_FLAGS PROCESS_FLAGS PROCESS_FLAGS PROCESS_FLAGS PROCESS_FLA
//********************************************************************
void process_flags()
{
  if (sensors_flag == true && line_count == 2)
  {
    // Make a right turn and acquire the center of the line
    right_turn();
  }
  else if (sensors_flag == true && line_count == 3)
  {
    // Add code here
  }
  else if (sensors_flag == true && line_count == 4)
  {
    // Add code here
  }
  
  // Clear sensors_flag
  sensors_flag = false;
}

//********************************************************************
// GET_POSITION FUNCTION GET_POSITION FUNCTION GET_POSITION FUNCTION G
//********************************************************************
void get_position()
{
  // Calculate the current position on the line
  position = int(sensors_average / sensors_sum);
}

//********************************************************************
// GET_PROPORTIONAL FUNCTION GET_PROPORTIONAL FUNCTION GET_PROPORTIONA
//********************************************************************
void get_proportional()
{
  // Caculate the proportional value
  proportional = position - 2000;
}

//********************************************************************
// GET_INTEGRAL FUNCTION GET_INTEGRAL FUNCTION GET_INTEGRAL FUNCTION G
//********************************************************************
void get_integral()
{
  // Calculate the integral value
  integral = integral + proportional;
}

//********************************************************************
// GET_DERIVATIVE FUNCTION GET_DERIVATIVE FUNCTION GET_DERIVATIVE FUNC
//********************************************************************
void get_derivative()
{
  // Calculate the derivative value
  derivative = proportional - last_proportional;
  
  // Store proportional value in last_proportional for the derivative
  // calculation on next loop
  last_proportional = proportional;
}

//********************************************************************
// GET_CONTROL FUNCTION GET_CONTROL FUNCTION GET_CONTROL FUNCTION GET_
//********************************************************************
void get_control()
{
  // Calculate the control value
  control_value = int(proportional * Kp +
                      integral * Ki +
                      derivative * Kd);
}

//********************************************************************
// PROCESS_CONTROL PROCESS_CONTROL PROCESS_CONTROL PROCESS_CONTROL PRO
//********************************************************************
void process_control()
{
  // If the control value is greater than the allowed maximum set it
  // to the maximum
  if (control_value > max_difference)
  {
    control_value = max_difference;
  }
  
  // If the control value is less than the allowed minimum set it to
  // the minimum
  if (control_value < -max_difference)
  {
    control_value = -max_difference;
  }
  
  // If control_value is less than zero calculate a right turn to
  // acquire the center of the line
  if (control_value < 0)
  {
    right_speed = max_difference + control_value;
    left_speed = max_difference;
  }
  // If control_value is greater than zero calculate a left turn to
  // acquire the center of the line
  else
  {
    right_speed = max_difference;
    left_speed = max_difference - control_value;
  }
}

//********************************************************************
// SET_MOTORS FUNCTION SET_MOTORS FUNCTION SET_MOTORS FUNCTION SET_MOT
//********************************************************************
void set_motors(int right_speed, int left_speed)
{
  // Adjust the motor speeds according to the calculated values
  analogWrite(RIGHT_MOTOR, right_speed);
  analogWrite(LEFT_MOTOR, left_speed);
}

//********************************************************************
// RIGHT_TURN FUNCTION RIGHT_TURN FUNCTION RIGHT_TURN FUNCTION RIGHT_T
//********************************************************************
void right_turn()
{
  // Cut power from left and right motors and coast until
  // perpendicular line is passed
  set_motors(0, 0);
  delay(250);
  
  // Take new sensor zero reading
  sensors[0] = analogRead(0);
  
  // Initialize the right motor for reverse travel
  digitalWrite(RIGHT_FORWARD, LOW);
  digitalWrite(RIGHT_REVERSE, HIGH);
  
  // Turn right until the edge of the line is acquired
  while (sensors[0] < 500)
  {
    set_motors(222, 222);
    sensors[0] = analogRead(0);
  }
  
  // Initialize the right motor back to forward travel
  digitalWrite(RIGHT_FORWARD, HIGH);
  digitalWrite(RIGHT_REVERSE, LOW);
}
