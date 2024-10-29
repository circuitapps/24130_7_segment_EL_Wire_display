
/*
  7-segment display driver

  Operation: This application simply counts up from 0 to 9 periodically and runs in an infinite loop. This code has been tested on Arduino Nano and works as expected.

  If the 7 segment display you are driving is common anode, you can use this code without any change. If you are using a common cathode 7-segment display, simply comment out the following definition:

  #define COMMON_ANODE_DISPLAY

  Be sure to connect your Arduino Nano to the respective digital pins as per definitions provided. You can change the recommended pins as you wish, of course.

  Useful tips:
  1 - Be sure to connect a 1K resistor externally to each digit pin of your 7-segment display to maintain a fixed light intensity.
  2 - This driver software will also work with optocouplers (assuming the resistors mentioned above are connected to each optocoupler!)
  3 - You can also experiment with different values for the #define DIGIT_LATENCY_MS and #define OFF_DELAY_MS values to change the speed of counting.

  by circuitapps
  October 2024
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

#define COMMON_ANODE_DISPLAY  // Simply comment this line out if you are using common cathode 7-segment display!

#define SEG_A 2  // Segment A of 7-segment display connected to D2 digital pin on Arduino Nano
#define SEG_B 3  // Segment B of 7-segment display connected to D3 digital pin on Arduino Nano
#define SEG_C 4  // Segment C of 7-segment display connected to D4 digital pin on Arduino Nano
#define SEG_D 5  // Segment D of 7-segment display connected to D5 digital pin on Arduino Nano
#define SEG_E 6  // Segment E of 7-segment display connected to D6 digital pin on Arduino Nano
#define SEG_F 7  // Segment F of 7-segment display connected to D7 digital pin on Arduino Nano
#define SEG_G 8  // Segment G of 7-segment display connected to D8 digital pin on Arduino Nano

#ifdef COMMON_ANODE_DISPLAY
  #define ACTIVE LOW  // Active definition as per 7-segment display
  #define PASSIVE HIGH  // Passive definition as per 7-segment display
#else
  #define ACTIVE HIGH  // Active definition as per 7-segment display
  #define PASSIVE LOW  // Passive definition as per 7-segment display
#endif

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
    display_operations[i]();
    i = (i + 1) %10;
    delay(DIGIT_LATENCY_MS);
  }
}
