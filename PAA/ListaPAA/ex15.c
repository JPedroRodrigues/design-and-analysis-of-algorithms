#include <stdio.h>

typedef struct {
    int hour;
    int minutes;
} Time;

Time sumTime(int minutes, Time t) {
    t.hour += (t.minutes + minutes) / 60;
    t.minutes = (t.minutes + minutes) % 60;

    return t;
}

int main() {
    Time t;
    int min;

    printf("Digite o número de horas: "); scanf("%d", &t.hour);
    printf("Digite o número de minutos: "); scanf("%d", &t.minutes);
    printf("Digite os minutos a serem somados ao horário digitado: "); scanf("%d", &min);

    printf("Horário digitado: %d:%dh\nMinutos a serem somados: %d min\n", t.hour, t.minutes, min);

    t = sumTime(min, t);

    printf("Tempo atualizado: %d:%dh\n", t.hour, t.minutes);
    return 0;
}