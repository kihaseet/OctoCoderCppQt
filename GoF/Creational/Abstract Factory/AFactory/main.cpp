#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Heal
{
  public:
    virtual void info() = 0;
    virtual ~Heal() {}
};

class Mana
{
  public:
    virtual void info() = 0;
    virtual ~Mana() {}
};

class HealPotion: public Heal
{
  public:
    void info() {
      cout << "Potion of Healing +5" << endl;
    }
};

class ManaPotion: public Mana
{
  public:
    void info() {
      cout << "Potion of Mana+20" << endl;
    }
};


class HealIngect: public Heal
{
  public:
    void info() {
      cout << "Ingect of Novocaine +20" << endl;
    }
};

class ManaIngect: public Mana
{
  public:
    void info() {
      cout << "Ingect of Mescaline +5" << endl;
    }
};

class Factory
{
  public:
    virtual Heal* addHeal() = 0;
    virtual Mana* addMana() = 0;
};


class PastFactory: public Factory
{
  public:
    Heal* addHeal()
    {
      return new HealPotion;
    }

    Mana* addMana()
    {
      return new ManaPotion;
    }
};


class FutureFactory: public Factory
{
  public:
    Heal* addHeal()
    {
      return new HealIngect;
    }

    Mana* addMana()
    {
      return new ManaIngect;
    }
};


class Inventory
{
  public:
    vector<Heal*> H;
    vector<Mana*> M;

   ~Inventory() {
    }
    void info() {
    }
};


class ActionInventory
{
    Inventory* p;

  public:
      ActionInventory()
      {
          p = new Inventory();
      }

    void  addHealItem(Factory &f){
        p->H.push_back(f.addHeal());}

    void  addManaItem(Factory &f){
        p->M.push_back(f.addMana());}

    void  deleteHealItem(){
        p->H.pop_back();}

    void  deleteManaItem(){
        p->M.pop_back();}



};

int main()
{
    PastFactory pf;

    ActionInventory *player1 = new ActionInventory;
    player1->addHealItem(pf);
    player1->addManaItem(pf)


}
