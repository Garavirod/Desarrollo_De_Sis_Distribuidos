import java.lang.Math;

public class programa {

	public static void main(String[] args) {

        int seno=0,coseno=0,tangente=0,logaritmo=0,raiz=0;
        double i = 0;	

        while(i < 1000000){
            seno += Math.sin(i);
            coseno += Math.cos(i);
            tangente += Math.tan(i);
            logaritmo += Math.log(i);
            raiz += Math.sqrt(i); 
            i++;
        }
		System.out.println("termine");
	}

}