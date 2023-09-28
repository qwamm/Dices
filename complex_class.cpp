#include <iostream>
#include "simple_class.h"
#include "complex_class.h"

using namespace complex_class;

simple_class::Dice& Dices::operator [] (const int ind)
{
	simple_class::Dice &ref = this->arr[ind];
	return ref;
}

void Dices::ascii_art()
{
	for (int i=0; i < this->arr_size; i++)
	{
        	std::string res = this->arr[i].ascii_art();
        	for (int i=0; i < res.length(); i++)
        	{
                	if (i>=9 && i%9 == 0)
                	{
                        	std :: cout << "\n";
                	}
                        std :: cout << res[i];
        	}
        	std::cout << "\n\n";
	}
}

bool Dices::operator -= (simple_class::Dice &obj)
{
	bool cond = false;
	for (int i=0; i < this->arr_size; i++)
	{
		while (obj.get_val() == this->arr[i].get_val())
		{
			this->arr[i].~Dice();
			this->arr[i] = this->arr[this->arr_size - 1];
			(this->arr_size)--;
			cond = true;
		}
	}
	return cond;
}

bool Dices::operator () (int num)
{
	if (this->arr_size + 1 < num)
		return false;
	this->arr[num-1].generate_random_value();
	return true;
}

bool Dices::operator () ()
{
	for (int i = 0; i < arr_size; i++)
	{
		this->arr[i].generate_random_value();
	}
	return true;
}

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

bool Dices::operator += (simple_class::Dice &obj)
{
	if (this->arr_size == 100)
	{
		return false;
	}
	this->arr[this->arr_size].set_val(obj.get_val());
	this->arr[this->arr_size].resize(obj.get_size());
	this->arr[this->arr_size].set_size(obj.get_size());
	for (int i=0; i < obj.get_size(); i++)
	{
		this->arr[this->arr_size].set_probability_of_dropping(obj.get_probability(i+1), i+1);
	}
	(this->arr_size) ++;
	obj.~Dice();
	return true;
}

void Dices::print(std::ostream &out) //вывод характеристик каждой кости из группы игральных костей
{
         for (int j=0; j < this->arr_size; j++)
         {
              this->arr[j].print(out);
         }
}
