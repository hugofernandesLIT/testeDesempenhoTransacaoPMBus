//Biblioteca
#include <Wire.h>

// Função Send Byte
unsigned long sendByte(uint8_t enderecoI2C, uint8_t comando)
{
    int codigoErro;
    unsigned long inicio = micros();   

    Wire.beginTransmission(enderecoI2C);
    Wire.write(comando);
    codigoErro = Wire.endTransmission((uint8_t)true);

    if (codigoErro != 0)
    {
        String erro = "Erro I²C: ";
        erro += Wire.getErrorText(codigoErro);
        return 0;
    }
    
    return micros() - inicio;  
}