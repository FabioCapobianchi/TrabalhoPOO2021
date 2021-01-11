
#ifndef CASTELO_H
#define CASTELO_H

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

class Castelo :public Territorio {
    
public:
    Castelo(string tipo);
    string criaNome();

    //void alimentar(int quant, Mundo* mundo) override;
    Territorio* duplica()const override;
};

#endif /* CASTELO_H */

