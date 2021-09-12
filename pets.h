#include <iostream>
#include <vector>

using namespace std;

enum CHARACTER{
    GOOD,
    FUN,
    CALM,
    BAD
};

enum COLOR {
    WHITE,
    GRAY,
    BLACK,
    ORANGE,
    BLOND,
    BRAWN,
    MULTICOLORED,
    BLUE,
    GREEN,
    YELLOW,
    RED,
    PINK,
    VIOLET,
};

enum TYPE {
    CAGE,
    COLLAR,
    TOY,
    CLOTHING
};

int Random () {
    return rand() % 10;
}

class Accessories{
protected:
    unsigned int price;
    TYPE type;

    string ToStringType() {
        switch (type) {
            case TYPE::CAGE:
                return "CAGE";
            case TYPE::COLLAR:
                return "COLLAR";
            case TYPE::TOY:
                return "TOY";
            case TYPE::CLOTHING:
                return "CLOTHING";
        };
    }
public:
    Accessories() {
        price = rand() % 500;
        type = (TYPE)(rand() % 3);
    }
    unsigned int GetPrice(){
        return price;
    }
    string GetType(){
        return ToStringType();
    }
};

class Pets {
protected:
   unsigned int age, price;
   bool gender;
   CHARACTER character;
   COLOR color;

    string ToStringColor() {
        switch (color) {
            case COLOR::WHITE: return "WHITE";
            case COLOR::GRAY: return "GRAY";
            case COLOR::BLACK: return "BLACK";
            case COLOR::ORANGE: return "ORANGE";
            case COLOR::BLOND: return "BLOND";
            case COLOR::BRAWN: return "BRAWN";
            case COLOR::MULTICOLORED: return "MULTICOLORED";
            case COLOR::BLUE: return "BLUE";
            case COLOR::RED: return "RED";
            case COLOR::PINK:return "PINK";
            case COLOR::GREEN:return "GREEN";
            case COLOR::VIOLET:return "VIOLET";
            case COLOR::YELLOW: return "YELLOW";
        }
    }
    string ToStringCharacter() {
        switch (character) {
            case CHARACTER::GOOD:
                return "good";
            case CHARACTER::FUN:
                return "fun";
            case CHARACTER::CALM:
                return "calm";
            case CHARACTER::BAD:
                return "bad";
        }
        throw std::logic_error("err");
    }
friend class Buyer;
public:
    Pets(){
        price = rand() %1000;
        if (Random() <=5) {
            gender = true;
        } else {
            gender = false;
        }
        character = (CHARACTER)( rand() % 3);
    }
    ~Pets() = default;


    unsigned  int GetAge() {
        return age ;
    };
    int GetPrice() {
        return price ;
    };
     string GetGender() {
        if (gender == true) {
            return "Boy";
        } else {
            return "Girl";
        }
    };
     string GetCharacter(){
        return  ToStringCharacter();
    };
     string GetColor(){
         return ToStringColor();
     }
};

class Fish : public Pets {
protected:
    bool sea_or_river;
public:
    Fish(){
        if (Random() <=5) {
            sea_or_river = true;
        } else {
            sea_or_river = false;
        }
        color = (COLOR)( rand() %12);
        age = rand() %5;
    }

    string GetWater() {
        if (sea_or_river == true) {
            return "Sea";
        } else {
            return "River";
        }
    }
};

class Bird : public Pets {
protected:
    bool talking;
public:
    Bird(){
        if(Random()<=5){
            talking = true;
        } else {
            talking = false;
        }
        color = (COLOR)( rand() %12);
        age = rand() %30;
    }

    string GetTalk() {
        if (talking == true) {
            return "Talking";
        } else {
            return "Not talking";
        }
    }

};

class Reptiles : public Pets {
protected:
public:
    Reptiles(){
        color = (COLOR)( rand() %9);
        age = rand() %36;
}
};

class Fluffy : public Pets {
protected:
public:
    Fluffy(){
        color = (COLOR)( rand() %6);
        age = rand() %25;
    }
};

class Zoo {
protected:
    vector<Fish> fish;
    vector<Bird> bird;
    vector<Reptiles> reptiles;
    vector<Fluffy> fluffy;
    vector<Accessories> access;
public:
    void  SetAccess(vector<Accessories> A){
        for (int x = 0; x < A.size(); x++) {
            access.push_back(A[x]);
        }
    }
    void SetPets(vector<Fish> pats) {
        for (int x = 0; x < pats.size(); x++) {
            fish.push_back(pats[x]);
        }
    }
    void SetPets(vector<Bird> pats) {
        for (int x = 0; x < pats.size(); x++) {
            bird.push_back(pats[x]);
        }
    }
    void SetPets(vector<Reptiles> pats) {
        for (int x = 0; x < pats.size(); x++) {
            reptiles.push_back(pats[x]);
        }
    }
    void SetPets(vector<Fluffy> pats) {
        for (int x = 0; x < pats.size(); x++) {
            fluffy.push_back(pats[x]);
        }
    }
    vector<Fish> GetFish (){
        return fish;
    }
    vector<Bird> GetBird (){
        return bird;
    }
    vector<Reptiles> GetReptiles (){
        return reptiles;
    }
    vector<Fluffy> GetFluffy (){
        return fluffy;
    }
    vector<Accessories> GetAccess(){
        return access;
    }
};

class Seller {
protected:
    friend class Day;
public:

    void GetFish(vector<Fish> fish) {
        for (int x = 0; x < fish.size(); x++) {
            cout << "Fish: " << fish[x].GetAge() << " yeas | " << fish[x].GetGender() << " | Color:  " << fish[x].GetColor() <<
                 " |Temper: " << fish[x].GetCharacter() << " | " << fish[x].GetWater() << " ||" << fish[x].GetPrice() << "$"<<endl;
            cout << "-----------------------------------------------------------" <<endl;
        }
    }
    void GetBird(vector<Bird> bird) {
        for (int x = 0; x < bird.size(); x++) {
            cout << "Bird: " << bird[x].GetAge() << " yeas | " << bird[x].GetGender() << " | Color:  " << bird[x].GetColor() <<
                 " |Temper: " << bird[x].GetCharacter() << " | " << bird[x].GetTalk() << " ||" << bird[x].GetPrice() << "$"<<endl;
            cout << "-----------------------------------------------------------" <<endl;
        }
    }
    void GetReptiles(vector<Reptiles> reptiles) {
        for (int x = 0; x < reptiles.size(); x++) {
            cout << "Reptiles: " << reptiles[x].GetAge() << " yeas | " << reptiles[x].GetGender() << " | Color:  " << reptiles[x].GetColor() <<
                 " |Temper: " << reptiles[x].GetCharacter() << " ||" << reptiles[x].GetPrice() << "$" <<endl;
            cout << "-----------------------------------------------------------" <<endl;
        }
    }
    void GetFluffy(vector<Fluffy> fluffy) {
        for (int x = 0; x < fluffy.size(); x++) {
            cout << "Fluffy: " << fluffy[x].GetAge() << " yeas | " << fluffy[x].GetGender() << " | Color:  " << fluffy[x].GetColor() <<
                 " |Temper: " << fluffy[x].GetCharacter() << " ||" << fluffy[x].GetPrice() << "$" <<endl;
            cout << "-----------------------------------------------------------" <<endl;
        }
    }
    void GetAll(vector<Fish> fish, vector<Bird> bird, vector<Reptiles> reptiles, vector<Fluffy> fluffy){
        cout <<"Zoo: "<<endl;
        GetFish(fish);
        GetBird(bird);
        GetReptiles(reptiles);
        GetFluffy(fluffy);
        cout << "-----------------------------------------------------------" <<endl;
    }
    //Продажа
    void Sell(vector<Fish> fish, int age, string character) {
    bool  check = true;
        for (int x = 0; x < fish.size(); x++) {
            if (fish[x].GetAge() <= age && fish[x].GetCharacter() == character) {
                cout << "Your pets is fish: " << fish[x].GetAge() << " yeas | " << fish[x].GetGender() << " | Color:  "
                     << fish[x].GetColor() <<
                     " |Temper: " << fish[x].GetCharacter() << " | " << fish[x].GetWater() << " ||"
                     << fish[x].GetPrice()
                     << "$" << endl;
                check = false;
                break;
            }
        }
        if (check == true) {
            if (Random() <= 5){
                cout << "Your pets is fish: " << fish[rand () % fish.size()].GetAge() << " yeas | " <<
                fish[rand () % fish.size()].GetGender() << " | Color:  "<< fish[rand () % fish.size()].GetColor() <<
                " |Temper: " << fish[rand () % fish.size()].GetCharacter() << " | " <<
                fish[rand () % fish.size()].GetWater() << " ||" << fish[rand () % fish.size()].GetPrice()<< "$" << endl;
            } else {
                cout << "Sorry! We couldn't find a pet for you, please come back later."<< endl;
            }
        }
    }

    void Sell(vector<Bird> bird, int age, string character) {
        bool  check = true;
        for (int x = 0; x < bird.size(); x++) {
            if (bird[x].GetAge() <= age && bird[x].GetCharacter() == character) {
                cout << "Your pets is bird: " << bird[x].GetAge() << " yeas | " << bird[x].GetGender() << " | Color:  "<<
                bird[x].GetColor() << " |Temper: " << bird[x].GetCharacter() << " | " << bird[x].GetTalk() <<
                " ||" << bird[x].GetPrice() << "$" << endl;
                check = false;
                break;
            }
        }
        if (check == true) {
            if (Random() <= 5){
                cout << "Your pets is bird: " << bird[rand () % bird.size()].GetAge() << " yeas | " <<
                bird[rand () % bird.size()].GetGender() << " | Color:  "<< bird[rand () % bird.size()].GetColor() <<
                " |Temper: " << bird[rand () % bird.size()].GetCharacter() << " | " <<
                bird[rand () % bird.size()].GetTalk() << " ||" << bird[rand () % bird.size()].GetPrice()<< "$" << endl;
            } else {
                cout << "Sorry! We couldn't find a pet for you, please come back later."<< endl;
            }
        }
    }

    void Sell(vector<Reptiles> reptiles, int age, string character) {
        bool  check = true;
        for (int x = 0; x < reptiles.size(); x++) {
            if (reptiles[x].GetAge() <= age && reptiles[x].GetCharacter() == character) {
                cout << "Your pets is reptiles: " << reptiles[x].GetAge() << " yeas | " << reptiles[x].GetGender() << " | Color:  "<<
                reptiles[x].GetColor() <<" |Temper: " << reptiles[x].GetCharacter() <<  " ||" <<
                reptiles[x].GetPrice() << "$" << endl;
                check = false;
                break;
            }
        }
        if (check == true) {
            if (Random() <= 5){
                cout << "Your pets is reptiles: " << reptiles[rand () % reptiles.size()].GetAge() << " yeas | " <<
                     reptiles[rand () % reptiles.size()].GetGender() << " | Color:  " << reptiles[rand () % reptiles.size()].GetColor() <<
                     " |Temper: " << reptiles[rand () % reptiles.size()].GetCharacter() << " ||" <<
                     reptiles[rand () % reptiles.size()].GetPrice() << "$" << endl;
            } else {
                cout << "Sorry! We couldn't find a pet for you, please come back later."<< endl;
            }
        }
    }

    void Sell(vector<Fluffy> fluffy, int age, string character) {
        bool  check = true;
        for (int x = 0; x < fluffy.size(); x++) {
            if (fluffy[x].GetAge() <= age && fluffy[x].GetCharacter() == character) {
                cout << "Your pets is fluffy: " << fluffy[x].GetAge() << " yeas | " << fluffy[x].GetGender() << " | Color: "<<
                fluffy[x].GetColor() << " |Temper: " << fluffy[x].GetCharacter() <<  " ||" << fluffy[x].GetPrice() << "$" << endl;
                check = false;
                break;
            }
        }
        if (check == true) {
            if (Random() <= 5){
                cout << "Your pets is fluffy: " << fluffy[rand () % fluffy.size()].GetAge() << " yeas | " <<
                     fluffy[rand () % fluffy.size()].GetGender() << " | Color:  " << fluffy[rand () % fluffy.size()].GetColor() <<
                     " |Temper: " << fluffy[rand () % fluffy.size()].GetCharacter() << " | " <<
                     " ||" << fluffy[rand () % fluffy.size()].GetPrice() << "$" << endl;
            } else {
                cout << "Sorry! We couldn't find a pet for you, please come back later."<< endl;
            }
        }
    }
    void SellAccess(vector<Accessories> A, string type) {
    for (int x = 0; x < A.size(); x++){
        if (A[x].GetType() == type){
            cout << A[x].GetType() << " | Price: " << A[x].GetPrice() << "$" <<endl;
            cout << "Thank you! Come back later!"<<endl;
            break;
        }
    }
}
};

class Buyer {
protected:
    string character_pets;
    string access;
    int age_pets;
    Seller S;
public:

    //просмотр
    //Просит показать всех
    void GetAllPats(Zoo Z){
    S.GetAll(Z.GetFish(), Z.GetBird(), Z.GetReptiles(), Z.GetFluffy());
        BuyOne(Z);
    if (Random() <= 5){
        BuyAccess(Z);
    }
}
//Просит показать некоторые виды
void GetSeveralPats(Zoo Z){
        vector<int> x;
        if (Random() <=5){
            S.GetFish(Z.GetFish());
            x.push_back(1);}
        if (Random()<= 5){
            S.GetBird(Z.GetBird());
            x.push_back(3);}
        if (Random() <=5){
            S.GetReptiles(Z.GetReptiles());
            x.push_back(5);}
        if (Random()<= 5){
            S.GetFluffy(Z.GetFluffy());
            x.push_back(7);}
        BuyOne(Z, x);
        if (Random() <= 5){
            BuyAccess(Z);
        }
    }
    //Просит показать конкретный вид
    void GetThisPats(Zoo Z, string name) {
        if (name == "Fish"){
            S.GetFish(Z.GetFish());
            BuyOne(Z, {1});}
        if (name == "Bird"){
            S.GetBird(Z.GetBird());
            BuyOne(Z, {3});}
        if (name == "Reptiles"){
            S.GetReptiles(Z.GetReptiles());
            BuyOne(Z, {5});}
        if (name == "Fluffy"){
            S.GetFluffy(Z.GetFluffy());
            BuyOne(Z, {7});}
        if (Random() <= 5){
            BuyAccess(Z);
        }
    }

//Покупка
//Покупает одного
void BuyOne(Zoo Z){
        int x;
        age_pets = rand() % 40;
        x = rand() % 7;
        if (x <= 1) {
            character_pets = "good";
        }else if (x == 2 || x == 3) {
            character_pets = "fun";
        } else if (x = 4 || x == 5) {
            character_pets = "calm";
        } else {character_pets = "bad";}

        x = rand() % 7;
        if (x <= 1) {
            cout << "------------------------------------------------"<<endl;
           S.Sell(Z.GetFish(), age_pets,  character_pets);
            cout << "------------------------------------------------"<<endl;
        } else if (x == 2 || x == 3) {
            cout << "------------------------------------------------"<<endl;
            S.Sell(Z.GetBird(), age_pets,  character_pets);
            cout << "------------------------------------------------"<<endl;
        } else if (x == 4 || x == 5) {
            cout << "------------------------------------------------"<<endl;
            S.Sell(Z.GetReptiles(), age_pets,  character_pets);
            cout << "------------------------------------------------"<<endl;
        } else {
            cout << "------------------------------------------------"<<endl;
            S.Sell(Z.GetFluffy(), age_pets,  character_pets);
            cout << "------------------------------------------------"<<endl;
        }
    }

    void BuyOne(Zoo Z, vector<int> y){
        int x;
        age_pets = rand() % 40;
        x = rand() % 3;
        if (x == 0) {
            character_pets = "good";
        }else if (x == 1) {
            character_pets = "fun";
        } else if (x == 2) {
            character_pets = "calm";
        } else {character_pets = "bad";}
        if (y.size() <= 1){
            x = 0;
        } else {x = rand () % y.size();}

        if ( y[x] <= 1) {
            cout << "------------------------------------------------"<<endl;
            S.Sell(Z.GetFish(), age_pets,  character_pets);
            cout << "------------------------------------------------"<<endl;
        } else if (y[x] == 2 || y[x] == 3) {
            cout << "------------------------------------------------"<<endl;
            S.Sell(Z.GetBird(), age_pets,  character_pets);
            cout << "------------------------------------------------"<<endl;
        } else if (y[x] == 4 || y[x] == 5) {
            cout << "------------------------------------------------"<<endl;
            S.Sell(Z.GetReptiles(), age_pets,  character_pets);
            cout << "------------------------------------------------"<<endl;
        } else {
            cout << "------------------------------------------------"<<endl;
            S.Sell(Z.GetFluffy(), age_pets,  character_pets);
            cout << "------------------------------------------------"<<endl;
        }
    }
    void BuyAccess(Zoo Z){
            int x = rand() % 3;
            if (x == 0){
                access = "CAGE";
            }else if (x == 1) {
                access = "COLLAR";
            }else if (x == 2) {
                access = "TOY";
            }else{access = "CLOTHING";}
            S.SellAccess(Z.GetAccess(),access);
        cout << "------------------------------------------------"<<endl;
        cout << "------------------------------------------------"<<endl;
    }
};

class Day {
protected:
public:

   void GetDays(Zoo Z) {
       int i;
       for (int x = 0; x < 4; x++) {
           Buyer B;
          i = rand() % 3;
           if (i == 0) {
               B.GetAllPats(Z);
           } else if (i == 1) {
               B.GetSeveralPats(Z);
           } else {
               i = rand() % 3;
               if (i == 0) {
                   B.GetThisPats(Z,"Fish");
               } else if (i == 1){
                   B.GetThisPats(Z,"Bird");
               } else if (i == 2) {
                   B.GetThisPats(Z, "Reptiles");
               }else {
                   B.GetThisPats(Z, "Fluffy");
               }
           }
       }
       cout << "Day off"<< endl;
   }
};

#ifndef UNTITLED20_PETS_H
#define UNTITLED20_PETS_H

#endif //UNTITLED20_PETS_H
