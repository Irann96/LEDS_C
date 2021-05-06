//Code to control the LED3 usr by arguments


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LED3 "/sys/class/leds/beaglebone:green:usr3"
  
      //Prototypes functions:
void WriteLED(char filename[], char value[]);
void RemoveTrigger();

int main(int argc, char* argv[]) {
	if(argc!=2){
		printf("Error wrong number of arguments!!\n");
		return 2;
	}
	printf("Starting the script....\n");
	//comparing arguments
	if(strcmp(argv[1], "on")==0){
		printf("LED on\n");
		RemoveTrigger();
		WriteLED( "/brightness", "1");  //argumentos
	}

	else if(strcmp(argv[1], "off")==0){
		printf("LED off\n");
		RemoveTrigger();
		WriteLED("/brightness", "0");
	}
	
	else if(strcmp(argv[1], "flash")==0){
		printf("Flashing the LED3\n");
		WriteLED("/trigger", "timer");
		WriteLED("/brightness", "100");
		WriteLED("/brightness", "100");
	}
	else{
		printf("Invalid comand!\n");
		return 0;
	}
printf("Led Aplication Done \n");	
	return 0;

}

//Complete functions:
void WriteLED(char filename[], char value[]){
	FILE* fp; //CORRESPONDE AL APUNTADOR que debo investigar
	char fullFile[100];
	sprintf(fullFile, LED3 "%s", filename);  //LA S, XK CORRESPONDE AL TIPO DE CARACTER
	fp = fopen(fullFile, "w+");
	fprintf(fp, "%s", value);
	fclose(fp);
}

void RemoveTrigger(){
	WriteLED("/trigger", "none");
}


