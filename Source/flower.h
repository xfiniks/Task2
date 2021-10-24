//
// Описание класса flower.
//

#ifndef TASK_2__FLOWER_H_
#define TASK_2__FLOWER_H_

#include <cstdio>
#include "plant.h"

//наследование от класса plant.
class flower : public plant {
 private:
  enum FLOWER_TYPE { DOMESTIC, GARDEN, WILD } type; //тип цветка
 public:
  //Конструктор.
  flower(const char *name, FLOWER_TYPE ft);

  // Ввод параметров цветка из потока(пришлось сделать static)
  static flower *InFlower(FILE *ifst);

// Случайный ввод параметров цветка(пришлось сделать static)
  static flower *InRndFlower();

// Вывод параметров цветка в форматируемый поток(реализация виртуальной функции класса plant)
  void OutPlant(FILE *ofst) override;
};

#endif //TASK_2__FLOWER_H_
