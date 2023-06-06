#include <iostream>
#include <vector>
#include <ctime>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

const int HASH_TABLE_SIZE = 20;
const int MIN_RANGE = 12000;
const int MAX_RANGE = 34000;

int hashFunction(int key);
void printArray(vector<int> arr);
void printHashTable(vector<int> hashTable);
void searchInHashTable(vector<int> hashTable);

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    int n = 15;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (MAX_RANGE - MIN_RANGE) + MIN_RANGE;
    }

    vector<int> hashTable(HASH_TABLE_SIZE, -1);
    for (int i = 0; i < n; i++) {
        if (arr[i] >= MIN_RANGE && arr[i] <= MAX_RANGE) {
            int index = hashFunction(arr[i]);
            while (hashTable[index] != -1) {
                index = (index + 1) % HASH_TABLE_SIZE;
            }
            hashTable[index] = arr[i];
        }
    }

    printArray(arr);
    cout << "<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3"<<endl<<endl;
    printHashTable(hashTable);
    system("pause");

    char key;
    do
    {
        system("cls");
        printHashTable(hashTable);
        cout << "<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3" << endl << endl;;
        searchInHashTable(hashTable);
        cout << "<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3" << endl << endl;;
        cout << "Хотите продолжить? (нет - 0, да - любая клавиша)\n";

        cin >> key;
    } while (key != '0');


    return 0;
}

int hashFunction(int key) {
    return key % HASH_TABLE_SIZE;
}

void printArray(std::vector<int> arr)
{
    cout << "Исходный массив: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

void printHashTable(vector<int> hashTable)
{
    cout << "Хеш-таблица:\n";
    for (int i = 0; i < hashTable.size(); i++) {
        cout << "[" << i + 1 << "]\t->\t" << hashTable[i] << '\n';
    }
    cout << '\n';
}

void searchInHashTable(vector<int> hashTable)
{
    int searchKey;
    cout << "Введите ключ для поиска: ";
    cin >> searchKey;

    int index = hashFunction(searchKey);
    while (hashTable[index] != searchKey && hashTable[index] != -1) {
        index = (index + 1) % HASH_TABLE_SIZE;
    }

    if (hashTable[index] == searchKey) {
        cout << "Элемент НАЙДЕН в хеш-таблице\n";
    }
    else {
        cout << "Элемент НЕ НАЙДЕН в хеш-таблице\n";
    }
}