#pragma once
#include <string>
#include "GrandHelper.h"
#include "Gyun.h"
#include <vector>

class Tribe {
private:

	std::string tribeName;
	std::vector<Gyun> members;
	int crystals;

public:

	Tribe(std::string = "Soleema B", int startingCystals = 0);

	// Party Management / Actions

	void AddMember(const Gyun& newMember);

	Gyun& GetMember(int index); // no const This is so combat can modify the data.

	int GetMemberCount() const; // for Game to know how many fighters there are.


	// Status & Currency / Getters

	std::string GetTribeName() const;

	int GetCrystals() const;

	void AddCrystals(int amount);

	bool isDefeated() const;

	void DisplayParty() const;



};