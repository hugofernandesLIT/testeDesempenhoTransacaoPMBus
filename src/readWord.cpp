//Biblioteca
#include <Wire.h>
#include <Arduino.h>
// Função Read Word

unsigned long readWord(uint8_t enderecoI2C, uint8_t comando, uint8_t *MSB, uint8_t *LSB)
{
    int codigoErro;    
    unsigned long inicio = micros();    
    Wire.beginTransmission(enderecoI2C);
    Wire.write(comando);
    codigoErro = Wire.endTransmission(false);
    
    if (codigoErro != 0)
    {
        String erro = "Erro I²C: ";
        erro += Wire.getErrorText(codigoErro);
        Serial.println(erro);
        return 0;
    }

    Wire.requestFrom(enderecoI2C, (uint8_t) 2, (uint8_t) true);
    
    if (Wire.available())
    {
        *LSB = Wire.read();
        *MSB = Wire.read();
    }
    else
    {
        Serial.println ("Sem dados no barramento I²C.");
    }

    return micros() - inicio;
}