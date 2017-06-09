#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "area.h"
#include "polygon.h"

char** stringSplit(char* subject, const char delimiter, int expectedParts);
void printUsage(char* command);

int main(int argc, char *argv[]) {
    if (1 == argc) {
        printUsage(argv[0]);
        return -1;
    }

    int i;
    char **splittedString;
    double *xc;
    double *yc;
    double *newX;
    double *newY;
    int corners = argc - 1;
    double area;

    xc = (double*) malloc(corners * sizeof (*xc));
    yc = (double*) malloc(corners * sizeof (*yc));

    newX = (double*) malloc(1 * sizeof (*xc));
    newY = (double*) malloc(1 * sizeof (*yc));

    for (i = 1; i <= corners; i++) {
        splittedString = stringSplit(argv[i], ':', 2);
        if (NULL == splittedString) {
            printUsage(argv[0]);
            return -1;
        }

        *(xc + i - 1) = strtod(splittedString[0], NULL);
        *(yc + i - 1) = strtod(splittedString[1], NULL);
        free(splittedString);
    }

    area = normalizedArea(xc, yc, &corners);
    free(xc);
    free(yc);

    if (area != -1) {
        printf("Obliczona powierzchnia %f\n", area);
    } else {
        printf("Error, poligon powinien posiadac przynajmniej trzy wierzcholki\n");
        return -1;
    }
    return 0;
}

void printUsage(char* command) {
    printf("Podaj: %s X0:Y0 ... Xn:Yn\n", command);
}

char** stringSplit(char* subject, const char delimiter, int expectedParts) {
    char** result = 0;
    size_t count = 0;
    char* tmp = subject;
    char* last_comma = 0;
    char delim[2];
    delim[0] = delimiter;
    delim[1] = 0;

    while (*tmp) {
        if (delimiter == *tmp) {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    count += last_comma < (subject + strlen(subject) - 1);
    count++;

    result = malloc(count * sizeof (char*));

    if (result) {
        size_t idx = 0;
        char* token = strtok(subject, delim);

        while (token) {
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        *(result + idx) = 0;

        if (expectedParts > 0 && expectedParts != idx) {
            return NULL;
        }
    }

    return result;
}

