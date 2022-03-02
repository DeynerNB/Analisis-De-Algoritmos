#include "noticiaDigital.h"
#include "noticiaPaper.h"
#include "noticiaRadio.h"

/*
 * Analisis de Algoritmos
 * Herencia de clases, polimorfismo y punteros
 *
 * > Quiz #1 - Deyner Navarro Badilla
 *
*/

int main() {

    // Vector de noticia
    vector<noticia*> noticias;

    // Parametros para los metodos getInfo
    string nombreNoticia = "Caso Fenix";
    string fechaNoticia = "28 de febrero";
    string reporteroNoticia = "Eillyn Jimenez";
    string arch_Foto = "fotoArch.png";
    vector<string> archVideo = {"video1.mov", "video2.mov", "video3.mov", "video4.mov", "video5.mov"};
    vector<string> archAudio = {"audio1.mp3", "audio2.mp3", "audio3.mp3", "audio4.mp3", "audio5.mp3"};
    vector<string> archFotos = {"foto1.png", "foto2.png", "foto3.png", "foto4.png", "foto5.png"};
    string url_Audio = "radioAudio.mp3";


    // Instancias de las clases noticiaPaper, noticiaDigital, noticiaRadio
    noticiaPaper *Paper = new noticiaPaper(nombreNoticia, fechaNoticia, reporteroNoticia, arch_Foto);
    noticiaDigital *Digital = new noticiaDigital(nombreNoticia, fechaNoticia, reporteroNoticia, archVideo, archAudio, archFotos);
    noticiaRadio *Radio = new noticiaRadio(nombreNoticia, fechaNoticia, reporteroNoticia, url_Audio);
    
    // Insercion de las instancias al vector noticia
    noticias.push_back(Paper);
    noticias.push_back(Digital);
    noticias.push_back(Radio);

    // Ciclo for para polimorfismo de getInfo
    for(noticia* n : noticias)
        n->getInfo();

    // Liberar memoria de las instancias
    delete Paper;
    delete Digital;
    delete Radio;

    return 0;
}