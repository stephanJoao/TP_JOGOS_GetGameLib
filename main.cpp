#include <iostream>
#include<stdlib.h>
#include <time.h>
#include <string.h>
#include "Base.h"


using namespace std;

int main()
{
    inicializar();

    criarInstancia();
    colocarEscalaInstancia(0, 0.5);
    criarAnimacao(100, 0, "texturas/nave.png");

    int inimigos[20];
    for(int i = 0; i < 20; i++)
    {
        inimigos[i] = criarInstancia();
        colocarEscalaInstancia(inimigos[i], 0.5);
        virarSpriteYInstancia(inimigos[i]);
        colocarInstanciaPosicao(inimigos[i], -50, -50);
        criarAnimacao(100, inimigos[i], "texturas/nave.png");
    }

    int tiros[20];
    for(int i = 0; i < 20; i++)
    {
        tiros[i] = criarInstancia();
        colocarEscalaInstancia(tiros[i], 0.2);
        colocarInstanciaPosicao(tiros[i], -50, -50);
        criarAnimacao(100, tiros[i], "texturas/tiro.png");
    }

    //GAME LOOP
    while(janelaAberta())
    {

        atualiza();
    }

    return 0;
}
