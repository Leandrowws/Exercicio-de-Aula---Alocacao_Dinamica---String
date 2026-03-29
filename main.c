#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
    
        char *nomes = NULL, nome[100], nomeRemover[100];
        int sel;
        do {
                printf("\n1 - Adicionar nome\n2 - Remover nome\n3 - Listar\n4 - Sair\n");
                scanf("%d", &sel);
                getchar();

                switch(sel) {
                    
                    case 1: 
                       
                        printf("Digite o nome: ");
                        fgets(nome,100,stdin);

                        int tamAtual;

                        if(nomes!=NULL)
                            tamAtual = strlen(nomes);
                        else 
                            tamAtual = 0;

                        
                            int tamNovo = tamAtual + strlen(nome) + 1;

                            nomes = realloc(nomes, tamNovo);

                            if(nomes==NULL) {
                                printf("Erro de memoria!\n");
                                exit(1);
                            }

                            if(tamAtual==0)
                                nomes[0] = '\0';

                        strcat(nomes, nome);
                        break;

                        case 2: 

                            if(nomes==NULL) {
                                printf("Lista vazia!;");
                            }

                            
                            printf("Nome a remover: ");
                            fgets(nomeRemover,100,stdin);

                            char *pos = strstr(nomes, nomeRemover);

                            if(pos) {
                                int tamNome = strlen(nomeRemover);
                                memmove(pos, pos + tamNome, strlen(pos + tamNome)+1);
                                printf("Removido!\n");
                            } else {
                                printf("Nome não encontrado!\n");
                            }
                            break;

                            case 3: 
                                if(nomes==NULL)
                                printf("Lista vazia!\n");
                                else 
                                printf("\nNomes:\n%s", nomes);
                }
        } while(sel!=4);

        free(nomes);

    return 0;
}
