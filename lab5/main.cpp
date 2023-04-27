/* 1) Дана строка длиной не более 100 символов. Посчитать количество знаков препинания в ней.  ASCII
   ! - 33 | " - 34 | # - 35 | % - 37 | & - 38 | ' - 39 |
   ( - 40 | ) - 41 | * - 42 | + - 43 | , - 44 | - - 45 |
   . - 46 | / - 47 | : - 58 | ; - 59 | < - 60 | = - 61 |
   > - 62 | ? - 63 | [ - 91 | \ - 92 | ] - 93 | ^ - 94 |
   ` - 96 | { - 123 | | - 124 | } - 125 | ~ - 126 |
*/

/*
#include <iostream>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    char string[100];               // массив строки
    cout << "Enter string: ";
    gets(string);                   // ввод строки
    cout << strlen(string) << endl;
    if ((strlen(string) > 100) || (strlen(string) <= 0)) {  // нарушение диапазона
        cout << "Error. The length of the entered string is longer than allowed" << endl;
        return 1;
    }

    int cnt_marks = 0; // количество знаков препинания
    int cnt_space = 0; // количество пробелов
    for (int i = 0; i < strlen(string); i++) {
        if (((string[i] >= 33) && (string[i] <= 47)) || ((string[i] >= 58) && (string[i] <= 63))
        || ((string[i] >= 91) && (string[i] <= 96)) || ((string[i] >= 123) && (string[i] <= 126)))
        {
            cnt_marks += 1;     // подсчёт знаков препинания
        }
        if (string[i] == 32) {
            cnt_space += 1;     // подсчёт пробелов
        }
    }

    //int cnt_Letters;                                            // количество обычных букв
   // cnt_Letters = strlen(string) - cnt_marks - cnt_space;       // подсчёт обычных букв

    if (cnt_marks == 0) {                                       // если нет знаков препинания
        cout << "The string does not have punctuation marks." << endl;;
        return 0;
    }

    cout << "String: " << string << endl;
    cout << "Punctuation marks: " << cnt_marks << endl;
    // cout << "Letters: " << cnt_Letters << endl;
    return 0;
}
*/


/* 2) Дан файл, содержащий русский текст, размер текста не превышает 10 К байт. Найти в тексте N (N ≤ 100)
   самых коротких слов, содержащих какую-либо букву три раза. 
   Записать найденные слова в текстовый файл в порядке возрастания длины.
   Все найденные слова должны быть разными. Число N вводить из файла.
*/


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");

    wifstream in("input.txt");
    wofstream out("output.txt");

    int N, cnt = 0, good_cnt = 0;
    wstring str;                // считывание файла
    wstring words[1000];        // только слова
    wstring good_words[100];    // cлова на вывод
    in >> N;
    wcout << "Count of output words: " << N << endl;
    while (!in.eof()) {
        in >> str;

        while (ispunct(str[str.length() - 1])) {        // eсли последний символ слова пункт. знак
            str.erase(str.length() - 1);                // удаляем последний символ
        }

        for (int i = 0; i < str.length(); i++) {
            str[i] = tolower(str[i]);                  // прописная -> строчная для англ букв

            if(str[i] >= 225 && str[i] <=255 ) {
                str[i] = str[i] - 32;                   // прописная -> строчная для рус букв
            }
        }        
            words[cnt] = str;
            cnt += 1;
    }

    wchar_t letters[512];                               // массив для букв и их кол-ва в каждом слове
    for(int i = 0; i < cnt; i++) {

        fill(letters, letters+512,0);                   // заполняем этот массив нулями

        wstring tmp = words[i];                         // tmp = одно слово из массива words
        wcout << tmp << endl;
        for(int j=0;j<tmp.length();j++) {               // перебор букв tmp
            letters[tmp[j]]++;                          // считываем j букву tmp в первый блок letters
        }

        // for(int k = 0; k < 256; k++) {                               // узнаём кол-во определённой буквы в tmp
        //    if(letters[k] > 0) {
        //        cout << (char)k << " " << (int)letters[k] << endl;    // вывод эл-та ASCII и сколько его в tmp
        //    }
        //}
        for (int k = 0; k < 512; k++) {
            if ((int)letters[k] == 3) {         // если в tmp 3 одинаковых буквы
                good_words[good_cnt] = tmp;     // добавить на вывод этот tmp
                good_cnt += 1;
            }
        }
    }

    for (int i = 0; i < good_cnt-1; i++) {
        for (int j = i+1; j < good_cnt; j++) {
            if (good_words[i] ==  good_words[j]) {
                good_words[j] = ' ';                                // удаление повторов
            }
            if (good_words[i].length() > good_words[j].length()) {
                swap(good_words[i], good_words[j]);                 // cортировка по длине слов
            }
        }
    }

    int n = 0;                                // для сравнения с N
    wcout << "Program is completed! Check 'output.txt' file" << endl;
    for (int i = 0; i < 100; i++)
        if (good_words[i] != L" ") {          // удаление лишних пробелов
            out << good_words[i] << " ";
            n += 1;
            if (n == N) {                     // вывод N слов
                break;
            }
        }


    return 0;
}

/*
Сварить густое пюре с маслом и яйцом, добавить муку, сделать лепешки.
Вареное мясо прокрутить на мясорубке + 2 вареных яйца + специи.
Жарить на сковородке мелко нарезанный лук + соусы + смесь из мяса и яйца.
Сделать пирожки из лепешек и полученной начинки, обжарить с двух сторон.

Astana is the capital of Kazakhstan.
A scientist created a apparatus for cooking - the multicooker.
*/

