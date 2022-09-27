//ANGEL EMANUEL MENDOZA REYES 
//22110083
//GRUPO 2 O
//PROGRAMACION ORIENTADA A OBJETOS
//PARCIAL 2
//LUIS MANUEL MORALES MEDINA
//TRABAJO Viernes  Parte 3
#include<iostream> 
#include<string>
#include <sstream>

int maxDate(int, int);

using namespace std;
class Date {
private:
	int Year;
	int Month;
	int Day;
	string dateinstring;

public:
	bool correctDate;
	Date(string Fecha) {
		Day = stoi(Fecha.substr(0, 2));//Obtenemos el día
		Month = stoi(Fecha.substr(3, 5));//Obtenemos el mes
		Year = stoi(Fecha.substr(6, 10));//Obtenemos el año
		correctDate = false;
		validar_fecha();
	};
	
	void validar_fecha() {
		if (Month > 12 or Day > maxDate(Month, Year) or Month <= 0 or Day <= 0 or Year <= 0) {
			cout << "la fecha no es valida" << endl;
		}
		else {
			cout << "la fecha es valida" << endl;
			correctDate = true;

			if (Year % 4 == 0 and Year % 100 != 0 or Year % 400 == 0) {
				cout << "es a" << (char)164 << "o bisiesto" << endl;
			}
			else {
				cout << "no es a" << (char)164 << "o bisiesto" << endl;
			}
		}

	}

	operator const char* () {
		ostringstream formattedDate;
		formattedDate << Day << "/" << Month << "/" << Year << endl;
		dateinstring = formattedDate.str();
		return dateinstring.c_str();
	}
	
	Date& operator++() {
		Day++;//Aumentamos el día
		if (Day > maxDate(Month, Year)) {
			Day = 1;//Si supera el maximo se iguala a uno
			Month++;//Aumentamos el mes uno
			if (Month > 12) {
				Month = 1;//Supero el número de meses y se igualo a 1
				Year++;//Aumentamos un año
			}
		}
		
		return *this;
	}

};

int main() {
	string Fecha;//Variable donde el usuario guarda la fecha
	cout << "Fecha: ";
	cin >> Fecha;//Obtenemos la fecha
	Date fecha = Date(Fecha);
	if (fecha.correctDate) {
		cout << "\nvalidacion de la fecha operator const char*(): " << fecha;
		++fecha;
		cout << "Fecha del dia siguiente: " << fecha;
	}
}

int maxDate(int month, int year) {
	int max = 31;

	switch (month) {
	case 2:
		if (year % 4 == 0 && year % 100 != 0) max = 29;//Bisiesto
		else max = 28;//No bisiesto
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		max = 30;
		break;
	}

	return max;
}
