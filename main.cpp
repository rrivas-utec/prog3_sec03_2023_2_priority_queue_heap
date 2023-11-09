#include <iostream>
#include <queue>
#include <vector>
#include <functional>

void ejercicio_1() {

    // std::priority_queue<int, std::vector<int>, std::less<>> pq;
    std::priority_queue<int> pq;
    pq.push(10);
    pq.push(2);
    pq.push(30);
    pq.push(20);
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }
}

template <typename T>
struct mayor_que {
    bool operator ()(T a, T b) {      // Sobrecargar el operador () - Functor
        return a > b;
    }
};

template <typename T>
struct menor_que {
    bool operator ()(T a, T b) {      // Sobrecargar el operador () - Functor
        return a < b;
    }
};

void ejercicio_2() {
    std::vector v {1, 4, 10, 50, 45, 20, 39, 89, 11};
    //std::priority_queue<int> pq(v); // porque no existe el constructor pq(Container cnt)

    std::priority_queue<int> pq(std::less<int>(), v);
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }
}

void ejercicio_3() {
    std::vector v {1, 4, 10, 50, 45, 20, 39, 89, 11};
    //std::priority_queue<int> pq(v); // porque no existe el constructor pq(Container cnt)

    std::priority_queue<int> pq(std::begin(v), std::end(v));
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }

}

void ejercicio_4() {
    std::vector v {1, 4, 10, 50, 45, 20, 39, 89, 11};
    //std::priority_queue<int> pq(v); // porque no existe el constructor pq(Container cnt)

    std::priority_queue<int, std::vector<int>, std::greater<int>>
            pq(std::begin(v), std::end(v), std::greater<int>());
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }

}

void ejercicio_5() {
    std::vector v {1, 4, 10, 50, 45, 20, 39, 89, 11};
    //std::priority_queue<int> pq(v); // porque no existe el constructor pq(Container cnt)

    std::priority_queue<int, std::vector<int>, mayor_que<int>>
            pq(std::begin(v), std::end(v), mayor_que<int>());
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }
}

void ejercicio_6() {
    std::vector v {1, 4, 10, 50, 45, 20, 39, 89, 11};
    //std::priority_queue<int> pq(v); // porque no existe el constructor pq(Container cnt)

    auto compare_greater = [](auto a, auto b) { return a > b; };
    std::priority_queue<int, std::vector<int>, decltype(compare_greater)>
            pq(std::begin(v), std::end(v), compare_greater);
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }
}

void ejercicio_7() {
    std::vector v {1, 4, 10, 50, 45, 20, 39, 89, 11};
    //std::priority_queue<int> pq(v); // porque no existe el constructor pq(Container cnt)

    auto compare_greater = [](auto a, auto b) { return a > b; };
    std::priority_queue<int, std::vector<int>, bool(*)(int, int)>
            pq(std::begin(v), std::end(v), compare_greater);
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }
}

void ejercicio_8() {
    std::vector v {1, 4, 10, 50, 45, 20, 39, 89, 11};
    //std::priority_queue<int> pq(v); // porque no existe el constructor pq(Container cnt)

    auto compare_greater = [](auto a, auto b) { return a > b; };
    std::priority_queue<int, std::vector<int>, std::function<bool(int, int)>>
            pq(std::begin(v), std::end(v), compare_greater);
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }
}

bool greater_fun(int a, int b) { return a > b; }

void ejercicio_9() {
    std::vector v {1, 4, 10, 50, 45, 20, 39, 89, 11};
    //std::priority_queue<int> pq(v); // porque no existe el constructor pq(Container cnt)

    auto compare_greater = [](auto a, auto b) { return a > b; };
    std::priority_queue<int, std::vector<int>, std::function<bool(int, int)>>
            pq(std::begin(v), std::end(v), greater_fun);
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }
}

class Persona {
    std::string nombre;
    std::string apellido;
    int edad;
public:
    Persona(std::string nombre, std::string apellido, int edad):
        nombre(std::move(nombre)), apellido(std::move(apellido)), edad(edad) {}

    [[nodiscard]] std::string get_nombre() const {return nombre; }
    [[nodiscard]] std::string get_apellido() const {return apellido; }
    [[nodiscard]] int get_edad() const {return edad; }

    bool operator<(const Persona& otro) {
        return apellido < otro.apellido;
    }
};


void ejercicio_10() {
    std::vector vp {Persona("Jose", "Perez", 18), Persona("Maria", "Abarca", 17), Persona("Rosa", "Zapata", 20)};

    std::priority_queue<Persona, std::vector<Persona>, std::less<>>
            pq(std::begin(vp), std::end(vp));
    while (!pq.empty()) {
        std::cout << pq.top().get_apellido() << " " << pq.top().get_nombre() << "\n";
        pq.pop();
    }
}

void ejercicio_11() {
    std::vector vp {Persona("Jose", "Perez", 18), Persona("Maria", "Abarca", 17), Persona("Rosa", "Zapata", 20)};

    auto compare_greater_name = [](auto a, auto b) { return a.get_nombre() > b.get_nombre(); };
    auto compare_greater_apellido = [](auto a, auto b) { return a.get_apellido() > b.get_apellido(); };
    auto compare_greater_edad = [](auto a, auto b) { return a.get_edad() > b.get_edad(); };

    std::priority_queue<Persona, std::vector<Persona>, decltype(compare_greater_name)>
            pq1(std::begin(vp), std::end(vp), compare_greater_name);
    while (!pq1.empty()) {
        std::cout << pq1.top().get_apellido() << " " << pq1.top().get_nombre() << "\n";
        pq1.pop();
    }
    std::cout << "--------------------\n";
    std::priority_queue<Persona, std::vector<Persona>, decltype(compare_greater_apellido)>
            pq2(std::begin(vp), std::end(vp), compare_greater_apellido);
    while (!pq2.empty()) {
        std::cout << pq2.top().get_apellido() << " " << pq2.top().get_nombre() << "\n";
        pq2.pop();
    }
    std::cout << "--------------------\n";
    std::priority_queue<Persona, std::vector<Persona>, decltype(compare_greater_edad)>
            pq3(std::begin(vp), std::end(vp), compare_greater_edad);
    while (!pq3.empty()) {
        std::cout << pq3.top().get_apellido() << " " << pq3.top().get_nombre() << " " << pq3.top().get_edad() << "\n";
        pq3.pop();
    }
}


int main() {
//    ejercicio_1();
//    ejercicio_2();
//    ejercicio_3();
    std::cout << std::endl;
//    ejercicio_4();
//    ejercicio_5();
//    ejercicio_6();
//    ejercicio_10();
    ejercicio_11();

    return 0;
}
