/*
    -----------------------------------------------------------------------------------------------------------------------
    Department of Information Security, Cryptography and Mathematics, Kookmin University College of Science and Technology 
    Creater : Yong Jin Lee 
    Date    : 2022.09.16
    Github  : https://github.com/leeeyj/Symmetric-Key-Algorithm

    Cipher Algorithm : AES
    Cipher Algorithm support mode : AES-128/192/256
        
    AES standard document : https://nvlpubs.nist.gov/nistpubs/fips/nist.fips.197.pdf
    -----------------------------------------------------------------------------------------------------------------------

    -----------------------------------------------------------------------------------------------------------------------
    Test Vector 
    <AES-128>
        Plain         = 00 11 22 33 44 55 66 77 88 99 aa bb cc dd ee ff
        Key(128 bits) = 00 01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f 
        Cipher        = 69 c4 e0 d8 6a 7b 04 30 d8 cd b7 80 70 b4 c5 5a

    <AES-192>
        Plain         = 00 11 22 33 44 55 66 77 88 99 aa bb cc dd ee ff
        Key(192 bits) = 00 01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f 10 11 12 13 14 15 16 17
        Cipher        = dd a9 7c a4 86 4c df e0 6e af 70 a0 ec 0d 71 91

    <AES-256>
        Plain         = 00 11 22 33 44 55 66 77 88 99 aa bb cc dd ee ff
        Key(256 bits) = 00 01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f 10 11 12 13 14 15 16 17 18 19 1a 1b 1c 1d 1e 1f
        Cipher        = 8e a2 b7 ca 51 67 45 bf ea fc 49 90 4b 49 60 89    
    -----------------------------------------------------------------------------------------------------------------------

    -----------------------------------------------------------------------------------------------------------------------
    How to Test 
    AES-Encrypt Function : AES_Encryption(uint8 plain[16], uint8 key[16 or 24 or 32], keySize, uint8 Cipher[16]);
    AES-Decrypt Function : AES_Decryption(uint8 Cipher[16], uint8 key[16 or 24 or 32], keySize, uint8 Decrypt[16]);
    ★ keySize must be 16 or 24 or 32 ★
    -----------------------------------------------------------------------------------------------------------------------
*/

#include "./AES.h"

int main()
{
    //uint8 = unsigned char
    
    uint8 plain[16] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff};
    
    // AES-128 Key
    // uint8 key[16] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};
    
    // AES-192 Key
    // uint8 key[24] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17};
    
    // AES-256 Key
    uint8 key[32] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f};
    
    uint8 Cipher[16];
    AES_Encryption(plain, key, sizeof(key)/sizeof(uint8), Cipher);
    printf("Encrypt Plain : \t");
    for (uint8 i = 0; i < 16; i++){
        printf("%02x ", Cipher[i]);
    }
    
    uint8 Decrypt[16];
    AES_Decryption(Cipher, key, sizeof(key)/sizeof(uint8), Decrypt);
    printf("\nDecrypt Cipher : \t");
    for (uint8 i = 0; i < 16; i++){
        printf("%02x ", Decrypt[i]);
    }

    return 0;
}