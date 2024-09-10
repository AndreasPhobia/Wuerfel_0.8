#include "MagicDice.h"
#include "DamageDice.h"
#include "SkillDice.h"

using namespace std;

// Diese Funktion steuert den Ablauf des W�rfelns
void DiceAndRoll() {
	int diceType; // Variable f�r den vom Benutzer gew�hlten W�rfel
	int Rolls; // Anzahl der W�rfe
	int totalPoints = 0; // Variable f�r die Summe aller gew�rfelten Punkte 
	Dice* selectedDice = nullptr; // Zeiger auf den ausgew�hlten W�rfel

	// Auswahl des W�rfeltyps
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
	cin >> diceType; // Benutzer w�hlt den W�rfeltyp

	// Erstelle den entsprechenden W�rfel basierend auf der Benutzereingabe
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
	case 8: selectedDice = new DamageDice(12, 3); // Schadensw�rfel W12 +3
		break;
	case 9: selectedDice = new SkillDice(10); // Skillw�rfel W10 mit Benutzerdefiniertem Bonus
		break;
	default: cout << "Ungueltige Wahl!" << endl; // Wenn die Auswahl ung�ltig ist
	}

	// Abfrage, wie oft der Benutzer w�rfeln mochte
	cout << "Wie viele Wuerfel?";
	cin >> Rolls;

	// f�hrt die Anzahl der gew�nschten W�rfe durch
	for (int i = 0; i < Rolls; ++i) {
		int result = selectedDice->roll(); // Ergebnis jedes Wurfs
		cout << "Wurf " << (i + 1) << ": " << result << endl;
		totalPoints += result; // Summe der gew�rfelten Punkte
	}

	// Gesamtergebnis anzeigen
	cout << " Gesamtsumme: " << totalPoints << endl;

	// L�schen des ausgew�hlten W�rfels
	delete selectedDice;
}

int main() {
	srand(time(0)); // Zufallsgenerator

	char repeat = 'y'; // Variable zur Steuerung der Wiederholung des Programms
	while (repeat == 'y') {
		DiceAndRoll(); // Aufruf der Funktion zum W�rfeln
		cout << "Erneut wuerfeln? (y/n): ";  // Fragt den Benutzer, ob er erneut w�rfeln m�chte
		cin >> repeat;
	}
	return 0;
}