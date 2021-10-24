//
// Описание класса tree.
//

#ifndef TASK_2__TREE_H_
#define TASK_2__TREE_H_

#include <cstdio>
#include "plant.h"

//Наследование от класса plant.
class tree : public plant {
 private:
  long long age; // возраст
 public:
  //Конструктор.
  tree(const char *name, long long age);

  // Ввод параметров дерева из файла(пришлось сделать static)
  static tree *InTree(FILE *ifst);

//Рандомный ввод параметров дерева(пришлось сделать static)
  static tree *InRndTree();

// Вывод параметров дерева в файл.
  void OutPlant(FILE *ofst) override;
};

#endif //TASK_2__TREE_H_
