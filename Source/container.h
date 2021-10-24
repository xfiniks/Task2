//
// Описание класса conteiner.
//

#ifndef TASK_2__CONTAINER_H_
#define TASK_2__CONTAINER_H_

#include <cstdio>
#include "plant.h"
class container {
 private:
  enum { max_len = 10000 }; // максимальная длина
  int len = 0; // текущая длина
  plant **cont; //контейнер с растениями
 public:
  // Конструктор.
  container();
  // Деструктор.
  ~container();

// Ввод содержимого контейнера из указанного потока
  void InContainer(FILE *ifst);

// Случайный ввод содержимого контейнера
  void InRndContainer(int size);

// Вывод содержимого контейнера в указанный поток
  void OutContainer(FILE *ofst);

// Shell sort
  void ShellSortContainer();
};

#endif //TASK_2__CONTAINER_H_
