#include <iostream>
#include<windows.h>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <cstdio>
#include <conio.h>


std::string comands = "";
std::string pokemon = "";
std::string enemyPokemon = "";

int selectorPosition = 0;

int playerDefense = 0;
int enemyDefense = 0;

int playerDamage = 0;
int enemyDamage = 0;

int playerHealth = 0, playerMaxHealth = 0;
int enemyHealth = 0, enemyMaxHealth = 0;

int potions = 3;

char playerSelection = 'a';

bool selected = false;
bool anyoneDead = false;

void PokemonSelection();
void PokemonStatsAndEnemy();
void Fight();
void CaseSelection(int max);
void EnemyAttack();
void PlayerDesicion(int desicionValue);

int main() {

    PokemonSelection();
    Fight();

    if (playerHealth > enemyHealth) {
        std::cout << "YOU WON!!!" << std::endl;

    }
    if (playerHealth < enemyHealth) {
        std::cout << "YOU LOSE" << std::endl;
    }
    if (playerHealth == enemyHealth) {
        std::cout << "TIE" << std::endl;
    }
    std::getchar();
}


/// <summary>
/// This Event manipulates everything about the pokemon selection
/// </summary>
void PokemonSelection() {
    while (!selected)
    {
        switch (selectorPosition)
        {
        case 0:
            //pregunto que escoja su pokemon de forma cute y kawaii
            std::cout << "Choose your pokemon: " << std::endl;
            std::cout <<
                "_________________\n" <<
                "| >Charmander    |\n" <<
                "| Squirtle       |\n" <<
                "| Bulbasaur      |\n" <<
                "_________________\n";

            CaseSelection(2);
            if (selected == true)
                pokemon = "Charmander";

            break;

        case 1:
            std::cout << "Choose your pokemon: " << std::endl;
            std::cout <<
                "_________________\n" <<
                "| Charmander     |\n" <<
                "| >Squirtle      |\n" <<
                "| Bulbasaur      |\n" <<
                "_________________\n";

            CaseSelection(2);
            if (selected == true)
                pokemon = "Squirtle";

            break;

        case 2:
            std::cout << "Choose your pokemon: " << std::endl;
            std::cout <<
                "_________________\n" <<
                "| Charmander     |\n" <<
                "| Squirtle       |\n" <<
                "| >Bulbasaur     |\n" <<
                "_________________\n";

            CaseSelection(2);
            if (selected == true)
                pokemon = "Bulbasaur";

            break;

        default:
            std::cout << "Bug" << std::endl;
            break;

        }

    }
    std::cout << "Your Pokemon is: " << pokemon << std::endl;
    std::cin.ignore();

    PokemonStatsAndEnemy();
}

/// <summary>
/// Se encarga de establecer los stats tanto del jugador como del enemigo
/// </summary>
void PokemonStatsAndEnemy() {

    //establesco las stats del jugador y enemigas
    if (pokemon == "Charmander") {

        enemyPokemon = "Squirtle";
        enemyDamage = 32;
        enemyDefense = 16;
        enemyHealth = 54;
        enemyMaxHealth = 54;

        playerDamage = 23;
        playerDefense = 25;
        playerHealth = 57;
        playerMaxHealth = 57;
    }
    if (pokemon == "Squirtle")
    {
        enemyPokemon = "Bulbasaur";
        enemyDamage = 31;
        enemyDefense = 19;
        enemyHealth = 50;
        enemyMaxHealth = 50;

        playerDamage = 27;
        playerDefense = 23;
        playerHealth = 54;
        playerMaxHealth = 54;
    }
    else if (pokemon == "Bulbasaur")
    {
        enemyPokemon = "Charmander";
        enemyDamage = 36;
        enemyDefense = 15;
        enemyHealth = 50;
        enemyMaxHealth = 50;

        playerDamage = 21;
        playerDefense = 22;
        playerHealth = 58;
        playerMaxHealth = 58;
    }

    //limpio la consola y muestro las stats del jugador
    system("CLS");

    std::cout <<
        "     STATS\n" <<
        "_____________\n" <<
        "Health:  " << playerHealth << std::endl <<
        "Defense: " << playerDefense << std::endl <<
        "Damage:  " << playerDamage << std::endl <<
        "_____________\n";

    std::getchar();
    system("CLS");
}

/// <summary>
/// Todo el nucleo y funcionalidad de la pelea pokemon
/// </summary>
void Fight() {
    selectorPosition = 0;

    while (!anyoneDead)
    {
        switch (selectorPosition)
        {
        case 0:
            std::cout <<
                "____________________" << std::endl <<
                "Rival: " << enemyPokemon << std::endl <<
                "HP: " << enemyHealth << std::endl <<
                "____________________" << std::endl <<
                "____________________" << std::endl <<
                pokemon << std::endl <<
                "HP: " << playerHealth << std::endl <<
                "____________________" << std::endl <<
                "____________________" << std::endl <<
                "| >Atack     Cure   |" << std::endl <<
                "| Growl      Run    |" << std::endl <<
                "____________________" << std::endl;

            CaseSelection(3);
            system("CLS");
            if (selected) {

                PlayerDesicion(0);
                EnemyAttack();
            }

            break;

        case 1:
            std::cout <<
                "____________________" << std::endl <<
                "Rival: " << enemyPokemon << std::endl <<
                "HP: " << enemyHealth << std::endl <<
                "____________________" << std::endl <<
                "____________________" << std::endl <<
                pokemon << std::endl <<
                "HP: " << playerHealth << std::endl <<
                "____________________" << std::endl <<
                "____________________" << std::endl <<
                "| Atack      >Cure  |" << std::endl <<
                "| Growl      Run    |" << std::endl <<
                "____________________" << std::endl;

            CaseSelection(2);
            system("CLS");
            if (selected) {

                PlayerDesicion(2);
                EnemyAttack();
            }

            break;

        case 2:
            std::cout <<
                "____________________" << std::endl <<
                "Rival: " << enemyPokemon << std::endl <<
                "HP: " << enemyHealth << std::endl <<
                "____________________" << std::endl <<
                "____________________" << std::endl <<
                pokemon << std::endl <<
                "HP: " << playerHealth << std::endl <<
                "____________________" << std::endl <<
                "____________________" << std::endl <<
                "| Atack      Cure   |" << std::endl <<
                "| >Growl      Run   |" << std::endl <<
                "____________________" << std::endl;

            CaseSelection(3);

            system("CLS");
            if (selected) {

                PlayerDesicion(1);
                EnemyAttack();
            }


            break;

        case 3:
            std::cout <<
                "____________________" << std::endl <<
                enemyPokemon << std::endl <<
                "HP: " << enemyHealth << std::endl <<
                "____________________" << std::endl <<
                "____________________" << std::endl <<
                pokemon << std::endl <<
                "HP: " << playerHealth << std::endl <<
                "____________________" << std::endl <<
                "____________________" << std::endl <<
                "| Atack      Cure   |" << std::endl <<
                "| Growl      >Run   |" << std::endl <<
                "____________________" << std::endl;

            CaseSelection(3);
            system("CLS");
            if (selected) {

                PlayerDesicion(3);
                EnemyAttack();
            }

            break;

        default:
            std::cout << "Bug" << std::endl;
            break;
        }
    }
}


/// <summary>
/// Controls the sections to 
/// </summary>
/// <param name="max"></param>
void CaseSelection(int max)
{
    selected = false;

    //Tomo toda la linea de texto y agarro solo el primer caracter 

    std::getline(std::cin, comands);
    playerSelection = comands[0];

    switch (playerSelection)
    {
    default:
        selected = true;
        break;
    case 's':
        if (selectorPosition < max)
        {
            selectorPosition++; system("CLS");
        }
        else
        {
            selectorPosition = 0; system("CLS");
        }

        break;
    case 'w':
        if (selectorPosition > 0)
        {
            selectorPosition--; system("CLS");
        }
        else
        {
            selectorPosition = max; system("CLS");
        }

        break;
    }

}

void EnemyAttack() {

    int enemyDecision = 0;
    int enemyRatio = std::rand() % 100;
    int hitDamage = enemyDamage - playerDefense + std::rand() % 6;
    int enemyPotions = 3;
    int healPoints = 25;

    if (enemyRatio < 50)
        enemyDecision = 0;
    if (enemyRatio >= 50 && enemyRatio < 75)
        enemyDecision = 1;
    if (enemyRatio >= 75)
        enemyDecision = 2;


    switch (enemyDecision)
    {
    case 0:

        if (hitDamage < playerHealth)
            playerHealth -= hitDamage;
        else if (hitDamage >= playerHealth) {
            hitDamage = playerHealth;
            playerHealth = 0;
            anyoneDead = true;
        }

        std::cout <<
            "________________________________" << std::endl <<
            "The enemy attacks" << std::endl <<
            "Damage deal: " << hitDamage << std::endl <<
            "Health: " << playerHealth << std::endl <<
            "________________________________" << std::endl;
        break;
    case 1:
        playerDefense -= 4;

        std::cout <<
            "________________________________" << std::endl <<
            "The enemy grwols" << std::endl <<
            "Your defense decrease" << std::endl <<
            "Defense: " << playerDefense << std::endl <<
            "________________________________" << std::endl;
        break;
    case 2:

        if (enemyPotions > 0) {
            if (enemyMaxHealth - enemyHealth > healPoints) {

                enemyHealth += healPoints;

                std::cout <<
                    "________________________________" << std::endl <<
                    "The enemy used a potion " << std::endl <<
                    "Enemy life increased by " << healPoints << std::endl <<
                    "Enemy health: " << enemyHealth << std::endl <<
                    "________________________________" << std::endl;
            }
            else if (enemyMaxHealth - enemyHealth < healPoints) {

                enemyHealth = enemyMaxHealth;

                std::cout <<
                    "________________________________" << std::endl <<
                    "The enemy used a potion " << std::endl <<
                    "Enemy life maxed out" << std::endl <<
                    "Enemy health: " << enemyHealth << std::endl <<
                    "________________________________" << std::endl;
            }

            enemyPotions--;
        }
        else if (enemyPotions == 0)
        {
            std::cout <<
                "________________________________" << std::endl <<
                "The enemy used a potion " << std::endl <<
                "Enemy dont have enough potions" << std::endl <<
                "Enemy health: " << enemyHealth << std::endl <<
                "________________________________" << std::endl;
        }

        break;
    default:
        std::cout <<
            "________________________________" << std::endl <<
            "The enemy tried to scape " << std::endl <<
            "Enemy failed" << std::endl <<
            "Enemies health: " << enemyHealth << std::endl <<
            "________________________________" << std::endl;
        break;
    }

    std::getchar();

    system("CLS");
}

void PlayerDesicion(int desicionValue) {
    int hitDamage = playerDamage - enemyDefense + std::rand() % 6;
    int healPoints = 25;

    switch (desicionValue)
    {
    case 0:

        if (hitDamage < enemyHealth)
            enemyHealth -= hitDamage;
        else if (hitDamage >= enemyHealth) {
            hitDamage = enemyHealth;
            enemyHealth = 0;
            anyoneDead = true;
        }

        std::cout <<
            "________________________________" << std::endl <<
            pokemon << " attacks" << std::endl <<
            "Damage deal: " << hitDamage << std::endl <<
            "Enemy health: " << enemyHealth << std::endl <<
            "________________________________" << std::endl;
        break;
    case 1:
        enemyDefense -= 4;

        std::cout <<
            "________________________________" << std::endl <<
            pokemon << " grwols" << std::endl <<
            "Enemy defense decrease" << std::endl <<
            "Enemy defense: " << enemyDefense << std::endl <<
            "________________________________" << std::endl;
        break;
    case 2:

        if (potions > 0) {
            if (playerMaxHealth - playerHealth > healPoints) {

                playerHealth += healPoints;

                std::cout <<
                    "________________________________" << std::endl <<
                    "You used a potion " << std::endl <<
                    pokemon << " life increased by " << healPoints << std::endl <<
                    pokemon << " health: " << playerHealth << std::endl <<
                    "________________________________" << std::endl;
            }
            else if (playerMaxHealth - playerHealth < healPoints) {

                playerHealth = playerMaxHealth;

                std::cout <<
                    "________________________________" << std::endl <<
                    "You used a potion " << std::endl <<
                    pokemon << " life maxed out" << std::endl <<
                    pokemon << " health: " << playerHealth << std::endl <<
                    "________________________________" << std::endl;
            }

            potions--;
        }
        else if (potions == 0)
        {
            std::cout <<
                "________________________________" << std::endl <<
                "You used a potion " << std::endl <<
                "You dont have enough potions" << std::endl <<
                pokemon << " health: " << playerHealth << std::endl <<
                "________________________________" << std::endl;
        }

        break;
    case 3:
        std::cout <<
            "________________________________" << std::endl <<
            pokemon << " tried to scape " << std::endl <<
            pokemon << " failed" << std::endl <<
            "Player health: " << playerHealth << std::endl <<
            "________________________________" << std::endl;
        break;
    default:
        std::cout << "bug" << std::endl;
    }

    std::getchar();

    system("CLS");
}