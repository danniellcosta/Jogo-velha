#include <iostream>
#include <string>
#include <stdlib.h>
#include <new>

using namespace std;

void menu();

void iniciaTabuleiro(char tabuleiro[3][3])
{

    int linhas, colunas;

    for (linhas = 0; linhas < 3; linhas++)
    {
        for (colunas = 0; colunas < 3; colunas++)
        {
            tabuleiro[linhas][colunas] = '-';
        }
    }
}

void exibeTabuleiro(char tabuleiro[3][3])
{
    int linhas, colunas;

    cout << "\n";

    for (linhas = 0; linhas < 3; linhas++)
    {
        for (colunas = 0; colunas < 3; colunas++)
        {
            cout << tabuleiro[linhas][colunas];
        }
        cout << "\n";
    }
}

void exibeInstrucao()
{

    cout << "\nMapa de Posicoes: ";
    cout << "\n 7 | 8 | 9";
    cout << "\n 4 | 5 | 6";
    cout << "\n 1 | 2 | 3";
}

int verificaVencedor(char tabuleiro[3][3])
{

    int linhas, colunas;

    for (linhas = 0; linhas < 3; linhas++)
    {
        if (tabuleiro[linhas][0] == 'X' && tabuleiro[linhas][0] == tabuleiro[linhas][1] && tabuleiro[linhas][1] == tabuleiro[linhas][2])
        {

            return 1;
        }
        else if (tabuleiro[linhas][0] == 'O' && tabuleiro[linhas][0] == tabuleiro[linhas][1] && tabuleiro[linhas][1] == tabuleiro[linhas][2])
        {

            return 2;
        }
    }

    for (colunas = 0; colunas < 3; colunas++)
    {
        if (tabuleiro[0][colunas] == 'X' && tabuleiro[0][colunas] == tabuleiro[1][colunas] && tabuleiro[1][colunas] == tabuleiro[2][colunas])
        {

            return 1;
        }
        else if (tabuleiro[0][colunas] == 'O' && tabuleiro[0][colunas] == tabuleiro[1][colunas] && tabuleiro[1][colunas] == tabuleiro[2][colunas])
        {

            return 2;
        }
    }

    if (tabuleiro[0][0] != '-' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2])
    {
        if (tabuleiro[0][0] == 'X')
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }

    if (tabuleiro[0][2] != '-' && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0])
    {
        if (tabuleiro[0][2] == 'X')
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
}

void jogar(string nomeJogador1, string nomeJogador2, int pontuacaoJogador1, int pontuacaoJogador2)
{

    string nomeJogaorAtual;
    char tabuleiro[3][3];
    int linhaJogada, colunaJogada, jogadaJogador;
    int estado = 1;
    int turno = 1;
    int rodada = 0;
    int reiniciar;
    bool posicaoJogada;

    iniciaTabuleiro(tabuleiro);

    while (rodada < 9 && estado == 1)
    {
        system("cls");

        cout << "\nRodada: " << rodada + 1 << "\n";
        cout << "Pontuacao: " << nomeJogador1 << " " << pontuacaoJogador1 << " x " << pontuacaoJogador2 << " " << nomeJogador2;
        
        exibeTabuleiro(tabuleiro);
        exibeInstrucao();

        if (turno == 1)
        {
            nomeJogaorAtual = nomeJogador1;
        }
        else
        {
            nomeJogaorAtual = nomeJogador2;
        }

        posicaoJogada = false;

        int posicoes[9][2]{{2, 0}, {2, 1}, {2, 2}, {1, 0}, {1, 1}, {1, 2}, {0, 0}, {0, 1}, {0, 2}};

        while (posicaoJogada == false)
        {

            cout << "\n" << nomeJogaorAtual << " Digite um posicao conforme o mapa acima: ";
            cin >> jogadaJogador;

            linhaJogada = posicoes[jogadaJogador - 1][0];
            colunaJogada = posicoes[jogadaJogador - 1][1];

            cout << "\n";

            if (tabuleiro[linhaJogada][colunaJogada] == '-')
            {

                posicaoJogada = true;

                if (turno == 1)
                {
                    tabuleiro[linhaJogada][colunaJogada] = 'X';

                    turno = 2;
                }
                else
                {
                    tabuleiro[linhaJogada][colunaJogada] = 'O';

                    turno = 1;
                }
            }
        }

        if (verificaVencedor(tabuleiro) == 1)
        {
            cout << "Parabens " << nomeJogador1 << " Voce Venceu!!!";
            pontuacaoJogador1++;
            estado = 0;
        }
        else if (verificaVencedor(tabuleiro) == 2)
        {
            cout << "Parabens " << nomeJogador2 << " Voce Venceu!!!!";
            pontuacaoJogador2++;
            estado = 0;
        }
        rodada++;
    }

    cout << "\nO jogo acabou!\n";
    cout << "\n";
    exibeTabuleiro(tabuleiro);
    cout << "\n";
    cout << "O que deseja fazer?";
    cout << "\n1-Continuar Jogo";
    cout << "\n2-Menu Inicial";
    cout << "\n3-Sair\n";
    cin >> reiniciar;

    if (reiniciar == 1)
    {
        jogar(nomeJogador1, nomeJogador2, pontuacaoJogador1, pontuacaoJogador2);
    }
    else if (reiniciar == 2)
    {
        menu();
    }
}

void menu()
{
    int opcao = 0;
    string nomeJogador1, nomeJogador2;

    while (opcao < 1 || opcao > 3)
    {
        system("cls");

        cout << "\n------------------------------------";
        cout << "\n|Bem vindo ao Jogo da Velha        |";
        cout << "\n|1 - Jogar                         |";
        cout << "\n|2 - Sobre                         |";
        cout << "\n|3 - Sair                          |";
        cout << "\n------------------------------------";
        cout << "\nEscolha uma opcao e aperte ENTER: ";

        cin >> opcao;

        switch (opcao)
        {
        case 1:
            cout << "Voce escolheu jogar\n";
            cout << "Digite o nome do jogador 1: ";
            cin >> nomeJogador1;
            cout << "Digite o nome do jogador 2: ";
            cin >> nomeJogador2;
            jogar(nomeJogador1, nomeJogador2, 0, 0);
            break;
        case 2:
            cout << "\nVoce escolheu sobre: \n";
            cout << "Esse eh um simples jogo da velha interativo, feito em c++, para jogar no terminal.Aroveite!!";
            break;
        case 3:
            cout << "\nSaindo...";
            break;
        }
    }
}

int main()
{

    menu();

    return 0;
}