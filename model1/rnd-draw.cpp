#include <stdio.h>
#include <stdlib.h>
int covid_19() {
    double scale = 1000.0;
    double Ncouples = 2000*scale;//10*scale;
    double Ntmp, N = 10000*scale;
    int Ndraw = 15;//*scale;
    double Pn0 = 1;
    Ntmp = N;
    for(int i=0; i<Ndraw; ++i) {
        Pn0 = Pn0*(N-Ncouples-i)/Ntmp;
        Ntmp = Ntmp - 1.0;
    }
    double Pn1 = Ncouples/N;
    Ntmp = N;
    for(int i=0; i<Ndraw-1; ++i) {
        Pn1 = Pn1*(N-Ncouples-i)/Ntmp;
        Ntmp = Ntmp - 1.0;
    }
    printf("P = %.10f, Pn0 = %.10f, Pn1 = %.10f\n", 1.0-Pn0-Pn1, Pn0, Pn1);
    return 0;
}

int birthday_paradox(int _Ndraw=20) {
    double scale = 10.0;
    double Ntmp, N = 365*scale;
    int Ndraw = _Ndraw;//*scale;
    double Pn1 = 1;
    for(int i=0; i<Ndraw-1; ++i) {
        Pn1 = Pn1*(N-i-1)/N;
        //Ntmp = Ntmp - 1.0;
    }
    printf("P = %.10f, Pn1 = %.10f\n", 1.0-Pn1, Pn1);
    return 0;
}

int main(int argc, char **argv) {
    covid_19();
    //birthday_paradox(atoi(argv[1]));
}
