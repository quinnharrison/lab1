int r_led = 6;  //tells what pin number r_led is
int g_led = 5;  //for examples look on arduino website
int b_led = 3;
int potent = 0; //reads in input from A0, where potentiometer is 
                //hooked up
                
//#define LED_R 3  -- #define does a search replace (LED_R to 3)

// the setup routine runs once you press reset:
void setup(){
  //initialize the digial pin as an output
  pinMode(r_led, OUTPUT);
  pinMode(b_led, OUTPUT);
  pinMode(g_led, OUTPUT);
}


const uint8_t gamma8[] = {
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,
    2,  3,  3,  3,  3,  3,  3,  3,  4,  4,  4,  4,  4,  5,  5,  5,
    5,  6,  6,  6,  6,  7,  7,  7,  7,  8,  8,  8,  9,  9,  9, 10,
   10, 10, 11, 11, 11, 12, 12, 13, 13, 13, 14, 14, 15, 15, 16, 16,
   17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 24, 24, 25,
   25, 26, 27, 27, 28, 29, 29, 30, 31, 32, 32, 33, 34, 35, 35, 36,
   37, 38, 39, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 50,
   51, 52, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 66, 67, 68,
   69, 70, 72, 73, 74, 75, 77, 78, 79, 81, 82, 83, 85, 86, 87, 89,
   90, 92, 93, 95, 96, 98, 99,101,102,104,105,107,109,110,112,114,
  115,117,119,120,122,124,126,127,129,131,133,135,137,138,140,142,
  144,146,148,150,152,154,156,158,160,162,164,167,169,171,173,175,
  177,180,182,184,186,189,191,193,196,198,200,203,205,208,210,213,
  215,218,220,223,225,228,231,233,236,239,241,244,247,249,252,255 };
  //gamma correction table
// loop that runs over and over again
void loop(){
  int val_r;
  int val_g;
  int val_b;
  
  //read in analog inputs from LEDs from board. Input arguments are 
  //ports on board
  val_r = analogRead(A0);
  val_g = analogRead(A5);  //double check values on ports!!!
  val_b = analogRead(A6);
  
  printf("LED Values: red - %f, green - %f, blue - %f\n,",val_r,val_g,val_b);
  
  //write the compensated color values to an LED 
  analogWrite(r_led, gamma8[val_r/4]);
  analogWrite(g_led, gamma8[val_g/4]);
  analogWrite(b_led, gamma8[val_b/4]);
  
  /*analogWrite(r_led, 255); //sends full pwm signal to led on board
  delay(1000);         //wait 1000 ms
  analogWrite(b_led, 120); //sends dimmed pwm signal 
  delay(1000);
  analogWrite(g_led, 120); //sends dimmed pwm signal 
  delay(1000);*/
}
  
  
