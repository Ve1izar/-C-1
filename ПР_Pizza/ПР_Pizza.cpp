#include <iostream>
#include <string>
using namespace std;

class Pizza {
protected:
    string ingredients[10];
    int count = 0;

public:
    virtual void CookPizza() const {
        cout << "Pizza created!" << endl;
	}

    void ShowIngredients() const {
        cout << "   Інгредієнти: ";
        for (int i = 0; i < count; i++) {
            cout << ingredients[i];
            if (i != count - 1) cout << ", ";
        }
        cout << "." << endl;
    }

    void AddIngredient(const string& ingr) {
        if (count < 10) {
            ingredients[count++] = ingr;
        }
    }
    virtual ~Pizza() = default;
};

class MilanPizza : public Pizza {
    public:
    MilanPizza() {
        AddIngredient("тонке тісто");
        AddIngredient("пармезан");
        AddIngredient("моцарела");
        AddIngredient("салямі");
        AddIngredient("томатний соус");
    }
    virtual void CookPizza() const override {
        cout << "Milan Pizza created!" << endl;
        ShowIngredients();
	}
};

class GreecePizza : public Pizza {
public:
    GreecePizza() {
        AddIngredient("пухке тісто");
        AddIngredient("фета");
        AddIngredient("оливки");
        AddIngredient("помідори");
        AddIngredient("цибуля");
    }
    virtual void CookPizza() const override {
        cout << "Greece Pizza created!" << endl;
        ShowIngredients();
    }
};

class Souse {
    public:
    virtual void CookSouse() const {
        cout << "Souse prepared!" << endl;
    }

    virtual ~Souse() = default;
};

class MilanSouse : public Souse {
    public:
    virtual void CookSouse() const override {
        cout << "Milan Souse prepared!" << endl;
    }
};

class GreeceSouse : public Souse {
    public:
    virtual void CookSouse() const override {
        cout << "Greece Souse prepared!" << endl;
    }
};

class Factory {
public:
    virtual Pizza* CreatePizza() = 0;
    virtual Souse* PrepareSouse() = 0;
    virtual ~Factory() = default;
};

class MilanFactory : public Factory {
public:
    Pizza* CreatePizza() override {
        return new MilanPizza();
    }
    Souse* PrepareSouse() override {
        return new MilanSouse();
    }
};

class GreeceFactory : public Factory {
public:
    Pizza* CreatePizza() override {
        return new GreecePizza();
    }
    Souse* PrepareSouse() override {
        return new GreeceSouse();
    }
};

int main()
{
    setlocale(LC_ALL, "ukr");
    Factory* f1 = new MilanFactory();
    Pizza* p1 = f1->CreatePizza();
    Souse* s1 = f1->PrepareSouse();
    p1->CookPizza();
    s1->CookSouse();
    delete p1;
    delete s1;
    delete f1;

    cout << "====================" << endl;

    Factory* f2 = new GreeceFactory();
    Pizza* p2 = f2->CreatePizza();
    Souse* s2 = f2->PrepareSouse();
    p2->CookPizza();
    s2->CookSouse();
    delete p2;
    delete s2;
    delete f2;

	return 0;
}

