#include <iostream>
#include <fstream>

using namespace std;

//prototipo de funciones
void horario(); //Reserva el espacio en memoria para una matriz
char* leerArchivoTexto(const char*); // Tomar el archivo guarda el archivo .txt y lo asigana a una variable
int strcmp(const char* cadena1, const char* cadena2);
void cortarCadena(const char* codigo);

int main() {

    char* contenido = leerArchivoTexto("archivo.txt");
    if (contenido != nullptr) {
        //cout << contenido << endl;
        delete[] contenido;
    }


    char codigo[] = "2538101";
    cortarCadena(codigo);

    //horario();

    return 0;
}

void horario(){
    //asignamos memoria dinamica para las 6 filas (dias) y 15 columnas (horas)
    int **matrix;
    matrix = new int *[6];
    for(int i=0;i<6; i++){
        matrix[i]=new int[15];
    }
    //las inicializamos en cero para que no haya basura y para que todas esten en "LIBRE".
    for(int j=0;j<6;j++){
        for(int k=0;k<15;k++){
            *(*(matrix+j)+k)=0;
        }

    }
    bool finished=false; //ponemos una bandera.
    while(finished==false){
        for(int j=0;j<6;j++){
            for(int k=0;k<15;k++){
                if((*(*(matrix+j)+k))==0) cout<<" LIBRE ";  //es como tener matriz[j][k] y empezaramos a pasar de posiciones.
                else cout<<" OCUPA ";  //para cuando esta matriz es = 1, que es cuando esta ocupada.
            }
            cout<<endl;
        }
        char fila, option; int columna;
        cout<<"Ingrese a para reservar una hora de su horario. "<<endl<<"Ingrese b para quitar un horario.  "<<endl<<"Ingrese una letra diferente para salir "<<endl;
        cin>>option;
        if(option!='a' && option!='b') break;
        cout<<"Ingrese el dia, lunes a sabado, solo la inicial y en mayuscula. EJM: martes = M... "<<endl; cin>>fila;
        cout<<"Ingrese la columna 6-20 "<<endl; cin>>columna;
        switch (fila) {
        case 'L':{
            if(option=='a') *(*(matrix)+(columna-6))=1;   //usamos algebra de punteros para posicionarnos en cada fila que indica los dias.
            else *(*(matrix)+(columna-6))=0;  //a las columnas les quitamos 6 porque el dia de estudio empieza a las 6 am.
            break;
        }
        case 'M':{
            if(option=='a') *(*(matrix+1)+(columna-6))=1;  //con algebra de punteros nos empezamos a mover en la matriz, ahora pasando a la siguiente fila.
            else *(*(matrix+1)+(columna-6))=0;  //cuando escogio la opcion a, e ingreso este dia martes, solo seria movernos entre la fila del martes. cero esta libre, 1 esta ocupada.
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

void cortarCadena(const char* codigo){

    const char* rutaArchivo = "archivo.txt";
    ifstream archivo(rutaArchivo);

    if(archivo.is_open()) {
        char caracter;

        while(archivo.get(caracter)){
            //cout << caracter;
            if(caracter == '\n'){ // verificar si el caracter es una coma

                char cadena[8]; // array de caracteres para almacenar los siguientes 7 caracteres
                char materia[60];
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




