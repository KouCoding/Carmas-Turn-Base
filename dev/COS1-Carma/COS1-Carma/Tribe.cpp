#include "Tribe.h"

Tribe::Tribe(std::string, int startingCrystals) : crystals(startingCrystals) {}

void Tribe::AddMember(const Gyun& newMember) 
{
	return members.push_back(newMember);
}

Gyun& Tribe::GetMember(int index) 
{
	return members.at(index);
}

int Tribe::GetMemberCount() const 
{			 
	
	auto it = members.begin();

	for (it; it != members.end(); ) {
		

	}

}

std::string Tribe::GetTribeName() const 
{
	return tribeName;
}

int Tribe::GetCrystals() const 
{
	return crystals;
}

void Tribe::AddCrystals(int amount) 
{
	crystals +=amount;
}

bool Tribe::isDefeated() const 
{
	for (const Gyun& member : members) {
		
		if (member.IsAlive() == true)
		{
			return false;
		}
		
	}

	return true;
}


void Tribe::DisplayParty() const 
{	

	for ( const Gyun& member : members) 
	{
		GrandHelper::WriteLine(member);
	}
}