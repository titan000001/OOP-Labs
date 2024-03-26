#include<bits/stdc++.h>
using namespace std;

class Animal{
protected: 
    string name;
    string sound;
    int age;
    int hunger;
    int happiness;
public:
    Animal(const string& n,const string& s, int a, int h, int hp) : 
    name(n), sound(s), age(a), hunger(h), happiness(hp){}

    virtual ~Animal(){}

    virtual void makeSound() const{
        cout << name << " makes a sound " << sound << endl;
    }

    string getName(){
        return name;
    }

    void eat(){
        hunger-- ;
        happiness++ ;
        cout << name << " is eating and getting happier." << endl;
    }

    void play(){
        happiness += 2;
        hunger++;
        cout << name << " is playing and getting happier." << endl;
    }

    void sleep(){
        hunger++;
        happiness--;
        cout << name << " is sleeping." << endl;
    }
};

class Dog : public Animal{
public: 
    Dog(const string& n, int a, int h, int hp)
        : Animal(n, "Woof", a, h , hp){}

    void makeSound() const override{
        cout << name << "barks: " << sound << endl;
    }

    void fetch(){
        hunger++;
        happiness += 2;
        cout << name << " is fetching and getting happier" << endl;
    }
};

class Cat : public Animal{
public:
    Cat(const string& n, int a, int h, int hp)
        : Animal(n, "Meow!" , a, h, hp){}
    
    void makeSound() const override{
        cout << name << " meows: " << sound << endl;
    }

    void catchMouse(){
        hunger--;
        happiness += 3;
        cout << name << " caught a mouse and is getting happier." << endl;
    }
};

class Cow : public Animal{
public:
    Cow(const string& n, int a, int h, int hp)
        : Animal (n, "Moo", a, h, hp){}

    void makeSound() const override{
        cout << name << " moos: " << sound << sound << endl;
    }

    void produceMilk(){
        hunger++;
        happiness++;
        cout << name << " produced some milk " << endl;
    }
};

class Game{
private:
    vector<Animal*> petlist;
public:
    ~Game(){
        for(Animal* pet : petlist)
            delete pet;
    }

    void addPet(Animal* pet){
        petlist.push_back(pet);
        cout << "Added " << pet->getName() << " to the pet list." << endl;
    }

    void removePet(int index){
        if(index >= 0 && index < petlist.size()){
            Animal* pet = petlist[index];
            petlist.erase(petlist.begin() + index);
            cout << "Removed " << pet->getName() << " from the pet list." << endl;
            delete pet;
        }else{
            cout << "Invalid pet index." << endl;
        }
    }

    void interactWithPet(int index){
        if(index >= 0 && index < petlist.size()){
            Animal* pet = petlist[index];
            int choice;
            cout << "What would you like to do with " << pet->getName() << "?" << endl;
            cout << "1.Make sound\n2.Eat\n3.Play\n4.Sleep\n5.Peform special action" << endl;
            cin >> choice;

            switch(choice){
                case 1:
                    pet->makeSound();
                    break;
                case 2:
                    pet->eat();
                    break;
                case 3:
                    pet->play();
                    break;
                case 4:
                    pet->sleep();
                    break;
                case 5:
                    performSpecialAction(pet);
                    break;
                default:
                    cout << "Invalid choice." << endl;
            }
        }else{
            cout << "Invalid pet index." << endl;
        }
    }

    void performSpecialAction(Animal* pet){
        Dog* dog = dynamic_cast<Dog*>(pet);
        if(dog){
            dog->fetch();
        }else{
            Cat* cat = dynamic_cast<Cat*>(pet);
            if(cat){
                cat->catchMouse();
            }else{
                Cow* cow = dynamic_cast<Cow*> (pet);
                if(cow){
                    cow->produceMilk();
                }else{
                    cout << "Special action not available for this pet." << endl;
                }
            }
        }
    }
};

int main(){
    Game game;
    Dog* dog = new Dog ("Buddy",2,5,8);
    Cat* cat = new Cat ("Whiskers",3,4,7);
    Cow* cow = new Cow ("Daisy", 4,6,9);

    game.addPet(dog);
    game.addPet(cat);
    game.addPet(cow);

    int choice;
    int petIndex;

    do{
        cout << "\nVirtual Pet simulator" << endl;
        cout<< "1. Interact with a pet" << endl;
        cout << "2. Add new pet" << endl;
        cout << "3. Remove a pet " << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: " ;
        cin >> choice;

        switch (choice){
            case 1:
                cout << "Enter the index of the pet to interact with: ";
                cin >> petIndex;
                game.interactWithPet(petIndex);
                break;
            case 2:
                int petType;
                cout << "Choose the type of the pet to add: " << endl;
                cout << "\n1. Dog\n2. Cat\n3. Cow\n";
                cin >> petType;
                switch(petType){
                    case 1:
                        game.addPet(new Dog("New Dog", 1,5,8));
                        break;
                    case 2:
                        game.addPet(new Cat("New Cat",1,4,7));
                        break;
                    case 3:
                        game.addPet(new Cow("New Cow", 1,6,9));
                        break;
                    default:
                        cout << "Invalid pet type" << endl;
                }
                break;
            case 3:
                cout << "Enter the index of the pet to remove: ";
                cin >> petIndex;
                game.removePet(petIndex);
                break;
            case 4:
                cout << "Exiting game..." << endl;
                break;
            default: 
                cout << "Invalid Choide" << endl;
        }
    }while (choice != 4);
}
