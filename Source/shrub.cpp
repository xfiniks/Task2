//
// Реализация функционала класса shrub.
//

#include "shrub.h"
#include "tree.h"
#include "flower.h"
#include "rnd.h"
#include <cstring>

//Конструктор.
shrub::shrub(const char *name, FLOWERING_MONTH month) : plant(name), floweringMonth(month) {}

//Ввод кустарника из файла.
shrub *shrub::InShrub(FILE *ifst) {
    char name[256];
    if (fscanf(ifst, "%s", name) == EOF)
        return nullptr;

    char flowering_month[10];
    if (fscanf(ifst, "%s", flowering_month) == EOF)
        return nullptr;
    FLOWERING_MONTH fm;
    if (strcmp(flowering_month, "JANUARY") == 0) {
        fm = JANUARY;
    } else if (strcmp(flowering_month, "FEBRUARY") == 0) {
        fm = FEBRUARY;
    } else if (strcmp(flowering_month, "MARCH") == 0) {
        fm = MARCH;
    } else if (strcmp(flowering_month, "APRIL") == 0) {
        fm = APRIL;
    } else if (strcmp(flowering_month, "MAY") == 0) {
        fm = MAY;
    } else if (strcmp(flowering_month, "JUNE") == 0) {
        fm = JUNE;
    } else if (strcmp(flowering_month, "JULY") == 0) {
        fm = JULY;
    } else if (strcmp(flowering_month, "AUGUST") == 0) {
        fm = AUGUST;
    } else if (strcmp(flowering_month, "SEPTEMBER") == 0) {
        fm = SEPTEMBER;
    } else if (strcmp(flowering_month, "OCTOBER") == 0) {
        fm = OCTOBER;
    } else if (strcmp(flowering_month, "NOVEMBER") == 0) {
        fm = NOVEMBER;
    } else if (strcmp(flowering_month, "DECEMBER") == 0) {
        fm = DECEMBER;
    } else {
        return nullptr;
    }

    return new shrub(name, fm);
}

//Рандомный ввод кустарника.
shrub *shrub::InRndShrub() {
    FLOWERING_MONTH fm;
    int random = rnd::RandomRange(0, 11);
    // Случайное месяц цветения
    fm = static_cast<FLOWERING_MONTH>(random);
    char name[256];
    rnd::RandomString(name, 11);
    return new shrub(name, fm);
}
//Вывод кустарника в файл.
void shrub::OutPlant(FILE *ofst) {
    char *outfloweringMonth;
    if (floweringMonth == JANUARY) {
        outfloweringMonth = "JANUARY";
    } else if (floweringMonth == FEBRUARY) {
        outfloweringMonth = "FEBRUARY";
    } else if (floweringMonth == MARCH) {
        outfloweringMonth = "MARCH";
    } else if (floweringMonth == APRIL) {
        outfloweringMonth = "APRIL";
    } else if (floweringMonth == MAY) {
        outfloweringMonth = "MAY";
    } else if (floweringMonth == JUNE) {
        outfloweringMonth = "JUNE";
    } else if (floweringMonth == JULY) {
        outfloweringMonth = "JULY";
    } else if (floweringMonth == AUGUST) {
        outfloweringMonth = "AUGUST";
    } else if (floweringMonth == SEPTEMBER) {
        outfloweringMonth = "SEPTEMBER";
    } else if (floweringMonth == OCTOBER) {
        outfloweringMonth = "OCTOBER";
    } else if (floweringMonth == NOVEMBER) {
        outfloweringMonth = "NOVEMBER";
    } else if (floweringMonth == DECEMBER) {
        outfloweringMonth = "DECEMBER";
    } else {
        outfloweringMonth = "WRONG_MONTH";
    }

    fprintf(ofst,
            "It is Shrub: Flowering month = %u. Name = %s. Task result: %f\n",
            this->floweringMonth,
            name,
            CalculateQuotient());
}

