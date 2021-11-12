//Biblioteca
#include <Wire.h>
#include <Arduino.h>

// Função Write Byte
unsigned long writeByte(uint8_t enderecoI2C, uint8_t comando, uint8_t byte)
{
    int codigoErro;
    unsigned long inicio = micros();
    Wire.beginTransmission(enderecoI2C);
    Wire.write(comando);
    Wire.write(byte);
    codigoErro = Wire.endTransmission((uint8_t)true);

    if (codigoErro != 0)
    {
        String erro = "Erro I²C: ";
        erro += Wire.getErrorText(codigoErro);
        Serial.println(erro);
        return 0;
    }

    return micros() - inicio;  
}