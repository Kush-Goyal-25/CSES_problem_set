import java.io.*;
import java.util.*;

public class playlist {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine()); // Number of songs
        long[] songs = new long[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        for (int i = 0; i < n; i++) {
            songs[i] = Long.parseLong(st.nextToken());
        }

        Set<Long> uniqueSongs = new HashSet<>();
        int start = 0, maxLength = 0;

        for (int end = 0; end < n; end++) {
            while (uniqueSongs.contains(songs[end])) {
                uniqueSongs.remove(songs[start]);
                start++;
            }
            uniqueSongs.add(songs[end]);
            maxLength = Math.max(maxLength, end - start + 1);
        }

        System.out.println(maxLength);
    }
}
