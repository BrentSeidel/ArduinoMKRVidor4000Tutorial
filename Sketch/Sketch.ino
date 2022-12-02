//
//  Based on the program available here: https://content.arduino.cc/assets/SketchVidorFPGA.zip
//  defines.h, jtag.c, and jtag.h are from that archive.  app.h is generated from the .ttf file
//  using the vidorcvt program.  I have modified sketch.ino for this demo.
// 
#include <wiring_private.h>
#include "jtag.h"
#include "defines.h"

//
//  Input pins
#define PIN_A 0
#define PIN_B 1
//
//  Output pins
#define PIN_NOT_A 2
#define PIN_NOT_B 3
#define PIN_AND 4
#define PIN_OR 5
#define PIN_XOR 6
//
//  Pin limits
#define MIN_PIN 2
#define MAX_PIN 22
//
//  Function to test a combination of inputs.
void test(bool a, bool b);

void setup()
{
  int x;

  setup_fpga();

  Serial.begin(9600);

  pinMode(PIN_A, OUTPUT);
  pinMode(PIN_B, OUTPUT);
  //
  //  Set the rest of the pins to input
  //
  for (x = MIN_PIN; x < MAX_PIN; x++)
  {
    pinMode(x, INPUT);
  }

  Serial.println("FPGA and MCU started!");
}

void loop()
{
  Serial.println("Testing logic gates.");
  test(false, false);
  test(false,  true);
  test( true, false);
  test( true,  true);
  Serial.println();
  delay(1000);
}

void test(bool b, bool a)
{
  digitalWrite(PIN_A, a);
  digitalWrite(PIN_B, b);
  delay(1);
  Serial.print(a);
  Serial.print(b);
  Serial.print("|");
  Serial.print(digitalRead(PIN_NOT_A));
  Serial.print(digitalRead(PIN_NOT_B));
  Serial.print(digitalRead(PIN_AND));
  Serial.print(digitalRead(PIN_OR));
  Serial.println(digitalRead(PIN_XOR));
}
