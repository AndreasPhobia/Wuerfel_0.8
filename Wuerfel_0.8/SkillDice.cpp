#include "SkillDice.h"
#include <iostream>
using namespace std;

// Konstruktor von SkillDice: Fragt den Benutzer nach einem Bonuswert
SkillDice::SkillDice(int s) : Dice(s) {
	cout << "Gib deinen Faehigkeitswert als Bonus ein: ";
	cin >> skillBonus; // Benutzer gibt den Bonuswert ein
}

// roll()-Methode von SkillDice: Fügt den benutzerdefinierten Skill-Bonus zum Würfelergebnis hinzu
int SkillDice::roll() const {
	int result = Dice::roll(); // Führt den normalen Wurf durch
	cout << "Faehigkeitsbonus: " << skillBonus << " hinzugefuegt." << endl;
	return result + skillBonus; // Füge den Skillbonus hizu
}