#include <iostream>
#include "Header.h"
#include <string>
#include <vector>
#define length 5
using namespace std;

int main(int argc, const char * argv[]) {
    Home Home;
    
    Pet stepan("Stepan", "Dog", 3, "Hello", 8, DOG);
    Home.addAnimal(stepan);
    Pet barbos("Barbos", "Dog", 4, "Hi", 4, DOG);
    Home.addAnimal(barbos);
    Pet garfild("Garfild", "Cat", 10, "Guten Tag", 6, CAT);
    Home.addAnimal(garfild);
    Pet jackson("Jackson", "Dragon", 1, "Hello", 78, DRAGON);
    Home.addAnimal(jackson);
    Pet ratatuj("Ratatuj", "Mouse", 2, "Hello", 2, MOUSE);
    Home.addAnimal(ratatuj);
    
    vector<Pet> animals = Home.getAnimal();
    sortByAge(animals, 0, length-1);
    for(int i=0; i<length; i++)
    {
        cout << animals[i].getName()<< " ";
        cout << animals[i].getGreeting()<< " ";
        cout << animals[i].getAge()<< " ";
        cout << animals[i].getBreed()<< " ";
        cout << animals[i].getMass()<< " " <<endl;
    }
    
    areFriends(animals, length);
    
    cout << endl;
    cout << "Check politeness of...";
    string name_polite;
    cin >> name_polite;
    for(int i = 0; i<length; i++)
        if(animals[i].getName() == name_polite)
        {
            if(isPolite(&animals[i])) cout << "Is polite";
                else cout << "Isn`t polite";
        }
    cout << endl;
    
    return 0;
}

