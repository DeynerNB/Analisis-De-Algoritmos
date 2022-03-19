#include <iostream>
#include <fstream>
using namespace std;




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
		return pointerPattern - badChar_Index;
	}
	else {
		return shiftPattern + pattern.length();
	}
}

int Boyer_Moore_GoodSufx(string text, string pattern, int pointerPattern, int pointerText, int shiftPattern) {
	if (shiftPattern <= 1) {
		return shiftPattern;
	}
	else {

		string subStringText = text.substr((pointerText + 1), shiftPattern);
		int aux_I;

		for (int i = 0; i < shiftPattern; i++) {
			aux_I = i;

			for (int j = 0; j <= (pointerPattern + i + 1) && (aux_I < subStringText.length()); j++) {
				if (subStringText[aux_I] == pattern[j]) {
					aux_I++;
				}
				else {
					aux_I = i;
				}
			}

			if (aux_I >= subStringText.length()) {
				return (subStringText.length() - i);
			}
		}

		return -1;
	}
}

int Boyer_Moore_Text(string text, string pattern) {

	if (pattern.length() > text.length())
		return 0;

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
			pointerText += (shiftPattern + numShift);

			shiftPattern = 0;
		}
	}

	return matches;
}

void readFile(string *text) {
	ifstream file("text2.txt");

	cout << "Opening file...\n";
	if (file.is_open()) {

		cout << "Reading file...\n";
		while(!file.eof()) {
			getline(file, *text);
		}

		cout << "File action completed!\n";
	}
	else {
		cout << "Failed open file!" << endl;
	}

	file.close();
}

int main() {

	string text;
	string pattern = "moving";
	readFile(&text);

	cout << text.length() << endl;

	cout << "\nIniciando proceso...\n";
	cout << Boyer_Moore_Text(text, pattern) << endl;
	cout << "Proceso finalizado...\n";


	return 0;
}

