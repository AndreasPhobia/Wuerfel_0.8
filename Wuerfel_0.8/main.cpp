#include "MagicDice.h"
#include "DamageDice.h"
#include "SkillDice.h"

using namespace std;

// Diese Funktion steuert den Ablauf des Würfelns
void DiceAndRoll() {
	int diceType; // Variable für den vom Benutzer gewählten Würfel
	int Rolls; // Anzahl der Würfe
	int totalPoints = 0; // Variable für die Summe aller gewürfelten Punkte 
	Dice* selectedDice = nullptr; // Zeiger auf den ausgewählten Würfel

	// Auswahl des Würfeltyps
	cout << "Waehle einen Wuerfel: \n";
	cout << "1. W4\n";
	cout << "2. W6\n";
	cout << "3. W8\n";
	cout << "4. W10\n";
	cout << "5. W20\n";
	cout << "6. W100\n";
	cout << "7. Magischer W6\n";
	cout << "8. Schadenswurf W12\n";
	cout << "9. Faehigkeitswurf W10 mit Skill-Bonus.\n";
	cin >> diceType; // Benutzer wählt den Würfeltyp

	// Erstelle den entsprechenden Würfel basierend auf der Benutzereingabe
	switch (diceType) {
	case 1: selectedDice = new Dice(4); // normaler W4
		break;
	case 2: selectedDice = new Dice(6); // normaler W6
		break;
	case 3: selectedDice = new Dice(8); // normaler W8
		break;
	case 4: selectedDice = new Dice(10); // normaler W10
		break;
	case 5: selectedDice = new Dice(20); // normaler W20
		break;
	case 6: selectedDice = new Dice(100); // normaler W100
		break;
	case 7: selectedDice = new MagicDice(6); // Magischer W6
		break;
	case 8: selectedDice = new DamageDice(12, 3); // Schadenswürfel W12 +3
		break;
	case 9: selectedDice = new SkillDice(10); // Skillwürfel W10 mit Benutzerdefiniertem Bonus
		break;
	default: cout << "Ungueltige Wahl!" << endl; // Wenn die Auswahl ungültig ist
	}

	// Abfrage, wie oft der Benutzer würfeln mochte
	cout << "Wie viele Wuerfel?";
	cin >> Rolls;

	// führt die Anzahl der gewünschten Würfe durch
	for (int i = 0; i < Rolls; ++i) {
		int result = selectedDice->roll(); // Ergebnis jedes Wurfs
		cout << "Wurf " << (i + 1) << ": " << result << endl;
		totalPoints += result; // Summe der gewürfelten Punkte
	}

	// Gesamtergebnis anzeigen
	cout << " Gesamtsumme: " << totalPoints << endl;

	// Löschen des ausgewählten Würfels
	delete selectedDice;
}

int main() {
	srand(time(0)); // Zufallsgenerator

	char repeat = 'y'; // Variable zur Steuerung der Wiederholung des Programms
	while (repeat == 'y') {
		DiceAndRoll(); // Aufruf der Funktion zum Würfeln
		cout << "Erneut wuerfeln? (y/n): ";  // Fragt den Benutzer, ob er erneut würfeln möchte
		cin >> repeat;
	}
	return 0;
}