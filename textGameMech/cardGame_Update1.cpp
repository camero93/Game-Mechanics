#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Player {
public:
	int lifePoints;
};

class Oponenet {
public:
	int lifePoints;
};

class Character {
public:
	string name;
	int strength, health;
};

class Weapon {
public:
	string name;
	int uses, attack, defense;//minStrength
};

class Upgrade {
public:
	string name;
	int uses;
	//minwield
};

enum charCard { ARMOUREDKNIGHT, RONIN, SPARTAN, JEDI };
enum wepCard { ZWEIHANDER, KATANA, GLADIUS, LIGHTSABER };
enum upgCard { plusH, plusA, plusHA, Hx2A_2 };

bool winner;
bool youWin;
bool oppWins;
int upgPU;
int oppUpgPU;
int wepPU;
int oppWepPU;
int charPU;
int oppCharPU;

string charName[4]{ "ARMOURED KNIGHT","RONIN","SPARTAN","JEDI" }, wepName[4]{ "ZWIEHANDER","KATANA","GLADIUS","LIGHT SABER" }, upgName[4]{ "+H","+A","+H+A","H*2, A/2" };

int upgSel() {
	//USE THIS SWITCH STATEMENT TO RETURN VALUE INTO THE WINLOSE FUNCTION THE CREATE ANOTHER SWITCH STATEMENT TO ADD UNIQUE FUNCTIONS FOR THE UPGRADE CARDS.
	enum upgCard upgrade;
	cout << "pick up an upgrade card" << endl;
	cin.get();
	srand(time(0));
	upgPU = (rand() % 4);
	switch (upgPU) {
	case plusH:
		cout << "you picked up a " << upgName[upgPU] << endl;
		//function
		break;
	case plusA:
		cout << "you picked up a " << upgName[upgPU] << endl;
		//function
		break;
	case plusHA:
		cout << "you picked up a " << upgName[upgPU] << endl;
		//function
		break;
	case Hx2A_2:
		cout << "you picked up a " << upgName[upgPU] << endl;
		//function
		break;
	}
	return upgPU;
}

int oppUpgSel() {
	//USE THIS SWITCH STATEMENT TO RETURN VALUE INTO THE WINLOSE FUNCTION THE CREATE ANOTHER SWITCH STATEMENT TO ADD UNIQUE FUNCTIONS FOR THE UPGRADE CARDS.
	enum upgCard upgrade;
	cout << "your OPPONENT picked up an upgrade card" << endl;
	cin.get();
	srand(time(0));
	upgPU = (rand() % 4);
	switch (upgPU) {
	case plusH:
		cout << "you picked up a " << upgName[upgPU] << endl;
		break;
	case plusA:
		cout << "you picked up a " << upgName[upgPU] << endl;
		break;
	case plusHA:
		cout << "you picked up a " << upgName[upgPU] << endl;
		break;
	case Hx2A_2:
		cout << "you picked up a " << upgName[upgPU] << endl;
		break;
	}
	return upgPU;
}

int wepSel() {
	cout << "pick up a weapon card" << endl;
	cin.get();
	srand(time(0));
	wepPU = (rand() % 4);
	cout << "you picked up a " << wepName[wepPU] << endl;
	return wepPU;
}

int oppWepSel() {
	cout << "your OPPONENT has picked up a weapon card" << endl;
	cin.get();
	srand(time(0));
	oppWepPU = (rand() % 4);
	cout << " your OPPONENT picked up a " << wepName[oppWepPU] << endl;
	return oppWepPU;
}

int charSel() {
	cout << "pick up a character card" << endl;
	cin.get();
	srand(time(0));
	charPU = (rand() % 4);
	cout << "you picked up " << charName[charPU] << endl;
	return charPU;
}

int oppCharSel() {
	cout << "your OPPONENT has picked up a character card" << endl;
	cin.get();
	srand(time(0));
	oppCharPU = (rand() % 4);
	cout << " your OPPONENT picked up " << charName[oppCharPU] << endl;
	return oppCharPU;
}

bool winLose() {
	srand(time(0));
	Upgrade currUpg, oppCurrUpg;
	currUpg.name = upgName[upgPU];
	oppCurrUpg.name = upgName[oppUpgPU];
	currUpg.uses = 1;
	oppCurrUpg.uses = 1;

	Weapon currWep, oppCurrWep;
	currWep.name = wepName[wepPU];
	oppCurrWep.name = wepName[oppWepPU];
	currWep.attack = 20;
	oppCurrWep.attack = 10;
	currWep.uses = 5;
	oppCurrWep.uses = 5;

	Character currChar, oppCurrChar;
	currChar.name = charName[charPU];
	oppCurrChar.name = charName[oppCharPU];
	currChar.health = { 100 };
	oppCurrChar.health = { 100 };
	currChar.strength = 3;
	oppCurrChar.strength = 2;

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
		int oppMove = (rand() % 1);// RANDOM WHEN UPGRADES ARE DONE.
		cout << "do you want to deploy an attack card or chance an upgrade card from the deck? type 'a' or 'u': \n";
		cin >> move;

		if (move == 'u') {
			cout << "you have chosen to pick up an upgrade" << endl;
			upgSel();
		}
		else if (move == 'a') {
			cout << "you attack " << charName[oppCharPU] << " with a " << wepName[wepPU] << endl;
			cin.get();
			cout << charName[oppCharPU] << "'s health is now at: " << (oppCurrChar.health -= (currWep.attack * currChar.strength)) << endl;
			cin.get();
			cout << "your " << wepName[wepPU] << " currently has " << (currWep.uses -= 1) << " uses remaining." << endl;
			if (currWep.uses == 0) {
				wepSel();
			}
		}
		if (oppMove == 0) {
			cout << "your opponent attacks " << charName[charPU] << endl;
			cin.get();
			cout << charName[charPU] << "'s health is now at: " << (currChar.health -= (oppCurrWep.attack * oppCurrChar.strength)) << endl;
			cin.get();
			cout << "your opponents " << wepName[oppWepPU] << " currently has " << (oppCurrWep.uses -= 1) << endl;
			if (oppCurrWep.uses == 0) {
				oppWepSel();
			}
		}
		else if (oppMove == 1) {
			cout << "your OPPONENT chose to draw for an upgrade card" << endl;
			oppUpgSel();
			cin.get();
		}
		if (oppCurrChar.health <= 0) {
			cin.get();
			cout << charName[charPU] << " match winner" << endl;
			winner = true;
			youWin = true;
			return youWin;
		}
		else if (currChar.health <= 0) {
			cout << charName[oppCharPU] << " match winner" << endl;
			cin.get();
			winner = true;
			oppWins = true;
			return oppWins;
		}
	} while (winner == false);
	cout << "great match" << endl;
	cin.get();
	cout << "get ready got the next round" << endl;
	cin.get();

	currChar.health = { 10 };
	oppCurrChar.health = { 10 };
}

bool winLose();

int main() {
	char playAgain;
	do {
		Player you;
		you.lifePoints = 1000;// = 1000

		Oponenet opp;
		opp.lifePoints = 1000;// = 1000

		bool finalWin;
		do {
			finalWin = false;
			for (int i = 250; i > 1000; i--) { //or (int i = 250; i>250; i--(or --i))
				winLose();
				if (youWin == true) {
					cout << "your opponents life points is now at: " << (opp.lifePoints -= i) << endl;
					cin.get();
					cout << "your life points " << you.lifePoints << endl;
					cin.get();
					if (opp.lifePoints <= 0) {
						finalWin = true;
						return youWin;
					}
				}
				else if (oppWins == true) {
					cout << "your life points are now at " << (you.lifePoints -= i) << endl;
					cin.get();
					cout << "opponents life points " << opp.lifePoints << endl;
					cin.get();
					if (you.lifePoints <= 0) {
						finalWin = true;
						return oppWins;
					}
				}
			}
		} while (finalWin == false);
		cin.get();
		if (oppWins == true) {
			cout << "YOU WERE DEFEATED" << endl;
			cin.get();
			cout << "wanna play again? type 'y' OR 'n'" << endl;
			cin >> playAgain;
			if (playAgain == 'n') {
				return 'n';
			}
			else {
				return 'y';
			}
		}
		else if (youWin == true) {
			cout << "VICTORY!! YOU DEFEATED YOUR OPPONENT!!" << endl;
			cin.get();
			cout << "wanna play again? type 'y' OR 'n'" << endl;
			cin >> playAgain;
			if (playAgain == 'n') {
				return 0;
			}
			else {
				playAgain = 'y';
				return playAgain = 'y';
			}
		}
	} while (playAgain == 'y');
	return 0;
}
