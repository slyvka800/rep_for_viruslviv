#pragma once
#include <string>
#include <vector>
using namespace std;
enum Kind{
    DOG,
    CAT,
    BIRD,
    ELEPHANT,
    SQUIRREL,
    DRAGON,
    MOUSE
};

class Pet
{
private:
    string name;
    string breed;
    int age;
    string greeting;
    int mass;
    Kind kind;
    
public:
    Pet();
    ~Pet();
    Pet(string, string, int, string, int, Kind);
    
    friend bool isPolite(Pet*);
    string getName();
    string getGreeting();
    int getAge();
    string getBreed();
    int getMass();
};

class Home
{
private:
    int count = 0;
    vector<Pet> pets;
public:
    Home();
    ~Home();
    void addAnimal(Pet);
    vector<Pet> getAnimal();
};

void sortByAge(vector <Pet> &, int, int);
void areFriends(vector <Pet>&, int);
