#pragma once

#include <U8g2lib.h>

static const unsigned char wrclogo[] U8X8_PROGMEM = {
    	// 'WRCLOGO, 64x18px
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0xFF, 0xFF, 0xF0, 0xFF, 0x1F, 
  0x18, 0x60, 0x80, 0xFF, 0xFF, 0xF9, 0xFF, 0x1F, 0x18, 0xF8, 0x81, 0x03, 
  0x80, 0x19, 0x00, 0x00, 0x18, 0xF8, 0x83, 0x01, 0x80, 0x1D, 0x00, 0x00, 
  0x18, 0x9C, 0x83, 0xE1, 0xFF, 0x1D, 0x00, 0x00, 0x18, 0x9C, 0x83, 0xF9, 
  0xFF, 0x1C, 0x00, 0x00, 0x18, 0x9C, 0x83, 0xF9, 0x3F, 0x1C, 0x00, 0x00, 
  0x18, 0x9C, 0x83, 0x19, 0x00, 0x1C, 0x00, 0x00, 0x38, 0x1E, 0xC7, 0x39, 
  0x00, 0x38, 0x00, 0x00, 0xF8, 0x0F, 0xFF, 0xF9, 0xFF, 0xF9, 0xFF, 0x1F, 
  0xE0, 0x07, 0xFE, 0xF0, 0xFF, 0xF1, 0xFF, 0x1F, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

static const unsigned char btnA18[] U8X8_PROGMEM = {
   0xc0, 0x0f, 0x00, 0x70, 0x38, 0x00, 0x18, 0x60, 0x00, 0x0c, 0xc3, 0x00,
   0x06, 0x83, 0x01, 0x82, 0x07, 0x01, 0x83, 0x07, 0x03, 0x81, 0x0c, 0x02,
   0xc1, 0x0c, 0x02, 0xc1, 0x0c, 0x02, 0xe1, 0x1f, 0x02, 0x63, 0x18, 0x03,
   0x62, 0x18, 0x01, 0x36, 0xb0, 0x01, 0x0c, 0xc0, 0x00, 0x18, 0x60, 0x00,
   0x70, 0x38, 0x00, 0xc0, 0x0f, 0x00 
};
static const unsigned char btnB18[] U8X8_PROGMEM = {
   0xc0, 0x0f, 0x00, 0x70, 0x38, 0x00, 0x18, 0x60, 0x00, 0x0c, 0xc0, 0x00,
   0xc6, 0x8f, 0x01, 0xc2, 0x1f, 0x01, 0xc3, 0x18, 0x03, 0xc1, 0x18, 0x02,
   0xc1, 0x0f, 0x02, 0xc1, 0x0f, 0x02, 0xc1, 0x18, 0x02, 0xc3, 0x18, 0x03,
   0xc2, 0x18, 0x01, 0xc6, 0x9f, 0x01, 0x0c, 0xc0, 0x00, 0x18, 0x60, 0x00,
   0x70, 0x38, 0x00, 0xc0, 0x0f, 0x00 };

static const unsigned char btnX18[] U8X8_PROGMEM = {
   0xc0, 0x0f, 0x00, 0x70, 0x38, 0x00, 0x18, 0x60, 0x00, 0x0c, 0xc0, 0x00,
   0x66, 0x98, 0x01, 0x62, 0x18, 0x01, 0xc3, 0x0c, 0x03, 0x81, 0x07, 0x02,
   0x81, 0x07, 0x02, 0x01, 0x03, 0x02, 0x81, 0x07, 0x02, 0xc3, 0x0f, 0x03,
   0xc2, 0x0c, 0x01, 0x66, 0x98, 0x01, 0x6c, 0xd8, 0x00, 0x18, 0x60, 0x00,
   0x70, 0x38, 0x00, 0xc0, 0x0f, 0x00
};

static const unsigned char btnY18[] U8X8_PROGMEM = {
   0xc0, 0x0f, 0x00, 0x70, 0x38, 0x00, 0x18, 0x60, 0x00, 0x0c, 0xc0, 0x00,
   0x66, 0x90, 0x01, 0x62, 0x18, 0x01, 0xe3, 0x1c, 0x03, 0xc1, 0x0c, 0x02,
   0x81, 0x07, 0x02, 0x81, 0x07, 0x02, 0x01, 0x03, 0x02, 0x03, 0x03, 0x03,
   0x02, 0x03, 0x01, 0x06, 0x83, 0x01, 0x0c, 0xc3, 0x00, 0x18, 0x60, 0x00,
   0x70, 0x38, 0x00, 0xc0, 0x0f, 0x00 };


static const unsigned char btnDown18[] U8X8_PROGMEM = {
   0xc0, 0x0f, 0x00, 0x40, 0x08, 0x00, 0x20, 0x10, 0x00, 0x20, 0x10, 0x00,
   0x20, 0x10, 0x00, 0x3c, 0xf0, 0x00, 0x03, 0x00, 0x03, 0x01, 0x00, 0x02,
   0x01, 0x00, 0x02, 0x01, 0x00, 0x02, 0x01, 0x00, 0x02, 0x03, 0x00, 0x03,
   0xfc, 0xff, 0x00, 0xe0, 0x1f, 0x00, 0xe0, 0x1f, 0x00, 0xe0, 0x1f, 0x00,
   0xc0, 0x0f, 0x00, 0xc0, 0x0f, 0x00 };

static const unsigned char btnLeft18[] U8X8_PROGMEM = {
   0xc0, 0x0f, 0x00, 0x40, 0x08, 0x00, 0x20, 0x10, 0x00, 0x20, 0x10, 0x00,
   0x20, 0x10, 0x00, 0x3c, 0xf0, 0x00, 0x3f, 0x00, 0x03, 0x3f, 0x00, 0x02,
   0x3f, 0x00, 0x02, 0x3f, 0x00, 0x02, 0x3f, 0x00, 0x02, 0x3f, 0x00, 0x03,
   0x3c, 0xf0, 0x00, 0x20, 0x10, 0x00, 0x20, 0x10, 0x00, 0x20, 0x10, 0x00,
   0x40, 0x08, 0x00, 0xc0, 0x0f, 0x00 };

static const unsigned char btnRight18[] U8X8_PROGMEM = {
   0xc0, 0x0f, 0x00, 0x40, 0x08, 0x00, 0x20, 0x10, 0x00, 0x20, 0x10, 0x00,
   0x20, 0x10, 0x00, 0x3c, 0xf0, 0x00, 0x03, 0xf0, 0x03, 0x01, 0xf0, 0x03,
   0x01, 0xf0, 0x03, 0x01, 0xf0, 0x03, 0x01, 0xf0, 0x03, 0x03, 0xf0, 0x03,
   0x3c, 0xf0, 0x00, 0x20, 0x10, 0x00, 0x20, 0x10, 0x00, 0x20, 0x10, 0x00,
   0x40, 0x08, 0x00, 0xc0, 0x0f, 0x00 };

static const unsigned char btnUp18[] U8X8_PROGMEM = {
   0xc0, 0x0f, 0x00, 0xc0, 0x0f, 0x00, 0xe0, 0x1f, 0x00, 0xe0, 0x1f, 0x00,
   0xe0, 0x1f, 0x00, 0xfc, 0xff, 0x00, 0x03, 0x00, 0x03, 0x01, 0x00, 0x02,
   0x01, 0x00, 0x02, 0x01, 0x00, 0x02, 0x01, 0x00, 0x02, 0x03, 0x00, 0x03,
   0x3c, 0xf0, 0x00, 0x20, 0x10, 0x00, 0x20, 0x10, 0x00, 0x20, 0x10, 0x00,
   0x40, 0x08, 0x00, 0xc0, 0x0f, 0x00 };

static const unsigned char btnView18[] U8X8_PROGMEM = {
   0xc0, 0x0f, 0x00, 0x70, 0x38, 0x00, 0x18, 0x60, 0x00, 0x0c, 0xc0, 0x00,
   0xe6, 0x83, 0x01, 0xf2, 0x07, 0x01, 0x13, 0x04, 0x03, 0x11, 0x00, 0x02,
   0x11, 0x3f, 0x02, 0x71, 0x21, 0x02, 0x01, 0x21, 0x02, 0x03, 0x21, 0x03,
   0x02, 0x3f, 0x01, 0x06, 0x9f, 0x01, 0x0c, 0xc0, 0x00, 0x18, 0x60, 0x00,
   0x70, 0x38, 0x00, 0xc0, 0x0f, 0x00 };

static const unsigned char btnMenu18[] U8X8_PROGMEM = {
   0xc0, 0x0f, 0x00, 0x70, 0x38, 0x00, 0x18, 0x60, 0x00, 0x0c, 0xc0, 0x00,
   0x06, 0x80, 0x01, 0x02, 0x00, 0x01, 0xe3, 0x1f, 0x03, 0x01, 0x00, 0x02,
   0xe1, 0x1f, 0x02, 0x01, 0x00, 0x02, 0x01, 0x00, 0x02, 0xe3, 0x1f, 0x03,
   0x02, 0x00, 0x01, 0x06, 0x80, 0x01, 0x0c, 0xc0, 0x00, 0x18, 0x60, 0x00,
   0x70, 0x38, 0x00, 0xc0, 0x0f, 0x00 };

static const unsigned char btnLS_24_18[] U8X8_PROGMEM = {
   0x00, 0xff, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x18, 0x00,
   0xfc, 0xff, 0x3f, 0x02, 0x00, 0xc0, 0x01, 0x00, 0x80, 0x01, 0x00, 0x80,
   0x03, 0x04, 0x80, 0xfe, 0x04, 0x7e, 0xc0, 0x04, 0x03, 0x80, 0x04, 0x03,
   0x80, 0x04, 0x03, 0x80, 0x3c, 0x03, 0x80, 0x00, 0x03, 0x80, 0x00, 0x03,
   0x80, 0x00, 0x01, 0x80, 0xff, 0x01 };

static const unsigned char btnRS_24_18[] U8X8_PROGMEM = {
   0x00, 0xff, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x18, 0x00,
   0xfc, 0xff, 0x3f, 0x02, 0x00, 0xc0, 0x01, 0x00, 0x80, 0x01, 0x00, 0x80,
   0x03, 0x3c, 0x80, 0xfe, 0x6c, 0x7e, 0xc0, 0x64, 0x03, 0x80, 0x3c, 0x03,
   0x80, 0x34, 0x03, 0x80, 0x64, 0x03, 0x80, 0x00, 0x03, 0x80, 0x00, 0x03,
   0x80, 0x00, 0x01, 0x80, 0xff, 0x01 };

static const unsigned char btnLB_30_18[] U8X8_PROGMEM = {
   0x00, 0x80, 0x7f, 0x00, 0x00, 0xfe, 0xff, 0x01, 0xc0, 0x1f, 0x80, 0x03,
   0xf0, 0x01, 0x00, 0x07, 0x3c, 0x00, 0x00, 0x0e, 0x0e, 0x00, 0x00, 0x1c,
   0x06, 0x8c, 0x0f, 0x18, 0x06, 0x8c, 0x19, 0x30, 0x06, 0x8c, 0x0f, 0x30,
   0x06, 0x8c, 0x1f, 0x30, 0x06, 0x8c, 0x19, 0x10, 0x02, 0xfc, 0x1f, 0x18,
   0x03, 0x00, 0x00, 0x18, 0x03, 0x00, 0x00, 0x18, 0x03, 0x00, 0x00, 0x0c,
   0x03, 0x00, 0x00, 0x0c, 0xfe, 0xff, 0xff, 0x07, 0xfc, 0xff, 0xff, 0x03 };

static const unsigned char btnRB_30_18[] U8X8_PROGMEM = {
   0x80, 0x7f, 0x00, 0x00, 0xe0, 0xff, 0x1f, 0x00, 0x70, 0x00, 0xfe, 0x00,
   0x38, 0x00, 0xe0, 0x03, 0x1c, 0x00, 0x00, 0x0f, 0x0e, 0x00, 0x00, 0x1c,
   0x06, 0x7c, 0x1f, 0x18, 0x03, 0x6c, 0x13, 0x18, 0x03, 0x6c, 0x1f, 0x18,
   0x03, 0x7c, 0x1f, 0x18, 0x02, 0x3c, 0x33, 0x18, 0x06, 0x6c, 0x3f, 0x10,
   0x06, 0x00, 0x00, 0x30, 0x06, 0x00, 0x00, 0x30, 0x0c, 0x00, 0x00, 0x30,
   0x0c, 0x00, 0x00, 0x30, 0xf8, 0xff, 0xff, 0x1f, 0xf0, 0xff, 0xff, 0x0f };

static const unsigned char btnLT_17_18[] U8X8_PROGMEM = {
   0xfe, 0x7f, 0x00, 0x02, 0xc0, 0x00, 0x03, 0xc0, 0x00, 0x01, 0x40, 0x00,
   0x01, 0x40, 0x00, 0x01, 0x40, 0x00, 0x21, 0x47, 0x00, 0x21, 0x42, 0x00,
   0x21, 0x42, 0x00, 0x21, 0x42, 0x00, 0xe3, 0x42, 0x00, 0x02, 0x40, 0x00,
   0x06, 0x40, 0x00, 0x04, 0xc0, 0x00, 0x0c, 0x80, 0x00, 0x38, 0x80, 0x01,
   0xe0, 0x80, 0x01, 0x80, 0xff, 0x00 };

static const unsigned char btnRT_17_18[] U8X8_PROGMEM = {
   0xfc, 0xff, 0x00, 0x06, 0x80, 0x00, 0x06, 0x80, 0x01, 0x04, 0x00, 0x01,
   0x04, 0x00, 0x01, 0x04, 0x00, 0x01, 0xe4, 0x1f, 0x01, 0x24, 0x09, 0x01,
   0xe4, 0x09, 0x01, 0xa4, 0x09, 0x01, 0x24, 0x89, 0x01, 0x04, 0x80, 0x00,
   0x04, 0xc0, 0x00, 0x06, 0x40, 0x00, 0x02, 0x60, 0x00, 0x03, 0x38, 0x00,
   0x03, 0x0e, 0x00, 0xfe, 0x03, 0x00 };

