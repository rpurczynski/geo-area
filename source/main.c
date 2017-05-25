#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "area.h"
#include "perimeter.h"

int main(void)
{
  double xc[] = {2,  2, 10, 10,  2};
  double yc[] = {2, 10,  2, 10,  2};
  int corners = 5;
  double newX[100];
  double newY[100];
  if (true == polygonPerimeter(xc, yc, &corners, newX, newY)) {
    printf("Normalized polygon has %d corners\n", corners);
    printf("Total area %f\n", polygonArea(newX, newY, corners));    
  }
}

