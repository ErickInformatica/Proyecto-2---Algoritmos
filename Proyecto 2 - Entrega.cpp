//Proprama que almacena y lee un documento no binario para almacenar Alumnos
////Autor: Erick Bran
//Fecha: 15/10/2021
#include <iostream>
#include <string.h>
#include <fstream>
#include "CppConsoleTable.hpp"
#include <stdlib.h>
using namespace std;

//VARIABLES GLOBALES
using ConsoleTable = samilton::ConsoleTable;
ConsoleTable tableMostrar(1, 1, samilton::Alignment::centre);
ConsoleTable tableModificar(1, 1, samilton::Alignment::centre);
ConsoleTable tableListar(1, 1, samilton::Alignment::centre);
int posicionTablaLista = 1;


typedef struct {
	int idAlumno = 0;
    char Nombre[50] = "";
    char Carne[50] = "";
    char Correo[50] = "";
    char Seccion[50] = "";
    int Ciclo = 0;
    char Estado[1] = "";
    float Promedio = 0;    
} Alumno;

//MOSTRAR TABLAS
void mostrar(Alumno a, int pos){
	tableMostrar[pos][0] = pos;
	tableMostrar[pos][1] = a.Nombre;
	tableMostrar[pos][2] = a.Carne;
	tableMostrar[pos][3] = a.Correo;
	tableMostrar[pos][4] = a.Seccion;
	tableMostrar[pos][5] = a.Ciclo;
	tableMostrar[pos][6] = a.Estado;
	tableMostrar[pos][7] = a.Promedio;	
}

void mostrarListar(Alumno a, int pos){
	tableListar[posicionTablaLista][0] = pos;
	tableListar[posicionTablaLista][1] = a.Nombre;
	tableListar[posicionTablaLista][2] = a.Carne;
	tableListar[posicionTablaLista][3] = a.Correo;
	tableListar[posicionTablaLista][4] = a.Seccion;
	tableListar[posicionTablaLista][5] = a.Ciclo;
	tableListar[posicionTablaLista][6] = a.Estado;
	tableListar[posicionTablaLista][7] = a.Promedio;	
	posicionTablaLista++;
}

void mostrarModificar(Alumno a, int pos){
	tableModificar[0][0] = "NO.";
	tableModificar[0][1] = "NOMBRE";
	tableModificar[0][2] = "CARNE";
	tableModificar[0][3] = "CORREO";
	tableModificar[0][4] = "SECCION";
	tableModificar[0][5] = "CICLO";
	tableModificar[0][6] = "ESTADO";
	tableModificar[0][7] = "PROMEDIO";		    
	tableModificar[1][0] = pos;
	tableModificar[1][1] = a.Nombre;
	tableModificar[1][2] = a.Carne;
	tableModificar[1][3] = a.Correo;
	tableModificar[1][4] = a.Seccion;
	tableModificar[1][5] = a.Ciclo;
	tableModificar[1][6] = a.Estado;
	tableModificar[1][7] = a.Promedio;
	cout << tableModificar;
}
//CREA ARCHIVO BINARIO SI NO EXISTE
void crearIfExiste(){
	ofstream archivoB;
	archivoB.open("pruebas.dat", ios::out | ios::app | ios::binary);
	archivoB.close();
}

//Obtener un Alumno en especifico
Alumno obtenerAlumno(int id){
	fstream archivoB ("pruebas.dat", ios::out | ios::in |  ios::binary);
	Alumno findAlum;
	if(archivoB.is_open()){
		archivoB.seekg((id-1)*sizeof(Alumno));
		archivoB.read((char*)&findAlum, sizeof(Alumno));
		archivoB.close();
	}
	return findAlum;
}

//Agregar un Alumno
void agregarStructAlumno(){
	
	Alumno alm;
	ofstream archivoB;
	
	archivoB.open("pruebas.dat", ios::out | ios::in |  ios::binary);
	if(archivoB.fail()){
		cout << "El Archivo Binario no se pudo abrir.";
		exit(1);
	}
	
	cout << "Ingrese Id del Alumno" << endl;
	cin >> alm.idAlumno;
	cout << "Ingrese Nombre del Alumno" << endl;
	cin.ignore();
	cin >> alm.Nombre;
	cout << "Ingrese Carne del Alumno" << endl;
	cin >> alm.Carne;
	cout << "Ingrese Correo del Alumno" << endl;
	cin >> alm.Correo;
	cout << "Ingrese Seccion del Alumno" << endl;
	cin >> alm.Seccion;
	cout << "Ingrese Ciclo del Alumno" << endl;
	cin >> alm.Ciclo;
	
	EstadoVer:
	cout << "Ingrese Estado del Alumno. Solo puede ser A (Aprobado) o R (Reprobado)" << endl;
	cin >> alm.Estado;
	if((strcmp(alm.Estado, "A") != 0) && (strcmp(alm.Estado, "R") != 0)){
		cout << "Solo puede ser A (Aprobado) o R (Reprobado). Ingrese nuevamente el Estado correctamente." << endl;
		goto EstadoVer; 
	}
	cout << "Ingrese Promedio del Alumno" << endl;
	cin >> alm.Promedio;
	
	Alumno veriAlumno = obtenerAlumno(alm.idAlumno);
	
	if(veriAlumno.idAlumno != 0){
		cout << "Id de Alumno, ya existente." << endl;
	}else{
		archivoB.seekp((alm.idAlumno-1)*sizeof(Alumno));
		archivoB.write((char*)&alm, sizeof(Alumno));
		archivoB.close();
	}	
}


//BUSCAR ALUMNO EN DOCUMENTO BINARIO
void buscarAlumnosDocumento(){
	ifstream archivoB("pruebas.dat", ios::out | ios::in | ios::binary);
	
	if(archivoB.fail()){
		cout << "El Archivo Binario no se pudo abrir.";
		exit(1);
	}
	
	Alumno al;
	archivoB.read((char*)&al, sizeof(Alumno));

	
		//CABECERA TABLA
	tableListar[0][0] = "NO.";
	tableListar[0][1] = "NOMBRE";
	tableListar[0][2] = "CARNE";
	tableListar[0][3] = "CORREO";
	tableListar[0][4] = "SECCION";
	tableListar[0][5] = "CICLO";
	tableListar[0][6] = "ESTADO";
	tableListar[0][7] = "PROMEDIO";
	
	//Variables de busqueda
	char busqueda[50] ;
	int opcionBusqueda = 0;	
	
	//Decidir porque se desea buscar
	cout << "Porque desea buscar?" << endl;
	cout << "--------- 1. Nombre ---------" << endl;
	cout << "--------- 2. Carne ----------" << endl;
	cout << "--------- 3. Correo ---------" << endl;
	cout << "--------- 4. Seccion --------" << endl;
	cout << "--------- 5. Ciclo ---------" << endl;
	cout << "--------- 6. Estado ---------" << endl;
	cout << "--------- 7. Promedio -------" << endl;
	cin >> opcionBusqueda;
	
	switch(opcionBusqueda){
		case 1:
			cout << "Cual es el nombre que desea buscar?" <<endl;
			cin >> busqueda;
			while(!archivoB.eof()){		
				if(strcmp(al.Nombre, busqueda)== 0){
					mostrarListar(al, al.idAlumno);
				}	
				archivoB.read((char*)&al, sizeof(Alumno));
			}
			cout << tableListar;
		break;
	
		case 2:
			cout << "Cual es el Carne que desea buscar?" <<endl;
			cin >> busqueda;
			while(!archivoB.eof()){		
				if(strcmp(al.Carne, busqueda)== 0){
					mostrarListar(al, al.idAlumno);
				}	
				archivoB.read((char*)&al, sizeof(Alumno));
			}
			cout << tableListar;
		break;
			
		case 3:
			cout << "Cual es el Correo que desea buscar?" <<endl;
			cin >> busqueda;
			while(!archivoB.eof()){		
				if(strcmp(al.Correo, busqueda)== 0){
					mostrarListar(al, al.idAlumno);
				}	
				archivoB.read((char*)&al, sizeof(Alumno));
			}
			cout << tableListar;
		break;
		case 4:
			cout << "Cual es el Seccion que desea buscar?" <<endl;
			cin >> busqueda;
			while(!archivoB.eof()){		
				if(strcmp(al.Seccion, busqueda)== 0){
					mostrarListar(al, al.idAlumno);
				}	
				archivoB.read((char*)&al, sizeof(Alumno));
			}
			cout << tableListar;
		break;
	
		case 5:
			int busquedaint;
			cout << "Cual es el Ciclo que desea buscar?" <<endl;
			cin >> busquedaint;
			while(!archivoB.eof()){		
				if(al.Ciclo == busquedaint){
					mostrarListar(al, al.idAlumno);
				}	
				archivoB.read((char*)&al, sizeof(Alumno));
			}
			cout << tableListar;
		break;
			
		case 6:
			cout << "Cual es el Estado que desea buscar?" <<endl;
			cin >> busqueda;
			while(!archivoB.eof()){		
				if(strcmp(al.Estado, busqueda)== 0){
					mostrarListar(al, al.idAlumno);
				}	
				archivoB.read((char*)&al, sizeof(Alumno));
			}
			cout << tableListar;
		break;
		
		case 7:
			float busquedaFloat;
			cout << "Cual es el Promedio que desea buscar?" <<endl;
			cin >> busquedaFloat;
			while(!archivoB.eof()){		
				if(al.Promedio == busquedaFloat){
					mostrarListar(al, al.idAlumno);
				}	
				archivoB.read((char*)&al, sizeof(Alumno));
			}
			cout << tableListar;
		break;
		default:
			cout << "Debe seleccionar una opcion correcta." << endl;	
	}	
	archivoB.close();	
	posicionTablaLista = 1;
	
//	char opcionRegresar;
//	cout << "Desea regresar al menu a realizar otra operacion? y/n";
//	cin >> opcionRegresar;
//	if(opcionRegresar == "y"){
//		goto menuGT;
//	}
}

//RECORRER DOCUMENTO BINARIO Y ALMACENARLO EN STRUCT PARA LISTAR
void recorrerAlumnosDocumento(){
	ifstream archivoB("pruebas.dat", ios::out | ios::in | ios::binary);
	
	if(archivoB.fail()){
		cout << "El Archivo Binario no se pudo abrir.";
		exit(1);
	}
	
	Alumno al;
	archivoB.read((char*)&al, sizeof(Alumno));
	
	//CABECERA TABLA
	tableMostrar[0][0] = "NO.";
	tableMostrar[0][1] = "NOMBRE";
	tableMostrar[0][2] = "CARNE";
	tableMostrar[0][3] = "CORREO";
	tableMostrar[0][4] = "SECCION";
	tableMostrar[0][5] = "CICLO";
	tableMostrar[0][6] = "ESTADO";
	tableMostrar[0][7] = "PROMEDIO";
	
	int pos = 1;
	while(!archivoB.eof()){
		mostrar(al, pos);	
		archivoB.read((char*)&al, sizeof(Alumno));
		pos++;
	}
	archivoB.close();
	cout << tableMostrar;
}

//MODIFICAR ALUMNO EN ESPECIFICO POR ID
void editarDatoAlumnoStruct(){
	int idBusqueda;
	int datoModificar;
	cout << "Ingrese el Identificador (id) del Alumno que desea buscar: " << endl;
	cin >> idBusqueda;
	Alumno busquedaAlumno = obtenerAlumno(idBusqueda);
	cin.ignore();
	if(busquedaAlumno.idAlumno == 0){
		cout << "Ese usuario, no existe." << endl;
	} else{
		mostrarModificar(busquedaAlumno, idBusqueda);		
		cout << "Que desea modificar?" << endl;
		cout << "--------- 1. Nombre ---------" << endl;
		cout << "--------- 2. Carne ----------" << endl;
		cout << "--------- 3. Correo ---------" << endl;
		cout << "--------- 4. Seccion --------" << endl;
		cout << "--------- 5. Ciclo ---------" << endl;
		cout << "--------- 6. Estado ---------" << endl;
		cout << "--------- 7. Promedio -------" << endl;
		cin >> datoModificar;
		
		switch(datoModificar){
			case 1:
				cout << "El Nombre anterior es: " << busquedaAlumno.Nombre << ". Cual es el nuevo Nombre?" <<endl;
				cin >> busquedaAlumno.Nombre;
			break;
		
			case 2:
				cout << "El Carne anterior es: " << busquedaAlumno.Carne << ". Cual es el nuevo Carne?" <<endl;
				cin >> busquedaAlumno.Carne;
			break;
				
			case 3:
				cout << "El correo anterior es: " << busquedaAlumno.Correo << ". Cual es el nuevo correo?" <<endl;
				cin >> busquedaAlumno.Correo;
			break;
			case 4:
				cout << "El Seccion anterior es: " << busquedaAlumno.Seccion << ". Cual es el nuevo Seccion?" <<endl;
				cin >> busquedaAlumno.Seccion;
			break;
		
			case 5:
				cout << "El Ciclo anterior es: " << busquedaAlumno.Ciclo << ". Cual es el nuevo Ciclo?" <<endl;
				cin >> busquedaAlumno.Ciclo;
			break;
				
			case 6:
				cout << "El Estado anterior es: " << busquedaAlumno.Estado << ". Cual es el nuevo Estado?" <<endl;
				cin >> busquedaAlumno.Estado;
			break;
			
			case 7:
				cout << "El Promedio anterior es: " << busquedaAlumno.Promedio << ". Cual es el nuevo Promedio?" <<endl;
				cin >> busquedaAlumno.Promedio;
			break;
			default:
				cout << "Debe seleccionar una opcion correcta." << endl;
		}
		
		ofstream archivoB;
		archivoB.open("pruebas.dat", ios::out | ios::in |  ios::binary);
		if(archivoB.is_open()){
			archivoB.seekp((busquedaAlumno.idAlumno-1)*sizeof(Alumno));
			archivoB.write((char*)&busquedaAlumno, sizeof(Alumno));
			archivoB.close();
			mostrarModificar(busquedaAlumno, idBusqueda);
		}
	}
		

}


//INICIO MENU
int main(){	
	crearIfExiste();
	int numMenu;
	string continuaUsuario = "";	
	while(continuaUsuario != "n"){
		cout << "--------- Menu ---------" << endl;
		cout << "---1. Agregar Alumno----" << endl;
		cout << "---2. Buscar Alumnos-----" << endl;
		cout << "---3. Listar Alumnos-----" << endl;
		cout << "---4. Modificar Alumno--" << endl;
		cin >> numMenu;
		switch(numMenu){
			case 1:
				agregarStructAlumno();
				recorrerAlumnosDocumento();
				break;
			
			case 2:
				buscarAlumnosDocumento();
				break;
			case 3:
				recorrerAlumnosDocumento();
				break;
			case 4:
				editarDatoAlumnoStruct();
				break;
		}
		
		cout << "Desea continuar realizacion calculos? (s/n)" << endl;
		cin >> continuaUsuario;		
		system ("CLS");
			
	}

}




