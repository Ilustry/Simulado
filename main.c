#include <stdio.h>
#include <stdlib.h>

typedef struct{
    float nota;
    int matricula;

}Dados;

typedef struct{
    Dados candidato;
    struct Lista *prox;

}Lista;

typedef struct{
    Dados candidato;
    struct Arvore *esq, *dir;

}Arvore;

int Inserir_Lista(){
    return;
}
Dados Excluir_Lista(){
    return;
}
int Verifica_Nota(){
    return;
}

void Exibir_Convocados(Arvore *folha){
    if(folha == NULL)
        return;
    else{
        printf("Matricula: %d\n", folha->candidato.matricula);
        printf("Nota: %.1f\n\n", folha->candidato.nota);
        Exibir_Convocados(folha->esq);
        Exibir_Convocados(folha->dir);
    }

}

void Incluir(Arvore** folha, Dados cand){
    if(*folha == NULL){
        *folha = malloc(sizeof(Arvore));
        (*folha)->dir = NULL;
        (*folha)->esq = NULL;
        (*folha)->candidato = cand;
    }
    else{
        if(cand.matricula < (*folha)->candidato.matricula)
            Incluir(&(*folha)->esq, cand);
        else if(cand.matricula > (*folha)->candidato.matricula)
            Incluir(&(*folha)->dir, cand);
    }

}

int main()
{
    Arvore *folha = NULL;
    Dados cand;
    int opc, retorno = 0;

    do{
        printf("//////////////////////////////\n");
        printf("/'          'MENU'          '/\n");
        printf("/'--------------------------'/\n");
        printf("/'1.Cadastrar               '/\n");
        printf("/'2.Gerar Classificacao     '/\n");
        printf("/'3.Exibir Classificados    '/\n");
        printf("/'4.Consultar Candidato     '/\n");
        printf("/'0.Sair                    '/\n");
        printf("//////////////////////////////\n");

        scanf("%d", &opc);

        switch(opc){
            case 1:
                printf("Informe a matricula.\n");
                scanf("%d", &cand.matricula);
                printf("Informe a nota.\n");
                scanf("%f", &cand.nota);
                retorno = Inserir_Lista(cand);
                if(retorno == 0)
                    printf("Candidado cadastrado com sucesso.\n");
                else if(retorno == -1)
                    printf("Candidato ja cadastrado.\n");
                break;

            case 2:
                do{
                    cand = Excluir_Lista();
                    if(cand.nota > 7)
                        Incluir(&folha, cand);
                }while(cand.nota != 0);
                break;

            case 3:
                Exibir_Convocados(folha);
                break;

            case 4:
                printf("Informe a matricula.\n");
                scanf("%d", cand.matricula);
                retorno = Verifica_Nota(cand.matricula);
                if(retorno == -1)
                    printf("Candidato nao classificado.\n");
                else
                    printf("Nota: %.1f\n", cand.nota);
                break;
        }
    }while(opc != 0);

    return 0;
}
