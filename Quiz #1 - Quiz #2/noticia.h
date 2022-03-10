#include <iostream>
#include <vector>

using namespace std;

#ifndef NOTICIA_H
#define NOTICIA_H

class noticia {
protected:
    string titulo;
    string fecha; 
    string reportero;

public:
    virtual void getInfo() = 0;
};

#endif