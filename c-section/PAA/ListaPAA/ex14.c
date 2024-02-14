#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void removeSpace(char string[]) {
    int j = 0;

    for (int i = 0; i < strlen(string); i++) {
        if (string[i] != ' ') {
            string[j++] = string[i];
        }
    }
    string[j] = '\0';
}


void lower(char string[]) {
    int i = 0;
    while (string[i]) {
        string[i] = tolower(string[i]);
        ++i;
    }
}


int vigenereDistance(char c) {
    char alphabet[26];

    for (int i = 0; i < 26; i++) {
        alphabet[i] = 'a' + i;
        if (c == alphabet[i]) return i;
    }
    return -1;
}


void vigenereCipher(char msg[], char key[]) {
    int msglen = strlen(msg);
    int keylen = strlen(key);

    // Gerando uma nova chave para o caso dela ser menor
    // que a mensagem
    char *newKey;

    if (keylen < msglen) {
        int newKeyLen = keylen + (msglen - keylen);

        newKey = (char *) calloc(newKeyLen, sizeof(char));

        int j = 0;
        for (int i = 0; i < newKeyLen; i++) {
            newKey[i] = key[j];
            j = (j + 1) % keylen;
        }
    } else {
        newKey = (char *) calloc(keylen, sizeof(char));

        for (int i = 0; i < keylen; i++) {
            newKey[i] = key[i];
        }
    }

    // Criando a cifra
    char alphabet[26];

    for (int i = 0; i < 26; i++) {
        alphabet[i] = 'a' + i;
    }

    for (int i = 0; i < msglen; i++) {
        msg[i] = alphabet[(vigenereDistance(msg[i]) + vigenereDistance(newKey[i])) % 26];
    }
}


int main() {
    char m[100];
    printf("Digite a mensagem a ser cifrada: ");
    scanf(" %[^\n]", m);

    char x[100];
    printf("Digite a chave para a cifra: ");
    scanf(" %[^\n]", x);

    removeSpace(m);
    removeSpace(x);

    lower(m);
    lower(x);

    printf("Mensagem: %s\n", m);

    vigenereCipher(m, x);

    printf("Chave: %s\nCifra: %s\n", x, m);

    return 0; 
}
