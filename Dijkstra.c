/**
 * @file fibonacci.c
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
void Dijkstra(int n, int a, int matriz[n][a],int nodoIni, int nodoFin);

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
            matriz[i][j] = -1;
    }
        
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(i != j){
                    printf("Ingrese el peso del arco entre %i y %i (0 en caso de no existir arco): ", i + 1, j + 1); // Pasar de nodo 0-1 a 1-2...
                    int nodo;
                    scanf("%i", &nodo);
                    matriz[i][j] = nodo;
                    /*if (matriz[i][j] == -1){
                        printf("Ingrese el peso del arco entre %i y %i (0 en caso de no existir arco): ", i + 1, j + 1); // Pasar de nodo 0-1 a 1-2...
                        int nodo;
                        scanf("%i", &nodo);
                        matriz[i][j] = nodo;*/
                    /*if (grafo = 1)
                        matriz[j][i] = 0;
                    else
                        matriz[j][i] = nodo;
                    }*/
                        /*if (grafo != 1)
                            matriz[j][i] = nodo;    
                    }*/
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
    int ini, fin;
    printf("Ingrese el nodo inicial: ");
    scanf("%i",&ini);
    printf("Ingrese el nodo final: ");
    scanf("%i",&fin);
    printf("Calculando ruta entre %i y %i ...\n",ini+1,fin+1);
    Dijkstra(n,n,matriz,ini,fin);
    return 0;
}

void Dijkstra (int n, int a, int matriz[n][a], int nodoIni, int nodoFin){
    bool estadoNodo [n];//Perm = True - Temp = False
    int distanciaNodo [n];//Distancias finales
    int procedente [n];//Guardar su predecesor final

    for (int i = 0; i < n; i++){//Inicializamos
        estadoNodo[i] = false;
        distanciaNodo[i] = 0;
        procedente[i] = 0;
    }
    
    int actual = nodoIni;
    estadoNodo[nodoIni] = true;
    do{
        int auxMenor = 0;
        for (int i = 0; i < n; i++){
            if(matriz[actual][i] != 0){//Ver si están conectados en la matriz de adyacencias
                if (estadoNodo[i] == false){ // Si el nodo adyacente es temporal, lo analizamos, si es permanente pasamos al siguiente
                    int dist_adyacente = distanciaNodo[i];//Sacamos la distancia almacenada del adyacente

                    int distTemporal = distanciaNodo[actual] + matriz[actual][i];//Sumamos la distancia del actual con el peso de su adyacente
                    if (dist_adyacente == 0 || distTemporal < dist_adyacente){
                        distanciaNodo[i] = distTemporal;
                        procedente[i] = actual+1;
                    }
                }
            }
        }
        printf("Nodo \t Etiqueta \t Estado\n");//Impresión de ruta
        for (int k = 0; k < n; k++){
            printf("%i \t [%i,%i] \t %s\n", k + 1, distanciaNodo[k], procedente[k], estadoNodo[k] ? "Permanente" : "Temporal");
        }

        for (int j = 0; j < n; j++){//Recorrer todos los temporales y ver el menor
            int distAdyacente = distanciaNodo[j];
            if(estadoNodo[j] == false && distAdyacente != 0){//Ver que sea temporal y que su distancia no sea 0
                if (auxMenor == 0){
                    auxMenor = distAdyacente;
                    actual = j;
                }
                if (distAdyacente < auxMenor){
                    auxMenor = distAdyacente;
                    actual = j;
                }
            }
        }
        estadoNodo[actual] = true; //cambiar actual al menor de los temporales
        printf("Nodo \t Etiqueta \t Estado\n");//Impresión de ruta
        for (int k = 0; k < n; k++){
            printf("%i \t [%i,%i] \t %s\n", k + 1, distanciaNodo[k], procedente[k], estadoNodo[k] ? "Permanente" : "Temporal");
        }
    } while (estadoNodo[nodoFin] == false);//Mientras el estado del nodoFin sea Temporal. Si pasa a Perma, paramos
    
    /*printf("Nodo \t Etiqueta \t Estado\n");//Impresión de ruta
    for (int k = 0; k < n; k++){
        printf("%i \t [%i,%i] \t %s\n",k+1,distanciaNodo[k],procedente[k], estadoNodo[k] ? "Permanente" : "Temporal");    
    }*/
    printf("La ruta tuvo un costo de %i y fue: %i ",distanciaNodo[nodoFin],nodoFin+1);
    int v_procedente = procedente[nodoFin];
    do{
        printf("<--  %i ",v_procedente);
        v_procedente = procedente[v_procedente - 1];
    } while (v_procedente != 0);
}