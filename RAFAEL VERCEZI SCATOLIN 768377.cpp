/*NOME: RAFAEL VERCEZI SCATOLIN   CÓDIGO: 768377

O volante da mega sena, contém números de 1 a 60 inclusive.
A possibilidade de vitória no jogo são divididas em:
Terno - quando o jogador acertar 3 números no sorteio;
Quadra -Terno - quando o jogador acertar 4 números no sorteio;
Quina - Terno - quando o jogador acertar 5 números no sorteio;
Sena - Terno - quando o jogador acertar 6 números no sorteio;

Um cliente lhe contratou para fazer um software que execute uma simulação de 100.000 sorteios.

O software a ser desenvolvido deve conter as seguintes características:
Armazenar 100.000 sorteios válidos;
Cada sorteio é identificado por um número;
Cada sorteio deve gerar 6 números inteiros entre 1 e 60 inclusive;
Cada sorteio não pode repetir número. Ex: 3, 5, 8, 8, 52 ,59, é um jogo inválido, pois não podem aparecer os dois números “8”.
Após armazenar os 100.000 jogos, o programa deve pedir para o usuário um jogo de até 6 dezenas válidas.
Com as 6 dezenas armazenadas, o programa deverá analisar dentre os 100.000 jogos armazenados, quantos acertos o jogador obteve em cada categoria (terno, quadra, quina e sena)
Caso haja acerto da sena, mostre qual foi o jogo vencedor;
Acrescente uma opção de exibir os jogos sorteados na tela caso o jogador queira vê-los;*/


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <vector>


int matriz[100][6], num_sorteado, posicao_sena, exibe_jogo; // matriz refere-se aos 100 sorteios com 6 números cada
int terno = 0, quadra = 0, quina = 0, sena = 0, acertos = 0;

void init_matriz (int matriz[100][6]) {
	for (int i=0; i!=100; i++)
		for (int j=0; j!=6; j++){
			
			num_sorteado = rand()%60+1;
			
			for (int j=0; j!=6; j++)
				while (matriz[i][j] == num_sorteado)  //o for e o while testa se o número sorteado não é repetido
					num_sorteado = rand()%60+1;
					
			matriz[i][j] = num_sorteado;
	}
}

			
void print_matriz (int matriz[100][6]) {
	for (int i=0; i!=100; i++) {
	printf ("Jogo %d:\t",i+1);
		for (int j=0; j!=6; j++)
			printf (" %d ",matriz[i][j]);		
	printf ("\n\n ");
	}
}

void verifica_sorteio (int numeros_usuario [6], int matriz[100][6]) {
	
	for (int i=0; i!=100; i++) {
		
		acertos = 0;
		
		for (int j=0; j!=6; j++){
			
			for (int k=0; k!=6; k++)
				if (matriz[i][j] == numeros_usuario [k]) //Compara o jogo do usuário com cada jogo da matriz e classifica em terno, quadra, quina e sena
					acertos++;
		
			switch (acertos) {
				case 3: terno++; break;
				case 4: quadra++; break;
				case 5: quina++; break;
				case 6: sena++; break;		
			}
		}
		if (sena > 0)
			posicao_sena = i;
	}
}


int main () {


	srand(time(NULL));
	
	init_matriz (matriz);
	
	print_matriz (matriz);

	int numeros_usuario [6];

	printf ("Entre com os seus numeros\n\n");
	
	
	for (int i=0; i!=6; i++){
			printf (" %d :",i+1);
			scanf("%d", &numeros_usuario [i]); // o software pede para o usuário inserir os números do 1º ao 6º
	}
	
	verifica_sorteio (numeros_usuario, matriz);
	
	printf ("\nOs acertos foram os seguintes...\n");
	
	printf ("terno: %d \n", terno);
	printf ("quadra: %d \n", quadra);
	printf ("quina: %d \n", quina);
	printf ("sena: %d \n", sena);
	
	if (sena > 0){
		printf ("Parabens!!! Voce foi sorteado na sena\n\n");
		
		printf ("Deseja exibir o jogo sorteado? (1-sim) (0-nao)...");
		
		scanf("%d", &exibe_jogo);
		
		if (exibe_jogo == 1) {

			printf ("\nO jogo sorteado foi o jogo %d: \t", posicao_sena+1);
			
			for (int j=0; j!=6; j++)
				printf ("%d   ", matriz[posicao_sena][j]);
				
			printf ("\n\n");
		}	
	}

	system ("pause");
	
	return 0;
}





