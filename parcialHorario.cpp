#include <iostream>

using namespace std;

//Prototipo de la(s) función(es) a usar
void horario(); 
char* leerArchivoTexto(const char*);

int main(){

    char* contenido = leerArchivoTexto("archivo.txt"); //Nombre del archivo que será leido

    if (contenido != nullptr) {   //Manejo de error
        cout << "Contenido del archivo: " << endl << contenido << endl;
        delete[] contenido;
    }

    horario();
}

// Funcion que genera una matriz con una determinada cantidad de información reservada
void horario(){
    int **matrix;
    matrix=new int *[6];
    for(int i=0;i<6; i++){
        matrix[i]=new int[15];
    }
    for(int j=0;j<6;j++){
        for(int k=0;k<15;k++){
            *(*(matrix+j)+k)=0;
        }

    }
    bool finished=false;
    while(finished==false){
        for(int j=0;j<6;j++){
            for(int k=0;k<15;k++){
                if((*(*(matrix+j)+k))==0) cout<<" LIBRE ";
                else cout<<" OCUPADO ";
            }
            cout<<endl;
        }
        char fila, option; int columna;
        cout<<"Ingrese a para reservar una hora de su horario. "<<endl<<"Ingrese b para quitar un horario.  "<<endl<<"Ingrese una letra diferente para salir "<<endl;
        cin>>option;
        if(option!='a' && option!='b') break;
        cout<<"Ingrese el dia, lunes a sabado, solo la inicial y en mayuscula. "<<endl; cin>>fila;
        cout<<"Ingrese la columna 6-20 "<<endl; cin>>columna;
        switch (fila) {
        case 'L':{
            if(option=='a') *(*(matrix)+(columna-6))=1;
            else *(*(matrix)+(columna-6))=0;
            break;
        }
        case 'M':{
            if(option=='a') *(*(matrix+1)+(columna-6))=1;
            else *(*(matrix+1)+(columna-6))=0;
            break;
        }
        case 'W':{
            if(option=='a') *(*(matrix+2)+(columna-6))=1;
            else *(*(matrix+2)+(columna-6))=0;
            break;
        }
        case 'J':{
            if(option=='a') *(*(matrix+3)+(columna-6))=1;
            else *(*(matrix+3)+(columna-6))=0;
            break;
        }
        case 'V':{
            if(option=='a') *(*(matrix+4)+(columna-6))=1;
            else *(*(matrix+4)+(columna-6))=0;
            break;
        }
        case 'S':{
            if(option=='a') *(*(matrix+5)+(columna-6))=1;
            else *(*(matrix+5)+(columna-6))=0;
            break;
        }
        default:{
            cout<<"Los valores ingresados son invalidos "<<endl;
        }
        }
    }
    delete [] matrix;
}


//Funcion para leer archivos .txt
char* leerArchivoTexto(const char* nombreArchivo) {
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


