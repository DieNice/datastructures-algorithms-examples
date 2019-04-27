//
// Created by pda on 21.04.19.
//


#include "Multi_character_links.h"
#include "cstring"

Multi_character_links::Multi_character_links(const char *const data) {

    unsigned int left = 0;
    unsigned int right = 0;
    unsigned int size = 0;

    Head = nullptr;
    Tail = nullptr;

    while (data[left] != '\0') {


        if (data[left] == ' ') {

            while (data[right] == ' ' && data[right] != '\0') {
                right++;
            }

        } else {
            while (data[right] != ' ' && data[right] != '\0') {
                right++;
            }

        }

        size = right - left + 1;

        char *substr = new char[size];


        memcpy(substr, &data[left], size - 1);


        substr[size] = '\0';

        add_elem(substr, size);

        left = right;


    }
}

void Multi_character_links::add_elem(char *const data, unsigned int size) {
    Link *temp = new Link;               //Выделение памяти под новый элемент структуры
    temp->Next = nullptr;                 //Указываем, что изначально по следующему адресу пусто

    temp->data = new char[size];

    memcpy(temp->data, data, size);                      //Записываем значение в структуру

    if (Head != nullptr)                    //Если список не пуст
    {
        temp->Prev = Tail;               //Указываем адрес на предыдущий элемент в соотв. поле
        Tail->Next = temp;               //Указываем адрес следующего за хвостом элемента
        Tail = temp;                     //Меняем адрес хвоста
    } else //Если список пустой
    {
        temp->Prev = nullptr;               //Предыдущий элемент указывает в пустоту
        Head = Tail = temp;              //Голова=Хвост=тот элемент, что сейчас добавили
    }

}

Multi_character_links::Multi_character_links(const Multi_character_links &obj) {
    Head = obj.Head;
    Tail = obj.Tail;
}

//
Multi_character_links::~Multi_character_links() {
    while (Head)                       //Пока по адресу на начало списка что-то есть
    {
        Tail = Head->Next;             //Резервная копия адреса следующего звена списка
        delete Head;                   //Очистка памяти от первого звена
        Head = Tail;                   //Смена адреса начала на адрес следующего элемента

    }
}

Multi_character_links &Multi_character_links::operator=(const char *const data) {

    unsigned int left = 0;
    unsigned int right = 0;
    unsigned int size = 0;

    Head = nullptr;
    Tail = nullptr;

    while (data[left] != '\0') {


        if (data[left] == ' ') {

            while (data[right] == ' ' && data[right] != '\0') {
                right++;
            }

        } else {
            while (data[right] != ' ' && data[right] != '\0') {
                right++;
            }

        }

        size = right - left + 1;

        char *substr = new char[size];


        memcpy(substr, &data[left], size - 1);


        substr[size] = '\0';

        add_elem(substr, size);

        left = right;


    }
}


Multi_character_links &Multi_character_links::operator=(Multi_character_links &data) {
    Head = data.Head;
    Tail = data.Tail;
}

std::ostream &operator<<(std::ostream &out, const Multi_character_links &obj) {
    Link *temp = obj.Head;
    while (temp != nullptr) {
        out << temp->data;
        temp = temp->Next;
    }
    return out;
}

void Multi_character_links::print() {
    Link *temp = Head;                       //Временно указываем на адрес первого элемента
    while (temp != nullptr)              //Пока не встретим пустое значение
    {
        cout << temp->data << "|";        //Выводим каждое считанное значение на экран
        temp = temp->Next;             //Смена адреса на адрес следующего элемента
    }
    cout << "\n";

}

Multi_character_links &Multi_character_links::operator+(Multi_character_links &data) {

    Multi_character_links *Res;
    Res = this;

    Res->Tail->Next = data.Head;
    Res->Tail = data.Tail;
    return *Res;

}

Multi_character_links &Multi_character_links::operator+(const char *const data) {

    Multi_character_links Sub(data);
    Multi_character_links *Res;
    Res = this;

    Res->Tail->Next = Sub.Head;
    Res->Tail = Sub.Tail;

    return *Res;
}