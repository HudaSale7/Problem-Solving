import java.util.HashMap;

public class Solution {

    public static int solution(int[] x, int[] y) {
        HashMap<Integer, Integer> m = new HashMap<>();
        for (int j = 0; j < x.length; j++) {
            int count = m.getOrDefault(x[j], 0);
            m.put(x[j], 1 + count);
        }
        for (int i = 0; i < y.length; i++) {
            if(!m.containsKey(y[i])) {
                return y[i];
            } else {
                m.replace(y[i], m.get(y[i]), m.get(y[i]) - 1);
            }
        }
        for (int i : m.keySet()) {
            if(m.get(i) > 0) return i;
        }
        return 1;
    }
}

