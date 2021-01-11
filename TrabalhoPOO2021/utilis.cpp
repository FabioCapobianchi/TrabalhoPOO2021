#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utilis.h"

#include <cstdlib>
#include<string>
#include<sstream>
#include<iostream>

void initRandom()
{
    srand(time(NULL));
}

int intUniformRnd(int a, int b)
{
    return a + rand()%(b-a+1);
}

