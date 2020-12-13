#include "Header.h"
#include <string>
#include <vector>
#include <iostream>
#define years_difference 2
using namespace std;

Pet::Pet(string name, string breed, int age, string greeting, int mass, Kind kind)
{
    this->name = name;
    this->breed = breed;
    this->age = age;
    this->greeting = greeting;
    this->mass = mass;
    this->kind = kind;
}

Pet::~Pet(){};
Home::Home(){};
Home::~Home(){};


void Home::addAnimal(Pet newAnimal)
{
    pets.push_back(newAnimal);
    this->count++;
}

vector<Pet> Home::getAnimal()
{
    return pets;
}

string Pet::getName()
{
    return name;
}

string Pet::getGreeting()
{
    return greeting;
}

int Pet::getAge()
{
    return age;
}

int Pet::getMass()
{
    return mass;
}

string Pet::getBreed()
{
    return breed;
}

bool isPolite(Pet* pet)
{
    if(pet -> getGreeting() == "Hello")
        return 1;
    return 0;
}

void areFriends(vector <Pet> &animal, int animal_count)
{
    for(int i=0; i<(animal_count-1); i++)
    {
        if( abs( animal[i+1].getAge()-animal[i].getAge() ) < years_difference )
        {
            cout << endl;
            cout << animal[i+1].getName() << " and " << animal[i].getName() << " are friends";
            cout << endl;
        }
    }
}

void swapPets(Pet &first, Pet &second)
{
    Pet temp = first;
    first = second;
    second = temp;
}

int partition(vector<Pet> &pet,int first_position,int second_position)
{
    int pivot = pet[second_position].getAge();
    int i = first_position-1;
    
    for(int j=first_position; j<second_position; j++)
    {
        if(pet[j].getAge() < pivot)
        {
            i++;
            swapPets(pet[i], pet[j]);
        }
    }
    swapPets(pet[++i], pet[second_position]);
    return i;
}

void sortByAge(vector<Pet> &pet, int first_position, int second_position)
{
    if(first_position < second_position)
    {
        int pi = partition(pet, first_position, second_position);
        sortByAge(pet, first_position, pi-1);
        sortByAge(pet, pi+1, second_position);
        
    }
}

