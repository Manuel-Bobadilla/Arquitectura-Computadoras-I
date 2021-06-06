#include <iostream>
#include <windows.h>
#include <conio.h>

bool validarPassword();
bool stringCompare(char* , char*);
void retardo(unsigned long int);
void autoFantastico();

int main()
{
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode = 0;
    GetConsoleMode(hStdin, &mode);
    SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));
    
    int menu = 0;
    
    if (validarPassword()){
    	retardo(500000000);
    	
    	system("cls");
    	
    	std::cout << "-----Presione-----" << std::endl <<
    			 "1. Auto Fantastico" << std::endl <<
    			 "2. El Choque"		  << std::endl <<
    			 "3. La Carrera"      << std::endl;
    
    	while(!menu){
    		menu = getch();
    	}
    	
    	std::cout << menu;
    	
    	switch(menu){
    		case 1: autoFantastico();break;
    		default: std::cout << "Numero incorrecto";break;
    	}
    }
    
    
    retardo(500000000);
    
	return 0;
}

bool validarPassword(){
	char strUser[6]; //5 longitud password + 1 caracter nulo
	char password[6] = "12345";
	int intentos = 3, longPassword = 0;
	
	std::cout << "Ingrese su password de 5 digitos: ";

	while(intentos){
		//carga de la contraseña
		while(longPassword < 5){
			if(strUser[longPassword] = getch()){
				std::cout << "*";
				longPassword ++;
			}
		}
		//validación contraseña
		if(stringCompare(strUser, password)){
			std::cout << "\nBienvenido al Sistema";
			return true;
		}
		std::cout << "\nPassword no valida";
		intentos --;
		longPassword = 0;
		if(intentos){
			getch();
			system("cls");
			std::cout << "Ingrese su password de 5 digitos: ";
		}else{
			std::cout << "\nExcedio el limite de intentos";
			return false;
		}
	}
}

void retardo(unsigned long int n){
	while(n){
		n--;
	}
}

bool stringCompare(char* strUser, char* password){
	for(int i = 0; i < 5; i++){
		if(strUser[i] != password[i]) return false;
	}
	return true;
}

void autoFantastico(){

}
