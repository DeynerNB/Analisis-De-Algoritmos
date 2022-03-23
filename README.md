# Analisis-De-Algoritmos

## Quiz #1
En la carpeta se cuenta con el main y los archivos headers de las clases.

 - noticia.h: Clase Base de todas las demas.
 - noticiaDigital.h: Clase de NoticiaDigital.
 - noticiaPaper.h: Clase de NoticiaPaper.
 - noticiaRadio.h: Clase de NoticiaRadio.

## Caso #2
**InsertionSort**
En el caso del algoritmo insertion sort, realice 2 vector distintos, uno para experimentar el mejor caso
y otro para experimentar con el peor caso.

 - Ω(n) : Caso Lineal.

Para el mejor caso, se genero varios arreglos, cuyos tamanos van aumentando de 5.000.000 en 5.000.000, iniciando en 5.000.000 hasta 50.000.000 y todos llenos con elementos ya ordenados.

![Image text](https://github.com/DeynerNB/Analisis-De-Algoritmos/blob/master/Caso%20%232/images/InsertionSort_Lineal.png)

 - O(n^2) : Peor Caso

Para el peor caso, se genero varios arreglos, cuyos tamanos van aumentando de 5.000 en 5.000, iniciando en 5.000 hasta 50.000 y todos llenos con elementos ordenados de manera descendente.

![Image text](https://github.com/DeynerNB/Analisis-De-Algoritmos/blob/master/Caso%20%232/images/InsertionSort_Cuadratico.png)

**QuickSort**
Para el algoritmo quick sort, realice, de igual manera, dos vectores distintos, uno en el cual almacenar el mejor caso y otro para el peor caso, en ambos casos utilice el metodo de pivote fijo(el elemento del medio).

 - Ω(nlog(n)) : Caso Logaritmico.

Para el mejor caso, se genero varios arreglos, cuyos tamanos van aumentando de 50.000 en 50.000, iniciando en 50.000 hasta 500.000 y todos llenos con elementos ordenados ascendente cuyo pivote sea el elemento del centro.

![Image text](https://github.com/DeynerNB/Analisis-De-Algoritmos/blob/master/Caso%20%232/images/QuickSort_Logaritmico.png)

 - O(n^2) : Peor Caso

Para el peor caso, se genero varios arreglos, cuyos tamanos van aumentando de 5.000 en 5.000, iniciando en 5.000 hasta 50.000 y todos llenos con elementos aleatorios.

![Image text](https://github.com/DeynerNB/Analisis-De-Algoritmos/blob/master/Caso%20%232/images/QuickSort_Cuadratico.png)

**Para ambos algoritmos, insertionSort y quickSort, se tomo la cantidad de elementos y el tiempo que duro en ejecutarse, para luego graficarlos y observar que siguen o simulan la funcion de complejidad esperada.**

**FreeText**
Para el funcionamiento del algoritmo de FreeText, es necesario que el archivo de texto este en la misma carpeta que archivo freeText.cpp y el nombre del archivo de texto sea 'text.txt'.
Cuando se inicie el programa, el mismo va a solicitar la cadena a buscar, una vez ingresada, se da enter y el algoritmo comenzara a buscar el total de apariciones de la cadena en el texto.

