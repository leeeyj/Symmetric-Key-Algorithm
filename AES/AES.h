#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned char uint8;

#define BlockSize 16

void RotWord(uint8* t);
void SubWord(uint8* t);
void RotSubWord(uint8* t);

uint8 xtime(uint8 a);
uint8 m02(uint8 a);
uint8 m03(uint8 a);

void AddRoundKey(uint8* arr, uint8* key, uint8 Round);
void SubBytes(uint8* arr);
void ShiftRows(uint8* arr);
void MixColumns(uint8* arr);

uint8* KeySchedule(uint8* key, uint8 size);
void AES_Encryption(uint8* plain, uint8* key, uint8 keySize, uint8* cipher);
