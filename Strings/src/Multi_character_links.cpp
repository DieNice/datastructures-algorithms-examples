//
// Created by pda on 21.04.19.
//


#include "Multi_character_links.h"

Multi_character_links::Multi_character_links(const char *const data) {

    bool flag = true;//check end of data

    while (flag) {

        Link *temp = new Link;               //Выделение памяти под новый элемент структуры
        temp->Next = nullptr;                   //Указываем, что изначально по следующему адресу пусто

        unsigned int len = 0;

        if (data[0] == ' ') {

        } else {

        }

        char *substr = new char[len + 1];


        for (int i = 0; i < len; i++) {
            substr[i] = data[i];
        }

        substr[len + 1] = '\0';



        // temp->x = x;                         //Записываем значение в структуру

        /* if (Head != nullptr)                    //Если список не пуст
         {
             temp->Prev = Tail;               //Указываем адрес на предыдущий элемент в соотв. поле
             Tail->Next = temp;               //Указываем адрес следующего за хвостом элемента
             Tail = temp;                     //Меняем адрес хвоста
         } else //Если список пустой
         {
             temp->Prev = nullptr;               //Предыдущий элемент указывает в пустоту
             Head = Tail = temp;              //Голова=Хвост=тот элемент, что сейчас добавили
         }*/

        delete[] temp;

        flag = false;
    }
}

Multi_character_links::Multi_character_links(const Multi_character_links &obj) {

}

Multi_character_links::~Multi_character_links() {
/*    while (Head)                       //Пока по адресу на начало списка что-то есть
    {
        Tail = Head->Next;             //Резервная копия адреса следующего звена списка
        delete Head;                   //Очистка памяти от первого звена
        Head = Tail;                   //Смена адреса начала на адрес следующего элемента

    }*/
}

Multi_character_links &Multi_character_links::operator=(const char *const data) {

}


Multi_character_links &Multi_character_links::operator=(Multi_character_links data) {

}

std::ostream &operator<<(std::ostream &out, const Multi_character_links &obj) {

}


#include "Multi_character_links.h"
