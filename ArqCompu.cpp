#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdint>
#include <stdlib.h>

bool validarPassword();
bool stringCompare(char* , char*);
void retardo(unsigned long int*,bool*);
void autoFantastico(unsigned long int*,bool*);
void carrera(unsigned long int*,bool*);
void semaforoCarrera(unsigned long int*,bool*);
void choque(unsigned long int*,bool*);
void sirena(unsigned long int*,bool*);
void pendulo(unsigned long int*,bool*);
void mostrar(uint8_t data);

int main(){
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE), 10); // letras verdes
    unsigned long int velocidad[7] = {800,1000,1000,10000,1500,1500,15000};
    int menu = 0;
    int exit = 0;
    bool skip;
    bool escrituraDesc; //escribir la descripcion de la secuencia, surge de evitar usar system("cls")
    
    if (validarPassword()){
    	retardo(&velocidad[6], &skip);
    	while(!exit){
    		system("cls");
    		skip = 0;
    		escrituraDesc = 1;
    														  
	    	std::cout << "------Presione------" << std::endl <<
		    			 "1. Auto Fantastico"   << std::endl <<
		    			 "2. El Choque"		    << std::endl <<
		    			 "3. La Carrera"        << std::endl <<
		    			 "4. Semaforo Carrera"  << std::endl <<
		    			 "5. Sirena"		    << std::endl <<
		    			 "6. Pendulo"			<< std::endl <<
		    			 "7. Salir"				<< std::endl;
	    			 
	    			 
	    	do{
	    		menu = getch(); // getch devuelve char, '1' = 49
	    	}while(menu < 49 || menu > 55);
	    	
	    	system("cls");
	    	
	    	switch(menu){
	    		case 49:
					while(!skip){
						if(escrituraDesc){
							std::cout << "El Auto Fantastico !!!" << std::endl 
							<< "Presione 'u' para aumentar el retardo y 'd' para disminuirlo" << std::endl;
							escrituraDesc = 0;
						}
						autoFantastico(&velocidad[0],&skip);
					}
					break;
				case 50:
					while(!skip){
						if(escrituraDesc){
							std::cout << "El Choque !!!" << std::endl 
							<< "Presione 'u' para aumentar el retardo y 'd' para disminuirlo" << std::endl;
							escrituraDesc = 0;
						}
						choque(&velocidad[1],&skip);
					}
				 	break;
				case 51:
					while(!skip){
						if(escrituraDesc){
							std::cout << "La Carrera !!!" << std::endl 
							<< "Presione 'u' para aumentar el retardo y 'd' para disminuirlo" << std::endl;
							escrituraDesc = 0;
						}
						carrera(&velocidad[2],&skip);
					}
				  	break;
				case 52:
					while(!skip){
						if(escrituraDesc){
							std::cout << "El Semaforo de Carrera !!!" << std::endl 
							<< "Presione 'u' para aumentar el retardo y 'd' para disminuirlo" << std::endl;
							escrituraDesc = 0;
						}
						semaforoCarrera(&velocidad[3],&skip);
					}
				 	break;
			 	case 53:
					while(!skip){
						if(escrituraDesc){
							std::cout << "La Sirena !!!" << std::endl 
							<< "Presione 'u' para aumentar el retardo y 'd' para disminuirlo" << std::endl;
							escrituraDesc = 0;
						}
						sirena(&velocidad[4],&skip);
					}
				 	break;
			 	case 54:
					while(!skip){
						if(escrituraDesc){
							std::cout << "El Pendulo !!!" << std::endl 
							<< "Presione 'u' para aumentar el retardo y 'd' para disminuirlo" << std::endl;
							escrituraDesc = 0;
						}
						pendulo(&velocidad[5],&skip);
					}
				 	break;
				case 55: exit = 1; break;
	    		default: break;
	    	}	
    	}	
    }
    
    std::cout << "Fin";
    
    retardo(&velocidad[6], &skip);
    
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

void retardo(unsigned long int* n,bool* skip){
	char control = 'f';
	float porcentajeCambio = *n;
	unsigned long int contador = *n;
	while(contador){
		if(kbhit()){
			control = getch();
			switch (control){
				case 's':
					*(skip) = true;
					return;
					break;
				case 'u':
					porcentajeCambio = 100 / porcentajeCambio + 1;
					contador *= porcentajeCambio;
					n[0] += 100;
					break;
				case 'd':
					if(n[0] != 100){
						porcentajeCambio = 1 - 100 / porcentajeCambio;
						contador *= porcentajeCambio;
						n[0] -= 100;
					}
					break;
				default:break;
			}
		}
		contador--;
	}
}

bool stringCompare(char* strUser, char* password){
	for(int i = 0; i < 5; i++){
		if(strUser[i] != password[i]) return false;
	}
	return true;
}

void autoFantastico(unsigned long int* v,bool* skip){
	uint8_t inicio = 0x80;
	for(int i = 0; i < 8; i++){
		mostrar(inicio);
		inicio >>= 1;
		std::cout << "    El retardo actual es: "<< v[0] << " ";
		retardo(v, skip);
		if(*skip) return;
	}
	
	inicio = 0x02;
	
	for(int i = 0; i < 6; i++){
		mostrar(inicio);
		inicio <<= 1;
		std::cout << "    El retardo actual es: "<< v[0] << " ";
		retardo(v, skip);
		if(*skip) return;
	}
}

void mostrar(uint8_t inicio){
	printf("\r");
	
	std::cout << "     ";//Separar la secuencia de la pantalla
	for(uint8_t mascara = 0x80; mascara > 0; mascara >>= 1){
		if(inicio & mascara) std::cout << '*';
		else std::cout << '_';
	}
}

void carrera(unsigned long int* v,bool* skip) {   
	uint8_t arreglo[] = {0x01,0x01,0x02,0x02,0x04,0x04,0x08,0x08,0x11,0x12,0x24,0x28,0x50,0x60,0xC0,0x80};
    for (int i = 0; i < 16; i++) {
		mostrar(arreglo[i]);
		std::cout << "    El retardo actual es: "<< v[0] << " ";
		retardo(v, skip);
		if(*skip) return;
	} 
}

void choque(unsigned long int* v,bool* skip) {
	uint8_t arreglo[] = {
		0x81, 0x42, 0x24,
		0x18, 0x18, 0x24,
		0x42
	};
	
	for (int i = 0; i < 7; i++) {
		mostrar(arreglo[i]);
		std::cout << "    El retardo actual es: "<< v[0] << " ";
		retardo(v, skip);
		if(*skip) return;
	}
}

void semaforoCarrera(unsigned long int* v,bool* skip){
	uint8_t arreglo[] = {
		0x00,0xc0,0xf0,
		0xfc,0xff,0xff
	};
	
	for (int i = 0; i < 6; i++) {
		mostrar(arreglo[i]);
		std::cout << "    El retardo actual es: "<< v[0] << " ";
		retardo(v, skip);
		if(*skip) return;
	}
}

void pendulo(unsigned long int* v,bool* skip){
	uint8_t arreglo[] = {
		0x0c,0x8c,0x4c,0x2c,
		0x1c,0x1a,0x19,0x18,
		0x18,0x19,0x1a,0x1c,
		0x2c,0x4c,0x8c,0x0c
	};
	
	for (int i = 0; i < 16; i++) {
		mostrar(arreglo[i]);
		std::cout << "    El retardo actual es: "<< v[0] << " ";
		retardo(v, skip);
		if(*skip) return;
	}
}

void sirena(unsigned long int* v,bool* skip){
	uint8_t inicio = 0xf0;
	for(int i = 0; i < 8; i++){
		mostrar(inicio);
		std::cout << "    El retardo actual es: "<< v[0] << " ";
		retardo(v,skip);
		if(*skip) return;
	}
	inicio >>= 4;
	for(int i = 0; i < 8; i++){
		mostrar(inicio);
		std::cout << "    El retardo actual es: "<< v[0] << " ";
		retardo(v,skip);
		if(*skip) return;
	}
	inicio <<= 4;
	for(int j = 0; j < 2 ; j++){
		for(int i = 0; i < 2; i++){
			mostrar(inicio);
			std::cout << "    El retardo actual es: "<< v[0] << " ";
			retardo(v,skip);
			if(*skip) return;
		}
		for(int i = 0; i < 2; i++){
			mostrar(0x00);
			std::cout << "    El retardo actual es: "<< v[0] << " ";
			retardo(v,skip);
			if(*skip) return;
		}
	}
	inicio >>= 4;
	for(int j = 0; j < 2 ; j++){
		for(int i = 0; i < 2; i++){
			mostrar(inicio);
			std::cout << "    El retardo actual es: "<< v[0] << " ";
			retardo(v,skip);
			if(*skip) return;
		}
		for(int i = 0; i < 2; i++){
			mostrar(0x00);
			std::cout << "    El retardo actual es: "<< v[0] << " ";
			retardo(v,skip);
			if(*skip) return;
		}
	}
}
    
