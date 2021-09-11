#include <iostream>
#include <time.h> // подключение библиотеки для рандома
#include <conio.h>
#include <stdio.h>

using namespace std;
// ---------------------------------------------------------------------------
const int width = 20; //постоянная ширина
const int height = 20; // постоянная высота
int switcher; //переключатель
const int size = width * height; // постоянная величина площади карты
int MapFor[size]; // массив для создания карты
int Point1, Point2; //координаты появления змеи
int Way = 1;
// ---------------------------------------------------------------------------
char SymbolReturn(int Number) // возвращение символьного типа для создания окна
{
    if (Number > 0) return 'o';
    switch(Number)
    {
        case -100: return 'x';
        case -1: return 'O';
        default: return ' ';
    }


}
// ---------------------------------------------------------------------------
void OutMap() // вывод карты
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            cout << SymbolReturn(MapFor[i + j * width]);

        }
    cout << "\n";

    }
}
// ---------------------------------------------------------------------------
void FoodMake() // отрисовка еды
{
    int Food1, Food2;
    //do
    //{
        srand(time(NULL)); // задается рандом по времени
        Food1 = rand() % (width - 2) + 1; // рандом появления еды по ширине
        Food2 = rand() % (height - 2) + 1; // рандом появления по высоте
    //}
    //while(MapFor[Food1 + Food2 * height] != 20);
    MapFor[Food1 + Food2 * height] = -100;
}
// ---------------------------------------------------------------------------
void SnakeMove() // движение змеи
{
    while(true) // бесконечный цикл всегда нужен при управлении
    {
        if (_kbhit())  // функция проверяет считывание с клавиатуры
        {
            char key = _getch(); // гетч получает код буквы, на которую нажал игрок
            switch(key)
            {
                case 'w':    if(Way != 3) Way = 1;   break;
                case 'a':    if(Way != 4) Way = 2;   break;
                case 's':    if(Way != 1) Way = 3;   break;
                case 'd':    if(Way != 2) Way = 4;   break;
            }
        }
        // update();
        system("clear"); // в windows system("cls");, обновляет карту
        OutMap(); // выводит новую сгенерированную карту
        switch()    //выбор сложности
        {
            case 1: Sleep(500);  // быстрее происходит отрисовка
            case 2: Sleep(400); // еще быстрее и тд
            case 3: Sleep(200);
        }
    }
}
// ---------------------------------------------------------------------------
void MakeMap()
{
    Point1 = width / 2; // вычисление центра по ширине
    Point2 = height / 2; // вычисление центра по высоте
    MapFor[Point1 + Point2 * width] = 10;

    for (int i = 0; i < width; i++) // заполнение верха и низа
    {
        MapFor[i] = -1;
        MapFor[i + (height-1)* width] = -1; // алгоритм взят с помощью проб и ошибок
    }

    for (int j = 0; j < width; j++) //заполнение правой и левой границы
    {
        MapFor[0 + j * height] = -1;
        MapFor[(width - 1) + j * width] = -1; // также взят с помощью проб и ошибок
    }
}
// ---------------------------------------------------------------------------
int main()
{
    setlocale(LC_ALL, "ru"); // вывод на русском
    cout << "Введите уровень сложности: \n"; // обычное меню
    cout << "1 - Легко\n";
    cout << "2 - Средний\n";
    cout << "3 - Сложный\n";
    cin >> switcher;
    MakeMap();
    FoodMake();
    //OutMap();
    SnakeMove();
    return 0;
}