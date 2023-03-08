import java.util.Objects;
import java.util.Scanner;

public class prob11 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String force = in.next();
        String forceVal = in.next();
        String constant = in.next();
        String constantVal = in.next();
        String distance = in.next();
        String distanceVal = in.next();
/*
     Creating a break point to debug.
       System.out.println(force + forceVal);
       System.out.println(constant + constantVal);
       System.out.println(distance + distanceVal);
 */
        double calc;

        if(Objects.equals(forceVal, "?")){
            calc = -Double.parseDouble(constantVal) * Double.parseDouble(distanceVal);
            System.out.print(force +" ");
            System.out.printf("%.2f",(calc));
        }
        else if(Objects.equals(constantVal, "?")){
            calc = Double.parseDouble(forceVal) / Double.parseDouble(distanceVal);
            System.out.print(constant+" ");
            System.out.printf("%.2f",(-calc));
        }
        else if(Objects.equals(distanceVal, "?")){
            calc = Double.parseDouble(forceVal) / -Double.parseDouble(constantVal);
            System.out.print(distance+" ");
            System.out.printf("%.2f",(calc));
        }
    }
}
