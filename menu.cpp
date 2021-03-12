#include <iostream>
#include <stdio.h>  
#include <string.h>
#include <conio.h>

using namespace std;

const char *nombe_archivo = "archivo.dat";

struct Empleado{
	int codigo;
	char nombre[50];
	char apellido[50];
	char puesto[50];
	int sueldo;
	int bono;
	int sueldo_total;
	
};

void ingresar_empleado();
void abrir_empleado();
void modificar_empleado();
void buscar_codigo();
void eliminar_empleado();

int main()
{
    int opcion;
    
        system("cls");        
        
        cout << "\n\nMenu de Opciones" << endl;
        
        cout << "1. Abrir Empleados" << endl;
        cout << "2. Ingresar Empleado" << endl;
        cout << "3. Modificar Empleado" << endl;
        cout << "4. Buscar Empleado" << endl;
        cout << "5. Eliminar" << endl;
        cout << "6. SALIR" << endl;
        
        cout << "\nIngrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                
                system("cls");
                abrir_empleado();
                break;
                
            case 2:
                
                system("cls");
                ingresar_empleado();
                break;
                
            case 3:
                
                system("cls");
				modificar_empleado();  
                break;
                
            case 4:
                
                system("cls");
				buscar_codigo();  
                break;
			    
            case 5:
                
                system("cls");
				cout<<"Eliminar";    
                break;
                
            case 6:
                
                system("cls");
				return 0;
				   
        }     
           
    return 0;
}

void buscar_codigo(){
	
	FILE* archivo = fopen(nombe_archivo, "rb");
	
	int indice=0,pos=0,cod=0;
	cout<<"BUSCAR CODIGO: ";
	cin>>cod;
	Empleado empleado;
	
	fread ( &empleado, sizeof(Empleado), 1, archivo );
		
		do{
			
			if (empleado.codigo == cod){
			pos = indice;
			}
	
		fread ( &empleado, sizeof(Empleado), 1, archivo );
		indice += 1;
		} while (feof( archivo ) == 0);
		
	cout<<"------------------ "<<pos<<" ------------------"<<endl;
	fseek ( archivo,pos * sizeof(Empleado), SEEK_SET );

    fread ( &empleado, sizeof( Empleado ), 1, archivo );

    	cout << "Codigo: " << empleado.codigo << endl;
        cout << "Nombre: " << empleado.nombre << endl;
        cout << "Apellido: " << empleado.apellido << endl;
        cout << "Puesto: " <<empleado.puesto << endl;
        cout << "Sueldo Base: " << empleado.sueldo << endl;
        cout << "Bonificacion: " << empleado.bono << endl;
        cout << endl;
	
	fclose(archivo);
	_getch();
	main();
}

void buscar_indice(){
	FILE* archivo = fopen(nombe_archivo, "rb");
	
	int pos=0;
	cout<<"Que registro desea ver: ";
	cin>>pos;
	cout<<"------------------ "<<pos<<" ------------------"<<endl;
	fseek ( archivo,pos * sizeof(Empleado), SEEK_SET );
	
	Empleado empleado;
	
    fread ( &empleado, sizeof( Empleado ), 1, archivo );

    	cout << "Codigo: " << empleado.codigo << endl;
        cout << "Nombre: " << empleado.nombre << endl;
        cout << "Apellido: " << empleado.apellido << endl;
        cout << "Puesto: " <<empleado.puesto << endl;
        cout << "Sueldo Base: " << empleado.sueldo << endl;
        cout << "Bonificacion: " << empleado.bono << endl;
        cout << endl;
	
	fclose(archivo);

	
}

void eliminar_empleado(){
	
}

void abrir_empleado(){

	system("cls");
	FILE* archivo = fopen(nombe_archivo, "rb");
	if(!archivo) {
		archivo = fopen(nombe_archivo, "w+b");
	}
	Empleado empleado;
	int registro=0;
	fread ( &empleado, sizeof(Empleado), 1, archivo );
	cout<<"____________________________________________________________________"<<endl;
	cout << "id" <<"|"<< "CODIGO" <<"|"<< "NOMBRE"<<" "<<"APELLIDO"<<"	"<<"PUESTO"<<" "<<"SUELDO"<<"| "<<"BONO"<<"| "<<"SUELDO TOTAL"<<endl;	
		do{
		cout<<"______________________________________________________________________________"<<endl;
		cout << registro <<" |  "<< empleado.codigo <<" | "<< empleado.nombre<<" "<<empleado.apellido<<" "<<empleado.puesto<<" "<<empleado.sueldo<<" | "<<empleado.bono<<" | "<<empleado.sueldo_total<<endl;
        
        
		fread ( &empleado, sizeof(Empleado), 1, archivo );
		registro += 1;	
		} while (feof( archivo ) == 0);
		
    cout<<endl;    
		fclose(archivo);
		_getch();
		main();	
		
		
	}
	
	
	void ingresar_empleado(){
	
	char continuar;
	FILE* archivo = fopen(nombe_archivo, "ab"); // ab
	
	
		Empleado empleado;
		string nombre,apellido,puesto;
		do{
			fflush(stdin);
			
		cout<<"Ingrese el Codigo:";
		cin>>empleado.codigo;
        cin.ignore();
        
		cout<<"Ingrese el Nombre:";
		getline(cin,nombre);
    	strcpy(empleado.nombre, nombre.c_str()); 
			
		cout<<"Ingrese el Apellido:";
		getline(cin,apellido);
		strcpy(empleado.apellido, apellido.c_str()); 
		
		cout<<"Ingrese Puesto: ";
		getline(cin,puesto);
		strcpy(empleado.puesto, puesto.c_str());
		
		cout<<"ingrese Sueldo base: ";
		cin>>empleado.sueldo;
		cin.ignore();
		
		cout<<"Ingrese el Bonificacion:";
		cin>>empleado.bono;
		cin.ignore();
		
		empleado.sueldo_total=empleado.sueldo + empleado.bono;
		
		cin.ignore();
		
		fwrite( &empleado, sizeof(Empleado), 1, archivo );
		
		cout<<"Desea Agregar otro empleado s/n : ";
		cin>>continuar;
		} 
		while((continuar=='s') || (continuar=='S') );
		
	
	fclose(archivo);
	abrir_empleado();
	//buscar_indice();	
	//buscar_codigo();
}
void modificar_empleado(){
	
	FILE* archivo = fopen(nombe_archivo, "r+b");
	
		int id;
		string nombre,apellido, puesto;	
    	Empleado empleado;
    
		cout << "Ingrese el ID que desea Modificar: ";
    		cin >> id;
    		fseek ( archivo, id * sizeof(Empleado), SEEK_SET );  // esto es lo que permite modificar en la pocision
	
		cout<<"Ingrese el Codigo:";
		cin>>empleado.codigo;
        cin.ignore();
        
		cout<<"Ingrese el Nombre:";
		getline(cin,nombre);
    	strcpy(empleado.nombre, nombre.c_str()); 
			
		cout<<"Ingrese el Apellido:";
		getline(cin,apellido);
		strcpy(empleado.apellido, apellido.c_str()); 
		
		cout<<"Ingrese Puesto: ";
		getline(cin,puesto);
		strcpy(empleado.puesto, puesto.c_str());
		
		cout<<"ingrese Sueldo base: ";
		cin>>empleado.sueldo;
		cin.ignore();
		
		cout<<"Ingrese el Bonificacion:";
		cin>>empleado.bono;
		cin.ignore();
		
		empleado.sueldo_total=empleado.sueldo+empleado.bono;
		cin>>empleado.sueldo_total;
		cin.ignore();
		
		fwrite( &empleado, sizeof(Empleado), 1, archivo );
		
	fclose(archivo);
	abrir_empleado();
		system("PAUSE");
}
