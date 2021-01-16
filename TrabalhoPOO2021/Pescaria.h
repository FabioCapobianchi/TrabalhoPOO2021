
#ifndef PESCARIA_H
#define PESCARIA_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <climits>
#include <stdlib.h>
#include<stdio.h>

using namespace std;

#include "Territorio.h"

class Mundo;

class Pescaria :public Territorio {
   
public:
    Pescaria(string tipo);
    string criaNome();
    Territorio* duplica()const override;
};

#endif /* PESCARIA_H */

