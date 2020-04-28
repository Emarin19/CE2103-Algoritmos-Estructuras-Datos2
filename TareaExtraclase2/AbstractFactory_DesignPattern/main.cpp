#include <iostream>
#define DIFFICULT

class Cake{
public:
    Cake(){
        number = total++;
    }
    virtual void bake() = 0;

protected:
    int number;
    static int total;
};

int Cake::total = 0;

class ApplePie : public Cake {
    void bake(){
        std::cout << "Bake apple pie " << number << std::endl;
    }
};

class CarrotCake : public Cake {
    void bake(){
        std::cout << "Bake carrot cake " << number << std::endl;
    }
};

class ChocolateCake : public Cake {
    void bake(){
        std::cout << "Bake chocolate cake " << number <<std::endl;
    }
};

class ThreeMilkCake : public Cake {
    void bake() {
        std::cout << "Bake three milk cake " << number << std::endl;
    }
};

class AbstractFactory{
public:
    virtual Cake *createBigCake() = 0;
    virtual Cake *createSmallCake() = 0;
};

class SimpleCakeFactory : public AbstractFactory {
    Cake *createBigCake(){
        return new ApplePie;
    }
    Cake *createSmallCake(){
        return new CarrotCake;
    }
};

class DifficultCakeFactory : public AbstractFactory {
    Cake *createBigCake(){
        return new ChocolateCake;
    }
    Cake *createSmallCake(){
        return new ThreeMilkCake;
    }
};

int main() {
#ifdef DIFFICULT
    AbstractFactory *factory = new DifficultCakeFactory;
#elif SIMPLE
    AbstractFactory *factory = new SimpleCakeFactory;

#endif
    Cake *cakes[3];
    cakes[0] = factory->createBigCake();
    cakes[1] = factory->createSmallCake();
    cakes[2] = factory->createBigCake();

    for(int i=0; i<3; i++){
        cakes[i]->bake();
    }
    return 0;
}