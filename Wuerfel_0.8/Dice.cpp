#include "Dice.h"
#include <iostream>
using namespace std;

// Konstruktor: Initialisiert den Würfel mit der Anzahl an Seiten
Dice::Dice(int s) : sides(s) {}

// roll() -Methode: Gibt eine zufällige Zahl zwischen 1 und der Anzahl der Seiten zurück
int Dice::roll() const {
	return (rand() % sides) + 1; // Zufallszahl zwischen 1 und sides
}

// Virtueller Destruktor
Dice::~Dice() {}