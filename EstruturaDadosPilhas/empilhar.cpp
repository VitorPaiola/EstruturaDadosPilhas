#include <iostream>
#include <stdlib.h>
#include <string>
#include <locale.h>
#define TAM 10

using namespace std;

static void imprime_vetor(int pilha[TAM], int topo) {
	int cont;

	cout << "\n";

	for (cont = 0; cont < TAM; cont++) {
		cout << pilha[cont] << " - ";
	}

	cout << "Topo: " << topo;

}

// Caso a pilha esteja vazia
static bool pilha_vazia(int topo) {
	if (topo == -1) {
		return true;
	} else {
		return false;
	}
}

// Confere se a pilha esta cheia
static bool pilha_cheia(int topo) {
	if (topo == TAM - 1) {
		return true;
	} else {
		return false;
	}
}

// Retorna o tamanho da pilha que sempre vai ser o topo + 1
static int pilha_tamanho(int topo) {
	return  topo + 1;
}

// Retorna o último valor da pilha
static int pilha_get(int pilha[TAM], int *topo) {
	if (pilha_vazia(*topo)) {
		cout << "A pilha esta vazia";
		return 0;
	} else {
		// Último elemento da pilha
		return pilha[*topo];
	}
}

// Adiciona um valor na pilha
static void pilha_push(int pilha[TAM], int valor, int *topo) {

	// Caso não possa colocar mais valores
	if (pilha_cheia(*topo)) {
		cout << "Pilha cheia";
	}
	else {
		*topo += 1;
		pilha[*topo] = valor;
	}
}

// Remove um valor da pilha
static void pilha_pop(int pilha[TAM], int *topo) {
	cout << "\n";

	// Se a pilha estiver vazia...
	if (pilha_vazia(*topo)) {
		cout << "A pilha já esta vazia";
	} else {
		cout << "Valor Removido: " << pilha[*topo];
		pilha[*topo] = 0;
		*topo -= 1;
	}

}

// Cria uma pilha e limpa ela
static void pilha_construtor(int pilha[TAM], int *topo) {

	// Coloca o topo negativo para indicar uma pilha vazia
	*topo = -1;

	// Auxiliar contador
	int cont;

	// Imprime o vetor
	for (cont = 0; cont < TAM; cont++) {
		pilha[cont] = 0;
	}

}

int main() {
	setlocale(LC_ALL, "");

	int pilha[TAM];

	// Topo da pilha e sem nada
	int topo;

	pilha_construtor(pilha, &topo);

	imprime_vetor(pilha, topo);

	pilha_push(pilha, 5, &topo);
	imprime_vetor(pilha, topo);

	cout << "\nÚltimo valor da pilha: " << pilha_get(pilha, &topo);
	cout << "\nTamanho da Pilha: " << pilha_tamanho(topo);

	pilha_push(pilha, 7, &topo);
	pilha_push(pilha, 7, &topo);
	pilha_push(pilha, 7, &topo);
	pilha_push(pilha, 7, &topo);
	pilha_push(pilha, 7, &topo);
	pilha_push(pilha, 7, &topo);
	pilha_push(pilha, 7, &topo);
	pilha_push(pilha, 7, &topo);
	pilha_push(pilha, 7, &topo);
	imprime_vetor(pilha, topo);

	pilha_pop(pilha, &topo);
	imprime_vetor(pilha, topo);

	return 0;
}