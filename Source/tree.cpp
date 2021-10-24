//
// Реализация функционала класса tree.
//

#include "tree.h"
#include "rnd.h"

//Констурктор.
tree::tree(const char *name, long long age) : plant(name), age(age) {}

//Ввод дерева из файла.
tree *tree::InTree(FILE *ifst) {
    char name[256];
    if (fscanf(ifst, "%s", name) == EOF)
        return nullptr;

    long long in_age;
    if (fscanf(ifst, "%lld", &in_age) == EOF)
        return nullptr;
    long long ans_age;
    if (in_age > 0) {
        ans_age = in_age;
    } else {
        return nullptr;
    }
    return new tree(name, ans_age);

}

//Рандомный ввод дерева.
tree *tree::InRndTree() {
    long long age = rnd::RandomRange(0, 100000);
    char name[256];
    rnd::RandomString(name, 11);
    return new tree(name, age);
}
//Вывод дерева в файл.
void tree::OutPlant(FILE *ofst) {
    fprintf(ofst, "It is Tree: Age = %lld. Name = %s. Task result: %f\n", age, name, CalculateQuotient());
}
