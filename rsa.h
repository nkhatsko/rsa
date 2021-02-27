#pragma once

#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>


int generate_keys(char *, char *);
int encrypt(char *, char *, char *);
int decrypt(char *, char *, char *);
