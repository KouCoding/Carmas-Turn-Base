// This header file is for the creation of the Gyun ( which are humans in the Grand Ile world )
// And declare any methods that are going to be used in its creation.
#pragma once
#include <string>




class Gyun {
private:

	std::string tribe;
	std::string name;
	int currentHealth;
	int maxHealth;
	int attack;
	int defense;
	int soul;

public:

	// Constructor
	Gyun(std::string playerTribe = "no tribe", std::string playerName = "Sam", int playerHealth = 100, int playerMaxHealth = 100, int attackP = 15, int defenseP = 5, int playerSoul = 20);
	
	// Getters

	std::string GetTribe() const;
	
	std::string GetName() const;

	int GetHealth() const;

	int GetAttack() const;

	int GetDefense() const;

	int GetSoul() const;

	bool IsAlive() const;

	// Action Member Variables

	void TakeDamage(int damage);

	void Heal(int amount);

	void DisplayStats() const;
};