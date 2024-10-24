#include <iostream>
#include <chrono>
#include <cstdlib>  // Для функции rand() и srand()
#include <ctime> 
#include <vector>

using namespace std;
using namespace chrono;

void bubbleSort(int arr[], int n) {

    setlocale(LC_ALL, "RU");
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    cout << "\n";
}

void findMinMax(int arr[], int n, int& min, int& max) {
    min = arr[0];
    max = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    cout << "\n";
}

void findIndices(int arr[], int n, int value, vector<int>& indices) {
    indices.clear(); // Очистка вектора перед использованием
    for (int i = 0; i < n; ++i) {
        if (arr[i] == value) {
            indices.push_back(i); // Добавление индекса в вектор
        }
    }
    cout << "\n";
}

int countLessThan(int arr[], int n, int a) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] < a) {
            count++;
        }
    }
    return count;
}

int countBiggestThan(int arr[], int n, int b) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] > b) {
            count++;
        }
    }
    return count;
}

bool binarySearch(int arr[], int n, int value) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == value)
            return true;
        else if (arr[mid] < value)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}

bool linearSearch(int arr[], int n, int value) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] == value)
            return true;
    }
    return false;
}

void swapElements(int arr[], int index1, int index2) {
    swap(arr[index1], arr[index2]);
}

int main() {

    setlocale(LC_ALL, "RU");
    const int N = 100;
    int arr[N];

    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < N; ++i) {
        arr[i] = rand() % 199 - 99;
    }


    cout << "Элементы массива до сортировки:" << endl;
    for (int i = 0; i < N; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "\n";

    // Запрос значения для уменьшения четных элементов
    int value_to_decrease;
    cout << "Введите значение для уменьшения четных элементов: ";
    cin >> value_to_decrease;

    // Новый код для работы с четными элементами
    int end_val = 9;
    int start_val = 1;

    // Генерация случайного числа в диапазоне от start_val до end_val
    int random_value = (rand() % (end_val - start_val + 1) + start_val);

    // Подсчет четных и нечетных элементов
    int count_even = 0;
    int count_odd = 0;

    // Обработка элементов массива
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            // Уменьшение четных элементов
            arr[i] -= value_to_decrease;
            if (arr[i] % 2 == 0) {
                count_even += 1;
            }
        }
        else if (i % 2 != 0 && arr[i] % 2 != 0) {
            count_odd += 1;
        }
    }
    cout << "\n";
    cout << "Массив после вычитания значения " << value_to_decrease << ":" << endl;
    for (int i = 0; i < N; ++i) {
        cout << arr[i] << " ";
    }

    // Умножение четных элементов на random_value
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            // Умножение четных элементов на random_value
            arr[i] *= random_value;
        }
    }
    cout << "\n" << "\n";
    cout << "Массив после умножения четных элементов на значение " << random_value << ":" << endl;
    for (int i = 0; i < N; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n" << "\n";
    cout << "Количество четных элементов: " << count_even << endl;
    cout << "Количество нечетных элементов: " << count_odd << endl;
    for (int i = 1; i < 10; i++) {
        int counter_del = 0;
        for (int j = 0; j < N; j++) {
            if (arr[j] % i == 0) {
                counter_del += 1;
            }
        };
        cout << " Кол-во чисел делящихся на " << i << " равно " << counter_del << endl;
    };



    //3 zad

    // Время поиска минимального и максимального элемента в неотсортированном массиве
    auto start = chrono::high_resolution_clock::now();
    int minUnsorted, maxUnsorted;
    findMinMax(arr, N, minUnsorted, maxUnsorted);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double, std::nano> elapsedUnsorted = end - start; // Время в наносекундах


    cout << "Минимальный элемент (неотсортированный): " << minUnsorted << endl;
    cout << "Максимальный элемент (неотсортированный): " << maxUnsorted << endl;
    cout << "Время поиска минимального и максимального элемента (неотсортированный): "
        << elapsedUnsorted.count() << " наносекунд." << endl;

    bubbleSort(arr, N);// Сортировка баблсортом


    cout << "Элементы массива после сортировки:" << endl;
    for (int i = 0; i < N; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "\n";

    // время поиска минимального и максимального элемента в отсортированном массиве
    start = chrono::high_resolution_clock::now();
    int minSorted, maxSorted;
    findMinMax(arr, N, minSorted, maxSorted);
    end = chrono::high_resolution_clock::now();

    chrono::duration<double, std::nano> elapsedSorted = end - start; // Время в наносекундах

    cout << "Минимальный элемент (отсортированный): " << minSorted << endl;
    cout << "Максимальный элемент (отсортированный): " << maxSorted << endl;
    cout << "Время поиска (отсортированный): " << elapsedSorted.count() << " наносекунд" << endl;


    //4 zad

    //ср.знач макс и мин элементов
    double averageUnsorted = round((minUnsorted + maxUnsorted) / 2.0);
    double averageSorted = round((minSorted + maxSorted) / 2.0);

    cout << "Среднее значение (неотсортированный): " << averageUnsorted << endl;
    cout << "Среднее значение (отсортированный): " << averageSorted << endl;

    // Поиск индексов для неотсортированного массива
    vector<int> indicesUnsorted;
    start = chrono::high_resolution_clock::now();
    findIndices(arr, N, averageUnsorted, indicesUnsorted);
    end = chrono::high_resolution_clock::now();

    chrono::duration<double, std::nano> elapsedIndicesUnsorted = end - start; // Время в наносекундах

    cout << "Индексы элементов, равных среднему значению (неотсортированный): ";
    for (int index : indicesUnsorted) {
        cout << index << " ";
    }
    cout << "\n";
    cout << "Количество: " << indicesUnsorted.size() << endl;
    cout << "Время поиска индексов (неотсортированный): " << elapsedIndicesUnsorted.count() << " наносекунд" << endl;

    vector<int> indicesSorted;
    start = chrono::high_resolution_clock::now();
    findIndices(arr, N, averageSorted, indicesSorted);
    end = chrono::high_resolution_clock::now();

    chrono::duration<double, std::nano> elapsedIndicesSorted = end - start; // Время в наносекундах

    cout << "Индексы элементов, равных среднему значению (отсортированный): ";
    for (int index : indicesSorted) {
        cout << index << " ";
    }
    cout << "\n";
    cout << "Количество: " << indicesSorted.size() << endl;
    cout << "Время поиска индексов (отсортированный): " << elapsedIndicesSorted.count() << " наносекунд" << endl;

    cout << "\n";

    //5 zad

    int a;
    cout << "Введите число a: ";
    cin >> a;

    int countLess = countLessThan(arr, N, a);

    cout << "Количество элементов в отсортированном массиве, которые меньше числа " << a << ": " << countLess << endl;

    cout << "\n";

    //6 zad

    int b;
    cout << "Введите число b: ";
    cin >> b;

    int countGreater = countBiggestThan(arr, N, b);

    cout << "Количество элементов в отсортированном массиве, которые больше числа " << b << ": " << countGreater << endl;
    cout << "\n";

    //7 zad

    int searchValue;
    cout << "Введите число для поиска: ";
    cin >> searchValue;

    // Сравнение скорости бинарного поиска и линейного поиска
    auto startLinear = chrono::high_resolution_clock::now();
    bool foundLinear = linearSearch(arr, N, searchValue);
    auto endLinear = chrono::high_resolution_clock::now();

    chrono::duration<double, std::nano> elapsedLinear = endLinear - startLinear; // Время в наносекундах

    auto startBinary = chrono::high_resolution_clock::now();
    bool foundBinary = binarySearch(arr, N, searchValue);
    auto endBinary = chrono::high_resolution_clock::now();

    chrono::duration<double, std::nano> elapsedBinary = endBinary - startBinary; // Время в наносекундах

    cout << "Результат линейного поиска: " << (foundLinear ? "Найдено" : "Не найдено") << endl;
    cout << "Время линейного поиска: " << elapsedLinear.count() << " наносекунд" << endl;

    cout << "Результат бинарного поиска: " << (foundBinary ? "Найдено" : "Не найдено") << endl;
    cout << "Время бинарного поиска: " << elapsedBinary.count() << " наносекунд" << endl;
    cout << "\n";
    //8 zad

    int index1, index2;
    cout << "Введите индексы для обмена местами (от 0 до " << N - 1 << "): ";
    cin >> index1 >> index2;

    if (index1 >= 0 && index1 < N && index2 >= 0 && index2 < N) {
        auto startSwap = chrono::high_resolution_clock::now();

        swapElements(arr, index1, index2);

        auto endSwap = chrono::high_resolution_clock::now();
        chrono::duration<double, std::nano> elapsedSwap = endSwap - startSwap; // Время в наносекундах

        cout << "Элементы массива после обмена местами:" << endl;
        for (int i = 0; i < N; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "\n";
        cout << "Время обмена: " << elapsedSwap.count() << " наносекунд" << endl;
    }
    else {
        cout << "Ошибка: индексы должны быть в диапазоне от 0 до " << N - 1 << "." << endl;
    }

    return 0;
}