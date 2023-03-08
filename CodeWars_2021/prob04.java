/*
Qustion: You will receive the number of lines you will receive followed by #'s in a wave pattern.
Note, there are no flat parts to the waves. Max Size of the wave is 80x80.

TEST CASE 1:

7
   #
  # #         #
 #   #       # #   #
#     #     #   # #
       #   #     #
        # #
         #

TEST CASE 2:
8
#                 #
 #   #           # #           #
  # # #         #   #     #   # #
   #   #       #     #   # # #   #
        #     #       # #   #     #
         #   #         #           #
          # #                       #
           #
 */

import java.io.UnsupportedEncodingException;
import java.nio.charset.StandardCharsets;
import java.util.Scanner;
public class prob04 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int lines = in.nextInt();
        int printlines=lines;
        String[] wave = new String[lines+1];
        String win ="";

        while (in.hasNextLine()){
            for(int i=0; i<=lines;i++){
                win = in.nextLine();
                wave[i]=win;
            }
            break;
        }
        for(int j=0;j<lines;j++){
            System.out.println(wave[printlines]);
            printlines--;
        }
    }
}

