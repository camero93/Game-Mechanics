#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>



using namespace std;


//VARIABLES
enum charCard { ARMOUREDKNIGHT, RONIN, SPARTAN, JEDI, VIKING, RAIDEN, LINK, CLOUDSTRIFE, NOCTIS };
enum wepCard { ZWEIHANDER, KATANA, GLADIUS, LIGHTSABER, SIGURD, HFBLADE, BLADEOFEVILSBANE, BUSTERSWORD, ENGINEBLADE };
enum upgCard { plusH, plusA, Ax2H_2, Hx2A_2, Sx2, xtraUse };


















//FUNCTIONS

























//CLASSES
class Character {
public:
	string charName[9]{ "ARMOURED KNIGHT","RONIN","SPARTAN","JEDI","VIKING","RAIDEN","LINK","CLOUD STRIFE","NOCTIS" };
	int charPU = (rand() % 9), health{}, strength{};
	string name = charName[charPU];

	
		
};

class Weapon {
public:
	string wepName[9]{ "ZWIEHANDER","KATANA","GLADIUS","LIGHT SABER","SIGURD","HF BLADE","BLADE OF EVIL's BANE","BUSTER SWORD","ENGINE BLADE" };
	int attack{}, uses{}, wepPU = (rand() % 9);
	string name = wepName[wepPU];


};

class Upgrade {
public:
	string upgName[6]{ "+H","+A","A*2, H/2","H*2, A/2","S*2","+U" };

	int upgPU = (rand() % 6), uses{};

	string name = upgName[upgPU];
};

class Player {
public:
	int lifePoints{ 1000 };

};



























//MAIN
int main() {
	bool gameOver{false};
	srand(time(NULL));




	




	//PLAY-AGAIN LOOP
		char playAgain;
	do {
			bool youWin{}, oppWins{}, charChange{};
			Player p1, cpu;
			
			
			
			
			
		do{
			Character p1char, cpuchar;
				Weapon p1wep, cpuwep;
				Upgrade p1upg, cpuupg;
				
				cout << "DEALING CARDs OUT...." << endl;
				

				//                               player selection
				switch (p1char.charPU) {
				case ARMOUREDKNIGHT:
					p1char.health = 200;
					p1char.strength = 4;
					break;
				case RONIN:
					p1char.health = 200;
					p1char.strength = 2;
					break;
				case SPARTAN:
					p1char.health = 200;
					p1char.strength = 3;
					break;
				case JEDI:
					p1char.health = 200;
					p1char.strength = 2;
					break;
				case VIKING:
					p1char.health = 200;
					p1char.strength = 5;
					break;
				case RAIDEN:
					p1char.health = 200;
					p1char.strength = 6;
					break;
				case LINK:
					p1char.health = 200;
					p1char.strength = 4;
					break;
				case CLOUDSTRIFE:
					p1char.health = 200;
					p1char.strength = 7;
					break;
				case NOCTIS:
					p1char.health = 200;
					p1char.strength = 7;
					break;
				}

				switch (p1wep.wepPU) {

				case ZWEIHANDER:
					p1wep.attack = (rand() % 48 + 25);
					p1wep.uses = (rand() % 5 + 2);
					break;
				case KATANA:
					p1wep.attack = (rand() % 45 + 35);
					p1wep.uses = (rand() % 7 + 2);
					break;
				case GLADIUS:
					p1wep.attack = (rand() % 44 + 29);
					p1wep.uses = (rand() % 4 + 2);
					break;
				case LIGHTSABER:
					p1wep.attack = (rand() % 50 + 35);
					p1wep.uses = (rand() % 10 + 2);
					break;
				case SIGURD:
					p1wep.attack = (rand() % 40 + 25);
					p1wep.uses = (rand() % 5 + 2);
					break;
				case HFBLADE:
					p1wep.attack = 150;
					p1wep.uses = 1;
					break;
				case BLADEOFEVILSBANE:
					p1wep.attack = (rand() % 37 + 25);
					p1wep.uses = 4;
					break;
				case BUSTERSWORD:
					p1wep.attack = (rand() % 50 + 40);
					p1wep.uses = (rand() % 5 + 2);
					break;
				case ENGINEBLADE:
					p1wep.attack = (rand() % 45 + 40);
					p1wep.uses = (rand() % 5 + 2);
					break;
				}

				//                               computer selection
				switch (cpuchar.charPU) {
				case ARMOUREDKNIGHT:
					cpuchar.health = 200;
					cpuchar.strength = 4;
					break;
				case RONIN:
					cpuchar.health = 200;
					cpuchar.strength = 2;
					break;
				case SPARTAN:
					cpuchar.health = 200;
					cpuchar.strength = 3;
					break;
				case JEDI:
					cpuchar.health = 200;
					cpuchar.strength = 2;
					break;
				case VIKING:
					cpuchar.health = 200;
					cpuchar.strength = 5;
					break;
				case RAIDEN:
					cpuchar.health = 200;
					cpuchar.strength = 6;
					break;
				case LINK:
					cpuchar.health = 200;
					cpuchar.strength = 4;
					break;
				case CLOUDSTRIFE:
					cpuchar.health = 200;
					cpuchar.strength = 7;
					break;
				case NOCTIS:
					cpuchar.health = 200;
					cpuchar.strength = 7;
					break;
				}

				switch (cpuwep.wepPU) {

				case ZWEIHANDER:
					cpuwep.attack = (rand() % 48 + 25);
					cpuwep.uses = (rand() % 5 + 2);
					break;
				case KATANA:
					cpuwep.attack = (rand() % 45 + 35);
					cpuwep.uses = (rand() % 7 + 2);
					break;
				case GLADIUS:
					cpuwep.attack = (rand() % 44 + 29);
					cpuwep.uses = (rand() % 4 + 2);
					break;
				case LIGHTSABER:
					cpuwep.attack = (rand() % 50 + 35);
					cpuwep.uses = (rand() % 10 + 2);
					break;
				case SIGURD:
					cpuwep.attack = (rand() % 40 + 25);
					cpuwep.uses = (rand() % 5 + 2);
					break;
				case HFBLADE:
					cpuwep.attack = 150;
					cpuwep.uses = 1;
					break;
				case BLADEOFEVILSBANE:
					cpuwep.attack = (rand() % 37 + 25);
					cpuwep.uses = 4;
					break;
				case BUSTERSWORD:
					cpuwep.attack = (rand() % 50 + 40);
					cpuwep.uses = (rand() % 5 + 2);
					break;
				case ENGINEBLADE:
					cpuwep.attack = (rand() % 45 + 40);
					cpuwep.uses = (rand() % 5 + 2);
					break;
				}

				
				
				cin.get();

				
				cout << "its " << p1char.name << " holding a " << p1wep.name << " vs " << cpuchar.name << " holding a " << cpuwep.name << endl;
				cout << "YOUR HEALTH: " << p1char.health << "                         " << "OPPONENT HEALTH: " << cpuchar.health << endl;
				cout << "YOUR STRENGTH: " << p1char.strength << "                         " << "OPPONENT STRENGTH: ?" << endl;
				cout << "YOUR WEAPON ATTACK: " << p1wep.attack << "                         " << "OPPONENT WEAPON ATTACK: ?" << endl;
				cin.get();
			//BATTLE LOOP
			charChange = false;
			do {
				
				//               YOUR TURN
				cout << "its your turn" << endl;
				cout << "attack or upgrade? a/u" << endl;
				char aORu;
				cin >> aORu;
				switch (aORu) {
				case 'a':
					cout << p1char.name << " uses " << p1wep.name << " to attack " << cpuchar.name << endl;

					cpuchar.health -= (p1wep.attack + p1char.strength);
					p1wep.uses -= 1;
				
					cout << cpuchar.name << "'s health: "<<cpuchar.health<<endl;
						
					cout << "your " << p1wep.name << " has " << p1wep.uses << " remaining." << endl;

					
					cin.get();



					break;
				case 'u':
					cout << p1char.name << " uses " << p1upg.name << endl;

					//         (UPGRADE FUNCTION HERE)
					switch (p1upg.upgPU) {

					case plusH:
						cout << "you picked up a " << p1upg.name << ". your character health will be increased by 10." << endl;
						p1char.health += 30;
						cout << "health: " << p1char.health << endl;
						cin.get();
						break;


					case plusA:
						cout << "you picked up a " << p1upg.name << ". your weapon attack will be increased by 10." << endl;
						p1wep.attack += 10;
						cout << "attack: " << p1wep.attack << endl;
						cin.get();
						break;


					case Ax2H_2:
						cout << "you picked up a " << p1upg.name << ". your attack will be doubled and health will be slashed in half." << endl;
						p1char.health -= (p1char.health/2);
						p1wep.attack += p1wep.attack;
						cout << "health: " << p1char.health << endl;
						cout << "attack: " << p1wep.attack << endl;
						cin.get();
						break;


					case Hx2A_2:
						cout << "you picked up a " << p1upg.name << ". your health will be doubled and attack will be slashed in half." << endl;
						p1wep.attack -= (p1wep.attack / 2);
						p1char.health += p1char.health;
						cout << "health: " << p1char.health << endl;
						cout << "attack: " << p1wep.attack << endl;
						cin.get();
						break;


					case Sx2:
						cout << "you picked up a " << p1upg.name << ". your strength will be doubled." << endl;
						p1char.strength += p1char.strength;
						cout << "strength: " << p1char.strength << endl;
						cin.get();
						break;


					case xtraUse:
						cout << "you picked up a " << p1upg.name << ". your weapon will be given 1 extra use." << endl;
						p1wep.uses += 1;
						cout << "weapon uses: " << p1wep.uses << endl;
						cin.get();
						break;
					}
					
	
					break;
					
				}

				//opponent health check
				if (cpuchar.health <= NULL) {
					cout << cpuchar.name << "'s health is 0" << endl;
					charChange = true;
					youWin = true;
					oppWins = false;
					cin.get();
					break;
				}/*else if (p1wep.uses == 0) {
					
					switch (p1wep.wepPU) {

					case ZWEIHANDER:
						p1wep.attack = (rand() % 48 + 25);
						p1wep.uses = (rand() % 5 + 2);
						break;
					case KATANA:
						p1wep.attack = (rand() % 45 + 35);
						p1wep.uses = (rand() % 7 + 2);
						break;
					case GLADIUS:
						p1wep.attack = (rand() % 44 + 29);
						p1wep.uses = (rand() % 4 + 2);
						break;
					case LIGHTSABER:
						p1wep.attack = (rand() % 50 + 35);
						p1wep.uses = (rand() % 10 + 2);
						break;
					case SIGURD:
						p1wep.attack = (rand() % 40 + 25);
						p1wep.uses = (rand() % 5 + 2);
						break;
					case HFBLADE:
						p1wep.attack = 150;
						p1wep.uses = 1;
						break;
					case BLADEOFEVILSBANE:
						p1wep.attack = (rand() % 37 + 25);
						p1wep.uses = 4;
						break;
					case BUSTERSWORD:
						p1wep.attack = (rand() % 50 + 40);
						p1wep.uses = (rand() % 5 + 2);
						break;
					case ENGINEBLADE:
						p1wep.attack = (rand() % 45 + 40);
						p1wep.uses = (rand() % 5 + 2);
						break;
					}
					cout << "your weapon uses have run out" << endl;
					cout << "you are now holding a " << p1wep.name << endl;
					cin.get();
					
				}*/


				cin.get();



				//                   OPPONENTS TURN
				cout << "its now your opponents turn" << endl;

				switch ((rand() % 2+1)) {
				case 1:
					cout << cpuchar.name << " uses " << cpuwep.name << " to attack " << p1char.name << endl;
					p1char.health -= (cpuwep.attack + cpuchar.strength);
					cpuwep.uses -= 1;

					cout << "opponents " << cpuwep.name << " has " << cpuwep.uses << " remaining." << endl;
					
					cin.get();
					break;
				case 2:
					cout << cpuchar.name << " uses " << cpuupg.name << endl;
					//         (UPGRADE FUNCTION HERE)

					switch (cpuupg.upgPU) {

					case plusH:
						cout << "opponent picked up a " << cpuupg.name << ". opponent character health will be increased by 10." << endl;
						cpuchar.health += 30;
						cout << "opponent health: " << cpuchar.health << endl;
						cin.get();
						break;


					case plusA:
						cout << "opponent picked up a " << cpuupg.name << ". opponent weapon attack will be increased by 10." << endl;
						cpuwep.attack += 10;
						cout << "opponent attack: " << cpuwep.attack << endl;
						cin.get();
						break;


					case Ax2H_2:
						cout << "opponent picked up a " << cpuupg.name << ". opponent attack will be doubled and health will be slashed in half." << endl;
						cpuchar.health -= ( cpuchar.health / 2);
						cpuwep.attack += cpuwep.attack;
						cout << "opponent health: " << cpuchar.health << endl;
						cout << "opponent attack: " << cpuwep.attack << endl;
						cin.get();
						break;


					case Hx2A_2:
						cout << "opponent picked up a " << cpuupg.name << ". opponent health will be doubled and attack will be slashed in half." << endl;
						cpuwep.attack -= (cpuwep.attack / 2);
						cpuchar.health += cpuchar.health;
						cout << "opponent health: " << cpuchar.health << endl;
						cout << "opponent attack: " << cpuwep.attack << endl;
						cin.get();
						break;


					case Sx2:
						cout << "opponent picked up a " << cpuupg.name << ". opponent strength will be doubled." << endl;
						cpuchar.strength += cpuchar.strength;
						cout << "opponent strength: " << cpuchar.strength << endl;
						cin.get();
						break;


					case xtraUse:
						cout << "opponent picked up a " << cpuupg.name << ". opponents weapon will be given 1 extra use." << endl;
						cpuwep.uses += 1;
						cout << "opponent weapon uses: " << cpuwep.uses << endl;
						cin.get();
						break;
					}

					
					break;
					
				}

				//player health check
				if (p1char.health <= NULL) {
					cout << p1char.health << "'s health is 0" << endl;
					charChange = true;
					youWin = false;
					oppWins = true;
					cin.get();
					break;
				}/*else if (cpuwep.uses == 0) {
					
					switch (cpuwep.wepPU) {

					case ZWEIHANDER:
						p1wep.attack = (rand() % 48 + 25);
						p1wep.uses = (rand() % 5 + 2);
						break;
					case KATANA:
						p1wep.attack = (rand() % 45 + 35);
						p1wep.uses = (rand() % 7 + 2);
						break;
					case GLADIUS:
						p1wep.attack = (rand() % 44 + 29);
						p1wep.uses = (rand() % 4 + 2);
						break;
					case LIGHTSABER:
						p1wep.attack = (rand() % 50 + 35);
						p1wep.uses = (rand() % 10 + 2);
						break;
					case SIGURD:
						p1wep.attack = (rand() % 40 + 25);
						p1wep.uses = (rand() % 5 + 2);
						break;
					case HFBLADE:
						p1wep.attack = 150;
						p1wep.uses = 1;
						break;
					case BLADEOFEVILSBANE:
						p1wep.attack = (rand() % 37 + 25);
						p1wep.uses = 4;
						break;
					case BUSTERSWORD:
						p1wep.attack = (rand() % 50 + 40);
						p1wep.uses = (rand() % 5 + 2);
						break;
					case ENGINEBLADE:
						p1wep.attack = (rand() % 45 + 40);
						p1wep.uses = (rand() % 5 + 2);
						break;
					}
					cout << "opponent weapon uses have run out" << endl;
					cout << "opponent is now holding a " << cpuwep.name << endl;
					cin.get();

				}*/




			} while (charChange == false);

			//  MATCH LOSE PENALTY
			if (youWin == true) {
				cpu.lifePoints -= 350;
				cout << "opponent -350 lifepoints" << endl;
				cout << " opponents lifePoints: " << cpu.lifePoints << endl;
				

				//  lifePoint check
				if (cpu.lifePoints <= 0) {
					cout << "game over" << endl;
					gameOver = true;
					cin.get();
				}

			
			}
			else if (oppWins == true) {
				p1.lifePoints -= 350;
				cout << "player -350 lifepoints" << endl;
				cout << "your lifePoints: " << p1.lifePoints << endl;
				cin.get();
				//  lifePoint check
				if (cpu.lifePoints <= 0) {
					cout << "game over" << endl;
					gameOver = true;
					cin.get();
				}

				
			}
			
			
		} while (gameOver == false);
			
			
			cout << "wanna play again?" << endl;
			cin >> playAgain;
	} while (playAgain == 'y');
	
	cout << "goodbye" << endl;
	cin.get();
	
}
