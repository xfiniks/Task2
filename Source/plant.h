//
// Описание базового класса plant.
//

#ifndef TASK_2__PLANT_H_
#define TASK_2__PLANT_H_

#include <cstdio>

class plant {
 protected:
  enum { max_name_len = 256 }; // максимальная длина имени

  char name[max_name_len]; //Имя растения.


 public:
  //Конструктор.
  plant(const char *name);

  //Getter поля name;
  char *GetName();
  //Setter поля name.
  char *SetName(char *n);

  // Ввод растения из файла.
  static plant *InPlant(FILE *ifst);

// Рандомный ввод растения.
  static plant *InRndPlant();

// Вывод растения вв файл.
  virtual void OutPlant(FILE *ofst);

// Вычисление частного от деления числа гласных букв в названии на общую длину названия (действительное число)
  double CalculateQuotient();
};

#endif //TASK_2__PLANT_H_
