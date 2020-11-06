#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

enum charCard { ARMOUREDKNIGHT, RONIN, SPARTAN, JEDI };
enum wepCard { ZWEIHANDER, KATANA, GLADIUS, LIGHTSABER };


string charName[4]{ "ARMOURED KNIGHT","RONIN","SPARTAN","JEDI" }, wepName[4]{ "a ZWIEHANDER","a KATANA","a GLADIUS","a LIGHT SABER" }, upgName[4]{"a +H","a +A","a +H+A","a H*2, A/2"};

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
	int uses, attack;//minStrength
};

class Upgrade {
public:
	string name;
	int uses, effect;//minwield
};

int upgPU;
int upgSel() {
	cout << "pick up an upgrade card" << endl;
	cin.get();
	srand(time(0));
	upgPU = (rand() % 4);
	cout << "you picked up " << upgName[upgPU] << endl;
	return upgPU;
}

int oppUpgPU;
int oppUpgSel() {
	cout << "your OPPONENT has picked up an upgrade card" << endl;
	cin.get();
	srand(time(0));
	oppUpgPU = (rand() % 4);
	cout << " your OPPONENT picked up " << upgName[oppUpgPU] << endl;
	return oppUpgPU;
}

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
	currWep.uses = 2;

	Character currChar, oppCurrChar;
	currChar.name = charName[charPU];
	oppCurrChar.name = charName[oppCharPU];
	currChar.health = { 10 };
	oppCurrChar.health = { 10 };



	charSel();
	oppCharSel();
	wepSel();
	oppWepSel();




	cout << "its " << charName[charPU] << " holding a " << wepName[wepPU] << " vs " << charName[oppCharPU] << " holding a " << wepName[oppWepPU] << endl;

	cin.get();
	do {
		srand(time(0));
		winner = false;
		char move;
		int oppMove = (rand()%1);// RANDOM WHEN UPGRADES ARE DONE.
		cout << "do you want to deploy an attack card or chance an upgrade card from the deck? type 'a' or 'u': \n";
		cin >> move;

		if (move == 'u') {
			cout << "upgrade function" << endl;
		}else if (move == 'a') {
			cout << "you attack " << charName[oppCharPU] << " with a " << wepName[wepPU] << endl;
			cout << charName[oppCharPU] << "'s health is now at: " << (oppCurrChar.health -= currWep.attack) << endl;
			cin.get();
			cout << "your " << wepName[wepPU] << " currently has " << (currWep.uses -= 1) << " uses remaining." << endl;
			if (currWep.uses == 0) {
				wepSel();
			}
		}


		if (oppMove == 0) {
			cout << "your opponent attacks " << charName[charPU] << endl;
			cout << charName[charPU] << "'s health is now at: " << (currChar.health -= oppCurrWep.attack) << endl;
			cin.get();
			cout<<"your opponents "<<wepName[oppWepPU]<< " currently has " <<(oppCurrWep.uses -= 1)<<endl;
			if (oppCurrWep.uses == 0) {
				oppWepSel();
			}
			
		}
		else if (oppMove == 1) {
			cout << "upgrade function" << endl;
			cin.get();

		}
		if (oppCurrChar.health <= 0) {
			cin.get();
			cout << charName[charPU] << "match winner" << endl;
			winner = true;
			youWin = true;
		}
		else if (currChar.health <= 0) {
			cout << charName[oppCharPU] << "match winner" << endl;
			cin.get();
			winner = true;
			oppWins = true;
		}
	} while (winner == false);
	cout << "great match" << endl;
	cin.get();
	cout << "get ready got the next round" << endl;
	cin.get();

	currChar.health = { 10 };
	oppCurrChar.health = { 10 };

}

void winLose();

int main() {
	char playAgain;

	for (;;) {
		Player you;
		you.lifePoints;// = 1000

		Oponenet opp;
		opp.lifePoints;// = 1000

		bool finalWin;
		do {
			finalWin = false;
			for (int i = 250; i < 1000; --i) {
				winLose();
				if (youWin == true) {
					cout << "your opponents life points is now at: " << (opp.lifePoints -= i) << endl;
					cout << "your life points " << you.lifePoints << endl;
					cin.get();
					if (opp.lifePoints <= 0) {
						return finalWin = true;
						cin.get();
					}
				}
				else if (oppWins == true) {
					cout << "your life points are now at " << (you.lifePoints -= i) << endl;
					cout << "opponents life points " << opp.lifePoints << endl;
					cin.get();
					if (you.lifePoints <= 0) {
						return finalWin = true;
						cin.get();
					}
				}
			}
		} while (finalWin == false);
		if (you.lifePoints <=0) {
			cout << "you were defeated" << endl;
			cout << "" << endl;
			cout << "wanna play again? type 'y' OR 'n'" << endl;
			cin >> playAgain;
			if (playAgain == 'n') {
				return 0;
			}
			else {
				return 'y';
			}
		}
		else if (opp.lifePoints <= 0) {
			cout << "VICTORY!! YOU DEFEATED YOUR OPPONENT!!" << endl;
			cout << "" << endl;
			cout << "wanna play again? type 'y' OR 'n'" << endl;
			cin >> playAgain;
			if (playAgain == 'n') {
				return 0;
			}
			else {
				return 'y';
			}
		}
	}
}
