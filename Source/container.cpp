//
// Реализация функционала класса container.
//


#include "container.h"
#include "plant.h"

//Конструктор.
container::container() {
    cont = new plant *[max_len];
}
//Деструктор.
container::~container() {
    for (int i = 0; i < len; ++i) {
        delete (cont[i]);
    }
    delete[] cont;
}

//Ввод данных растений из файла
void container::InContainer(FILE *ifst) {
    plant *newPlant;
    while ((newPlant = plant::InPlant(ifst)) != nullptr) {
        cont[len] = newPlant;
        len++;
    }
}
//Рандомной заполнение контейнера.
void container::InRndContainer(int size) {
    while (len < size) {
        if ((cont[len] = plant::InRndPlant()) != nullptr) {
            len++;
        }
    }
}
//Вывод двнных контейнера.
void container::OutContainer(FILE *ofst) {
    fprintf(ofst, "Container contains %d elements.\n", len);
    for (int i = 0; i < len; i++) {
        fprintf(ofst, "%d: ", i);
        cont[i]->OutPlant(ofst);
    }
}
//Shell sort.
void container::ShellSortContainer() {
    for (int s = len / 2; s > 0; s /= 2) {
        for (int i = 0; i < len; i++) {
            for (int j = i + s; j < len; j += s) {
                if (cont[i]->CalculateQuotient() > cont[j]->CalculateQuotient()) {
                    plant *temp = cont[j];
                    cont[j] = cont[i];
                    cont[i] = temp;
                }
            }
        }
    }
}