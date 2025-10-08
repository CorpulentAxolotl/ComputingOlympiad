import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Arrays;
public class JavaCode {
    public static void main(String[] args) {
        try{ //input reader needs this or it tweaks out
            long mPaid = 0; //initiate most paid
            long bTuition = 0; //initiate best tuition
            BufferedReader in = new BufferedReader(new InputStreamReader(System.in)); //input reader
            int N = Integer.parseInt(in.readLine()); //convert next line from string to integer
            StringTokenizer line = new StringTokenizer(in.readLine()); //split the line into "tokens"
            long[] cows = new long[N]; //list of cows
            for (int i = 0; i < N; i++) { //for all cows
                cows[i] = Integer.parseInt(line.nextToken()); //read integer values of tokens into cows
            }
            Arrays.sort(cows); //sort the cows by tuition from least to greatest
            for (int i = 0; i < N; i++) { //loop through all cow tuitions
                if (cows[i]*(N-i) > mPaid) { //check if total paid > most paid
                    mPaid = cows[i]*(N-i); //if so update most paid
                    bTuition = cows[i]; //and update best tuition
                }
            }
            System.out.println(mPaid + " " + bTuition); //print out answers
        } catch (IOException e) {
            //hopefully your code would be flawless but you can always just println(e)
        }
    }
}
