#include <stdio.h>
#include <stdlib.h>

int main()
{
    int linhas =0,colunas=0, cont=0,cont2=0;

    printf("====================================================\nDigite a quantidade de linhas:\n");
    scanf("%d",&linhas);
    printf("====================================================\nDigite a quantidade de colunas:\n");
    scanf("%d",&colunas);
    float matrix[linhas][colunas];

//seta os valores na matriz
    for(cont=0; cont<linhas; cont++)
    {
        printf("====================================================\nDigite a restricao %d:\n",cont);
        for(cont2=0; cont2<colunas; cont2++)
        {

            scanf("%f",&matrix[cont][cont2]);
        }
    }


    int MenorValordeZ() {
    float menor=matrix[0][0],maior=matrix[0][0];
    int posMenor=0;
    for(cont=0; cont<linhas; cont++)
    {
        printf("\n");
        for(cont2=0; cont2<colunas; cont2++)
        {
            //verifica o maior valor negativo de z
            printf("%f ",matrix[cont][cont2]);
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
    }
    printf("menorZ: %f, posicao: %d",menor,posMenor);
    return posMenor;
   }

    void EncontraCoeficiente(int menorZ)
    {
        float coeficiente=0;
        float menorCoefifiente=matrix[0][menorZ];
        int posMenorCoeficiente;
        float maiorCoefifiente=matrix[0][menorZ];
        //encontrando o menor coeficiente
        for(cont=0; cont<linhas; cont++)
        {
            coeficiente=matrix[linhas][colunas]/ matrix[cont][menorZ];
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
    }
    while(variaveis<0){
            posMenor = MenorValordeZ();
            EncontraCoeficiente(posMenor);
    }

return 0;
}
