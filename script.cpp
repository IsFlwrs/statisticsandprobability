#include <stdio.h>
#include "estadisticas.h"
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#define MAX 10
//VARIABLES
   char q;
   float resultado,clasico, empirico,x,e,N,A,A2,B,c,d,l,o,y[20],v[20],w[20];
   int opc;
   long int fact=1,pc=1,fact2=1,fact3=1,r=0,k,fx,z;
   int i=1,j=1,num=0,num2=0,s=0,a=0,b=0,res=0,n,m,p;
   int numeros[MAX];
   int contador=0;
   int auxiliar[MAX];
   int posicion=0;
   int numero=0;
   int contador2=0;
   int mayor=0;
   int posicionmayor=0;
   int bandera=0;
   float suma=0;
   int opcion = -1;
   int cantidad = 0;
   float varianza = 0;
   float desviacion = 0;
   char resp;
   REAL *datos;
    int N_datos,i;
    PARAMETRO parametro;
    TENDENCIA tendencia;
    LIMITES limites;
    FRECUENCIA frecuencia;


int factorial(int n) {
   int resultado=1, i;
   if (n>1) {
        for (i=2;i<=n;i++) {
            resultado*=i;   /* Esta expresion es una abreviatura de resultado=resultado*i; */
        }
   }
   return resultado;
}

int combinaciones(int y, int z) {
  return (factorial(y) / (factorial(z) * factorial(y-z)));
}

int main(){
   printf("\nMateria:");
   printf("\nProbabilidad y Estadistica");
   printf("\nEquipo:  Doble A ");
   printf("\nIntegrantes:");
   printf("\nDe Luna Lopez Avianey");
   printf("\nMorales Vida Rigoberto");
   printf("\nPreciado Carvajal Carlos Alberto");
   printf("\n");
   while(1){

   printf("\n");
   printf("\n");
   printf("***Programas aplicado a Probabilidad y Estadistica***");
   printf("\nSeleccione el tema que necesite");
   printf("\n");
   printf("\n1.Notacion Factorial");
   printf("\n2.Permutacion Circular");
   printf("\n3.Permutacion de Objetos distintos tomados de r en r");
   printf("\n4.Permutaciones con repeticion de n elemntos tomados de r en r ");
   printf("\n5.Principio Multiplicativo");
   printf("\n6.Combinaciones");
   printf("\n7.Enfoque de probablidad clasico");
   printf("\n8.Enfoque de probablidad empirico");
   printf("\n9.Regla general de adicion");
   printf("\n10.Probabildad condicional");
   printf("\n11.regla general de multiplicacion");
   printf("\n12.Probablidad total");
   printf("\n13.Teorema de Bayes");
   printf("\n+ Medidas de tendencia central para datos no agrupados");
   printf("\n14.Moda");
   printf("\n   Media");
   printf("\n   Mediana");
   printf("\n+ Medidas de dispersion");
   printf("\n15.Rango");
   printf("\n   Varianza");
   printf("\n   Desviacion estandar");
   printf("\n   Coeficiente de variacion");
   printf("\n16.Tabla de frecuencias");
   printf("\n");
   scanf("%i" ,&opc);
   getch();
   switch(opc)
        {
        case 1:printf("\n");
            printf("**Notacion Factorial**");
            printf("\nIngrese el numero al que le quiere calcular el factorial\n");
            scanf("%d",&num);
                    printf("El factorial  es %ld",factorial(num));
                    getch();
            break;

        case 2:printf("\n");
            printf("**Permutacion Circular**");
            printf("\nIngrese el numero al que le quiere calcular\n");
            scanf("%d",&num);
            num2=num-1;
                    printf("La permutacion circular  %ld",factorial(num2));
                    getch();
            break;

        case 3: printf("\n");
            printf("**Permutacion de Objetos distintos tomados de r en r**");
            printf("\nIngrese el numero de el total de los elementos que se tienen\n");
            scanf("%d",&num);
            printf("\nIngrese la condicion\n");
            scanf("%d",&num2);
            s=num-num2;
            fact= factorial(num) ;
            fact2 =factorial(s);
            r= fact/ fact2;
            printf("El resultado es: %ld",r);
            getch();
            break;

        case 4:printf("\n");
            printf("**Permutaciones con repeticion de n elemntos tomados de r en r**");
            printf("\nIngrese el numero de opciones con las que se cuenta\n");
            scanf("%d",&num);
            printf("\nIngrese el numero de veces que se repite la opcion\n");
            scanf("%d",&num2);
            s=pow(num,num2);
            printf("\nEl resultado es: %d",s);
            getch();
            break;

        case 5:printf("\n");
        int arreglo[9];
        int  mult,evento;
            printf("**Principio Multiplicativo**");
            printf("\nNOTA: Tiene un maximo de 10 etapas a ingresar");
            printf("\nSi las etapas son menos de 10 llena el resto con 1");
            printf("\n");
            for(i=0;i<10;i++){
                printf("Etapa [%d]:", i+1);
                scanf("%d",&arreglo[i]);
                mult=arreglo[0]*arreglo[1]*arreglo[2]*arreglo[3]*arreglo[4]*arreglo[5]*arreglo[6]*arreglo[7]*arreglo[8]*arreglo[9];
            }
              printf("\nResultado :%d",mult);
              getch();
            break;

    case 6:printf("\n");
         printf("**Combinaciones**");
         printf("Introduzca el numero de objetos del conjunto (n):");
         scanf("%d",&n);
         printf("Introduzca el numero de objetos a elegir (m):");
         scanf("%d",&m);
         printf("Las combinaciones de %d objetos tomados %d a %d son ",n,m,m);
         printf("\n%ld",combinaciones(n,m));
    break;

    case 7:printf("\n");
        printf("**Enfoque de probabilidad clasico**");
        printf("\ncuantas veces puede ocurrir el evento?\n");
	scanf("%i",&x);
		printf("\ntotal de formas en las que se puede realizar el experimento \n");
	scanf("%d",&N);
	 clasico=x/N;
		printf("la probabilidad de que pueda  ocurrir el evento es: %.3f",clasico);

		break;
		case 8: printf("\n");
		    printf("**Enfoque de probabilidad empirico**");
			printf("numero de veces que ocurrio el evento \n");
				scanf("%i",&x);
		printf("numero de formas en las que se realizo  el experimento \n");
	scanf("%d",&N);
	 empirico=x/N;
		printf("la probabilidad de que vuelva a ocurrir el evento es :%.3f",empirico);
		break;

	 case 9:printf("\n");
	        printf("**Regla general de adicion**");
			printf("\nintroduce la P(A)= \n");
				scanf("%f",&A);
				while(A>1||A<0){
                    printf("La probabilidad debe de ser menor a 1");
                    printf("\nintroduce la P(A)= \n");
				scanf("%f",&A);}
		printf("\nintroduce la P(B)= \n");
		scanf("%f",&B);
		while(B>1||B<0){
            printf("La probabilidad debe de ser menor a 1");
            printf("\nintroduce la P(B)= \n");
		    scanf("%f",&B);}

		printf("\nintroduce la probabilidad de A interseccion B,P(AnB)=");
		scanf("%f",&c);
		while(c>1||c<0)
            printf("La interseccion debe de ser menor a 1");
            printf("\nintroduce la probabilidad de A interseccion B,P(AnB)=");
            scanf("%f",&c);
        d=(A+B)-c;
		if(d<0||d>1)
            printf("No se mostrara la P(AuB), ya que el este resultado es menor a cero o bien mayor a 1");
        else
			printf("\nP(AuB)=%.3f",d);
			break;

	 case 10:printf("\n");
            printf("**Probabilidad condicional**");
			printf("\nintroduce la probabilidad de A P(A1):");
				scanf("%f",&A2);
				printf("\nintroduce la probabilidad de A2 P(A2)");
				scanf("%f",&A);
				while((A+A2)>1){
                    printf("P(A1) y P(A2) debe ser menor o bien igual a 1.");
                    printf("\nintroduce la probabilidad de A P(A1):");
				scanf("%f",&A2);
				printf("\nintroduce la probabilidad de A2 P(A2)");
				scanf("%f",&A);
				}
				printf("\nconoces la interseccion?\n");
			printf("s) si \nn) no\n");
			scanf("%s",&q);
			if(q=='s'){
			printf("\nintroduce la probabilidad de A1 interseccion A2 P(A1nA2): ");
			scanf("%f",&B);
			d=(B/A);
			if(d>1)
                printf("La P(A1|A2) es mayor a 1");
            else
			printf("P(A1|A2)= %.3f",d);
			}if(q=='n'){

			x=A2*A;
			e=(A2+A)-x;
			d=(e/A);
			if(d>1)
                printf("La P(A1|A2) es mayor a 1");
            else
			printf("\nP(A1|A2)=%.3f",d );}
				break;
        case 11:printf("\n");
                printf("**Regla genera de multiplicacion**");
                printf("\nintroduce la probabilidad de a tal que b P(A|B)= ");
				scanf("%f",&A);
			printf("\nintroduce la probabilidad b P(B)= ");
			scanf("%f",&B);
			d=(B*A);
				printf("\nP(AnB)= %.3f",d );
				break;

		case 12:printf("\n");
                printf("***Probabilidad total");
                printf("\nDivisiones del espacio muestral\n");
                scanf("%i", &z);
                for (a=0;a<z;a++){
                        printf("B%i\n", a+1);
                scanf("%f", &y[a]);r=r+y[a];
                printf("\n(A|B%i)\n", a+1);
                scanf("%f", &v[a]);
                l=y[a]*v[a];
                o=o+l;

                }
                if(r>1||r<0){
                    printf("No puedes continuar, ya que la suma de las P(B) debe de ser menor o igual a 1");
                }
                else
                printf("\nLa probablilidad total de A es P(A)=%f", o);
                getche();
                break;

        case 13:printf("\n");
            printf("\n**Teorema de Bayes**");
            printf("\nDivisiones del espacio muestral\n");
            	scanf("%i", &z);
            	for (a=0;a<z;a++){
            	    printf("P(B%i)\n", a+1);
                scanf("%f", &y[a]);
                printf("\nP(A|B%i)\n", a+1);
                scanf("%f", &v[a]);
                l=y[a]*v[a];
                o=o+l;
                }
                printf("\nLos resultados son:");
                for (a=0;a<z;a++){
                        l=y[a]*v[a];
                w[a]=l/o;
                printf("\nP(B%i|A)= %f\n", a+1, w[a]);
                }
                getch();
            break;


       case 14:printf("\n");
            printf("\n**Medidas de tendencia central**");
            // Solicitar los numeros para rellenar el vector
            printf("\nIntroduce los valores para de estos obtengas la Moda,Media y Mediana");
            printf("\nTiene como maximo 15 valores");
            printf("\n");
            for(contador=0;contador<MAX;contador++) {
                    printf("No. %d : ",contador+1);
            scanf(" %d",&numeros[contador]);
            }
            // Visualizar los elementos introducidos en el vector
            printf("\nElementos del vector : ");
             for(contador=0;contador<MAX;contador++) {
                    printf(" %d",numeros[contador]);
             }
             // Calcular la moda
             for(contador=0;contador<MAX;contador++) {
                    auxiliar[contador]=0;
             }
             for(contador=0;contador<MAX;contador++) {
                    numero = numeros[contador];
             posicion = contador;
             for(contador2=contador;contador2<MAX;contador2++) {
                  if(numeros[contador2]==numero) auxiliar[posicion]++;
                  }
                  }

                   mayor=auxiliar[0];
                   posicionmayor = 0;
                   for(contador=0;contador<MAX;contador++) {
                        if(auxiliar[contador]>mayor) {
                            posicionmayor=contador;
                            mayor=auxiliar[contador];
                             }
                              }
                              printf("\nMODA : %d",numeros[posicionmayor]);
                              // CALCULO DE LA MEDIANA
                              bandera=0;
                               for(contador=MAX;contador>0 && bandera==0;contador--){
                                    bandera=1;
                               for(contador2=0;contador2<contador;contador2++) {
                                    if(numeros[contador2]>numeros[contador2+1]) {
                                        numero = numeros[contador2];
                               numeros[contador2] = numeros[contador2+1];
                               numeros[contador2+1]=numero;
                               bandera=0;
                               }
                            }
                        }
                        printf("\nElementos del vector : ");
                        for(contador=0;contador<MAX;contador++) {
                                printf(" %d",numeros[contador]);
                        }
                        if(MAX%2!=0) {
                                printf("\nEL valor de la mediana es : %d",numeros[MAX/2]);
                                 } else {
                                     printf("\nEL valor 1 de la mediana es : %d",numeros[MAX/2]);
                        printf("\nEL valor 2 de la mediana es : %d",numeros[(MAX/2)-1]);
                        }
                        // Calcular la media
                        suma = 0;
                        for(contador=0;contador<MAX;contador++) {
                            suma+=numeros[contador];
                            }
                            printf("\nMEDIA : %.2f\n",suma/MAX);
                            return 0;

        case 15:printf("\n");
            int V[50];
            int i,n;
            float suma, suma2, media, varianza, desv_estandar,prom;
            double rango;
            float Mayor=0, Menor=0;
            printf("\n**Medidas de dispersion para datos no agrupados**");
            printf("\nNumeros de datos que desea introducir: ");
            scanf("%i",&n);
              for(i=0; i<n; i++){
                    printf("Valor %i= ",i+1);
                    scanf("%i",&V[i]);
                    suma=suma+V[i];
                    suma2=suma2+(V[i]*V[i]);
                   if (i==0){
                        Menor=Mayor=V[i];
                   }
                   if (V[i]<Menor){
                       Menor=V[i];
                   }
                   if (V[i]>Mayor)
                    {
                        Mayor=V[i];
                   }
                }
                rango=Mayor-Menor;

                prom=suma/n;
            varianza=((n*suma2)-(suma*suma))/(n*(n-1));
            printf("\nVarianza %.5f",varianza);
            desv_estandar=sqrt(varianza);
            printf("\nDesviacion estandar= %.5f",desv_estandar);
            printf("\nValor mayor= %.2f",Mayor);
            printf("\nValor menor= %.2f",Menor);
            printf("\nRango=%f",rango);
            printf("\nCoeficiente de variacion=%f",desv_estandar/prom);
            break;

        case 16:
            do{
       NumeroDatos(&N_datos);
       datos=(REAL*)malloc((N_datos+1)*sizeof(REAL));
       RegistrarDatos(datos,N_datos);
       RevisaCorrige(datos,N_datos);
       CalculaParametro(&parametro,datos,N_datos);
       CalculaTendencia(&tendencia,datos,N_datos);
       DefinirLimites(&limites,datos,&parametro);
       CalcularFrecuencia(datos,&limites,&parametro,N_datos,&frecuencia);
       Resultado(datos,N_datos,&parametro,&limites,&tendencia,&frecuencia);
       pausar();
       do{
           printf("\nDESEA EVALUAR OTRO CONJUNTO (s/n): ");scanf("%c",&resp);fflush(stdin);
           resp=toupper(resp);
       }while(resp!='S'&&resp!='N');
    }while(resp=='S');
    pausar();

            break;

            }

        }
    }