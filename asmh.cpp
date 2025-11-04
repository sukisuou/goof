//assembly simulator

#include <iostream>
#include <string>
#define db =
#define equ = 
#define global
#define mov func1(
#define end );
#define _xor func2(
#define syscall print();
#define _start
#define OxA ;

//ahem
int rax = 0;
int rdi = 0;
std::string rsi;
int rdx = 0;
std::string msg;
int len = 0;

struct money{
    int operator-(const std::string& msg) const{
        return msg.size();
    }
};
money $;
void func1(int& a, int b){
    a = b;
}
void func1(std::string& a, const std::string& b){
    a = b;
}
void func2(int& a, int b){
    a = a ^ b;
}
void print(){
    if(rax == 1) std::cout << rsi;
    if(rax == 60) return;
}






void section_data(){
    msg db "Hello world!" OxA
    len equ $ - msg;
}    

void section_text(){
    global _start;
}    

void start(){
    mov rax, 1 end
    mov rdi, 1 end
    mov rsi, msg end
    mov rdx, len end
    syscall

    mov rax, 60 end
    _xor rdi, rdi end
    syscall
}    








int main(){
    section_data();

    section_text();

    start();

    return 0;
}