#ifndef BusWrapper_h
#define BusWrapper_h

#include "NeoPixelBusLg.h"
#include "bus_manager.h"

// temporary - these defines should actually be set in platformio.ini
// C3: I2S0 and I2S1 methods not supported (has one I2S bus)
// S2: I2S1 methods not supported (has one I2S bus)
// S3: I2S0 and I2S1 methods not supported yet (has two I2S buses)
// https://github.com/Makuna/NeoPixelBus/blob/b32f719e95ef3c35c46da5c99538017ef925c026/src/internal/Esp32_i2s.h#L4
// https://github.com/Makuna/NeoPixelBus/blob/b32f719e95ef3c35c46da5c99538017ef925c026/src/internal/NeoEsp32RmtMethod.h#L857

#if !defined(WLED_NO_I2S0_PIXELBUS) && (defined(CONFIG_IDF_TARGET_ESP32S3) || defined(CONFIG_IDF_TARGET_ESP32C3))
#define WLED_NO_I2S0_PIXELBUS
#endif
#if !defined(WLED_NO_I2S1_PIXELBUS) && (defined(CONFIG_IDF_TARGET_ESP32S3) || defined(CONFIG_IDF_TARGET_ESP32C3) || defined(CONFIG_IDF_TARGET_ESP32S2))
#define WLED_NO_I2S1_PIXELBUS
#endif
// temporary end

//Hardware SPI Pins
#define P_8266_HS_MOSI 13
#define P_8266_HS_CLK  14
#define P_32_HS_MOSI   13
#define P_32_HS_CLK    14
#define P_32_VS_MOSI   23
#define P_32_VS_CLK    18

//The dirty list of possible bus types. Quite a lot...
#define I_NONE 0
//ESP8266 RGB
#define I_8266_U0_NEO_3 1
#define I_8266_U1_NEO_3 2
#define I_8266_DM_NEO_3 3
#define I_8266_BB_NEO_3 4
//RGBW
#define I_8266_U0_NEO_4 5
#define I_8266_U1_NEO_4 6
#define I_8266_DM_NEO_4 7
#define I_8266_BB_NEO_4 8
//400Kbps
#define I_8266_U0_400_3 9
#define I_8266_U1_400_3 10
#define I_8266_DM_400_3 11
#define I_8266_BB_400_3 12
//TM1814 (RGBW)
#define I_8266_U0_TM1_4 13
#define I_8266_U1_TM1_4 14
#define I_8266_DM_TM1_4 15
#define I_8266_BB_TM1_4 16
//TM1829 (RGB)
#define I_8266_U0_TM2_3 17
#define I_8266_U1_TM2_3 18
#define I_8266_DM_TM2_3 19
#define I_8266_BB_TM2_3 20
//UCS8903 (RGB)
#define I_8266_U0_UCS_3 49
#define I_8266_U1_UCS_3 50
#define I_8266_DM_UCS_3 51
#define I_8266_BB_UCS_3 52
//UCS8904 (RGBW)
#define I_8266_U0_UCS_4 53
#define I_8266_U1_UCS_4 54
#define I_8266_DM_UCS_4 55
#define I_8266_BB_UCS_4 56
//FW1906 GRBCW
#define I_8266_U0_FW6_5 66
#define I_8266_U1_FW6_5 67
#define I_8266_DM_FW6_5 68
#define I_8266_BB_FW6_5 69
//ESP8266 APA106
#define I_8266_U0_APA106_3 81
#define I_8266_U1_APA106_3 82
#define I_8266_DM_APA106_3 83
#define I_8266_BB_APA106_3 84
//WS2805 (RGBCW)
#define I_8266_U0_2805_5 89
#define I_8266_U1_2805_5 90
#define I_8266_DM_2805_5 91
#define I_8266_BB_2805_5 92
//TM1914 (RGB)
#define I_8266_U0_TM1914_3 99
#define I_8266_U1_TM1914_3 100
#define I_8266_DM_TM1914_3 101
#define I_8266_BB_TM1914_3 102
//SM16825 (RGBCW)
#define I_8266_U0_SM16825_5 103
#define I_8266_U1_SM16825_5 104
#define I_8266_DM_SM16825_5 105
#define I_8266_BB_SM16825_5 106

/*** ESP32 Neopixel methods ***/
//RGB
#define I_32_RN_NEO_3 21
#define I_32_I0_NEO_3 22
#define I_32_I1_NEO_3 23
//RGBW
#define I_32_RN_NEO_4 25
#define I_32_I0_NEO_4 26
#define I_32_I1_NEO_4 27
//400Kbps
#define I_32_RN_400_3 29
#define I_32_I0_400_3 30
#define I_32_I1_400_3 31
//TM1814 (RGBW)
#define I_32_RN_TM1_4 33
#define I_32_I0_TM1_4 34
#define I_32_I1_TM1_4 35
//TM1829 (RGB)
#define I_32_RN_TM2_3 36
#define I_32_I0_TM2_3 37
#define I_32_I1_TM2_3 38
//UCS8903 (RGB)
#define I_32_RN_UCS_3 57
#define I_32_I0_UCS_3 58
#define I_32_I1_UCS_3 59
//UCS8904 (RGBW)
#define I_32_RN_UCS_4 60
#define I_32_I0_UCS_4 61
#define I_32_I1_UCS_4 62
//FW1906 GRBCW
#define I_32_RN_FW6_5 63
#define I_32_I0_FW6_5 64
#define I_32_I1_FW6_5 65
//APA106
#define I_32_RN_APA106_3 85
#define I_32_I0_APA106_3 86
#define I_32_I1_APA106_3 87
//WS2805 (RGBCW)
#define I_32_RN_2805_5 93
#define I_32_I0_2805_5 94
#define I_32_I1_2805_5 95
//TM1914 (RGB)
#define I_32_RN_TM1914_3 96
#define I_32_I0_TM1914_3 97
#define I_32_I1_TM1914_3 98
//SM16825 (RGBCW)
#define I_32_RN_SM16825_5 107
#define I_32_I0_SM16825_5 108
#define I_32_I1_SM16825_5 109

//APA102
#define I_HS_DOT_3 39 //hardware SPI
#define I_SS_DOT_3 40 //soft SPI

//LPD8806
#define I_HS_LPD_3 41
#define I_SS_LPD_3 42

//WS2801
#define I_HS_WS1_3 43
#define I_SS_WS1_3 44

//P9813
#define I_HS_P98_3 45
#define I_SS_P98_3 46

//LPD6803
#define I_HS_LPO_3 47
#define I_SS_LPO_3 48


// In the following NeoGammaNullMethod can be replaced with NeoGammaWLEDMethod to perform Gamma correction implicitly
// unfortunately that may apply Gamma correction to pre-calculated palettes which is undesired

/*** ESP8266 Neopixel methods ***/
#ifdef ESP8266
//RGB
#define B_8266_U0_NEO_3 NeoPixelBusLg<NeoGrbFeature, NeoEsp8266Uart0Ws2813Method, NeoGammaNullMethod> //3 chan, esp8266, gpio1
#define B_8266_U1_NEO_3 NeoPixelBusLg<NeoGrbFeature, NeoEsp8266Uart1Ws2813Method, NeoGammaNullMethod> //3 chan, esp8266, gpio2
#define B_8266_DM_NEO_3 NeoPixelBusLg<NeoGrbFeature, NeoEsp8266Dma800KbpsMethod, NeoGammaNullMethod>  //3 chan, esp8266, gpio3
#define B_8266_BB_NEO_3 NeoPixelBusLg<NeoGrbFeature, NeoEsp8266BitBang800KbpsMethod, NeoGammaNullMethod> //3 chan, esp8266, bb (any pin but 16)
//RGBW
#define B_8266_U0_NEO_4 NeoPixelBusLg<NeoGrbwFeature, NeoEsp8266Uart0Ws2813Method, NeoGammaNullMethod>   //4 chan, esp8266, gpio1
#define B_8266_U1_NEO_4 NeoPixelBusLg<NeoGrbwFeature, NeoEsp8266Uart1Ws2813Method, NeoGammaNullMethod>   //4 chan, esp8266, gpio2
#define B_8266_DM_NEO_4 NeoPixelBusLg<NeoGrbwFeature, NeoEsp8266Dma800KbpsMethod, NeoGammaNullMethod>    //4 chan, esp8266, gpio3
#define B_8266_BB_NEO_4 NeoPixelBusLg<NeoGrbwFeature, NeoEsp8266BitBang800KbpsMethod, NeoGammaNullMethod> //4 chan, esp8266, bb (any pin)
//400Kbps
#define B_8266_U0_400_3 NeoPixelBusLg<NeoGrbFeature, NeoEsp8266Uart0400KbpsMethod, NeoGammaNullMethod>   //3 chan, esp8266, gpio1
#define B_8266_U1_400_3 NeoPixelBusLg<NeoGrbFeature, NeoEsp8266Uart1400KbpsMethod, NeoGammaNullMethod>   //3 chan, esp8266, gpio2
#define B_8266_DM_400_3 NeoPixelBusLg<NeoGrbFeature, NeoEsp8266Dma400KbpsMethod, NeoGammaNullMethod>     //3 chan, esp8266, gpio3
#define B_8266_BB_400_3 NeoPixelBusLg<NeoGrbFeature, NeoEsp8266BitBang400KbpsMethod, NeoGammaNullMethod> //3 chan, esp8266, bb (any pin)
//TM1814 (RGBW)
#define B_8266_U0_TM1_4 NeoPixelBusLg<NeoWrgbTm1814Feature, NeoEsp8266Uart0Tm1814Method, NeoGammaNullMethod>
#define B_8266_U1_TM1_4 NeoPixelBusLg<NeoWrgbTm1814Feature, NeoEsp8266Uart1Tm1814Method, NeoGammaNullMethod>
#define B_8266_DM_TM1_4 NeoPixelBusLg<NeoWrgbTm1814Feature, NeoEsp8266DmaTm1814Method, NeoGammaNullMethod>
#define B_8266_BB_TM1_4 NeoPixelBusLg<NeoWrgbTm1814Feature, NeoEsp8266BitBangTm1814Method, NeoGammaNullMethod>
//TM1829 (RGB)
#define B_8266_U0_TM2_3 NeoPixelBusLg<NeoBrgFeature, NeoEsp8266Uart0Tm1829Method, NeoGammaNullMethod>
#define B_8266_U1_TM2_3 NeoPixelBusLg<NeoBrgFeature, NeoEsp8266Uart1Tm1829Method, NeoGammaNullMethod>
#define B_8266_DM_TM2_3 NeoPixelBusLg<NeoBrgFeature, NeoEsp8266DmaTm1829Method, NeoGammaNullMethod>
#define B_8266_BB_TM2_3 NeoPixelBusLg<NeoBrgFeature, NeoEsp8266BitBangTm1829Method, NeoGammaNullMethod>
//UCS8903
#define B_8266_U0_UCS_3 NeoPixelBusLg<NeoRgbUcs8903Feature, NeoEsp8266Uart0Ws2813Method, NeoGammaNullMethod> //3 chan, esp8266, gpio1
#define B_8266_U1_UCS_3 NeoPixelBusLg<NeoRgbUcs8903Feature, NeoEsp8266Uart1Ws2813Method, NeoGammaNullMethod> //3 chan, esp8266, gpio2
#define B_8266_DM_UCS_3 NeoPixelBusLg<NeoRgbUcs8903Feature, NeoEsp8266Dma800KbpsMethod, NeoGammaNullMethod>  //3 chan, esp8266, gpio3
#define B_8266_BB_UCS_3 NeoPixelBusLg<NeoRgbUcs8903Feature, NeoEsp8266BitBang800KbpsMethod, NeoGammaNullMethod> //3 chan, esp8266, bb (any pin but 16)
//UCS8904 RGBW
#define B_8266_U0_UCS_4 NeoPixelBusLg<NeoRgbwUcs8904Feature, NeoEsp8266Uart0Ws2813Method, NeoGammaNullMethod>   //4 chan, esp8266, gpio1
#define B_8266_U1_UCS_4 NeoPixelBusLg<NeoRgbwUcs8904Feature, NeoEsp8266Uart1Ws2813Method, NeoGammaNullMethod>   //4 chan, esp8266, gpio2
#define B_8266_DM_UCS_4 NeoPixelBusLg<NeoRgbwUcs8904Feature, NeoEsp8266Dma800KbpsMethod, NeoGammaNullMethod>    //4 chan, esp8266, gpio3
#define B_8266_BB_UCS_4 NeoPixelBusLg<NeoRgbwUcs8904Feature, NeoEsp8266BitBang800KbpsMethod, NeoGammaNullMethod> //4 chan, esp8266, bb (any pin)
//APA106
#define B_8266_U0_APA106_3 NeoPixelBusLg<NeoRbgFeature, NeoEsp8266Uart0Apa106Method, NeoGammaNullMethod> //3 chan, esp8266, gpio1
#define B_8266_U1_APA106_3 NeoPixelBusLg<NeoRbgFeature, NeoEsp8266Uart1Apa106Method, NeoGammaNullMethod> //3 chan, esp8266, gpio2
#define B_8266_DM_APA106_3 NeoPixelBusLg<NeoGrbFeature, NeoEsp8266DmaApa106Method, NeoGammaNullMethod>  //3 chan, esp8266, gpio3
#define B_8266_BB_APA106_3 NeoPixelBusLg<NeoGrbFeature, NeoEsp8266BitBangApa106Method, NeoGammaNullMethod> //3 chan, esp8266, bb (any pin but 16)
//FW1906 GRBCW
#define B_8266_U0_FW6_5 NeoPixelBusLg<NeoGrbcwxFeature, NeoEsp8266Uart0Ws2813Method, NeoGammaNullMethod>   //esp8266, gpio1
#define B_8266_U1_FW6_5 NeoPixelBusLg<NeoGrbcwxFeature, NeoEsp8266Uart1Ws2813Method, NeoGammaNullMethod>   //esp8266, gpio2
#define B_8266_DM_FW6_5 NeoPixelBusLg<NeoGrbcwxFeature, NeoEsp8266Dma800KbpsMethod, NeoGammaNullMethod>   //esp8266, gpio3
#define B_8266_BB_FW6_5 NeoPixelBusLg<NeoGrbcwxFeature, NeoEsp8266BitBang800KbpsMethod, NeoGammaNullMethod>   //esp8266, bb
//WS2805 GRBCW
#define B_8266_U0_2805_5 NeoPixelBusLg<NeoGrbwwFeature, NeoEsp8266Uart0Ws2805Method, NeoGammaNullMethod> //esp8266, gpio1
#define B_8266_U1_2805_5 NeoPixelBusLg<NeoGrbwwFeature, NeoEsp8266Uart1Ws2805Method, NeoGammaNullMethod> //esp8266, gpio2
#define B_8266_DM_2805_5 NeoPixelBusLg<NeoGrbwwFeature, NeoEsp8266DmaWs2805Method, NeoGammaNullMethod> //esp8266, gpio3
#define B_8266_BB_2805_5 NeoPixelBusLg<NeoGrbwwFeature, NeoEsp8266BitBangWs2805Method, NeoGammaNullMethod> //esp8266, bb
//TM1914 (RGB)
#define B_8266_U0_TM1914_3 NeoPixelBusLg<NeoRgbTm1914Feature, NeoEsp8266Uart0Tm1914Method, NeoGammaNullMethod>
#define B_8266_U1_TM1914_3 NeoPixelBusLg<NeoRgbTm1914Feature, NeoEsp8266Uart1Tm1914Method, NeoGammaNullMethod>
#define B_8266_DM_TM1914_3 NeoPixelBusLg<NeoRgbTm1914Feature, NeoEsp8266DmaTm1914Method, NeoGammaNullMethod>
#define B_8266_BB_TM1914_3 NeoPixelBusLg<NeoRgbTm1914Feature, NeoEsp8266BitBangTm1914Method, NeoGammaNullMethod>
//Sm16825 (RGBWC)
#define B_8266_U0_SM16825_5 NeoPixelBusLg<NeoRgbwcSm16825eFeature, NeoEsp8266Uart0Ws2813Method, NeoGammaNullMethod>
#define B_8266_U1_SM16825_5 NeoPixelBusLg<NeoRgbwcSm16825eFeature, NeoEsp8266Uart1Ws2813Method, NeoGammaNullMethod>
#define B_8266_DM_SM16825_5 NeoPixelBusLg<NeoRgbwcSm16825eFeature, NeoEsp8266Dma800KbpsMethod, NeoGammaNullMethod>
#define B_8266_BB_SM16825_5 NeoPixelBusLg<NeoRgbwcSm16825eFeature, NeoEsp8266BitBangWs2813Method, NeoGammaNullMethod>
#endif

/*** ESP32 Neopixel methods ***/
#ifdef ARDUINO_ARCH_ESP32
//RGB
#define B_32_RN_NEO_3 NeoPixelBusLg<NeoGrbFeature, NeoEsp32RmtNWs2812xMethod, NeoGammaNullMethod>
#define B_32_I0_NEO_3 NeoPixelBusLg<NeoGrbFeature, NeoEsp32I2s0Ws2812xMethod, NeoGammaNullMethod>
#define B_32_I1_NEO_3 NeoPixelBusLg<NeoGrbFeature, NeoEsp32I2s1Ws2812xMethod, NeoGammaNullMethod>
#define B_32_I1_NEO_3P NeoPixelBusLg<NeoGrbFeature, NeoEsp32I2s1X8Ws2812xMethod, NeoGammaNullMethod> // parallel I2S
//RGBW
#define B_32_RN_NEO_4 NeoPixelBusLg<NeoGrbwFeature, NeoEsp32RmtNSk6812Method, NeoGammaNullMethod>
#define B_32_I0_NEO_4 NeoPixelBusLg<NeoGrbwFeature, NeoEsp32I2s0Sk6812Method, NeoGammaNullMethod>
#define B_32_I1_NEO_4 NeoPixelBusLg<NeoGrbwFeature, NeoEsp32I2s1Sk6812Method, NeoGammaNullMethod>
#define B_32_I1_NEO_4P NeoPixelBusLg<NeoGrbwFeature, NeoEsp32I2s1X8Sk6812Method, NeoGammaNullMethod> // parallel I2S
//400Kbps
#define B_32_RN_400_3 NeoPixelBusLg<NeoGrbFeature, NeoEsp32RmtN400KbpsMethod, NeoGammaNullMethod>
#define B_32_I0_400_3 NeoPixelBusLg<NeoGrbFeature, NeoEsp32I2s0400KbpsMethod, NeoGammaNullMethod>
#define B_32_I1_400_3 NeoPixelBusLg<NeoGrbFeature, NeoEsp32I2s1400KbpsMethod, NeoGammaNullMethod>
#define B_32_I1_400_3P NeoPixelBusLg<NeoGrbFeature, NeoEsp32I2s1X8400KbpsMethod, NeoGammaNullMethod> // parallel I2S
//TM1814 (RGBW)
#define B_32_RN_TM1_4 NeoPixelBusLg<NeoWrgbTm1814Feature, NeoEsp32RmtNTm1814Method, NeoGammaNullMethod>
#define B_32_I0_TM1_4 NeoPixelBusLg<NeoWrgbTm1814Feature, NeoEsp32I2s0Tm1814Method, NeoGammaNullMethod>
#define B_32_I1_TM1_4 NeoPixelBusLg<NeoWrgbTm1814Feature, NeoEsp32I2s1Tm1814Method, NeoGammaNullMethod>
#define B_32_I1_TM1_4P NeoPixelBusLg<NeoWrgbTm1814Feature, NeoEsp32I2s1X8Tm1814Method, NeoGammaNullMethod> // parallel I2S
//TM1829 (RGB)
#define B_32_RN_TM2_3 NeoPixelBusLg<NeoBrgFeature, NeoEsp32RmtNTm1829Method, NeoGammaNullMethod>
#define B_32_I0_TM2_3 NeoPixelBusLg<NeoBrgFeature, NeoEsp32I2s0Tm1829Method, NeoGammaNullMethod>
#define B_32_I1_TM2_3 NeoPixelBusLg<NeoBrgFeature, NeoEsp32I2s1Tm1829Method, NeoGammaNullMethod>
#define B_32_I1_TM2_3P NeoPixelBusLg<NeoBrgFeature, NeoEsp32I2s1X8Tm1829Method, NeoGammaNullMethod> // parallel I2S
//UCS8903
#define B_32_RN_UCS_3 NeoPixelBusLg<NeoRgbUcs8903Feature, NeoEsp32RmtNWs2812xMethod, NeoGammaNullMethod>
#define B_32_I0_UCS_3 NeoPixelBusLg<NeoRgbUcs8903Feature, NeoEsp32I2s0800KbpsMethod, NeoGammaNullMethod>
#define B_32_I1_UCS_3 NeoPixelBusLg<NeoRgbUcs8903Feature, NeoEsp32I2s1800KbpsMethod, NeoGammaNullMethod>
#define B_32_I1_UCS_3P NeoPixelBusLg<NeoRgbUcs8903Feature, NeoEsp32I2s1X8800KbpsMethod, NeoGammaNullMethod> // parallel I2S
//UCS8904
#define B_32_RN_UCS_4 NeoPixelBusLg<NeoRgbwUcs8904Feature, NeoEsp32RmtNWs2812xMethod, NeoGammaNullMethod>
#define B_32_I0_UCS_4 NeoPixelBusLg<NeoRgbwUcs8904Feature, NeoEsp32I2s0800KbpsMethod, NeoGammaNullMethod>
#define B_32_I1_UCS_4 NeoPixelBusLg<NeoRgbwUcs8904Feature, NeoEsp32I2s1800KbpsMethod, NeoGammaNullMethod>
#define B_32_I1_UCS_4P NeoPixelBusLg<NeoRgbwUcs8904Feature, NeoEsp32I2s1X8800KbpsMethod, NeoGammaNullMethod>// parallel I2S
//APA106
#define B_32_RN_APA106_3 NeoPixelBusLg<NeoGrbFeature, NeoEsp32RmtNApa106Method, NeoGammaNullMethod>
#define B_32_I0_APA106_3 NeoPixelBusLg<NeoGrbFeature, NeoEsp32I2s0Apa106Method, NeoGammaNullMethod>
#define B_32_I1_APA106_3 NeoPixelBusLg<NeoGrbFeature, NeoEsp32I2s1Apa106Method, NeoGammaNullMethod>
#define B_32_I1_APA106_3P NeoPixelBusLg<NeoGrbFeature, NeoEsp32I2s1X8Apa106Method, NeoGammaNullMethod> // parallel I2S
//FW1906 GRBCW
#define B_32_RN_FW6_5 NeoPixelBusLg<NeoGrbcwxFeature, NeoEsp32RmtNWs2812xMethod, NeoGammaNullMethod>
#define B_32_I0_FW6_5 NeoPixelBusLg<NeoGrbcwxFeature, NeoEsp32I2s0800KbpsMethod, NeoGammaNullMethod>
#define B_32_I1_FW6_5 NeoPixelBusLg<NeoGrbcwxFeature, NeoEsp32I2s1800KbpsMethod, NeoGammaNullMethod>
#define B_32_I1_FW6_5P NeoPixelBusLg<NeoGrbcwxFeature, NeoEsp32I2s1X8800KbpsMethod, NeoGammaNullMethod> // parallel I2S
//WS2805 RGBWC
#define B_32_RN_2805_5 NeoPixelBusLg<NeoGrbwwFeature, NeoEsp32RmtNWs2805Method, NeoGammaNullMethod>
#define B_32_I0_2805_5 NeoPixelBusLg<NeoGrbwwFeature, NeoEsp32I2s0Ws2805Method, NeoGammaNullMethod>
#define B_32_I1_2805_5 NeoPixelBusLg<NeoGrbwwFeature, NeoEsp32I2s1Ws2805Method, NeoGammaNullMethod>
#define B_32_I1_2805_5P NeoPixelBusLg<NeoGrbwwFeature, NeoEsp32I2s1X8Ws2805Method, NeoGammaNullMethod> // parallel I2S
//TM1914 (RGB)
#define B_32_RN_TM1914_3 NeoPixelBusLg<NeoGrbTm1914Feature, NeoEsp32RmtNTm1914Method, NeoGammaNullMethod>
#define B_32_I0_TM1914_3 NeoPixelBusLg<NeoGrbTm1914Feature, NeoEsp32I2s0Tm1914Method, NeoGammaNullMethod>
#define B_32_I1_TM1914_3 NeoPixelBusLg<NeoGrbTm1914Feature, NeoEsp32I2s1Tm1914Method, NeoGammaNullMethod>
#define B_32_I1_TM1914_3P NeoPixelBusLg<NeoGrbTm1914Feature, NeoEsp32I2s1X8Tm1914Method, NeoGammaNullMethod> // parallel I2S
//Sm16825 (RGBWC)
#define B_32_RN_SM16825_5 NeoPixelBusLg<NeoRgbcwSm16825eFeature, NeoEsp32RmtNWs2812xMethod, NeoGammaNullMethod>
#define B_32_I0_SM16825_5 NeoPixelBusLg<NeoRgbcwSm16825eFeature, NeoEsp32I2s0Ws2812xMethod, NeoGammaNullMethod>
#define B_32_I1_SM16825_5 NeoPixelBusLg<NeoRgbcwSm16825eFeature, NeoEsp32I2s1Ws2812xMethod, NeoGammaNullMethod>
#define B_32_I1_SM16825_5P NeoPixelBusLg<NeoRgbcwSm16825eFeature, NeoEsp32I2s1X8Ws2812xMethod, NeoGammaNullMethod> // parallel I2S
#endif

//APA102
#ifdef WLED_USE_ETHERNET
// fix for #2542 (by @BlackBird77)
#define B_HS_DOT_3 NeoPixelBusLg<DotStarBgrFeature, DotStarEsp32HspiHzMethod, NeoGammaNullMethod> //hardware HSPI (was DotStarEsp32DmaHspi5MhzMethod in NPB @ 2.6.9)
#else
#define B_HS_DOT_3 NeoPixelBusLg<DotStarBgrFeature, DotStarSpiHzMethod, NeoGammaNullMethod> //hardware VSPI
#endif
#define B_SS_DOT_3 NeoPixelBusLg<DotStarBgrFeature, DotStarMethod, NeoGammaNullMethod>    //soft SPI

//LPD8806
#define B_HS_LPD_3 NeoPixelBusLg<Lpd8806GrbFeature, Lpd8806SpiHzMethod, NeoGammaNullMethod>
#define B_SS_LPD_3 NeoPixelBusLg<Lpd8806GrbFeature, Lpd8806Method, NeoGammaNullMethod>

//LPD6803
#define B_HS_LPO_3 NeoPixelBusLg<Lpd6803GrbFeature, Lpd6803SpiHzMethod, NeoGammaNullMethod>
#define B_SS_LPO_3 NeoPixelBusLg<Lpd6803GrbFeature, Lpd6803Method, NeoGammaNullMethod>

//WS2801
#ifdef WLED_USE_ETHERNET
#define B_HS_WS1_3 NeoPixelBusLg<NeoRbgFeature, Ws2801MethodBase<TwoWireHspiImple<SpiSpeedHz>>, NeoGammaNullMethod>
#else
#define B_HS_WS1_3 NeoPixelBusLg<NeoRbgFeature, Ws2801SpiHzMethod, NeoGammaNullMethod>
#endif
#define B_SS_WS1_3 NeoPixelBusLg<NeoRbgFeature, Ws2801Method, NeoGammaNullMethod>

//P9813
#define B_HS_P98_3 NeoPixelBusLg<P9813BgrFeature, P9813SpiHzMethod, NeoGammaNullMethod>
#define B_SS_P98_3 NeoPixelBusLg<P9813BgrFeature, P9813Method, NeoGammaNullMethod>

// 48bit & 64bit to 24bit & 32bit RGB(W) conversion
#define toRGBW32(c) (RGBW32((c>>40)&0xFF, (c>>24)&0xFF, (c>>8)&0xFF, (c>>56)&0xFF))
#define RGBW32(r,g,b,w) (uint32_t((byte(w) << 24) | (byte(r) << 16) | (byte(g) << 8) | (byte(b))))

//handles pointer type conversion for all possible bus types
class PolyBus {
  private:
    static bool useParallelI2S;

  public:
    static inline void setParallelI2S1Output(bool b = true) { useParallelI2S = b; }
    static inline bool isParallelI2S1Output(void) { return useParallelI2S; }

  // initialize SPI bus speed for DotStar methods
  template <class T>
  static void beginDotStar(void* busPtr, int8_t sck, int8_t miso, int8_t mosi, int8_t ss, uint16_t clock_kHz = 0U) {
    T dotStar_strip = static_cast<T>(busPtr);
    #ifdef ESP8266
    dotStar_strip->Begin();
    #else
    if (sck == -1 && mosi == -1) dotStar_strip->Begin();
    else                         dotStar_strip->Begin(sck, miso, mosi, ss);
    #endif
    if (clock_kHz) dotStar_strip->SetMethodSettings(NeoSpiSettings((uint32_t)clock_kHz*1000));
  }

  // Begin & initialize the PixelSettings for TM1814 strips.
  template <class T>
  static void beginTM1814(void* busPtr) {
    T tm1814_strip = static_cast<T>(busPtr);
    tm1814_strip->Begin();
    // Max current for each LED (22.5 mA).
    tm1814_strip->SetPixelSettings(NeoTm1814Settings(/*R*/225, /*G*/225, /*B*/225, /*W*/225));
  }

  template <class T>
  static void beginTM1914(void* busPtr) {
    T tm1914_strip = static_cast<T>(busPtr);
    tm1914_strip->Begin();
    tm1914_strip->SetPixelSettings(NeoTm1914Settings());  //NeoTm1914_Mode_DinFdinAutoSwitch, NeoTm1914_Mode_DinOnly, NeoTm1914_Mode_FdinOnly 
  }

  static void begin(void* busPtr, uint8_t busType, uint8_t* pins, uint16_t clock_kHz = 0U) {
    switch (busType) {
      case I_NONE: break;
    #ifdef ESP8266
      case I_8266_U0_NEO_3: (static_cast<B_8266_U0_NEO_3*>(busPtr))->Begin(); break;
      case I_8266_U1_NEO_3: (static_cast<B_8266_U1_NEO_3*>(busPtr))->Begin(); break;
      case I_8266_DM_NEO_3: (static_cast<B_8266_DM_NEO_3*>(busPtr))->Begin(); break;
      case I_8266_BB_NEO_3: (static_cast<B_8266_BB_NEO_3*>(busPtr))->Begin(); break;
      case I_8266_U0_NEO_4: (static_cast<B_8266_U0_NEO_4*>(busPtr))->Begin(); break;
      case I_8266_U1_NEO_4: (static_cast<B_8266_U1_NEO_4*>(busPtr))->Begin(); break;
      case I_8266_DM_NEO_4: (static_cast<B_8266_DM_NEO_4*>(busPtr))->Begin(); break;
      case I_8266_BB_NEO_4: (static_cast<B_8266_BB_NEO_4*>(busPtr))->Begin(); break;
      case I_8266_U0_400_3: (static_cast<B_8266_U0_400_3*>(busPtr))->Begin(); break;
      case I_8266_U1_400_3: (static_cast<B_8266_U1_400_3*>(busPtr))->Begin(); break;
      case I_8266_DM_400_3: (static_cast<B_8266_DM_400_3*>(busPtr))->Begin(); break;
      case I_8266_BB_400_3: (static_cast<B_8266_BB_400_3*>(busPtr))->Begin(); break;
      case I_8266_U0_TM1_4: beginTM1814<B_8266_U0_TM1_4*>(busPtr); break;
      case I_8266_U1_TM1_4: beginTM1814<B_8266_U1_TM1_4*>(busPtr); break;
      case I_8266_DM_TM1_4: beginTM1814<B_8266_DM_TM1_4*>(busPtr); break;
      case I_8266_BB_TM1_4: beginTM1814<B_8266_BB_TM1_4*>(busPtr); break;
      case I_8266_U0_TM2_3: (static_cast<B_8266_U0_TM2_3*>(busPtr))->Begin(); break;
      case I_8266_U1_TM2_3: (static_cast<B_8266_U1_TM2_3*>(busPtr))->Begin(); break;
      case I_8266_DM_TM2_3: (static_cast<B_8266_DM_TM2_3*>(busPtr))->Begin(); break;
      case I_8266_BB_TM2_3: (static_cast<B_8266_BB_TM2_3*>(busPtr))->Begin(); break;
      case I_HS_DOT_3: beginDotStar<B_HS_DOT_3*>(busPtr, -1, -1, -1, -1, clock_kHz); break;
      case I_HS_LPD_3: beginDotStar<B_HS_LPD_3*>(busPtr, -1, -1, -1, -1, clock_kHz); break;
      case I_HS_LPO_3: beginDotStar<B_HS_LPO_3*>(busPtr, -1, -1, -1, -1, clock_kHz); break;
      case I_HS_WS1_3: beginDotStar<B_HS_WS1_3*>(busPtr, -1, -1, -1, -1, clock_kHz); break;
      case I_HS_P98_3: beginDotStar<B_HS_P98_3*>(busPtr, -1, -1, -1, -1, clock_kHz); break;
      case I_8266_U0_UCS_3: (static_cast<B_8266_U0_UCS_3*>(busPtr))->Begin(); break;
      case I_8266_U1_UCS_3: (static_cast<B_8266_U1_UCS_3*>(busPtr))->Begin(); break;
      case I_8266_DM_UCS_3: (static_cast<B_8266_DM_UCS_3*>(busPtr))->Begin(); break;
      case I_8266_BB_UCS_3: (static_cast<B_8266_BB_UCS_3*>(busPtr))->Begin(); break;
      case I_8266_U0_UCS_4: (static_cast<B_8266_U0_UCS_4*>(busPtr))->Begin(); break;
      case I_8266_U1_UCS_4: (static_cast<B_8266_U1_UCS_4*>(busPtr))->Begin(); break;
      case I_8266_DM_UCS_4: (static_cast<B_8266_DM_UCS_4*>(busPtr))->Begin(); break;
      case I_8266_BB_UCS_4: (static_cast<B_8266_BB_UCS_4*>(busPtr))->Begin(); break;
      case I_8266_U0_APA106_3: (static_cast<B_8266_U0_APA106_3*>(busPtr))->Begin(); break;
      case I_8266_U1_APA106_3: (static_cast<B_8266_U1_APA106_3*>(busPtr))->Begin(); break;
      case I_8266_DM_APA106_3: (static_cast<B_8266_DM_APA106_3*>(busPtr))->Begin(); break;
      case I_8266_BB_APA106_3: (static_cast<B_8266_BB_APA106_3*>(busPtr))->Begin(); break;
      case I_8266_U0_FW6_5: (static_cast<B_8266_U0_FW6_5*>(busPtr))->Begin(); break;
      case I_8266_U1_FW6_5: (static_cast<B_8266_U1_FW6_5*>(busPtr))->Begin(); break;
      case I_8266_DM_FW6_5: (static_cast<B_8266_DM_FW6_5*>(busPtr))->Begin(); break;
      case I_8266_BB_FW6_5: (static_cast<B_8266_BB_FW6_5*>(busPtr))->Begin(); break;
      case I_8266_U0_2805_5: (static_cast<B_8266_U0_2805_5*>(busPtr))->Begin(); break;
      case I_8266_U1_2805_5: (static_cast<B_8266_U1_2805_5*>(busPtr))->Begin(); break;
      case I_8266_DM_2805_5: (static_cast<B_8266_DM_2805_5*>(busPtr))->Begin(); break;
      case I_8266_BB_2805_5: (static_cast<B_8266_BB_2805_5*>(busPtr))->Begin(); break;
      case I_8266_U0_TM1914_3: beginTM1914<B_8266_U0_TM1914_3*>(busPtr); break;
      case I_8266_U1_TM1914_3: beginTM1914<B_8266_U1_TM1914_3*>(busPtr); break;
      case I_8266_DM_TM1914_3: beginTM1914<B_8266_DM_TM1914_3*>(busPtr); break;
      case I_8266_BB_TM1914_3: beginTM1914<B_8266_BB_TM1914_3*>(busPtr); break;
      case I_8266_U0_SM16825_5: (static_cast<B_8266_U0_SM16825_5*>(busPtr))->Begin(); break;
      case I_8266_U1_SM16825_5: (static_cast<B_8266_U1_SM16825_5*>(busPtr))->Begin(); break;
      case I_8266_DM_SM16825_5: (static_cast<B_8266_DM_SM16825_5*>(busPtr))->Begin(); break;
      case I_8266_BB_SM16825_5: (static_cast<B_8266_BB_SM16825_5*>(busPtr))->Begin(); break;
    #endif
    #ifdef ARDUINO_ARCH_ESP32
      // RMT buses
      case I_32_RN_NEO_3: (static_cast<B_32_RN_NEO_3*>(busPtr))->Begin(); break;
      case I_32_RN_NEO_4: (static_cast<B_32_RN_NEO_4*>(busPtr))->Begin(); break;
      case I_32_RN_400_3: (static_cast<B_32_RN_400_3*>(busPtr))->Begin(); break;
      case I_32_RN_TM1_4: beginTM1814<B_32_RN_TM1_4*>(busPtr); break;
      case I_32_RN_TM2_3: (static_cast<B_32_RN_TM2_3*>(busPtr))->Begin(); break;
      case I_32_RN_UCS_3: (static_cast<B_32_RN_UCS_3*>(busPtr))->Begin(); break;
      case I_32_RN_UCS_4: (static_cast<B_32_RN_UCS_4*>(busPtr))->Begin(); break;
      case I_32_RN_FW6_5: (static_cast<B_32_RN_FW6_5*>(busPtr))->Begin(); break;
      case I_32_RN_APA106_3: (static_cast<B_32_RN_APA106_3*>(busPtr))->Begin(); break;
      case I_32_RN_2805_5: (static_cast<B_32_RN_2805_5*>(busPtr))->Begin(); break;
      case I_32_RN_TM1914_3: beginTM1914<B_32_RN_TM1914_3*>(busPtr); break;
      case I_32_RN_SM16825_5: (static_cast<B_32_RN_SM16825_5*>(busPtr))->Begin(); break;
      // I2S1 bus or parellel buses
      #ifndef WLED_NO_I2S1_PIXELBUS
      case I_32_I1_NEO_3: if (useParallelI2S) (static_cast<B_32_I1_NEO_3P*>(busPtr))->Begin(); else (static_cast<B_32_I1_NEO_3*>(busPtr))->Begin(); break;
      case I_32_I1_NEO_4: if (useParallelI2S) (static_cast<B_32_I1_NEO_4P*>(busPtr))->Begin(); else (static_cast<B_32_I1_NEO_4*>(busPtr))->Begin(); break;
      case I_32_I1_400_3: if (useParallelI2S) (static_cast<B_32_I1_400_3P*>(busPtr))->Begin(); else (static_cast<B_32_I1_400_3*>(busPtr))->Begin(); break;
      case I_32_I1_TM1_4: if (useParallelI2S) beginTM1814<B_32_I1_TM1_4P*>(busPtr); else beginTM1814<B_32_I1_TM1_4*>(busPtr); break;
      case I_32_I1_TM2_3: if (useParallelI2S) (static_cast<B_32_I1_TM2_3P*>(busPtr))->Begin(); else (static_cast<B_32_I1_TM2_3*>(busPtr))->Begin(); break;
      case I_32_I1_UCS_3: if (useParallelI2S) (static_cast<B_32_I1_UCS_3P*>(busPtr))->Begin(); else (static_cast<B_32_I1_UCS_3*>(busPtr))->Begin(); break;
      case I_32_I1_UCS_4: if (useParallelI2S) (static_cast<B_32_I1_UCS_4P*>(busPtr))->Begin(); else (static_cast<B_32_I1_UCS_4*>(busPtr))->Begin(); break;
      case I_32_I1_FW6_5: if (useParallelI2S) (static_cast<B_32_I1_FW6_5P*>(busPtr))->Begin(); else (static_cast<B_32_I1_FW6_5*>(busPtr))->Begin(); break;
      case I_32_I1_APA106_3: if (useParallelI2S) (static_cast<B_32_I1_APA106_3P*>(busPtr))->Begin(); else (static_cast<B_32_I1_APA106_3*>(busPtr))->Begin(); break;
      case I_32_I1_2805_5: if (useParallelI2S) (static_cast<B_32_I1_2805_5P*>(busPtr))->Begin(); else (static_cast<B_32_I1_2805_5*>(busPtr))->Begin(); break;
      case I_32_I1_TM1914_3: if (useParallelI2S) beginTM1914<B_32_I1_TM1914_3P*>(busPtr); else beginTM1914<B_32_I1_TM1914_3*>(busPtr); break;
      case I_32_I1_SM16825_5: if (useParallelI2S) (static_cast<B_32_I1_SM16825_5P*>(busPtr))->Begin(); else (static_cast<B_32_I1_SM16825_5*>(busPtr))->Begin(); break;
      #endif
      // I2S0 bus
      #ifndef WLED_NO_I2S0_PIXELBUS
      case I_32_I0_NEO_3: (static_cast<B_32_I0_NEO_3*>(busPtr))->Begin(); break;
      case I_32_I0_NEO_4: (static_cast<B_32_I0_NEO_4*>(busPtr))->Begin(); break;
      case I_32_I0_400_3: (static_cast<B_32_I0_400_3*>(busPtr))->Begin(); break;
      case I_32_I0_TM1_4: beginTM1814<B_32_I0_TM1_4*>(busPtr); break;
      case I_32_I0_TM2_3: (static_cast<B_32_I0_TM2_3*>(busPtr))->Begin(); break;
      case I_32_I0_UCS_3: (static_cast<B_32_I0_UCS_3*>(busPtr))->Begin(); break;
      case I_32_I0_UCS_4: (static_cast<B_32_I0_UCS_4*>(busPtr))->Begin(); break;
      case I_32_I0_FW6_5: (static_cast<B_32_I0_FW6_5*>(busPtr))->Begin(); break;
      case I_32_I0_APA106_3: (static_cast<B_32_I0_APA106_3*>(busPtr))->Begin(); break;
      case I_32_I0_2805_5: (static_cast<B_32_I0_2805_5*>(busPtr))->Begin(); break;
      case I_32_I0_TM1914_3: beginTM1914<B_32_I0_TM1914_3*>(busPtr); break;
      case I_32_I0_SM16825_5: (static_cast<B_32_I0_SM16825_5*>(busPtr))->Begin(); break;
      #endif
      // ESP32 can (and should, to avoid inadvertantly driving the chip select signal) specify the pins used for SPI, but only in begin()
      case I_HS_DOT_3: beginDotStar<B_HS_DOT_3*>(busPtr, pins[1], -1, pins[0], -1, clock_kHz); break;
      case I_HS_LPD_3: beginDotStar<B_HS_LPD_3*>(busPtr, pins[1], -1, pins[0], -1, clock_kHz); break;
      case I_HS_LPO_3: beginDotStar<B_HS_LPO_3*>(busPtr, pins[1], -1, pins[0], -1, clock_kHz); break;
      case I_HS_WS1_3: beginDotStar<B_HS_WS1_3*>(busPtr, pins[1], -1, pins[0], -1, clock_kHz); break;
      case I_HS_P98_3: beginDotStar<B_HS_P98_3*>(busPtr, pins[1], -1, pins[0], -1, clock_kHz); break;
    #endif
      case I_SS_DOT_3: (static_cast<B_SS_DOT_3*>(busPtr))->Begin(); break;
      case I_SS_LPD_3: (static_cast<B_SS_LPD_3*>(busPtr))->Begin(); break;
      case I_SS_LPO_3: (static_cast<B_SS_LPO_3*>(busPtr))->Begin(); break;
      case I_SS_WS1_3: (static_cast<B_SS_WS1_3*>(busPtr))->Begin(); break;
      case I_SS_P98_3: (static_cast<B_SS_P98_3*>(busPtr))->Begin(); break;
    }
  }

  static void* create(uint8_t busType, uint8_t* pins, uint16_t len, uint8_t channel, uint16_t clock_kHz = 0U) {
    #if defined(ARDUINO_ARCH_ESP32) && !(defined(CONFIG_IDF_TARGET_ESP32S2) || defined(CONFIG_IDF_TARGET_ESP32S3) || defined(CONFIG_IDF_TARGET_ESP32C3))
    // NOTE: "channel" is only used on ESP32 (and its variants) for RMT channel allocation
    // since 0.15.0-b3 I2S1 is favoured for classic ESP32 and moved to position 0 (channel 0) so we need to subtract 1 for correct RMT allocation
    if (useParallelI2S && channel > 7) channel -= 8; // accommodate parallel I2S1 which is used 1st on classic ESP32
    else if (channel > 0) channel--; // accommodate I2S1 which is used as 1st bus on classic ESP32
    #endif
    void* busPtr = nullptr;
    switch (busType) {
      case I_NONE: break;
    #ifdef ESP8266
      case I_8266_U0_NEO_3: busPtr = new B_8266_U0_NEO_3(len, pins[0]); break;
      case I_8266_U1_NEO_3: busPtr = new B_8266_U1_NEO_3(len, pins[0]); break;
      case I_8266_DM_NEO_3: busPtr = new B_8266_DM_NEO_3(len, pins[0]); break;
      case I_8266_BB_NEO_3: busPtr = new B_8266_BB_NEO_3(len, pins[0]); break;
      case I_8266_U0_NEO_4: busPtr = new B_8266_U0_NEO_4(len, pins[0]); break;
      case I_8266_U1_NEO_4: busPtr = new B_8266_U1_NEO_4(len, pins[0]); break;
      case I_8266_DM_NEO_4: busPtr = new B_8266_DM_NEO_4(len, pins[0]); break;
      case I_8266_BB_NEO_4: busPtr = new B_8266_BB_NEO_4(len, pins[0]); break;
      case I_8266_U0_400_3: busPtr = new B_8266_U0_400_3(len, pins[0]); break;
      case I_8266_U1_400_3: busPtr = new B_8266_U1_400_3(len, pins[0]); break;
      case I_8266_DM_400_3: busPtr = new B_8266_DM_400_3(len, pins[0]); break;
      case I_8266_BB_400_3: busPtr = new B_8266_BB_400_3(len, pins[0]); break;
      case I_8266_U0_TM1_4: busPtr = new B_8266_U0_TM1_4(len, pins[0]); break;
      case I_8266_U1_TM1_4: busPtr = new B_8266_U1_TM1_4(len, pins[0]); break;
      case I_8266_DM_TM1_4: busPtr = new B_8266_DM_TM1_4(len, pins[0]); break;
      case I_8266_BB_TM1_4: busPtr = new B_8266_BB_TM1_4(len, pins[0]); break;
      case I_8266_U0_TM2_3: busPtr = new B_8266_U0_TM2_3(len, pins[0]); break;
      case I_8266_U1_TM2_3: busPtr = new B_8266_U1_TM2_3(len, pins[0]); break;
      case I_8266_DM_TM2_3: busPtr = new B_8266_DM_TM2_3(len, pins[0]); break;
      case I_8266_BB_TM2_3: busPtr = new B_8266_BB_TM2_3(len, pins[0]); break;
      case I_8266_U0_UCS_3: busPtr = new B_8266_U0_UCS_3(len, pins[0]); break;
      case I_8266_U1_UCS_3: busPtr = new B_8266_U1_UCS_3(len, pins[0]); break;
      case I_8266_DM_UCS_3: busPtr = new B_8266_DM_UCS_3(len, pins[0]); break;
      case I_8266_BB_UCS_3: busPtr = new B_8266_BB_UCS_3(len, pins[0]); break;
      case I_8266_U0_UCS_4: busPtr = new B_8266_U0_UCS_4(len, pins[0]); break;
      case I_8266_U1_UCS_4: busPtr = new B_8266_U1_UCS_4(len, pins[0]); break;
      case I_8266_DM_UCS_4: busPtr = new B_8266_DM_UCS_4(len, pins[0]); break;
      case I_8266_BB_UCS_4: busPtr = new B_8266_BB_UCS_4(len, pins[0]); break;
      case I_8266_U0_APA106_3: busPtr = new B_8266_U0_APA106_3(len, pins[0]); break;
      case I_8266_U1_APA106_3: busPtr = new B_8266_U1_APA106_3(len, pins[0]); break;
      case I_8266_DM_APA106_3: busPtr = new B_8266_DM_APA106_3(len, pins[0]); break;
      case I_8266_BB_APA106_3: busPtr = new B_8266_BB_APA106_3(len, pins[0]); break;
      case I_8266_U0_FW6_5: busPtr = new B_8266_U0_FW6_5(len, pins[0]); break;
      case I_8266_U1_FW6_5: busPtr = new B_8266_U1_FW6_5(len, pins[0]); break;
      case I_8266_DM_FW6_5: busPtr = new B_8266_DM_FW6_5(len, pins[0]); break;
      case I_8266_BB_FW6_5: busPtr = new B_8266_BB_FW6_5(len, pins[0]); break;
      case I_8266_U0_2805_5: busPtr = new B_8266_U0_2805_5(len, pins[0]); break;
      case I_8266_U1_2805_5: busPtr = new B_8266_U1_2805_5(len, pins[0]); break;
      case I_8266_DM_2805_5: busPtr = new B_8266_DM_2805_5(len, pins[0]); break;
      case I_8266_BB_2805_5: busPtr = new B_8266_BB_2805_5(len, pins[0]); break;
      case I_8266_U0_TM1914_3: busPtr = new B_8266_U0_TM1914_3(len, pins[0]); break;
      case I_8266_U1_TM1914_3: busPtr = new B_8266_U1_TM1914_3(len, pins[0]); break;
      case I_8266_DM_TM1914_3: busPtr = new B_8266_DM_TM1914_3(len, pins[0]); break;
      case I_8266_BB_TM1914_3: busPtr = new B_8266_BB_TM1914_3(len, pins[0]); break;
      case I_8266_U0_SM16825_5: busPtr = new B_8266_U0_SM16825_5(len, pins[0]); break;
      case I_8266_U1_SM16825_5: busPtr = new B_8266_U1_SM16825_5(len, pins[0]); break;
      case I_8266_DM_SM16825_5: busPtr = new B_8266_DM_SM16825_5(len, pins[0]); break;
      case I_8266_BB_SM16825_5: busPtr = new B_8266_BB_SM16825_5(len, pins[0]); break;
    #endif
    #ifdef ARDUINO_ARCH_ESP32
      // RMT buses
      case I_32_RN_NEO_3: busPtr = new B_32_RN_NEO_3(len, pins[0], (NeoBusChannel)channel); break;
      case I_32_RN_NEO_4: busPtr = new B_32_RN_NEO_4(len, pins[0], (NeoBusChannel)channel); break;
      case I_32_RN_400_3: busPtr = new B_32_RN_400_3(len, pins[0], (NeoBusChannel)channel); break;
      case I_32_RN_TM1_4: busPtr = new B_32_RN_TM1_4(len, pins[0], (NeoBusChannel)channel); break;
      case I_32_RN_TM2_3: busPtr = new B_32_RN_TM2_3(len, pins[0], (NeoBusChannel)channel); break;
      case I_32_RN_UCS_3: busPtr = new B_32_RN_UCS_3(len, pins[0], (NeoBusChannel)channel); break;
      case I_32_RN_UCS_4: busPtr = new B_32_RN_UCS_4(len, pins[0], (NeoBusChannel)channel); break;
      case I_32_RN_APA106_3: busPtr = new B_32_RN_APA106_3(len, pins[0], (NeoBusChannel)channel); break;
      case I_32_RN_FW6_5: busPtr = new B_32_RN_FW6_5(len, pins[0], (NeoBusChannel)channel); break;
      case I_32_RN_2805_5: busPtr = new B_32_RN_2805_5(len, pins[0], (NeoBusChannel)channel); break;
      case I_32_RN_TM1914_3: busPtr = new B_32_RN_TM1914_3(len, pins[0], (NeoBusChannel)channel); break;
      case I_32_RN_SM16825_5: busPtr = new B_32_RN_SM16825_5(len, pins[0], (NeoBusChannel)channel); break;
      // I2S1 bus or paralell buses
      #ifndef WLED_NO_I2S1_PIXELBUS
      case I_32_I1_NEO_3: if (useParallelI2S) busPtr = new B_32_I1_NEO_3P(len, pins[0]); else busPtr = new B_32_I1_NEO_3(len, pins[0]); break;
      case I_32_I1_NEO_4: if (useParallelI2S) busPtr = new B_32_I1_NEO_4P(len, pins[0]); else busPtr = new B_32_I1_NEO_4(len, pins[0]); break;
      case I_32_I1_400_3: if (useParallelI2S) busPtr = new B_32_I1_400_3P(len, pins[0]); else busPtr = new B_32_I1_400_3(len, pins[0]); break;
      case I_32_I1_TM1_4: if (useParallelI2S) busPtr = new B_32_I1_TM1_4P(len, pins[0]); else busPtr = new B_32_I1_TM1_4(len, pins[0]); break;
      case I_32_I1_TM2_3: if (useParallelI2S) busPtr = new B_32_I1_TM2_3P(len, pins[0]); else busPtr = new B_32_I1_TM2_3(len, pins[0]); break;
      case I_32_I1_UCS_3: if (useParallelI2S) busPtr = new B_32_I1_UCS_3P(len, pins[0]); else busPtr = new B_32_I1_UCS_3(len, pins[0]); break;
      case I_32_I1_UCS_4: if (useParallelI2S) busPtr = new B_32_I1_UCS_4P(len, pins[0]); else busPtr = new B_32_I1_UCS_4(len, pins[0]); break;
      case I_32_I1_APA106_3: if (useParallelI2S) busPtr = new B_32_I1_APA106_3P(len, pins[0]); else busPtr = new B_32_I1_APA106_3(len, pins[0]); break;
      case I_32_I1_FW6_5: if (useParallelI2S) busPtr = new B_32_I1_FW6_5P(len, pins[0]); else busPtr = new B_32_I1_FW6_5(len, pins[0]); break;
      case I_32_I1_2805_5: if (useParallelI2S) busPtr = new B_32_I1_2805_5P(len, pins[0]); else busPtr = new B_32_I1_2805_5(len, pins[0]); break;
      case I_32_I1_TM1914_3: if (useParallelI2S) busPtr = new B_32_I1_TM1914_3P(len, pins[0]); else busPtr = new B_32_I1_TM1914_3(len, pins[0]); break;
      case I_32_I1_SM16825_5: if (useParallelI2S) busPtr = new B_32_I1_SM16825_5P(len, pins[0]); else busPtr = new B_32_I1_SM16825_5(len, pins[0]); break;
      #endif
      // I2S0 bus
      #ifndef WLED_NO_I2S0_PIXELBUS
      case I_32_I0_NEO_3: busPtr = new B_32_I0_NEO_3(len, pins[0]); break;
      case I_32_I0_NEO_4: busPtr = new B_32_I0_NEO_4(len, pins[0]); break;
      case I_32_I0_400_3: busPtr = new B_32_I0_400_3(len, pins[0]); break;
      case I_32_I0_TM1_4: busPtr = new B_32_I0_TM1_4(len, pins[0]); break;
      case I_32_I0_TM2_3: busPtr = new B_32_I0_TM2_3(len, pins[0]); break;
      case I_32_I0_UCS_3: busPtr = new B_32_I0_UCS_3(len, pins[0]); break;
      case I_32_I0_UCS_4: busPtr = new B_32_I0_UCS_4(len, pins[0]); break;
      case I_32_I0_APA106_3: busPtr = new B_32_I0_APA106_3(len, pins[0]); break;
      case I_32_I0_FW6_5: busPtr = new B_32_I0_FW6_5(len, pins[0]); break;
      case I_32_I0_2805_5: busPtr = new B_32_I0_2805_5(len, pins[0]); break;
      case I_32_I0_TM1914_3: busPtr = new B_32_I0_TM1914_3(len, pins[0]); break;
      case I_32_I0_SM16825_5: busPtr = new B_32_I0_SM16825_5(len, pins[0]); break;
      #endif
    #endif
      // for 2-wire: pins[1] is clk, pins[0] is dat.  begin expects (len, clk, dat)
      case I_HS_DOT_3: busPtr = new B_HS_DOT_3(len, pins[1], pins[0]); break;
      case I_SS_DOT_3: busPtr = new B_SS_DOT_3(len, pins[1], pins[0]); break;
      case I_HS_LPD_3: busPtr = new B_HS_LPD_3(len, pins[1], pins[0]); break;
      case I_SS_LPD_3: busPtr = new B_SS_LPD_3(len, pins[1], pins[0]); break;
      case I_HS_LPO_3: busPtr = new B_HS_LPO_3(len, pins[1], pins[0]); break;
      case I_SS_LPO_3: busPtr = new B_SS_LPO_3(len, pins[1], pins[0]); break;
      case I_HS_WS1_3: busPtr = new B_HS_WS1_3(len, pins[1], pins[0]); break;
      case I_SS_WS1_3: busPtr = new B_SS_WS1_3(len, pins[1], pins[0]); break;
      case I_HS_P98_3: busPtr = new B_HS_P98_3(len, pins[1], pins[0]); break;
      case I_SS_P98_3: busPtr = new B_SS_P98_3(len, pins[1], pins[0]); break;
    }
    begin(busPtr, busType, pins, clock_kHz);
    return busPtr;
  }

  static void show(void* busPtr, uint8_t busType, bool consistent = true) {
    switch (busType) {
      case I_NONE: break;
    #ifdef ESP8266
      case I_8266_U0_NEO_3: (static_cast<B_8266_U0_NEO_3*>(busPtr))->Show(consistent); break;
      case I_8266_U1_NEO_3: (static_cast<B_8266_U1_NEO_3*>(busPtr))->Show(consistent); break;
      case I_8266_DM_NEO_3: (static_cast<B_8266_DM_NEO_3*>(busPtr))->Show(consistent); break;
      case I_8266_BB_NEO_3: (static_cast<B_8266_BB_NEO_3*>(busPtr))->Show(consistent); break;
      case I_8266_U0_NEO_4: (static_cast<B_8266_U0_NEO_4*>(busPtr))->Show(consistent); break;
      case I_8266_U1_NEO_4: (static_cast<B_8266_U1_NEO_4*>(busPtr))->Show(consistent); break;
      case I_8266_DM_NEO_4: (static_cast<B_8266_DM_NEO_4*>(busPtr))->Show(consistent); break;
      case I_8266_BB_NEO_4: (static_cast<B_8266_BB_NEO_4*>(busPtr))->Show(consistent); break;
      case I_8266_U0_400_3: (static_cast<B_8266_U0_400_3*>(busPtr))->Show(consistent); break;
      case I_8266_U1_400_3: (static_cast<B_8266_U1_400_3*>(busPtr))->Show(consistent); break;
      case I_8266_DM_400_3: (static_cast<B_8266_DM_400_3*>(busPtr))->Show(consistent); break;
      case I_8266_BB_400_3: (static_cast<B_8266_BB_400_3*>(busPtr))->Show(consistent); break;
      case I_8266_U0_TM1_4: (static_cast<B_8266_U0_TM1_4*>(busPtr))->Show(consistent); break;
      case I_8266_U1_TM1_4: (static_cast<B_8266_U1_TM1_4*>(busPtr))->Show(consistent); break;
      case I_8266_DM_TM1_4: (static_cast<B_8266_DM_TM1_4*>(busPtr))->Show(consistent); break;
      case I_8266_BB_TM1_4: (static_cast<B_8266_BB_TM1_4*>(busPtr))->Show(consistent); break;
      case I_8266_U0_TM2_3: (static_cast<B_8266_U0_TM2_3*>(busPtr))->Show(consistent); break;
      case I_8266_U1_TM2_3: (static_cast<B_8266_U1_TM2_3*>(busPtr))->Show(consistent); break;
      case I_8266_DM_TM2_3: (static_cast<B_8266_DM_TM2_3*>(busPtr))->Show(consistent); break;
      case I_8266_BB_TM2_3: (static_cast<B_8266_BB_TM2_3*>(busPtr))->Show(consistent); break;
      case I_8266_U0_UCS_3: (static_cast<B_8266_U0_UCS_3*>(busPtr))->Show(consistent); break;
      case I_8266_U1_UCS_3: (static_cast<B_8266_U1_UCS_3*>(busPtr))->Show(consistent); break;
      case I_8266_DM_UCS_3: (static_cast<B_8266_DM_UCS_3*>(busPtr))->Show(consistent); break;
      case I_8266_BB_UCS_3: (static_cast<B_8266_BB_UCS_3*>(busPtr))->Show(consistent); break;
      case I_8266_U0_UCS_4: (static_cast<B_8266_U0_UCS_4*>(busPtr))->Show(consistent); break;
      case I_8266_U1_UCS_4: (static_cast<B_8266_U1_UCS_4*>(busPtr))->Show(consistent); break;
      case I_8266_DM_UCS_4: (static_cast<B_8266_DM_UCS_4*>(busPtr))->Show(consistent); break;
      case I_8266_BB_UCS_4: (static_cast<B_8266_BB_UCS_4*>(busPtr))->Show(consistent); break;
      case I_8266_U0_APA106_3: (static_cast<B_8266_U0_APA106_3*>(busPtr))->Show(consistent); break;
      case I_8266_U1_APA106_3: (static_cast<B_8266_U1_APA106_3*>(busPtr))->Show(consistent); break;
      case I_8266_DM_APA106_3: (static_cast<B_8266_DM_APA106_3*>(busPtr))->Show(consistent); break;
      case I_8266_BB_APA106_3: (static_cast<B_8266_BB_APA106_3*>(busPtr))->Show(consistent); break;
      case I_8266_U0_FW6_5: (static_cast<B_8266_U0_FW6_5*>(busPtr))->Show(consistent); break;
      case I_8266_U1_FW6_5: (static_cast<B_8266_U1_FW6_5*>(busPtr))->Show(consistent); break;
      case I_8266_DM_FW6_5: (static_cast<B_8266_DM_FW6_5*>(busPtr))->Show(consistent); break;
      case I_8266_BB_FW6_5: (static_cast<B_8266_BB_FW6_5*>(busPtr))->Show(consistent); break;
      case I_8266_U0_2805_5: (static_cast<B_8266_U0_2805_5*>(busPtr))->Show(consistent); break;
      case I_8266_U1_2805_5: (static_cast<B_8266_U1_2805_5*>(busPtr))->Show(consistent); break;
      case I_8266_DM_2805_5: (static_cast<B_8266_DM_2805_5*>(busPtr))->Show(consistent); break;
      case I_8266_BB_2805_5: (static_cast<B_8266_BB_2805_5*>(busPtr))->Show(consistent); break;
      case I_8266_U0_TM1914_3: (static_cast<B_8266_U0_TM1914_3*>(busPtr))->Show(consistent); break;
      case I_8266_U1_TM1914_3: (static_cast<B_8266_U1_TM1914_3*>(busPtr))->Show(consistent); break;
      case I_8266_DM_TM1914_3: (static_cast<B_8266_DM_TM1914_3*>(busPtr))->Show(consistent); break;
      case I_8266_BB_TM1914_3: (static_cast<B_8266_BB_TM1914_3*>(busPtr))->Show(consistent); break;
      case I_8266_U0_SM16825_5: (static_cast<B_8266_U0_SM16825_5*>(busPtr))->Show(consistent); break;
      case I_8266_U1_SM16825_5: (static_cast<B_8266_U1_SM16825_5*>(busPtr))->Show(consistent); break;
      case I_8266_DM_SM16825_5: (static_cast<B_8266_DM_SM16825_5*>(busPtr))->Show(consistent); break;
      case I_8266_BB_SM16825_5: (static_cast<B_8266_BB_SM16825_5*>(busPtr))->Show(consistent); break;
    #endif
    #ifdef ARDUINO_ARCH_ESP32
      // RMT buses
      case I_32_RN_NEO_3: (static_cast<B_32_RN_NEO_3*>(busPtr))->Show(consistent); break;
      case I_32_RN_NEO_4: (static_cast<B_32_RN_NEO_4*>(busPtr))->Show(consistent); break;
      case I_32_RN_400_3: (static_cast<B_32_RN_400_3*>(busPtr))->Show(consistent); break;
      case I_32_RN_TM1_4: (static_cast<B_32_RN_TM1_4*>(busPtr))->Show(consistent); break;
      case I_32_RN_TM2_3: (static_cast<B_32_RN_TM2_3*>(busPtr))->Show(consistent); break;
      case I_32_RN_UCS_3: (static_cast<B_32_RN_UCS_3*>(busPtr))->Show(consistent); break;
      case I_32_RN_UCS_4: (static_cast<B_32_RN_UCS_4*>(busPtr))->Show(consistent); break;
      case I_32_RN_APA106_3: (static_cast<B_32_RN_APA106_3*>(busPtr))->Show(consistent); break;
      case I_32_RN_FW6_5: (static_cast<B_32_RN_FW6_5*>(busPtr))->Show(consistent); break;
      case I_32_RN_2805_5: (static_cast<B_32_RN_2805_5*>(busPtr))->Show(consistent); break;
      case I_32_RN_TM1914_3: (static_cast<B_32_RN_TM1914_3*>(busPtr))->Show(consistent); break;
      case I_32_RN_SM16825_5: (static_cast<B_32_RN_SM16825_5*>(busPtr))->Show(consistent); break;
      // I2S1 bus or paralell buses
      #ifndef WLED_NO_I2S1_PIXELBUS
      case I_32_I1_NEO_3: if (useParallelI2S) (static_cast<B_32_I1_NEO_3P*>(busPtr))->Show(consistent); else (static_cast<B_32_I1_NEO_3*>(busPtr))->Show(consistent); break;
      case I_32_I1_NEO_4: if (useParallelI2S) (static_cast<B_32_I1_NEO_4P*>(busPtr))->Show(consistent); else (static_cast<B_32_I1_NEO_4*>(busPtr))->Show(consistent); break;
      case I_32_I1_400_3: if (useParallelI2S) (static_cast<B_32_I1_400_3P*>(busPtr))->Show(consistent); else (static_cast<B_32_I1_400_3*>(busPtr))->Show(consistent); break;
      case I_32_I1_TM1_4: if (useParallelI2S) (static_cast<B_32_I1_TM1_4P*>(busPtr))->Show(consistent); else (static_cast<B_32_I1_TM1_4*>(busPtr))->Show(consistent); break;
      case I_32_I1_TM2_3: if (useParallelI2S) (static_cast<B_32_I1_TM2_3P*>(busPtr))->Show(consistent); else (static_cast<B_32_I1_TM2_3*>(busPtr))->Show(consistent); break;
      case I_32_I1_UCS_3: if (useParallelI2S) (static_cast<B_32_I1_UCS_3P*>(busPtr))->Show(consistent); else (static_cast<B_32_I1_UCS_3*>(busPtr))->Show(consistent); break;
      case I_32_I1_UCS_4: if (useParallelI2S) (static_cast<B_32_I1_UCS_4P*>(busPtr))->Show(consistent); else (static_cast<B_32_I1_UCS_4*>(busPtr))->Show(consistent); break;
      case I_32_I1_APA106_3: if (useParallelI2S) (static_cast<B_32_I1_APA106_3P*>(busPtr))->Show(consistent); else (static_cast<B_32_I1_APA106_3*>(busPtr))->Show(consistent); break;
      case I_32_I1_FW6_5: if (useParallelI2S) (static_cast<B_32_I1_FW6_5P*>(busPtr))->Show(consistent); else (static_cast<B_32_I1_FW6_5*>(busPtr))->Show(consistent); break;
      case I_32_I1_2805_5: if (useParallelI2S) (static_cast<B_32_I1_2805_5P*>(busPtr))->Show(consistent); else (static_cast<B_32_I1_2805_5*>(busPtr))->Show(consistent); break;
      case I_32_I1_TM1914_3: if (useParallelI2S) (static_cast<B_32_I1_TM1914_3P*>(busPtr))->Show(consistent); else (static_cast<B_32_I1_TM1914_3*>(busPtr))->Show(consistent); break;
      case I_32_I1_SM16825_5: if (useParallelI2S) (static_cast<B_32_I1_SM16825_5P*>(busPtr))->Show(consistent); else (static_cast<B_32_I1_SM16825_5*>(busPtr))->Show(consistent); break;
      #endif
      // I2S0 bus
      #ifndef WLED_NO_I2S0_PIXELBUS
      case I_32_I0_NEO_3: (static_cast<B_32_I0_NEO_3*>(busPtr))->Show(consistent); break;
      case I_32_I0_NEO_4: (static_cast<B_32_I0_NEO_4*>(busPtr))->Show(consistent); break;
      case I_32_I0_400_3: (static_cast<B_32_I0_400_3*>(busPtr))->Show(consistent); break;
      case I_32_I0_TM1_4: (static_cast<B_32_I0_TM1_4*>(busPtr))->Show(consistent); break;
      case I_32_I0_TM2_3: (static_cast<B_32_I0_TM2_3*>(busPtr))->Show(consistent); break;
      case I_32_I0_UCS_3: (static_cast<B_32_I0_UCS_3*>(busPtr))->Show(consistent); break;
      case I_32_I0_UCS_4: (static_cast<B_32_I0_UCS_4*>(busPtr))->Show(consistent); break;
      case I_32_I0_APA106_3: (static_cast<B_32_I0_APA106_3*>(busPtr))->Show(consistent); break;
      case I_32_I0_FW6_5: (static_cast<B_32_I0_FW6_5*>(busPtr))->Show(consistent); break;
      case I_32_I0_2805_5: (static_cast<B_32_I0_2805_5*>(busPtr))->Show(consistent); break;
      case I_32_I0_TM1914_3: (static_cast<B_32_I0_TM1914_3*>(busPtr))->Show(consistent); break;
      case I_32_I0_SM16825_5: (static_cast<B_32_I0_SM16825_5*>(busPtr))->Show(consistent); break;
      #endif
    #endif
      case I_HS_DOT_3: (static_cast<B_HS_DOT_3*>(busPtr))->Show(consistent); break;
      case I_SS_DOT_3: (static_cast<B_SS_DOT_3*>(busPtr))->Show(consistent); break;
      case I_HS_LPD_3: (static_cast<B_HS_LPD_3*>(busPtr))->Show(consistent); break;
      case I_SS_LPD_3: (static_cast<B_SS_LPD_3*>(busPtr))->Show(consistent); break;
      case I_HS_LPO_3: (static_cast<B_HS_LPO_3*>(busPtr))->Show(consistent); break;
      case I_SS_LPO_3: (static_cast<B_SS_LPO_3*>(busPtr))->Show(consistent); break;
      case I_HS_WS1_3: (static_cast<B_HS_WS1_3*>(busPtr))->Show(consistent); break;
      case I_SS_WS1_3: (static_cast<B_SS_WS1_3*>(busPtr))->Show(consistent); break;
      case I_HS_P98_3: (static_cast<B_HS_P98_3*>(busPtr))->Show(consistent); break;
      case I_SS_P98_3: (static_cast<B_SS_P98_3*>(busPtr))->Show(consistent); break;
    }
  }

  static bool canShow(void* busPtr, uint8_t busType) {
    switch (busType) {
      case I_NONE: return true;
    #ifdef ESP8266
      case I_8266_U0_NEO_3: return (static_cast<B_8266_U0_NEO_3*>(busPtr))->CanShow(); break;
      case I_8266_U1_NEO_3: return (static_cast<B_8266_U1_NEO_3*>(busPtr))->CanShow(); break;
      case I_8266_DM_NEO_3: return (static_cast<B_8266_DM_NEO_3*>(busPtr))->CanShow(); break;
      case I_8266_BB_NEO_3: return (static_cast<B_8266_BB_NEO_3*>(busPtr))->CanShow(); break;
      case I_8266_U0_NEO_4: return (static_cast<B_8266_U0_NEO_4*>(busPtr))->CanShow(); break;
      case I_8266_U1_NEO_4: return (static_cast<B_8266_U1_NEO_4*>(busPtr))->CanShow(); break;
      case I_8266_DM_NEO_4: return (static_cast<B_8266_DM_NEO_4*>(busPtr))->CanShow(); break;
      case I_8266_BB_NEO_4: return (static_cast<B_8266_BB_NEO_4*>(busPtr))->CanShow(); break;
      case I_8266_U0_400_3: return (static_cast<B_8266_U0_400_3*>(busPtr))->CanShow(); break;
      case I_8266_U1_400_3: return (static_cast<B_8266_U1_400_3*>(busPtr))->CanShow(); break;
      case I_8266_DM_400_3: return (static_cast<B_8266_DM_400_3*>(busPtr))->CanShow(); break;
      case I_8266_BB_400_3: return (static_cast<B_8266_BB_400_3*>(busPtr))->CanShow(); break;
      case I_8266_U0_TM1_4: return (static_cast<B_8266_U0_TM1_4*>(busPtr))->CanShow(); break;
      case I_8266_U1_TM1_4: return (static_cast<B_8266_U1_TM1_4*>(busPtr))->CanShow(); break;
      case I_8266_DM_TM1_4: return (static_cast<B_8266_DM_TM1_4*>(busPtr))->CanShow(); break;
      case I_8266_BB_TM1_4: return (static_cast<B_8266_BB_TM1_4*>(busPtr))->CanShow(); break;
      case I_8266_U0_TM2_3: return (static_cast<B_8266_U0_TM2_3*>(busPtr))->CanShow(); break;
      case I_8266_U1_TM2_3: return (static_cast<B_8266_U1_TM2_3*>(busPtr))->CanShow(); break;
      case I_8266_DM_TM2_3: return (static_cast<B_8266_DM_TM2_3*>(busPtr))->CanShow(); break;
      case I_8266_BB_TM2_3: return (static_cast<B_8266_BB_TM2_3*>(busPtr))->CanShow(); break;
      case I_8266_U0_UCS_3: return (static_cast<B_8266_U0_UCS_3*>(busPtr))->CanShow(); break;
      case I_8266_U1_UCS_3: return (static_cast<B_8266_U1_UCS_3*>(busPtr))->CanShow(); break;
      case I_8266_DM_UCS_3: return (static_cast<B_8266_DM_UCS_3*>(busPtr))->CanShow(); break;
      case I_8266_BB_UCS_3: return (static_cast<B_8266_BB_UCS_3*>(busPtr))->CanShow(); break;
      case I_8266_U0_UCS_4: return (static_cast<B_8266_U0_UCS_4*>(busPtr))->CanShow(); break;
      case I_8266_U1_UCS_4: return (static_cast<B_8266_U1_UCS_4*>(busPtr))->CanShow(); break;
      case I_8266_DM_UCS_4: return (static_cast<B_8266_DM_UCS_4*>(busPtr))->CanShow(); break;
      case I_8266_U0_APA106_3: return (static_cast<B_8266_U0_APA106_3*>(busPtr))->CanShow(); break;
      case I_8266_U1_APA106_3: return (static_cast<B_8266_U1_APA106_3*>(busPtr))->CanShow(); break;
      case I_8266_DM_APA106_3: return (static_cast<B_8266_DM_APA106_3*>(busPtr))->CanShow(); break;
      case I_8266_BB_APA106_3: return (static_cast<B_8266_BB_APA106_3*>(busPtr))->CanShow(); break;
      case I_8266_U0_FW6_5: return (static_cast<B_8266_U0_FW6_5*>(busPtr))->CanShow(); break;
      case I_8266_U1_FW6_5: return (static_cast<B_8266_U1_FW6_5*>(busPtr))->CanShow(); break;
      case I_8266_DM_FW6_5: return (static_cast<B_8266_DM_FW6_5*>(busPtr))->CanShow(); break;
      case I_8266_BB_FW6_5: return (static_cast<B_8266_BB_FW6_5*>(busPtr))->CanShow(); break;
      case I_8266_U0_2805_5: return (static_cast<B_8266_U0_2805_5*>(busPtr))->CanShow(); break;
      case I_8266_U1_2805_5: return (static_cast<B_8266_U1_2805_5*>(busPtr))->CanShow(); break;
      case I_8266_DM_2805_5: return (static_cast<B_8266_DM_2805_5*>(busPtr))->CanShow(); break;
      case I_8266_BB_2805_5: return (static_cast<B_8266_BB_2805_5*>(busPtr))->CanShow(); break;
      case I_8266_U0_TM1914_3: return (static_cast<B_8266_U0_TM1914_3*>(busPtr))->CanShow(); break;
      case I_8266_U1_TM1914_3: return (static_cast<B_8266_U1_TM1914_3*>(busPtr))->CanShow(); break;
      case I_8266_DM_TM1914_3: return (static_cast<B_8266_DM_TM1914_3*>(busPtr))->CanShow(); break;
      case I_8266_BB_TM1914_3: return (static_cast<B_8266_BB_TM1914_3*>(busPtr))->CanShow(); break;
      case I_8266_U0_SM16825_5: return (static_cast<B_8266_U0_SM16825_5*>(busPtr))->CanShow(); break;
      case I_8266_U1_SM16825_5: return (static_cast<B_8266_U1_SM16825_5*>(busPtr))->CanShow(); break;
      case I_8266_DM_SM16825_5: return (static_cast<B_8266_DM_SM16825_5*>(busPtr))->CanShow(); break;
      case I_8266_BB_SM16825_5: return (static_cast<B_8266_BB_SM16825_5*>(busPtr))->CanShow(); break;
    #endif
    #ifdef ARDUINO_ARCH_ESP32
      // RMT buses
      case I_32_RN_NEO_3: return (static_cast<B_32_RN_NEO_3*>(busPtr))->CanShow(); break;
      case I_32_RN_NEO_4: return (static_cast<B_32_RN_NEO_4*>(busPtr))->CanShow(); break;
      case I_32_RN_400_3: return (static_cast<B_32_RN_400_3*>(busPtr))->CanShow(); break;
      case I_32_RN_TM1_4: return (static_cast<B_32_RN_TM1_4*>(busPtr))->CanShow(); break;
      case I_32_RN_TM2_3: return (static_cast<B_32_RN_TM2_3*>(busPtr))->CanShow(); break;
      case I_32_RN_UCS_3: return (static_cast<B_32_RN_UCS_3*>(busPtr))->CanShow(); break;
      case I_32_RN_UCS_4: return (static_cast<B_32_RN_UCS_4*>(busPtr))->CanShow(); break;
      case I_32_RN_APA106_3: return (static_cast<B_32_RN_APA106_3*>(busPtr))->CanShow(); break;
      case I_32_RN_FW6_5: return (static_cast<B_32_RN_FW6_5*>(busPtr))->CanShow(); break;
      case I_32_RN_2805_5: return (static_cast<B_32_RN_2805_5*>(busPtr))->CanShow(); break;
      case I_32_RN_TM1914_3: return (static_cast<B_32_RN_TM1914_3*>(busPtr))->CanShow(); break;
      case I_32_RN_SM16825_5: return (static_cast<B_32_RN_SM16825_5*>(busPtr))->CanShow(); break;
      // I2S1 bus or paralell buses
      #ifndef WLED_NO_I2S1_PIXELBUS
      case I_32_I1_NEO_3: if (useParallelI2S) return (static_cast<B_32_I1_NEO_3P*>(busPtr))->CanShow(); else return (static_cast<B_32_I1_NEO_3*>(busPtr))->CanShow(); break;
      case I_32_I1_NEO_4: if (useParallelI2S) return (static_cast<B_32_I1_NEO_4P*>(busPtr))->CanShow(); else return (static_cast<B_32_I1_NEO_4*>(busPtr))->CanShow(); break;
      case I_32_I1_400_3: if (useParallelI2S) return (static_cast<B_32_I1_400_3P*>(busPtr))->CanShow(); else return (static_cast<B_32_I1_400_3*>(busPtr))->CanShow(); break;
      case I_32_I1_TM1_4: if (useParallelI2S) return (static_cast<B_32_I1_TM1_4P*>(busPtr))->CanShow(); else return (static_cast<B_32_I1_TM1_4*>(busPtr))->CanShow(); break;
      case I_32_I1_TM2_3: if (useParallelI2S) return (static_cast<B_32_I1_TM2_3P*>(busPtr))->CanShow(); else return (static_cast<B_32_I1_TM2_3*>(busPtr))->CanShow(); break;
      case I_32_I1_UCS_3: if (useParallelI2S) return (static_cast<B_32_I1_UCS_3P*>(busPtr))->CanShow(); else return (static_cast<B_32_I1_UCS_3*>(busPtr))->CanShow(); break;
      case I_32_I1_UCS_4: if (useParallelI2S) return (static_cast<B_32_I1_UCS_4P*>(busPtr))->CanShow(); else return (static_cast<B_32_I1_UCS_4*>(busPtr))->CanShow(); break;
      case I_32_I1_APA106_3: if (useParallelI2S) return (static_cast<B_32_I1_APA106_3P*>(busPtr))->CanShow(); else return (static_cast<B_32_I1_APA106_3*>(busPtr))->CanShow(); break;
      case I_32_I1_FW6_5: if (useParallelI2S) return (static_cast<B_32_I1_FW6_5P*>(busPtr))->CanShow(); else return (static_cast<B_32_I1_FW6_5*>(busPtr))->CanShow(); break;
      case I_32_I1_2805_5: if (useParallelI2S) return (static_cast<B_32_I1_2805_5P*>(busPtr))->CanShow(); else return (static_cast<B_32_I1_2805_5*>(busPtr))->CanShow(); break;
      case I_32_I1_TM1914_3: if (useParallelI2S) return (static_cast<B_32_I1_TM1914_3P*>(busPtr))->CanShow(); else return (static_cast<B_32_I1_TM1914_3*>(busPtr))->CanShow(); break;
      case I_32_I1_SM16825_5: if (useParallelI2S) return (static_cast<B_32_I1_SM16825_5P*>(busPtr))->CanShow(); else return (static_cast<B_32_I1_SM16825_5*>(busPtr))->CanShow(); break;
      #endif
      // I2S0 bus
      #ifndef WLED_NO_I2S0_PIXELBUS
      case I_32_I0_NEO_3: return (static_cast<B_32_I0_NEO_3*>(busPtr))->CanShow(); break;
      case I_32_I0_NEO_4: return (static_cast<B_32_I0_NEO_4*>(busPtr))->CanShow(); break;
      case I_32_I0_400_3: return (static_cast<B_32_I0_400_3*>(busPtr))->CanShow(); break;
      case I_32_I0_TM1_4: return (static_cast<B_32_I0_TM1_4*>(busPtr))->CanShow(); break;
      case I_32_I0_TM2_3: return (static_cast<B_32_I0_TM2_3*>(busPtr))->CanShow(); break;
      case I_32_I0_UCS_3: return (static_cast<B_32_I0_UCS_3*>(busPtr))->CanShow(); break;
      case I_32_I0_UCS_4: return (static_cast<B_32_I0_UCS_4*>(busPtr))->CanShow(); break;
      case I_32_I0_APA106_3: return (static_cast<B_32_I0_APA106_3*>(busPtr))->CanShow(); break;
      case I_32_I0_FW6_5: return (static_cast<B_32_I0_FW6_5*>(busPtr))->CanShow(); break;
      case I_32_I0_2805_5: return (static_cast<B_32_I0_2805_5*>(busPtr))->CanShow(); break;
      case I_32_I0_TM1914_3: return (static_cast<B_32_I0_TM1914_3*>(busPtr))->CanShow(); break;
      case I_32_I0_SM16825_5: return (static_cast<B_32_I0_SM16825_5*>(busPtr))->CanShow(); break;
      #endif
    #endif
      case I_HS_DOT_3: return (static_cast<B_HS_DOT_3*>(busPtr))->CanShow(); break;
      case I_SS_DOT_3: return (static_cast<B_SS_DOT_3*>(busPtr))->CanShow(); break;
      case I_HS_LPD_3: return (static_cast<B_HS_LPD_3*>(busPtr))->CanShow(); break;
      case I_SS_LPD_3: return (static_cast<B_SS_LPD_3*>(busPtr))->CanShow(); break;
      case I_HS_LPO_3: return (static_cast<B_HS_LPO_3*>(busPtr))->CanShow(); break;
      case I_SS_LPO_3: return (static_cast<B_SS_LPO_3*>(busPtr))->CanShow(); break;
      case I_HS_WS1_3: return (static_cast<B_HS_WS1_3*>(busPtr))->CanShow(); break;
      case I_SS_WS1_3: return (static_cast<B_SS_WS1_3*>(busPtr))->CanShow(); break;
      case I_HS_P98_3: return (static_cast<B_HS_P98_3*>(busPtr))->CanShow(); break;
      case I_SS_P98_3: return (static_cast<B_SS_P98_3*>(busPtr))->CanShow(); break;
    }
    return true;
  }

  static void setPixelColor(void* busPtr, uint8_t busType, uint16_t pix, uint32_t c, uint8_t co, uint16_t wwcw = 0) {
    uint8_t r = c >> 16;
    uint8_t g = c >> 8;
    uint8_t b = c >> 0;
    uint8_t w = c >> 24;
    RgbwColor col;
    uint8_t cctWW = wwcw & 0xFF, cctCW = (wwcw>>8) & 0xFF;

    // reorder channels to selected order
    switch (co & 0x0F) {
      default: col.G = g; col.R = r; col.B = b; break; //0 = GRB, default
      case  1: col.G = r; col.R = g; col.B = b; break; //1 = RGB, common for WS2811
      case  2: col.G = b; col.R = r; col.B = g; break; //2 = BRG
      case  3: col.G = r; col.R = b; col.B = g; break; //3 = RBG
      case  4: col.G = b; col.R = g; col.B = r; break; //4 = BGR
      case  5: col.G = g; col.R = b; col.B = r; break; //5 = GBR
    }
    // upper nibble contains W swap information
    switch (co >> 4) {
      default: col.W = w;                break; // no swapping
      case  1: col.W = col.B; col.B = w; break; // swap W & B
      case  2: col.W = col.G; col.G = w; break; // swap W & G
      case  3: col.W = col.R; col.R = w; break; // swap W & R
      case  4: std::swap(cctWW, cctCW);  break; // swap WW & CW
    }

    switch (busType) {
      case I_NONE: break;
    #ifdef ESP8266
      case I_8266_U0_NEO_3: (static_cast<B_8266_U0_NEO_3*>(busPtr))->SetPixelColor(pix, RgbColor(col)); break;
      case I_8266_U1_NEO_3: (static_cast<B_8266_U1_NEO_3*>(busPtr))->SetPixelColor(pix, RgbColor(col)); break;
      case I_8266_DM_NEO_3: (static_cast<B_8266_DM_NEO_3*>(busPtr))->SetPixelColor(pix, RgbColor(col)); break;
      case I_8266_BB_NEO_3: (static_cast<B_8266_BB_NEO_3*>(busPtr))->SetPixelColor(pix, RgbColor(col)); break;
      case I_8266_U0_NEO_4: (static_cast<B_8266_U0_NEO_4*>(busPtr))->SetPixelColor(pix, col); break;
      case I_8266_U1_NEO_4: (static_cast<B_8266_U1_NEO_4*>(busPtr))->SetPixelColor(pix, col); break;
      case I_8266_DM_NEO_4: (static_cast<B_8266_DM_NEO_4*>(busPtr))->SetPixelColor(pix, col); break;
      case I_8266_BB_NEO_4: (static_cast<B_8266_BB_NEO_4*>(busPtr))->SetPixelColor(pix, col); break;
      case I_8266_U0_400_3: (static_cast<B_8266_U0_400_3*>(busPtr))->SetPixelColor(pix, RgbColor(col)); break;
      case I_8266_U1_400_3: (static_cast<B_8266_U1_400_3*>(busPtr))->SetPixelColor(pix, RgbColor(col)); break;
      case I_8266_DM_400_3: (static_cast<B_8266_DM_400_3*>(busPtr))->SetPixelColor(pix, RgbColor(col)); break;
      case I_8266_BB_400_3: (static_cast<B_8266_BB_400_3*>(busPtr))->SetPixelColor(pix, RgbColor(col)); break;
      case I_8266_U0_TM1_4: (static_cast<B_8266_U0_TM1_4*>(busPtr))->SetPixelColor(pix, col); break;
      case I_8266_U1_TM1_4: (static_cast<B_8266_U1_TM1_4*>(busPtr))->SetPixelColor(pix, col); break;
      case I_8266_DM_TM1_4: (static_cast<B_8266_DM_TM1_4*>(busPtr))->SetPixelColor(pix, col); break;
      case I_8266_BB_TM1_4: (static_cast<B_8266_BB_TM1_4*>(busPtr))->SetPixelColor(pix, col); break;
      case I_8266_U0_TM2_3: (static_cast<B_8266_U0_TM2_3*>(busPtr))->SetPixelColor(pix, RgbColor(col)); break;
      case I_8266_U1_TM2_3: (static_cast<B_8266_U1_TM2_3*>(busPtr))->SetPixelColor(pix, RgbColor(col)); break;
      case I_8266_DM_TM2_3: (static_cast<B_8266_DM_TM2_3*>(busPtr))->SetPixelColor(pix, RgbColor(col)); break;
      case I_8266_BB_TM2_3: (static_cast<B_8266_BB_TM2_3*>(busPtr))->SetPixelColor(pix, RgbColor(col)); break;
      case I_8266_U0_UCS_3: (static_cast<B_8266_U0_UCS_3*>(busPtr))->SetPixelColor(pix, Rgb48Color(RgbColor(col))); break;
      case I_8266_U1_UCS_3: (static_cast<B_8266_U1_UCS_3*>(busPtr))->SetPixelColor(pix, Rgb48Color(RgbColor(col))); break;
      case I_8266_DM_UCS_3: (static_cast<B_8266_DM_UCS_3*>(busPtr))->SetPixelColor(pix, Rgb48Color(RgbColor(col))); break;
      case I_8266_BB_UCS_3: (static_cast<B_8266_BB_UCS_3*>(busPtr))->SetPixelColor(pix, Rgb48Color(RgbColor(col))); break;
      case I_8266_U0_UCS_4: (static_cast<B_8266_U0_UCS_4*>(busPtr))->SetPixelColor(pix, Rgbw64Color(col)); break;
      case I_8266_U1_UCS_4: (static_cast<B_8266_U1_UCS_4*>(busPtr))->SetPixelColor(pix, Rgbw64Color(col)); break;
      case I_8266_DM_UCS_4: (static_cast<B_8266_DM_UCS_4*>(busPtr))->SetPixelColor(pix, Rgbw64Color(col)); break;
      case I_8266_BB_UCS_4: (static_cast<B_8266_BB_UCS_4*>(busPtr))->SetPixelColor(pix, Rgbw64Color(col)); break;
      case I_8266_U0_APA106_3: (static_cast<B_8266_U0_APA106_3*>(busPtr))->SetPixelColor(pix, RgbColor(col)); break;
      case I_8266_U1_APA106_3: (static_cast<B_8266_U1_APA106_3*>(busPtr))->SetPixelColor(pix, RgbColor(col)); break;
      case I_8266_DM_APA106_3: (static_cast<B_8266_DM_APA106_3*>(busPtr))->SetPixelColor(pix, RgbColor(col)); break;
      case I_8266_BB_APA106_3: (static_cast<B_8266_BB_APA106_3*>(busPtr))->SetPixelColor(pix, RgbColor(col)); break;
      case I_8266_U0_FW6_5: (static_cast<B_8266_U0_FW6_5*>(busPtr))->SetPixelColor(pix, RgbwwColor(col.R, col.G, col.B, cctWW, cctCW)); break;
      case I_8266_U1_FW6_5: (static_cast<B_8266_U1_FW6_5*>(busPtr))->SetPixelColor(pix, RgbwwColor(col.R, col.G, col.B, cctWW, cctCW)); break;
      case I_8266_DM_FW6_5: (static_cast<B_8266_DM_FW6_5*>(busPtr))->SetPixelColor(pix, RgbwwColor(col.R, col.G, col.B, cctWW, cctCW)); break;
      case I_8266_BB_FW6_5: (static_cast<B_8266_BB_FW6_5*>(busPtr))->SetPixelColor(pix, RgbwwColor(col.R, col.G, col.B, cctWW, cctCW)); break;
      case I_8266_U0_2805_5: (static_cast<B_8266_U0_2805_5*>(busPtr))->SetPixelColor(pix, RgbwwColor(col.R, col.G, col.B, cctWW, cctCW)); break;
      case I_8266_U1_2805_5: (static_cast<B_8266_U1_2805_5*>(busPtr))->SetPixelColor(pix, RgbwwColor(col.R, col.G, col.B, cctWW, cctCW)); break;
      case I_8266_DM_2805_5: (static_cast<B_8266_DM_2805_5*>(busPtr))->SetPixelColor(pix, RgbwwColor(col.R, col.G, col.B, cctWW, cctCW)); break;
      case I_8266_BB_2805_5: (static_cast<B_8266_BB_2805_5*>(busPtr))->SetPixelColor(pix, RgbwwColor(col.R, col.G, col.B, cctWW, cctCW)); break;
      case I_8266_U0_TM1914_3: (static_cast<B_8266_U0_TM1914_3*>(busPtr))->SetPixelColor(pix, RgbColor(col)); break;
      case I_8266_U1_TM1914_3: (static_cast<B_8266_U1_TM1914_3*>(busPtr))->SetPixelColor(pix, RgbColor(col)); break;
      case I_8266_DM_TM1914_3: (static_cast<B_8266_DM_TM1914_3*>(busPtr))->SetPixelColor(pix, RgbColor(col)); break;
      case I_8266_BB_TM1914_3: (static_cast<B_8266_BB_TM1914_3*>(busPtr))->SetPixelColor(pix, RgbColor(col)); break;
      case I_8266_U0_SM16825_5: (static_cast<B_8266_U0_SM16825_5*>(busPtr))->SetPixelColor(pix, Rgbww80Color(col.R*257, col.G*257, col.B*257, cctWW*257, cctCW*257)); break;
      case I_8266_U1_SM16825_5: (static_cast<B_8266_U1_SM16825_5*>(busPtr))->SetPixelColor(pix, Rgbww80Color(col.R*257, col.G*257, col.B*257, cctWW*257, cctCW*257)); break;
      case I_8266_DM_SM16825_5: (static_cast<B_8266_DM_SM16825_5*>(busPtr))->SetPixelColor(pix, Rgbww80Color(col.R*257, col.G*257, col.B*257, cctWW*257, cctCW*257)); break;
      case I_8266_BB_SM16825_5: (static_cast<B_8266_BB_SM16825_5*>(busPtr))->SetPixelColor(pix, Rgbww80Color(col.R*257, col.G*257, col.B*257, cctWW*257, cctCW*257)); break;
    #endif
    #ifdef ARDUINO_ARCH_ESP32
      // RMT buses
      case I_32_RN_NEO_3: (static_cast<B_32_RN_NEO_3*>(busPtr))->SetPixelColor(pix, RgbColor(col)); break;
      case I_32_RN_NEO_4: (static_cast<B_32_RN_NEO_4*>(busPtr))->SetPixelColor(pix, col); break;
      case I_32_RN_400_3: (static_cast<B_32_RN_400_3*>(busPtr))->SetPixelColor(pix, RgbColor(col)); break;
      case I_32_RN_TM1_4: (static_cast<B_32_RN_TM1_4*>(busPtr))->SetPixelColor(pix, col); break;
      case I_32_RN_TM2_3: (static_cast<B_32_RN_TM2_3*>(busPtr))->SetPixelColor(pix, RgbColor(col)); break;
      case I_32_RN_UCS_3: (static_cast<B_32_RN_UCS_3*>(busPtr))->SetPixelColor(pix, Rgb48Color(RgbColor(col))); break;
      case I_32_RN_UCS_4: (static_cast<B_32_RN_UCS_4*>(busPtr))->SetPixelColor(pix, Rgbw64Color(col)); break;
      case I_32_RN_APA106_3: (static_cast<B_32_RN_APA106_3*>(busPtr))->SetPixelColor(pix, RgbColor(col)); break;
      case I_32_RN_FW6_5: (static_cast<B_32_RN_FW6_5*>(busPtr))->SetPixelColor(pix, RgbwwColor(col.R, col.G, col.B, cctWW, cctCW)); break;
      case I_32_RN_2805_5: (static_cast<B_32_RN_2805_5*>(busPtr))->SetPixelColor(pix, RgbwwColor(col.R, col.G, col.B, cctWW, cctCW)); break;
      case I_32_RN_TM1914_3: (static_cast<B_32_RN_TM1914_3*>(busPtr))->SetPixelColor(pix, RgbColor(col)); break;
      case I_32_RN_SM16825_5: (static_cast<B_32_RN_SM16825_5*>(busPtr))->SetPixelColor(pix, Rgbww80Color(col.R*257, col.G*257, col.B*257, cctWW*257, cctCW*257)); break;
      // I2S1 bus or paralell buses
      #ifndef WLED_NO_I2S1_PIXELBUS
      case I_32_I1_NEO_3: if (useParallelI2S) (static_cast<B_32_I1_NEO_3P*>(busPtr))->SetPixelColor(pix, RgbColor(col)); else (static_cast<B_32_I1_NEO_3*>(busPtr))->SetPixelColor(pix, RgbColor(col)); break;
      case I_32_I1_NEO_4: if (useParallelI2S) (static_cast<B_32_I1_NEO_4P*>(busPtr))->SetPixelColor(pix, RgbColor(col)); else (static_cast<B_32_I1_NEO_4*>(busPtr))->SetPixelColor(pix, col); break;
      case I_32_I1_400_3: if (useParallelI2S) (static_cast<B_32_I1_400_3P*>(busPtr))->SetPixelColor(pix, RgbColor(col)); else (static_cast<B_32_I1_400_3*>(busPtr))->SetPixelColor(pix, RgbColor(col)); break;
      case I_32_I1_TM1_4: if (useParallelI2S) (static_cast<B_32_I1_TM1_4P*>(busPtr))->SetPixelColor(pix, RgbColor(col)); else (static_cast<B_32_I1_TM1_4*>(busPtr))->SetPixelColor(pix, col); break;
      case I_32_I1_TM2_3: if (useParallelI2S) (static_cast<B_32_I1_TM2_3P*>(busPtr))->SetPixelColor(pix, RgbColor(col)); else (static_cast<B_32_I1_TM2_3*>(busPtr))->SetPixelColor(pix, RgbColor(col)); break;
      case I_32_I1_UCS_3: if (useParallelI2S) (static_cast<B_32_I1_UCS_3P*>(busPtr))->SetPixelColor(pix, RgbColor(col)); else (static_cast<B_32_I1_UCS_3*>(busPtr))->SetPixelColor(pix, Rgb48Color(RgbColor(col))); break;
      case I_32_I1_UCS_4: if (useParallelI2S) (static_cast<B_32_I1_UCS_4P*>(busPtr))->SetPixelColor(pix, RgbColor(col)); else (static_cast<B_32_I1_UCS_4*>(busPtr))->SetPixelColor(pix, Rgbw64Color(col)); break;
      case I_32_I1_APA106_3: if (useParallelI2S) (static_cast<B_32_I1_APA106_3P*>(busPtr))->SetPixelColor(pix, RgbColor(col)); else (static_cast<B_32_I1_APA106_3*>(busPtr))->SetPixelColor(pix, RgbColor(col)); break;
      case I_32_I1_FW6_5: if (useParallelI2S) (static_cast<B_32_I1_FW6_5P*>(busPtr))->SetPixelColor(pix, RgbwwColor(col.R, col.G, col.B, cctWW, cctCW)); else (static_cast<B_32_I1_FW6_5*>(busPtr))->SetPixelColor(pix, RgbwwColor(col.R, col.G, col.B, cctWW, cctCW)); break;
      case I_32_I1_2805_5: if (useParallelI2S) (static_cast<B_32_I1_2805_5P*>(busPtr))->SetPixelColor(pix, RgbwwColor(col.R, col.G, col.B, cctWW, cctCW)); else (static_cast<B_32_I1_2805_5*>(busPtr))->SetPixelColor(pix, RgbwwColor(col.R, col.G, col.B, cctWW, cctCW)); break;
      case I_32_I1_TM1914_3: if (useParallelI2S) (static_cast<B_32_I1_TM1914_3P*>(busPtr))->SetPixelColor(pix, RgbColor(col)); else (static_cast<B_32_I1_TM1914_3*>(busPtr))->SetPixelColor(pix, RgbColor(col)); break;
      case I_32_I1_SM16825_5: if (useParallelI2S) (static_cast<B_32_I1_SM16825_5P*>(busPtr))->SetPixelColor(pix, Rgbww80Color(col.R*257, col.G*257, col.B*257, cctWW*257, cctCW*257)); else (static_cast<B_32_I1_SM16825_5*>(busPtr))->SetPixelColor(pix, Rgbww80Color(col.R*257, col.G*257, col.B*257, cctWW*257, cctCW*257)); break;
      #endif
      // I2S0 bus
      #ifndef WLED_NO_I2S0_PIXELBUS
      case I_32_I0_NEO_3: (static_cast<B_32_I0_NEO_3*>(busPtr))->SetPixelColor(pix, RgbColor(col)); break;
      case I_32_I0_NEO_4: (static_cast<B_32_I0_NEO_4*>(busPtr))->SetPixelColor(pix, col); break;
      case I_32_I0_400_3: (static_cast<B_32_I0_400_3*>(busPtr))->SetPixelColor(pix, RgbColor(col)); break;
      case I_32_I0_TM1_4: (static_cast<B_32_I0_TM1_4*>(busPtr))->SetPixelColor(pix, col); break;
      case I_32_I0_TM2_3: (static_cast<B_32_I0_TM2_3*>(busPtr))->SetPixelColor(pix, RgbColor(col)); break;
      case I_32_I0_UCS_3: (static_cast<B_32_I0_UCS_3*>(busPtr))->SetPixelColor(pix, Rgb48Color(RgbColor(col))); break;
      case I_32_I0_UCS_4: (static_cast<B_32_I0_UCS_4*>(busPtr))->SetPixelColor(pix, Rgbw64Color(col)); break;
      case I_32_I0_APA106_3: (static_cast<B_32_I0_APA106_3*>(busPtr))->SetPixelColor(pix, RgbColor(col)); break;
      case I_32_I0_FW6_5: (static_cast<B_32_I0_FW6_5*>(busPtr))->SetPixelColor(pix, RgbwwColor(col.R, col.G, col.B, cctWW, cctCW)); break;
      case I_32_I0_2805_5: (static_cast<B_32_I0_2805_5*>(busPtr))->SetPixelColor(pix, RgbwwColor(col.R, col.G, col.B, cctWW, cctCW)); break;
      case I_32_I0_TM1914_3: (static_cast<B_32_I0_TM1914_3*>(busPtr))->SetPixelColor(pix, RgbColor(col)); break;
      case I_32_I0_SM16825_5: (static_cast<B_32_I0_SM16825_5*>(busPtr))->SetPixelColor(pix, Rgbww80Color(col.R*257, col.G*257, col.B*257, cctWW*257, cctCW*257)); break;
      #endif
    #endif
      case I_HS_DOT_3: (static_cast<B_HS_DOT_3*>(busPtr))->SetPixelColor(pix, RgbColor(col)); break;
      case I_SS_DOT_3: (static_cast<B_SS_DOT_3*>(busPtr))->SetPixelColor(pix, RgbColor(col)); break;
      case I_HS_LPD_3: (static_cast<B_HS_LPD_3*>(busPtr))->SetPixelColor(pix, RgbColor(col)); break;
      case I_SS_LPD_3: (static_cast<B_SS_LPD_3*>(busPtr))->SetPixelColor(pix, RgbColor(col)); break;
      case I_HS_LPO_3: (static_cast<B_HS_LPO_3*>(busPtr))->SetPixelColor(pix, RgbColor(col)); break;
      case I_SS_LPO_3: (static_cast<B_SS_LPO_3*>(busPtr))->SetPixelColor(pix, RgbColor(col)); break;
      case I_HS_WS1_3: (static_cast<B_HS_WS1_3*>(busPtr))->SetPixelColor(pix, RgbColor(col)); break;
      case I_SS_WS1_3: (static_cast<B_SS_WS1_3*>(busPtr))->SetPixelColor(pix, RgbColor(col)); break;
      case I_HS_P98_3: (static_cast<B_HS_P98_3*>(busPtr))->SetPixelColor(pix, RgbColor(col)); break;
      case I_SS_P98_3: (static_cast<B_SS_P98_3*>(busPtr))->SetPixelColor(pix, RgbColor(col)); break;
    }
  }

  static void setBrightness(void* busPtr, uint8_t busType, uint8_t b) {
    switch (busType) {
      case I_NONE: break;
    #ifdef ESP8266
      case I_8266_U0_NEO_3: (static_cast<B_8266_U0_NEO_3*>(busPtr))->SetLuminance(b); break;
      case I_8266_U1_NEO_3: (static_cast<B_8266_U1_NEO_3*>(busPtr))->SetLuminance(b); break;
      case I_8266_DM_NEO_3: (static_cast<B_8266_DM_NEO_3*>(busPtr))->SetLuminance(b); break;
      case I_8266_BB_NEO_3: (static_cast<B_8266_BB_NEO_3*>(busPtr))->SetLuminance(b); break;
      case I_8266_U0_NEO_4: (static_cast<B_8266_U0_NEO_4*>(busPtr))->SetLuminance(b); break;
      case I_8266_U1_NEO_4: (static_cast<B_8266_U1_NEO_4*>(busPtr))->SetLuminance(b); break;
      case I_8266_DM_NEO_4: (static_cast<B_8266_DM_NEO_4*>(busPtr))->SetLuminance(b); break;
      case I_8266_BB_NEO_4: (static_cast<B_8266_BB_NEO_4*>(busPtr))->SetLuminance(b); break;
      case I_8266_U0_400_3: (static_cast<B_8266_U0_400_3*>(busPtr))->SetLuminance(b); break;
      case I_8266_U1_400_3: (static_cast<B_8266_U1_400_3*>(busPtr))->SetLuminance(b); break;
      case I_8266_DM_400_3: (static_cast<B_8266_DM_400_3*>(busPtr))->SetLuminance(b); break;
      case I_8266_BB_400_3: (static_cast<B_8266_BB_400_3*>(busPtr))->SetLuminance(b); break;
      case I_8266_U0_TM1_4: (static_cast<B_8266_U0_TM1_4*>(busPtr))->SetLuminance(b); break;
      case I_8266_U1_TM1_4: (static_cast<B_8266_U1_TM1_4*>(busPtr))->SetLuminance(b); break;
      case I_8266_DM_TM1_4: (static_cast<B_8266_DM_TM1_4*>(busPtr))->SetLuminance(b); break;
      case I_8266_BB_TM1_4: (static_cast<B_8266_BB_TM1_4*>(busPtr))->SetLuminance(b); break;
      case I_8266_U0_TM2_3: (static_cast<B_8266_U0_TM2_3*>(busPtr))->SetLuminance(b); break;
      case I_8266_U1_TM2_3: (static_cast<B_8266_U1_TM2_3*>(busPtr))->SetLuminance(b); break;
      case I_8266_DM_TM2_3: (static_cast<B_8266_DM_TM2_3*>(busPtr))->SetLuminance(b); break;
      case I_8266_BB_TM2_3: (static_cast<B_8266_BB_TM2_3*>(busPtr))->SetLuminance(b); break;
      case I_8266_U0_UCS_3: (static_cast<B_8266_U0_UCS_3*>(busPtr))->SetLuminance(b); break;
      case I_8266_U1_UCS_3: (static_cast<B_8266_U1_UCS_3*>(busPtr))->SetLuminance(b); break;
      case I_8266_DM_UCS_3: (static_cast<B_8266_DM_UCS_3*>(busPtr))->SetLuminance(b); break;
      case I_8266_BB_UCS_3: (static_cast<B_8266_BB_UCS_3*>(busPtr))->SetLuminance(b); break;
      case I_8266_U0_UCS_4: (static_cast<B_8266_U0_UCS_4*>(busPtr))->SetLuminance(b); break;
      case I_8266_U1_UCS_4: (static_cast<B_8266_U1_UCS_4*>(busPtr))->SetLuminance(b); break;
      case I_8266_DM_UCS_4: (static_cast<B_8266_DM_UCS_4*>(busPtr))->SetLuminance(b); break;
      case I_8266_BB_UCS_4: (static_cast<B_8266_BB_UCS_4*>(busPtr))->SetLuminance(b); break;
      case I_8266_U0_APA106_3: (static_cast<B_8266_U0_APA106_3*>(busPtr))->SetLuminance(b); break;
      case I_8266_U1_APA106_3: (static_cast<B_8266_U1_APA106_3*>(busPtr))->SetLuminance(b); break;
      case I_8266_DM_APA106_3: (static_cast<B_8266_DM_APA106_3*>(busPtr))->SetLuminance(b); break;
      case I_8266_BB_APA106_3: (static_cast<B_8266_BB_APA106_3*>(busPtr))->SetLuminance(b); break;
      case I_8266_U0_FW6_5: (static_cast<B_8266_U0_FW6_5*>(busPtr))->SetLuminance(b); break;
      case I_8266_U1_FW6_5: (static_cast<B_8266_U1_FW6_5*>(busPtr))->SetLuminance(b); break;
      case I_8266_DM_FW6_5: (static_cast<B_8266_DM_FW6_5*>(busPtr))->SetLuminance(b); break;
      case I_8266_BB_FW6_5: (static_cast<B_8266_BB_FW6_5*>(busPtr))->SetLuminance(b); break;
      case I_8266_U0_2805_5: (static_cast<B_8266_U0_2805_5*>(busPtr))->SetLuminance(b); break;
      case I_8266_U1_2805_5: (static_cast<B_8266_U1_2805_5*>(busPtr))->SetLuminance(b); break;
      case I_8266_DM_2805_5: (static_cast<B_8266_DM_2805_5*>(busPtr))->SetLuminance(b); break;
      case I_8266_BB_2805_5: (static_cast<B_8266_BB_2805_5*>(busPtr))->SetLuminance(b); break;
      case I_8266_U0_TM1914_3: (static_cast<B_8266_U0_TM1914_3*>(busPtr))->SetLuminance(b); break;
      case I_8266_U1_TM1914_3: (static_cast<B_8266_U1_TM1914_3*>(busPtr))->SetLuminance(b); break;
      case I_8266_DM_TM1914_3: (static_cast<B_8266_DM_TM1914_3*>(busPtr))->SetLuminance(b); break;
      case I_8266_BB_TM1914_3: (static_cast<B_8266_BB_TM1914_3*>(busPtr))->SetLuminance(b); break;
      case I_8266_U0_SM16825_5: (static_cast<B_8266_U0_SM16825_5*>(busPtr))->SetLuminance(b); break;
      case I_8266_U1_SM16825_5: (static_cast<B_8266_U1_SM16825_5*>(busPtr))->SetLuminance(b); break;
      case I_8266_DM_SM16825_5: (static_cast<B_8266_DM_SM16825_5*>(busPtr))->SetLuminance(b); break;
      case I_8266_BB_SM16825_5: (static_cast<B_8266_BB_SM16825_5*>(busPtr))->SetLuminance(b); break;
    #endif
    #ifdef ARDUINO_ARCH_ESP32
      // RMT buses
      case I_32_RN_NEO_3: (static_cast<B_32_RN_NEO_3*>(busPtr))->SetLuminance(b); break;
      case I_32_RN_NEO_4: (static_cast<B_32_RN_NEO_4*>(busPtr))->SetLuminance(b); break;
      case I_32_RN_400_3: (static_cast<B_32_RN_400_3*>(busPtr))->SetLuminance(b); break;
      case I_32_RN_TM1_4: (static_cast<B_32_RN_TM1_4*>(busPtr))->SetLuminance(b); break;
      case I_32_RN_TM2_3: (static_cast<B_32_RN_TM2_3*>(busPtr))->SetLuminance(b); break;
      case I_32_RN_UCS_3: (static_cast<B_32_RN_UCS_3*>(busPtr))->SetLuminance(b); break;
      case I_32_RN_UCS_4: (static_cast<B_32_RN_UCS_4*>(busPtr))->SetLuminance(b); break;
      case I_32_RN_APA106_3: (static_cast<B_32_RN_APA106_3*>(busPtr))->SetLuminance(b); break;
      case I_32_RN_FW6_5: (static_cast<B_32_RN_FW6_5*>(busPtr))->SetLuminance(b); break;
      case I_32_RN_2805_5: (static_cast<B_32_RN_2805_5*>(busPtr))->SetLuminance(b); break;
      case I_32_RN_TM1914_3: (static_cast<B_32_RN_TM1914_3*>(busPtr))->SetLuminance(b); break;
      case I_32_RN_SM16825_5: (static_cast<B_32_RN_SM16825_5*>(busPtr))->SetLuminance(b); break;
      // I2S1 bus or paralell buses
      #ifndef WLED_NO_I2S1_PIXELBUS
      case I_32_I1_NEO_3: if (useParallelI2S) (static_cast<B_32_I1_NEO_3P*>(busPtr))->SetLuminance(b); else (static_cast<B_32_I1_NEO_3*>(busPtr))->SetLuminance(b); break;
      case I_32_I1_NEO_4: if (useParallelI2S) (static_cast<B_32_I1_NEO_4P*>(busPtr))->SetLuminance(b); else (static_cast<B_32_I1_NEO_4*>(busPtr))->SetLuminance(b); break;
      case I_32_I1_400_3: if (useParallelI2S) (static_cast<B_32_I1_400_3P*>(busPtr))->SetLuminance(b); else (static_cast<B_32_I1_400_3*>(busPtr))->SetLuminance(b); break;
      case I_32_I1_TM1_4: if (useParallelI2S) (static_cast<B_32_I1_TM1_4P*>(busPtr))->SetLuminance(b); else (static_cast<B_32_I1_TM1_4*>(busPtr))->SetLuminance(b); break;
      case I_32_I1_TM2_3: if (useParallelI2S) (static_cast<B_32_I1_TM2_3P*>(busPtr))->SetLuminance(b); else (static_cast<B_32_I1_TM2_3*>(busPtr))->SetLuminance(b); break;
      case I_32_I1_UCS_3: if (useParallelI2S) (static_cast<B_32_I1_UCS_3P*>(busPtr))->SetLuminance(b); else (static_cast<B_32_I1_UCS_3*>(busPtr))->SetLuminance(b); break;
      case I_32_I1_UCS_4: if (useParallelI2S) (static_cast<B_32_I1_UCS_4P*>(busPtr))->SetLuminance(b); else (static_cast<B_32_I1_UCS_4*>(busPtr))->SetLuminance(b); break;
      case I_32_I1_APA106_3: if (useParallelI2S) (static_cast<B_32_I1_APA106_3P*>(busPtr))->SetLuminance(b); else (static_cast<B_32_I1_APA106_3*>(busPtr))->SetLuminance(b); break;
      case I_32_I1_FW6_5: if (useParallelI2S) (static_cast<B_32_I1_FW6_5P*>(busPtr))->SetLuminance(b); else (static_cast<B_32_I1_FW6_5*>(busPtr))->SetLuminance(b); break;
      case I_32_I1_2805_5: if (useParallelI2S) (static_cast<B_32_I1_2805_5P*>(busPtr))->SetLuminance(b); else (static_cast<B_32_I1_2805_5*>(busPtr))->SetLuminance(b); break;
      case I_32_I1_TM1914_3: if (useParallelI2S) (static_cast<B_32_I1_TM1914_3P*>(busPtr))->SetLuminance(b); else (static_cast<B_32_I1_TM1914_3*>(busPtr))->SetLuminance(b); break;
      case I_32_I1_SM16825_5: if (useParallelI2S) (static_cast<B_32_I1_SM16825_5P*>(busPtr))->SetLuminance(b); else (static_cast<B_32_I1_SM16825_5*>(busPtr))->SetLuminance(b); break;
      #endif
      // I2S0 bus
      #ifndef WLED_NO_I2S0_PIXELBUS
      case I_32_I0_NEO_3: (static_cast<B_32_I0_NEO_3*>(busPtr))->SetLuminance(b); break;
      case I_32_I0_NEO_4: (static_cast<B_32_I0_NEO_4*>(busPtr))->SetLuminance(b); break;
      case I_32_I0_400_3: (static_cast<B_32_I0_400_3*>(busPtr))->SetLuminance(b); break;
      case I_32_I0_TM1_4: (static_cast<B_32_I0_TM1_4*>(busPtr))->SetLuminance(b); break;
      case I_32_I0_TM2_3: (static_cast<B_32_I0_TM2_3*>(busPtr))->SetLuminance(b); break;
      case I_32_I0_UCS_3: (static_cast<B_32_I0_UCS_3*>(busPtr))->SetLuminance(b); break;
      case I_32_I0_UCS_4: (static_cast<B_32_I0_UCS_4*>(busPtr))->SetLuminance(b); break;
      case I_32_I0_APA106_3: (static_cast<B_32_I0_APA106_3*>(busPtr))->SetLuminance(b); break;
      case I_32_I0_FW6_5: (static_cast<B_32_I0_FW6_5*>(busPtr))->SetLuminance(b); break;
      case I_32_I0_2805_5: (static_cast<B_32_I0_2805_5*>(busPtr))->SetLuminance(b); break;
      case I_32_I0_TM1914_3: (static_cast<B_32_I0_TM1914_3*>(busPtr))->SetLuminance(b); break;
      case I_32_I0_SM16825_5: (static_cast<B_32_I0_SM16825_5*>(busPtr))->SetLuminance(b); break;
      #endif
    #endif
      case I_HS_DOT_3: (static_cast<B_HS_DOT_3*>(busPtr))->SetLuminance(b); break;
      case I_SS_DOT_3: (static_cast<B_SS_DOT_3*>(busPtr))->SetLuminance(b); break;
      case I_HS_LPD_3: (static_cast<B_HS_LPD_3*>(busPtr))->SetLuminance(b); break;
      case I_SS_LPD_3: (static_cast<B_SS_LPD_3*>(busPtr))->SetLuminance(b); break;
      case I_HS_LPO_3: (static_cast<B_HS_LPO_3*>(busPtr))->SetLuminance(b); break;
      case I_SS_LPO_3: (static_cast<B_SS_LPO_3*>(busPtr))->SetLuminance(b); break;
      case I_HS_WS1_3: (static_cast<B_HS_WS1_3*>(busPtr))->SetLuminance(b); break;
      case I_SS_WS1_3: (static_cast<B_SS_WS1_3*>(busPtr))->SetLuminance(b); break;
      case I_HS_P98_3: (static_cast<B_HS_P98_3*>(busPtr))->SetLuminance(b); break;
      case I_SS_P98_3: (static_cast<B_SS_P98_3*>(busPtr))->SetLuminance(b); break;
    }
  }

  static uint32_t getPixelColor(void* busPtr, uint8_t busType, uint16_t pix, uint8_t co) {
    RgbwColor col(0,0,0,0);
    switch (busType) {
      case I_NONE: break;
    #ifdef ESP8266
      case I_8266_U0_NEO_3: col = (static_cast<B_8266_U0_NEO_3*>(busPtr))->GetPixelColor(pix); break;
      case I_8266_U1_NEO_3: col = (static_cast<B_8266_U1_NEO_3*>(busPtr))->GetPixelColor(pix); break;
      case I_8266_DM_NEO_3: col = (static_cast<B_8266_DM_NEO_3*>(busPtr))->GetPixelColor(pix); break;
      case I_8266_BB_NEO_3: col = (static_cast<B_8266_BB_NEO_3*>(busPtr))->GetPixelColor(pix); break;
      case I_8266_U0_NEO_4: col = (static_cast<B_8266_U0_NEO_4*>(busPtr))->GetPixelColor(pix); break;
      case I_8266_U1_NEO_4: col = (static_cast<B_8266_U1_NEO_4*>(busPtr))->GetPixelColor(pix); break;
      case I_8266_DM_NEO_4: col = (static_cast<B_8266_DM_NEO_4*>(busPtr))->GetPixelColor(pix); break;
      case I_8266_BB_NEO_4: col = (static_cast<B_8266_BB_NEO_4*>(busPtr))->GetPixelColor(pix); break;
      case I_8266_U0_400_3: col = (static_cast<B_8266_U0_400_3*>(busPtr))->GetPixelColor(pix); break;
      case I_8266_U1_400_3: col = (static_cast<B_8266_U1_400_3*>(busPtr))->GetPixelColor(pix); break;
      case I_8266_DM_400_3: col = (static_cast<B_8266_DM_400_3*>(busPtr))->GetPixelColor(pix); break;
      case I_8266_BB_400_3: col = (static_cast<B_8266_BB_400_3*>(busPtr))->GetPixelColor(pix); break;
      case I_8266_U0_TM1_4: col = (static_cast<B_8266_U0_TM1_4*>(busPtr))->GetPixelColor(pix); break;
      case I_8266_U1_TM1_4: col = (static_cast<B_8266_U1_TM1_4*>(busPtr))->GetPixelColor(pix); break;
      case I_8266_DM_TM1_4: col = (static_cast<B_8266_DM_TM1_4*>(busPtr))->GetPixelColor(pix); break;
      case I_8266_BB_TM1_4: col = (static_cast<B_8266_BB_TM1_4*>(busPtr))->GetPixelColor(pix); break;
      case I_8266_U0_TM2_3: col = (static_cast<B_8266_U0_TM2_3*>(busPtr))->GetPixelColor(pix); break;
      case I_8266_U1_TM2_3: col = (static_cast<B_8266_U1_TM2_3*>(busPtr))->GetPixelColor(pix); break;
      case I_8266_DM_TM2_3: col = (static_cast<B_8266_DM_TM2_3*>(busPtr))->GetPixelColor(pix); break;
      case I_8266_BB_TM2_3: col = (static_cast<B_8266_BB_TM2_3*>(busPtr))->GetPixelColor(pix); break;
      case I_8266_U0_UCS_3: { Rgb48Color c = (static_cast<B_8266_U0_UCS_3*>(busPtr))->GetPixelColor(pix); col = RGBW32(c.R>>8,c.G>>8,c.B>>8,0); } break;
      case I_8266_U1_UCS_3: { Rgb48Color c = (static_cast<B_8266_U1_UCS_3*>(busPtr))->GetPixelColor(pix); col = RGBW32(c.R>>8,c.G>>8,c.B>>8,0); } break;
      case I_8266_DM_UCS_3: { Rgb48Color c = (static_cast<B_8266_DM_UCS_3*>(busPtr))->GetPixelColor(pix); col = RGBW32(c.R>>8,c.G>>8,c.B>>8,0); } break;
      case I_8266_BB_UCS_3: { Rgb48Color c = (static_cast<B_8266_BB_UCS_3*>(busPtr))->GetPixelColor(pix); col = RGBW32(c.R>>8,c.G>>8,c.B>>8,0); } break;
      case I_8266_U0_UCS_4: { Rgbw64Color c = (static_cast<B_8266_U0_UCS_4*>(busPtr))->GetPixelColor(pix); col = RGBW32(c.R>>8,c.G>>8,c.B>>8,c.W>>8); } break;
      case I_8266_U1_UCS_4: { Rgbw64Color c = (static_cast<B_8266_U1_UCS_4*>(busPtr))->GetPixelColor(pix); col = RGBW32(c.R>>8,c.G>>8,c.B>>8,c.W>>8); } break;
      case I_8266_DM_UCS_4: { Rgbw64Color c = (static_cast<B_8266_DM_UCS_4*>(busPtr))->GetPixelColor(pix); col = RGBW32(c.R>>8,c.G>>8,c.B>>8,c.W>>8); } break;
      case I_8266_BB_UCS_4: { Rgbw64Color c = (static_cast<B_8266_BB_UCS_4*>(busPtr))->GetPixelColor(pix); col = RGBW32(c.R>>8,c.G>>8,c.B>>8,c.W>>8); } break;
      case I_8266_U0_APA106_3: col = (static_cast<B_8266_U0_APA106_3*>(busPtr))->GetPixelColor(pix); break;
      case I_8266_U1_APA106_3: col = (static_cast<B_8266_U1_APA106_3*>(busPtr))->GetPixelColor(pix); break;
      case I_8266_DM_APA106_3: col = (static_cast<B_8266_DM_APA106_3*>(busPtr))->GetPixelColor(pix); break;
      case I_8266_BB_APA106_3: col = (static_cast<B_8266_BB_APA106_3*>(busPtr))->GetPixelColor(pix); break;
      case I_8266_U0_FW6_5: { RgbwwColor c = (static_cast<B_8266_U0_FW6_5*>(busPtr))->GetPixelColor(pix); col = RGBW32(c.R,c.G,c.B,max(c.WW,c.CW)); } break; // will not return original W
      case I_8266_U1_FW6_5: { RgbwwColor c = (static_cast<B_8266_U1_FW6_5*>(busPtr))->GetPixelColor(pix); col = RGBW32(c.R,c.G,c.B,max(c.WW,c.CW)); } break; // will not return original W
      case I_8266_DM_FW6_5: { RgbwwColor c = (static_cast<B_8266_DM_FW6_5*>(busPtr))->GetPixelColor(pix); col = RGBW32(c.R,c.G,c.B,max(c.WW,c.CW)); } break; // will not return original W
      case I_8266_BB_FW6_5: { RgbwwColor c = (static_cast<B_8266_BB_FW6_5*>(busPtr))->GetPixelColor(pix); col = RGBW32(c.R,c.G,c.B,max(c.WW,c.CW)); } break; // will not return original W
      case I_8266_U0_2805_5: { RgbwwColor c = (static_cast<B_8266_U0_2805_5*>(busPtr))->GetPixelColor(pix); col = RGBW32(c.R,c.G,c.B,max(c.WW,c.CW)); } break; // will not return original W
      case I_8266_U1_2805_5: { RgbwwColor c = (static_cast<B_8266_U1_2805_5*>(busPtr))->GetPixelColor(pix); col = RGBW32(c.R,c.G,c.B,max(c.WW,c.CW)); } break; // will not return original W
      case I_8266_DM_2805_5: { RgbwwColor c = (static_cast<B_8266_DM_2805_5*>(busPtr))->GetPixelColor(pix); col = RGBW32(c.R,c.G,c.B,max(c.WW,c.CW)); } break; // will not return original W
      case I_8266_BB_2805_5: { RgbwwColor c = (static_cast<B_8266_BB_2805_5*>(busPtr))->GetPixelColor(pix); col = RGBW32(c.R,c.G,c.B,max(c.WW,c.CW)); } break; // will not return original W
      case I_8266_U0_TM1914_3: col = (static_cast<B_8266_U0_TM1914_3*>(busPtr))->GetPixelColor(pix); break;
      case I_8266_U1_TM1914_3: col = (static_cast<B_8266_U1_TM1914_3*>(busPtr))->GetPixelColor(pix); break;
      case I_8266_DM_TM1914_3: col = (static_cast<B_8266_DM_TM1914_3*>(busPtr))->GetPixelColor(pix); break;
      case I_8266_BB_TM1914_3: col = (static_cast<B_8266_BB_TM1914_3*>(busPtr))->GetPixelColor(pix); break;
      case I_8266_U0_SM16825_5: { Rgbww80Color c = (static_cast<B_8266_U0_SM16825_5*>(busPtr))->GetPixelColor(pix); col = RGBW32(c.R,c.G,c.B,max(c.WW,c.CW)); } break; // will not return original W
      case I_8266_U1_SM16825_5: { Rgbww80Color c = (static_cast<B_8266_U1_SM16825_5*>(busPtr))->GetPixelColor(pix); col = RGBW32(c.R,c.G,c.B,max(c.WW,c.CW)); } break; // will not return original W
      case I_8266_DM_SM16825_5: { Rgbww80Color c = (static_cast<B_8266_DM_SM16825_5*>(busPtr))->GetPixelColor(pix); col = RGBW32(c.R,c.G,c.B,max(c.WW,c.CW)); } break; // will not return original W
      case I_8266_BB_SM16825_5: { Rgbww80Color c = (static_cast<B_8266_BB_SM16825_5*>(busPtr))->GetPixelColor(pix); col = RGBW32(c.R,c.G,c.B,max(c.WW,c.CW)); } break; // will not return original W
    #endif
    #ifdef ARDUINO_ARCH_ESP32
      // RMT buses
      case I_32_RN_NEO_3: col = (static_cast<B_32_RN_NEO_3*>(busPtr))->GetPixelColor(pix); break;
      case I_32_RN_NEO_4: col = (static_cast<B_32_RN_NEO_4*>(busPtr))->GetPixelColor(pix); break;
      case I_32_RN_400_3: col = (static_cast<B_32_RN_400_3*>(busPtr))->GetPixelColor(pix); break;
      case I_32_RN_TM1_4: col = (static_cast<B_32_RN_TM1_4*>(busPtr))->GetPixelColor(pix); break;
      case I_32_RN_TM2_3: col = (static_cast<B_32_RN_TM2_3*>(busPtr))->GetPixelColor(pix); break;
      case I_32_RN_UCS_3: { Rgb48Color c = (static_cast<B_32_RN_UCS_3*>(busPtr))->GetPixelColor(pix); col = RGBW32(c.R>>8,c.G>>8,c.B>>8,0); } break;
      case I_32_RN_UCS_4: { Rgbw64Color c = (static_cast<B_32_RN_UCS_4*>(busPtr))->GetPixelColor(pix); col = RGBW32(c.R>>8,c.G>>8,c.B>>8,c.W>>8); } break;
      case I_32_RN_APA106_3: col = (static_cast<B_32_RN_APA106_3*>(busPtr))->GetPixelColor(pix); break;
      case I_32_RN_FW6_5: { RgbwwColor c = (static_cast<B_32_RN_FW6_5*>(busPtr))->GetPixelColor(pix); col = RGBW32(c.R,c.G,c.B,max(c.WW,c.CW)); } break; // will not return original W
      case I_32_RN_2805_5: { RgbwwColor c = (static_cast<B_32_RN_2805_5*>(busPtr))->GetPixelColor(pix); col = RGBW32(c.R,c.G,c.B,max(c.WW,c.CW)); } break; // will not return original W
      case I_32_RN_TM1914_3: col = (static_cast<B_32_RN_TM1914_3*>(busPtr))->GetPixelColor(pix); break;
      case I_32_RN_SM16825_5: { Rgbww80Color c = (static_cast<B_32_RN_SM16825_5*>(busPtr))->GetPixelColor(pix); col = RGBW32(c.R/257,c.G/257,c.B/257,max(c.WW,c.CW)/257); } break; // will not return original W
      // I2S1 bus or paralell buses
      #ifndef WLED_NO_I2S1_PIXELBUS
      case I_32_I1_NEO_3: col = (useParallelI2S) ? (static_cast<B_32_I1_NEO_3P*>(busPtr))->GetPixelColor(pix) : (static_cast<B_32_I1_NEO_3*>(busPtr))->GetPixelColor(pix); break;
      case I_32_I1_NEO_4: col = (useParallelI2S) ? (static_cast<B_32_I1_NEO_4P*>(busPtr))->GetPixelColor(pix) : (static_cast<B_32_I1_NEO_4*>(busPtr))->GetPixelColor(pix); break;
      case I_32_I1_400_3: col = (useParallelI2S) ? (static_cast<B_32_I1_400_3P*>(busPtr))->GetPixelColor(pix) : (static_cast<B_32_I1_400_3*>(busPtr))->GetPixelColor(pix); break;
      case I_32_I1_TM1_4: col = (useParallelI2S) ? (static_cast<B_32_I1_TM1_4P*>(busPtr))->GetPixelColor(pix) : (static_cast<B_32_I1_TM1_4*>(busPtr))->GetPixelColor(pix); break;
      case I_32_I1_TM2_3: col = (useParallelI2S) ? (static_cast<B_32_I1_TM2_3P*>(busPtr))->GetPixelColor(pix) : (static_cast<B_32_I1_TM2_3*>(busPtr))->GetPixelColor(pix); break;
      case I_32_I1_UCS_3: { Rgb48Color c = (useParallelI2S) ? (static_cast<B_32_I1_UCS_3P*>(busPtr))->GetPixelColor(pix) : (static_cast<B_32_I1_UCS_3*>(busPtr))->GetPixelColor(pix); col = RGBW32(c.R/257,c.G/257,c.B/257,0); } break;
      case I_32_I1_UCS_4: { Rgbw64Color c = (useParallelI2S) ? (static_cast<B_32_I1_UCS_4P*>(busPtr))->GetPixelColor(pix) : (static_cast<B_32_I1_UCS_4*>(busPtr))->GetPixelColor(pix); col = RGBW32(c.R/257,c.G/257,c.B/257,c.W/257); } break;
      case I_32_I1_APA106_3: col = (useParallelI2S) ? (static_cast<B_32_I1_APA106_3P*>(busPtr))->GetPixelColor(pix) : (static_cast<B_32_I1_APA106_3*>(busPtr))->GetPixelColor(pix); break;
      case I_32_I1_FW6_5: { RgbwwColor c = (useParallelI2S) ? (static_cast<B_32_I1_FW6_5P*>(busPtr))->GetPixelColor(pix) : (static_cast<B_32_I1_FW6_5*>(busPtr))->GetPixelColor(pix); col = RGBW32(c.R,c.G,c.B,max(c.WW,c.CW)); } break; // will not return original W
      case I_32_I1_2805_5: { RgbwwColor c = (useParallelI2S) ? (static_cast<B_32_I1_2805_5P*>(busPtr))->GetPixelColor(pix) : (static_cast<B_32_I1_2805_5*>(busPtr))->GetPixelColor(pix); col = RGBW32(c.R,c.G,c.B,max(c.WW,c.CW)); } break; // will not return original W
      case I_32_I1_TM1914_3: col = (useParallelI2S) ? (static_cast<B_32_I1_TM1914_3P*>(busPtr))->GetPixelColor(pix) : (static_cast<B_32_I1_TM1914_3*>(busPtr))->GetPixelColor(pix); break;
      case I_32_I1_SM16825_5: { Rgbww80Color c = (useParallelI2S) ? (static_cast<B_32_I1_SM16825_5P*>(busPtr))->GetPixelColor(pix) : (static_cast<B_32_I1_SM16825_5*>(busPtr))->GetPixelColor(pix); col = RGBW32(c.R/257,c.G/257,c.B/257,max(c.WW,c.CW)/257); } break; // will not return original W
      #endif
      // I2S0 bus
      #ifndef WLED_NO_I2S0_PIXELBUS
      case I_32_I0_NEO_3: col = (static_cast<B_32_I0_NEO_3*>(busPtr))->GetPixelColor(pix); break;
      case I_32_I0_NEO_4: col = (static_cast<B_32_I0_NEO_4*>(busPtr))->GetPixelColor(pix); break;
      case I_32_I0_400_3: col = (static_cast<B_32_I0_400_3*>(busPtr))->GetPixelColor(pix); break;
      case I_32_I0_TM1_4: col = (static_cast<B_32_I0_TM1_4*>(busPtr))->GetPixelColor(pix); break;
      case I_32_I0_TM2_3: col = (static_cast<B_32_I0_TM2_3*>(busPtr))->GetPixelColor(pix); break;
      case I_32_I0_UCS_3: { Rgb48Color c = (static_cast<B_32_I0_UCS_3*>(busPtr))->GetPixelColor(pix); col = RGBW32(c.R/257,c.G/257,c.B/257,0); } break;
      case I_32_I0_UCS_4: { Rgbw64Color c = (static_cast<B_32_I0_UCS_4*>(busPtr))->GetPixelColor(pix); col = RGBW32(c.R/257,c.G/257,c.B/257,c.W/257); } break;
      case I_32_I0_APA106_3: col = (static_cast<B_32_I0_APA106_3*>(busPtr))->GetPixelColor(pix); break;
      case I_32_I0_FW6_5: { RgbwwColor c = (static_cast<B_32_I0_FW6_5*>(busPtr))->GetPixelColor(pix); col = RGBW32(c.R,c.G,c.B,max(c.WW,c.CW)); } break; // will not return original W
      case I_32_I0_2805_5: { RgbwwColor c = (static_cast<B_32_I0_2805_5*>(busPtr))->GetPixelColor(pix); col = RGBW32(c.R,c.G,c.B,max(c.WW,c.CW)); } break; // will not return original W
      case I_32_I0_TM1914_3: col = (static_cast<B_32_I0_TM1914_3*>(busPtr))->GetPixelColor(pix); break;
      case I_32_I0_SM16825_5: { Rgbww80Color c = (static_cast<B_32_I0_SM16825_5*>(busPtr))->GetPixelColor(pix); col = RGBW32(c.R/257,c.G/257,c.B/257,max(c.WW,c.CW)/257); } break; // will not return original W
      #endif
    #endif
      case I_HS_DOT_3: col = (static_cast<B_HS_DOT_3*>(busPtr))->GetPixelColor(pix); break;
      case I_SS_DOT_3: col = (static_cast<B_SS_DOT_3*>(busPtr))->GetPixelColor(pix); break;
      case I_HS_LPD_3: col = (static_cast<B_HS_LPD_3*>(busPtr))->GetPixelColor(pix); break;
      case I_SS_LPD_3: col = (static_cast<B_SS_LPD_3*>(busPtr))->GetPixelColor(pix); break;
      case I_HS_LPO_3: col = (static_cast<B_HS_LPO_3*>(busPtr))->GetPixelColor(pix); break;
      case I_SS_LPO_3: col = (static_cast<B_SS_LPO_3*>(busPtr))->GetPixelColor(pix); break;
      case I_HS_WS1_3: col = (static_cast<B_HS_WS1_3*>(busPtr))->GetPixelColor(pix); break;
      case I_SS_WS1_3: col = (static_cast<B_SS_WS1_3*>(busPtr))->GetPixelColor(pix); break;
      case I_HS_P98_3: col = (static_cast<B_HS_P98_3*>(busPtr))->GetPixelColor(pix); break;
      case I_SS_P98_3: col = (static_cast<B_SS_P98_3*>(busPtr))->GetPixelColor(pix); break;
    }

    // upper nibble contains W swap information
    uint8_t w = col.W;
    switch (co >> 4) {
      case 1: col.W = col.B; col.B = w; break; // swap W & B
      case 2: col.W = col.G; col.G = w; break; // swap W & G
      case 3: col.W = col.R; col.R = w; break; // swap W & R
    }
    switch (co & 0x0F) {
      //                    W               G              R               B
      default: return ((col.W << 24) | (col.G << 8) | (col.R << 16) | (col.B)); //0 = GRB, default
      case  1: return ((col.W << 24) | (col.R << 8) | (col.G << 16) | (col.B)); //1 = RGB, common for WS2811
      case  2: return ((col.W << 24) | (col.B << 8) | (col.R << 16) | (col.G)); //2 = BRG
      case  3: return ((col.W << 24) | (col.B << 8) | (col.G << 16) | (col.R)); //3 = RBG
      case  4: return ((col.W << 24) | (col.R << 8) | (col.B << 16) | (col.G)); //4 = BGR
      case  5: return ((col.W << 24) | (col.G << 8) | (col.B << 16) | (col.R)); //5 = GBR
    }
    return 0;
  }

  static void cleanup(void* busPtr, uint8_t busType) {
    if (busPtr == nullptr) return;
    switch (busType) {
      case I_NONE: break;
    #ifdef ESP8266
      case I_8266_U0_NEO_3: delete (static_cast<B_8266_U0_NEO_3*>(busPtr)); break;
      case I_8266_U1_NEO_3: delete (static_cast<B_8266_U1_NEO_3*>(busPtr)); break;
      case I_8266_DM_NEO_3: delete (static_cast<B_8266_DM_NEO_3*>(busPtr)); break;
      case I_8266_BB_NEO_3: delete (static_cast<B_8266_BB_NEO_3*>(busPtr)); break;
      case I_8266_U0_NEO_4: delete (static_cast<B_8266_U0_NEO_4*>(busPtr)); break;
      case I_8266_U1_NEO_4: delete (static_cast<B_8266_U1_NEO_4*>(busPtr)); break;
      case I_8266_DM_NEO_4: delete (static_cast<B_8266_DM_NEO_4*>(busPtr)); break;
      case I_8266_BB_NEO_4: delete (static_cast<B_8266_BB_NEO_4*>(busPtr)); break;
      case I_8266_U0_400_3: delete (static_cast<B_8266_U0_400_3*>(busPtr)); break;
      case I_8266_U1_400_3: delete (static_cast<B_8266_U1_400_3*>(busPtr)); break;
      case I_8266_DM_400_3: delete (static_cast<B_8266_DM_400_3*>(busPtr)); break;
      case I_8266_BB_400_3: delete (static_cast<B_8266_BB_400_3*>(busPtr)); break;
      case I_8266_U0_TM1_4: delete (static_cast<B_8266_U0_TM1_4*>(busPtr)); break;
      case I_8266_U1_TM1_4: delete (static_cast<B_8266_U1_TM1_4*>(busPtr)); break;
      case I_8266_DM_TM1_4: delete (static_cast<B_8266_DM_TM1_4*>(busPtr)); break;
      case I_8266_BB_TM1_4: delete (static_cast<B_8266_BB_TM1_4*>(busPtr)); break;
      case I_8266_U0_TM2_3: delete (static_cast<B_8266_U0_TM2_3*>(busPtr)); break;
      case I_8266_U1_TM2_3: delete (static_cast<B_8266_U1_TM2_3*>(busPtr)); break;
      case I_8266_DM_TM2_3: delete (static_cast<B_8266_DM_TM2_3*>(busPtr)); break;
      case I_8266_BB_TM2_3: delete (static_cast<B_8266_BB_TM2_3*>(busPtr)); break;
      case I_8266_U0_UCS_3: delete (static_cast<B_8266_U0_UCS_3*>(busPtr)); break;
      case I_8266_U1_UCS_3: delete (static_cast<B_8266_U1_UCS_3*>(busPtr)); break;
      case I_8266_DM_UCS_3: delete (static_cast<B_8266_DM_UCS_3*>(busPtr)); break;
      case I_8266_BB_UCS_3: delete (static_cast<B_8266_BB_UCS_3*>(busPtr)); break;
      case I_8266_U0_UCS_4: delete (static_cast<B_8266_U0_UCS_4*>(busPtr)); break;
      case I_8266_U1_UCS_4: delete (static_cast<B_8266_U1_UCS_4*>(busPtr)); break;
      case I_8266_DM_UCS_4: delete (static_cast<B_8266_DM_UCS_4*>(busPtr)); break;
      case I_8266_BB_UCS_4: delete (static_cast<B_8266_BB_UCS_4*>(busPtr)); break;
      case I_8266_U0_APA106_3: delete (static_cast<B_8266_U0_APA106_3*>(busPtr)); break;
      case I_8266_U1_APA106_3: delete (static_cast<B_8266_U1_APA106_3*>(busPtr)); break;
      case I_8266_DM_APA106_3: delete (static_cast<B_8266_DM_APA106_3*>(busPtr)); break;
      case I_8266_BB_APA106_3: delete (static_cast<B_8266_BB_APA106_3*>(busPtr)); break;
      case I_8266_U0_FW6_5: delete (static_cast<B_8266_U0_FW6_5*>(busPtr)); break;
      case I_8266_U1_FW6_5: delete (static_cast<B_8266_U1_FW6_5*>(busPtr)); break;
      case I_8266_DM_FW6_5: delete (static_cast<B_8266_DM_FW6_5*>(busPtr)); break;
      case I_8266_BB_FW6_5: delete (static_cast<B_8266_BB_FW6_5*>(busPtr)); break;
      case I_8266_U0_2805_5: delete (static_cast<B_8266_U0_2805_5*>(busPtr)); break;
      case I_8266_U1_2805_5: delete (static_cast<B_8266_U1_2805_5*>(busPtr)); break;
      case I_8266_DM_2805_5: delete (static_cast<B_8266_DM_2805_5*>(busPtr)); break;
      case I_8266_BB_2805_5: delete (static_cast<B_8266_BB_2805_5*>(busPtr)); break;
      case I_8266_U0_TM1914_3: delete (static_cast<B_8266_U0_TM1914_3*>(busPtr)); break;
      case I_8266_U1_TM1914_3: delete (static_cast<B_8266_U1_TM1914_3*>(busPtr)); break;
      case I_8266_DM_TM1914_3: delete (static_cast<B_8266_DM_TM1914_3*>(busPtr)); break;
      case I_8266_BB_TM1914_3: delete (static_cast<B_8266_BB_TM1914_3*>(busPtr)); break;
      case I_8266_U0_SM16825_5: delete (static_cast<B_8266_U0_SM16825_5*>(busPtr)); break;
      case I_8266_U1_SM16825_5: delete (static_cast<B_8266_U1_SM16825_5*>(busPtr)); break;
      case I_8266_DM_SM16825_5: delete (static_cast<B_8266_DM_SM16825_5*>(busPtr)); break;
      case I_8266_BB_SM16825_5: delete (static_cast<B_8266_BB_SM16825_5*>(busPtr)); break;
    #endif
    #ifdef ARDUINO_ARCH_ESP32
      // RMT buses
      case I_32_RN_NEO_3: delete (static_cast<B_32_RN_NEO_3*>(busPtr)); break;
      case I_32_RN_NEO_4: delete (static_cast<B_32_RN_NEO_4*>(busPtr)); break;
      case I_32_RN_400_3: delete (static_cast<B_32_RN_400_3*>(busPtr)); break;
      case I_32_RN_TM1_4: delete (static_cast<B_32_RN_TM1_4*>(busPtr)); break;
      case I_32_RN_TM2_3: delete (static_cast<B_32_RN_TM2_3*>(busPtr)); break;
      case I_32_RN_UCS_3: delete (static_cast<B_32_RN_UCS_3*>(busPtr)); break;
      case I_32_RN_UCS_4: delete (static_cast<B_32_RN_UCS_4*>(busPtr)); break;
      case I_32_RN_APA106_3: delete (static_cast<B_32_RN_APA106_3*>(busPtr)); break;
      case I_32_RN_FW6_5: delete (static_cast<B_32_RN_FW6_5*>(busPtr)); break;
      case I_32_RN_2805_5: delete (static_cast<B_32_RN_2805_5*>(busPtr)); break;
      case I_32_RN_TM1914_3: delete (static_cast<B_32_RN_TM1914_3*>(busPtr)); break;
      case I_32_RN_SM16825_5: delete (static_cast<B_32_RN_SM16825_5*>(busPtr)); break;
      // I2S1 bus or paralell buses
      #ifndef WLED_NO_I2S1_PIXELBUS
      case I_32_I1_NEO_3: if (useParallelI2S) delete (static_cast<B_32_I1_NEO_3P*>(busPtr)); else delete (static_cast<B_32_I1_NEO_3*>(busPtr)); break;
      case I_32_I1_NEO_4: if (useParallelI2S) delete (static_cast<B_32_I1_NEO_4P*>(busPtr)); else delete (static_cast<B_32_I1_NEO_4*>(busPtr)); break;
      case I_32_I1_400_3: if (useParallelI2S) delete (static_cast<B_32_I1_400_3P*>(busPtr)); else delete (static_cast<B_32_I1_400_3*>(busPtr)); break;
      case I_32_I1_TM1_4: if (useParallelI2S) delete (static_cast<B_32_I1_TM1_4P*>(busPtr)); else delete (static_cast<B_32_I1_TM1_4*>(busPtr)); break;
      case I_32_I1_TM2_3: if (useParallelI2S) delete (static_cast<B_32_I1_TM2_3P*>(busPtr)); else delete (static_cast<B_32_I1_TM2_3*>(busPtr)); break;
      case I_32_I1_UCS_3: if (useParallelI2S) delete (static_cast<B_32_I1_UCS_3P*>(busPtr)); else delete (static_cast<B_32_I1_UCS_3*>(busPtr)); break;
      case I_32_I1_UCS_4: if (useParallelI2S) delete (static_cast<B_32_I1_UCS_4P*>(busPtr)); else delete (static_cast<B_32_I1_UCS_4*>(busPtr)); break;
      case I_32_I1_APA106_3: if (useParallelI2S) delete (static_cast<B_32_I1_APA106_3P*>(busPtr)); else delete (static_cast<B_32_I1_APA106_3*>(busPtr)); break;
      case I_32_I1_FW6_5: if (useParallelI2S) delete (static_cast<B_32_I1_FW6_5P*>(busPtr)); else delete (static_cast<B_32_I1_FW6_5*>(busPtr)); break;
      case I_32_I1_2805_5: if (useParallelI2S) delete (static_cast<B_32_I1_2805_5P*>(busPtr)); else delete (static_cast<B_32_I1_2805_5*>(busPtr)); break;
      case I_32_I1_TM1914_3: if (useParallelI2S) delete (static_cast<B_32_I1_TM1914_3P*>(busPtr)); else delete (static_cast<B_32_I1_TM1914_3*>(busPtr)); break;
      case I_32_I1_SM16825_5: if (useParallelI2S) delete (static_cast<B_32_I1_SM16825_5P*>(busPtr)); else delete (static_cast<B_32_I1_SM16825_5*>(busPtr)); break;
      #endif
      // I2S0 bus
      #ifndef WLED_NO_I2S0_PIXELBUS
      case I_32_I0_NEO_3: delete (static_cast<B_32_I0_NEO_3*>(busPtr)); break;
      case I_32_I0_NEO_4: delete (static_cast<B_32_I0_NEO_4*>(busPtr)); break;
      case I_32_I0_400_3: delete (static_cast<B_32_I0_400_3*>(busPtr)); break;
      case I_32_I0_TM1_4: delete (static_cast<B_32_I0_TM1_4*>(busPtr)); break;
      case I_32_I0_TM2_3: delete (static_cast<B_32_I0_TM2_3*>(busPtr)); break;
      case I_32_I0_UCS_3: delete (static_cast<B_32_I0_UCS_3*>(busPtr)); break;
      case I_32_I0_UCS_4: delete (static_cast<B_32_I0_UCS_4*>(busPtr)); break;
      case I_32_I0_APA106_3: delete (static_cast<B_32_I0_APA106_3*>(busPtr)); break;
      case I_32_I0_FW6_5: delete (static_cast<B_32_I0_FW6_5*>(busPtr)); break;
      case I_32_I0_2805_5: delete (static_cast<B_32_I0_2805_5*>(busPtr)); break;
      case I_32_I0_TM1914_3: delete (static_cast<B_32_I0_TM1914_3*>(busPtr)); break;
      case I_32_I0_SM16825_5: delete (static_cast<B_32_I0_SM16825_5*>(busPtr)); break;
      #endif
    #endif
      case I_HS_DOT_3: delete (static_cast<B_HS_DOT_3*>(busPtr)); break;
      case I_SS_DOT_3: delete (static_cast<B_SS_DOT_3*>(busPtr)); break;
      case I_HS_LPD_3: delete (static_cast<B_HS_LPD_3*>(busPtr)); break;
      case I_SS_LPD_3: delete (static_cast<B_SS_LPD_3*>(busPtr)); break;
      case I_HS_LPO_3: delete (static_cast<B_HS_LPO_3*>(busPtr)); break;
      case I_SS_LPO_3: delete (static_cast<B_SS_LPO_3*>(busPtr)); break;
      case I_HS_WS1_3: delete (static_cast<B_HS_WS1_3*>(busPtr)); break;
      case I_SS_WS1_3: delete (static_cast<B_SS_WS1_3*>(busPtr)); break;
      case I_HS_P98_3: delete (static_cast<B_HS_P98_3*>(busPtr)); break;
      case I_SS_P98_3: delete (static_cast<B_SS_P98_3*>(busPtr)); break;
    }
  }

  //gives back the internal type index (I_XX_XXX_X above) for the input
  static uint8_t getI(uint8_t busType, uint8_t* pins, uint8_t num = 0) {
    if (!Bus::isDigital(busType)) return I_NONE;
    if (Bus::is2Pin(busType)) { //SPI LED chips
      bool isHSPI = false;
      #ifdef ESP8266
      if (pins[0] == P_8266_HS_MOSI && pins[1] == P_8266_HS_CLK) isHSPI = true;
      #else
      // temporary hack to limit use of hardware SPI to a single SPI peripheral (HSPI): only allow ESP32 hardware serial on segment 0
      // SPI global variable is normally linked to VSPI on ESP32 (or FSPI C3, S3)
      if (!num) isHSPI = true;
      #endif
      uint8_t t = I_NONE;
      switch (busType) {
        case TYPE_APA102:  t = I_SS_DOT_3; break;
        case TYPE_LPD8806: t = I_SS_LPD_3; break;
        case TYPE_LPD6803: t = I_SS_LPO_3; break;
        case TYPE_WS2801:  t = I_SS_WS1_3; break;
        case TYPE_P9813:   t = I_SS_P98_3; break;
        default: t=I_NONE;
      }
      if (t > I_NONE && isHSPI) t--; //hardware SPI has one smaller ID than software
      return t;
    } else {
      #ifdef ESP8266
      uint8_t offset = pins[0] -1; //for driver: 0 = uart0, 1 = uart1, 2 = dma, 3 = bitbang
      if (offset > 3) offset = 3;
      switch (busType) {
        case TYPE_WS2812_1CH_X3:
        case TYPE_WS2812_2CH_X3:
        case TYPE_WS2812_RGB:
        case TYPE_WS2812_WWA:
          return I_8266_U0_NEO_3 + offset;
        case TYPE_SK6812_RGBW:
          return I_8266_U0_NEO_4 + offset;
        case TYPE_WS2811_400KHZ:
          return I_8266_U0_400_3 + offset;
        case TYPE_TM1814:
          return I_8266_U0_TM1_4 + offset;
        case TYPE_TM1829:
          return I_8266_U0_TM2_3 + offset;
        case TYPE_UCS8903:
          return I_8266_U0_UCS_3 + offset;
        case TYPE_UCS8904:
          return I_8266_U0_UCS_4 + offset;
        case TYPE_APA106:
          return I_8266_U0_APA106_3 + offset;
        case TYPE_FW1906:
          return I_8266_U0_FW6_5 + offset;
        case TYPE_WS2805:
          return I_8266_U0_2805_5 + offset;
        case TYPE_TM1914:
          return I_8266_U0_TM1914_3 + offset;
        case TYPE_SM16825:
          return I_8266_U0_SM16825_5 + offset;
      }
      #else //ESP32
      uint8_t offset = 0; // 0 = RMT (num 1-8), 1 = I2S0 (used by Audioreactive), 2 = I2S1
      #if defined(CONFIG_IDF_TARGET_ESP32S2)
      // ESP32-S2 only has 4 RMT channels
      if (num > 4) return I_NONE;
      if (num > 3) offset = 1;  // only one I2S (use last to allow Audioreactive)
      #elif defined(CONFIG_IDF_TARGET_ESP32C3)
      // On ESP32-C3 only the first 2 RMT channels are usable for transmitting
      if (num > 1) return I_NONE;
      //if (num > 1) offset = 1; // I2S not supported yet (only 1 I2S)
      #elif defined(CONFIG_IDF_TARGET_ESP32S3)
      // On ESP32-S3 only the first 4 RMT channels are usable for transmitting
      if (num > 3) return I_NONE;
      //if (num > 3) offset = num -4; // I2S not supported yet
      #else
      // standard ESP32 has 8 RMT and 2 I2S channels
      if (useParallelI2S) {
        if (num > 16) return I_NONE;
        if (num < 8) offset = 2;  // prefer 8 parallel I2S1 channels
        if (num == 16) offset = 1;
      } else {
        if (num > 9) return I_NONE;
        if (num > 8) offset = 1;
        if (num == 0) offset = 2; // prefer I2S1 for 1st bus (less flickering but more RAM needed)
      }
      #endif
      switch (busType) {
        case TYPE_WS2812_1CH_X3:
        case TYPE_WS2812_2CH_X3:
        case TYPE_WS2812_RGB:
        case TYPE_WS2812_WWA:
          return I_32_RN_NEO_3 + offset;
        case TYPE_SK6812_RGBW:
          return I_32_RN_NEO_4 + offset;
        case TYPE_WS2811_400KHZ:
          return I_32_RN_400_3 + offset;
        case TYPE_TM1814:
          return I_32_RN_TM1_4 + offset;
        case TYPE_TM1829:
          return I_32_RN_TM2_3 + offset;
        case TYPE_UCS8903:
          return I_32_RN_UCS_3 + offset;
        case TYPE_UCS8904:
          return I_32_RN_UCS_4 + offset;
        case TYPE_APA106:
          return I_32_RN_APA106_3 + offset;
        case TYPE_FW1906:
          return I_32_RN_FW6_5 + offset;
        case TYPE_WS2805:
          return I_32_RN_2805_5 + offset;
        case TYPE_TM1914:
          return I_32_RN_TM1914_3 + offset;
        case TYPE_SM16825:
          return I_32_RN_SM16825_5 + offset;
      }
      #endif
    }
    return I_NONE;
  }
};
#endif
