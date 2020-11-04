#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

enum charCard { ARMOUREDKNIGHT, RONIN, SPARTAN, JEDI };
enum wepCard { ZWEIHANDER, KATANA, GLADIUS, LIGHTSABER };

string charName[4]{ "ARMOURED KNIGHT","RONIN","SPARTAN","JEDI" }, wepName[4]{ "ZWIEHANDER","KATANA","GLADIUS","LIGHT SABER" };

class Player {
public:
	int lifePoints = 1000;
};

class Oponenet {
public:
	int lifePoints = 1000;
};

class Character {
public:
	string name;
	int strength, health, wield;
};

class Weapon {
public:
	string name;
	int minStrength, uses, attack;
};

class Upgrade {
public:
	string name;
	int minWield, uses, effect;
};

int wepPU;
int wepSel() {
	cout << "pick up a weapon card" << endl;
	cin.get();
	srand(time(0));
	wepPU = (rand() % 4);
	cout << "you picked up " << wepName[wepPU] << endl;
	return wepPU;
}

int oppWepPU;
int oppWepSel() {
	cout << "your OPPONENT has picked up a weapon card" << endl;
	cin.get();
	srand(time(0));
	oppWepPU = (rand() % 4);
	cout << " your OPPONENT picked up " << wepName[oppWepPU] << endl;
	return oppWepPU;
}

int charPU;
int charSel() {
	cout << "pick up a character card" << endl;
	cin.get();
	srand(time(0));
	charPU = (rand() % 4);
	cout << "you picked up " << charName[charPU] << endl;
	return charPU;
}

int oppCharPU;
int oppCharSel() {
	cout << "your OPPONENT has picked up a character card" << endl;
	cin.get();
	srand(time(0));
	oppCharPU = (rand() % 4);
	cout << " your OPPONENT picked up " << charName[oppCharPU] << endl;
	return oppCharPU;
}
bool winner;
bool youWin;
bool oppWins;

void winLose() {
	srand(time(0));
	Weapon currWep, oppCurrWep;
	currWep.name = wepName[wepPU];
	oppCurrWep.name = wepName[oppWepPU];
	currWep.attack = 2;
	oppCurrWep.attack = 1;

	Character currChar, oppCurrChar;
	currChar.name = charName[charPU];
	oppCurrChar.name = charName[oppCharPU];
	currChar.health = { 10 };
	oppCurrChar.health = { 10 };



	charSel();
	oppCharSel();
	wepSel();
	oppWepSel();




	cout << "its " << charName[charPU] << " holding a " << wepName[wepPU] << " vs " << charName[oppCharPU] << " holding a " << oppWepName[oppWepPU] << endl;

	cin.get();
	do {

		winner = false;
		char move("a", "u");
		int oppMove = 1;// RANDOM WHEN UPGRADES ARE DONE.
		cout << "do you want to deploy an attack card or an upgrade card? type 'a' or 'u': \n";
		cin >> move;

		if (move == 'a') {
			cout << "you attack " << charName[oppCharPU] << " with a " << wepName[currWep] << endl;
			cout << charName[oppCharPU] << "'s health is now at: " << (oppCurrChar.health -= currWep.attack) << endl;
			cin.get();
		}


		if (oppMove == 1)
			cout << "your opponent attacks " << charName[charPU] << endl;
		cout << charName[charPU] << "'s health is now at: " << (currChar.health -= oppCurrWep.attack) << endl;
		cin.get();
		if (oppCurrChar.health <= 0) {
			cin.get();
			cout << charName[charPU] << " wins" << endl;
			winner = true;
			youWin = true;
		}
		else if (currChar.health <= 0) {
			cout << charName[oppCharPU] << " wins" << endl;
			cin.get();
			winner = true;
			oppWins = true;
		}
	} while (winner == false);
	cout << "great match" << endl;
	cin.get();

	currChar.health = { 10 };
	oppCurrChar.health = { 10 };

}
void winLose();
int main() {

	for (;;) {
		Player you;
		you.lifePoints;// = 1000
		you.winner;//this is a bool

		Oponenet opp;
		opp.lifePoints;// = 1000
		opp.winner;//this is a bool
		
		bool finalWin;
		do {
			finalWin = false;
			for (int i = 250; i < 1000; --i) {
				winLose();
				if (youWin == true) {
					cout << "your opponents life points is now at: " << (opp.lifePoints -= i) << endl;
					cout << "your life points " << you.lifePoints << endl;
					if (opp.lifePoints <= 0) {
						return finalWin = true;
					}
				}
				else if (oppWins == true) {
					cout << "your life points are now at " << (you.lifePoints -= i) << endl;
					cout << "opponents life points " << opp.lifePoints << endl;
					if (you.lifePoints <= 0) {
						return finalWin = true;
					}
				}
			}
		} while (finalWin == false);
		cin.get();
		cout << "end" << endl;
		return 0;
	}
}
