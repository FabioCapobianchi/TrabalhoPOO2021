
#ifndef MONTANHA_H
#define MONTANHA_H

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

class Montanha :public Territorio {
    
public:
    Montanha(string tipo);
    string criaNome();

    //void alimentar(int quant, Mundo* mundo) override;
    Territorio* duplica()const override;
};

#endif /* MONTANHA_H */


