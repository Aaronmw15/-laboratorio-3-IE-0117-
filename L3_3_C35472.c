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

#define TAMANO 5
int encontrar_diagonal_mas_larga(int matriz[TAMANO][TAMANO]) {
// reutilizamos  codigo del ejercicio 2 para organizar la matriz por diagonales
int celdas[2][100];//creamos una matriz donde la fila 0 corresponde al valor de una casilla y la fila 1 al numero de diagonal de tipo A y la fila 2 será el numero de tipo B 
    //recorrer la matriz por diagonales y clasificar valores
    int contador_celdas = 0;
    for (int fila=0; fila<TAMANO ;fila++){
        for(int columna=0; columna<TAMANO;columna++){ //recorremos la matriz
            //para separar las diagonales, vamos a seguir dos criterios
            int tipoB=fila+columna;//las diagonales que van de izquierda-abajo a derecha-arriba, se cuentan en la misma diagonal las que si se suma filas+columnas, da el mismo resultado; estas serán de tipo B
            int valor= matriz[fila][columna];//tomamos el valor guardado en la matriz
            //guardamos en celdas, la informacion
            celdas[0][contador_celdas] = valor;
            celdas[1][contador_celdas] = tipoB;
            contador_celdas++;
}
}
//al terminar con esto nos queda una matriz que anota el orden para recorrer las celdas por diagonales
//reccorremos nuevamente la matriz en este orden
    int secuencia=0;//esta lleva la cuenta de unos
    int secuencia_max=0;//esta guarda la cuenta más grande registrada

    int minimo=min(celdas[1], contador_celdas);//para ambos recorridos, encontramos el menor y el mayor para conocer el orden para recorrerlos
    int maximo=max(celdas[1], contador_celdas);//esto funciona porque los numeros de diagonal terminan siguiendo una secuencia creciente para ambos casos


    for (int diagonal=minimo; diagonal<=maximo; diagonal++){//en orden de numero de diagonal, evaluamos si el valor guardado es uno o cero
        for (int indice=0;indice<contador_celdas;indice++){//recorremos la matriz celdas
            if (celdas[1][indice]==diagonal){ //si encontramos un elemento con el numero de tipo que estamos buscando lo evaluamos
                if(celdas[0][indice]==1){
                secuencia+=1; //si el elemento es uno, aumentamos la secuencia
                    if (secuencia>secuencia_max){
                        secuencia_max=secuencia;//si la cuenta supera a la mayor encontrada, la actualizamos
                    }
                }
                else{
                    secuencia=0;//si el elemento es cero, la secuencia se reinicia
                }

            }
            

        }
       
    }
    //al terminar, guardamos la secuencia para comparar la mas larga de los dos recorridos
    return secuencia_max;
}

int main() {
int matriz[TAMANO][TAMANO] = {
{0, 1, 1, 1, 0},
{0, 1, 1, 1, 1},
{1, 1, 1, 1, 0},
{0, 1, 1, 0, 1},
{1, 0, 1, 0, 1},
};
int diagonal_mas_larga = encontrar_diagonal_mas_larga(matriz);
printf("La secuencia de 1s más grande es: %d\n", diagonal_mas_larga);
return 0;
}















