//
// Описание функционала класса shrub.
//

#ifndef TASK_2__SHRUB_H_
#define TASK_2__SHRUB_H_

#include <cstdio>
#include "plant.h"
//Наследование от класса plant.
class shrub : public plant {
 private:
  enum FLOWERING_MONTH {
    JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY,
    AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER
  } floweringMonth; //месяц цветения
 public:
  //Конструктор.
  shrub(const char *name, FLOWERING_MONTH);

  // Ввод параметров кустарника из файла(пришлось сделать static)
  static shrub *InShrub(FILE *ifst);

// Рандомный ввод параметров кустарника(пришлось сделать static)
  static shrub *InRndShrub();

// Вывод параметров кустарника в файл
  void OutPlant(FILE *ofst) override;
};

#endif //TASK_2__SHRUB_H_
