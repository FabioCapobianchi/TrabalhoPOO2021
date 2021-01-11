
#ifndef PLANICIE_H
#define PLANICIE_H

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

class Planicie :public Territorio{
    
public:
    Planicie(string tipo);
    string criaNome();
    
    //void alimentar( int quant , Mundo * mundo) override;
    Territorio * duplica()const override;
};

#endif /* PLANICIE_H */

