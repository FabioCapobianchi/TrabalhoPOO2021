
#ifndef FORTALEZA_H
#define FORTALEZA_H

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

class Fortaleza :public Territorio {
    
public:
    Fortaleza(string tipo);
    string criaNome();

   // void alimentar(int quant, Mundo* mundo) override;
    Territorio* duplica()const override;
};

#endif /* FORTALEZA_H */

