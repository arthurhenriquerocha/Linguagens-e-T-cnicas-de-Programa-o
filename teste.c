#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#endif

#define TAMANHO_TRILHA 6
#define ESQUERDA 2
#define DIREITA 6
#define FOICE 7
#define MACHADO 9
#define BUMERANGUE 4

// Coloque 0 aqui se o seu terminal nao mostrar as cores direito
#ifndef USAR_COR
#define USAR_COR 1
#endif

// ============================================================
//  CENARIO ASCII
// ============================================================
#define LARGURA_CASA   11
#define LARGURA_CENA   (TAMANHO_TRILHA * LARGURA_CASA)
#define ALTURA_CENA    16
#define ALTURA_SPRITE  4
#define LINHA_SPRITES  10   // onde os personagens/itens comecam
#define LINHA_CAMINHO  14   // linha da trilha ("=====")
#define LINHA_NUMEROS  15   // numeracao das casas

static char cena[ALTURA_CENA][LARGURA_CENA];
static char cor[ALTURA_CENA][LARGURA_CENA];


// ---------- Desenhos ----------
static const char *SOL[3] = {
    "  \\ | /  ",
    " -- O -- ",
    "  / | \\  "
};

static const char *NUVEM[3] = {
    "    .--.   ",
    " .-(    ). ",
    "(___.__)__)"
};

static const char *MONTANHA[4] = {
    "     /\\    ",
    "    /  \\   ",
    "   / /\\ \\  ",
    "  /_/  \\_\\ "
};

static const char *ARVORE_GRANDE[5] = {
    "   /\\   ",
    "  /^^\\  ",
    " /^^^^\\ ",
    "/^^^^^^\\",
    "   ||   "
};

static const char *ARVORE_PEQUENA[4] = {
    "  /\\  ",
    " /^^\\ ",
    "/^^^^\\",
    "  ||  "
};

static const char *PERSONAGEM_1[ALTURA_SPRITE] = {
    " _/^\\_ ",
    " (o.o) ",
    " /|=|\\ ",
    "  / \\  "
};

static const char *PERSONAGEM_3[ALTURA_SPRITE] = {
    " .-^-. ",
    " (^_^) ",
    "<|###|>",
    "  / \\  "
};

static const char *BINOCULO[ALTURA_SPRITE] = {
    "  \\ | /",
    " _   _ ",
    "(O)=(O)",
    " '   ' "
};

static const char *TESOURO[ALTURA_SPRITE] = {
    "  \\ | /",
    ".-----.",
    "|=[X]=|",
    "'-----'"
};


// ---------- Cores (ANSI) ----------
static const char *codigoCor(char c)
{
    switch (c)
    {
        case 'y': return "\033[93m";   // amarelo
        case 'o': return "\033[33m";   // marrom
        case 'g': return "\033[32m";   // verde
        case 'G': return "\033[92m";   // verde claro
        case 'c': return "\033[96m";   // ciano
        case 'w': return "\033[97m";   // branco
        case 'k': return "\033[90m";   // cinza
        case 'r': return "\033[91m";   // vermelho
        case 'm': return "\033[95m";   // magenta
        default:  return "\033[0m";    // normal
    }
}

static void trocarCor(char *atual, char nova)
{
#if USAR_COR
    if (*atual != nova)
    {
        printf("%s", codigoCor(nova));
        *atual = nova;
    }
#else
    (void)atual;
    (void)nova;
#endif
}

static void habilitarCores(void)
{
#if defined(_WIN32) && USAR_COR
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD modo = 0;

    if (h != INVALID_HANDLE_VALUE && GetConsoleMode(h, &modo))
        SetConsoleMode(h, modo | 0x0004);   // ENABLE_VIRTUAL_TERMINAL_PROCESSING
#endif
}


// ---------- Funcoes de desenho ----------

// Escreve um texto na cena (espacos sao transparentes)
static void carimbar(int y, int x, const char *txt, char c)
{
    int i;

    if (y < 0 || y >= ALTURA_CENA)
        return;

    for (i = 0; txt[i] != '\0'; i++)
    {
        int xx = x + i;

        if (xx < 0 || xx >= LARGURA_CENA || txt[i] == ' ')
            continue;

        cena[y][xx] = txt[i];
        cor[y][xx] = c;
    }
}

// Desenha varias linhas; "cores" tem uma letra de cor por linha
static void desenhar(int y, int x, const char *linhas[], int n, const char *cores)
{
    int i;

    for (i = 0; i < n; i++)
        carimbar(y + i, x, linhas[i], cores[i]);
}

// Monta o cenario completo na memoria
static void montarCena(char trilha[], int posJogador, int personagem)
{
    int i, x, y;
    char numero[16];

    // Limpa
    for (y = 0; y < ALTURA_CENA; y++)
        for (x = 0; x < LARGURA_CENA; x++)
        {
            cena[y][x] = ' ';
            cor[y][x] = ' ';
        }

    // Ceu
    desenhar(0, 57, SOL, 3, "yyy");
    desenhar(0, 14, NUVEM, 3, "www");
    desenhar(0, 35, NUVEM, 3, "www");

    // Montanhas
    desenhar(1, 3,  MONTANHA, 4, "wkkk");
    desenhar(1, 24, MONTANHA, 4, "wkkk");
    desenhar(1, 46, MONTANHA, 4, "wkkk");

    // Floresta
    desenhar(5, 0,  ARVORE_GRANDE,  5, "GGggo");
    desenhar(6, 11, ARVORE_PEQUENA, 4, "Gggo");
    desenhar(5, 20, ARVORE_GRANDE,  5, "GGggo");
    desenhar(6, 31, ARVORE_PEQUENA, 4, "Gggo");
    desenhar(5, 41, ARVORE_GRANDE,  5, "GGggo");
    desenhar(6, 52, ARVORE_PEQUENA, 4, "Gggo");
    desenhar(5, 58, ARVORE_GRANDE,  5, "GGggo");

    // Caminho de terra
    for (x = 0; x < LARGURA_CENA; x++)
    {
        cena[LINHA_CAMINHO][x] = '=';
        cor[LINHA_CAMINHO][x] = 'o';
    }

    // Casas da trilha
    for (i = 0; i < TAMANHO_TRILHA; i++)
    {
        int base = i * LARGURA_CASA;

        // tufos de grama nas laterais
        carimbar(LINHA_CAMINHO - 1, base,     ",\"", 'g');
        carimbar(LINHA_CAMINHO - 1, base + 9, "\",", 'g');

        // quem esta nessa casa?
        if (i == posJogador)
        {
            if (personagem == 1)
                desenhar(LINHA_SPRITES, base + 2, PERSONAGEM_1, ALTURA_SPRITE, "cccc");
            else
                desenhar(LINHA_SPRITES, base + 2, PERSONAGEM_3, ALTURA_SPRITE, "mmmm");
        }
        else if (trilha[i] == '8')
            desenhar(LINHA_SPRITES, base + 2, BINOCULO, ALTURA_SPRITE, "ywww");
        else if (trilha[i] == 'X')
            desenhar(LINHA_SPRITES, base + 2, TESOURO, ALTURA_SPRITE, "yoyo");

        // numeracao (a casa do jogador fica destacada)
        if (i == posJogador)
        {
            snprintf(numero, sizeof(numero), " >>[ %d ]<< ", i);
            carimbar(LINHA_NUMEROS, base, numero, 'y');
        }
        else
        {
            snprintf(numero, sizeof(numero), "   [ %d ]   ", i);
            carimbar(LINHA_NUMEROS, base, numero, 'k');
        }
    }
}

// Imprime o cenario com moldura
static void imprimirCena(void)
{
    int x, y, i;
    char atual = ' ';

    printf("\n");

    // Moldura superior com titulo
    trocarCor(&atual, 'k');
    printf("+");
    for (i = 0; i < 23; i++) putchar('=');
    trocarCor(&atual, 'y');
    printf(" TRILHA DA AVENTURA ");
    trocarCor(&atual, 'k');
    for (i = 0; i < 23; i++) putchar('=');
    printf("+\n");

    // Cenario
    for (y = 0; y < ALTURA_CENA; y++)
    {
        trocarCor(&atual, 'k');
        putchar('|');

        for (x = 0; x < LARGURA_CENA; x++)
        {
            trocarCor(&atual, cor[y][x]);
            putchar(cena[y][x]);
        }

        trocarCor(&atual, 'k');
        printf("|\n");
    }

    // Moldura inferior
    trocarCor(&atual, 'k');
    printf("+");
    for (i = 0; i < LARGURA_CENA; i++) putchar('=');
    printf("+\n");

    // Legenda
    trocarCor(&atual, 'w');
    printf("  (O)=(O) binoculo     |=[X]=| tesouro     >>[ n ]<< voce esta aqui\n");

    trocarCor(&atual, ' ');
}


// MOSTRAR A TRILHA
void mostrarTrilha(char trilha[], int posJogador, int personagem)
{
    montarCena(trilha, posJogador, personagem);
    imprimirCena();
}


// ESCOLHER PERSONAGEM
int escolherPersonagem()
{
    int personagem, l;

    printf("\nEscolha seu personagem:\n\n");
    printf("        [1]                 [3]\n");

    for (l = 0; l < ALTURA_SPRITE; l++)
        printf("      %s             %s\n", PERSONAGEM_1[l], PERSONAGEM_3[l]);

    printf("\n");

    do
    {
        printf("> ");
        scanf("%d", &personagem);

        if (personagem != 1 && personagem != 3)
            printf("Opcao invalida! Escolha 1 ou 3.\n");

    } while (personagem != 1 && personagem != 3);

    return personagem;
}


// ESCOLHER ARMA
int escolherArma()
{
    int arma;

    printf("\n====================================\n");
    printf("            ESCOLHA SUA ARMA\n");
    printf("====================================\n");

    printf("[7] Foice\n");
    printf("[9] Machado\n");
    printf("[4] Bumerangue\n");

    do
    {
        printf("> ");
        scanf("%d", &arma);

        if (arma != FOICE && arma != MACHADO && arma != BUMERANGUE)
            printf("Arma invalida! Escolha 7, 9 ou 4.\n");

    } while (arma != FOICE && arma != MACHADO && arma != BUMERANGUE);

    return arma;
}


// JOGAR NA TRILHA
int jogarNaTrilha(char trilha[], int posJogador, int posBinoculo,
                  int posTesouro, int personagem, int pontuacao)
{
    int movimento;
    int achouBinoculo = 0;
    int achouTesouro = 0;

    trilha[posBinoculo] = '8';

    printf("\n====================================\n");
    printf("          AVENTURA INICIADA!\n");
    printf("====================================\n");

    printf("Use %d para esquerda e %d para direita.\n", ESQUERDA, DIREITA);
    printf("Encontre o binoculo para revelar o tesouro!\n");

    while (achouTesouro == 0)
    {
        mostrarTrilha(trilha, posJogador, personagem);

        printf("Posicao atual: %d\n", posJogador);
        printf("Escolha %d ou %d: ", ESQUERDA, DIREITA);
        scanf("%d", &movimento);

        if (movimento == ESQUERDA)
        {
            if (posJogador > 0)
            {
                posJogador--;
                printf("Voce andou para a esquerda.\n");
            }
            else
                printf("Voce ja esta no inicio da trilha!\n");
        }
        else if (movimento == DIREITA)
        {
            if (posJogador < TAMANHO_TRILHA - 1)
            {
                posJogador++;
                printf("Voce andou para a direita.\n");
            }
            else
                printf("Voce ja esta no final da trilha!\n");
        }
        else
            printf("Movimento invalido! Use 2 ou 6.\n");


        if (movimento == ESQUERDA || movimento == DIREITA)
        {
            if (achouBinoculo == 0 && posJogador == posBinoculo)
            {
                achouBinoculo = 1;
                trilha[posBinoculo] = '.';
                trilha[posTesouro] = 'X';

                printf("\nBINOCULO ENCONTRADO!\n");
                printf("O tesouro foi revelado!\n");
            }

            if (achouBinoculo == 1 && posJogador == posTesouro)
            {
                achouTesouro = 1;
                pontuacao += 50;

                // Mostra a trilha uma ultima vez com o jogador no tesouro
                mostrarTrilha(trilha, posJogador, personagem);

                printf("\nTESOURO ENCONTRADO!\n");
                printf("+50 pontos!\n");
                printf("Pontuacao atual: %d\n", pontuacao);
            }
        }
    }

    return pontuacao;
}


// BATALHA CONTRA A COBRA
int batalha(int pontuacao)
{
    int arma, dano;

    printf("\n====================================\n");
    printf("       UMA COBRA GIGANTE APARECEU!\n");
    printf("====================================\n");

    arma = escolherArma();

    if (arma == MACHADO)
        dano = 30;
    else if (arma == FOICE)
        dano = 20;
    else
        dano = 15;

    printf("\nVoce atacou a cobra!\n");
    printf("Dano causado: %d\n", dano);

    pontuacao += dano;

    if (dano >= 20)
    {
        printf("\nA cobra foi derrotada!\n");
        printf("Voce venceu o jogo!\n");
    }
    else
    {
        printf("\nA cobra ficou ferida.\n");
        printf("Voce escapou com o tesouro!\n");
    }

    printf("\nPontuacao apos a batalha: %d\n", pontuacao);

    return pontuacao;
}


// PROGRAMA PRINCIPAL
int main()
{
    char trilha[TAMANHO_TRILHA] = {'.', '.', '.', '.', '.', '.'};

    int posJogador, posBinoculo, posTesouro;
    int personagem;
    int pontuacao = 0;

    habilitarCores();

    srand(time(NULL));

    printf("====================================\n");
    printf("       JOGO DA CALCULADORA\n");
    printf("====================================\n");

    personagem = escolherPersonagem();

    // SORTEAR POSICOES
    posJogador = rand() % TAMANHO_TRILHA;

    posBinoculo = rand() % TAMANHO_TRILHA;

    while (posBinoculo == posJogador)
        posBinoculo = rand() % TAMANHO_TRILHA;

    posTesouro = rand() % TAMANHO_TRILHA;

    while (posTesouro == posJogador || posTesouro == posBinoculo)
        posTesouro = rand() % TAMANHO_TRILHA;


    printf("\nSeu personagem comecou na posicao %d.\n", posJogador);
    printf("O binoculo esta escondido na trilha.\n");
    printf("Encontre-o para revelar o tesouro!\n");

    pontuacao = jogarNaTrilha(trilha, posJogador, posBinoculo,
                              posTesouro, personagem, pontuacao);

    pontuacao = batalha(pontuacao);


    // RESULTADO FINAL
    printf("\n====================================\n");
    printf("          (=) RESULTADO FINAL\n");
    printf("====================================\n");

    printf("Pontuacao final: %d pontos\n", pontuacao);

    printf("====================================\n");
    printf("             FIM DO JOGO!\n");
    printf("====================================\n");

    return 0;
}
