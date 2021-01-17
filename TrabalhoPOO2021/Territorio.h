

#ifndef TERRITORIO_H
#define	TERRITORIO_H

#include<string>
using namespace std;

class Mundo;

class Territorio {
      
    string tipo;
    int res;
    int prod;
    int ouro;
    int ptsv;
    
public:
    Territorio(string tipo0, int res0, int prod0, int ouro0, int ptsv0);
    Territorio( const Territorio & orig);
    virtual string getAsString()const;
    string getTipo() const;
    int getRes()const;
    int getProd()const;
    void setProd(int i);
    int getOuro()const;
    void setOuro(int i);
    int getptsv()const;
    virtual ~Territorio(){}
    virtual Territorio * duplica()const = 0;

	static Territorio * fabrica(string tipo);
};
ostream & operator<<(ostream & saida, const Territorio & x);
#endif	/* TERRITORIO_H */

