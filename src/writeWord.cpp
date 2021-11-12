//Biblioteca
#include <Wire.h>
#include <Arduino.h>

// Função Write Word
unsigned long writeWord(uint8_t enderecoI2C, uint8_t comando, uint8_t MSB, uint8_t LSB)
{
    int codigoErro;
    unsigned long inicio = micros();
    
    Wire.beginTransmission(enderecoI2C);
    Wire.write(comando);
    Wire.write(LSB);
    Wire.write(MSB);
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