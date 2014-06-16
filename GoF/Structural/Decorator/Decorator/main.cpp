#include <iostream>

using namespace std;

//
// Объект - то, к чему мы будем добавлять детали,
// или что мы будем декорировать
//

class Object {
public:
    virtual void LookAt() = 0;
};

//
// Face - лицо, которое мы будем декорировать
//

class Face: public Object {
public:
    void LookAt() {
        cout << "Face ";
    }
};

//
// Декоратор декорирует объект component,
// на который ссылается переменная detail
//

class Decorator: public Object {
public:
    Decorator(Object *component) {
        detail = component;
    }

    void LookAt() {
        detail->LookAt();
    }

private:
    Object *detail;
};

//
// Усы, добавляемые к объекту
//

class Wisker: public Decorator {
public:
    Wisker(Object *component): Decorator(component){}

    void LookAt() {
        Decorator::LookAt();
        cout << "with a wisker ";
    }
};

//
// Шляпа, добавляемая к объекту
//

class Hat: public Decorator {
public:
    Hat(Object *component): Decorator(component){}
    void LookAt() {
        Decorator::LookAt();
        cout << "in a hat ";
    }
};

//
// Перо, добавляемое к объекту
//

class Feather: public Decorator {
public:
    Feather(Object *component): Decorator(component){}
    void LookAt() {
        Decorator::LookAt();
        cout << "with a feather ";
    }
};

int main() {
    Object *man = new Face;
    Object *man1 = new Wisker(new Wisker(new Face));
    Object *man2 = new Hat(new Wisker(new Face));
    Object *man3 = new Feather(new Hat(new Wisker(new Face)));

    man->LookAt();
    cout <<'\n';

    man1->LookAt();
    cout << '\n';

    man2->LookAt();
    cout << '\n';

    man3->LookAt();
    cout << '\n';

}

