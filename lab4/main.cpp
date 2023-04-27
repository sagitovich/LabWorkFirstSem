// 1) Дана последовательность натуральных чисел {aj}j=1...n (n<=10000). 
// Если в последовательности есть не менее 3-х чисел, все цифры которых одинаковы, упорядочить последовательность по невозрастанию.

/*
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    cout << "Enter count number in sequence: ";
    int n;    
    cin >> n;  // ввод длины массива 

    if ((n <= 0) || (n > 10000)) { // условия диапазона
        cout << "Error: incorrect sequence length" << endl;
        return 1;  // Если введена недопутсимая длина диапазона, вывести ошибку и завершить работу программы.
    }
    
    const int N = 10000;
    int a[N];  // создание массива
    cout << "Enter number of sequence: " << endl;
    for (int i = 0; i < n; i++) { // заполнение массива
        cin >> a[i];
    }

    int A, b, c;  // временные переменные
    int event = 0;  // в числе все цифры сошлись
    int k;
    for (int i = 0; i < n; i++) {
        k = 0;  // событие сходства цифр в числе
        A = a[i];  // запоминаем первый элемент последовательности
        c = A % 10;  // запоминаем его последнюю цифру
        while(A > 0) {
            A = A / 10;  // укорачиваем число
            b = A % 10;  // запоминаем новую последнюю цифру          
            if (b != c) { // сравниваем страую и новую последние цифры
                k = 0;
                break;  // если они не совпали - стоп
            }
            else {  // если совпали - двигаем дальше
                k += 1;
            }
        }
        
        if (k != 0) {  // если все цифры 
            event += 1;
        }
    }
    


    if (event >= 3) { // вывод обратного массива
        for (int i = 0; i < n-1; i++) {
            sort(a, a+n);  // сортируем по возрастанию
            for (int i = n-1; i >= 0; --i) {  // выводим обратный массив
                cout << a[i] << " ";
            }
            break;
        }
    } 
    else {  // вывод массива
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
    }

    cout << endl;
    return 0;
}
*/

// 2) Ввести последовательность натуральных чисел {Aj}j=1...n (n<=1000).
// Упорядочить последовательность по возрастанию суммы цифр числа,
// числа с одинаковыми суммами цифр дополнительно упорядочить по возрастанию наименьшей цифры числа,
// числа с одинаковыми суммами цифр и одинаковыми наименьшими цифрами дополнительно упорядочить 
// по возростанию самого числа.

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    cout << "Enter count number in sequence: ";
    int n;    
    cin >> n;  // ввод длины массива 

    if ((n <= 0) || (n > 10000)) { // условия диапазона
        cout << "Error: incorrect sequence length" << endl;
        return 1;  // Если введена недопутсимая длина диапазона, вывести ошибку и завершить работу программы.
    }

    int a[n];  // создание массива
    cout << "Enter number of sequence: " << endl;
    for (int i = 0; i < n; i++) { // заполнение массива
        cin >> a[i];
    }


    int sum[n];  // массив суммы цифр каждого числа посл-ти   
    for (int i = 0; i < n; i++) { // подсчёт суммы цифр числа
        int new_a_i = a[i];  // переменная нового a[i] делённого на 10
        sum[i] = 0;
        while (new_a_i > 0) {  // "пока от нового А есть что отрезать"   
            sum[i] += (new_a_i % 10); // добавляем в сумму последний эл-т            
            new_a_i /= 10;  // отрезаем от нового А последнюю цифру  
        }
    }

    int min_digit[n]; // создать массив минимальных цифр числа
    for (int i = 0; i < n; i++) {  // поиск и запоминание минимальной цифры числа 
        min_digit[i] = 9;  // переменная минимально возможной цифры
        int new_a_i = a[i]; // временная переменная sum[i]
        while (new_a_i > 0) {  // пока числа есть
            if (new_a_i % 10 < min_digit[i]) { // если последняя цифра меньше минимальной 
                min_digit[i] = new_a_i % 10; // присвоить её
            } 
            new_a_i /= 10;  // укоротить временную переменную
        }
    }

    for (int i = 0; i < n; i++) {  // сортировка массивов 
        for (int j = i + 1; j < n; j++) {
            if (sum[i] > sum[j]) {  
                swap(sum[i], sum[j]); // выполнение первого критерия
                swap(a[i], a[j]);
                swap(min_digit[i], min_digit[j]);
            }
            if (sum[i] == sum[j]) {
                if (min_digit[i] > min_digit[j]) {
                    swap(min_digit[i], min_digit[j]); // выполнение второго критерия
                    swap(a[i], a[j]);
                }
            }
            if ((sum[i] == sum[j]) && (min_digit[i] == min_digit[j])) {
                if (a[i] > a[j]) {
                    swap(a[i], a[j]);
                }
            }
        }
    }


    cout << "Sequence: ";
    for (int i = 0; i < n; i++) { // вывод массива отсортированных  чисел
        cout << a[i] << " ";
    }
    cout << endl;


    cout << endl;
    return 0;
}


// 3) Дана целочисленная матрица {Aij}i=1..n,j=1..m (n,m<=100). 
// Найти столбец с наибольшим произведением элементов и уменьшить все элементы этого столбца на 3.
 
/*
#include <iostream>
using namespace std;

int main() 
{
    int row, colums;
    cout << "Enter count of matrix rows: "; // ввод кол-ва строк матрицы
    cin >> row;
    if ((row <= 0) || (row > 100)) { // условия диапазона для строк
            cout << "Error: incorrect row length" << endl;
            return 1;  // Если введён недопутсимый размер строки, вывести ошибку и завершить работу программы.
    }

    cout << "Enter count of matrix columns: "; // ввод кол-ва столбцов матрицы
    cin >> colums;
    if ((colums <= 0) || (colums > 100)) { // условия диапазона для столбцов
        cout << "Error: incorrect colums length" << endl;
        return 1;  // Если введён недопутсимый размер столбца, вывести ошибку и завершить работу программы.
    }


    int matrix[row][colums];  // заполнение матрицы
    for (int i = 0; i < row; i++) {
		for (int j = 0; j < colums; j++) {
			cin >> matrix[i][j];
        }
    }
    cout << endl;
    
    int index_max_product = -1;  // индекс столбца с максимальным произведением
    int product[colums], max_product = 1;
    for (int j = 0; j < colums; j++) { // перемножение элементов столбцов
        product[j] = 1;
		for (int i = 0; i < row; i++)  
            product[j] *= matrix[i][j];

        if (product[j] > max_product)
            {max_product = product[j];
            index_max_product = j;}
    }

    
	for (int i = 0; i < row; i++)  {
        matrix[i][index_max_product] = matrix[i][colums] - 3;
        }
    
    

    cout << "Matrix: " << endl;
    for (int i = 0; i < row; i++) {  // вывод матрицы
		for (int j = 0; j < colums; j++) {
			cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "The product of each column: " << endl;
    for (int i = 0; i < colums; i++) {
        cout << product[i] << " ";
    }

    return 0;
}
*/