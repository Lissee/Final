#include <iostream>
#include "pets.h"

using namespace std;

int main() {
    srand(0);

    Zoo Z;
    for (int x = 0; x<10; x++) {
        Accessories A;
        Bird B;
        Fish G;
        Reptiles R;
        Fluffy F;
        Z.SetPets({G});
        Z.SetPets({B});
        Z.SetPets({R});
        Z.SetPets({F});
        Z.SetAccess({A});
    }
Day D_1, D_2;
    D_1.GetDays(Z);

    return 0;
}
//Магазин животных
//вид рыбы, птицы земноводные. пушистые///
//пол. возраст. цвет. характер. цена//
// товары для животных
/// аксессуары. еда//
// продавец подбирает животное для покупателя и продает//
// покупатель просит показать всех животных//
// просит показать конкретный вид животных//
// тоже самое но несколько//
// покупатель задает характеристики//
//