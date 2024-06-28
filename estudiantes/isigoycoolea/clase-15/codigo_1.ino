#include <ArduCAM.h>
#include <SPI.h>
#include "memorysaver.h"

// Pin definitions for the camera module
#define CS_PIN 10
#define XCLK_PIN A0
#define SIOD_PIN A4
#define SIOC_PIN A5
#define VSYNC_PIN 2
#define HREF_PIN 3
#define PCLK_PIN 4

// Create an ArduCAM object
ArduCAM myCAM(OV7670, CS_PIN);

void setup() {
  Serial.begin(115200);
  Wire.begin();
  SPI.begin();
  
  // Set pin modes
  pinMode(CS_PIN, OUTPUT);
  pinMode(XCLK_PIN, OUTPUT);
  pinMode(SIOD_PIN, OUTPUT);
  pinMode(SIOC_PIN, OUTPUT);
  pinMode(VSYNC_PIN, INPUT);
  pinMode(HREF_PIN, INPUT);
  pinMode(PCLK_PIN, INPUT);

  // Initialize the camera module
  myCAM.InitCAM();
  myCAM.clear_fifo_flag();

  // Configure the camera settings
  myCAM.write_reg(0x12, 0x80); // Reset the camera
  delay(100);
  myCAM.write_reg(0x11, 0x01); // Set clock prescaler
  myCAM.write_reg(0x6b, 0x0A); // PLL
  myCAM.write_reg(0x0C, 0x00); // Disable color bar

  // Set the resolution to 640x480
  myCAM.write_reg(0x3A, 0x04); // Set bit[3:0] to '0100' to select VGA
  myCAM.write_reg(0x12, 0x14); // set the bit[6:4] to '0010' to select VGA
  myCAM.set_format(JPEG);
  myCAM.InitCAM();
}

void loop() {
  // Capture an image
  myCAM.clear_fifo_flag();
  myCAM.start_capture();
  while (!myCAM.get_bit(ARDUCHIP_TRIG, CAP_DONE_MASK));

  // Read image data from the camera
  myCAM.CS_LOW();
  myCAM.set_fifo_burst();
  
  uint8_t temp = 0;
  int i = 0;
  while ( (temp != 0xD9) | (temp != 0xFF)) {
    temp = SPI.transfer(0x00);
    Serial.write(temp);
  }
  myCAM.CS_HIGH();

  // Wait before capturing the next frame
  delay(1000);
}    
