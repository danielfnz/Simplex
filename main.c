#include <stdio.h>
#include <stdlib.h>
#define TRUE  1
#define FALSE 0
typedef int bool;
int variaveis =0,restricoes=0, cont=0,cont2=0;

bool verificaPositivos(float Matrix[0][variaveis+1])
{
    for(cont=0; cont<variaveis+1; cont++)
    {
        if(Matrix[0][cont]<0)
        {
            return TRUE;
        }
    }
    return FALSE;
}
int main()
{
    int loop=0;

    int PosCoeficiente = 0,ColunaMenorZ=0;
    float menorCoefifiente=0;

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
            printf("%.2f*x%d+ ",matrix[cont][cont2],cont2);

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
        for(cont=1; cont<=variaveis; cont++)
        {
            for(cont2=1; cont2<=restricoes; cont2++)
            {
                if(matrix[variaveis][restricoes==0])
                {
                    ok=1;
                }
                if(matrix[variaveis][restricoes]>0)
                {
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
    {   float coeficientes[restricoes];
        float coeficiente=0,maior=0;
       int posMenorCoeficiente = 0;

        //encontrando o menor coeficiente
        for(cont=1; cont<=restricoes; cont++)
        {
            if(matrix[cont][menorZ]!=0) {
           coeficientes[cont]=matrix[cont][restricoes+variaveis+1]/ matrix[cont][menorZ];
            printf("\nLinha %d - coeficiente %f\n",cont,matrix[cont][restricoes+variaveis+1]/ matrix[cont][menorZ]);
        }
        else {
             coeficientes[cont] = -1;
        }
    }
    float menorCoefifiente=coeficientes[0];
    float maiorCoefifiente=coeficientes[0];
    for(cont=1; cont<=restricoes; cont++){
            printf("Tabela coeficientes:%f\n",coeficientes[cont]);
     if ( coeficientes[cont]>0 &&  coeficientes[cont]>maiorCoefifiente)
            {
            printf("coe maior %f\n", coeficientes[cont]);
            maiorCoefifiente=matrix[cont][menorZ];
            posMenorCoeficiente = cont;
            maior= coeficientes[cont];
            }
            if ( coeficientes[cont]>0 &&  coeficientes[cont]<menorCoefifiente)
            {
                 printf("coe menor%f\n", coeficientes[cont]);
               menorCoefifiente=matrix[cont][menorZ];
                posMenorCoeficiente = cont;
                maior= coeficientes[cont];
            }
    }
       printf("\nValor do menor Coeficiente  %f",maior);
       printf("\nValor na tabela do Coeficiente: %f\n",matrix[posMenorCoeficiente][menorZ]);
        return posMenorCoeficiente;
    }
    void SubistituiLinha(int linhaPivo, float Coeficiente)
    {
        printf("\nSubistitui Linha do pivo atual %d / Elemento pivô: %f",linhaPivo,Coeficiente);


        for(cont=0; cont<restricoes+variaveis+2; cont++)
        {
            if(Coeficiente !=0 )
            {
            matrix[linhaPivo][cont] = matrix[linhaPivo][cont]/Coeficiente;
            }
            else
            {
             matrix[linhaPivo][cont]= matrix[linhaPivo][cont];
            }
        }
    }

    //Subistitui todas linhas, pegando sua linha, menos o coeficiente da linha * pivô
    void SubistituiTodasLinhas(int linhaPivo,int ColunaMenorZ2)
    {
        for(cont=0; cont<restricoes+1; cont++)
        {
            float pivorlinha = matrix[cont][ColunaMenorZ2];
            for(cont2=0; cont2<restricoes+variaveis+2; cont2++)
            {
                if(cont!=linhaPivo)
                {
                    matrix[cont][cont2] = matrix[cont][cont2] -(pivorlinha* matrix[linhaPivo][cont2]);
                }
                else
                {

                }
            }
        }
    }

    while(verificaPositivos(matrix))
    {
        if(verificaModelo() ==1)
        {
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
        printf("\nMatrizFinal");
        ImprimeMatriz();
    }
    return 0;
}
