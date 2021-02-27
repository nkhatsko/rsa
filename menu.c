#include "menu.h"


void menu_generate_keys(void) {

	printf("\n");
	printf("GENERATE KEYS\n");

	char public_key[32];
	printf("enter name file public key: ");
	scanf("%31s", public_key);

	char private_key[32];
	printf("enter name file private key: ");
	scanf("%31s", private_key);

	if (!generate_keys(public_key, private_key)) {
		printf("\n");
		printf("KEYS SUCCESSFULLY GENERATED\n");
	};

};


void menu_encrypt(void) {

	printf("\n");
	printf("ENCRYPT\n");

	char public_key[32];
	printf("enter name file public key: ");
	scanf("%31s", public_key);

	char data_in[32];
	printf("enter name file data in: ");
	scanf("%31s", data_in);

	char data_out[32];
	printf("enter name file data out: ");
	scanf("%31s", data_out);

	if (!encrypt(public_key, data_in, data_out)) {
		printf("\n");
		printf("DATA SUCCESSFULLY ENCRYPTED\n");
	};

};


void menu_decrypt(void) {

	printf("\n");
	printf("DECRYPT\n");

	char private_key[32];
	printf("enter name file private key: ");
	scanf("%31s", private_key);

	char data_in[32];
	printf("enter name file data in: ");
	scanf("%31s", data_in);

	char data_out[32];
	printf("enter name file data out: ");
	scanf("%31s", data_out);

	if (!decrypt(private_key, data_in, data_out)) {
		printf("\n");
		printf("DATA SUCCESSFULLY DECRYPTED\n");
	};

};


void menu_error(void) {

	printf("\n");
	printf("WRONG CHOICE\n");

};
