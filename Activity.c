#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct cliente
{
    int cpf;
    char nome[150];
    char endereco[41];
    struct cliente *prox;
};

typedef struct cliente Cliente;

#define N 10

void inicializa_tabela(Cliente **);
void imprime_tabela_Hash(Cliente **);
void imprime_conteudo(Cliente **);
int calcula_indice(int);
void incluir_na_tabela_Hash(Cliente **);
void busca_na_tabela(Cliente **);
void excluir_na_tabela(Cliente**);

int main(void)
{
    Cliente *Hash[N];
    inicializa_tabela(&Hash[0]);
    
    char escolha;

	while (escolha != '5') {
		printf("Escolha uma as opcoes a seguir: \n 1 - Inserir \n 2 - Pesquisar \n 3 - deletar \n 4 - visualizar\n 5 - sair\n");
		scanf("%c", &escolha);
		
		switch (escolha) {
			case '1':
				incluir_na_tabela_Hash(&Hash[0]);
			break;
			
			case '2':
				 busca_na_tabela(&Hash[0]);
			break;
			
			case '3':
				excluir_na_tabela(&Hash[0]);
	 		break;
	 		
			case '4':
				//imprime_tabela_Hash(&Hash[0]);
				imprime_conteudo(&Hash[0]);
			break;
			
			case '5':
				printf("saindo...");
			break;
		}
	}
  
   // imprime_conteudo(&Hash[0]);
   

}

void inicializa_tabela(Cliente **ptrHash)
{
    int i;
    for (i = 0; i < N; i++)
    {
        *ptrHash = NULL;
         ptrHash++;
    }
}

void imprime_tabela_Hash(Cliente **ptrHash)
{
    int i;
    printf("\n---------------------------------------------\n");
    for (i = 0; i < N; i++)
    {
        printf("\n Hash[%d] = %p\n", i, *ptrHash);
        ptrHash++;
    }
    printf("\n---------------------------------------------\n");
}

void imprime_conteudo(Cliente **ptrHash)
{
    Cliente *aux;
    int i;
    printf("\n---------------------------------------------\n");
    for (i = 0; i < N; i++)
    {
        if (ptrHash[i] == NULL)
        {
            printf("\n Hash[%d] = %p\n", i, *ptrHash);
        }
        else
        {
            printf("\n Hash[%d] :   ", i);
            printf("\n CPF = %d ", ptrHash[i]->cpf);
            printf("\n Nome = %s ", ptrHash[i]->nome);
            printf("\n Endereco = %s \n", ptrHash[i]->endereco);
            aux = ptrHash[i]->prox;
            while (aux != NULL)
            {
                printf("\n Hash[%d] :   ", i);
                printf("\n CPF = %d :", aux->cpf);
                printf("\n Nome = %s: ", aux->nome);
                printf("\n Endereco = %s \n", aux->endereco);
                aux = aux->prox;
            }
        }
    }
    printf("\n---------------------------------------------\n");
}
int calcula_indice(int cpf)
{
    return cpf % N;
}

void incluir_na_tabela_Hash(Cliente **ptrHash)
{
    int teste = 1, cpf, indice;
    char nome[81];
    char endereco[41];
    Cliente *aux, *pai;

        printf("\n Digite o CPF do cliente: ");
        scanf("%d", &cpf);
        printf("\n Digite o nome do cliente: ");
        scanf("%s", nome);
        printf("\n Digite o endereco do cliente: ");
        scanf("%s", endereco);

        indice = calcula_indice(cpf);

        if (ptrHash[indice] == NULL)
        {
            aux = (Cliente *)malloc(sizeof(Cliente));
            if (aux == NULL)
            {
                printf("\n Nao ha memoria suficiente");
                free(aux);
                exit(1);
            }
            aux->cpf = cpf;
            strcpy(aux->nome, nome);
            strcpy(aux->endereco, endereco);
            aux->prox = NULL;
            ptrHash[indice] = aux;
        }
        else
        {
            aux = ptrHash[indice];
            while (aux != NULL)
            {
                pai = aux;
                aux = aux->prox;
            }
            aux = (Cliente *)malloc(sizeof(Cliente));
            if (aux == NULL)
            {
                printf("\n Nao ha memoria suficiente");
                free(aux);
                exit(1);
            }
            aux->cpf = cpf;
            strcpy(aux->nome, nome);
            strcpy(aux->endereco, endereco);
            aux->prox = NULL;
            pai->prox = aux;
        }

}

void busca_na_tabela(Cliente **ptrHash)
{
    int cpf, indice;
    Cliente *aux;

    printf("\n Digite o CPF do cliente: ");
    scanf("%d", &cpf);

    indice = calcula_indice(cpf);

    if (ptrHash[indice] == NULL)
    {
        printf(" \n CPF nao existe na tabela.");
        return;
    }
    else
    {
        aux = ptrHash[indice];
        while (aux != NULL)
        {
            if (aux->cpf == cpf)
            {
                printf("\n CPF encontrado. \n");
                printf("\n Hash[%d] :   ", indice);
                printf("\n CPF = %d :", aux->cpf);
                printf("\n Nome = %s: ", aux->nome);
                printf("\n Endereco = %s \n", aux->endereco);
                return;
            }
            else
            {
                aux = aux->prox;
            }
        }
        if(aux==NULL)
        {
            printf("\n CPF nao existe na tabela");
        }
    }
}

void excluir_na_tabela(Cliente **ptrHash)
{
    
}