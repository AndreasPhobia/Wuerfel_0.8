#include "DamageDice.h"
#include <iostream>
using namespace std;

// Konstruktor von DamageDice: Initialisiert den Würfel und den Schadensbonus
DamageDice::DamageDice(int s, int b) : Dice(s), bonus(b) {}

//roll() -Methode von DamageDice: Fügt den Schadensbonus zum Ergebnis hinzu
int DamageDice::roll() const {
	int result = Dice::roll(); // Führt den normalen Wurf durch
	cout << "Shaden + Bonus: " << bonus << endl;
	return result + bonus; // fügt den Bonus hinzu
}
