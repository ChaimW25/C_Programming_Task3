#include <stdio.h>
#include "str_ex3.h"
#include <string.h>

int main(){
//    fgets(word,WORD,stdin);
//    fgets(txt,TXT,stdin);
//char tmp1;
//char tmp2;
for(int i=0; i<WORD; i++){
    scanf("%c",&word[i]);
    if(word[i]=='\n'||word[i]=='\t'||word[i]==32){
        break;
    }
}
    for(int i=0; i<TXT; i++){
        scanf("%c",&txt[i]);
        if(txt[i]=='~'){
            break;
        }
    }

    gematria();
    atbash();
    anagram();

    return 0;
}
