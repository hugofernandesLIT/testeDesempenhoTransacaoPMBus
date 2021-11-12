//Bibliotecas
#include <Arduino.h>

//Protótipos
unsigned long sendByte(uint8_t enderecoI2C, uint8_t comando);

//Função Teste Send Byte
void testeSendByte(uint8_t enderecoI2C, uint8_t comando)
{
    
    double media = 0;
    int iteracoes = 100;
    unsigned long tempo = 0;

    Serial.println("\nTeste Send Byte (Comando CLEAR_FAULTS 0x03) \n");

    for (int i = 0; i < iteracoes; i++)
    {
        tempo += sendByte(enderecoI2C, comando);
    }
    
    media = (double) tempo/(double) iteracoes;
    char mensagem[100] = "";
    sprintf(mensagem, "Média de duração da transação Send Byte: %.2fus.\n\n", media);
    Serial.print(mensagem);
}
