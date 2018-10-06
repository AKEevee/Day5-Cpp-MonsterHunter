#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

class Weapon {
	public:
		std::string name;
		int element;
		int power;
};

class Monster {
	public:
		std::string name;
		int element;
		int health;
};

int randNumber(int maxRange) {
	return rand() % maxRange;
}

int main() {

	//Weapon Type Names
	std::string axe [4] = { "Axe", "Broadaxe", "Cleaver", "Hatchet" };
	std::string crossbow [4] = { "Crossbow", "Ballista", "Longbow", "Arbalest" };
	std::string flail [4] = { "Flail", "Chain", "Thresher", "Lash" };
	std::string mace [4] = { "Mace", "Hammer", "Gavel", "Crusher" };
	std::string staff [4] = { "Staff", "Ward", "Scepter", "Quarterstaff" };
	std::string sword [4] = { "Sword", "Edge", "Blade", "Saber" };

	//Elemental Type Names
	std::string fire [4] = { "Cinder", "Smoldering", "Infernal", "Fiery" };
	std::string frost [4] = { "Frosted", "Frozen", "Crystalline", "Icy" };
	std::string arcane [4] = { "Spellbound", "Hypnotic", "Magical", "Enchanted" };
	std::string poison [4] = { "Spiteful", "Venomous", "Blighted", "Toxic" };

	//Monster Type Names
	std::string fireMonster [4] = { "Demon", "Dragon", "Hellhound", "Skeleton" };
	std::string frostMonster [4] = { "Vampire", "Wendigo", "Ice Worm", "Ghoul" };
	std::string arcaneMonster [4] = { "Banshee", "Shapeshifter", "Fairy", "Unicorn" };
	std::string poisonMonster [4] = { "Basilisk", "Arachnid", "Imp", "Orc" };

	//Monster Descriptive Names
	std::string description [10] = { "malicious", "vicious", "vile", "savage", "murderous", "bloodthirsty", "ferocious", "fierce", "horrific", "gruesome" };

	//Location
	std::string location [4] = { "the fiery pits of Hell", "an underground ice cave", "a large, abandoned castle", "a mosquito-infested swamp" };

	int randWeapon;
	int randWeaponType;
	int randWeaponElementType;
	int randWeaponElement;

	std::string weaponType;
	std::string weaponElement;

	int randMonsterElementType;
	int randMonsterElement;
	int randMonsterDescription;

	std::string monsterType;
	std::string monsterElement;
	std::string monsterDescription;

	std::string where;

	int randWeaponPower;
	int randMonsterHealth;

	std::string playerChoice;

	int randRun;

	int remainingHealth;

	srand (time(NULL));

	randWeapon = randNumber(6);//There are six different types of weapons to choose from
	randWeaponType = randNumber(4);//There are 4 possible weapons in each weapon type category

	if ( randWeapon == 0 ) {
		weaponType = axe[randWeaponType];
	} else if ( randWeapon == 1 ) {
		weaponType = crossbow[randWeaponType];
	} else if ( randWeapon == 2 ) {
		weaponType = flail[randWeaponType];
	} else if ( randWeapon == 3 ) {
		weaponType = mace[randWeaponType];
	} else if ( randWeapon == 4 ) {
		weaponType = staff[randWeaponType];
	} else {
		weaponType = sword[randWeaponType];
	}

	randWeaponElementType = randNumber(4);//There are 4 possible weapon elements
	randWeaponElement = randNumber(4);//There are 4 possible element names within each type

	if ( randWeaponElementType == 0 ) {
		weaponElement = fire[randWeaponElement];
	} else if ( randWeaponElementType == 1 ) {
		weaponElement = frost[randWeaponElement];
	} else if ( randWeaponElementType == 2 ) {
		weaponElement = arcane[randWeaponElement];
	} else {
		weaponElement = poison[randWeaponElement];
	}

	randWeaponPower = 50 + 50 * randNumber(3);

	Weapon theWeapon;
	theWeapon.name = weaponElement + " " + weaponType;
	theWeapon.power = randWeaponPower;

	randMonsterElementType = randNumber(4);//There are 4 possible elemental monster types
	randMonsterElement = randNumber(4);//There are 4 possible monsters within each type 	

	if ( randMonsterElementType == 0 ) {
		monsterElement = fireMonster[randMonsterElement];
	} else if ( randMonsterElementType == 1 ) {
		monsterElement = frostMonster[randMonsterElement];
	} else if ( randMonsterElementType == 2 ) {
		monsterElement = arcaneMonster[randMonsterElement];
	} else {
		monsterElement = poisonMonster[randMonsterElement];
	}

	where = location[randMonsterElementType];
	randMonsterDescription = randNumber(10);//There are 10 possible words that can describe the monsters

	monsterDescription = description[randMonsterDescription];

	randMonsterHealth = 50 + 50 * randNumber(3);

	Monster theMonster;
	theMonster.name = monsterDescription + " " + monsterElement;
	theMonster.health = randMonsterHealth;

	std::cout << "You are walking through " << where << " when you stumble upon a " << theMonster.name << "!" << std::endl;
	std::cout << "\nWhat do you want to do? (Enter 0 to attack, 1 to run away in fear) " << std::endl;

	std::cin >> playerChoice;

	if( playerChoice == "1" ) {
		randRun = randNumber(2);

		if ( randRun == 0 ) {
			std::cout << "\nThe monster tries to attack you, but you manage to escape! For now..." << std::endl;
		} else {
			std::cout << "\nAs you turn to run away, the monster attacks and kills you.\nGame over, man! Game over!" << std::endl;
		}
	} else if ( playerChoice == "0" ) {
		std::cout << "\nYou look down and notice a pile of weapons lying nearby. With no time to spare, you leap toward the weapons and manage to grab a " << theWeapon.name << "!" << std::endl;
		std::cout << "Quickly! Make your attack! (Enter any character) " << std::endl;

		std::cin >> playerChoice;

		remainingHealth = theMonster.health - theWeapon.power;

		if ( remainingHealth <= 0 ) {
			std::cout << "\nYou did it! You defeated the " + theMonster.name + "!";
		} else {
			while ( remainingHealth > 0 ) {
				std::cout << "\nYour attack has weakened the monster, but it isn't dead yet. What do you want to do? (Enter 0 to attack, 1 to run away in fear) " << std::endl;
				std::cin >> playerChoice;

				if ( playerChoice == "1" ) {
					randRun = randNumber(2);

					if ( randRun == 0 ) {
						std::cout << "\nThe monster tries to attack you, but you manage to escape! For now..." << std::endl;
						break;
					} else {
						std::cout << "\nAs you turn to run away, the monster attacks and kills you.\nGame over, man! Game over!" << std::endl;
						break;
					}
				} else if ( playerChoice == "0" ) {
					remainingHealth = remainingHealth - theWeapon.power;

					if ( remainingHealth <= 0 ) {
						std::cout << "\nYou did it! You defeated the " + theMonster.name + "!";
					}

				} else {
					std::cout << "\nYour indecision has cost you your life. Game over.";
					break;
				}
			}
		}

	} else {
		std::cout << "\nYour indecision has cost you your life. Game over.";
	}

	return 0;
}