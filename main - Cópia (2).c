#include <stdio.h>
#include <stdlib.h>
#define TRUE  1
#define FALSE 0
typedef int bool;
int main()
{
    int loop=0;
    int variaveis =0,restricoes=0, cont=0,cont2=0;
    int PosCoeficiente = 0,ColunaMenorZ=0;
    float menorCoefifiente=0;
    bool tudoNegativo= TRUE;

    scanf("%d",&variaveis);
    scanf("%d",&restricoes);
    printf("\n====================================================\nDigite a quantidade de variaveis:\n %d",variaveis);
    printf("\n====================================================\nDigite a quantidade de restricoes:\n %d",restricoes);

    float matrix[restricoes+1][restricoes+variaveis+2];
    memset(matrix,0,sizeof matrix);
    int indetidade=variaveis;

    matrix[0][0] =1;
    //seta os valores na matriz
    for(cont=0; cont<restricoes+1; cont++)
    {
        if(cont==0)
        {
            printf("\n====================================================\nFuncao objetiva Z:\n");
        }
        else
        {
            printf("\n====================================================\nRestricao [%d]:\n",cont);
        }
        //Coloca a matriz como identidade
        matrix[cont][indetidade] = 1;
        indetidade++;
        for(cont2=1; cont2<=variaveis; cont2++)
        {
            scanf("%f",&matrix[cont][cont2]);
            printf("%.2fx*%d+ ",matrix[cont][cont2],cont2);

        }
        //Captura o valor do da solucao;
        scanf("%f",&matrix[cont][restricoes+variaveis+1]);
        printf("=%f",matrix[cont][restricoes+variaveis+1]);
        if(matrix[cont][restricoes+variaveis+1]<0)
        {
            printf("\n----------------------------------------------------------------\nSolução inviavel, valor da mao direita negativo\n----------------------------------------------------------------\n");
            break;
        }
    }

int verificaModelo()
    {
        int ok =0;
        for(cont=1; cont<=variaveis; cont++){
            for(cont2=1; cont2<=restricoes; cont2++){
            if(matrix[variaveis][restricoes==0])  {
            ok=1;
            }
            if(matrix[variaveis][restricoes]>0){
                ok=0;
            }
            if(matrix[variaveis][restricoes]<0 && ok==1)
            {
                ok=1;
            }

        }

    }
return ok;
}

void ImprimeMatriz()
    {
        printf("\n");
        for(cont=0; cont<restricoes+1; cont++)
        {

            printf("\n");
            for(cont2=0; cont2<restricoes+variaveis+2; cont2++)
            {
                printf("%.1f\t",matrix[cont][cont2]);

            }
        }
    }

    int MenorValordeZ()
    {
        float menor=matrix[0][0],maior=matrix[0][0];
        int posMenor=0;

        for(cont2=0; cont2<=variaveis; cont2++)
        {
            if(matrix[0][cont2] < menor)
            {
                menor =  matrix[0][cont2];
                posMenor = cont2;
            }
            if(matrix[0][cont2] > maior)
            {
                maior =  matrix[0][cont2];
                posMenor = cont2;
            }
        }
        return posMenor;
    }

    float EncontraCoeficiente(int menorZ)
    {
        float coeficiente=0;
        float menorCoefifiente=matrix[0][menorZ];
        int posMenorCoeficiente;
        float maiorCoefifiente=matrix[0][menorZ];
        //encontrando o menor coeficiente
        for(cont=0; cont<variaveis; cont++)
        {
            printf("Valor de Z: %f - Valor do Coeficiente %f\n",matrix[variaveis][restricoes+variaveis+1],matrix[cont][menorZ]);
            coeficiente=matrix[variaveis][restricoes+variaveis+1]/ matrix[cont][menorZ];
            printf("\nValor do Coeficiente: %f\n",coeficiente);
            if(coeficiente>0 && coeficiente<menorCoefifiente)
            {
                menorCoefifiente =  matrix[cont][menorZ];
                posMenorCoeficiente = cont;
            }
            if(coeficiente>0 && coeficiente > maiorCoefifiente)
            {
                maiorCoefifiente =  matrix[cont][menorZ];
                posMenorCoeficiente = cont;
            }
        }
        return posMenorCoeficiente;
    }
    void SubistituiLinha(int linhaPivo, float Coeficiente)
    {
        printf("\nSubistitui linha do pivor pelo coeficiente:");

       float valor=Coeficiente;
        for(cont=0; cont<restricoes+variaveis+2; cont++)
        {
            if(Coeficiente !=0 )
            { valor=Coeficiente;
               // printf("COEFICIENTE: %f",Coeficiente);
                matrix[linhaPivo][cont] = matrix[linhaPivo][cont]/valor;
            }
            else
            {   valor=0;
                matrix[linhaPivo][cont]=0;
            }
        }
    }
    //Subistitui todas linhas, pegando sua linha, menos o coeficiente da linha * pivô
    void SubistituiTodasLinhas(int linhaPivo,int ColunaMenorZ2)
    {
        for(cont=0; cont<restricoes+1; cont++)
        {
            float pivorlinha = matrix[cont][ColunaMenorZ2];
            //printf("[");
            for(cont2=0; cont2<restricoes+variaveis+2; cont2++)
            {
                if(cont!=linhaPivo)
                {
                    // printf("%f,",matrix[cont][cont2]);
                    matrix[cont][cont2] =  -1*(((pivorlinha)* matrix[linhaPivo][cont2])-(matrix[cont][cont2]));
                }
                else
                {
                    cont++;
                }
            }
        }
    }

    while(++loop)
    {
        if(loop>20)
        {
            break;
        }
        if(verificaModelo() ==1){
            printf("Solucao ilimitada");
            break;
        }

        ImprimeMatriz();
        ColunaMenorZ = MenorValordeZ();
        printf("\nMenor z na posicao:x%d",ColunaMenorZ);
        //Encontrou o pivor e sua linha
        PosCoeficiente = EncontraCoeficiente(ColunaMenorZ);
        //Subistituiu a linha do pivor;
        SubistituiLinha(PosCoeficiente,matrix[PosCoeficiente][ColunaMenorZ]);
        ImprimeMatriz();
        SubistituiTodasLinhas(PosCoeficiente,ColunaMenorZ);
        printf("\nMatriz Final\n");
        ImprimeMatriz();
    }
    return 0;
}
