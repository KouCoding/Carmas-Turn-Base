// This is where we will define all methods for the creation of the Gyuns ( humans )
#include "Gyun.h"
#include "GrandHelper.h"


Gyun::Gyun(std::string playerTribe, std::string playerName, int playerHealth, int playerMaxHealth, int attackP, int defenseP, int playerSoul)
: tribe(playerTribe), name(playerName), currentHealth(playerHealth), maxHealth(playerMaxHealth), attack(attackP), defense(defenseP), soul(playerSoul) 
{
	// Safety check for overhealth.
	if (currentHealth > maxHealth)
	{
		currentHealth = maxHealth;
	}
}


std::string Gyun::GetTribe() const { return tribe; }

std::string Gyun::GetName() const { return name; }

int Gyun::GetHealth() const { return currentHealth; }

int Gyun::GetAttack() const { return attack; }

int Gyun::GetDefense() const { return defense; }

int Gyun::GetSoul() const { return soul; }

bool Gyun::IsAlive() const { return currentHealth > 0; }

void Gyun::TakeDamage(int damage) 
{
	// new variable to store damage - defense
	int actualDamage = damage - defense;

	// if the actual damage is clamped to 0 it stops defense from heal targets.
	if (actualDamage < 0)
	{
		damage = 0;
	}

	currentHealth = currentHealth - actualDamage;

	if (currentHealth < 0)
	{
		currentHealth = 0;
	}

}

void Gyun::Heal(int amount) 
{
	currentHealth = (currentHealth + amount); 

	// Heal Check to make sure overheal doesn't make health go past its max.
	if (currentHealth > maxHealth)
	{
		currentHealth = maxHealth;
	}
}

void Gyun::DisplayStats() const
{
	GrandHelper::WriteLine("Name: " + name);
	// Converted to string using std::to_string
	GrandHelper::WriteLine("Health: " + std::to_string(currentHealth));
	GrandHelper::WriteLine("Attack: " + std::to_string(attack));
	GrandHelper::WriteLine("Defense: " + std::to_string(defense));
	GrandHelper::WriteLine("Soul: " + std::to_string(soul));

}