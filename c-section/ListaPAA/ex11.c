#include <stdio.h>
#include <stdlib.h>

#define FLIGHTS 1

typedef struct {
    int flightNumber, airplaneNumber, seatsNumber;
    float price;
} airplaneData;


void flightData(airplaneData v[], int n) {
    
    for (int i = 0; i < n; i++) {
        printf("Número do vôo: "); scanf("%d", &v[i].flightNumber);
        printf("Tipo de avião: "); scanf("%d", &v[i].airplaneNumber);
        printf("Preço da passagem: "); scanf("%f", &v[i].price);
        printf("Quantidade de assentos: "); scanf("%d", &v[i].seatsNumber);
    }
}


int main() {
    airplaneData tripData[FLIGHTS];
    flightData(tripData, FLIGHTS);

    int resNumber;
    printf("Quantidade de reservas a serem lidas: "); scanf("%d", &resNumber);

    int identity, flyNumber;
    for (int i = 0; i < resNumber; i++) {
        printf("Número de identidade do passageiro: "); scanf("%d", &identity);
        printf("Número do vôo desejado: "); scanf("%d", &flyNumber);
        for (int j = 0; j < FLIGHTS; j++) {
            if (flyNumber == tripData[j].flightNumber && tripData[i].seatsNumber > 0) {
                printf("\n|===| RESERVA |===| \n");
                printf("Número da identidade do passageiro: %d\n", identity);
                printf("Número do vôo: %d\n", tripData[j].flightNumber);
                printf("Preço da passagem: %.2f\n", tripData[j].price);
                printf("RESERVA CONFIRMADA.\n\n");

                tripData[j].seatsNumber -= 1;
            } else {
                printf("Número da identidade do passageiro: %d\n", identity);
                printf("Número do vôo: %d\n", tripData[j].flightNumber);
                printf("VÔO LOTADO.\n\n");

                break;
            }
        }
    }
}