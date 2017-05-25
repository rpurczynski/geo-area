#include <math.h>
#include "const.h"
#include "angle.h"

double angleOf(double x, double y)
{
  double  dist=sqrt(x*x+y*y);

  if (y>=0.0) {
    return acos(x/dist);
  } else {
    return acos(-x/dist)+0.5*CIRCLE_RADIANS;
  }
}

