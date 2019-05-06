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


        substr[size - 1] = '\0';

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
    this->Head = nullptr;
    this->Tail = nullptr;

    if (!(obj.Head == obj.Tail && obj.Head == nullptr)) {


        Link *buf = obj.Head;


        while (buf != nullptr) {
            Link *temp = new Link;
            temp->data = buf->data;

            if (Head != nullptr) {
                temp->Prev = Tail;
                Tail->Next = temp;
                Tail = temp;
            } else //Если список пустой
            {
                temp->Prev = nullptr;
                Head = Tail = temp;
            }

            buf = buf->Next;
        }
    }

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
/*    while (Head) {
        Tail = Head->Next;
        delete Head;
        Head = Tail;

    }*/

    Multi_character_links *Res = new Multi_character_links(data);

    this->Head = Res->Head;
    this->Tail = Res->Tail;

}


Multi_character_links &Multi_character_links::operator=(Multi_character_links &data) {


/*    while (Head) {
        Tail = Head->Next;
        delete Head;
        Head = Tail;

    }*/

    Multi_character_links *Res = new Multi_character_links(data);

    this->Head = Res->Head;
    this->Tail = Res->Tail;
    return *Res;

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
    Link *temp = Head;
    while (temp != nullptr) {
        cout << temp->data << "|";
        temp = temp->Next;
    }
    cout << "\n";

}

Multi_character_links &Multi_character_links::operator+(Multi_character_links &data) {

    Multi_character_links *Res = new Multi_character_links(*this);

    Multi_character_links *Buf = new Multi_character_links(data);

    if (Res->Head == Res->Tail && Res->Head == nullptr) {

        return *Buf;
    }
    if (Buf->Head == Buf->Tail && Buf->Head == nullptr) {

        return *Res;
    }


    Res->Tail->Next = Buf->Head;
    Res->Tail = Buf->Tail;

    return *Res;

}

Multi_character_links &Multi_character_links::operator+(const char *const data) {


    Multi_character_links *Res = new Multi_character_links(*this);

    Multi_character_links *Buf = new Multi_character_links(data);

    Res->Tail->Next = Buf->Head;
    Res->Tail = Buf->Tail;

    return *Res;
}

Multi_character_links &operator+(const char *const data, Multi_character_links &obj) {

    Multi_character_links *Buf = new Multi_character_links(obj);

    Multi_character_links *Res = new Multi_character_links(data);

    if (Res->Head != nullptr) {
        Res->Tail->Next = Buf->Head;
        Res->Tail = Buf->Tail;
    } else {
        Res = Buf;
    }

    return *Res;
};


unsigned int Multi_character_links::length() {
    Link *temp = Head;
    unsigned int count = 0;

    while (temp != nullptr) {
        count = count + strlen(temp->data);
        temp = temp->Next;

    }
    return count;
}

int search_string(char *string1, char *string2) {
    if (strlen(string2) > strlen(string1)) { return -1; }

    if ((strlen(string1) == strlen(string2)) && strcmp(string1, string2) == 0) { return 0; }

    for (int i = 0; i <= strlen(string1) - strlen(string2); i++) {
        char *newStr = new char[strlen(string2) + 1];

        for (int j = 0; j < strlen(string2); j++) {
            newStr[j] = string1[i + j];
        }
        newStr[strlen(string2) + 1] = '\0';


        if (strcmp(newStr, string2) == 0) {
            delete[] newStr;
            return i;
        }
        delete[] newStr;
    }

    return -1;


}

int Multi_character_links::pos(Multi_character_links &sub) {

    int len = length();
    int len2 = sub.length();

    char *allstr = new char[len];

    int j = 0;
    Link *temp = Head;

    while (temp != nullptr) {

        for (int i = 0; i < strlen(temp->data); i++) {
            allstr[j + i] = temp->data[i];
        }

        j = j + strlen(temp->data);
        temp = temp->Next;
    }
    allstr[len] = '\0';

    char *substr = new char[len2];

    j = 0;
    temp = sub.Head;

    while (temp != nullptr) {

        for (int i = 0; i < strlen(temp->data); i++) {
            substr[j + i] = temp->data[i];
        }

        j = j + strlen(temp->data);
        temp = temp->Next;
    }
    substr[len2] = '\0';

    return search_string(allstr, substr);

}


Multi_character_links &Multi_character_links::substr(int k, int n) {

    int len = length();

    if (k >= len || n < k || k < 0 || n < 0) {
        Multi_character_links *Res = new Multi_character_links;
        return *Res;
    }

    char *substr;
    char *allstr = new char[len];

    if (n >= len) {
        n = len;
    }
    substr = new char[n - k + 1];

    int j = 0;
    Link *temp = Head;

    while (temp != nullptr) {

        for (int i = 0; i < strlen(temp->data); i++) {
            allstr[j + i] = temp->data[i];
        }

        j = j + strlen(temp->data);
        temp = temp->Next;
    }

    allstr[len] = '\0';


    memcpy((substr), &allstr[k], n - k + 1);
    substr[n - k + 1] = '\0';

    //  delete[] allstr;

    Multi_character_links *Res = new Multi_character_links(substr);

//    delete[] substr;

    return *Res;


}

Multi_character_links &Multi_character_links::del(int k, int n) {
    Multi_character_links *Res = new Multi_character_links;

    int len = length();

    if (n >= len) { n = len - 1; }

    if (n - k == len || k > n || k < 0 || n < 0) {
        delete Res;
        return *Res = *this;
    }

    if (k == 0 && n < len) {
        *Res = this->substr(n + 1, length());

    } else {

        *Res = this->substr(0, k - 1) + this->substr(n + 1, length());
    }

    return *Res;

}

void change(Multi_character_links &obj1, Multi_character_links &obj2, Multi_character_links &obj3) {


    if (obj3.pos(obj2) == -1) {
        int p = obj1.pos(obj2);

        Multi_character_links buf = obj1;

        while (p != -1) {
            buf = obj1.substr(0, p - 1) + obj3;
            buf = buf + obj1.substr(p + obj2.length(), obj1.length());
            obj1 = buf;
            p = obj1.pos(obj2);
        }
    }
};