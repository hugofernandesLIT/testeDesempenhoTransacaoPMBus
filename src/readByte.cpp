//Biblioteca
#include <Wire.h>
#include <Arduino.h>

// Função Read Byte
unsigned long readByte(uint8_t enderecoI2C, uint8_t comando, uint8_t *byte)
{
    int codigoErro;
    unsigned long inicio = micros();    
    Wire.beginTransmission(enderecoI2C);
    Wire.write(comando);
    codigoErro = Wire.endTransmission((uint8_t) false);

    if (codigoErro != 0)
    {
        String erro = "Erro I²C: ";
        erro += Wire.getErrorText(codigoErro);
        Serial.println(erro);
        return 0;
    }

    Wire.requestFrom((uint8_t) enderecoI2C, (uint8_t) 1, (uint8_t) true);
    if (Wire.available())
    {
        *byte = Wire.read();
    }
    else
    {
        Serial.println ("Sem dados no barramento I²C.");
    }
    
    return micros() - inicio;  
}