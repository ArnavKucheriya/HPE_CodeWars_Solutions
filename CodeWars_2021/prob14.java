import java.util.Scanner;

public class prob14 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int dynamite = in.nextInt();
        String dynamiteLength = in.next();
        int tensileLimit = in.nextInt();

        double dynamiteActualSize = 0;


        if(dynamiteLength.length()>1){
            double num , den;
            String[] frac = dynamiteLength.split("/");
            num = Double.parseDouble(frac[0]);
            den = Double.parseDouble(frac[1]);
            dynamiteActualSize = dynamite * (num/den);
        }
        else if(dynamiteLength.length()==1){
            double dynamitePow = Double.parseDouble(dynamiteLength);
            dynamiteActualSize = dynamite * dynamitePow;
        }

        double dynamiteWeight = (1.0/0.45);
        double dynamiteActualWeight = dynamiteActualSize / dynamiteWeight;
        double dynamitePower = dynamiteActualWeight * 7.5;

        if(tensileLimit>dynamitePower){
            System.out.printf("%.2f",dynamitePower);
            System.out.print("\sthe Mask can eat it!");
        }
        else if(tensileLimit<dynamitePower){
            System.out.printf("%.2f",dynamitePower);
            System.out.print("\sthe Mask should not eat it!");
        }
    }
}
