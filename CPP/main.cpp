//
// Created by cubero2112 on 6/9/20.
//

#include "VSPtr.h"

int main() {


    VSPtr<int> ptr = VSPtr<int>::New();
/*    cout << "Direccion asignada para la variable 'ptr' tipo 'MiPuntero': " << &ptr << endl;
    cout << "Direccion en el heap hacia donde apunta la variable 'ptr' tipo 'MiPuntero': " << ptr.ptr << endl;
    cout << "El dato almacenado en el heap dentro de la direccion: " << ptr.ptr << " es: " << *(ptr.ptr) << endl << endl;

    cout << "Cambiando el dato almacenado dentro del heap por 10... " << endl;
    *(ptr.ptr) = 10;

    cout << "El dato almacenado en el heap dentro de la direccion: " << ptr.ptr << " es: " << *(ptr.ptr) << endl << endl;*/

    *ptr = 30;


    VSPtr<double> ptr2 = VSPtr<double >::New();


/*    cout << "Direccion asignada para la variable 'ptr2' tipo 'MiPuntero': " << &ptr2 << endl;
    cout << "Direccion en el heap hacia donde apunta la variable 'ptr' tipo 'MiPuntero': " << ptr2.ptr << endl;
    cout << "El dato almacenado en el heap dentro de la direccion: " << ptr2.ptr << " es: " << *(ptr2.ptr) << endl << endl;

    cout << "Cambiando el dato almacenado dentro del heap por 20... " << endl;

    *(ptr2.ptr) = 20;

    cout << "El dato almacenado en el heap dentro de la direccion: " << ptr2.ptr << " es: " << *(ptr2.ptr) << endl << endl;

    cout << "Cambiando el dato almacenado dentro del heap por 60... " << endl;
    ptr2.setVal(60);
    cout << "El dato almacenado en el heap dentro de la direccion: " << ptr2.ptr << " es: " << *(ptr2.ptr) << endl << endl;*/

    *ptr2 = 67;

    //cout << *ptr2 << endl;

    //ptr2 = 83;
    //cout << *ptr2 << endl;

    VSPtr<double > ptr3 = VSPtr<double>::New();
    VSPtr<double > ptr4 = VSPtr<double>::New();

    //Por ahora, hace que ocurra un "error" cuando se libera dos veces la misma direccion de memoria
    ptr3 = ptr2;

    ptr4 = ptr3;

    VSPtr<double > ptr5 = VSPtr<double>::New();
    *ptr5 = 99;

    ptr3 = ptr5;



    //double num = &ptr2;
    //cout << "Numero: " << num << endl;


    return 0;
}
