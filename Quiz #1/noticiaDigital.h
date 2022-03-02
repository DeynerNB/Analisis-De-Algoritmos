#include "noticia.h"

#ifndef NOTICIADIGITAL_H
#define NOTICIADIGITAL_H

class noticiaDigital : public noticia {
protected:
    vector<string> video;
    vector<string> audio;
    vector<string> fotos;

public:
    noticiaDigital(string titulo,
                   string fecha,
                   string reportero,
                   vector<string> video,
                   vector<string> audio,
                   vector<string> fotos);

    void getInfo() override;
};

noticiaDigital::noticiaDigital(string titulo, string fecha, string reportero,
    vector<string> video, vector<string> audio, vector<string> fotos) {
        this->titulo = titulo;
        this->fecha = fecha;
        this->reportero = reportero;
        this->video = video;
        this->audio = audio;
        this->fotos = fotos;
};

void noticiaDigital::getInfo() {
    cout << "\n\n > Noticia Digital";
    cout << "\nTitulo: " + this->titulo; 
    cout << "\nFecha: " + this->fecha; 
    cout << "\nReportero: " + this->reportero; 
    
    cout << "\nArchivos Video:\n";
    for (string m : video)
        cout << "\t" + m << endl;
    cout << "\nArchivos Audio:\n";
    for (string m : audio)
        cout << "\t" + m << endl;
    cout << "\nArchivos Fotos:\n";
    for (string m : fotos)
        cout << "\t" + m << endl; 
};


#endif