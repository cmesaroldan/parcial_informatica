#include <iostream>
#include <fstream>

using namespace std;



//Definicion de variables:
char dia;
int hora = 0,opc = 0;
char mat[6][15];
int filas,columnas;

//prototipo de funciones:
void menu();
void mostrarMatriz(char[5][15],int,int);
char modificarHorario(char[5][15]);
void LeerBase();  //opcion 3 para mirar los horarios e interactuar en el archivo
char* leerArchivo(const char*); //funcion para leer la base de datos.
void cortarCadena(const char* codigo); //Toma la información relacionada al código de la materia
char* intACharPuntero(int num); //función, toma un entero y lo convierte en entero
int horas_ti(int a); //Retorna numero de horas asistidas y no asistidas
int strcmp(const char* cadena1, const char* cadena2); //Prototipo de funcion comparadora
char Matricular(char[5][15], int, int);


int main()
{   char mat[6][15];
    char dias[]={'L','M','W','J','V','S'};
    for(int i=0; i<6; i++){
        for (int j = 0; j < 15; j++)
            mat[i][j] =  '-';
    }
    //  cout<<"  ";
    menu();

    return 0;

}
void menu(){
    int opt=1;
    cout<<"     ....Bienvenido a su modificador de horario.....      "<<endl<<endl;
    int hdocente = 0, hindividual = 0;
    while(opt !=0){
        int opt;

        cout<<"Ingrese su opcion elegida "<<endl;
        cout<<"1.Visualizar su horario "<<endl;
        cout<<"2.Registrar o borrar un horario"<<endl;
        cout<<"3.Mostrar opciones de horario "<<endl;
        cout<<"4.Salir "<<endl;
        cin>>opt;

        switch(opt){
        case(1):{
            mostrarMatriz(mat,4, 15);
            break;
        }

        case(2):{
            modificarHorario(mat);
            break;
        }
        case(3):{
            LeerBase();

            break;
        }
        case(4):{
            exit(0);
            break;
        }
        default:{
            cout<<"XXXXX.....error al ingresar datos.....XXXXX"<<endl;
            exit(0);
            break;
        }

        }
    }
}
void mostrarMatriz(char mat[][15],int filas, int columnas){

    char dias[]={'L','M','W','J','V','S'};
    for(int i=0; i<6 ; i++){
        for(int j=0; j<15; j++)
            cout<<mat[i][j];
        cout<<endl;
    }
    cout<<"  ";

    cout<<"  ";

    for(int j = 0; j < 15; j++){
        cout<<j+6<<'\t';
    }
    cout<<endl;


    for(int i = 0; i < 6; i++){
        cout <<dias[i]<<" ";
        for(int j = 0; j < 15; j++){

            cout<<mat[i][j] <<'\t';
        }
        cout<<endl;
    }
}

char modificarHorario(char[][15]){
    /*
      for(int i=0; i<6; i++){
         for (int j = 0; j < 15; j++)
                 mat[i][j] =  '-';
         }
    cout<<"  ";
    */
    char dias[]={'L','M','W','J','V','S'};
    bool funcionando = true;
    char op;
    while(funcionando == true){
        cout<<endl<<endl;

        cout<<"  ";

        for(int j = 0; j < 15; j++){
            cout<<j+6<<'\t';
        }
        cout<<endl;


        for(int i = 0; i < 6; i++){
            cout <<dias[i]<<" ";
            for(int j = 0; j < 15; j++){

                cout<<mat[i][j] <<'\t';
            }
            cout<<endl;
        }

        cout<<"Ingrese a para reservar una hora de su horario. "<<endl<<"Ingrese b para quitar un horario."<<endl<<"Ingrese una letra diferente para salir "<<endl<<endl;
        cin>>op;
        if(op!='a' && op!='b') break;
        cout<<"Ingrese el dia, lunes a sabado, solo la inicial"<<endl; cin>>dia;
        cout<<"Ingrese la hora 6-20 "<<endl; cin>>hora;
        switch(dia){
        case 'l':{
            if(op=='a'){
                //system("pause");
                cout<<endl;
                mat[0][hora-6] = 'X';
            }
            else{
                mat[0][hora-6] = ' ';
            }
            break;
        }

        case 'm':{
            if(op=='a'){
                //system("pause");
                cout<<endl;
                mat[1][hora-6] = 'X';
            }
            else {
                mat[1][hora-6] = ' ';
            }
            break;
        }

        case 'w':{
            if(op=='a'){
                // system("pause");
                cout<<endl;
                mat[2][hora-6] = 'X';
            }
            else {
                mat[2][hora-6] = ' ';
            }
            break;
        }

        case 'j':{
            if(op=='a'){
                // system("pause");
                cout<<endl;
                mat[3][hora-6] = 'X';
            }
            else {
                mat[3][hora-6] = ' ';
            }
            break;
        }

        case 'v':{
            if(op=='a'){
                // system("pause");
                cout<<endl;
                mat[4][hora-6] = 'X';
            }
            else {
                mat[4][hora-6] = ' ';
            }
            break;
        }

        case 's':{
            if(op=='a'){

                //system("pause");
                cout<<endl;
                mat[5][hora-6] = 'X';
            }
            else {
                mat[5][hora-6] = ' ';
            }
            break;
        }
        default:{
            cout<<" xxxx...Datos incorrectos...xxxxx";
            break;
        }
            funcionando = false;
        }

    }
    return mat[5][14];
}

void LeerBase(){

    int horasTi = 0;
    int userCode = 0;
    int opcion = 0;



    cout<<endl<<endl;
    cout<<"Matricula completada";

    cout<<".....Mostrando los horarios por semestre.....";
    char* contenido = leerArchivo("archivo.txt");
    if (contenido != nullptr) {
        cout << endl << contenido << endl;
        delete[] contenido;
    }

    cout<<"Ingrese 1. si desea abrir ingresar un codigo de una materia: "<<endl;
    cout<<"Ingrese otro numero si no desea matricular: "<<endl;
    cin>>opcion;
    if(opcion == 1){
        cout<<"Ingrese el codigo de la materia"<<endl;
        cin >> userCode;
        cout<<"Usted ha eledigo la materia: ";
        char* charPtr = intACharPuntero(userCode);
        cortarCadena(charPtr);
        horasTi = horas_ti(userCode);
    }
}

char* leerArchivo(const char* nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {   //si no se puede abrir el archivo.
        cerr << "Error al abrir el archivo " << nombreArchivo << endl;
        return nullptr;
    }

    //obtenemos el tamaño del archivo:
    archivo.seekg(0, ios::end);
    int tamanoArchivo = archivo.tellg();
    archivo.seekg(0, ios::beg);


    char* contenido = new char[tamanoArchivo + 1];  //creamos un puntero de char y reservamos la memoria dependiendo del tamaño del archivo obtuvimos con las lineas anteriores.
    archivo.read(contenido, tamanoArchivo);   //leemos el archivo.
    contenido[tamanoArchivo] = '\0';   //limpiamos la variable del contenido del archivo.

    archivo.close(); //cerramos el archivo

    return contenido;
}

void cortarCadena(const char* codigo){

    const char* rutaArchivo = "archivo.txt";
    ifstream archivo(rutaArchivo);

    if(archivo.is_open()) {
        char caracter;

        while(archivo.get(caracter)) {
            //cout << caracter;
            if(caracter == '\n'){ // verificar si el caracter es una coma

                char cadena[8]; // array de caracteres para almacenar los siguientes 7 caracteres
                char materia[60]={0};
                int indice = 0;

                for(int i = 0; i < 7; i++){
                    if (archivo.get(caracter)) {
                        cadena[indice] = caracter; // almacenar el caracter en el array
                        indice++; // aumentar el índice para el siguiente caracter
                        //cout << cadena[i]<<endl;
                    }

                    else{
                        break;
                    }
                }
                cadena[indice] = '\0'; // agregar un carácter nulo al final del array
                if(strcmp(codigo,cadena)==0){
                    int indice = 0;
                    for(int i = 0; i < 60; i++){
                        if(archivo.get(caracter)){
                            if(caracter=='\n'){
                                break;
                            }

                            else{
                                materia[indice] = caracter; // almacenar el caracter en el array
                                indice++; // aumentar el índice para el siguiente caracter

                            }
                        }

                        else{
                            break;
                        }
                    }
                    cout << materia << endl;


                }
            }//if salto de linea

        }//while
        archivo.close();
    }//if open

    else{
        cout << "Error al abrir el archivo." << endl;
    }
}


char* intACharPuntero(int num) {
    int temp = num, digits = 0;
    while(temp > 0) {
        temp /= 10;
        digits++;
    }
    char* charPtr = new char[digits + 1];
    for(int i = digits - 1; i >= 0; i--) {
        charPtr[i] = num % 10 + '0';
        num /= 10;
    }
    charPtr[digits] = '\0';
    return charPtr;
}

int horas_ti(int a){
    int horasTi = 0, hdocente = 0, hindividual = 0;
    if(a == 2555131 || a == 2536101 || a == 2555101 ||a == 2555121|| a == 2555231 ||a == 2536201 ||a == 2555221 ||a == 2538201 ||a == 2536302 ||a == 2555331 ||a == 2598531 ||a == 2599431 ||a == 2555131 ||a == 2517362){
        hdocente = 4;
        hindividual = ((3*48) / 16) - hdocente;
        int htotal = hdocente + hindividual;
        cout << endl << endl <<"Por lo tanto usted debe matricular "<<hdocente <<" horas de estudio con docente asistido y " << hindividual <<" horas de estudio individual"<<endl;
        cout<<"total de horas es: "<<htotal;
        Matricular(mat, 4, hindividual);

    }else if(a == 2517362|| a == 2599421||a == 2555121||a == 2537101 || a == 2538101 || a == 2538201 || a == 2539101 ||a == 2538301){
        hdocente = 2;
        hindividual = ((1*48) / 16) - hdocente;
        int htotal = hdocente + hindividual;
        cout << endl << endl <<"Por lo tanto usted debe matricular "<<hdocente <<" horas de estudio con docente asistido y " << hindividual <<" horas de estudio individual"<<endl;
        cout<<"total de horas es: "<<htotal;
        Matricular(mat,2,hindividual);

    }else if(a == 2598511|| a == 2598521||a == 2598532){


        hdocente = 7;
        hindividual = ((4*48) / 16) - hdocente;
        int htotal = hdocente + hindividual;
        cout << endl << endl <<"Por lo tanto usted debe matricular "<<hdocente <<" horas de estudio con docente asistido y " << hindividual <<" horas de estudio individual"<<endl;
        cout<<"total de horas es: "<<htotal;
        Matricular(mat,2,hindividual);
    }else{
        cout<<"No hay materias con este codigo"<<endl;
    }
    return horasTi;
}



int strcmp(const char* cadena1, const char* cadena2){
    int i = 0;
    while (cadena1[i]==cadena2[i] && cadena1[i]!='\0'){
        i++;
    }

    if (cadena1[i]>cadena2[i])
        return 1;

    else if (cadena1[i]<cadena2[i])
        return -1;

    else
        return 0;
}


char Matricular(char[5][15], int hdocente, int hindividual){

    int suma = hdocente + hindividual;

    for(int i = 0; i < suma; i++){
        modificarHorario(mat);
    }

}
