#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;


struct Player {

	string name;
	int health;
	int attack;
	int defence;
	int speed;
	unsigned int luck;
	unsigned int level;
	unsigned int experience;
	unsigned int nextlevel;
	string Classtype;
};


struct Enemy {

	string name;
	int health;
	int attack;
	int defence;
	int speed;
	int luck;
	string difficulty;

};

Player CharacterCreator(Player character) {
	string name;
	cout << "What is your name my dear Hero?"<<endl;
	getline(cin, name);
	character.name = name;
	int choice;
	bool mistake;
	cout << "Tell me something about yourself:" << endl;
	do {
        mistake=false;
		cout<< "1.I just love slicing enemies with my axe.(Barbarian)" << endl
		<< "2.I am a wizard. My mastery is casting powerfull seplls.(Mage)" << endl 
		<< "3. Let's just say my job is full of risks.(Thief)" << endl << "4.I am a loyal servant of our Majesty.(Knight)" << endl;
		cin >> choice;
		if (choice > 4 || choice < 1) {mistake = true; cout << "No such option on the list, choose again" << endl; }
	} while (mistake);

	switch (choice) {

	case 1:
		character = { name,100,70,50,35,3,1,0,50,"Barbarian"};
		break;
     
	case 2:
		character = { name,100,85,35,50,4,1,0,50,"Mage"};
		break;

	case 3:
		character = { name,100,60,30,70,6,1,0,50,"Thief"};
		break;

	case 4:
		character = { name,100,50,50,50,3,1,0,50,"Knight"};
		break;
	};
	return character;
};

Enemy Encounter(int act)
{
	srand(time(NULL));

	Enemy MetEnemy;
	int random;

	switch (act) {

	case 1:

		random = rand() % 2;
		if (random == 0) {

			MetEnemy = { "Fox",60,50,15,55,2,"easy"};

		}
		else MetEnemy = { "Wolf",100,60,35,60,3,"medium"};
		break;

	case 2:


		random = rand() % 3;
		if (random == 0) {

			MetEnemy = { "Thief Goblin",65,33,22,55,3,"easy"};

		}
		else if (random == 1) { MetEnemy = { "Bandit",120,66,44,60,4,"medium"}; }
		else MetEnemy = { "Renegate Knight",165,77,60,60,4,"hard"};
		break;

	case 3:

		random = rand() % 2;
		if (random == 0) {

			MetEnemy = { "Fire Elemental",110,80,50,66,4,"medium"};

		}
		else { MetEnemy = { "Magma Golem",190,90,75,60,5,"hard"}; }
		break;

	}

	return MetEnemy;
};

int DamageDelt(Enemy enemy, Player player) {

	srand(time(NULL));
	int luckystrike = rand() % 10 + 1;
	int damage = (player.attack - enemy.defence);
	if (enemy.defence > player.attack)damage = 7;
	if (player.luck >= luckystrike)damage = damage * 2;
	return damage;
}

int DamageTaken(Enemy enemy, Player player) {

	srand(time(NULL));
	int luckystrike = rand() % 10 + 1;
	int damage = (enemy.attack - player.defence);
	if (player.defence > enemy.attack)damage = 7;
	if (enemy.luck >= luckystrike)damage = damage * 2;
	return damage;
}

Player BossBattle(Player player, Enemy enemy){

	cout << "You meet The great enemy: " << enemy.name << endl;
	cout << "Enemy Difficulty: " << enemy.difficulty << endl;

	int faster;
	if (player.speed > enemy.speed) { faster = 1; }
	else if (player.speed < enemy.speed) { faster = 2; }
	else faster = 0;
	int damage;
	switch (faster) {

	case 1:

		do
		{
			damage = DamageDelt(enemy, player);
			enemy.health -= damage;
			cout << "--------------------------" << endl;
			cout << "Dealt " << damage << " damage" << endl;
			if (enemy.health < 0) { cout << "Enemy Fainted" << endl; break; }
			damage = DamageTaken(enemy, player);
			player.health -= damage;
			cout << "Taken " << damage << " damage" << endl;
			cout << "------------------------------" << endl;
			if (player.health < 0) { cout << "You Fainted" << endl; break; }
		} while (player.health > 0 && enemy.health > 0);
		break;

	case 2:
		do
		{
			damage = DamageTaken(enemy, player);
			player.health -= damage;
			cout << "--------------------------" << endl;
			cout << "taken " << damage << " damage" << endl;
			if (player.health < 0) { cout << "You Fainted" << endl; break; }
			damage = DamageDelt(enemy, player);
			enemy.health -= damage;
			cout << "delt " << damage << " damage" << endl;
			cout << "------------------------------" << endl;
			if (enemy.health < 0) { cout << "Enemy Fainted" << endl; break; }
		} while (player.health > 0 && enemy.health > 0);
		break;

	case 0:
		do
		{
			damage = DamageDelt(enemy, player);
			enemy.health -= damage;
			cout << "--------------------------" << endl;
			cout << "Dealt " << damage << " damage" << endl;
			if (enemy.health < 0) { cout << "Enemy Fainted" << endl; break; }
			damage = DamageTaken(enemy, player);
			player.health -= damage;
			cout << "Taken " << damage << " damage" << endl;
			cout << "------------------------------" << endl;
			if (player.health < 0) { cout << "You Fainted" << endl; break; }
		} while (player.health > 0 && enemy.health > 0);
		break;

	}

	return player;

}

Player Battle(Player player, Enemy enemy, int act) {

    int choice;
	int runcounter=0;
	do
	{
    cout << "You meet: " << enemy.name << endl;
	cout << "Enemy Difficulty: " << enemy.difficulty << endl;
	cout << "Do you want to fight or runaway?" << endl;
	cout << "----------------------------------" << endl;
	cout << "1.Fight" << endl << "2. Run away" << endl;
	
	runcounter = 0;
	do
	{
		cin >> choice;
		if (choice < 1 || choice>2)cout<<"No such answer";
	} while (choice<1 || choice>2);
	if (choice == 2) { enemy = Encounter(act); runcounter++; }
	} while (choice == 2 && runcounter <3);

	int faster;
	if (player.speed > enemy.speed) { faster = 1; }
	else if (player.speed < enemy.speed) { faster = 2; }
	else faster = 0;
	int damage;
	switch (faster) {

	case 1:

		do
		{
			damage = DamageDelt(enemy, player);
			enemy.health -= damage;
			cout << "--------------------------" << endl;
			cout << "Dealt " << damage << " damage" << endl;
			if (enemy.health <= 0) { cout << "Enemy Fainted" << endl; break;}
			damage = DamageTaken(enemy, player);
			player.health -= damage;
			cout << "Taken " << damage << " damage" << endl;
			cout << "------------------------------" << endl;
			if (player.health <= 0) { cout << "You Fainted" << endl; break;}
		} while (player.health>0 && enemy.health>0);
			break;

	case 2:
		do
		{
			damage = DamageTaken(enemy, player);
			player.health -= damage;
			cout << "--------------------------" << endl;
			cout << "taken " << damage << " damage" << endl;
			if (player.health <= 0) { cout << "You Fainted" << endl; break; }
			damage = DamageDelt(enemy, player);
			enemy.health -= damage;
			cout << "delt " << damage << " damage" << endl;
			cout << "------------------------------" << endl;
			if (enemy.health <= 0) { cout << "Enemy Fainted" << endl; break; }
		} while (player.health > 0 && enemy.health > 0);
			break;

	case 0:
		do
		{
			damage = DamageDelt(enemy, player);
			enemy.health -= damage;
			cout << "--------------------------" << endl;
			cout << "Dealt " << damage << " damage" << endl;
			if (enemy.health <= 0) { cout << "Enemy Fainted" << endl; break; }
			damage = DamageTaken(enemy, player);
			player.health -= damage;
			cout << "Taken " << damage << " damage" << endl;
			cout << "------------------------------" << endl;
			if (player.health <= 0) { cout << "You Fainted" << endl; break; }
		} while (player.health > 0 && enemy.health > 0);
			break;

	}

	
	if (enemy.health <= 0) {

	    if(enemy.difficulty=="easy"){
		
			player.experience += 25;
			cout << "Gained 25 experience" << endl;;
			cout << "---------------------------" << endl;
		}
		else if (enemy.difficulty == "medium") {

			player.experience += 50;
			cout << "Gained 50 experience"<<endl;
			cout << "---------------------------" << endl;
		}
		else {
			player.experience += 75;
			cout << "Gained 75 experience"<<endl;
			cout << "---------------------------" << endl;
		}

	}

	if (player.experience >= player.nextlevel) { 
		player.nextlevel += 50 * player.level; 
		player.level++;
		cout << "-------------------------------------------------" << endl;
		cout << "You Reached a new level! Choose stat to upgrade(+10 to chosen statistic):" << endl;
		cout << "1.Attack 2.Defene 3.Speed" << endl;
		int upgrade = 0;
		do
		{
            cin >> upgrade;
		} while (upgrade!=1 && upgrade != 2 && upgrade != 3);
		cout << "-------------------------------------------------" << endl;
		
		switch (upgrade) {

            case 1:
				player.attack += 10;
				break;

			case 2:
				player.defence += 10;
				break;


			case 3:
				player.speed += 10;
				break;



		}

		player.health = 100;

	}
	return player;
}

void Game() {

	Player maincharachter;
	int act = 1;
	maincharachter = CharacterCreator(maincharachter);
	cout << "Village next to our castle was obliterated by some powerfull monster. Our scouts saw this thing flying away to the top of the inactive volcano, probably it has it's lair there. Reach that place and slay the monster" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "ACT I - The Forest" << endl;
	cout << "On your way to the monster's lair you pass through the big forest. You can encounter some wild animals there." << endl;
	cout << "------------------------------------------------" << endl;

	Enemy metenemy;
	

	for (int i = 0; i < 4; i++) {
        metenemy = Encounter(act);
		maincharachter = Battle(maincharachter, metenemy, act);
		if (maincharachter.health <= 0) return;

	}
	int artifacts;
	cout << "------------------------------------------------------------------------------------------------" << endl;
	cout << "Near the Forest Exit you find mystery chest full of artiacts. These might be blessed or cursed. Would you take them?" << endl;
	cout << "1.take 2.leave" << endl;
	do
	{
		cin >> artifacts;
		if (artifacts != 1 && artifacts != 2) cout << "no such option" << endl;
	} while (artifacts!=1 && artifacts!=2);

	cout << "-------------------------------------------" << endl;
	if (artifacts == 1) {

		srand(time(NULL));
		int luckartf = rand() % 2;
		if (luckartf > 0) {
			cout << "Your luck increased" << endl;
			maincharachter.luck += 2;
			if (maincharachter.luck > 10)maincharachter.luck = 10;
		}

		else {
			cout << "Your lost come of your luck" << endl;
			maincharachter.luck -= 2;
			if (maincharachter.luck < 1)maincharachter.luck = 1;
		}

	}

	act++;

    cout << "------------------------------------------------" << endl;
	cout << "ACT II - Destroyed Village" << endl;
	cout << "You reach the Village that was attacked by the monster. Only rubble remained of the buildings. Place is full of bandits robbing of the ramainings" << endl;
	

	for (int i = 0; i < 4; i++) {
		metenemy = Encounter(act);
		maincharachter = Battle(maincharachter, metenemy, act);
		if (maincharachter.health <= 0) { cout << "You lost. Game over"; return; }

	}

	artifacts = 0;
	cout << "------------------------------------------------------------------------------------------------" << endl;
	cout << "On some dead warriors neck you cans see a glowing medalion, very similar to the artifacts found in chest in the forest? take it?" << endl;
	cout << "1.take 2.leave" << endl;
	do
	{
		cin >> artifacts;
		if (artifacts != 1 && artifacts != 2) cout << "no such option" << endl;
	} while (artifacts != 1 && artifacts != 2);

	cout << "-------------------------------------------" << endl;
	if (artifacts == 1) {

		srand(time(NULL));
		int luckartf = rand() % 2;
		if (luckartf > 0) {
			cout << "Your luck increased" << endl;
			maincharachter.luck += 2;
			if (maincharachter.luck > 10)maincharachter.luck = 10;
		}

		else {
			cout << "Your lost come of your luck" << endl;
			maincharachter.luck -= 2;
			if (maincharachter.luck < 1)maincharachter.luck = 1;
		}

	}
	act++;

	cout << "------------------------------------------------" << endl;
	cout << "ACT III - The Volcanic Mountain" << endl;
	cout << "You are geting closer, and closer to the volcano. It started getting hotter and hotter. This awfull monster's presence must have activated the volcano" << endl;
	cout << "After a while you reached the volcano. You can smell sulfur and smoke in the air";
	for (int i = 0; i < 4; i++) {
		metenemy = Encounter(act);
		maincharachter = Battle(maincharachter, metenemy, act);

		if (maincharachter.health <= 0) { cout << "You lost. Game over"; return; }
	}


	cout << "------------------------------------------------------------------------------------------------" << endl;
	cout << "You have reached huge cave on top of the volcano. It must be the monster's lair" << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << "------------------------------------------------------------------------------------------------" << endl;
	cout << "FINAL ACT - The Final Battle" << endl;
	cout << "Yes the monster is here. It seems to be some kind of Fire Demon. /n The demon uses telepathy to comunicate with you, and says that, it  awaited you, because the blood of a great warrior is the last thing it needed to reach he's full power."<<endl;
	cout << "Without more talking, you reached for your weapon and the fight begun"<<endl;
	cout << "------------------------------------------------------------------------------------------------" << endl;

	Enemy TheDemon = {"The Fire Demon", 250, 100, 100, 100, 5, "Demonic"};

	maincharachter = BossBattle(maincharachter, TheDemon);


	if (maincharachter.health <= 0) { cout<<"You lost. Game over"; return; }

	cout << "------------------------------------------------" << endl;
	cout << "Congratulations "<<maincharachter.name<<" you beat The Fire Demon now you can go back to the castle for your great prize" << endl;
	


};

int main() {

	//Player player;
   // CharacterCreator(player);
	//int act = 2;
	//Encounter(act);
	bool end =false;
	char choice;
	do
	{
		Game();
		cout << "Play Again?(y/n)" << endl;
		do
		{
           cin >> choice;
		   if (choice != 'y' && choice != 'n')cout << "Adnswer only y or n" << endl;
		} while (choice!='y'&& choice!='n');
		
		if (choice == 'n')end = true;
	} while (!end);

}









