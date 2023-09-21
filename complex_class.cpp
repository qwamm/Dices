#include <iostream>
#include "simple_class.h"
#include "complex_class.h"

using namespace complex_class;

bool Dices::check(int num) //проверка, есть ли кость с заданным номером в массиве
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

int Dices::sum() //подсчет суммы очков в группе костей
{
         int res = 0;
         for (int i=0; i < this->arr_size; i++)
         {
               res += this->arr[i].get_val();
         }
         return res;
}

bool Dices::operator += (simple_class::Dice &obj) const
{
	simple_class::Dice *new_arr = new simple_class::Dice[this->arr_size + 1];
	for (int i = 0; i < this->arr_size; i++)
	{
		new_arr[i] = arr[i];
	}
	new_arr[this->arr_size] = obj;
	delete[] this->arr;
	this->arr = new_arr;
	this->arr_size ++;
	return true;
}

void Dices::print() //вывод характеристик каждой кости из группы игральных костей
{
         for (int j=0; j < this->arr_size; j++)
         {
              this->arr[j].print(std::cout);
         }
}