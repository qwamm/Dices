#ifndef LAB2_SIMPLE_CLASS_H
#define LAB2_SIMPLE_CLASS_H

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <functional>

namespace simple_class
{
    template <class T>
    T getNum(T min = std::numeric_limits<T>::min(), T max = std::numeric_limits<T>::max())
    {
        T a;
        while (true)
        {
            std:: cin >> a;
            if (std::cin.eof()) //конец файла
                throw std::runtime_error("Failed to read number: EOF");
            else if (std::cin.bad()) //невосстановимая ошибка входного потока
                throw  std::runtime_error(std::string("Failed to read number") + strerror(errno));
            else if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std:: cout<<"You are wrong, repeat please!"<<std::endl;
            }
            else if (a>=min && a<=max)
                return a;
        }
    }


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

        void generate_random_value() //генерация рандомного значения игральной кости с учетом вероятностей
        {
            srand(time(nullptr));
	    int p = rand()%101;
	    double cnt = (int) (this->probabilities[0]*100);
	    //std::copy(this->probabilities, this->probabilities + 6, buf);
	    //std::sort(buf, buf + 6, std::greater<double>());
	   /*for (int i=0; i<6; i++)
	   {
		std::cout<<buf[i]<<" ";
	   }
	   std::cout<<std::endl; */
	    for (int i = 0; i<6; i++)
	    {
		if (this->probabilities[i] != 0 && cnt > p)
		{
			this->value = i + 1;
			break;
		}
		else if (i < 5)
		{
			cnt += (int) (this->probabilities[i+1]*100);
		}
	    }
	    /*delete[] buf;
	    buf = nullptr;*/
        }

        double get_probability(int num) //изменение значения вероятности выпадения числа
        {
            return this->probabilities[num-1];
        }

        void set_state() //ввод состояния класса через входной поток
        {
            	std::cout << "Enter dropped value of dice:\n";
        	int val = getNum<int>(1,6);
        	this->value = val;
        	double sum = 1.0;
        	for (int i=0; i<6; i++)
        	{
                	std::cout << "Enter probability of dropping number #" << (i+1) << ":\n";
                	double cur = getNum<double>(0,sum);
			this->probabilities[i] = cur;
                	sum -= cur;
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

   //int invite();
   //int D_Create(Dice &d);

   //void D_Create();
}

#endif //LAB2_SIMPLE_CLASS_H
