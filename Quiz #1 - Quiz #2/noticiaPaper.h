#include "noticia.h"

#ifndef NOTICIAPAPER_H
#define NOTICIAPAPER_H

class noticiaPaper : public noticia {
protected:
    string arch_Foto;

public:
    noticiaPaper(string titulo,
                 string fecha,
                 string reportero,
                 string arch);

    void getInfo() override;

};

noticiaPaper::noticiaPaper(string titulo, string fecha, string reportero, string arch) {
    this->titulo = titulo;
    this->fecha = fecha;
    this->reportero = reportero;
    this->arch_Foto = arch;
};

void noticiaPaper::getInfo() {
    cout << "\n\n > Noticia Paper";
    cout << "\nTitulo: " + this->titulo; 
    cout << "\nFecha: " + this->fecha; 
    cout << "\nReportero: " + this->reportero; 
    cout << "\nArchivo Foto: " + this->arch_Foto; 
}

#endif