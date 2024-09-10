#pragma once
#include "Dice.h"

// Kindklasse für den Skill-Würfel
class SkillDice :
    public Dice
{
private:
    int skillBonus; // Speichert den benutzerdefinierten Bonus

public:

    // Konstruktor: Initialisiert den Skill-Würfel und fragt den Benutzer nach einem Skillbonus
    SkillDice(int s);

    // Überscheibt die roll() -Methode, um den Skillbonus zum Ergebnis hinzufügen
    int roll() const override;
};
 