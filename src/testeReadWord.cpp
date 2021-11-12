//Bibliotecas
#include <Arduino.h>
//Protótipos
unsigned long readWord(uint8_t enderecoI2C, uint8_t comando, uint8_t *MSB, uint8_t *LSB);

void testeReadWord(uint8_t enderecoI2C, uint8_t comando) {
    double media = 0;
    int iteracoes = 100;
    unsigned long tempo = 0;
    uint8_t LSB, MSB;

    Serial.println("Teste Read Word (Comando: READ_VOUT - 0x8B) \n");    
    for (int i = 0; i < iteracoes; i++)
    {        
        
        tempo += readWord(enderecoI2C, comando, &MSB, &LSB);
        
    }
    char mensagem[100] = "";
    media = (double)tempo / (double) iteracoes;
    uint16_t resposta = LSB + ( MSB << 8 );
    float tensao = (float) resposta / 256;
    sprintf(mensagem, "MSB: %Xh, LSB: %Xh, Tensão = %.3fV.", MSB, LSB, tensao);
    Serial.println(mensagem);
    sprintf(mensagem, "Média de duração da transação Read Word: %.2fus.\n\n", media);
    Serial.print(mensagem);    
}

