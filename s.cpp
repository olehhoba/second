
//138 2kn
//Lista jednokierunkowa nie cykliczna
////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <windows.h>
using namespace std;

//////////////////////////////////////////////////////////////////////////
struct LISTA
{
    struct LISTA *nast;
    int x;
};
///////////////////////////////////////////////////////////////////////////
struct LISTA *dodaj(struct LISTA *list)
{
    int szukany,element;
    cout<<"Podaj element ,ktory chcesz wstawic: ";
    cin>>element;
    cout<<"Podaj element wartosc elemntu ,za ktory chcesz wstawic: ";
    cin>>szukany;
    struct LISTA *new_element=new LISTA;
    struct LISTA *temp=NULL;
    new_element->x=element;
    new_element->nast=NULL;
    if(list==NULL)
    {
        list=new_element;
    }
    else
    {
        temp=list;
        while(temp->x!=szukany)
        {
            if(temp->nast==NULL)
            {
                temp->nast=new_element;
                return list;
            }
            else
            {
                temp=temp->nast;
            }
        }
        new_element->nast=temp->nast;
        temp->nast=new_element;
    }
    return list;
};
/////////////////////////////////////////////////////////////////////////////////////////////////////
struct LISTA *usun(struct LISTA *list)
{

    if(list==NULL)
    {
        cout<<"Lista jest pusta,nie moge nic usunac!"<<endl<<endl;
        return list;
    }
    int us;
    cout<<"Podaj wartosci elementow, ktorych chcesz usunac:";
    cin>>us;
    while(list!=NULL && list->x==us)
    {
        list=list->nast;
    }
    struct LISTA* current = list;
    struct LISTA* temp = current;

    while(current != NULL)
    {
        if(current->x == us)
        {
            temp->nast = current->nast;
            delete current;
        }
        else
        {
            temp = current;
        }
        current = current->nast;
    }
    fflush(stdin);
    getchar();
    return list;

};
//////////////////////////////////////////////////////////////////////////
void wydruk(struct LISTA *list)
{
    struct LISTA *temp=list;
    if(temp==NULL)
    {
        cout<<"Lista jest pusta"<<endl;
    }
    else
    {
        cout<<"Lista:\t";
        do
        {
            cout<<temp->x<<"\t";
            temp=temp->nast;
        }while(temp!=NULL);
    }
    cout<<endl;
};
/////////////////////////////////////////////////////////////////////////////

int main()
{
    int choice,element;
    struct LISTA *list=NULL;

    do{
        cout<<"1.Dodanie elementu za element o podanej wartosci(jezeli elementu o podanejwartosci nie ma na liscie, nale¿y dolaczyc element na koncu listy)"<<endl;
        cout<<"2.Usuniecie wszystkich (jezeli jest wiecej niz jeden) elementow o podanej przez uzytkownika wartosci)"<<endl;
        cout<<"3.Wydruk listy od poczatku"<<endl;
        cout<<"4.Koniec"<<endl;
        cout<<endl<<"Twoj wybor: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            list=dodaj(list);
            break;
        case 2:
            list=usun(list);
            break;
        case 3:
            wydruk(list);
            break;
        }
    }while(choice!=4);
    return 0;
}


//Lista dwukierinkowa nie cyckliczna
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;
/*struct LISTA
{
    int data;
    struct LISTA *next;
    struct LISTA *prev;
};*/

struct LISTA
{
    int data;
    struct LISTA *next;
    struct LISTA *prev;

    struct LISTA *head;
    struct LISTA *tail;
    int count;
};

void pushBack(int newdata, struct LISTA* list);
void pushFront (int newdata, struct LISTA* list);
void pushAfter (int newdata, struct LISTA* list);
void popBack(struct LISTA* list);
void popFront(struct LISTA* list);
void popAfter(struct LISTA* list);
void wyswietlFront(struct LISTA* list);
void wyswietlBack(struct LISTA* list);
struct LISTA *szukaj2(struct LISTA* list);
int szukaj (struct LISTA* list);

int main()
{
    int wybor1,wartosc;
    int wybor2;
    struct LISTA* list = new struct      LISTA;
    list->head = NULL;
    list->tail = NULL;
    list->count = 0;
    do
    {
        cout<<"LISTA DWUKIERUNKOWA NIECYKLICZNA:\n1.Dodanie elementu\n2.Usuniecie elementu\n3.Wyswietlenie\n4.Wyszukiwanie elementu o podanym numerze\n5.Zakonczenie dzialania programu\nWybor: ";
        cin>>wybor1;
        if (wybor1 == 1)
        {
            cout<<"\n1. na koniec listy\n2. na poczatek listy\n3. po elemencie o podanej wartosci\nWybor:";
            cin>>wybor2;
            switch (wybor2)
            {
                case 1:
                cout<<"Podaj wartosc dodawanego elemenu: ";
                cin>>wartosc;
                pushBack(wartosc, list);
                break;

                case 2:
                cout<<"Podaj wartosc dodawanego elementu: ";
                cin>>wartosc;
                pushFront(wartosc, list);
                break;

                case 3:
                cout<<"Podaj wartosc dodawanego elementu: ";
                cin>>wartosc;
                pushAfter(wartosc, list);
                break;

                default:
                cout<<"Podano wartosc spoza zakresu";
                break;
            }
            getchar();
        }

        if (wybor1 == 2)
        {
            cout<<"\na. z konca listy\nb. z poczatku listy\nc. elementu o podanej wartosci\nWybor:";
            cin>>wybor2;
            switch (wybor2)
            {
                case 1:
                popBack(list);
                break;

                case 2:
                popFront(list);
                break;

                case 3:
                popAfter(list);
                break;


                default:
                cout<<"Podano wartosc spoza zakresu";
                break;
            }
            getchar();
        }

        if (wybor1 == 3)
        {
            cout<<"\n1. od konca\n2. od poczatku\nWybor:";
            cin>>wybor2;
            switch (wybor2)
            {
                case 1:
                wyswietlBack(list);
                break;

                case 2:
                wyswietlFront(list);
                break;

                default:
                cout<<"Podano wartosc spoza zakresu";
                break;
            }
            getchar();
        }

        if (wybor1 == 4)
        {
            int indeks=szukaj(list);
            if (indeks == 0)
            {
                 cout<<"Szukany element nie znajduje sie na liscie.\n";
            }
            else 
            {
                cout<<"Szukany element jest elementem nr "<<indeks<<endl;
            }
            getchar();
        }

        if (wybor1 == 5) 
        {
            cout<<"Koniec"<<endl;
        }

        getchar();
        system("cls");
    } while (wybor1 != 5);
    return 0;
}


void pushBack(int newdata, struct LISTA* list)
{
    struct LISTA* newEl = (struct LISTA*)malloc(sizeof(struct LISTA));
    newEl->data = newdata;
    newEl->next = NULL;
    if (list->count == 0)
    {
        list->head=newEl;
        list->tail=newEl;
        newEl->prev=NULL;
    }
    else
    {
        newEl->prev=list->tail;
        list->tail->next=newEl;
        list->tail=newEl;
    }
    list->count++;
}

void pushFront (int newdata, struct LISTA* list)
{
    struct LISTA* newEl = (struct LISTA*)malloc(sizeof(struct LISTA));
    newEl->data = newdata;
    newEl->prev = NULL;
    if (list->count == 0)
    {
        list->head=newEl;
        list->tail=newEl;
        newEl->next = NULL;
    }
    else
    {
        newEl->next=list->head;
        list->head->prev=newEl;
        list->head=newEl;
    }
    list->count++;
}

void pushAfter(int newdata, struct LISTA* list)
{
    struct LISTA* newEl = (struct LISTA*)malloc(sizeof(struct LISTA));
    struct LISTA* szukany = (struct LISTA*)malloc(sizeof(struct LISTA));
    szukany=szukaj2(list);
    if (szukany == NULL) pushBack(newdata, list);
    else
    {
        if (szukany == list->tail) pushBack(newdata, list);
        else
        {
            newEl->data = newdata;
            newEl->prev = szukany;
            newEl->next = szukany->next;
            szukany->next->prev = newEl;
            szukany->next = newEl;
            list->count++;
        }
    }

}

void popBack(struct LISTA* list)
{
    if (list->count == 0) printf("LISTA jest pusta\n");
    if (list->count == 1)
    {
        free(list->tail);
        free(list->head);
        list->count=0;
        return;
    }
    if (list->count > 1)
    {
        list->tail=list->tail->prev;
        free(list->tail->next);
        list->tail->next=NULL;
        list->count--;
    }

}

void popFront(struct LISTA* list)
{
    if (list->count == 0) printf("LISTA jest pusta\n");
    if (list->count == 1)
    {
        free(list->head);
        free(list->tail);
        list->count=0;
        return;
    }
    if (list->count > 1)
    {
        list->head=list->head->next;
        free(list->head->prev);
        list->head->prev=NULL;
        list->count--;
    }

}

void popAfter(struct LISTA* list)
{
    struct LISTA* usuwany = (struct LISTA*)malloc(sizeof(struct LISTA));
    usuwany=szukaj2(list);
    if (usuwany == NULL) return;

    else
    {

        if (usuwany->prev == NULL)
        {
            popFront(list);
            return;
        }
        if (usuwany->next == NULL)
        {
            popBack(list);
            return;
        }
        if (usuwany->prev && usuwany->next)
        {
            usuwany->next->prev = usuwany->prev;
            usuwany->prev->next = usuwany->next;
            free(usuwany);
            list->count--;
        }
    }
}

void wyswietlFront(struct LISTA* list)
{
    if (list->count == 0) cout<<"LISTA jest pusta\n";
    else
    {
        struct LISTA* el = new struct LISTA;
        el = list->head;
        while (el)
        {
            cout<<el->data<<"\t";
            el = el->next;
        }
    }
}

void wyswietlBack(struct LISTA* list)
{
    if (list->count == 0) cout<<"LISTA jest pusta\n";
    else
    {
        struct LISTA* el = new struct LISTA;
        el = list->tail;
        while (el)
        {
            cout<<el->data<<"\t";
            el = el->prev;
        }
    }
}

struct LISTA *szukaj2(struct LISTA* list)
{
    int szukana;
    printf("Podaj wartosc elementu o ktory Ci chodzi: ");
    scanf("%d", &szukana);

    struct LISTA* el = (struct LISTA*)malloc(sizeof(struct LISTA));
    el = list->head;
    if (list->count == 0) return NULL;
    else
    {
    while (1)
    {
        if (el->data == szukana) break;
        if (el->next) el = el->next;
        else return NULL;
    }
    return el;
    }
}

int szukaj (struct LISTA* list)
{
    int szukana,indeks=1;
    printf("Podaj wartosc elementu ktorego szukasz: ");
    scanf("%d", &szukana);

    if (list->count == 0) return 0;
    else
    {
    struct LISTA* el = (struct LISTA*)malloc(sizeof(struct LISTA));
    el = list->head;
    while (1)
    {
        if (el->data == szukana) break;

        if (el->next)
        {
        el = el->next;
        indeks++;
        }
        else return 0;
    }
    return indeks;
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////



