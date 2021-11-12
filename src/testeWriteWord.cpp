//Bibliotecas
#include <Arduino.h>
//Protótipos
unsigned long writeWord(uint8_t enderecoI2C, uint8_t comando, uint8_t MSB, uint8_t LSB);

void testeWriteWord(uint8_t enderecoI2C, uint8_t comando, uint8_t MSB, uint8_t LSB) {
    double media = 0;
    int iteracoes = 100;
    unsigned long tempo = 0;
    Serial.println("Teste Write Word (Comando: VOUT_MAX - 0x24) \n");   

    for (int i = 0; i < iteracoes; i++)
    {        
        tempo += writeWord(enderecoI2C, comando, MSB, LSB);
    }

    char mensagem[100] = "";
    media = (double)tempo / (double) iteracoes;   
    sprintf(mensagem, "Média de duração da transação Write Word: %.2fus.\n\n", media);
    Serial.print(mensagem);    
}
