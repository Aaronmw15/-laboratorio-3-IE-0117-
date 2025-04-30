#include <stdio.h>
//funciones necesarias
int min(int arreglo[], int tamaño) {
    int min = arreglo[0];
    for (int i = 1; i < tamaño; i++) {
        if (arreglo[i] < min)
            min = arreglo[i];
    }
    return min;
}

int max(int arreglo[], int tamaño) {
    int max = arreglo[0];
    for (int i = 1; i < tamaño; i++) {
        if (arreglo[i] > max)
            max = arreglo[i];
    }
    return max;
}

//main
int main(){

int matriz[3][3]={1,2,3    //declaramos una matriz
                 ,4,5,6
                 ,7,8,9};

//note que cada elemento pertenece a dos diagonales al mismo tiempo, se distinguiran entre diagonales de tipo A y tipo B
int celdas[3][100];//creamos una matriz donde la fila 0 corresponde al valor de una casilla y la fila 1 al numero de diagonal de tipo A y la fila 2 será el numero de tipo B 

    //recorrer la matriz por diagonales y clasificar valores
    int contador_celdas = 0;
    for (int fila=0; fila<=2;fila++){
        for(int columna=0; columna<=2;columna++){ //recorremos la matriz
            
            //para separar las diagonales, vamos a seguir dos criterios
            
            int tipoA=fila-columna;//las diagonales que van de izquierda-arriba a derecha-abajo, se cuentan en la misma diagonal las que si se resta filas-columnas, da el mismo resultado; estas serán de tipo A
            int tipoB=fila+columna;//las diagonales que van de izquierda-abajo a derecha-arriba, se cuentan en la misma diagonal las que si se suma filas+columnas, da el mismo resultado; estas serán de tipo B
            int valor= matriz[fila][columna];//tomamos el valor guardado en la matriz

            //guardamos en celdas, la informacion
            celdas[0][contador_celdas] = valor;
            celdas[1][contador_celdas] = tipoA;
            celdas[2][contador_celdas] = tipoB;
            
            contador_celdas++;

            //esto es sólo paara verificar el proceso de guardado
            //printf("celda (%i,%i)\n" , fila, columna);
            //printf("valor [%i] guardado\n", valor);
            //printf("tipoA [%i] guardado\n", tipoA);
            //printf("\n");
        }
    }
    // despues de recorrer la matriz, toca sumar los numeros que tengan el mismo numero de tipoA y los que tengan el mismo tipoB

    for (int tipo=1;tipo<=2;tipo++){//este for realiza la suma primero para tipoA y luego para tipoB
        printf("\nProcesando diagonales tipo%c:\n", (tipo == 1) ? 'A' : 'B');//mensaje para saber cuales diagonales estamos buscando
        int minimo=min(celdas[tipo], contador_celdas);
        int maximo=max(celdas[tipo], contador_celdas);

        for (int diagonal=minimo; diagonal<=maximo; diagonal++){//en orden de numero de diagonal, sumamos todos los numeros con ese numero
            int suma=0;
            for (int indice=0;indice<contador_celdas;indice++){//recorremos la matriz celdas
                if (celdas[tipo][indice]==diagonal){ //si encontramos un elemento con el numero de tipo que estamos buscando lo sumamos 
                    suma+=celdas[0][indice];
                    printf("sumado \n");
                }
                

            }
            printf("Diagonal [%d] suma = %d\n", diagonal, suma);
        }
   }

return 0;
}