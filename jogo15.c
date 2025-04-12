#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void switchTile(int m[4][4], int **, int *);
void scramble(int m[4][4], int **, int *);
void dificultyScramble(int [4][4], int **, int *, int);
void printMat(int m[4][4]);
int menu(int m[4][4]);
int win(int m[4][4]);
int main()
{
	int m[4][4]={{1, 2 ,3 ,4},							//matriz inicial
			 	 {5, 6, 7 ,8},
				 {9, 10, 11 ,12},
				 {13, 14, 15, 0}};
	int *zero, *switcher;
	zero = &m[3][3];
	int x = 1;
	while(x == 1)										//loop para jogar mais de uma vez
	{
		int dif = menu(m);								//chama o menu
		dificultyScramble(m, &zero, switcher, dif);		//embaralha
		int movs = 0, seconds;							//movs = quantos movimentos a pessoa realizou, seconds = tempo de resolucao do jogo
		printMat(m);									//imprime a matriz que vai jogar
		time_t start = time(NULL);						//start do timer
		while(!win(m))									//enquanto o valor retornado por win for 0, continua o jogo
		{
			switchTile(m, &zero, switcher);				//funcao para realizar as trocas de posicao
			printMat(m);								//print da matriz
			movs++;										//adiciona +1 na quantidade de movimentos realizadas pelo usuario
		}
		time_t end = time(NULL);						//para o timer
		seconds = end - start;							//faz o calculo para saber o tempo de partida
		printf("VC GANHOU, TOP!\nTotal de movimentos: %d\nTempo de resolução: %d segundos\n", movs, seconds); //impressao dos dados
		printf("Se deseja jogar novamente:\n1 = Jogar Novamente\n0 = Sair do jogo\n");
		scanf("%d", &x);
		system("clear");
		while(x != 0 && x != 1)
		{
			printf("Numero invalido, e deseja jogar novamente:\n1 = Jogar Novamente\n0 = Sair do jogo\n"); // verificacao para "quer jogar de novo"
			scanf("%d", &x);
			system("clear");
		}
	}
}

void printMat(int m[4][4])
{
	int l, c;								//imprime os numeros da matriz atraves de um loop
											//quando o numero eh zero, ela nao imprime e pula 4 casas para manter o espaco dessa variavel
	for(l = 0; l < 4; l++)
	{
		for(c = 0; c < 4; c++)
		{
			if(m[l][c] != 0)
			{
			
				printf(" %2d ", m[l][c]);
			}
			else printf("    ");
		}
		printf("\n");
	}
}
void switchTile(int m[4][4], int **zero, int *switcher)
{
	char mov;											//scaneia a variavel mov para definir a direcao do movimento 
	fflush(stdin);												//fflush para limpar o buffer do teclado
	scanf(" %c", &mov);											//usei ponteiro para o ponteiro pois precisava passar o endereco de zero para fora da funcao
	if(mov == 's' || mov == 'S')								//o processo da troca esta descrito apenas no primeiro movimento, mas a logica segue para todos os outros
	{	
		if(*zero != &m[0][0] && *zero != &m[0][1] && *zero != &m[0][2] && *zero != &m[0][3])
		{	
			int aux;
			switcher = (*zero - 4);								//switcher vai apontar para a posicao onde o numero 0 vai ficar
			aux = *switcher;									//aux recebe o valor apontado por switcher
			switcher = *zero;									//switcher aponta para o e do numero 0
			*zero = *zero - 4;									//ponteiro zero aponta para a posicao do numero 0
			**zero = 0;											//valor apontado recebe 0
			*switcher = aux;									//antiga posicao de 0 recebe o antigo valor da posicao onde o 0 foi
		}														//troca foi realizada
	}
	if(mov == 'w' || mov == 'W')
	{
		if(*zero != &m[3][0] && *zero != &m[3][1] && *zero != &m[3][2] && *zero != &m[3][3])
		{
			int aux;
			switcher = (*zero + 4);
			aux = *switcher;
			switcher = *zero;
			*zero = *zero + 4;
			**zero = 0;
			*switcher = aux;	
		}
	}
	if(mov == 'a' || mov == 'A')
	{
		if(*zero != &m[0][3] && *zero != &m[1][3] && *zero != &m[2][3] && *zero != &m[3][3])
		{
			int aux;
			switcher = (*zero + 1);	
			aux = *switcher;
			switcher = *zero;
			*zero = *zero + 1;
			**zero = 0;
			*switcher = aux;
		}	
	}
	if(mov == 'd' || mov == 'D')
	{
		if(*zero != &m[0][0] && *zero != &m[1][0] && *zero != &m[2][0] && *zero != &m[3][0])
		{
			int aux;
			switcher = (*zero - 1);	
			aux = *switcher;
			switcher = *zero;
			*zero = *zero - 1;
			**zero = 0;
			*switcher = aux;
		}
	}
	system("clear");
}
void scramble(int m[4][4], int **zero, int *switcher)
{																//faz os movimentos de embaralhamento utilizando a mesma logica descrita na funcao switchtile		
	int mov;													//randomiza um numero de 0 - 3, para fazer o movimento
	usleep(600000);												//para garantir a integridade a randomizacao, utiliza como fator do rand o horario atual
	srand(time(NULL));												
	mov = rand() % 4;
	if(mov == 0)
	{	
		if(*zero != &m[0][0] && *zero != &m[0][1] && *zero != &m[0][2] && *zero != &m[0][3]) // movimento equivalente a letra s
		{	
			int aux;
			switcher = (*zero - 4);	
			aux = *switcher;
			switcher = *zero;
			*zero = *zero - 4;
			**zero = 0;
			*switcher = aux;
		}
	}
	if(mov == 1)
	{
		if(*zero != &m[3][0] && *zero != &m[3][1] && *zero != &m[3][2] && *zero != &m[3][3]) //movimento equivalente a letra w
			{
				int aux;
				switcher = (*zero + 4);
				aux = *switcher;
				switcher = *zero;
				*zero = *zero + 4;
				**zero = 0;
				*switcher = aux;	
			}
	}
	if(mov == 2)
	{
		if(*zero != &m[0][3] && *zero != &m[1][3] && *zero != &m[2][3] && *zero != &m[3][3])//movimento equivalente a letra a
		{
			int aux;
			switcher = (*zero + 1);	
			aux = *switcher;
			switcher = *zero;
			*zero = *zero + 1;
			**zero = 0;
			*switcher = aux;
		}	
	}
	if(mov == 3)
	{
		if(*zero != &m[0][0] && *zero != &m[1][0] && *zero != &m[2][0] && *zero != &m[3][0]) //movimento equivalente a letra d
		{
			int aux;
			switcher = (*zero - 1);	
			aux = *switcher;
			switcher = *zero;
			*zero = *zero - 1;
			**zero = 0;
			*switcher = aux;
		}
	}
}
void dificultyScramble(int m[4][4], int **zero, int *switcher, int dif) 
{	 																	//seleciona a dificuldade e faz um embaralhamento inicial de acordo com a dificuldade																		
	int p[4][4]={{1, 2 ,3 ,4},											//apos isso roda a matriz procurando por numeros fora de lugar
			 	 {5, 6, 7 ,8},											//ao achar algum numero fora de lugar, ele aumenta 1 no verificador
				 {9, 10, 11 ,12}, //matriz de comparacao                //se a rodar a matriz inteira e nao houver numeros fora do lugar, o loop reinicia
				 {13, 14, 15, 0}};										//isso garante uma quantidade minima de numeros embaralhados
    int count = 0;														//apenas a dificuldade facil esta comentada, mas a logica eh a mesma para as outras
    if(dif == 1) 
	{
		for(int i = 0; i < 5; i++)
		{
			scramble(m, zero, switcher);
		}
		while(count < 5) //quantidade ideal de embaralhamentos
		{
			int l, c;
			for(l = 0; l < 4; l++)
			{
				for(c = 0; c < 4; c++)
				{
					if(m[l][c] != p[l][c]) //loop que procura numeros fora de ordem
					{
						count++;
					}
				}
			}
			if(count < 5) // verificador da matriz apos checar ela inteira
			{
				count = 0;
				scramble(m, zero, switcher);
			}
		}
	}
	if(dif == 2)
	{
		for(int i = 0; i < 9; i++)
		{
			scramble(m, zero, switcher);
		}
		while(count < 9)
		{
			int l, c;
			for(l = 0; l < 4; l++)
			{
				for(c = 0; c < 4; c++)
				{
					if(m[l][c] != p[l][c])
					{
						count++;
					}
				}
			}
			if(count < 9)
			{
				count = 0;
				scramble(m, zero, switcher);
			}
		}
	}
	if(dif == 3)
	{
		for(int i = 0; i < 13; i++)
		{
			scramble(m, zero, switcher);
		}
		while(count < 13)
		{
			int l, c;
			for(l = 0; l < 4; l++)
			{
				for(c = 0; c < 4; c++)
				{
					if(m[l][c] != p[l][c])
					{
						count++;
					}
				}
			}
			if(count < 13)
			{
				count = 0;
				scramble(m, zero, switcher);
			}
		}
	}
	system("clear");
}
int menu(int m[4][4])
{
	int dificulty;
	printf("Seja bem-vindo ao Jogo dos 15, o seu objetivo aqui eh deixar a tabela de numeros embaralhada em ordem utilizando o WASD crescente\n");
	printf("Aqui esta um exemplo de como a matriz tem que ficar no final\n");
	printMat(m);
	printf("Escolha o nivel de dificuldade:\n1-Facil\n2-Medio\n3-Dificil\n");
	scanf("%d", &dificulty); //seleciona a dificuldade
	system("clear");
	if(dificulty != 1 && dificulty != 2 && dificulty != 3) //Verificação para numeros invalidos
	{
		printf("Valor invalido, tente novamente:\n1-Facil\n2-Medio\n3-Dificil\n");
		scanf("%d", &dificulty);
		system("clear");
	}
	if(dificulty == 1) 
	{
		printf("A dificuldade escolhida foi a facil, boa sorte!\n");
	}
	if(dificulty == 2)
	{
		printf("A dificuldade escolhida foi a media, boa sorte!\n");
	}
	if(dificulty == 3)
	{
		printf("A dificuldade escolhida foi a dificil, boa sorte!\n");
	}
	return dificulty;
}
int win(int m[4][4])
{
	int p[4][4]={{1, 2 ,3 ,4},
			 	 {5, 6, 7 ,8},
				 {9, 10, 11 ,12},
				 {13, 14, 15, 0}};
	int l, c;
	for(l = 0; l < 4; l++)
	{
		for(c = 0; c < 4; c++)
		{
			if(m[l][c] != p[l][c])
			{
				return 0; //quebra o loop, impossibilitando o termino do loop
			}
		}
	}
	return 1; //retorna um valor verdadeiro para ser lido pelo while na main
}
