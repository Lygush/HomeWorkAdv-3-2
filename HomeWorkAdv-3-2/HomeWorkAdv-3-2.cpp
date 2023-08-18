#include <iostream>

class smart_array {
    int size{};
    int logical_index{};
    int* arr{};
public:
    smart_array(int size) {
        arr = new int[size];
        this->size = size;
    }

    ~smart_array() {
        delete[] arr;
    }

    void add_element(int elem) {
        if (logical_index == size) {
            throw std::exception("Выход за пределы массива!");
        }
        else {
            arr[logical_index] = elem;
            logical_index++;
        }
    }

    int get_element(int index) {
        if (index < 0 || index > logical_index) {
            throw std::exception("Индекс выходит за пределы массива!");
        }
        else {
            return arr[index];
        }
    }

    smart_array& operator=(const smart_array& arr) {
        this->size = arr.size;
        this->logical_index = arr.logical_index;
        int* new_arr = new int[size];
        for (int i{}; i < size; ++i) {
            new_arr[i] = arr.arr[i];
        }
        delete[] this-> arr;
        this->arr = new_arr;
        return *this;
    }
};
int main()
{
    setlocale(LC_ALL, "Russian");
    try {
        smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        std::cout << arr.get_element(0) << " ";
        std::cout << arr.get_element(1) << "\n";

        smart_array new_array(2);
        new_array.add_element(44);
        new_array.add_element(34);

        arr = new_array;
        std::cout << arr.get_element(0) << " ";
        std::cout << arr.get_element(1) << " ";
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
}