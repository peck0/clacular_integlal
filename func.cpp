//Programa para calcular el area bajo la curva
//Hecho por Kelvin Peña y Pedro Pablo Infante
//Mayo 2019
#include <iostream>
#include <math.h>
#define PI 3.141592653589793

//Declaracion de las funicones
double funcion(double a);
void metodoTrapezoidal(double a, double b, int n);
void metodoSimpson(double a, double b, int n);
void cargarValores(double a, double b, int n);

//Metodo main
int main (){
    //Declarar variables
    int opcion, particiones;    
    double inicio, fin;  

    //mostrar pantall de inicio
    std::cout << "*********************************************";
    std::cout << "\n*****\tCalcular el area bajo la curva\t*****\n";
    std::cout << "*********************************************\n";     
    
    //entrada de datos para calcular
    std::cout << "El intervalo de inicio es: ";
    std::cin >> inicio;
    while(!std::cin){
        std::cin.clear();
        std::cin.ignore();
        std::cin >> inicio;
    }
    std::cout << "El intervalo de final es: ";
    std::cin >> fin;
    while(!std::cin){
        std::cin.clear();
        std::cin.ignore();
        std::cin >> fin;
    }
    //condiciones para evitar la divicion entre 0
    do{
        std::cout << "Cantidad de particiones: ";
        std::cin >> particiones;
        while(!std::cin){
            std::cin.clear();
            std::cin.ignore();
            std::cin >> particiones;
        }
        if(particiones == 0){
            std::cout << "No se puede realizar operaciones con 0 particiones.\n";
        } 
    }while(particiones == 0);     

    //bucle para ejecutar el programa    
    do{ 
        //muestra las opciones del menu del programa
        std::cout << "[1] - Metodo del trapecio\n";
        std::cout << "[2] - Metodo de Simpson\n";
        std::cout << "[3] - Calcular con otros valores\n";
        std::cout << "[0] - SALIR\n";

        //entrada para el menu
        std::cin>>opcion;
        
        //rutinas a ejecutar segun la opcion elegida
        if(opcion == 1) metodoTrapezoidal(inicio, fin, particiones);
        if(opcion == 2) metodoSimpson(inicio, fin, particiones);
        if(opcion == 3) main();    
    }while(opcion!=0) ;       
}

//Funcion para evaluar 
double funcion(double a){
    /*esta funcion matematica se puede sustituir por otra
    que representa la integral a evaluar ya sea por el metodo
    del trapezoide o el metodo de Simpon*/
    return sin(a);
    
}

//Metodo del trapecio
void metodoTrapezoidal(double a, double b, int n){
    //declaracion de variables
    double res = 0, dx = 0, area = 0;

    //calcular el diferencial segun los datos suministrados
    dx = (b - a) / n;

    /*segun el metodo de trapecio en el primer y ultimo intervalo
    la funcion se evalua segun la suma del area de los trapecios para los demas
    intervalos la funcion se evalua por la suma del area de los trapecios y se
    multiplica por 2*/
    for (int i = 0; i <= n; i++){
        if(i == 0){
            res = res +  funcion(a);
        }else if(i == n){
            res = res +  funcion(a);
        }else{
            res = res + 2 * funcion(a);
        }
        /*se realiza la suma del area de los trapecios para
        el siguiente intervalo*/
        a = a + dx;
    }
    system("clear");
    /*La suma de todos los intervalos se multiplica por el diferencial
    dividido entre 2*/
    area = dx / 2 * res;
    std::cout << "El area por el metodo del trapecio es: " << area << "\n\n"; 
}

//Metodo de Simpson
void metodoSimpson(double a, double b, int n){
    //declara variables
    double res = 0, dx = 0, area = 0;    
     
    if(n % 2 == 0){
        //calcular el diferencial
        dx = (b - a) / n;

    /*segun el metodo de Simpson en el primer y ultimo intervalo
    la funcion se evalua segun la suma del area de los trapecios para los demas
    intervalos la funcion se evalua por la suma del area de los trapecios y se
    multiplica por 2 cuando la posicion es par o se multiplica por 4 cuando la
    posicion es impar*/
        for(int i = 0; i <= n; i++){
            if(i == 0){
                res = res + funcion(a);
            }else if(i % 2 == 0 && i < n){
                res = res + 2 * funcion(a);
            }else if(i == n){
                res = res + funcion(a);
            }else{
                res = res + 4 * funcion(a);
            }
            /*se realiza la suma del area de los trapecios para
            el siguiente intervalo*/
            a = a + dx;
        }
        /*La suma de todos los intervalos se multiplica por el diferencial
        dividido entre 3*/
        area = dx / 3 * res;
        system("clear");
        std::cout << "El area por el metodo Simpson es: " << area << "\n\n";
     }else{
         system("clear");
         std::cout << "Con el metodo de Simpson el numero de intervalo no debe ser IMPAR\n";
     }
}