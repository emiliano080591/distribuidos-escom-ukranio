#include<stdio.h>

int main(){
    char caracter=0;
    int entero=0;
    float flotante=0;
    long largo=0;
    double doble=0;

    printf("Dir de char %p\n",&caracter);
    printf("Dir de entero %p\n",&entero);
    printf("Dir de flotante %p\n",&flotante);
    printf("Dir de largo %p\n",&largo);
    printf("Dir de doble %p\n",&doble);

    printf("Tam de char %ld\n",sizeof(caracter));
    printf("Tam de entero %ld\n",sizeof(entero));
    printf("Tam de flotante %ld\n",sizeof(flotante));
    printf("Tam de largo %ld\n",sizeof(largo));
    printf("Tam de doble %ld\n",sizeof(doble));
    char *pcaracter=&caracter;
    int *pentero;
    float *pflotante;
    long *plong;
    double *pdouble;

    printf("Tam de apuntador caracter %ld\n",sizeof(pcaracter));
    printf("Tam de apuntador entero %ld\n",sizeof(pentero));
    printf("Tam de apuntador flotante %ld\n",sizeof(pflotante));
    printf("Tam de apuntador long %ld\n",sizeof(plong));
    printf("Tam de apuntador double %ld\n",sizeof(pdouble));

    printf("Caracter apuntador %p\n",&caracter);
    printf("Contenido apuntador %p\n",pcaracter);

    char cadena[]="ESCOM-IPN";
    for(int i=0;i<9;i++){
        printf("%p\n",&cadena[i]);
    }

    int valor=1234567890;
    printf("%d\n",valor);
    printf("%x\n",valor);

    valor=-1234567890;
    printf("%d\n",valor);
    printf("%x\n",valor);
    return 0;
}