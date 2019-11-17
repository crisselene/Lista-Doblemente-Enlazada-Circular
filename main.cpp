#include <iostream>
using namespace std;

struct nod {
    float info;
    struct nod *next;
    struct nod *previous;
}*start, *last;

//variables
int count = 0; //contador de elementos
int i; //para los for
float numBusq; //busqueda de numeros

//métodos
void mostrar_lista();
void insert_principio();
void insert_final();
void insert_pos();
void invertir();
void sum_todos();
void mayor();
void ordenada();
int buscarNodo(float numBusq);
void eliminarRecursiv(float);
void eliminarIterativ(float);
void intercambiar();
nod *getNod(float v);

int main() {
    int op;
    cout <<  "          << PROGRAMA PARA MANIPULAR LISTAS >>" <<endl;
    do {
        cout << "Elija una opcion del menu" << endl ;
        cout << "[ 1 ] Mostrar lista " << endl ;
        cout << "[ 2 ] Insertar un elemento al INICIO de la lista " << endl ;
        cout << "[ 3 ] Insertar un elemento al FINAL de la lista " << endl ;
        cout << "[ 4 ] Insertar un elemento en una POSICION elegida por el usuario " << endl ;
        cout << "[ 5 ] Calculo del mayor de los elementos y cuantas veces se repite " << endl ;
        cout << "[ 6 ] Suma de todos los datos de la lista " << endl ;
        cout << "[ 7 ] Comprobar si la lista esta ORDENADA " << endl ;
        cout << "[ 8 ] Eliminar todas las ocurrencias de un elemento dado de la lista " << endl ;
        cout << "[ 9 ] INVERTIR la lista " << endl ;
        cout << "[ 10 ] INTERCAMBIAR dos nodos dados de la lista " << endl ;
        cout << "[ 0 ] SALIR " << endl ;
        cin >> op;
        switch(op) {
            case 1: mostrar_lista(); break;
            case 2: insert_principio(); break;
            case 3: insert_final(); break;
            case 4: insert_pos(); break;
            case 5: mayor(); break;
            case 6: sum_todos(); break;
            case 7: ordenada(); break;
            case 8:
                cout <<"Ingrese el numero que desea eliminar" <<endl;
                cin >> numBusq;
                eliminarRecursiv(numBusq); break;
            case 9: invertir(); break;
            case 10: intercambiar(); break;
            //caso extra de eliminar iterativamente
            case 11:
                cout <<"Ingrese el numero que desea eliminar" <<endl;
                cin >> numBusq;
                eliminarIterativ(numBusq); break;

        }
    }while(op!= 0);
    cout << "Saliendo...";

}

void intercambiar() {
    int pos1,pos2;
    int cont=1;
    float value;
    bool hecho = false,hecho2 = false;
    nod *aux1;
    nod *val1, *val2;
    //pedir posiciones de los valores a intercambiar
    cout <<"Introduzca la posicion del primer valor a intercambiar" <<endl;
    cin>> pos1;
    cout <<"Introduzca la posicion del segundo valor a intercambiar" <<endl;
    cin>> pos2;
    if (start != NULL){
        //control de errores
        if (pos1<=count && pos2<=count && pos1>0 && pos2>0 && pos1!=pos2) {
            aux1 = start;
            while (hecho == false || hecho2 == false) {
            //obtener los valores de las posiciones dadas
                if (cont == pos2) {
                    val2 = aux1;
                    hecho2 = true;
                    aux1 = aux1->next;
                    cont++;
                } else if (cont == pos1) {
                    val1 = aux1;
                    hecho = true;
                    aux1 = aux1->next;
                    cont++;
                } else {
                    aux1 = aux1->next;
                    cont++;
                }
            } //intercambiar los valores
            value= val2->info;
            val2->info = val1->info;
            val1->info = value;
            cout<<"Intercambiado" <<endl;

        }else cout<<"Posiciones incorrectas, la lista tiene " << count << " elementos" <<endl;
        }else cout << "Lista vacía" << endl;
    }


void eliminarRecursiv(float numBusq) {
    int pos, i;
    nod *ptr, *s;
    //controlar que la lista no este vacia
    if (start == last && start == NULL) {
        cout<<"Lista vacia"<<endl;
        return;
    }
    //buscar el nodo
    pos = buscarNodo(numBusq);
    //sumar 1 para que las posiciones no vayan de 0 a n
    //posiciones de 1 a n
    pos++;
    //si la posicion es -1 es que no se ha encontrado
    if(pos==0) {
        //if (count < pos ) {
           cout << "No encontrado" << endl;
            return;
        }
        s = start;
        if (pos == 1) {
            if(start == last){
               //si solo hay un valor en la lista y lo eliminamos
               //se vacia la lista y start y last es null
               start = NULL;
               last = NULL;
                count--;
                cout<<"Lista vaciada " <<endl;
                return;
            }
            //eliminarRecursiv un elemento en primera posicion
            count--; //quitar uno al contador de elementos
            last->next = s->next;
            s->next->previous = last;
            start = s->next;
            cout << "Elemento eliminado" << endl;
        }else {
            for (i = 0; i < pos - 1; i++) {
                s = s->next;
                ptr = s->previous;
            }
            ptr->next = s->next;
            s->next->previous = ptr;
            if (pos == count) {
                last = ptr;
            }
            count--;
            cout << "Elemento eliminado" << endl;

    }
    //se busca de nuevo y si se encuentra otra vez se elimina
    pos = buscarNodo(numBusq);
    if(pos != -1){
        eliminarRecursiv(numBusq);
    }
}

void eliminarIterativ(float numBusq) {
    int pos, i;
    nod *ptr, *s;
    //controlar que la lista no este vacia
    if (start == last && start == NULL) {
        cout<<"Lista vacia"<<endl;
        return;
    }
    //buscar el nodo
    pos = buscarNodo(numBusq);
    //si se encuentra debe ser distinto de -1
    while(pos !=-1) {
            s = start;
            if (pos == 1) {
                if (start == last) {
                    //si solo hay un valor en la lista y lo eliminamos
                    //se vacia la lista y start y last es null
                    start = NULL;
                    last = NULL;
                    count--;
                    cout << "Lista vaciada " << endl;
                    return;
                }
                //eliminarRecursiv un elemento en primera posicion
                count--; //quitar uno al contador de elementos
                last->next = s->next;
                s->next->previous = last;
                start = s->next;
                cout << "Elemento eliminado" << endl;
                //return;       *****
            } else {
                for (i = 0; i < pos - 1; i++) {
                    s = s->next;
                    ptr = s->previous;
                }
                ptr->next = s->next;
                s->next->previous = ptr;
                if (pos == count) {
                    last = ptr;
                }
                count--;
                cout << "Elemento eliminado" << endl;
            }

       // }
        //se busca de nuevo y si se encuentra otra vez se elimina
        pos = buscarNodo(numBusq);
    }
   /* if(pos != -1){
        eliminarRecursiv(numBusq);
    }*/
}


int buscarNodo(float numBusq) {
    nod *busq;
    busq = start;
    bool encontrado = false;
    int position = -1;
    if(start!=NULL){
        do{
            if(busq->info == numBusq){
                position++;
                //cout << "Numero encontrado en posicion " <<position <<endl;
                encontrado = true;
            }else position++;
            busq = busq->next;
        }while (busq!=start && encontrado!= true && busq!=NULL);
        if(!encontrado){
           // cout <<"Nodo no encontrado" <<endl;
            position = -1;
        }
    }else {cout <<"Lista vacia" <<endl;
    position = -1;}

    return position;
}

void ordenada() {
    //primero hay que comparar el valor del inicio con el siguiente
    float num = start->info;
    bool ordenada = false;
    struct nod *s;
    if (start == last && start == NULL) {
        cout<<"The List is empty, nothing to display"<<endl;
    }
    s = start;
    for (i = 0;i < count;i++) {
        if(num <= s->info){
           ordenada = true;
            num = s->info;
            s = s->next;
        }else{
                ordenada=false;
            }
        }

    if(ordenada) cout<<"Lista ordenada"<<endl;
    else cout<<"Lista desordenada"<<endl;

}

void mayor() {
    float mayo = start->info;
    int cont = 0;
    struct nod *s;
    if (start == last && start == NULL) {
        cout<<"The List is empty, nothing to display"<<endl;
        return;
    }
    s = start;
    for (i = 0;i < count;i++) {
        if( s->info > mayo) {
            mayo = s->info;
            cont = 1;
        } else if (mayo == s-> info){
            cont++;
        }
        s = s->next;
    }
    cout<<"El mayor valor es " <<mayo <<" y se repite " <<cont <<endl;
}

void sum_todos() {
    float sum = 0;
    struct nod *s;
    if (start == last && start == NULL) {
        cout<<"The List is empty, nothing to display"<<endl;
        return;
    }
    s = start;
    for (i = 0;i < count;i++) {
       // cout<<s->info<<"<->";
        sum = s->info + sum;
        s = s->next;
    }
    cout<<sum<<endl;
}

void invertir() {
    if (start == last && start == NULL) {
        cout<<"Lista vacia"<<endl;
        return;
    }
    struct nod *p1, *p2;
    p1 = start;
    p2 = p1->next;
    p1->next = NULL;
    p1->previous= p2;
    while (p2 != start) {
        p2->previous = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p2->previous;
    }
    last = start;
    start = p1;
    cout<<"Lista invertida"<<endl;
}

void insert_pos() {
    float v, pos;
    cout<<endl<<"Introduzca el elemento a insertar: ";
    cin>>v;
    cout<<endl<<"Introduzca en que posicion quiere introducrilo: ";
    cin>>pos;
    struct nod *t, *s, *ptr;
    t = getNod(v);
    if (start == last && start == NULL) {
        if (pos == 1) {
            start = last = t;
            start->next = last->next = NULL;
            start->previous = last->previous = NULL;
        } else {
            cout<<"Fuera de rango"<<endl;
            count--;
            return;
        }
    } else {
        if (count < pos) {
            cout<<"Fuera de rango"<<endl;
            count--;
            return;
        }
        s = start;
        for (i = 1;i <= count;i++) {
            ptr = s;
            s = s->next;
            if (i == pos - 1) {
                ptr->next = t;
                t->previous= ptr;
                t->next= s;
                s->previous = t;
                cout<<"Element inserted"<<endl;
                break;
            }
        }
    }
}

void insert_final() {
    float v;
    cout<<endl<<"Introduzca el elemento a insertar al final: ";
    cin>>v;
    struct nod *t;
    t = getNod(v);
    if (start == last && start == NULL) {
        cout<<"Elemento insertado en la lista vacia"<<endl;
        start = last = t;
        start->next= last->next = NULL;
        start->previous = last->previous= NULL;
    } else {
        last->next= t;
        t->previous= last;
        last = t;
        start->previous = last;
        last->next= start;
    }

}

void insert_principio() {
    float v;
    cout<<endl<<"Introduzca el elemento a insertar al principio: ";
    cin>>v;
    nod *t = getNod(v);
    if (start == last && start == NULL) {
        cout<<"Elemento insertado en la lista vacia"<<endl;
        start = last = t;
        start->next = last->next = NULL;
        start->previous = last->previous = NULL;
    } else {
        t->next = start;
        start->previous = t;
        start = t;
        start->previous = last;
        last->next = start;
        cout<<"Elemento insertado"<<endl;
    }
}

nod *getNod(float v) {
    count++;
    struct nod *t;
    t = new(struct nod);
    t->info = v;
    t->next = NULL;
    t->previous = NULL;
    return t;
}

void mostrar_lista() {
    struct nod *s;
    if (start == last && start == NULL) {
        cout<<"Lista vacia"<<endl;
        return;
    }
    s = start;
    for (i = 0;i < count-1;i++) {
        cout<<s->info<<"<->";
        s = s->next;
    }
    cout<<s->info<<endl;
}


