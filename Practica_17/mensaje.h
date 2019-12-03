#define TAM_MAX_DATA 65000

#define suma 1
#define resta 2
#define multiplicacion 3

struct mensaje{
    int messageType;  //0= Solicitud, 1 = Respuesta
    unsigned int requestId;  //Identificador del mensaje
    int operationId;  //Identificador de la operación
    char arguments[TAM_MAX_DATA];
};
