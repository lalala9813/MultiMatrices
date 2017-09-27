#include <iostream>
#include <stdlib.h>//Libreria para poder usar el new y delete

using namespace std;

int **matrizA,**matrizB,**matrizC,nFilasA,nColA,nFilasB,nColB,**pm=matrizC,p=0;//Mis variables globales
void inicializar()//Funcion que inicializa mis matrices
{
    //************************************************************************************
    matrizA = new int*[nFilasA];
    for(int i=0;i<nFilasA;i++)
    {
        matrizA[i]=new int[nColA];
    }
    //************************************************************************************
    matrizB = new int*[nFilasB];
    for(int i=0;i<nFilasB;i++)
    {
        matrizB[i]=new int[nColB];
    }
    //************************************************************************************
    matrizC = new int*[nColA];
    for(int i=0;i<nColA;i++)
    {
        matrizC[i] = new int[nFilasB];
    }
    //************************************************************************************
}
void pedir()//Funcion que pide los datos al usuario como las dimensiones de las matrices y los elementos de estas
{
    cout << "Datos de tu primera matriz\n\n";
    //************************************************************************************
    cout << "Dame el numero de FilasA -> ";
    cin >> nFilasA;
    cout << "Dame el numero de ColumnasA -> ";
    cin >> nColA;
    //************************************************************************************
    cout << "\nDatos de tu segunda matriz\n\n";
    //************************************************************************************
    cout << "Dame el numero de FilasB -> ";
    cin >> nFilasB;
    cout << "Dame el numero de columnasB -> ";
    cin >> nColB;
    inicializar();
    cout << "\n";
    //************************************************************************************
    for(int i=0;i<nFilasA;i++)//Le pide los elementos a la matriz
    {
        for(int j=0;j<nColA;j++)
        {
            cout << "Dame mis numeros["<<i<<"]["<<j<<"]: ";
            cin>>*(*(matrizA+i)+j);

        }
    }
    cout << "\n";
    //************************************************************************************

    for(int i=0;i<nFilasB;i++)//Le pide los elementos a la matriz
    {
        for(int j=0;j<nColB;j++)
        {
            cout << "Dame mis numeros["<<i<<"]["<<j<<"]: ";
            cin>>*(*(matrizB+i)+j);

        }
    }
}

void imprimir(int **matrizA,int nFilasA,int nColA,int **matrizB,int nFilasB,int nColB,int **matrizC)/*Funcion que imprime mis matrices
como la A, la B y la C(La C es mi matriz resultante)*/
{
    //************************************************************************************
    cout << "\nTu primera Matriz\n";
    for(int i=0;i<nFilasA;i++)
    {
        for(int j=0;j<nColA;j++)
        {
            cout << *(*(matrizA+i)+j)<<" ";
        }
        cout << "\n";
    }
    cout << "\n";
    //************************************************************************************
    cout << "\nTu segunda Matriz\n";
    for(int i=0;i<nFilasB;i++)
    {
        for(int j=0;j<nColB;j++)
        {
            cout << *(*(matrizB+i)+j)<<" ";
        }
        cout << "\n";
    }
    //************************************************************************************
    if(nColA==nFilasB)//verificacion si es que podemos multiplicar las matrices
    {
        cout << "\nTu Multiplicacion de las Matrices\n";
        for(int i=0;i<nFilasA;i++)
        {
            for(int j=0;j<nColB;j++)
            {
                cout << *(*(matrizC+i)+j)<<" ";
            }
            cout << "\n";
        }
    }
    else
    {
        cout << "\n" << "********************MENSAJITO*******************";
        cout << "\n" << "ERROR no podemos multiplicar esta matrices \n";
    }

}
/*-----------------------------------------------------------------------------------------------------------------------------*/
/*Intento de multiplicacion de matrices por RECURSION no lo pude implemetar en mi main de la forma correcta
se me cerraba la pantalla osea pedia datos y los guardaba pero no multiplicaba*/

/*
void tercerfor(int **matrizA,int **matrizB,int **matrizC,int nFilasA,int nColB,int i,int j,int k)
{
        *(*(matrizC+i)+j)+=(*(*(matrizA+i)+k))*(*(*(matrizB+k)+j));
        tercerfor(matrizA,matrizB,matrizC,nFilasA,nColB,i,j,k+1);
}
void segundofor(int **matrizA,int **matrizB,int **matrizC,int nFilasA,int nColB,int i,int j)
{
        *(*(matrizC+i)+j)=0;
        tercerfor(matrizA,matrizB,matrizC,nFilasA,nColB,i,j,0);
        segundofor(matrizA,matrizB,matrizC,nFilasA,nColB,i,j+1);
}
void primerfor(int **matrizA,int **matrizB,int **matrizC,int nFilasA,int nColB,int i)
{
        segundofor(matrizA,matrizB,matrizC,nFilasA,nColB,i,0);
        primerfor(matrizA,matrizB,matrizC,nFilasA,nColB,i+1);
}
*/
void multi(int **matrizA,int **matrizB,int **matrizC,int nFilasA, int nColB, int nColA)//Funcion que multiplica mis Matrices
{
    //INTENTO DE LLAMADO DE MIS FUNCIONES
    /*primerfor(matrizA,matrizB,matrizC,nFilasA,nColB,0);
    segundofor(matrizA,matrizB,matrizC,nFilasA,nColB,0,0);
    tercerfor(matrizA,matrizB,matrizC,nFilasA,nColB,0,0,0);*/

    //FORMA ITERATIVO DISCULPE PROFESOR
    for(int i=0;i<nFilasA;i++)
    {
        for(int j=0;j<nColB;j++)
        {
            *(*(matrizC+i)+j)=0;
            for(int k=0;k<nColA;k++)
            {
                *(*(matrizC+i)+j)+=(*(*(matrizA+i)+k))*(*(*(matrizB+k)+j));
            }
        }
    }
}
/*-----------------------------------------------------------------------------------------------------------------------------*/

int main()//FUNCION PRINCIPAL
{
    //LLAMANDO A MIS FUNCIONES
    pedir();
    multi(matrizA,matrizB,matrizC,nFilasA,nColB,nColA);
    imprimir(matrizA,nFilasA,nColA,matrizB,nFilasB,nColB,matrizC);

    //BORRANDO EL ESPACIO ALMACENADO
    for(int i=0;i<nFilasA;i++)
    {
        delete[] matrizA[i];
    }
    delete[] matrizA;

    for(int i=0;i<nFilasB;i++)
    {
        delete[] matrizB[i];
    }
    delete[] matrizB;
    for(int i=0;i<nFilasA;i++)
    {
        delete[] matrizC[i];
    }
    delete[] matrizC;

    return 0;
}
