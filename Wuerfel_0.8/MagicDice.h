#pragma once
#include "Dice.h"

// Kindklasse für den magischen Würfel
class MagicDice :
    public Dice
{ 
public:
    // Konstruktor: Initialisiert den magischen Würfel mit einer bestimmten Anzahl an Seiten
    MagicDice(int s);

    // Überschreibt die roll() -Methode, um einen Bonus hinzuzufügen, ernn die höchste Zahl geworfen wird
    int roll() const override;
};

