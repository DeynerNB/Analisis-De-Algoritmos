#include <iostream>
#include <fstream>
#include <map>
#include <time.h>
using namespace std;

map<string, int> prefixPatternMap;

void initPrefixPatternMap(string pattern) {
	
	int patternLenght = pattern.length();

	for (int i = 0; i < (patternLenght - 1); i++) {
		prefixPatternMap.insert(make_pair(pattern.substr(0, i+1), i));
	}
}

int getCharIndex(string pattern, char letter, int sizePattern) {
	int index = -1;

	for (int i = 0; i < sizePattern; i++)
		if (pattern[i] == letter)
			return i;

	return index;
}

int Boyer_Moore_BadChar(string text, string pattern, int pointerPattern, int pointerText, int shiftPattern) {
	int badChar_Index = getCharIndex(pattern, text[pointerText], pointerPattern);

	if (badChar_Index != -1) {
		return shiftPattern + (pointerPattern - badChar_Index);
	}
	else {
		return shiftPattern + pointerPattern + 1;
	}
}

int Boyer_Moore_GoodSufx(string text, string pattern, int pointerPattern, int pointerText, int shiftPattern) {	

	if (shiftPattern <= 1) {
		return shiftPattern;
	}
	else {
		string subStringText = text.substr((pointerText + 1), shiftPattern);
		string subPattern;

		// Check for sufix inside the pattern
		for (int i = 0; i <= pointerPattern; i++) {
			subPattern = pattern.substr((pointerPattern - i), shiftPattern);
			if (subPattern == subStringText)
				return shiftPattern + (i + 1);
		}

		// Check for sufix of sufix in prefix of pattern
		while(subStringText.length() > 1) {
			subStringText.erase(0, 1);
			if (prefixPatternMap.find(subStringText) != prefixPatternMap.end())
				return shiftPattern + pointerPattern + 1;
		}

		return -1;
	}

}


int Boyer_Moore_Text(string text, string pattern) {

	if (pattern.length() > text.length())
		return 0;

	initPrefixPatternMap(pattern);

	int pointerPattern = pattern.length() - 1;
	int pointerText = pointerPattern;
	int shiftPattern = 0;
	int matches = 0;

	while(pointerText < text.length()) {
		if (text[pointerText] == pattern[pointerPattern]) {
			pointerPattern--;
			pointerText--;
			shiftPattern++;

			if (pointerPattern < 0) {
				matches++;
				
				pointerPattern += shiftPattern;
				pointerText += (shiftPattern + pattern.length());

				shiftPattern = 0;
			}
		}
		else {

			int numShift = max(
				Boyer_Moore_BadChar(text, pattern, pointerPattern, pointerText, shiftPattern),
				Boyer_Moore_GoodSufx(text, pattern, pointerPattern, pointerText, shiftPattern)
			);

			pointerPattern += shiftPattern;
			pointerText += numShift;

			shiftPattern = 0;
		}
	}

	return matches;
}

void readFile(string *text) {
	ifstream file("text.txt");

    cout << "Abriendo archivo...\n";
    if (file.is_open()) {

        cout << "Leyendo archivo...\n";
        while(!file.eof()) {
            getline(file, *text);
        }

        cout << "Archivo leido por completo!\n";
    }
    else {
        cout << "Fallo al intentar abrir el archivo!!!\n" << endl;
    }

    file.close();
}

void startFreeText() {
	string text;
    string pattern;
    int result = 0;
    unsigned t0, t1;

    // Get user input pattern
    cout << "\nIngrese el patron a buscar: ";
    getline(cin, pattern);

    readFile(&text);

    // Change pattern into lower case
    for (int i = 0; i < pattern.length(); i++)
        pattern[i] = tolower(pattern[i]);

    // Change file text into lower case
    cout << "\nConversion del archivo a minusculas iniciado...\n";
    t0 = clock();
    for (int i = 0; i < text.length(); i++)
        text[i] = tolower(text[i]);
    t1 = clock();
    cout << "Conversion del archivo a minusculas finalizado\n";
    cout << "Tiempo de la conversion: " << double(t1 - t0)/CLOCKS_PER_SEC << endl;

    int limitSize = text.length()/2000;
    string subText;

    cout << "\nProcesamiento freetext del archivo iniciado...\n";
    t0 = clock();
    for (int i = 0; i < text.length(); i += limitSize) {
        subText = text.substr(i, limitSize);

        while (text[i + limitSize] != ' ' && text[i + limitSize] != '\0') {
            subText += text[i + limitSize];
            i++;
        }

        result += Boyer_Moore_Text(subText, pattern);
    }
    t1 = clock();
    cout << "Procesamiento freetext del archivo finalizado!\n";
    cout << "Tiempo del procesamiento: " << double(t1 - t0)/CLOCKS_PER_SEC << endl;


    cout << "\nTotal de apariciones de '" << pattern << "': " << result << endl;
}

int main() {
	
	startFreeText();

	return 0;
}

