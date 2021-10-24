//
// Реализация функционала класса flower.
//

#include <cstring>
#include "flower.h"
#include "rnd.h"

//Конструктор.
flower::flower(const char *name, flower::FLOWER_TYPE ft) : plant(name), type(ft) {}

//Ввод цветка из файла.
flower *flower::InFlower(FILE *ifst) {
    char name[256];
    if (fscanf(ifst, "%s", name) == EOF)
        return nullptr;
    char flowerType[10];
    if (fscanf(ifst, "%s", flowerType) == EOF)
        return nullptr;
    FLOWER_TYPE ftype;
    if (strcmp(flowerType, "DOMESTIC") == 0) {
        ftype = DOMESTIC;
    } else if (strcmp(flowerType, "GARDEN") == 0) {
        ftype = GARDEN;
    } else if (strcmp(flowerType, "WILD") == 0) {
        ftype = WILD;
    } else {
        return nullptr;
    }

    return new flower(name, ftype);
}
//Рандомный ввод цветка.
flower *flower::InRndFlower() {
    FLOWER_TYPE ft;
    int random = rnd::RandomRange(0, 2);
    // Случайный тип цветка
    ft = static_cast<FLOWER_TYPE>(random);
    char name[256];
    rnd::RandomString(name, 11);
    return new flower(name, ft);
}
//Вывод цветка.
void flower::OutPlant(FILE *ofst) {
    char *flowerType;
    if (type == DOMESTIC) {
        flowerType = "DOMESTIC";
    } else if (type == GARDEN) {
        flowerType = "GARDEN";
    } else if (type == WILD) {
        flowerType = "WILD";
    } else {
        flowerType = "WRONG_TYPE";
    }

    fprintf(ofst, "It is Flower: type = %s. Name = %s. Task result: %f\n", flowerType, name, CalculateQuotient());
}

