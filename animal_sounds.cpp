#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void makeSound()
    {
        cout << "ANIMAL SOUNDS" << endl;
    }
};

class Dog : public Animal
{
public:
    void makeSound() override
    {
        cout << "Dog: BARKS - BOWW, BOWW !" << endl;
    }
};

class Cat : public Animal
{
public:
    void makeSound() override
    {
        cout << "Cat: MEOWS - MEEOOWW, MEEOOWW !" << endl;
    }
};

int main()
{
    Dog myDog;
    Cat myCat;

    cout<<"***********ANIMAL SOUNDS***********"<<endl;
    myDog.makeSound();
    myCat.makeSound();
    cout<<"***********************************";

    return 0;
}
