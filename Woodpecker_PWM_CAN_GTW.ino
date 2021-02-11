#include <SPI.h>
#include "mcp2515_can.h"

const int SPI_CS_PIN = 9;
mcp2515_can CAN(SPI_CS_PIN); // Set CS pin                                  // Set CS pin s


int ch1; // channels
int ch2;
int ch3;
int ch4;
int ch5;
int ch6;
int ch7;

unsigned char stmp[8] = {0, 0, 0, 0, 0, 0, 0, 0};

unsigned char forward[8] = {0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char reverse[8] = {0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char threnable[8] = {0x05, 0xCC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char thrdisabl[8] = {0x05, 0xCC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

unsigned char steer20[8] = {0x20, 0x00, 0x00, 0x01, 0xF8, 0x00, 0x96, 0x4F};
unsigned char steer19[8] = {0x20, 0x00, 0x00, 0x02, 0x12, 0x00, 0x96, 0xA6};
unsigned char steer18[8] = {0x20, 0x00, 0x00, 0x02, 0x2C, 0x00, 0x96, 0x98};
unsigned char steer17[8] = {0x20, 0x00, 0x00, 0x02, 0x46, 0x00, 0x96, 0xF2};
unsigned char steer16[8] = {0x20, 0x00, 0x00, 0x02, 0x60, 0x00, 0x96, 0xD4};
unsigned char steer15[8] = {0x20, 0x00, 0x00, 0x02, 0x7A, 0x00, 0x96, 0xCE};
unsigned char steer14[8] = {0x20, 0x00, 0x00, 0x02, 0x94, 0x00, 0x96, 0x20};
unsigned char steer13[8] = {0x20, 0x00, 0x00, 0x02, 0xAE, 0x00, 0x96, 0x1A};
unsigned char steer12[8] = {0x20, 0x00, 0x00, 0x02, 0xC8, 0x00, 0x96, 0x7C};
unsigned char steer11[8] = {0x20, 0x00, 0x00, 0x02, 0xE2, 0x00, 0x96, 0x56};
unsigned char steer10[8] = {0x20, 0x00, 0x00, 0x02, 0xFC, 0x00, 0x96, 0x48};
unsigned char steer9[8] = {0x20, 0x00, 0x00, 0x03, 0x16, 0x00, 0x96, 0xA3};
unsigned char steer8[8] = {0x20, 0x00, 0x00, 0x03, 0x30, 0x00, 0x96, 0x85};
unsigned char steer7[8] = {0x20, 0x00, 0x00, 0x03, 0x4A, 0x00, 0x96, 0xFF};
unsigned char steer6[8] = {0x20, 0x00, 0x00, 0x03, 0x64, 0x00, 0x96, 0xD1};
unsigned char steer5[8] = {0x20, 0x00, 0x00, 0x03, 0x7E, 0x00, 0x96, 0xCB};
unsigned char steer4[8] = {0x20, 0x00, 0x00, 0x03, 0x98, 0x00, 0x96, 0x2D};
unsigned char steer3[8] = {0x20, 0x00, 0x00, 0x03, 0xB2, 0x00, 0x96, 0x07};
unsigned char steer2[8] = {0x20, 0x00, 0x00, 0x03, 0xCC, 0x00, 0x96, 0x79};
unsigned char steer1[8] = {0x20, 0x00, 0x00, 0x03, 0xE6, 0x00, 0x96, 0x53};
unsigned char steer0[8] = {0x20, 0x00, 0x00, 0x04, 0x00, 0x00, 0x96, 0xB2};
unsigned char steern1[8] = {0x20, 0x00, 0x00, 0x04, 0x1A, 0x00, 0x96, 0xA8};
unsigned char steern2[8] = {0x20, 0x00, 0x00, 0x04, 0x34, 0x00, 0x96, 0x86};
unsigned char steern3[8] = {0x20, 0x00, 0x00, 0x04, 0x4E, 0x00, 0x96, 0xFC};
unsigned char steern4[8] = {0x20, 0x00, 0x00, 0x04, 0x68, 0x00, 0x96, 0xDA};
unsigned char steern5[8] = {0x20, 0x00, 0x00, 0x04, 0x82, 0x00, 0x96, 0x30};
unsigned char steern6[8] = {0x20, 0x00, 0x00, 0x04, 0x9C, 0x00, 0x96, 0x2E};
unsigned char steern7[8] = {0x20, 0x00, 0x00, 0x04, 0xB6, 0x00, 0x96, 0x04};
unsigned char steern8[8] = {0x20, 0x00, 0x00, 0x04, 0xD0, 0x00, 0x96, 0x62};
unsigned char steern9[8] = {0x20, 0x00, 0x00, 0x04, 0xEA, 0x00, 0x96, 0x58};
unsigned char steern10[8] = {0x20, 0x00, 0x00, 0x05, 0x04, 0x00, 0x96, 0xB7};
unsigned char steern11[8] = {0x20, 0x00, 0x00, 0x05, 0x1E, 0x00, 0x96, 0xAD};
unsigned char steern12[8] = {0x20, 0x00, 0x00, 0x05, 0x38, 0x00, 0x96, 0x8B};
unsigned char steern13[8] = {0x20, 0x00, 0x00, 0x05, 0x52, 0x00, 0x96, 0xE1};
unsigned char steern14[8] = {0x20, 0x00, 0x00, 0x05, 0x6C, 0x00, 0x96, 0xDF};
unsigned char steern15[8] = {0x20, 0x00, 0x00, 0x05, 0x86, 0x00, 0x96, 0x35};
unsigned char steern16[8] = {0x20, 0x00, 0x00, 0x05, 0xA0, 0x00, 0x96, 0x13};
unsigned char steern17[8] = {0x20, 0x00, 0x00, 0x05, 0xBA, 0x00, 0x96, 0x09};
unsigned char steern18[8] = {0x20, 0x00, 0x00, 0x05, 0xD4, 0x00, 0x96, 0x67};
unsigned char steern19[8] = {0x20, 0x00, 0x00, 0x05, 0xEE, 0x00, 0x96, 0x5D};
unsigned char steern20[8] = {0x20, 0x00, 0x00, 0x06, 0x08, 0x00, 0x96, 0xB8};


//Accelerator 
unsigned char accel0[8] = {0x04, 0xCC, 0x3D, 0x02, 0x00, 0x00, 0x00, 0x00};
unsigned char accel1[8] = {0x05, 0xCC, 0xD9, 0x03, 0xF4, 0x01, 0x00, 0x00};
unsigned char accel2[8] = {0x05, 0xCC, 0x2D, 0x04, 0x58, 0x02, 0x00, 0x00};
unsigned char accel3[8] = {0x05, 0xCC, 0x81, 0x04, 0xBC, 0x02, 0x00, 0x00};
unsigned char accel4[8] = {0x05, 0xCC, 0xD5, 0x04, 0x20, 0x03, 0x00, 0x00};
unsigned char accel5[8] = {0x05, 0xCC, 0x29, 0x05, 0x84, 0x03, 0x00, 0x00};
unsigned char accel6[8] = {0x05, 0xCC, 0x7D, 0x05, 0xE8, 0x03, 0x00, 0x00};
unsigned char accel7[8] = {0x05, 0xCC, 0xD1, 0x05, 0x4C, 0x04, 0x00, 0x00};
unsigned char accel8[8] = {0x05, 0xCC, 0x25, 0x06, 0xB0, 0x04, 0x00, 0x00};
unsigned char accel9[8] = {0x05, 0xCC, 0x79, 0x06, 0x14, 0x05, 0x00, 0x00};
unsigned char accel10[8] = {0x05, 0xCC, 0xCD, 0x06, 0x78, 0x05, 0x00, 0x00};
unsigned char accel11[8] = {0x05, 0xCC, 0x21, 0x07, 0xDC, 0x05, 0x00, 0x00};
unsigned char accel12[8] = {0x05, 0xCC, 0x75, 0x07, 0x40, 0x06, 0x00, 0x00};
unsigned char accel13[8] = {0x05, 0xCC, 0xC9, 0x07, 0xA4, 0x06, 0x00, 0x00};
unsigned char accel14[8] = {0x05, 0xCC, 0x1D, 0x08, 0x08, 0x07, 0x00, 0x00};
unsigned char accel15[8] = {0x05, 0xCC, 0x71, 0x08, 0x6C, 0x07, 0x00, 0x00};
unsigned char accel16[8] = {0x05, 0xCC, 0xC5, 0x08, 0xD0, 0x07, 0x00, 0x00};
unsigned char accel17[8] = {0x05, 0xCC, 0x19, 0x09, 0x34, 0x08, 0x00, 0x00};
unsigned char accel18[8] = {0x05, 0xCC, 0x6D, 0x09, 0x98, 0x08, 0x00, 0x00};
unsigned char accel19[8] = {0x05, 0xCC, 0xC1, 0x09, 0xFC, 0x08, 0x00, 0x00};
unsigned char accel20[8] = {0x05, 0xCC, 0x15, 0x0A, 0x60, 0x09, 0x00, 0x00};
unsigned char accel21[8] = {0x05, 0xCC, 0x69, 0x0A, 0xC4, 0x09, 0x00, 0x00};
unsigned char accel22[8] = {0x05, 0xCC, 0xBD, 0x0A, 0x28, 0x0A, 0x00, 0x00};
unsigned char accel23[8] = {0x05, 0xCC, 0x11, 0x0B, 0x8C, 0x0A, 0x00, 0x00};
unsigned char accel24[8] = {0x05, 0xCC, 0x65, 0x0B, 0xF0, 0x0A, 0x00, 0x00};
unsigned char accel25[8] = {0x05, 0xCC, 0xB9, 0x0B, 0x54, 0x0B, 0x00, 0x00};
unsigned char accel26[8] = {0x05, 0xCC, 0x0D, 0x0C, 0xB8, 0x0B, 0x00, 0x00};
unsigned char accel27[8] = {0x05, 0xCC, 0x61, 0x0C, 0x1C, 0x0C, 0x00, 0x00};
unsigned char accel28[8] = {0x05, 0xCC, 0xB5, 0x0C, 0x80, 0x0C, 0x00, 0x00};
unsigned char accel29[8] = {0x05, 0xCC, 0x09, 0x0D, 0xE4, 0x0C, 0x00, 0x00};
unsigned char accel30[8] = {0x05, 0xCC, 0x5D, 0x0D, 0x48, 0x0D, 0x00, 0x00};
unsigned char accel31[8] = {0x05, 0xCC, 0x09, 0x0D, 0xAC, 0x0D, 0x00, 0x00};
unsigned char accel32[8] = {0x05, 0xCC, 0x5D, 0x0D, 0x10, 0x0E, 0x00, 0x00};
unsigned char accel33[8] = {0x05, 0xCC, 0x09, 0x0D, 0x74, 0x0E, 0x00, 0x00};
unsigned char accel34[8] = {0x05, 0xCC, 0x5D, 0x0D, 0xD8, 0x0E, 0x00, 0x00};
unsigned char accel35[8] = {0x05, 0xCC, 0x09, 0x0D, 0x3C, 0x0F, 0x00, 0x00};
unsigned char accel36[8] = {0x05, 0xCC, 0x09, 0x0D, 0xA0, 0x0F, 0x00, 0x00};
unsigned char accel37[8] = {0x05, 0xCC, 0x5D, 0x0D, 0x04, 0x10, 0x00, 0x00};
unsigned char accel38[8] = {0x05, 0xCC, 0x09, 0x0D, 0x68, 0x10, 0x00, 0x00};
unsigned char accel39[8] = {0x05, 0xCC, 0x5D, 0x0D, 0xCC, 0x10, 0x00, 0x00};
unsigned char accel40[8] = {0x05, 0xCC, 0x09, 0x0D, 0x30, 0x11, 0x00, 0x00};
unsigned char accel41[8] = {0x05, 0xCC, 0x09, 0x0D, 0x94, 0x11, 0x00, 0x00};
unsigned char accel42[8] = {0x05, 0xCC, 0x10, 0x0D, 0xF8, 0x11, 0x00, 0x00};
unsigned char accel43[8] = {0x05, 0xCC, 0x11, 0x0D, 0x5C, 0x12, 0x00, 0x00};
unsigned char accel44[8] = {0x05, 0xCC, 0x12, 0x0D, 0xC0, 0x12, 0x00, 0x00};
unsigned char accel45[8] = {0x05, 0xCC, 0x13, 0x0D, 0x24, 0x13, 0x00, 0x00};
unsigned char accel46[8] = {0x05, 0xCC, 0x14, 0x0D, 0x88, 0x13, 0x00, 0x00};


void setup() {
     Serial.begin(115200);
     

    while (CAN_OK != CAN.begin(CAN_500KBPS))              // init can bus : baudrate = 500k
    {
        Serial.println("CAN BUS Shield init fail");
        Serial.println(" Init CAN BUS Shield again");
        delay(100);
    }
    Serial.println("CAN BUS Shield init ok!");

  pinMode(0, INPUT); 
  pinMode(19, INPUT); 
  pinMode(3, INPUT); 
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);

  pinMode(A0,OUTPUT);
  digitalWrite(A0,LOW);
  pinMode(A1,OUTPUT);
  digitalWrite(A1,LOW);
  pinMode(A2,OUTPUT);
  digitalWrite(A2,LOW);
  pinMode(A3,OUTPUT);
  digitalWrite(A3,LOW);

}

void loop() {
  
  ch5 = pulseIn(0, HIGH, 30000); // Switch1 SF - Power ON/OFF
  ch7 = pulseIn(19, HIGH, 30000); // Switch1 SA - Ignition ON/OFF
  ch1 = pulseIn(3, HIGH, 30000); // Steering 
  ch2 = pulseIn(4, HIGH, 30000); // Acceleration
  ch3 = pulseIn(5, HIGH, 30000); // Steering2
  ch4 = pulseIn(6, HIGH, 30000); // Throttle Enable /Disable
  ch6 = pulseIn(7, HIGH, 30000); // Switch2 SG - Forward Reverse switch

//  Serial.print("Steering: "); 
//  Serial.print(ch1);        // Steering
//  Serial.print(" | ");
//  Serial.print(ch2);       //Acceleration
//  Serial.print(": Acceleration");
//  Serial.print("| Steering2: "); 
//  Serial.print(ch3); 
//  Serial.print("| ThrottleEnable: "); 
//  Serial.print(ch4); 
//  Serial.print("| SW1: "); 
//  Serial.print(ch5); 
//  Serial.print("| SW3: "); 
//  Serial.println(ch7); 

 
  if (ch4 > 980 && ch4 < 1105) {CAN.sendMsgBuf(0x053, 1, 8, thrdisabl);Serial.println("Thr_Disable");};
  if (ch4 > 1900 && ch4 < 2100) {CAN.sendMsgBuf(0x052, 1, 8, threnable);Serial.println("Thr_Enable");};
 
  // if (ch2 > 1463 && ch2 < 2043) CAN.sendMsgBuf(0x030, 0, 8, forward);
//Serial.println("{UI|SET|Item.Text=trackbars, progress bars}");
  if (ch1 > 980 && ch1 < 1105) {CAN.sendMsgBuf(0x469, 0, 8, steern20);Serial.println(-20);};
  if (ch1 > 1106 && ch1 < 1125) {CAN.sendMsgBuf(0x469, 0, 8, steern19);Serial.println(-19);};
  if (ch1 > 1126 && ch1 < 1145) {CAN.sendMsgBuf(0x469, 0, 8, steern18);Serial.println(-18);};
  if (ch1 > 1146 && ch1 < 1165) {CAN.sendMsgBuf(0x469, 0, 8, steern17);Serial.println(-17);};
  if (ch1 > 1166 && ch1 < 1185) {CAN.sendMsgBuf(0x469, 0, 8, steern16);Serial.println(-16);};
  if (ch1 > 1186 && ch1 < 1205) {CAN.sendMsgBuf(0x469, 0, 8, steern15);Serial.println(-15);};
  if (ch1 > 1206 && ch1 < 1225) {CAN.sendMsgBuf(0x469, 0, 8, steern14);Serial.println(-14);};
  if (ch1 > 1226 && ch1 < 1245) {CAN.sendMsgBuf(0x469, 0, 8, steern13);Serial.println(-13);};
  if (ch1 > 1246 && ch1 < 1265) {CAN.sendMsgBuf(0x469, 0, 8, steern12);Serial.println(-12);};
  if (ch1 > 1266 && ch1 < 1285) {CAN.sendMsgBuf(0x469, 0, 8, steern11);Serial.println(-11);};
  if (ch1 > 1286 && ch1 < 1305) {CAN.sendMsgBuf(0x469, 0, 8, steern10);Serial.println(-10);};
  if (ch1 > 1306 && ch1 < 1325) {CAN.sendMsgBuf(0x469, 0, 8, steern9);Serial.println(-9);};
  if (ch1 > 1326 && ch1 < 1345) {CAN.sendMsgBuf(0x469, 0, 8, steern8);Serial.println(-8);};
  if (ch1 > 1346 && ch1 < 1365) {CAN.sendMsgBuf(0x469, 0, 8, steern7);Serial.println(-7);};
  if (ch1 > 1366 && ch1 < 1385) {CAN.sendMsgBuf(0x469, 0, 8, steern6);Serial.println(-6);};
  if (ch1 > 1386 && ch1 < 1405) {CAN.sendMsgBuf(0x469, 0, 8, steern5);Serial.println(-5);};
  if (ch1 > 1406 && ch1 < 1425) {CAN.sendMsgBuf(0x469, 0, 8, steern4);Serial.println(-4);};
  if (ch1 > 1426 && ch1 < 1445) {CAN.sendMsgBuf(0x469, 0, 8, steern3);Serial.println(-3);};
  if (ch1 > 1446 && ch1 < 1465) {CAN.sendMsgBuf(0x469, 0, 8, steern2);Serial.println(-2);};
  if (ch1 > 1466 && ch1 < 1485) {CAN.sendMsgBuf(0x469, 0, 8, steern1);Serial.println(-1);};
  if (ch1 > 1486 && ch1 < 1505) {CAN.sendMsgBuf(0x469, 0, 8, steer0);Serial.println(0);};
  if (ch1 > 1506 && ch1 < 1525) {CAN.sendMsgBuf(0x469, 0, 8, steer1);Serial.println(1);};
  if (ch1 > 1526 && ch1 < 1545) {CAN.sendMsgBuf(0x469, 0, 8, steer2);Serial.println(2);};
  if (ch1 > 1546 && ch1 < 1565) {CAN.sendMsgBuf(0x469, 0, 8, steer3);Serial.println(3);};
  if (ch1 > 1566 && ch1 < 1585) {CAN.sendMsgBuf(0x469, 0, 8, steer4);Serial.println(4);};
  if (ch1 > 1586 && ch1 < 1605) {CAN.sendMsgBuf(0x469, 0, 8, steer5);Serial.println(5);};
  if (ch1 > 1606 && ch1 < 1625) {CAN.sendMsgBuf(0x469, 0, 8, steer6);Serial.println(6);};
  if (ch1 > 1626 && ch1 < 1645) {CAN.sendMsgBuf(0x469, 0, 8, steer7);Serial.println(7);};
  if (ch1 > 1646 && ch1 < 1665) {CAN.sendMsgBuf(0x469, 0, 8, steer8);Serial.println(8);};
  if (ch1 > 1666 && ch1 < 1685) {CAN.sendMsgBuf(0x469, 0, 8, steer9);Serial.println(9);};
  if (ch1 > 1686 && ch1 < 1705) {CAN.sendMsgBuf(0x469, 0, 8, steer10);Serial.println(10);};
  if (ch1 > 1706 && ch1 < 1725) {CAN.sendMsgBuf(0x469, 0, 8, steer11);Serial.println(11);};
  if (ch1 > 1726 && ch1 < 1745) {CAN.sendMsgBuf(0x469, 0, 8, steer12);Serial.println(12);};
  if (ch1 > 1746 && ch1 < 1765) {CAN.sendMsgBuf(0x469, 0, 8, steer13);Serial.println(13);};
  if (ch1 > 1766 && ch1 < 1785) {CAN.sendMsgBuf(0x469, 0, 8, steer14);Serial.println(14);};
  if (ch1 > 1786 && ch1 < 1805) {CAN.sendMsgBuf(0x469, 0, 8, steer15);Serial.println(15);};
  if (ch1 > 1806 && ch1 < 1825) {CAN.sendMsgBuf(0x469, 0, 8, steer16);Serial.println(16);};
  if (ch1 > 1826 && ch1 < 1845) {CAN.sendMsgBuf(0x469, 0, 8, steer17);Serial.println(17);};
  if (ch1 > 1846 && ch1 < 1865) {CAN.sendMsgBuf(0x469, 0, 8, steer18);Serial.println(18);};
  if (ch1 > 1866 && ch1 < 1885) {CAN.sendMsgBuf(0x469, 0, 8, steer19);Serial.println(19);};
  if (ch1 > 1886 && ch1 < 2005) {CAN.sendMsgBuf(0x469, 0, 8, steer19);Serial.println(20);};

  if (ch3 > 980 && ch3 < 1105) {CAN.sendMsgBuf(0x369, 0, 8, steern20);Serial.println("R-20");};
  if (ch3 > 1106 && ch3 < 1125) {CAN.sendMsgBuf(0x369, 0, 8, steern19);Serial.println("R-19");};
  if (ch3 > 1126 && ch3 < 1145) {CAN.sendMsgBuf(0x369, 0, 8, steern18);Serial.println("R-18");};
  if (ch3 > 1146 && ch3 < 1165) {CAN.sendMsgBuf(0x369, 0, 8, steern17);Serial.println("R-17");};
  if (ch3 > 1166 && ch3 < 1185) {CAN.sendMsgBuf(0x369, 0, 8, steern16);Serial.println("R-16");};
  if (ch3 > 1186 && ch3 < 1205) {CAN.sendMsgBuf(0x369, 0, 8, steern15);Serial.println("R-15");};
  if (ch3 > 1206 && ch3 < 1225) {CAN.sendMsgBuf(0x369, 0, 8, steern14);Serial.println("R-14");};
  if (ch3 > 1226 && ch3 < 1245) {CAN.sendMsgBuf(0x369, 0, 8, steern13);Serial.println("R-13");};
  if (ch3 > 1246 && ch3 < 1265) {CAN.sendMsgBuf(0x369, 0, 8, steern12);Serial.println("R-12");};
  if (ch3 > 1266 && ch3 < 1285) {CAN.sendMsgBuf(0x369, 0, 8, steern11);Serial.println("R-11");};
  if (ch3 > 1286 && ch3 < 1305) {CAN.sendMsgBuf(0x369, 0, 8, steern10);Serial.println("R-10");};
  if (ch3 > 1306 && ch3 < 1325) {CAN.sendMsgBuf(0x369, 0, 8, steern9);Serial.println("R-9");};
  if (ch3 > 1326 && ch3 < 1345) {CAN.sendMsgBuf(0x369, 0, 8, steern8);Serial.println("R-8");};
  if (ch3 > 1346 && ch3 < 1365) {CAN.sendMsgBuf(0x369, 0, 8, steern7);Serial.println("R-7");};
  if (ch3 > 1366 && ch3 < 1385) {CAN.sendMsgBuf(0x369, 0, 8, steern6);Serial.println("R-6");};
  if (ch3 > 1386 && ch3 < 1405) {CAN.sendMsgBuf(0x369, 0, 8, steern5);Serial.println("R-5");};
  if (ch3 > 1406 && ch3 < 1425) {CAN.sendMsgBuf(0x369, 0, 8, steern4);Serial.println("R-4");};
  if (ch3 > 1426 && ch3 < 1445) {CAN.sendMsgBuf(0x369, 0, 8, steern3);Serial.println("R-3");};
  if (ch3 > 1446 && ch3 < 1465) {CAN.sendMsgBuf(0x369, 0, 8, steern2);Serial.println("R-2");};
  if (ch3 > 1466 && ch3 < 1485) {CAN.sendMsgBuf(0x369, 0, 8, steern1);Serial.println("R-1");};
  if (ch3 > 1486 && ch3 < 1505) {CAN.sendMsgBuf(0x369, 0, 8, steer0);Serial.println("R0");};
  if (ch3 > 1506 && ch3 < 1525) {CAN.sendMsgBuf(0x369, 0, 8, steer1);Serial.println("R1");};
  if (ch3 > 1526 && ch3 < 1545) {CAN.sendMsgBuf(0x369, 0, 8, steer2);Serial.println("R2");};
  if (ch3 > 1546 && ch3 < 1565) {CAN.sendMsgBuf(0x369, 0, 8, steer3);Serial.println("R3");};
  if (ch3 > 1566 && ch3 < 1585) {CAN.sendMsgBuf(0x369, 0, 8, steer4);Serial.println("R4");};
  if (ch3 > 1586 && ch3 < 1605) {CAN.sendMsgBuf(0x369, 0, 8, steer5);Serial.println("R5");};
  if (ch3 > 1606 && ch3 < 1625) {CAN.sendMsgBuf(0x369, 0, 8, steer6);Serial.println("R6");};
  if (ch3 > 1626 && ch3 < 1645) {CAN.sendMsgBuf(0x369, 0, 8, steer7);Serial.println("R7");};
  if (ch3 > 1646 && ch3 < 1665) {CAN.sendMsgBuf(0x369, 0, 8, steer8);Serial.println("R8");};
  if (ch3 > 1666 && ch3 < 1685) {CAN.sendMsgBuf(0x369, 0, 8, steer9);Serial.println("R9");};
  if (ch3 > 1686 && ch3 < 1705) {CAN.sendMsgBuf(0x369, 0, 8, steer10);Serial.println("R10");};
  if (ch3 > 1706 && ch3 < 1725) {CAN.sendMsgBuf(0x369, 0, 8, steer11);Serial.println("R11");};
  if (ch3 > 1726 && ch3 < 1745) {CAN.sendMsgBuf(0x369, 0, 8, steer12);Serial.println("R12");};
  if (ch3 > 1746 && ch3 < 1765) {CAN.sendMsgBuf(0x369, 0, 8, steer13);Serial.println("R13");};
  if (ch3 > 1766 && ch3 < 1785) {CAN.sendMsgBuf(0x369, 0, 8, steer14);Serial.println("R14");};
  if (ch3 > 1786 && ch3 < 1805) {CAN.sendMsgBuf(0x369, 0, 8, steer15);Serial.println("R15");};
  if (ch3 > 1806 && ch3 < 1825) {CAN.sendMsgBuf(0x369, 0, 8, steer16);Serial.println("R16");};
  if (ch3 > 1826 && ch3 < 1845) {CAN.sendMsgBuf(0x369, 0, 8, steer17);Serial.println("R17");};
  if (ch3 > 1846 && ch3 < 1865) {CAN.sendMsgBuf(0x369, 0, 8, steer18);Serial.println("R18");};
  if (ch3 > 1866 && ch3 < 1885) {CAN.sendMsgBuf(0x369, 0, 8, steer19);Serial.println("R19");};
  if (ch3 > 1886 && ch3 < 2005) {CAN.sendMsgBuf(0x369, 0, 8, steer19);Serial.println("R20");};

if (ch2 > 950 && ch2 < 1011){ CAN.sendMsgBuf(0x062, 1, 8, accel1);Serial.println("TH1");};
if (ch2 > 1012 && ch2 < 1033){ CAN.sendMsgBuf(0x062, 1, 8, accel2);Serial.println("TH2");};
if (ch2 > 1034 && ch2 < 1055){ CAN.sendMsgBuf(0x062, 1, 8, accel3);Serial.println("TH3");};
if (ch2 > 1056 && ch2 < 1077){ CAN.sendMsgBuf(0x062, 1, 8, accel4);Serial.println("TH4");};
if (ch2 > 1078 && ch2 < 1099){ CAN.sendMsgBuf(0x062, 1, 8, accel5);Serial.println("TH5");};
if (ch2 > 1100 && ch2 < 1121){ CAN.sendMsgBuf(0x062, 1, 8, accel6);Serial.println("TH6");};
if (ch2 > 1122 && ch2 < 1143){ CAN.sendMsgBuf(0x062, 1, 8, accel7);Serial.println("TH7");};
if (ch2 > 1144 && ch2 < 1165){ CAN.sendMsgBuf(0x062, 1, 8, accel8);Serial.println("TH8");};
if (ch2 > 1166 && ch2 < 1187){ CAN.sendMsgBuf(0x062, 1, 8, accel9);Serial.println("TH9");};
if (ch2 > 1188 && ch2 < 1209){ CAN.sendMsgBuf(0x062, 1, 8, accel10);Serial.println("TH10");};
if (ch2 > 1210 && ch2 < 1231){ CAN.sendMsgBuf(0x062, 1, 8, accel11);Serial.println("TH11");};
if (ch2 > 1232 && ch2 < 1253){ CAN.sendMsgBuf(0x062, 1, 8, accel12);Serial.println("TH12");};
if (ch2 > 1254 && ch2 < 1275){ CAN.sendMsgBuf(0x062, 1, 8, accel13);Serial.println("TH13");};
if (ch2 > 1276 && ch2 < 1297){ CAN.sendMsgBuf(0x062, 1, 8, accel14);Serial.println("TH14");};
if (ch2 > 1298 && ch2 < 1319){ CAN.sendMsgBuf(0x062, 1, 8, accel15);Serial.println("TH15");};
if (ch2 > 1320 && ch2 < 1341){ CAN.sendMsgBuf(0x062, 1, 8, accel16);Serial.println("TH16");};
if (ch2 > 1342 && ch2 < 1363){ CAN.sendMsgBuf(0x062, 1, 8, accel17);Serial.println("TH17");};
if (ch2 > 1364 && ch2 < 1385){ CAN.sendMsgBuf(0x062, 1, 8, accel18);Serial.println("TH18");};
if (ch2 > 1386 && ch2 < 1407){ CAN.sendMsgBuf(0x062, 1, 8, accel19);Serial.println("TH19");};
if (ch2 > 1408 && ch2 < 1429){ CAN.sendMsgBuf(0x062, 1, 8, accel20);Serial.println("TH20");};
if (ch2 > 1430 && ch2 < 1451){ CAN.sendMsgBuf(0x062, 1, 8, accel21);Serial.println("TH21");};
if (ch2 > 1452 && ch2 < 1473){ CAN.sendMsgBuf(0x062, 1, 8, accel22);Serial.println("TH22");};
if (ch2 > 1474 && ch2 < 1495){ CAN.sendMsgBuf(0x062, 1, 8, accel23);Serial.println("TH23");};
if (ch2 > 1496 && ch2 < 1517){ CAN.sendMsgBuf(0x062, 1, 8, accel24);Serial.println("TH24");};
if (ch2 > 1518 && ch2 < 1539){ CAN.sendMsgBuf(0x062, 1, 8, accel25);Serial.println("TH25");};
if (ch2 > 1540 && ch2 < 1561){ CAN.sendMsgBuf(0x062, 1, 8, accel26);Serial.println("TH26");};
if (ch2 > 1562 && ch2 < 1583){ CAN.sendMsgBuf(0x062, 1, 8, accel27);Serial.println("TH27");};
if (ch2 > 1584 && ch2 < 1605){ CAN.sendMsgBuf(0x062, 1, 8, accel28);Serial.println("TH28");};
if (ch2 > 1606 && ch2 < 1627){ CAN.sendMsgBuf(0x062, 1, 8, accel29);Serial.println("TH29");};
if (ch2 > 1628 && ch2 < 1649){ CAN.sendMsgBuf(0x062, 1, 8, accel30);Serial.println("TH30");};
if (ch2 > 1650 && ch2 < 1671){ CAN.sendMsgBuf(0x062, 1, 8, accel31);Serial.println("TH31");};
if (ch2 > 1672 && ch2 < 1693){ CAN.sendMsgBuf(0x062, 1, 8, accel32);Serial.println("TH32");};
if (ch2 > 1694 && ch2 < 1715){ CAN.sendMsgBuf(0x062, 1, 8, accel33);Serial.println("TH33");};
if (ch2 > 1716 && ch2 < 1737){ CAN.sendMsgBuf(0x062, 1, 8, accel34);Serial.println("TH34");};
if (ch2 > 1738 && ch2 < 1759){ CAN.sendMsgBuf(0x062, 1, 8, accel35);Serial.println("TH35");};
if (ch2 > 1760 && ch2 < 1781){ CAN.sendMsgBuf(0x062, 1, 8, accel36);Serial.println("TH36");};
if (ch2 > 1782 && ch2 < 1803){ CAN.sendMsgBuf(0x062, 1, 8, accel37);Serial.println("TH37");};
if (ch2 > 1804 && ch2 < 1825){ CAN.sendMsgBuf(0x062, 1, 8, accel38);Serial.println("TH38");};
if (ch2 > 1826 && ch2 < 1847){ CAN.sendMsgBuf(0x062, 1, 8, accel39);Serial.println("TH39");};
if (ch2 > 1848 && ch2 < 1869){ CAN.sendMsgBuf(0x062, 1, 8, accel40);Serial.println("TH40");};
if (ch2 > 1870 && ch2 < 1891){ CAN.sendMsgBuf(0x062, 1, 8, accel41);Serial.println("TH41");};
if (ch2 > 1892 && ch2 < 1913){ CAN.sendMsgBuf(0x062, 1, 8, accel42);Serial.println("TH42");};
if (ch2 > 1914 && ch2 < 1935){ CAN.sendMsgBuf(0x062, 1, 8, accel43);Serial.println("TH43");};
if (ch2 > 1936 && ch2 < 1957){ CAN.sendMsgBuf(0x062, 1, 8, accel44);Serial.println("TH44");};
if (ch2 > 1958 && ch2 < 1979){ CAN.sendMsgBuf(0x062, 1, 8, accel45);Serial.println("TH45");};
if (ch2 > 1980 && ch2 < 2100){ CAN.sendMsgBuf(0x062, 1, 8, accel46);Serial.println("TH46");};

        if ((ch5 >=1950) && (ch5<= 2050)){
          digitalWrite(A0,HIGH);
         Serial.println("CH5 Power ON");
              } 
         else {
            digitalWrite(A0,LOW);
           Serial.println("CH5 Power OFF");
               }

         if ((ch7 >=1950) && (ch7<= 2050)){
          digitalWrite(A3,HIGH);
         Serial.println("CH7 Power ON");
              } 
         else {
            digitalWrite(A3,LOW);
           Serial.println("CH7 Power OFF");
               }      
          
          if ((ch6 >=950) && (ch6<= 1000)){
         digitalWrite(A1,HIGH);
          Serial.println("CH6 Forward ON");
              } 
          else if ((ch6 >=1950) && (ch6<= 2050)){
         digitalWrite(A2,HIGH);
         Serial.println("CH6 Reverse ON");
               }     
         else {
            digitalWrite(A1,LOW);
            digitalWrite(A2,LOW);
           Serial.println("CH6 FW/REW OFF");
              }


    delay(50);                       // send data per 20ms
  
}
