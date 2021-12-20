#include <stdio.h>
#include "str_ex3.h"
#include <string.h>
#include <strings.h>
#include <stdlib.h>

int length_word(){
    int length=0;
    while (word[length]!='\0')
    {
        length++;
    }
    return length;
}

int len_sentence(){
    int len=0;
    while (txt[len]!='~')
    {
        len++;
    }
    return len;
}

int not_letter(char a){
    if(a<65)return 1;
    else if(a>90&&a<97)return 1;
    else if(a>122)return 1;

    return 0;
}
//return the geamtri value of each letter
int gematri_letter(char a){
    if(not_letter(a)==1){
        return 0;
    }
    else if (a>=65&&a<=90) //capital case
    {
        return a-64;
    }
    return a-96; //normal case
}

int gematri_word(){
    int sum=0; int len=length_word();
    for(int i=0; i<len ; i++){
        sum+=gematri_letter(word[i]);
    }
    return sum;
}

int sum( int i, int j){
    int s=0;

    for(int a=i; a<=j; a++){
        s+=gematri_letter(txt[a]);
    }
    return s;
}

void print(int i, int j, int* num){
    if(*num>0) printf("~");
    while (txt[i]==32||txt[i]=='\n'||txt[i]=='\t')
    {
        j--;
    }

    for(int a=i; a<=j; a++){
        printf("%c",txt[a]);
    }

}

void gematria(){
    printf("Gematria Sequences:");
    int len=len_sentence();
    int s=gematri_word();
    int i=0,j=0;
    int sum2=0;
    int printNum=0;
    while (j<len){

        sum2=sum(i,j);
        if (sum2<s) {j++;}

        else if (sum2>s) {i++;}

        else {
            while (gematri_letter(txt[i])==0){i++;}
            print(i,j, &printNum);
            i++; j++; printNum++;
        }
    }
    printf("\n");
}

char atbash_letter(char a){
    int s=gematri_letter(a);
    int t=26-s;
    if (a>=65&&a<=90)
    {
        return 65+t;
    }
    else if(a>=97&&a<=122){
        return 97+t;
    }
    return 0;
}

void fill_atb(){

    int len=length_word();
    for(int i=0; i< len; i++){
        atb[i]=atbash_letter(word[i]);
    }

}

void reverse_atb_temp(char* atb_temp){

    int len=length_word();

    for(int i=0; i<len ;i++){
        atb_temp[i]=atb[len-2-i];
    }

}

int seq_atb(int i, int j){
    int l=0;
    for(int a=i; a<=j; a++){
        if (txt[a]!=atb[l]&&txt[a]!='\n'&&txt[a]!='\t'&&txt[a]!=32)
        {
            return 0;
        }
        if(txt[a]==atb[l])l++;
    }
    return 1;
}

int seq_atb_temp(char* atb_temp,int i, int j){
    int l=0;
    for(int a=i; a<=j; a++){
        if (txt[a]!=atb_temp[l]&&txt[a]!='\n'&&txt[a]!='\t'&&txt[a]!=32)
        {
            return 0;
        }
        if(txt[a]==atb_temp[l])l++;
    }
    return 1;
}

int num_of_letters(int i, int j){
    int sum=0;
    for(int a=i; a<=j; a++){
        int b=gematri_letter(txt[a]);
        if(b>0){
            sum++;
        }
    }
    return sum;
}

void atbash(){
    fill_atb();
    char atb_temp[WORD];
    reverse_atb_temp(atb_temp);
    printf("Atbash Sequences:");
    int len=len_sentence();
    int len2=length_word()-1;
    int printNum=0;
    int i=0; int j=i+(len2-1);
    while (j<len){

        int num=num_of_letters(i,j);

        if (num<len2){j++; continue;}

        else if (num>len2){i++;continue;}

        else{
            int a=seq_atb(i,j);
            int b=seq_atb_temp(atb_temp,i,j);
            if(a==1||b==1){
                while (txt[i]==32||txt[i]=='\n'||txt[i]=='\t'){i++;}
                print(i,j,&printNum); printNum++;}
            i++; j++;
        }
    }
    printf("\n");
}

void fill_anagram(){
    int len=length_word()-1;

    for (size_t i = 0; i < 128; i++){
        anagram_arr[i]=0;}

    for (size_t i = 0; i <len ; i++){
        anagram_arr[(int)word[i]]++;}
}

int seq_anagram(int* i, int* j){
    for (size_t a = *i; a <= *j; a++){

        if(txt[a]==32||txt[a]=='\n'||txt[a]=='\t')continue;
            //if the chat isn't there
        else if (anagram_arr[(int)txt[a]]==0){
           *i+=(1); *j+=(1);
            fill_anagram();
            return 0;}
        //if the char is there
        else{
            anagram_arr[(int)txt[a]]--;
        }
    }
    fill_anagram();
    return 1;
}

int num_of_chars(int i, int j){
    int sum=0;
    for (size_t a = i; a <= j; a++)
    {
        if (txt[a]!=32&&txt[a]!='\n'&&txt[a]!='\t'){
            sum++;}
    }
    return sum;
}

void anagram(){
    fill_anagram();
    printf("Anagram Sequences:");
    int printNum=0;
    int len=len_sentence();
    int i=0, j=length_word()-2;
    int len2=length_word()-1;

    while (j<len){
        int num=num_of_chars(i,j);

        if(num<len2){ j++; continue; }

        else if(num>len2){i++; continue;}

        else{
            int n=seq_anagram(&i,&j);
            if(n==1){
                while(txt[i]==32||txt[i]=='\n'||txt[i]=='\t'){i++;}
                print(i,j,&printNum); printNum++;
                i++; j++;}
        }
    }
}

