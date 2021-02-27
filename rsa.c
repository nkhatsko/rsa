#include "rsa.h"


int generate_keys(char public_key_out[], char private_key_out[]) {

	RSA *rsa;
	FILE *public_file;
	FILE *private_file;
	const EVP_CIPHER *cipher;

	public_file = fopen(public_key_out, "wb");
	private_file = fopen(private_key_out, "wb");

	rsa = RSA_generate_key(1024, RSA_F4, NULL, NULL);
	cipher = EVP_get_cipherbyname("base64");

	PEM_write_RSAPublicKey(public_file, rsa);
	PEM_write_RSAPrivateKey(private_file, rsa, cipher, NULL, 0, NULL, NULL);

	RSA_free(rsa);
	fclose(public_file);
	fclose(private_file);

	return (0);

};


int encrypt(char public_key_out[], char data_in[], char data_out[]) {

	RSA *public_key;
	FILE *public_file;
	unsigned char *ctext;
	unsigned char *ptext;
	unsigned int inlen;
	unsigned int outlen;

	public_file = fopen(public_key_out, "rb");
	public_key = PEM_read_RSAPublicKey(public_file, NULL, NULL, NULL);
	fclose(public_file);

	int key_size = RSA_size(public_key);
	ctext = malloc(key_size);
	ptext = malloc(key_size);
	OpenSSL_add_all_algorithms();

	int in = open(data_in, O_RDWR);
	int out = open(data_out, O_CREAT | O_TRUNC | O_RDWR, 0600);

	while (1) {
		inlen = read(in, ptext, key_size - 11);
		if (inlen <= 0) {
			break;
		};

		outlen = RSA_public_encrypt(inlen, ptext, ctext, public_key, RSA_PKCS1_PADDING);
		if (outlen != RSA_size(public_key)) {
			return (1);
		};

		write(out, ctext, outlen);
	};

	return (0);

};


int decrypt(char public_key_out[], char data_in[], char data_out[]) {

	RSA *private_key;
	FILE *private_file;
	unsigned char *ptext;
	unsigned char *ctext;
	unsigned int inlen;
	unsigned int outlen;

	OpenSSL_add_all_algorithms();
	private_file = fopen(public_key_out, "rb");
	private_key = PEM_read_RSAPrivateKey(private_file, NULL, NULL, NULL);
	fclose(private_file);

	int key_size = RSA_size(private_key);
	ptext = malloc(key_size);
	ctext = malloc(key_size);

	int in = open(data_in, O_RDWR);
	int out = open(data_out, O_CREAT | O_TRUNC | O_RDWR, 0600);

	while (1) {
		inlen = read(in, ctext, key_size);
		if (inlen <= 0) {
			break;
		};

		outlen = RSA_private_decrypt(inlen, ctext, ptext, private_key, RSA_PKCS1_PADDING);
		if (outlen < 0) {
			return (1);
		};

		write(out, ptext, outlen);
	};

	return (0);

};

