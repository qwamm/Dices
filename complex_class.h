#ifndef COMPLEX_CLASS
#define COMPLEX_CLASS

#include <iostream>
#include <cstring>
#include "simple_class.h"

namespace complex_class
{
	class Dices
	{
		private:
		 	simple_class::Dice *arr; //массив игральных костей
			int arr_size; //размер массива
        public:
            Dices(int honest) //инициализаця массива кол-вом честных костей с заполнением их случайными числами
            {
                this->arr_size = honest;
                this->arr = new simple_class::Dice[this->arr_size];
                for (int i=0; i < this->arr_size; i++)
                {
                    simple_class::Dice x;
                    this->arr[i] = x;
                }
            }

            Dices (int honest, int *values) //инициализация массива кол-вом честных костей и массивом их значений
            {
                this->arr_size = honest;
                this->arr = new simple_class::Dice[this->arr_size];
                for (int i=0; i < this->arr_size; i++)
                {
                    this->arr[i].set_val(values[i]);
                }
            }

            Dices() : Dices(0) {}

            ~Dices()
            {
                std::cout << "Group of dices was destroyed\n";
            }

            void print()
            {
                for (int j=0; j<this->arr_size; j++)
                {
                    this->arr[j].print(std::cout);
                }
            }

            bool check(int num) //проверка, есть ли кость с заданным номером в массиве
            {
                for (int i=0; i< this->arr_size; i++)
                {
                    if (this->arr[i].get_val() == num)
                    {
                                return true;
                    }
                }
                return false;
            }
	};
}

#endif
