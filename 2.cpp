#include "estadisticas.h"

void pausar(void){
    printf("\n\n");
    system("pause");
}

void NumeroDatos(int *ptr){
	char buffer[10];
	int valor;
	do{
		system("cls");
	    do{
		   printf("NUMERO DE DATOS A REGISTRAR : ");fflush(stdin);gets(buffer);
	    }while(!validarEntero(buffer));
		  valor=atoi(buffer);
		  if(valor < MINIMO || valor>MAXIMO){
			printf("ERROR : VALOR FUERA DE RANGO (%d - %d)\n\n",MINIMO,MAXIMO);
			system("pause");
		}
	}while(valor < MINIMO || valor>MAXIMO);
	*ptr=valor;
}

REAL* RegistrarDatos(REAL *datos,int n){
	char buffer[20];

	int i=1;
	while(i<=n){
		do{
		   printf("DATO (%d) :",i);fflush(stdin);gets(buffer);
		}while(!validarNumero(buffer));
	    datos[i]=atof(buffer);
		i++;
	}
	return datos;
}

int validarNumero(char buffer[])
{
 int i=0,verdadero=1,puntos=0;
 while((buffer[i]!='\0')&&verdadero)
 {
   if(buffer[i]=='.'){puntos++;}
   if((buffer[0]=='-')||(buffer[i]=='1')||(buffer[i]=='.')||(buffer[i]=='2')||(buffer[i]=='3')||(buffer[i]=='4')||
   (buffer[i]=='5')||(buffer[i]=='6')||(buffer[i]=='7')||(buffer[i]=='8')||
   (buffer[i]=='9')||(buffer[i]=='0'))
     verdadero=1;
   else
     verdadero=0;
   i++;
 }
 if(puntos>1)
     return 0;
 return(verdadero);
}

void RevisaCorrige(REAL *datos,int n){
int i,valor;
char r,buffer[20],entero[20];

do{
   system("cls");
   i=1;
   printf("\t\t\tCONJUNTO DE DATOS\n\n");
   while(i<=n){
     printf("DATO(%d)=%.4f",i,datos[i]);
     if((i%4)==0){
         printf("\n");
     }else{
         printf("   ");
     }
     i++;
    }
   printf("\n");
   r='n';
    do{
	printf("\nDESEA CAMBIAR UN DATO : (s/n)");scanf("%s",&r);fflush(stdin);
	r=toupper(r);
    }while(r!='S' && r!='N');
	if(r=='S'){
  	  do{
	     printf("\nINGRESE NUMERO DE DATO A CAMBIAR : ");fflush(stdin);gets(entero);
	     if(validarEntero(entero)){
		valor=atoi(entero);
		if(valor==0 || valor > n){
		  printf("\nERROR: NO HAY VALOR %d\n\n",valor);
		}
		else{
		   printf("VALOR ACTUAL : %.4f\n",datos[valor]);
		   do{
		       printf("INGRESE NUEVO VALOR : ");fflush(stdin);gets(buffer);
		       if(!validarNumero(buffer)){
			 printf("\nENTRADA NO VALIDA !");
		       }
		     }while(!validarNumero(buffer));
		     datos[valor]=atof(buffer);
		}
	     }
	  }while(!validarEntero(entero));
	}
}while(r=='S');

}

void CalculaParametro(PARAMETRO *ptr,REAL *datos,int n){
	REAL max,min;
	int i;
	max=min=datos[1];
    for(i=1;i<=n;i++){
        if(max<datos[i]){max=datos[i];}
        if(min>datos[i]){min=datos[i];}
    }
     ptr->maximo=max;ptr->minimo=min;
     ptr->rango=max-min;
     ptr->intervalo=(int)(1+3.322*log10((double)(n)));
     ptr->amplitud=(ptr->rango)/(ptr->intervalo);
}

void CalculaTendencia(TENDENCIA *ptr,REAL *datos,int n){
    int i; REAL suma=0;
    /CALCULAR LA MEDIA/
    for(i=1;i<=n;i++){
        suma=suma+datos[i];
    }
    ptr->media=suma/n;
    suma=0;
    for(i=1;i<=n;i++){
        suma=suma+pow(datos[i]-ptr->media,2);
    }
    ptr->var=suma/(n-1);
    ptr->desv=pow(ptr->var,0.5);
}

void DefinirLimites(LIMITES *ptr,REAL *datos,PARAMETRO *param){
    int i;

    ptr->Lsup=(REAL*)malloc((param->intervalo+1)*sizeof(REAL));
    ptr->Linf=(REAL*)malloc((param->intervalo+1)*sizeof(REAL));
    if(ptr->Linf==NULL || ptr->Lsup==NULL){
        printf("\nERROR: INSUFICIENTE MEMORIA \n");system("pause");exit(-1);
    }
    for(i=1;i<=param->intervalo;i++){
        if(i==1){
            ptr->Linf[i]=param->minimo;
            ptr->Lsup[i]=ptr->Linf[i]+param->amplitud;
        }else{
          ptr->Linf[i]=ptr->Lsup[i-1];
          ptr->Lsup[i]=ptr->Linf[i]+param->amplitud;
        }
    }
}

void CalcularFrecuencia(REAL *datos,LIMITES *L,PARAMETRO *P,int n,FRECUENCIA *F){
    int i,j;
    F->frec=(int*)malloc((P->intervalo+1)*sizeof(int));
    F->frecA=(int*)malloc((P->intervalo+1)*sizeof(int));
    F->frecR=(REAL*)malloc((P->intervalo+1)*sizeof(REAL));
    F->frecRA=(REAL*)malloc((P->intervalo+1)*sizeof(REAL));
    if(F->frec==NULL || F->frecA==NULL || F->frecR==NULL ||F->frecRA==NULL){
        printf("\nERROR: INSUFICIENTE MEMORIA \n");system("pause");exit(-1);
    }
    for(i=0;i<=P->intervalo;i++){
        F->frec[i]=0;
        F->frecA[i]=0;
        F->frecR[i]=0;
        F->frecRA[i]=0;
    }
    for(i=1;i<=P->intervalo;i++){
        for(j=1;j<=n;j++){
            if(i!=(P->intervalo)){
                if((datos[j]>=L->Linf[i])&&(datos[j]<L->Lsup[i])){
                    F->frec[i]++;
                }
            }
            else{
                if(datos[j]>=L->Linf[i] && datos[j]<=L->Lsup[i]){
                    F->frec[i]++;
                }
            }
        }

        F->frecA[i]=F->frecA[i-1]+F->frec[i];
        F->frecR[i]=((float)(F->frec[i]))/n;
        F->frecRA[i]=F->frecRA[i-1]+F->frecR[i];
    }
}

void Resultado(REAL *datos,int n,PARAMETRO *P,LIMITES *L,TENDENCIA *T,FRECUENCIA *F){
    int i;
    system("cls");
    printf("\t\t\t * RESULTADO *\n");
    printf("CONJUNTO DE DATOS :\n\n");
    for(i=1;i<=n;i++){
        printf("DATO(%d)=%.4f",i,datos[i]);
        if((i%4)==0){
           printf("\n");
        }else{
           printf("   ");
        }
    }printf("\n\n");
    for(i=1;i<=80;i++){
        printf("-");
    }
    printf("\tINFORMACION DEL CONJUNTO:\n\n");
    printf("MAXIMO=%.4f    MINIMO=%.4f    RANGO : %.4f\n\n",P->maximo,P->minimo,P->rango);
    printf("NUMERO DE INTERVALOS=%d    AMPLITUD DE CLASE=%.4f\n\n",P->intervalo,P->amplitud);
    printf("MEDIA : %.4f\tVARIANZA(MUESTRAL) : %.4f\tDESVIACION(MUESTRAL) : %.4f\n\n",T->media,T->var,T->desv);
    for(i=1;i<=80;i++){
        printf("-");
    }
    printf("\t    TABLA DE FRECUENCIA\n");
    for(i=1;i<=80;i++){
        printf("_");
    }printf("\n");
    printf("\tCLASES\t\tFRECUENCIA  FREC.ACUM     F.RELATIVA \t  F.R.ACUM\n");
    for(i=1;i<=P->intervalo;i++){
        printf("[ %.4f - %.4f ]\t    %d\t\t",L->Linf[i],L->Lsup[i],F->frec[i]);
        printf("%d  \t    %.4f    \t   %.4f\n",F->frecA[i],F->frecR[i],F->frecRA[i]);
    }
}

int validarEntero(char buffer[]){
 int i=0,verdadero=1;
 while((buffer[i]!='\0')&&verdadero)
 {
   if((buffer[i]=='1')||(buffer[i]=='2')||(buffer[i]=='3')||(buffer[i]=='4')||
   (buffer[i]=='5')||(buffer[i]=='6')||(buffer[i]=='7')||(buffer[i]=='8')||
   (buffer[i]=='9')||(buffer[i]=='0'))
     verdadero=1;
   else
     verdadero=0;
   i++;
 }
 return(verdadero);
}