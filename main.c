#include <stdio.h>
#include "str_ex3.h"
#include <string.h>

int main(){
    fgets(word,WORD,stdin);
    fgets(txt,TXT,stdin);
    gematria();
    atbash();
    anagram();

    return 0;
}
