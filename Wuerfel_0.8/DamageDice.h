#pragma once
#include "Dice.h"

// Kindklasse für den Schadenswürfel
class DamageDice :
    public Dice
{ 
private: 
    int bonus; // speichert den Schadensbonus

public:
    // Konstrukto: Initialisiert den Schadenswürfel mit Seiten und Bonus
    DamageDice(int s, int b);

    // Überschreibt die roll() -Methode, um den Schadensbonus zum Ergebnis hinzuzufügen
    int roll() const override;

};

