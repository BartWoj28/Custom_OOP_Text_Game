/*
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Enemy {
private:
    string name;
    int health;
    int attack;

public:
    Enemy(string n, int h, int a) : name(n), health(h), attack(a) {}

    bool isAlive() const {
        return health > 0;
    }

    int getAttack() const {
        return attack;
    }

    void takeDamage(int damage) {
        health -= damage;
    }

    string getName() const {
        return name;
    }
};

class Hero {
private:
    string name;
    int level;
    int experience;
    int health;
    int attack;

public:
    Hero(string n) : name(n), level(1), experience(0), health(100), attack(10) {}

    bool isAlive() const {
        return health > 0;
    }

    void levelUp() {
        level++;
        experience = 0;
        health += 20;
        attack += 5;

        cout << "Gratulacje! Awansowales na poziom " << level << "." << endl;
        cout << "Zdrowie zwiekszone o 20, atak zwiekszony o 5." << endl;
    }

    void gainExperience(int exp) {
        experience += exp;
        cout << "Zdobyto " << exp << " doswiadczenia." << endl;

        if (experience >= 50) {
            levelUp();
        }
    }

    int getAttack() const {
        return attack;
    }

    void takeDamage(int damage) {
        health -= damage;
    }

    string getName() const {
        return name;
    }

    int getLevel() const {
        return level;
    }
};

class Game {
private:
    Hero hero;
    Enemy currentEnemy;

public:
    Game(string heroName) : hero(heroName), currentEnemy("Zombie", 30, 8) {}

    void start() {
        cout << "Witaj w grze przygodowej, " << hero.getName() << "!" << endl;

        while (hero.isAlive()) {
            displayStatus();
            int choice = getMenuChoice();

            switch (choice) {
            case 1:
                encounterEnemy();
                break;
            case 2:
                rest();
                break;
            case 3:
                exitGame();
                break;
            default:
                cout << "Niepoprawny wybor. Sprobuj ponownie." << endl;
            }

            if (!hero.isAlive()) {
                gameOver();
                break;
            }
        }
    }

private:
    void displayStatus() {
        cout << "----------------------" << endl;
        cout << "Poziom: " << hero.getLevel() << " | Doswiadczenie: " << hero.getLevel() << "/" << "50 | Zdrowie: "
            << hero.isAlive() << "/" << "100 | Atak: " << hero.getAttack() << endl;
        cout << "----------------------" << endl;
        cout << "Co chcesz zrobic?" << endl;
        cout << "1. Spotkaj przeciwnika" << endl;
        cout << "2. Odpocznij" << endl;
        cout << "3. Wyjdz z gry" << endl;
    }

    int getMenuChoice() {
        int choice;
        cout << "Wybierz opcje: ";
        cin >> choice;
        return choice;
    }

    void encounterEnemy() {
        cout << "Spotkales przeciwnika: " << currentEnemy.getName() << " (Zdrowie: " << currentEnemy.isAlive() << ")" << endl;

        while (currentEnemy.isAlive() && hero.isAlive()) {
            int enemyAttack = currentEnemy.getAttack();
            int heroAttack = hero.getAttack();

            cout << "Twoje zdrowie: " << hero.isAlive() << " | Zdrowie przeciwnika: " << currentEnemy.isAlive() << endl;
            cout << "1. Atakuj" << endl;
            cout << "2. Uciekaj" << endl;

            int choice;
            cin >> choice;

            switch (choice) {
            case 1:
                currentEnemy.takeDamage(heroAttack);
                hero.takeDamage(enemyAttack);

                cout << "Zadano " << heroAttack << " obrazen przeciwnikowi." << endl;
                cout << "Przeciwnik zadal " << enemyAttack << " obrazen." << endl;

                if (!currentEnemy.isAlive()) {
                    cout << "Pokonano przeciwnika!" << endl;
                    hero.gainExperience(20);
                    currentEnemy = Enemy("Zombie", 30, 8); // Przygotuj nowego przeciwnika
                }

                break;
            case 2:
                cout << "Uciekles z walki." << endl;
                return;
            default:
                cout << "Niepoprawny wybor. Sprobuj ponownie." << endl;
            }
        }
    }

    void rest() {
        hero.takeDamage(-20); // Odpoczynek, przywróæ czêœæ zdrowia
        cout << "Odpoczywasz. Przywracasz 20 punktow zdrowia." << endl;
    }

    void exitGame() {
        cout << "Dziekujemy za gre. Do zobaczenia!" << endl;
        exit(0);
    }

    void gameOver() {
        cout << "Game Over! Niestety, umarles. Koniec gry." << endl;
    }
};

int main() {
    srand(static_cast<unsigned>(time(0))); // Inicjalizacja generatora liczb losowych

    string playerName;
    cout << "Podaj imie bohatera: ";
    cin >> playerName;

    Game game(playerName);
    game.start();

    return 0;
}
*/