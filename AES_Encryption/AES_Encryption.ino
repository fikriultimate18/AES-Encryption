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
