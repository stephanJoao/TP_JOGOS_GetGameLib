#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Base.h"


using namespace std;

int main()
{
    inicializar(530, 800);

    criarInstancia();
    criarAnimacao(100, 0, "texturas/raquete.png");
    criarInstancia();
    criarAnimacao(100, 1, "texturas/raquete.png");
    criarInstancia();
    criarAnimacao(100, 2, "texturas/bola.png");
    float velocidadeX = 1.5, velocidadeY = 1.5;

    colocarInstanciaPosicao(0, 30 , 150);
    colocarInstanciaPosicao(1, 770, 500);
    colocarInstanciaPosicao(2, 400, 300);

    //GAME LOOP
    while(janelaAberta())
    {
        //MOVIMENTACAO JOGADOR
        if(pressionarTecla(TECLA_CIMA))
            moverInstancia(0, 0, -1.2);
        if(pressionarTecla(TECLA_BAIXO))
            moverInstancia(0, 0, 1.2);

        //MOVIMENTACAO ADVERSARIO
        if(retornaPosicaoInstanciaY(2) > retornaPosicaoInstanciaY(1))
            moverInstancia(1, 0, 1.2);
        else
            moverInstancia(1, 0, -1.2);

        //MOVIMENTACAO BOLA
        if(retornaPosicaoInstanciaX(2) > 800 || retornaPosicaoInstanciaX(2) < 0)
            velocidadeX *= -1;
        if(retornaPosicaoInstanciaY(2) > 530 || retornaPosicaoInstanciaY(2) < 0)
            velocidadeY *= -1;
        if(analisaColisaoInstancias(0, 2) || analisaColisaoInstancias(1, 2))
            velocidadeX *= -1;
        moverInstancia(2, velocidadeX, velocidadeY);

        atualiza();
    }

    return 0;
}
