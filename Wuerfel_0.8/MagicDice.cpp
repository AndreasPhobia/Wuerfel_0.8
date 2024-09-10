#include "MagicDice.h"
#include <iostream>
using namespace std;

// Konstruktor von MagicDice: Ruft den Konstruktor der Elternklasse Dice auf
MagicDice::MagicDice(int s) : Dice (s) {}

// roll() -Methode von MagicDice: fügt einen Bonus hinzu, wenn der höchste Wert geworfen wird
int MagicDice::roll() const {
	int result = Dice::roll(); // Führt den normalen Würfelwurf durch
	if (result == sides) { // Wenn die höchste Zahl gewordfen wird
		cout << "Magischer Bonus! Extra Punkte!" << endl;
		result += 5; // Füge 5 Bonuspunkte hinzu
	}
	return result;
}
