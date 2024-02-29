// �� 8 ����������
#include <iostream>
#include <list>

using namespace std;

int main() {
    int n;
    cin >> n;  // ���-�� ��������/���
    list<int> positions;  // ������� �������
    /*auto it = positions.begin();*/
    for (int i = 0; i < n; i++) {
        int current_player, next_player;
        cin >> current_player >> next_player;  // ���� �������� ��������������� �����: ������� ��������� � �� ��� �� �����
        auto place = positions.end();  // ������� ����� ������, ���� ���������� ���������� ��� � ������
        for (auto player = positions.begin(); player != positions.end(); player++) {  // ������� ��� �������� �� ������� ���������� ����������
            if (*player == next_player) {  // ���� ��������� �� ������ ����� ���������� ����������
                place = player;  // ����� � ������ ������������� ���������
                break;
            }
        }
        positions.insert(place, current_player);  // ����������� ������� ��������� � �����
    }

    cout << "Output:\n";  // �����
    for (auto i : positions)
        cout << i << "\n";

    return 0;
}


//����
//5
//42 0
//17 42
//13 0
//123 42
//5 13

//�����
//17
//123
//42
//5
//13