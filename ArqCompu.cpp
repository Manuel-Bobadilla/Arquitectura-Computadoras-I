#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdint>

static bool skip = false;
unsigned long int velocidad[4] = {50000000,50000000,50000000,50000000};

bool validarPassword();
bool stringCompare(char* , char*);
void retardo(unsigned long int);
void autoFantastico();
void carrera();
void choque();
void mostrar(uint8_t data);

int main(){
    /*HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode = 0;
    GetConsoleMode(hStdin, &mode);
    SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));*/
    
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE), 10);
    int menu = 0;
    int exit = 0;
    
    if (validarPassword()){
    	retardo(500000000);
    	while(!exit){
    		system("cls");
    		skip = 0;
    	
	    	std::cout << "-----Presione-----" << std::endl <<
	    			 "1. Auto Fantastico" << std::endl <<
	    			 "2. El Choque"		  << std::endl <<
	    			 "3. La Carrera"      << std::endl <<
	    			 "4. Arkanoid" 	      << std::endl <<
	    			 "5. Salir"			  << std::endl;
	    			 
	    	menu = getch(); // getch devuelve char, '1' = 49
	    	
	    	switch(menu){
	    		case 49:
					while(!skip){
						autoFantastico();
					}
					break;
				case 50:
					while(!skip){
						choque();
					}
				 	break;
				case 51:
					while(!skip){
						carrera();
					}
				  	break;
				case 52: break;
				case 53: exit = 1; break;
	    		default: break;
	    	}	
    	}	
    }
    
    system("cls");
    
    std::cout << "Fin";
    
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
			strUser[longPassword] = getch();
			std::cout << "*";
			longPassword ++;
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
	uint8_t inicio = 0x80;
	for(int i = 0; i < 8; i++){
		mostrar(inicio);
		inicio >>= 1;
		skip = GetAsyncKeyState(0x53);
		if(skip) return;
		if(GetAsyncKeyState(0x26)) velocidad[0] -= 5000000;
		if(GetAsyncKeyState(0x28)) velocidad[0] += 5000000;
		std::cout << std::endl << velocidad[0];
		retardo(velocidad[0]);
	}
	
	inicio = 0x02;
	
	for(int i = 0; i < 6; i++){
		mostrar(inicio);
		inicio <<= 1;
		skip = GetAsyncKeyState(0x53);
		if(skip) return;
		if(GetAsyncKeyState(0x26)) velocidad[0] -= 5000000;
		if(GetAsyncKeyState(0x28)) velocidad[0] += 5000000;
		std::cout << std::endl << velocidad[0];
		retardo(velocidad[0]);
	}
}

void mostrar(uint8_t inicio){
	system("cls");
	for(uint8_t mascara = 0x80; mascara > 0; mascara >>= 1){
		if(inicio & mascara) std::cout << '*';
		else std::cout << '_';
	}
}

void carrera() {   
	uint8_t table[] = {0x01,0x01,0x02,0x02,0x04,0x04,0x08,0x08,0x11,0x12,0x24,0x28,0x50,0x60,0xC0,0x80};
    for (int i = 0; i < 16; ++i) {
		mostrar(table[i]);
		skip = GetAsyncKeyState(0x53);
		if(skip) return;
		if(GetAsyncKeyState(0x26)) velocidad[2] -= 5000000;
		if(GetAsyncKeyState(0x28)) velocidad[2] += 5000000;
		std::cout << std::endl << velocidad[2];
		retardo(velocidad[2]);
	} 
}

void choque() {
	uint8_t arreglo[] = {
		0x81, 0x42, 0x24,
		0x18, 0x18, 0x24,
		0x42
	};
	
	for (int i = 0; i < 7; ++i) {
		mostrar(arreglo[i]);
		skip = GetAsyncKeyState(0x53);
		if(skip) return;
		if(GetAsyncKeyState(0x26)) velocidad[1] -= 5000000;
		if(GetAsyncKeyState(0x28)) velocidad[1] += 5000000;
		std::cout << std::endl << velocidad[1];
		retardo(velocidad[1]);
	}
}
    
