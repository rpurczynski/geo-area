#include <math.h>

double polygonArea(double *xCoords, double *yCoords, int points)
{

  double  area=0.0;
  int     i, j=points - 1;

  for (i=0; i<points; i++) {
    area += (xCoords[j] + xCoords[i])*(yCoords[j] - yCoords[i]);
    j=i;
  }

  return area*0.5;
}
