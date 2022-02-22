#include <FastLED.h>
#include <SoftwareSerial.h>

#define NUM_LEDS 119

CRGB leds[NUM_LEDS];
SoftwareSerial s(5, 6); // RX, TX

uint8_t paletteIndex = 0;
int whichPalette = 0;
uint8_t hue = 0;

long change_delay = 60000;
long pre = 0;

char value;
char pre_value = '0';

//  Basic

DEFINE_GRADIENT_PALETTE(Black_gp){
    0, 0, 0, 0,
    255, 0, 0, 0};

// Gaming

DECLARE_GRADIENT_PALETTE(Rainbow_gp);

DEFINE_GRADIENT_PALETTE(King_Yna_gp){
    0, 26, 42, 108,
    128, 178, 31, 31,
    255, 253, 187, 45};

DEFINE_GRADIENT_PALETTE(Celestial_gp){
    0, 195, 55, 100,
    255, 29, 38, 113};

DEFINE_GRADIENT_PALETTE(Influenza_gp){
    0, 192, 72, 72,
    255, 72, 0, 72};

//  Music

DEFINE_GRADIENT_PALETTE(Terminal_gp){
    0, 15, 155, 15,
    255, 0, 0, 0};

DEFINE_GRADIENT_PALETTE(Meridian_gp){
    0, 40, 60, 134,
    255, 69, 162, 71};

DEFINE_GRADIENT_PALETTE(Purpink_gp){
    0, 127, 0, 255,
    255, 255, 0, 255};

DEFINE_GRADIENT_PALETTE(Calm_Darya_gp){
    0, 95, 44, 130,
    255, 73, 160, 157};

//  Study

DEFINE_GRADIENT_PALETTE(Sunny_Days_gp){
    0, 237, 229, 116,
    255, 255, 245, 196};

DEFINE_GRADIENT_PALETTE(Margo_gp){
    0, 255, 239, 186,
    255, 255, 255, 255};

DEFINE_GRADIENT_PALETTE(Sky_gp){
    0, 7, 101, 133,
    255, 255, 255, 255};

DEFINE_GRADIENT_PALETTE(Windy_gp){
    0, 172, 182, 229,
    255, 134, 253, 232};

//  Alarm

DEFINE_GRADIENT_PALETTE(Witching_Hour_gp){
    0, 195, 20, 50,
    255, 36, 11, 54};

CRGBPalette16 currentPalette(Black_gp);
CRGBPalette16 targetPalette(Rainbow_gp);

CRGBPalette16 witching_hour(Witching_Hour_gp);

void off_lights()
{
  FastLED.setBrightness(0);

  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB(0, 0, 0);
  }

  FastLED.show();
}

void normal_lights()
{
  FastLED.setBrightness(255);

  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CHSV(hue, 255, 100);
  }

  EVERY_N_MILLISECONDS(250)
  {
    hue++;
  }

  if (hue > 255)
  {
    hue = 0;
  }

  FastLED.show();
}

void night_lights()
{
  FastLED.setBrightness(100);

  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB(255, 241, 84);
  }

  FastLED.show();
}

void gaming_lights()
{
  FastLED.setBrightness(255);

  fill_palette(leds, NUM_LEDS, paletteIndex, 255 / NUM_LEDS, currentPalette, 100, LINEARBLEND);

  EVERY_N_MILLISECONDS(20)
  {
    paletteIndex++;
  }

  nblendPaletteTowardPalette(currentPalette, targetPalette, 10);

  switch (whichPalette)
  {
  case 0:
    targetPalette = Rainbow_gp;
    break;
  case 1:
    targetPalette = King_Yna_gp;
    break;
  case 2:
    targetPalette = Celestial_gp;
    break;
  case 3:
    targetPalette = Influenza_gp;
  }

  EVERY_N_SECONDS(10)
  {
    whichPalette++;
    if (whichPalette > 4)
      whichPalette = 0;
  }

  FastLED.show();
}

void music_lights()
{
  FastLED.setBrightness(255);

  fill_palette(leds, NUM_LEDS, paletteIndex, 255 / NUM_LEDS, currentPalette, 100, LINEARBLEND);

  EVERY_N_MILLISECONDS(10)
  {
    paletteIndex++;
  }

  nblendPaletteTowardPalette(currentPalette, targetPalette, 10);

  switch (whichPalette)
  {
  case 0:
    targetPalette = Terminal_gp;
    break;
  case 1:
    targetPalette = Meridian_gp;
    break;
  case 2:
    targetPalette = Purpink_gp;
    break;
  case 3:
    targetPalette = Calm_Darya_gp;
  }

  EVERY_N_SECONDS(10)
  {
    whichPalette++;
    if (whichPalette > 4)
      whichPalette = 0;
  }

  FastLED.show();
}

void study_lights()
{
  FastLED.setBrightness(255);
  fill_palette(leds, NUM_LEDS, paletteIndex, 255 / NUM_LEDS, currentPalette, 100, LINEARBLEND);

  EVERY_N_MILLISECONDS(50)
  {
    paletteIndex++;
  }

  nblendPaletteTowardPalette(currentPalette, targetPalette, 10);

  switch (whichPalette)
  {
  case 0:
    targetPalette = Sunny_Days_gp;
    break;
  case 1:
    targetPalette = Margo_gp;
    break;
  case 2:
    targetPalette = Sky_gp;
    break;
  case 3:
    targetPalette = Windy_gp;
  }

  EVERY_N_SECONDS(10)
  {
    whichPalette++;
    if (whichPalette > 4)
      whichPalette = 0;
  }

  FastLED.show();
}

void alarm_lights()
{
  FastLED.setBrightness(255);
  fill_palette(leds, NUM_LEDS, paletteIndex, 255 / NUM_LEDS, witching_hour, 100, LINEARBLEND);

  EVERY_N_MILLISECONDS(5)
  {
    paletteIndex++;
  }

  FastLED.show();
}

void setup()
{
  FastLED.addLeds<WS2812, 10, GRB>(leds, NUM_LEDS);

  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB(255, 255, 255);
  }

  FastLED.show();

  delay(2000);

  Serial.begin(9600);
  s.begin(9600);
}

void loop()
{
  if (s.available())
  {
    char v = s.read();
    if (v != pre_value)
    {
      value = v;
      Serial.println(value);
    }
  }

  if (value == '1')
  {
    normal_lights();
  }

  else if (value == '2')
  {
    gaming_lights();
  }

  else if (value == '3')
  {
    music_lights();
  }

  else if (value == '4')
  {
    study_lights();
  }

  else if (value == '5')
  {
    FastLED.setBrightness(255);

    for (int i = 0; i < NUM_LEDS; i++)
    {
      leds[i] = CRGB(0, 255, 0);
    }

    FastLED.show();
  }

  else if (value == '6')
  {
    FastLED.setBrightness(255);

    for (int i = 0; i < NUM_LEDS; i++)
    {
      leds[i] = CRGB(255, 0, 0);
    }

    FastLED.show();
  }

  else if (value == '7')
  {
    alarm_lights();
  }

  else if (value == '8')
  {
    night_lights();
  }

  else if (value == '9')
  {
    off_lights();
  }
}
