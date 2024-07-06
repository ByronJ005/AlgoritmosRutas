/**
 * @file Floyd.c
 * @author Bayron Jimenez
 * @brief 
 * @version 0.1
 * @date 2024-06-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define infinito  100000
void Floyd(int n, int matriz[n][n]);
void imprimirMatricesAct(int n,int matrizDistancias [n][n],int matrizRecorridos [n][n]);
void llenarMatrices(int n, int matrizOriginal[n][n],int matrizDistancias [n][n],int matrizRecorridos [n][n]);

int main (){
    printf("Ingrese el numero de nodos: ");
    int n;
    scanf("%i",&n);
    
    /*printf("¿Grafo dirigido: 1, No dirigido: 2? ");
    int grafo;
    scanf("%i",&grafo);*/

    //Llenar matriz
    int matriz [n][n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            matriz[i][j] = infinito;
    }
        
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(i != j){
                    printf("Ingrese el peso del arco entre %i y %i (0 en caso de no existir arco): ", i + 1, j + 1); // Pasar de nodo 0-1 a 1-2...
                    int nodo;
                    scanf("%i", &nodo);
                    if(nodo!=0){
                       matriz[i][j] = nodo;     
                    }
            }else{
                matriz[i][j] = 0;
            }
        }
    }
    printf("Matriz: \n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%i\t",matriz[i][j]);
        }
        printf("\n");
    }
    /*int ini, fin;
    printf("Ingrese el nodo inicial: ");
    scanf("%i",&ini);
    printf("Ingrese el nodo final: ");
    scanf("%i",&fin);
    printf("Calculando ruta entre %i y %i ...\n",ini+1,fin+1);*/
    printf("Obteniendo matriz de distancias y recorridos...\n");
    Floyd(n,matriz);
    return 0;
}

void llenarMatrices(int n, int matrizOriginal[n][n],int matrizDistancias [n][n],int matrizRecorridos [n][n]){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            matrizDistancias[i][j] = matrizOriginal[i][j];
            if(i!=j){
                matrizRecorridos[i][j] = j;//Ver si sumamos aqui o despues
            }else{
                matrizRecorridos[i][j] = 0;
            }
        }
    }
}

void imprimirMatricesAct(int n,int matrizDistancias [n][n],int matrizRecorridos [n][n]){
    printf("Matriz de distancias: \n");
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                printf("%i\t",matrizDistancias[i][j]);
            }
            printf("\n");
        }

        printf("Matriz de recorrido: \n");
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if(i!=j){
                    printf("%i\t",matrizRecorridos[i][j] + 1);
                }else{
                    printf("0\t");
                }
                /*int recorrido = matrizRecorridos[i][j];
                if(recorrido!=0){
                    printf("%i\t", recorrido + 1);
                }else{
                    
                }*/
            }
            printf("\n");
        }
}

void Floyd(int n, int matriz[n][n]){
    int matrizDistancias [n][n];
    int matrizRecorridos [n][n];

    llenarMatrices(n,matriz,matrizDistancias,matrizRecorridos);
    for (int i = 0; i < n; i++){//Este es el valor de K
        //Fila
        for (int j = 0; j < n; j++){
            if(i!=j && matrizDistancias[i][j] != infinito){
                for (int x = 0; x < n; x++){
                        if(i!=x){//Para no comparar el elemento del pivote con la interseccion
                            //declarar suma arriba;
                            int suma = matrizDistancias[i][j] + matrizDistancias[x][i];
                            //printf("Sumando %i con %i da: %i\n",matrizDistancias[i][j],matrizDistancias[x][i],suma);
                            if((suma) < matrizDistancias[x][j]){
                                matrizDistancias[x][j] = suma;
                                matrizRecorridos[x][j] = i;
                                //printf("Entramos y ahora matrizDistancias[x][j] vale %i y matrizRecorridos[x][j] vale %i\n",matrizDistancias[x][j],matrizRecorridos[x][j]);
                            }
                        }
                    } 
            }
            /*if(matrizDistancias[i][j] != infinito){//Intersecciones no consideramos y tampoco el infinito
                if(i!=j){
                    //printf("Estoy en %i, el elemento del pivote\n",matrizDistancias[i][j]);
                    for (int x = 0; x < n; x++){
                        if(i!=x){//Para no comparar el elemento del pivote con la interseccion
                            //declarar suma arriba;
                            int suma = matrizDistancias[i][j] + matrizDistancias[x][i];
                            //printf("Sumando %i con %i da: %i\n",matrizDistancias[i][j],matrizDistancias[x][i],suma);
                            if((suma) < matrizDistancias[x][j]){
                                matrizDistancias[x][j] = suma;
                                matrizRecorridos[x][j] = i;
                                //printf("Entramos y ahora matrizDistancias[x][j] vale %i y matrizRecorridos[x][j] vale %i\n",matrizDistancias[x][j],matrizRecorridos[x][j]);
                            }
                        }
                    } 
                }
                       
            }*/   
                //Columna
                //K = 3
                // [3][0..1..2..3]
                //Por cada elemento de la fila, hago un recorrido
                // evaluando siempre [1][3] [2][3] -- [4][3] [5][3]
                // Y si son menores 
        }
        
        printf("Analizando K = %i\n",i+1);
        imprimirMatricesAct(n,matrizDistancias,matrizRecorridos);
    }
}