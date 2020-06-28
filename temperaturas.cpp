#include <iostream>
using namespace std;

void imprimirTemperaturaDelDia(string diaSemana, float temperatura[]){

    int tempSemanal[4];
    string vecDiaSemana[7] = {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado", "Domingo"};

    for(int i = 0; i < 7; i++){

        if(vecDiaSemana[i] == diaSemana){

          for(int j = 0; j < 4; j++){

             tempSemanal[j] = temperatura[(j * 7) + i];
             cout << diaSemana << " " << j + 1 << ": " << tempSemanal[j] << endl;
            }
        }
    }

return;
}

void semanaTemperaturaMaxima(float tempMaxima, int temperaturasDelMes, float temperatura[]){

    char semanaMaxima;

    for(int i = 0; i < temperaturasDelMes; i++){

        if(temperatura[i] == tempMaxima && i >= 0 && i <= 6){
            semanaMaxima = '1';
        }
        else if(temperatura[i] == tempMaxima && i >= 7 && i <= 13){
            semanaMaxima = '2';
        }
        else if(temperatura[i] == tempMaxima && i >= 14 && i <= 20){
            semanaMaxima = '3';
        }
        else if(temperatura[i] == tempMaxima && i >= 21 && i <= 27){
            semanaMaxima = '4';
        }
    }
    cout << endl;
    cout << "La temperatura máxima del mes es " << tempMaxima <<  " y estuvo en la semana " << semanaMaxima << endl;
    cout << endl;

    return;
}

void temperaturaMaxima(float& tempMaxima, int temperaturasDelMes, float temperatura[]){

    for(int i = 0; i < temperaturasDelMes; i++){

        if(temperatura[i] > tempMaxima){
            tempMaxima = temperatura[i];
        }
    }

    return;
}

void imprimirTendencia(string tendencia, string mensaje){

    cout << mensaje << tendencia << endl;

    return;
}

void tendencias(float temperatura[], int posicion, string& tendencia){

    int resultado = 0;
    int aux = posicion;

    for(int i = posicion; i < (aux + 6); i++){

        if(temperatura[i] < temperatura[i + 1]){
            resultado = resultado + 1;
        }
        else if(temperatura[i] > temperatura[i + 1]){
            resultado = resultado - 1;
        }
    }

    if(resultado == 6){
       tendencia = "Creciente";
    }
    else if(resultado == -6){
        tendencia = "Decreciente";
    }
    else{
        tendencia = "Otra";
    }

    return;
}

string cargarDiaSemana(string diaSemana){

    cout << "Ingrese el día de la semana: ";
    cin >> diaSemana;
    cout << endl;
    
    return diaSemana;
}

int main(){

    int temperaturasDelMes = 28;
    float temperatura[temperaturasDelMes];
    float tempMaxima = 0;
    string tendencia;
    string diaSemana;

    for(int i = 0; i < temperaturasDelMes; i++){

       cout << "Ingrese la temperatura del dia " << i + 1 << ": ";
       cin >> temperatura[i];
    }
    cout << endl;

    diaSemana = cargarDiaSemana(diaSemana);

    tendencias(temperatura, 0, tendencia);
    imprimirTendencia(tendencia, "Semana 1: Tendencia ");

    tendencias(temperatura, 7, tendencia);
    imprimirTendencia(tendencia, "Semana 2: Tendencia ");

    tendencias(temperatura, 14, tendencia);
    imprimirTendencia(tendencia, "Semana 3: Tendencia ");

    tendencias(temperatura, 21, tendencia);
    imprimirTendencia(tendencia, "Semana 4: Tendencia ");

    temperaturaMaxima(tempMaxima, temperaturasDelMes, temperatura);

    semanaTemperaturaMaxima(tempMaxima, temperaturasDelMes, temperatura);

    imprimirTemperaturaDelDia(diaSemana, temperatura);

    return 0;
}
