#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

const int SIZE = 25;
const int BUCKET_SIZE = 51; // определяем размер карманов, учитывая диапазон значений от -25 до 25

static void bucketSort(int *arr) {

    int buckets[BUCKET_SIZE]{ 0 };  

    for (int i = 0; i < SIZE; i++) {
        int index = arr[i] + 25; // смещаем диапазон значений, чтобы наименьшее значение стало равным 0
        ++buckets[index]; 
    }

    
    int idx = 0;

    for (int i = 0; i < BUCKET_SIZE; ++i) {
        for (int j = 0; j < buckets[i]; ++j) {
            arr[idx++] = i - 25; // отнимаем 25, чтобы преобразовать индекс кармана обратно в значение элемента
        }
    }
}

int main() {

    srand(time(0));
    system("chcp 1251 > Null");

    int arr[SIZE]{};

    for (int i = 0; i < SIZE; ++i) {
        arr[i] = rand() % 26 - 15; 
    }

    cout << "Неотсортированный массив: ";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;
    
    auto start = high_resolution_clock::now();

    bucketSort(arr);
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Отсортированный массив: ";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl << "Время выполнения программы (в микросекундах): " << duration.count() << endl;

    return 0;
}
