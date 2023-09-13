#ifndef LAB2_SIMPLE_CLASS_H
#define LAB2_SIMPLE_CLASS_H

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <random>

namespace simple_class
{
    class Dice
    {
    private:
        int value;
        double probabilities[6];
    public:
        Dice() //конструктор по умолчанию
        {
            this->value = 3;
            for (int i=0; i<6; i++)
            {
                this->probabilities[i] = 1.0/6.0;
            }
        }

        Dice (const int &cur_value, const double arr[6])
        {
            value = cur_value;
            std::copy(arr, arr+6, probabilities);
            std::cout << "The dice was created" << std::endl;
        }
        ~Dice()
        {
            std::cout << "The dice was deleted" << std::endl;
        }
        void set_val (const int &cur_value) //изменение текущего значения игральной кости
        {
            this->value = cur_value;
        }
        void set_probability_of_dropping (const double p, const int num) //изменение значения вероятности выпадения числа
        {
            this->probabilities[num-1] = p;
        }
        int get_val() //изменение текущего значения игральной кости
        {
            return this->value;
        }

        void set_random()
        {
            srand(time(nullptr));
            this->value = rand()%6;
            for (int i=0; i<6; i++)
            {
                this->probabilities[i] = 1.0/6.0;
            }
        }

        void generate_random_value()
        {
            srand(time(nullptr));
        }

        double get_probability(int num) //изменение значения вероятности выпадения числа
        {
            return this->probabilities[num-1];
        }

        void set_state() //ввод состояния класса через входной поток
        {
            std::cout << "Enter current value of dice: \n";
            std::cin >> this->value;
            for (int i=0; i<6; i++)
            {
                std::cout << "Enter probability of dropping " << (i+1) << " number:\n";
                std::cin >> this->probabilities[i];
            }
        }

        void print() //вывод состояния игральной кости
        {
            std::cout << "Current value of dice: " << this->value << std::endl;
            for (int i = 0; i<6; i++)
            {
                std::cout << "Probability of dropping value " << (i+1) << ": " << this->probabilities[i] << std::endl;
            }
        }
    };
}

#endif //LAB2_SIMPLE_CLASS_H
