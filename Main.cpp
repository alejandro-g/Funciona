#include "Persona.h"
#include "Object.h"
#include "Employee.h"
#include "ADTList.h"
#include "VSArrayList.h"
#include <iostream>
#include <string>

using namespace std;

void menu();

int main(){
  ADTList* Employees = new VSArrayList();//creacion de la lista de Empleados
  cout << "La lista ha sido creada con exito!" << endl;
  int opcion = 0;
  do{
    menu();//se creo el metodo menu para no dejar todo en el main y para que se vea mas ordenado
    cin >> opcion;
    if(opcion == 1){//insercion de nuevo empleados en la lista recien creada
      string nombreEmpleado, int edadEmpleado, double salario;
      cout << "Por favor ingrese nombre del nuevo empleado: ";
      cin.ignore();//metodo perteneciente a cin para asi poder ignorar cualquier espacio cuando se ingrese el nombre del empleado
      getline(cin, nombreEmpleado);
      cout << endl;
      cout << "Por favor ingrese edad del empleado: ";
      cin >> edadEmpleado << endl;
      cout << "Cuaunto sera el salario de su nuevo empleado?: ";
      cin >> salario << endl;
      if(Employees->insert(new Employee(nombreEmpleado, edadEmpleado, salario), Employees->size())){//creacion del objeto empleado y tambien obtiene el size de la lista
        cout << "El Empleado ha sido agregado de forma Exitosa!" << endl;
      }else{
        cout << "No se ha podido agregar al empleado, operacion fallida!" << endl;
      }
    }//cierre de opcion 1
    if(opcion == 2){//listar a los empleados existentes
      cout << "Lista de los empleados exitentes: " << endl;
      if(!Employees->isEmpty()){//si la lista no esta vacia
        for (int i = 0; i < Employees->size(); i++) {
          cout << i << ")" << Employees->get(i)->toString() << endl;
        }
      }else{
        cout << "La lista se encuentra vacia por el momento" << endl;
      }
    }//cierre de  opcion 2
    if(opcion == 3){//remover empleados de la lista
      int position;
      cout << "Lista de empleados que estan en la lista: " << endl;
      if(!Employees->isEmpty())//si la lista no esta vacia
        for(int i = 0l i < Employees->size(); i++){
          cout << i << ")" << Employees->get(i)->toString() << endl;
        }
        cout << "Escoga la posicion del empleado que desea eliminar!";
        cin >> position << endl;
        if(position < Employees->size() && psition >= 0){
          //Employee* deletedEmployee = (Employee*)Employees->remove(position);
          cout << "El empleado ha sido eliminado Exitosamente!" << endl;
        }else{
          cout << "La posicion del empleado es inexsistente!" <<endl;
        }
    }//cierre opcion 3
    if(opcion == 4){//salario promedio de los empleados
      double promedio = 0, total = 0;
      if(!Employees->isEmpty()){//si la lista no esta vacia
        for (int i = 0; i < Employees->size(); i++) {
          promedio += Employees->get(i)->getSalario();
        }
        total = promedio/Employees->size();
        cout << "El promedio de los salarios de los empleados es de: Lps." << total << endl;
      }else{
        cout << "La lista se encuentra vacia por el momento" << endl;
      }
    }//cierre opcion 4
    if(opcion == 5){//revisar salario maximo de la lista de empleados
      double maximo = 0;
      if(!Employees->isEmpty()){//si la lista no esta vacia
        for (int i = 0; i < Employees->size(); i++) {
          if(dynamic_cast <Employee*>(Employees->get(i))->getSalario() > maximo){
            maximo = dynamic_cast <Employee*>(Employees->get(i))->getSalario();//le asigna el salario maximo al empleado que se encuentre en la posicion i
          }
        }
        cout << "El salario maximo entre todos los empleados es: Lps." << maximo << endl;
      }else{
        cout << "La lista se encuentra vacia por el momento" << endl;
      }
    }//cierre opcion 5
    if(opcion == 6){//revisar salario minimo entre toda la lista de empleados
      double minimo = 0;
      if(!Employees->isEmpty()){//si la lista no esta vacia
        for (int i = 0; i < Employees->size(); i++) {
          if(dynamic_cast<Employee*>(Employees->get(i))->getSalario() < minimo){
            minimo = dynamic_cast<Employee*>(Employees->get(i))->getSalario();
          }
        }
        cout << "El salario minimo entre todos los empleados es: Lps." << minimo << endl;
      }else{
        cout << "La lista se encuentra vacia por el momento" << endl;
      }
    }//cierre opcion 6
    if(opcion == 7){//dar aumento por inflacion
      double aumento = 0, nuevoSalario = 0;
      if(!Employees->isEmpty()){//si la lista no esta vacia
        cout << "Ingrese el porcentaje de inflacion: ";
        cin >> aumento;
        aumento = aumento / 100;//convertir de entero a porcentaje
        for (int i = 0; i < Employees->size(); i++) {
          nuevoSalario = dynamic_cast<Employee*>(Employees->get(i))->getSalario();//consigue el salario actual de el empleado
          nuevoSalario = nuevoSalario + (nuevoSalario*aumento);//consigue el salario actual del empleado y se lo suma al aumento que tuvo
          dynamic_cast <Employee*>(Employees->get(i))->setSalario(nuevoSalario);//le asigna el nuevo salario al empleado
        }
        cout << "El aumento ha sido proporcionado!" << endl;
      }else{
        cout << "La lista se encuentra vacia por el momento" << endl;
      }
    }//cierre opcion 7
    if(opcion == 8){//opcion para salirse de la simulacion
      cout << "Disfrute su nuevo puesto como gerente! Esperamos vuelva pronto!" << endl;
    }//cierre opcion 8
  }while(opcion != 8 && opcion > 0)//fin do-while
}

void menu(){
  int opcion = 0;
  cout << "Bienvenido a su nuevo puesto como gerente! Esperamos todo cumpla con sus requisitos!" << endl;
  cout << "Opcion 1. Ingresar nuevo empleado" << endl;
  cout << "Opcion 2. Listar empleados" << endl;
  cout << "Opcion 3. Remover Empleados" << endl;
  cout << "Opcion 4. Calcular salario promedio" << endl;
  cout << "Opcion 5. Ver salario maximo" << endl;
  cout << "Opcion 6. Ver salario minimo" << endl;
  cout << "Opcion 7. Dar incremento por inflacion" << endl;
  cout << "Opcion 8. Salir de simulacion" << endl;
  cout << "Por favor ingrese una opcion: " << endl;
}
