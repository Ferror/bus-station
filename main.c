#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "header/temp.h"

struct Passenger {
    char* name;
    unsigned int seatNumber;

    struct Passenger* next;
};

struct Bus {
    long connectionCode;
    long amountOfPassengers;
    char* startingPoint;
    char* startingDate;

    struct Bus* next;
    struct Passenger* passengers;
};

struct Bus* busList = NULL;

int main(int argc, const char* argv[]) {
    FILE* source = fopen("/Users/zbyszek/Projects/Ferror/bus-station/test/input/in_example_single.txt", "rt");

    if (argv[1] != NULL && strcmp(argv[1], "-i") == 0) {
        fclose(source);

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
    struct Bus* tmpBus = (struct Bus*) malloc(sizeof(struct Bus));
    struct Passenger* tmpPassenger = (struct Passenger*) malloc(sizeof(struct Passenger));

    char* connectionCode[255];
    char* startingPoint[255];
    char* startingDate[255];
    char* seatNumber[255];
    char* passengerName[255];

    while(fscanf(source, "%s %s %s %s %s", connectionCode, startingPoint, startingDate, passengerName, seatNumber) == 5) {
        printf("SOURCE: %s %s %s %s %s\n", connectionCode, startingPoint, startingDate, passengerName, seatNumber);

        //to separate function to remove else statement and not having double while
        if (/* Bus for connectionCode & startingPoint & startingDate exists */ 1) {
            //create passenger
            //add passenger to bus BY seatNumber
            //increment number of passengers
        } else {
            //add passenger to bus BY seatNumber
            //increment number of passengers
        }

        tmpPassenger->next = NULL;
        tmpPassenger->name = passengerName;
        tmpPassenger->seatNumber = strtol(seatNumber, (char **) NULL, 10);

        tmpBus->connectionCode = strtol(connectionCode, (char **) NULL, 10);
        tmpBus->startingDate = startingDate;
        tmpBus->startingPoint = startingPoint;
        tmpBus->next = NULL;
        tmpBus->passengers = tmpPassenger;
        printf("STRUCT: %ld %s %s %s %u\n", tmpBus->connectionCode, tmpBus->startingPoint, tmpBus->startingDate, tmpPassenger->name, tmpPassenger->seatNumber);

        //RESULT
        //list to file service
        //count amount of passengers


        //strptime(startingDate, "%Y-%m-%d", &result);
        //printf("%d\n", result.tm_year + 1900);
    }


    fclose(source);
    free(busList);
    free(tmpPassenger);
    free(tmpBus);
    return 0;
}
