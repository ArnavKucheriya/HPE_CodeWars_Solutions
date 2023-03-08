import java.util.Scanner;
import java.math.*;
public class prob09 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int minions = in.nextInt(); //Number of Minions.
        double radiusCockpit = in.nextDouble(); //Radius of the Cockpit.
        double radiusBody = in.nextDouble(); //Radius of the Body.
        double heightBody = in.nextDouble(); //Height of the Body.
        double length = in.nextDouble(); //Length of the Aircraft.
        double width = in.nextDouble(); //Width of the Aircraft.
        double height = in.nextDouble(); //Height of the Aircraft.

        /*
        Aircraft Specifications:
        Cockpit : Spherical
        Body : Cylindrical
        Storage pods x2 : Pyramids

        Space required by Minions : 1.20 m^3
        Space required by Gru (Cockpit): 2.20 m^3
        Space required by Control (Cockpit): 4.10 m^3
        Space required by Jet Engine (Body): 12.10 m^3

        Storage pod is empty -> Minions can fit inside.
         */

        System.out.printf("Cockpit %.2f%n", cockpit(radiusCockpit));
        System.out.printf("Body %.2f%n", body(radiusBody, heightBody));
        System.out.printf("Pods %.2f%n", storage(length, width, height));
        System.out.printf("Minions Need %.2f%n", minionSpace(minions));

        double actualSpaceChecker = (cockpit(radiusCockpit)) + (body(radiusBody, heightBody)) + (storage(length, width, height));
        if (Math.round(actualSpaceChecker) >= minionSpace(minions)) {
            System.out.println("PLAN ACCEPTED");
        }
        if (Math.round(actualSpaceChecker) < minionSpace(minions)) {
            System.out.println("PLAN REJECTED");
        }
    }
    public static double cockpit(double radiusCockpit){
        double v = Math.PI * (Math.pow(radiusCockpit, 3));
        double frac = 4.0/3.0 ;
        double radiusCockpitFinal = (frac * v) - 6.30; //Subtracting space for Gru and Controls.
        return radiusCockpitFinal;
    }
    public static double body(double radiusBody, double heightBody){
        double v = Math.PI * (Math.pow(radiusBody, 2));
        double bodyFinal = (heightBody * v) - 12.10; //Subtracting space required for Jett engines.
        return bodyFinal;
    }
    public static double storage(double length, double width, double height){
        double v = length * width * height;
        double frac = 1.0/3.0;
        double storageFinal = ((v)*(frac))*2 ;
        return storageFinal;
    }
    public static double minionSpace(int minions){
        double minionsSpace = (1.20) * minions;
        return minionsSpace;
    }

}
