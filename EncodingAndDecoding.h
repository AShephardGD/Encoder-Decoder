#ifndef ENCODING_AND_DECODING_H
#define ENCODING_AND_DECODING_H

void mutableEncodeCaesar(char* str, int n);
char* immutableEncodeCaesar(const char* str, const int n);
void mutableDecodeCaesar(char* str, int n);
char* immutableDecodeCaesar(const char* str, const int n);
void mutableEncodeXOR(char* str, const char* code);
char* immutableEncodeXOR(const char* str, const char* code);
void mutableDecodeXOR(char* str, const char* code);
char* immutableDecodeXOR(const char* str, const char* code);

#endif
