#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

int gcd(int e, int fn) {
    if (fn == 0) {
        return e;
    }
    return gcd(fn, e % fn);
}

int areCoprime(int e, int fn) {
    return gcd(e, fn) == 1;
}

int ePrimo(int n){
if (n <= 1) {
        return 1;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 1; 
        }
    }
    return 0;
}

int ottieniNumeroPrimo(){
    int random = 0;
    do{
        srand(time(NULL));
        random = rand() % 26;
    }
    while(ePrimo(random) == 1);
    return random;
}

int main(int argc, char *argv[]){
    //int p = ottieniNumeroPrimo();
    //int q = ottieniNumeroPrimo();

    int p = 3;
    int q = 11;

    int n = p*q;
    int fn = (p - 1) * (q - 1); //f(n)

    int e = 0;
    do{
        srand(time(NULL));
        e = rand() % 21;
    }while(e >= fn); //aggiungere se coprimo
    
    int d;
    for(d = 1 ; d*e % fn != 1 ; d++);
    printf("%d",d);

    char pub[100] ; 
    char priv[100];
    char ns[50];
    char es[50];
    char ds[50];
    sprintf(ns, "%d", n);
    sprintf(es, "%d", e);
    sprintf(ds, "%d", d);
    strcat(pub, ns);
    strcat(priv, ns);
    strcat(pub, es);
    strcat(priv, ds);

    printf("Chiave pubblica: %s\n", pub);
    printf("Chiave privata: %s\n", priv);

    return 0;
}