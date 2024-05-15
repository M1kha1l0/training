#include <iostream>
#include <vector>
#include <algorithm>

class Animal {
protected:
    std::string name;
    bool isflying;
    bool isunderwater;

public:
    static int cnt;

    bool get() { return isflying; }
    void set(bool p_isflying) { this->isflying = p_isflying; }

    Animal() { cnt++; }
    Animal(std::string p_name, bool p_isflying, bool p_underwater) {
        this->name = p_name;
        this->isflying = p_isflying;
        this->isunderwater = p_underwater;
        cnt++;
    }

    void voice() {}
};

class Bird: public Animal {
public:
    Bird() {}
    Bird(std::string p_name, bool p_isflying) : Animal(p_name, p_isflying, false) {}

    void fly() {
        if (isflying) { std::cout << "I'm flying!\n"; }
        else { std::cout << "I can't fly!\n"; }
    }

    void voice() { std::cout << "phu phu phu!\n"; }
};

class Mammal : public Animal {
public:
    Mammal() {}
    Mammal(std::string p_name, bool p_isflying, bool p_underwater) : Animal(p_name, p_isflying, p_underwater) {}
    void swim() { std::cout << "I'm swimming!\n"; }
    void hunt() { std::cout << "I'm hunting!\n"; }
};

class Lion : public Mammal {
public:
    Lion() {}
    Lion(std::string name) : Mammal(name, false, false) {}

    void voice() { std::cout << "Arrrrr!\n"; }
};

class Dolphin : public Mammal {
public:
    Dolphin() {}
    Dolphin(std::string name) : Mammal(name, false, true) {}

    void voice() { std::cout << "pshhh!\n"; }
};

int Animal::cnt = 0;

int main() {
    Bird b("Titmouse", true);
    b.fly();
    b.voice();

    std::cout << "\n\n";

    Lion l("Lion");
    l.hunt();
    l.voice();

    Dolphin d("V");
    std::cout << Animal::cnt;
    return 0;
}