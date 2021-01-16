
#ifndef PESCADA_H
#define PESCADA_H

#include<string>
using namespace std;

#include "Territorio.h"

class Mundo;
class Duna: public Territorio{
  
public:
    Duna(string tipo);
    string criaNome();
    Territorio * duplica()const override;
};

#endif /* PESCADA_H */

