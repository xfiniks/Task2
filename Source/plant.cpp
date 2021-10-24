//
// Реализация функционала базового класса plant
//


#include <cstring>
#include "plant.h"
#include "tree.h"
#include "shrub.h"
#include "flower.h"
#include "rnd.h"

//Конструктор.
plant::plant(const char *name) {
    strcpy(this->name, name);
}

//Getter поля name
char *plant::GetName() {
    return name;
}
//Getter поля name
char *plant::SetName(char *n) {
    strcpy(name, n);
}
//Ввод растений из файла.
plant *plant::InPlant(FILE *ifst) {
    int in_k;
    if (fscanf(ifst, "%d", &in_k) == EOF)
        return nullptr;

    switch (in_k) {
        case 1:return tree::InTree(ifst);
        case 2:return shrub::InShrub(ifst);
        case 3:return flower::InFlower(ifst);
        default:return nullptr;
    }
}
//Рандомный ввод растения.
plant *plant::InRndPlant() {
    int in_k = rnd::RandomRange(0, 3);
    switch (in_k) {
        case 1:return tree::InRndTree();
        case 2:return shrub::InRndShrub();
        case 3:return flower::InRndFlower();
        default:return nullptr;
    }
}
//Вывод растения в файл.
void plant::OutPlant(FILE *ofst) {
    fprintf(ofst, " Name = %s. Task result: %f\n", name, CalculateQuotient());
}
//Функция из ТЗ.
double plant::CalculateQuotient() {
    double vowelsCount = 0;
    char vowels[max_name_len] = "aeyuioAEYUIO";
    for (int i = 0; i < strlen(name); i++) {
        if (name[i] == vowels[0] || name[i] == vowels[1] || name[i] == vowels[2] ||
            name[i] == vowels[3] || name[i] == vowels[4] || name[i] == vowels[5] ||
            name[i] == vowels[6] || name[i] == vowels[7] || name[i] == vowels[8] ||
            name[i] == vowels[9] || name[i] == vowels[10] || name[i] == vowels[11]) {
            vowelsCount++;
        }
    }
    return (double) vowelsCount / (double) strlen(name);
}
