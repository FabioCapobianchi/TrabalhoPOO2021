
#ifndef REFUGIO_H
#define REFUGIO_H

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

class Refugio :public Territorio {
    
public:
    Refugio(string tipo);
    string criaNome();

    //void alimentar(int quant, Mundo* mundo) override;
    Territorio* duplica()const override;
};

#endif /* REFUGIO_H */

