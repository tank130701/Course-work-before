// Kursovaya_Medveditskov_Marshruti.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class Point
{
    int x;
    int y;
    string name;
public:
    Point();
    ~Point();
    void setPoint(Point* a, int x, int y, string name);
    int getPoint_x();
    int getPoint_y();
    string getPoint_name();

};
class List
{

    Point a;
    List* next;
    double distanse;
    //List* prev;
public:


    List();
    ~List();
    void start_list(List** begin);
    void add_point(List** begin);
    void insert_point(List** begin);
    void delete_point(List** begin);
    void Print_Points(List* begin);
    void Delete(List** begin);
    void calcualte_distance(List* begin);

};



Point::Point()
{
    x = 0; y = 0; name = "untitled";
}
Point::~Point()
{

}

void Point::setPoint(Point* a, int x, int y, string name)
{

    (*a).x = x;
    (*a).y = y;
    (*a).name = name;
}

int Point::getPoint_x()
{
    return x;
}

int Point::getPoint_y()
{
    return y;
}

string Point::getPoint_name()
{
    return name;
}

List::List()
{
    //Point* a = new Point;
    List* next = NULL;
    //List* prev = NULL;
}

List::~List()
{

}

void List::start_list(List** begin)
{
    Point a;
    int x, y;
    string name;
    cout << "Введите ваше местоположение" << endl;
    cout << "Введите x" << endl;
    cin >> x;
    cout << "Введите y" << endl;
    cin >> y;
    cout << "Введите название" << endl;
    cin >> name;
    a.setPoint(&a, x, y, name);
    List* start = new List;
    (start)->a = a;

    (start)->next = NULL;
    *begin = start;

}

void List::add_point(List** begin)
{
    List* old_end = *begin;
    List* new_end = new List;

    Point a;
    int x, y;
    string name;
    cout << "Введите x" << endl;
    cin >> x;
    cout << "Введите y" << endl;
    cin >> y;
    cout << "Введите название" << endl;
    cin >> name;
    a.setPoint(&a, x, y, name);
    new_end->a = a;
    new_end->next = NULL;

    while (1)
    {
        if (!old_end->next)
        {
            old_end->next = new_end;
            break;
        }
        old_end = old_end->next;
    }

}

void List::insert_point(List** begin)
{

    List* newlist = new List;
    List* oldlist = *begin;
    string current_name;
    cout << "Введите название точки после которой необходимо осуществить вствку" << endl;
    cin >> current_name;

    while (oldlist->a.getPoint_name() != current_name)
    {
        oldlist = oldlist->next;
        if (oldlist->a.getPoint_name() == current_name)
        {

            int x, y;
            string name;

            cout << "Введите x" << endl;
            cin >> x;
            cout << "Введите y" << endl;
            cin >> y;
            cout << "Введите название" << endl;
            cin >> name;
            Point a;
            a.setPoint(&a, x, y, name);
            newlist->a = a;
            newlist->next = oldlist->next;
            oldlist->next = newlist;
            //(*begin) = oldlist;
            break;
        }
        else
        {
            cout << "Точка не найдена" << endl;
            return;
        }
    }

}

void List::delete_point(List** begin)
{
    List* oldlist = *begin;
    if (oldlist == NULL) {
        cout << "Список пуст" << endl;
        return;
    }
    string name;
    cout << "Введите название точки которую необходимо удалить" << endl;
    cin >> name;

    if (oldlist->a.getPoint_name() == name)
    {
        *begin = oldlist->next;
        delete oldlist;
        return;
    }
    List* toDelete = oldlist->next;
    while (toDelete)
    {
        if (toDelete->a.getPoint_name() == name)
        {
            oldlist->next = toDelete->next;
            delete toDelete;
            return;
        }
        oldlist = toDelete;
        toDelete = toDelete->next;
    }
    cout << "Точка не найдена" << endl;
}



void List::Print_Points(List* begin)
{
    List* print = new List;
    print = begin;

    while (print)
    {
        cout << "Название: " << print->a.getPoint_name() << "\n" << "Координаты X и Y: (" << print->a.getPoint_x() << ";" << print->a.getPoint_y() << ")" << endl;
        cout << "=========================================================\n";

        //print->a = print->next->a;
        print = print->next;
    }


}

void List::Delete(List** begin)
{
    if (*begin == 0) return;
    List* p = *begin;
    List* t;
    while (p)
    {
        t = p;
        p = p->next;
        delete t;
    }
    *begin = NULL;
}

int menu() {
    cout << "\n1. Создание списка\n"
        "2. Вывод списка на экран\n"
        "3. Вставка элемента\n"
        "4. Добавление в список\n"
        "5. Удаление списка\n"
        "6. Удаление точки\n"
        "7. Расчитать стоимость поездки\n"
        "0. Выход из программы " << endl;
    int commandID;
    cout << "~$ ";
    cin >> commandID;
    return commandID;
};

void List::calcualte_distance(List* begin)
{

    List* get = new List;
    get = begin;
    get->next = begin->next;
    int x1, x2, y1, y2;
    double distance = 0;
    if (get->next == NULL)
    {
        cout << "В вашем маршруте должо быть больше одной точки";
        return;
    }
    while (get->next) {
        x1 = get->a.getPoint_x();
        x2 = get->next->a.getPoint_x();
        y1 = get->a.getPoint_y();
        y2 = get->next->a.getPoint_y();
        distance = distance + (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
        get = get->next;
    }
    cout << "distance = " << distance << endl;
    cout << "Стоимость поездки составит: " << 15 * distance << "  рублей" << endl;

}

int main()
{
    SetConsoleTitle(L"Диспетчерская Такси");
    setlocale(LC_ALL, "Russian");
    //system("color F0");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    List* begin = NULL;
    //List d;



    while (true) {
        int commandID = menu();
        bool exit = false;
        switch (commandID) {
        case 0:
            exit = true;
            break;
        case 1:
            //Создание списка

            begin->start_list(&begin);
            break;
        case 2:
            //Вывод списка
            if (begin == NULL)
                cout << "Список пуст" << endl;
            else
                begin->Print_Points(begin);
            break;
        case 3:
            //вставка элемента
            begin->insert_point(&begin);
            break;
        case 4:
            //Добавление в список
            if (begin == NULL)
                begin->start_list(&begin);
            else
                begin->add_point(&begin);
            break;
        case 5:
            //Удаление списка
            begin->Delete(&begin);
            break;
        case 6:
            //Удаление точки
            begin->delete_point(&begin);
            break;
        case 7:
            //Расчитать стоимость поездки
            begin->calcualte_distance(begin);
            break;
        }
        if (exit == true) break;

    }
    //std::cout << "Hello World!\n";
    //return 0;
}


