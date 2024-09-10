#pragma once
#include <iostream>
using namespace std;

// Eltern-Klasse für den Würfel
class Dice{
protected:
	int sides; // Anzahl der Seiten des Würfels (W6, W8, W10, etc.)

public:
	// Konstruktor: Initialisiert den Würfel mit einer bestimmten Anzahl von Seiten
	Dice(int s);

	//Methode zum Würfeln: Gibt eine zufällige Zahl zwischen 1 un der Anzahl der Seiten zurück
	virtual int roll() const;

	// Virtueller Destruktor: Wird verwendet, um sicherzustellen, dass Kindklassen korrekt gelöscht werden
	virtual ~Dice();
}; 

