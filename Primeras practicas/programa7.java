import java.util.Random;

class programa7 
{ 
    
    
    public static void main(String args[]) 
    { 
        String cadenaChica = "";
        String cadenaGrande = "";
        int count=0;
        Random rnd = new Random();

        for(int j=0;j<1000000;j++){
            for (int i = 0; i < 3; i++)
            {
            cadenaChica += (char)(65+rnd.nextInt( (90+1) - 65));
            }
            cadenaGrande+=cadenaChica+" ";
            cadenaChica="";
        }

        String partes[]=cadenaGrande.split(" ");
        //System.out.println(cadenaGrande);
        for(int i=0;i<partes.length;i++){
            if(partes[i].equals("IPN"))
                count++;
        }   

        System.out.println("Se encontro IPN "+count+" veces.");
    }//fin de main 
} //fin de la clase