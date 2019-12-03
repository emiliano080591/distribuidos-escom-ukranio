class calculo 
{ 
    
    public static void main(String args[]) 
    { 
        double i=0,seno=0,coseno=0,tangente=0,logaritmo=0,raiz=0;
        while(i<10000000000000000000){
            seno+=Math.sin(i);
            coseno+=Math.cos(i);
            tangente+=Math.tan(i);
            logaritmo+=Math.log(i);
            raiz+=Math.sqrt(i);
            i++;
        } 
    } 
} 