#include "noticia.h"

#ifndef NOTICIARADIO_H
#define NOTICIARADIO_H

class noticiaRadio : public noticia {
protected:
    string url_Audio;

public:
    noticiaRadio(string titulo,
                 string fecha,
                 string reportero,
                 string url_Audio);

    void getInfo() override;

};

noticiaRadio::noticiaRadio(string titulo, string fecha, string reportero, string url_Audio) {
    this->titulo = titulo;
    this->fecha = fecha;
    this->reportero = reportero;
    this->url_Audio = url_Audio;
};

void noticiaRadio::getInfo() {
    cout << "\n\n > Noticia Radio";
    cout << "\nTitulo: " + this->titulo; 
    cout << "\nFecha: " + this->fecha; 
    cout << "\nReportero: " + this->reportero; 
    cout << "\nURL Audio: " + this->url_Audio;
};

#endif