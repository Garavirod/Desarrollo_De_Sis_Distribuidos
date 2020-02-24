import java.util.Random;
class Rendimiento {

    private int n;
    private StringBuilder cadenota = new StringBuilder("");

    public Rendimiento (int n){
        this.n=n;
    }

    public StringBuilder generaWord() {
        StringBuilder t = new StringBuilder("");
        char w1 = (char) (Math.random() * (90 - 65 + 1) + 65);
        char w2 = (char) (Math.random() * (90 - 65 + 1) + 65);
        char w3 = (char) (Math.random() * (90 - 65 + 1) + 65);
        t.append(w1+""+w2+""+w3);
        return t;
    }

    public int getOcurrencias(){
        int c=0;  
        int idx = this.cadenota.indexOf("IPN");
        while(idx != -1){
            c++;
            idx = this.cadenota.indexOf("IPN", idx+3);
        }
        return c;
    }

    public void genCadenota(){
        for(int i=0; i<n; i++)
            this.cadenota.append(generaWord()+" ");                        
    }
    
    public static void main(String[] args) {
        Rendimiento r = new Rendimiento(1000000);
        r.genCadenota();               
        System.out.println(r.getOcurrencias());
    }
}