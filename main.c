#include "menu.h"

#include <stdio.h>


int main(void) {

	printf("RSA ALGORITHM MANAGER\n");
	printf("\n");

	printf("MENU\n");
	printf("[1] generate keys\n");
	printf("[2] encrypt data\n");
	printf("[3] decrypt data\n");
	printf("\n");

	printf("make your choice: ");

	int select;
	scanf("%i", &select);
	switch (select) {
		case 1: menu_generate_keys(); break;
		case 2: menu_encrypt(); break;
		case 3: menu_decrypt(); break;
		default: menu_error(); break;
	};

	return (0);

};
