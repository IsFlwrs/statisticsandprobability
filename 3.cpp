#ifndef ESTADISTICAS_H_INCLUDED
#define ESTADISTICAS_H_INCLUDED

 #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include<ctype.h>
    #include <math.h>
    #define MINIMO 1
    #define MAXIMO 100

    typedef float REAL;
    typedef struct{
      REAL rango,amplitud,maximo,minimo;
      int   intervalo;
    }PARAMETRO;

    typedef struct{
        REAL media,desv,var;
    }TENDENCIA;

    typedef struct{
        REAL *Lsup,*Linf;
    }LIMITES;

    typedef struct{
        int *frec,*frecA;
        REAL *frecR,*frecRA;
    }FRECUENCIA;

    void pausar(void);
    void NumeroDatos(int *ptr);
    REAL* RegistrarDatos(REAL *datos,int n);
    int validarNumero(char buffer[]);
    void RevisaCorrige(REAL *datos,int n);
    void CalculaParametro(PARAMETRO *ptr,REAL *datos,int n);
    int validarEntero(char buffer[]);
    void CalculaTendencia(TENDENCIA *ptr,REAL *datos,int n);
    void DefinirLimites(LIMITES *ptr,REAL *datos,PARAMETRO *param);
    void CalcularFrecuencia(REAL *datos,LIMITES *L,PARAMETRO *P,int n,FRECUENCIA *F);
    void Resultado(REAL *datos,int n,PARAMETRO *P,LIMITES *L,TENDENCIA *T,FRECUENCIA *F);


#endif // ESTADISTICAS_H_INCLUDED