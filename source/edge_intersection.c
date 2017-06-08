#include "edge_intersection.h"

bool lineSegmentIntersection(double Ax, double Ay, double Bx, double By, double Cx, double Cy, double Dx, double Dy, double *X, double *Y) {

    double distAB, theCos, theSin, newX, ABpos;

    if (Ax == Bx && Ay == By || Cx == Dx && Cy == Dy) {
        return false;
    }

    if (Ax == Cx && Ay == Cy || Bx == Cx && By == Cy || Ax == Dx && Ay == Dy || Bx == Dx && By == Dy) {
        return false;
    }

    Bx -= Ax;
    By -= Ay;
    Cx -= Ax;
    Cy -= Ay;
    Dx -= Ax;
    Dy -= Ay;

    distAB = sqrt(Bx * Bx + By * By);

    theCos = Bx / distAB;
    theSin = By / distAB;
    newX = Cx * theCos + Cy*theSin;
    Cy = Cy * theCos - Cx*theSin;
    Cx = newX;
    newX = Dx * theCos + Dy*theSin;
    Dy = Dy * theCos - Dx*theSin;
    Dx = newX;

    if (Cy < 0.0 && Dy < 0.0 || Cy >= 0.0 && Dy >= 0.0) {
        return false;
    }

    ABpos = Dx + (Cx - Dx) * Dy / (Dy - Cy);

    if (ABpos < 0.0 || ABpos > distAB) {
        return false;
    }

    *X = Ax + ABpos*theCos;
    *Y = Ay + ABpos*theSin;

    return true;
}

