#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "header/temp.h"

struct Passenger {
    char* name;
    unsigned long seatNumber;

    struct Passenger* next;
};

struct Bus {
    unsigned long connectionCode;
    unsigned long amountOfPassengers;
    char* startingPoint;
    char* startingDate;

    struct Bus* next;
    struct Passenger* passengers;
};

struct Bus* busList = NULL;

int isBusForConnectionCode(unsigned long connectionCode)
{
    struct Bus* tmp = busList;

    while (tmp != NULL) {
        if (tmp->connectionCode == connectionCode) {
            return 1;
        }

        tmp = tmp->next;
    }

    return 0;
}

//@todo function isBusDuplicated
int isBusDuplicated(unsigned long connectionCode, char* city, char* date)
{
    struct Bus* tmp = busList;

    while (tmp != NULL) {
        if (tmp->connectionCode == connectionCode) {
            if (strcmp(city, tmp->startingPoint) == 1) {
                if (strcmp(date, tmp->startingDate)) {
                    return 1;
                }
            }
        }

        tmp = tmp->next;
    }

    free(tmp);

    return 0;
}

void addPassengerToBusBySeat(unsigned long connectionCode, char* name, unsigned long seatNumber)
{
    struct Bus* bus = busList;

    while (bus != NULL && bus->connectionCode != connectionCode) {
        bus = bus->next;
    }

    struct Passenger* tmp = (struct Passenger*) malloc(sizeof(struct Passenger));

    if (bus != NULL) {
        tmp->name = name;
        tmp->seatNumber = seatNumber;
        tmp->next = busList->passengers;

        bus->passengers = tmp;
        bus->amountOfPassengers += 1;
    }
}

void printBus(unsigned long connectionCode)
{
    struct Bus* tmp = busList;

    while (tmp != NULL && tmp->connectionCode != connectionCode) {
        tmp = tmp->next;
    }

    if (tmp != NULL) {
        printf("Symbol trasy: %lu\n", tmp->connectionCode);
        printf("Punkt startowy: %s\n", tmp->startingPoint);
        printf("Data: %s\n", tmp->startingDate);

        struct Passenger* passenger = tmp->passengers;

        while (passenger != NULL) {
            printf("%lu %s\n", passenger->seatNumber, passenger->name);
            passenger = passenger->next;
        }

        printf("Liczba rezerwacji: %lu\n\n", tmp->amountOfPassengers);
    }
}

int main(int argc, const char* argv[]) {
    FILE* source = fopen("/Users/zbyszek/Projects/Ferror/bus-station/test/input/in_example_double.txt", "rt");

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

//    struct tm result;
    char* connectionCode[255];
    char* startingPoint[255];
    char* startingDate[255];
    char* seatNumber[255];
    char* passengerName[255];

    while(fscanf(source, "%s %s %s %s %s", connectionCode, startingPoint, startingDate, passengerName, seatNumber) == 5) {
        //printf("SOURCE: %s %s %s %s %s\n", connectionCode, startingPoint, startingDate, passengerName, seatNumber);

        unsigned long code = strtol(strdup(connectionCode), (char **) NULL, 10);

        if (isBusForConnectionCode(code) == 0) {
            struct Bus* tmpBus = (struct Bus*) malloc(sizeof(struct Bus));
            //create new bus
            printf("Utworz nowy Bus\n");
            tmpBus->connectionCode = code;
            tmpBus->startingPoint = strdup(startingPoint);
            tmpBus->startingDate = strdup(startingDate);
            tmpBus->amountOfPassengers = 0;
            tmpBus->passengers = NULL;
            tmpBus->next = busList;
            busList = tmpBus;
        } else {
            printf("istnieje Bus nr: %lu\n", code);
        }
        //add passenger to bus BY seatNumber
        addPassengerToBusBySeat(code, strdup(passengerName), strtol(strdup(seatNumber), (char **) NULL, 10));

        //printf("STRUCT: %ld %s %s %s %u\n", tmpBus->connectionCode, tmpBus->startingPoint, tmpBus->startingDate, tmpPassenger->name, tmpPassenger->seatNumber);
        //RESULT
        //list to file service
        //count amount of passengers

        //strptime(startingDate, "%Y-%m-%d", &result);
        //printf("%d\n", result.tm_year + 1900);
    }

    if (isBusForConnectionCode(155) == 1) {
        printBus(155);
    }

    if (isBusForConnectionCode(156) == 1) {
        printBus(156);
    }

    if (isBusForConnectionCode(157) == 1) {
        printBus(157);
    }

    fclose(source);
    free(busList);
    return 0;
}
