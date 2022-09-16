#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned char uint8;

#define BlockSize 16

void RotWord(uint8* t);
void SubWord(uint8* t);
void RotSubWord(uint8* t);

// Multiplication on GF(2^8) 
uint8 xtime(uint8 a);   
uint8 m02(uint8 a);
uint8 m03(uint8 a);
uint8 m04(uint8 a);
uint8 m08(uint8 a);
uint8 m09(uint8 a);
uint8 m0b(uint8 a);
uint8 m0d(uint8 a);
uint8 m0e(uint8 a);

// AES basic function 
void AddRoundKey(uint8* arr, uint8* key, uint8 Round);
void SubBytes(uint8* arr);
void InvSubBytes(uint8* arr);
void ShiftRows(uint8* arr);
void InvShiftRows(uint8* arr);
void MixColumns(uint8* arr);
void InvMixColumns(uint8* arr);

// AES KeySchedule  
uint8* KeySchedule(uint8* key, uint8 size);

// AES operation function 
void AES_Encryption(uint8* plain, uint8* key, uint8 keySize, uint8* cipher);
void AES_Decryption(uint8* cipher, uint8* key, uint8 keySize, uint8* plain);