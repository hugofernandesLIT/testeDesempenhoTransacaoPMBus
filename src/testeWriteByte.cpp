//Bibliotecas
#include <Arduino.h>
//Protótipos
unsigned long writeByte(uint8_t enderecoI2C, uint8_t comando, uint8_t byte);

void testeWriteByte(uint8_t enderecoI2C, uint8_t comando, uint8_t byte) {
    double media = 0;
    int iteracoes = 100;
    unsigned long tempo = 0;
    Serial.println("Teste Write Byte (Comando: OPERATION - 0x01) \n");   

    for (int i = 0; i < iteracoes; i++)
    {        
        tempo += writeByte(enderecoI2C, comando, byte);
    }

    char mensagem[100] = "";
    media = (double)tempo / (double) iteracoes;   
    sprintf(mensagem, "Média de duração da transação Write Byte: %.2fus.\n\n", media);
    Serial.print(mensagem);    
}

