#include <iostream>
#include <string>
using namespace std;
const int length = 100;

int findIndex(int* arr, int length) {
    for (int i = 0; i < length; i++) {
        int colv1 = 0;
        int cur10 = arr[i];
        int cur2 = 0;
        int d = 1;
        while (cur10) {
            cur2 += cur10 % 2 *d;
            cur10 /= 2;
            d *= 10;
        }
        while (cur2) {
            if (cur2%10 == 1) {
                colv1++;
            }
            cur2 /= 10;
        }
        if (colv1 == 3) {
            return i;
        }
    }
    return -1; //error flag
}

void insertAfter(int* arr, int& length, int num, int index) {
    index++;
    for (int i = length; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = num;
}

void deleteElement(int* arr, int& n, int index) {
    for (int i = index; i < n; i++) {
        arr[i] = arr[i + 1];
    }
    n -= 1;
}

void getArr(int* arr, int length) {
    cout << "������� �������� �������" << endl;
    for (int i = 0; i < length; i++) {
        int a;
        while (true) {
            cin >> a;
            if (cin.fail() || cin.peek() != '\n') {
                cin.clear();
                cin.ignore(32777, '\n');
                cout << "Input error! Repeat please..." << endl;
            }
            else
                break;
        }
        arr[i] = a;
    }
}

void printArr(int* arr, int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << endl;
    }
}

int main() {

    system("chcp 65001");

    int n = -1;
    int chooser = 100;
    int arr[length];
    int index = -1;

    while (chooser != 0) {
        system("cls");

        cout << "������������ ������ �1 ����-08-21 �������� �.�. ������� 16" << endl << endl;
        cout << "������� 1" << endl;
        cout << "����\n";
        cout << "1) ��������� ������\n";
        cout << "2) ������� ������\n";
        cout << "3) ����� ������ ������� ��������, � �������� �������� ��� �������� ����� 3 �������\n";
        cout << "4) �������� ����� ������� � ������ ����� ��������� �������\n";
        cout << "5) ������� ��� ��������, � ������� � �������� ���� ����� 3 �������\n";
        cout << "0) �����\n";

        cout << "��� �����: ";
        cin >> chooser;

        switch (chooser)
        {
            case 1: {
                cout << "������� ���-�� ��������� � �������: ";
                while (cin >> n) {
                    if (n >= 100) {
                        cout << "������� ������� ��������. ���������� ��� ���" << endl;
                    }
                    else break;
                }
                getArr(arr, n);
                system("pause");
                break;
            }
            case 2: {
                if (n == -1) {
                    cout << "������ �� �����. ���������� ��� ���." << endl;
                    system("pause");
                    break;
                }
                cout << "����� �������" << endl;
                printArr(arr, n);
                system("pause");
                break;
            }
            case 3: {
                index = findIndex(arr, n);
                if (index == -1) {
                    cout << "������. ������� �� ������." << endl;
                }
                else cout << "������: " << index << endl;
                system("pause");
                break;
            }
            case 4: {
                if (n == -1) {
                    cout << "������ �� �����. ���������� ��� ���." << endl;
                    system("pause");
                    break;
                }
                if (index == -1) {
                    cout << "��������! ������ ��������, ����� �������� ���� �������� �����, �� �����! �������� 1 ���� ������ ����� � ���� ��� 0 ���� ������ ������ ������ ��������������" << endl;
                    int ans;
                    cin >> ans;
                    if (ans == 0) {
                        cout << "������� ������" << endl;
                        cin >> index;
                    }
                    else break;
                }
                cout << "������� �����, ������� ������ ��������" << endl;
                int num;
                cin >> num;
                cout << "������ �� ����������� ���������" << endl;
                insertAfter(arr, n, num, index);
                printArr(arr, n);
                system("pause");
                break;
            }

            case 5: {
                if (n == -1) {
                    cout << "������ �� �����. ���������� ��� ���." << endl;
                    system("pause");
                    break;
                }
                cout << "������ ����� �������� ���������, �������� ��� ������� �������� ����� 3 �������:" << endl;
                int found = findIndex(arr, n);
                while (found != -1) {
                    deleteElement(arr, n, found);
                    found = findIndex(arr, n);
                }

                printArr(arr, n);
                system("pause");
                break;
            }

            case 0: { return 0; }
            default: {
                chooser = 100;
                break;
            }

        }

    }return 0;
}