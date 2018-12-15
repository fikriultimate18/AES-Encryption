#include <AES.h>
#include "./printf.h"

AES aes ;

byte *key = (unsigned char*)"0123456789010123";

byte plain[] = "Fikri Rida P";
int plainLength = sizeof(plain)-1;  // don't count the trailing /0 of the string !
int padedLength = plainLength + N_BLOCK - plainLength % N_BLOCK;

//real iv = iv x2 ex: 01234567 = 0123456701234567
unsigned long long int my_iv = 36753562;

void setup ()
{
  Serial.begin (57600);

  printf_begin();
  delay(500);


  prekey(128);
}

void loop () 
{

}

void prekey (int bits){

  aes.iv_inc();
  
  byte iv [N_BLOCK] ;
  byte plain_p[padedLength];
  byte cipher [padedLength] ;
  byte check [padedLength] ;

  aes.set_IV(my_iv);
  aes.get_IV(iv);
  aes.do_aes_encrypt(plain,plainLength,cipher,key,bits,iv);

  aes.set_IV(my_iv);
  aes.get_IV(iv);
  aes.do_aes_decrypt(cipher,padedLength,check,key,bits,iv);

  printf("\n\nPLAIN :");
  aes.printArray(plain,(bool)true);

  for(int i=0; i<=sizeof(plain); i++){
    Serial.print(plain[i]);
    Serial.print(" ");
  }

  Serial.println();
  
  Serial.println(sizeof(plain));
  printf("\nCIPHER:");
  aes.printArray(cipher,(bool)false);
  printf("\nCHECK :");

  int textLength = 0;

  for(int i=0; i<=sizeof(check); i++){
    if(check[i]>31 && check[i]<127) textLength++;
  }

  textLength--;

  char decryptedChar[textLength];
  
  for(int i=0; i<=textLength; i++){
    decryptedChar[i]=check[i];
    Serial.print(decryptedChar[i]);
  }
  Serial.println();
  

  printf("\nIV    :");
  aes.printArray(iv,16);
  
}

void printArrayHehe(byte check[]){

}
