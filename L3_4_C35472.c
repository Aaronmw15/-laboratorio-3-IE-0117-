#include <stdio.h>

int main(){
    //entrada del numero decimal por parte del usuario
    int numero;
    printf(" digite un número positivo");
    scanf("%i", &numero);

    //"conversion" a binario
    int binario[32];//32 ya que es el tamaño máximo de un entero en c
    int contador=0; //un contador para marcar las posiciones en el arreglo
    while(numero>=1){     //el while se detiene al llegar a 1
        binario[contador]=numero%2; //guardamos el modulo de la division entre dos
        numero/=2; //divide
        contador++; //aumenta el contador
    }

    //impresion
    for (int i=contador-1; i>=0;i--){
        printf("%i", binario[i]);
    }
    printf("\n");
}