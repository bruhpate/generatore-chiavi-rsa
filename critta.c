#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[]){
    //int pub = 77968964883;
    //int priv = 7796891286503;
    int n = 33;
    int e = 13;
    int d = 17;

    int msg = 2;
    int msg_crittato = (int)pow(msg, e) % n;
    printf("%d\n", msg_crittato);

    int msg_decrittato = (int)pow(msg_crittato,d) % n;
    printf("%d", msg_decrittato);

    return 0;
}