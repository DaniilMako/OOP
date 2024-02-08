// дз 8 Спортсмены
#include <iostream>
#include <list>

using namespace std;

int main() {
    int n;
    cin >> n;  // кол-во запросов/пар
    list<int> positions;  // позиции игроков
    /*auto it = positions.begin();*/
    for (int i = 0; i < n; i++) {
        int current_player, next_player;
        cin >> current_player >> next_player;  // ввод попарное неотрицательных чисел: текущий спортсмен и за кем он стоит
        auto place = positions.end();  // берется конец списка, если следующего спортсмена нет в списке
        for (auto player = positions.begin(); player != positions.end(); player++) {  // перебор для проверки на наличие следующего спортсмена
            if (*player == next_player) {  // если спортсмен из списка равен следующему спортсмену
                place = player;  // месту в списке присваивается спортсмен
                break;
            }
        }
        positions.insert(place, current_player);  // вставляется текущий спортсмен в место
    }

    cout << "Output:\n";  // ВЫВОД
    for (auto i : positions)
        cout << i << "\n";

    return 0;
}


//Ввод
//5
//42 0
//17 42
//13 0
//123 42
//5 13

//Вывод
//17
//123
//42
//5
//13