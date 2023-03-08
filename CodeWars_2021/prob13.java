import java.util.Scanner;

public class prob13 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String vehicle = in.nextLine();
        int rampLength = in.nextInt();
        float acceleration = in.nextFloat();
        float riverWidth = in.nextFloat();

        double time = Math.sqrt((2*(rampLength))/acceleration);
        double speed = time * acceleration;
        double distance =((Math.pow(speed,2)) / 9.805);

        if(distance<riverWidth-5){
            System.out.print(vehicle+" will reach a speed of\s");
            System.out.printf("%.2f",speed);
            System.out.print(" m/s on a "+rampLength+" meter ramp, crossing\s");
            System.out.printf("%.1f",distance);
            System.out.print(" of\s");
            System.out.printf("%.1f",riverWidth);
            System.out.print(" meters, SPLASH!");
        }
        else if(distance>=riverWidth-5 && distance<=riverWidth){
            System.out.print(vehicle+" will reach a speed of\s");
            System.out.printf("%.2f",speed);
            System.out.print(" m/s on a "+rampLength+" meter ramp, crossing\s");
            System.out.printf("%.1f",distance);
            System.out.print(" of\s");
            System.out.printf("%.1f",riverWidth);
            System.out.print(" meters, BARELY MADE IT!");        }
        else if(distance>riverWidth){
            System.out.print(vehicle+" will reach a speed of\s");
            System.out.printf("%.2f",speed);
            System.out.print(" m/s on a "+rampLength+" meter ramp, crossing\s");
            System.out.printf("%.1f",distance);
            System.out.print(" of\s");
            System.out.printf("%.1f",riverWidth);
            System.out.print(" meters, LIKE A BOSS!");        }
    }
}
