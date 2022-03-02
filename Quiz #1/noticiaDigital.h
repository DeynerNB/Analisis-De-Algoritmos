#include "noticia.h"

#ifndef NOTICIADIGITAL_H
#define NOTICIADIGITAL_H

class noticiaDigital : public noticia {
protected:
    vector<string> media;

public:
    noticiaDigital(string titulo,
                   string fecha,
                   string reportero,
                   vector<string> media);

    void getInfo() override;
};

noticiaDigital::noticiaDigital(string titulo, string fecha, string reportero, vector<string> media) {
        this->titulo = titulo;
        this->fecha = fecha;
        this->reportero = reportero;
        this->media = media;
};

void noticiaDigital::getInfo() {
    cout << "\n\n > Noticia Digital";
    cout << "\nTitulo: " + this->titulo; 
    cout << "\nFecha: " + this->fecha; 
    cout << "\nReportero: " + this->reportero; 
    cout << "\nArchivos Media:\n";
    for (string m : media)
        cout << "\t" + m << endl; 
};


#endif