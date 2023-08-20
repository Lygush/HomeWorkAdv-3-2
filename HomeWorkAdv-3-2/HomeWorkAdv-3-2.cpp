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

    smart_array(const smart_array& arr) {
        this->size = arr.size;
        this->logical_index = arr.logical_index;
        this->arr = new int[size];
        for (int i{}; i < size; ++i) {
            this->arr[i] = arr.arr[i];
        }
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
        if (this != &arr) {
            this->size = arr.size;
            this->logical_index = arr.logical_index;
            int* new_arr = new int[size];
            for (int i{}; i < size; ++i) {
                new_arr[i] = arr.arr[i];
            }
            delete[] this->arr;
            this->arr = new_arr;
        }
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

        smart_array new_array(arr);
        new_array.add_element(44);
        new_array.add_element(34);

        std::cout << new_array.get_element(0) << " ";
        std::cout << new_array.get_element(1) << " ";
        std::cout << new_array.get_element(2) << " ";
        std::cout << new_array.get_element(3) << " ";
        std::cout << new_array.get_element(4) << " ";   
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
}