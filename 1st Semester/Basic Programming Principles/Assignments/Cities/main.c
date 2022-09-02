#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "routes.h"
#define STR 100000
int main()
{
 void * Dist;
 struct city *C;
 int n;
 C=GetCities(&n);
 Dist = Distances(C,n);
 GetRoutes(C,n, Dist);
 return 0;
}
