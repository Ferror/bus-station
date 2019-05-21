#include <stdio.h>
#include <time.h>
#include <string.h>
#include "header/temp.h"

struct Ticket {
    int connectionCode;
    char* startingPoint;
    char* startingDate;

};

int main(int argc, const char* argv[]) {
    FILE* source = fopen("/Users/zbyszek/Projects/Ferror/bus-station/input.txt", "rt");

    if (argv[1] != NULL && strcmp(argv[1], "-i") == 0) {
        if (argv[2] == NULL) {
            printf("Argument -i potrzebuje sciezki do pliku wejsciowego\n");

            return 0;
        }

        printf("Wczytuje plik z lini polecen: %s\n", argv[2]);
        source = fopen(argv[2], "rt");
    }

    if (source == NULL) {
        printf("Nie znaleziono pliku z danymi!\n");
        printf("Pamietaj, ze moze byc potrzebna sciezka absolutna pliku\n");
        
        return 0;
    }

    struct tm result;
    char* string1[255];
    char* startingPoint[255];
    char* startingDate[255];
    char* seatNumber[255];
    char* passengerName[255];

    while(fscanf(source, "%s %s %s %s %s", string1, startingPoint, startingDate, seatNumber, passengerName) == 5) {
        printf("%s %s %s %s\n", string1, startingPoint, startingDate, seatNumber, passengerName);
        strptime(startingDate, "%Y-%m-%d", &result);
        printf("%d\n", result.tm_year + 1900);
    }

    if (is_it_working() == 1) {
        printf("\nIt is!\n");
    } else {
        printf("It isnt\n");
    }

    return 0;
}
