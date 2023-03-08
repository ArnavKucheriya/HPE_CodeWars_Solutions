import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.Scanner;
import java.lang.*;
public class prob02 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        double height=in.nextDouble();
        double radius=in.nextDouble();
        double volume=((Math.PI)*(Math.pow(radius,2))*(height));
        System.out.printf("%.2f",volume);
        System.out.print("\scubic inches");

    }
}
