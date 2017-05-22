#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define CIRCLE_RADIANS 6.283185307179586476925286766559
#define MAX_SEGS 1000

double angleOf(double x, double y);
bool lineSegmentIntersection(double Ax, double Ay,double Bx, double By,double Cx, double Cy,double Dx, double Dy,double *X, double *Y);
bool polygonPerimeter(double *x, double *y, int *corners, double *newX, double *newY);

double angleOf(double x, double y)
{
  double  dist=sqrt(x*x+y*y);

  if (y>=0.0) {
    return acos(x/dist);
  } else {
    return acos(-x/dist)+0.5*CIRCLE_RADIANS;
  }
}

bool polygonPerimeter(double *x, double *y, int *corners, double *newX, double *newY)
{
  double  segSx[MAX_SEGS], segSy[MAX_SEGS], segEx[MAX_SEGS], segEy[MAX_SEGS];
  double  segAngle[MAX_SEGS], intersectX, intersectY;
  double  startX=x[0], startY=y[0], lastAngle=.5*CIRCLE_RADIANS, turnAngle;
  double  a, b, c, d, e, f, angleDif, bestAngleDif;
  int     i, j=(*corners)-1, segs=0;

  if ((*corners)>MAX_SEGS) {
    return false;
  }

  for (i=0; i<(*corners); i++) {
    if (x[i]!=x[j] || y[i]!=y[j]) {
      segSx[segs]=x[i];
      segSy[segs]=y[i];
      segEx[segs]=x[j];
      segEy[segs++]=y[j];
    }
    j=i;
    if (y[i]>startY || y[i]==startY && x[i]<startX) {
      startX=x[i];
      startY=y[i];
    }
  }
  if (segs==0) {
    return false;
  }

  for (i=0; i<segs-1; i++) {
    for (j=i+1; j<segs; j++) {
      if (lineSegmentIntersection(segSx[i],segSy[i],segEx[i],segEy[i],segSx[j],segSy[j],segEx[j],segEy[j],&intersectX,&intersectY)) {
        if ((intersectX!=segSx[i] || intersectY!=segSy[i]) && (intersectX!=segEx[i] || intersectY!=segEy[i])) {
          if (segs==MAX_SEGS) {
            return false;
          }
          segSx[segs]=segSx[i];
          segSy[segs]=segSy[i];
          segEx[segs]=intersectX;
          segEy[segs++]=intersectY;
          segSx[i]=intersectX;
          segSy[i]=intersectY;
        }
        if ((intersectX!=segSx[j] || intersectY!=segSy[j]) &&  (intersectX!=segEx[j] || intersectY!=segEy[j])) {
          if (segs==MAX_SEGS) {
            return false;
          }
          segSx[segs]=segSx[j];
          segSy[segs]=segSy[j];
          segEx[segs]=intersectX;
          segEy[segs++]=intersectY;
          segSx[j]=intersectX;
          segSy[j]=intersectY;
        }
      }
    }
  }

  for (i=0; i<segs; i++) {
    segAngle[i]=angleOf(segEx[i]-segSx[i],segEy[i]-segSy[i]);
  }

  c=startX;
  d=startY;
  a=c-1.0;
  b=d;
  newX[0]=c;
  newY[0]=d;
  *corners=1;
  while (true) {
    bestAngleDif=CIRCLE_RADIANS;
    for (i=0; i<segs; i++) {
      if (segSx[i]==c && segSy[i]==d && (segEx[i]!=a || segEy[i]!=b)) {
        angleDif=lastAngle-segAngle[i];
        while (angleDif>=CIRCLE_RADIANS) {
          angleDif-=CIRCLE_RADIANS;
        }
        while (angleDif<0) {
          angleDif+=CIRCLE_RADIANS;
        }
        if (angleDif<bestAngleDif) {
          bestAngleDif=angleDif;
          e=segEx[i];
          f=segEy[i];
        }
      }
      if (segEx[i]==c && segEy[i]==d && (segSx[i]!=a || segSy[i]!=b)) {
        angleDif=lastAngle-segAngle[i]+0.5*CIRCLE_RADIANS;
        while (angleDif>=CIRCLE_RADIANS) {
          angleDif-=CIRCLE_RADIANS;
        }
        while (angleDif<0) {
          angleDif+=CIRCLE_RADIANS;
        }
        if (angleDif<bestAngleDif) {
          bestAngleDif=angleDif;
          e=segSx[i];
          f=segSy[i];
        }
      }
    }
    if ((*corners)>1 && c==newX[0] && d==newY[0] && e==newX[1] && f==newY[1]) {
      (*corners)--;
      return true;
    }
    if (bestAngleDif==CIRCLE_RADIANS || (*corners)==MAX_SEGS) {
      return false;
    }
    newX[*corners]=e;
    lastAngle-=bestAngleDif+0.5*CIRCLE_RADIANS;
    newY[(*corners)++]=f;
    a=c;
    b=d;
    c=e;
    d=f;
  }
}

bool lineSegmentIntersection(double Ax, double Ay,double Bx, double By,double Cx, double Cy,double Dx, double Dy,double *X, double *Y) {

  double distAB, theCos, theSin, newX, ABpos;

  if (Ax==Bx && Ay==By || Cx==Dx && Cy==Dy) {
    return false;
  }

  if (Ax==Cx && Ay==Cy || Bx==Cx && By==Cy ||  Ax==Dx && Ay==Dy || Bx==Dx && By==Dy) {
    return false;
  }

  Bx-=Ax;
  By-=Ay;
  Cx-=Ax;
  Cy-=Ay;
  Dx-=Ax;
  Dy-=Ay;

  distAB=sqrt(Bx*Bx+By*By);

  theCos=Bx/distAB;
  theSin=By/distAB;
  newX=Cx*theCos+Cy*theSin;
  Cy=Cy*theCos-Cx*theSin;
  Cx=newX;
  newX=Dx*theCos+Dy*theSin;
  Dy=Dy*theCos-Dx*theSin;
  Dx=newX;

  if (Cy<0.0 && Dy<0.0 || Cy>=0.0 && Dy>=0.0) {
    return false;
  }

  ABpos=Dx+(Cx-Dx)*Dy/(Dy-Cy);

  if (ABpos<0.0 || ABpos>distAB) {
    return false;
  }

  *X=Ax+ABpos*theCos;
  *Y=Ay+ABpos*theSin;

  return true;
}
