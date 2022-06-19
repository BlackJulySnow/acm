//
// Created by B1GGersnow on 2022/5/1.
//

class Foo { int x; };

int main(){
    for (;;) {
        Foo* p = new Foo;
        delete p;
    }
}