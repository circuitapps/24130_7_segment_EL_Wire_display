
/*
  H-bridge inverter controller
  (For reference, see circuit in https://drive.google.com/file/d/1E8HW0ulxhN9Z9mWrTRM3nkDeVtunls0v/view?usp=drive_link)
  Circuit based on reference: https://www.homemade-circuits.com/arduino-full-bridge-h-bridge-sinewave-inverter-circuit/ 

  Operation: 

  by circuitapps
  January 2024
*/

/* 7-SEGMENT DISPLAY NAMING CONVENTION
  
    ----A----
    |       |
    F       B
    |       |
    ----G----
    |       |
    E       C
    |       |
    ----D----

*/

#define SEG_A 2  // D2
#define SEG_B 3  // D3
#define SEG_C 4  // D4
#define SEG_D 5  // D5
#define SEG_E 6  // D6
#define SEG_F 7  // D7
#define SEG_G 8  // D8

#define ACTIVE LOW  // Active definition as per 7-segment display
#define PASSIVE HIGH  // Passive definition as per 7-segment display

#define DIGIT_LATENCY_MS 1000  // Period of changing number displayed (in milliseconds)
#define OFF_DELAY_MS 600  // Wait after turning all segments off

void turn_on(int pin_name)
{
  digitalWrite(pin_name, ACTIVE); // Turn pin_name ON
}

void turn_off(int pin_name)
{
  digitalWrite(pin_name, PASSIVE); // Turn pin_name OFF
}

void turn_all_off(void)
{
  turn_off(SEG_D);
  turn_off(SEG_G); 
  turn_off(SEG_A);
  turn_off(SEG_B);
  turn_off(SEG_C);
  turn_off(SEG_E);
  turn_off(SEG_F);

}

void display_ZERO(void)
{
    turn_all_off();
    delay(OFF_DELAY_MS);
    turn_on(SEG_A);
    turn_on(SEG_B);
    turn_on(SEG_C);
    turn_on(SEG_D);
    turn_on(SEG_E);
    turn_on(SEG_F);
}

void display_ONE(void)
{
    turn_all_off();
    delay(OFF_DELAY_MS);
    turn_on(SEG_B);
    turn_on(SEG_C);
}

void display_TWO(void)
{
    turn_all_off();
    delay(OFF_DELAY_MS);
    turn_on(SEG_A);
    turn_on(SEG_B);
    turn_on(SEG_D);
    turn_on(SEG_E);
    turn_on(SEG_G);
}

void display_THREE(void)
{
    turn_all_off();
    delay(OFF_DELAY_MS);
    turn_on(SEG_A);
    turn_on(SEG_B);
    turn_on(SEG_C);
    turn_on(SEG_D);
    turn_on(SEG_G);
}

void display_FOUR(void)
{
    turn_all_off();
    delay(OFF_DELAY_MS);
    turn_on(SEG_B);
    turn_on(SEG_C);
    turn_on(SEG_G);
    turn_on(SEG_F);
}

void display_FIVE(void)
{
    turn_all_off();
    delay(OFF_DELAY_MS);
    turn_on(SEG_A);
    turn_on(SEG_C);
    turn_on(SEG_D);
    turn_on(SEG_G);
    turn_on(SEG_F);
}

void display_SIX(void)
{
    turn_all_off();
    delay(OFF_DELAY_MS);
    turn_on(SEG_A);
    turn_on(SEG_G);
    turn_on(SEG_C);
    turn_on(SEG_D);
    turn_on(SEG_E);
    turn_on(SEG_F);
}

void display_SEVEN(void)
{
    turn_all_off();
    delay(OFF_DELAY_MS);
    turn_on(SEG_A);
    turn_on(SEG_B);
    turn_on(SEG_C);
}

void display_EIGHT(void)
{
    turn_all_off();
    delay(OFF_DELAY_MS);
    turn_on(SEG_A);
    turn_on(SEG_B);
    turn_on(SEG_C);
    turn_on(SEG_D);
    turn_on(SEG_E);
    turn_on(SEG_F);
    turn_on(SEG_G);
}

void display_NINE(void)
{
    turn_all_off();
    delay(OFF_DELAY_MS);
    turn_on(SEG_A);
    turn_on(SEG_B);
    turn_on(SEG_C);
    turn_on(SEG_D);
    turn_on(SEG_F);
    turn_on(SEG_G);
}

void (*display_operations[10])(void);  // Function pointers for fast display refresh

// the setup function runs once when you press reset or power the board
void setup()
{
  pinMode(SEG_A, OUTPUT);
  pinMode(SEG_B, OUTPUT);
  pinMode(SEG_C, OUTPUT);
  pinMode(SEG_D, OUTPUT);
  pinMode(SEG_E, OUTPUT);
  pinMode(SEG_F, OUTPUT);
  pinMode(SEG_G, OUTPUT);

  turn_all_off();  // all segments turned off at power up

  display_operations[0] = display_ZERO;
  display_operations[1] = display_ONE;
  display_operations[2] = display_TWO;
  display_operations[3] = display_THREE;
  display_operations[4] = display_FOUR;
  display_operations[5] = display_FIVE;
  display_operations[6] = display_SIX;
  display_operations[7] = display_SEVEN;
  display_operations[8] = display_EIGHT;
  display_operations[9] = display_NINE;
  }

// the loop function runs over and over again forever
void loop()
{
  int i=0;

  while(1)
  {
    /*
    turn_on(SEG_D);
    delay(1000);
    turn_off(SEG_D);
    delay(4000);
    */

    display_operations[i]();
    i = (i + 1) %10;
    delay(DIGIT_LATENCY_MS);
  }
}
