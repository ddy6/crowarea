// A basic everyday NeoPixel strip test program.

// NEOPIXEL BEST PRACTICES for most reliable operation:
// - Add 1000 uF CAPACITOR between NeoPixel strip's + and - connections.
// - MINIMIZE WIRING LENGTH between microcontroller board and first pixel.
// - NeoPixel strip's DATA-IN should pass through a 300-500 OHM RESISTOR.
// - AVOID connecting NeoPixels on a LIVE CIRCUIT. If you must, ALWAYS
//   connect GROUND (-) first, then +, then data.
// - When using a 3.3V microcontroller with a 5V-powered NeoPixel strip,
//   a LOGIC-LEVEL CONVERTER on the data line is STRONGLY RECOMMENDED.
// (Skipping these may work OK on your workbench but can fail in the field)

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1:
#define plumeria    2
#define mocklime    3
#define trumpet     4
#define hibiscus    5
#define bluebutt    6

// How many NeoPixels are attached to the Arduino?
#define plumCount   300
#define mockCount   144
#define trumCount   144
#define hibiCount   300
#define blueCount   150




// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip1(plumeria, plumCount, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2(mocklime, mockCount, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip3(trumpet, trumCount, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip4(hibiscus, hibiCount, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip5(bluebutt, blueCount, NEO_GRB + NEO_KHZ800);
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)

int plumDry = 625;
int plumWet = 350;
int mockDry = 625;
int mockWet = 350;
int trumDry = 625;
int trumWet = 350;
int hibiDry = 625;
int hibiWet = 350;
int blueDry = 625;
int blueWet = 350;

int plumPercentageMoisture = 0;
int mockPercentageMoisture = 0;
int trumPercentageMoisture = 0;
int hibiPercentageMoisture = 0;
int bluePercentageMoisture = 0;

// setup() function -- runs once at startup --------------------------------

void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.
  
  Serial.begin(9600);
  //randomSeed(analogRead(0));
  strip1.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip1.show();            // Turn OFF all pixels ASAP
  strip1.setBrightness(100); // Set BRIGHTNESS to about 1/5 (max = 255)
  strip2.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip2.show();            // Turn OFF all pixels ASAP
  strip2.setBrightness(100); // Set BRIGHTNESS to about 1/5 (max = 255)
  strip3.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip3.show();            // Turn OFF all pixels ASAP
  strip3.setBrightness(100); // Set BRIGHTNESS to about 1/5 (max = 255)
  strip4.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip4.show();            // Turn OFF all pixels ASAP
  strip4.setBrightness(100); // Set BRIGHTNESS to about 1/5 (max = 255)
  strip5.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip5.show();            // Turn OFF all pixels ASAP
  strip5.setBrightness(100); // Set BRIGHTNESS to about 1/5 (max = 255)
}


// loop() function -- runs repeatedly as long as board is on ---------------

void loop() {
  // Fill along the length of the strip in various colors...

    int plumSensor = analogRead(A1);
    int mockSensor = analogRead(A2);
    int trumSensor = analogRead(A3);
    int hibiSensor = analogRead(A4);
    int blueSensor = analogRead(A5);

  
    plumPercentageMoisture = map(plumSensor, plumWet, plumDry, 100, 0);
    mockPercentageMoisture = map(mockSensor, mockWet, mockDry, 100, 0);
    trumPercentageMoisture = map(trumSensor, trumWet, trumDry, 100, 0);
    hibiPercentageMoisture = map(hibiSensor, hibiWet, hibiDry, 100, 0);
    bluePercentageMoisture = map(blueSensor, blueWet, blueDry, 100, 0);

    Serial.print(plumSensor);
    Serial.print(" | ");
    Serial.print(mockSensor);
    Serial.print(" | ");
    Serial.print(trumSensor);
    Serial.print(" | ");
    Serial.print(hibiSensor);
    Serial.print(" | ");
    Serial.println(blueSensor);
    delay(1000);

}
