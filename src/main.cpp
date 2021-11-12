//Bibliotecas

#include <Arduino.h>
#include <Wire.h>
//Protótipos

unsigned long sendByte(uint8_t enderecoI2C, uint8_t comando);
unsigned long  writeByte(uint8_t enderecoI2C, uint8_t comando, uint8_t byte);
unsigned long  writeWord(uint8_t enderecoI2C, uint8_t comando, uint8_t MSB, uint8_t LSB);
unsigned long  readByte(uint8_t enderecoI2C, uint8_t comando, uint8_t *byte);
unsigned long readWord(uint8_t enderecoI2C, uint8_t comando, uint8_t *MSB, uint8_t *LSB);
void  testeSendByte(uint8_t enderecoI2C, uint8_t comando);
void  testeWriteByte(uint8_t enderecoI2C, uint8_t comando, uint8_t byte);
void  testeWriteWord(uint8_t enderecoI2C, uint8_t comando, uint8_t MSB, uint8_t LSB);
void  testeReadByte(uint8_t enderecoI2C, uint8_t comando);
void  testeReadWord(uint8_t enderecoI2C, uint8_t comando);

// Constantes

const uint8_t g_enderecoI2C = 0X40;
const uint8_t g_readWordComm = 0X8B;
const uint8_t g_sendbyteComm = 0x03;
const uint8_t g_readByteComm = 0X19;
const uint8_t g_writeByteComm = 0X01;
const uint8_t g_writeWordComm = 0X24;
const uint8_t g_writeByte = 0x80;
const uint8_t g_writeWordLSB = 0x00;
const uint8_t g_writeWordMSB = 0x06;


void setup() {
  Serial.begin(115200);  
  Wire.begin();  
}

void loop() {
  testeSendByte(g_enderecoI2C, g_sendbyteComm);
  testeWriteByte(g_enderecoI2C, g_writeByteComm, g_writeByte);
  testeWriteWord(g_enderecoI2C, g_writeWordComm, g_writeWordMSB, g_writeWordLSB);
  testeReadByte(g_enderecoI2C, g_readByteComm);
  testeReadWord(g_enderecoI2C, g_readWordComm);  
  delay(120000);
}

