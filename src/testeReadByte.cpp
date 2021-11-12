//Bibliotecas
#include <Arduino.h>
//Protótipos
unsigned long readByte(uint8_t enderecoI2C, uint8_t comando, uint8_t *byte);

void testeReadByte(uint8_t enderecoI2C, uint8_t comando) {
    double media = 0;
    int iteracoes = 100;
    unsigned long tempo = 0;
    uint8_t byte;
    Serial.println("Teste Read Byte (Comando: CAPABILITY - 0x19) \n");   

    for (int i = 0; i < iteracoes; i++)
    {        
        tempo += readByte(enderecoI2C, comando, &byte);
    }

    char mensagem[100] = "";
    media = (double)tempo / (double) iteracoes;
    sprintf(mensagem, "Byte de resposta: %Xh", byte);
    Serial.println(mensagem);

    sprintf(mensagem, "Média de duração da transação Read Byte: %.2fus.\n\n", media);
    Serial.print(mensagem);    
}

