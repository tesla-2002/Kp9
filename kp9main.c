#include "table.h"

int main(int argv, char* argc[]) {
    FILE* file1, * file2; //Создание потоков для чтения из файлов
    int size = 0, flag = 0, key = 0, index = 0; //Размер, меню, значение искомого ключа, индекс искомого ключа соотв.
    enum {
        MIXED = 1,
        SORTED = 2,
        REVSORTED = 3
    };
    while (1) {
        printf("Что Вы хотите сделать?:\n [1] - Проверить для неупорядоченных данных\n [2] - Проверить для упорядоченных данных \n\
 [3] - Проверить для упорядоченных в обратном порядке данных \n [0] - Завершить\n");
        fscanf(stdin, "%d", &flag);
        switch (flag) {
        case MIXED:
            if ((file1 = fopen("keys.txt", "r")) == NULL) { //Проверка, откроется ли файл на чтение
                printf("Не удалось открыть файл");
                exit(1);
            }

            if ((file2 = fopen("data.txt", "r")) == NULL) { //Проверка, откроется ли файл на чтение
                printf("Не удалось открыть файл");
                exit(1);
            }

            size = getsize(file1);
            Data* datamix = calloc(size, sizeof(Data));
            read_data(datamix, file1, file2);
            fclose(file1);
            fclose(file2);
            printf("Исходная таблица:\n");
            print_data(datamix, size);
            heap_sort(datamix, size);
            printf("Отсортированная таблица:\n");
            print_data(datamix, size);
            if (is_sorted(datamix, size)) {
                printf("Введите ключ, который необходимо найти:\n");
                fscanf(stdin, "%d", &key);
                index = binary_search(datamix, size, key);
                if (index != -1) {
                    printf("Соответствующее ключу поле таблицы: %s", datamix[index]->text);
                } else {
                    printf("Такого ключа нет в таблице\n");
                }
            } else {
                printf("Таблица неотсортирована!\n");
            }
            free_data(datamix, size);
            break;

        case SORTED:
            if ((file1 = fopen("keys_sorted.txt", "r")) == NULL) { //Проверка, откроется ли файл на чтение
                printf("Не удалось открыть файл");
                exit(1);
            }

            if ((file2 = fopen("data_sorted.txt", "r")) == NULL) { //Проверка, откроется ли файл на чтение
                printf("Не удалось открыть файл");
                exit(1);
            }

            size = getsize(file1);
            Data* datasort = calloc(size, sizeof(Data));
            read_data(datasort, file1, file2);
            fclose(file1);
            fclose(file2);
            printf("Исходная таблица:\n");
            print_data(datasort, size);
            heap_sort(datasort, size);
            printf("Отсортированная таблица:\n");
            print_data(datasort, size);
            if (is_sorted(datasort, size)) {
                printf("Введите ключ, который необходимо найти:\n");
                fscanf(stdin, "%d", &key);
                index = binary_search(datasort, size, key);
                if (index != -1) {
                    printf("Соответствующее ключу поле таблицы: %s", datasort[index]->text);
                } else {
                    printf("Такого ключа нет в таблице\n");
                }
            } else {
                printf("Таблица неотсортирована!\n");
            }
            free_data(datasort, size);
            break;

        case REVSORTED:
            if ((file1 = fopen("keys_revers.txt", "r")) == NULL) { //Проверка, откроется ли файл на чтение
                printf("Не удалось открыть файл");
                exit(1);
            }

            if ((file2 = fopen("data_revers.txt", "r")) == NULL) { //Проверка, откроется ли файл на чтение
                printf("Не удалось открыть файл");
                exit(1);
            }

            size = getsize(file1);
            Data* datarevsort = calloc(size, sizeof(Data));
            read_data(datarevsort, file1, file2);
            fclose(file1);
            fclose(file2);
            printf("Исходная таблица:\n");
            print_data(datarevsort, size);
            heap_sort(datarevsort, size);
            printf("Отсортированная таблица:\n");
            print_data(datarevsort, size);
            if (is_sorted(datarevsort, size)) {
                printf("Введите ключ, который необходимо найти:\n");
                fscanf(stdin, "%d", &key);
                index = binary_search(datarevsort, size, key);
                if (index != -1) {
                    printf("Соответствующее ключу поле таблицы: %s", datarevsort[index]->text);
                } else {
                    printf("Такого ключа нет в таблице\n");
                }
            } else {
                printf("Таблица неотсортирована!\n");
            }
            free_data(datarevsort, size);
            break;

        default:
            return 0;
        }
    }
}
