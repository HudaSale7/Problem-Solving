import java.awt.*;
import java.util.*;
import java.util.Comparator;

interface IPlayersFinder {
    java.awt.Point[] findPlayers(String[] photo, int team, int threshold);
}

class Teams {
    public int count = 1;
    public int maxRow;
    public int maxCol;
    public int minRow;
    public int minCol;

    Teams(int i , int j){
        maxRow = i;
        minRow = i;
        maxCol = j;
        minCol = j;
    }

    public int getArea() {
        return 4 * this.count;
    }
}

public class PlayersFinder implements IPlayersFinder{

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String[] dimS = scan.nextLine().replace(" " , "").split(",") ;
        int rows =  Integer.parseInt(dimS[0]);
        int cols =  Integer.parseInt(dimS[1]);
        String[] photo = new String[rows];
        for(int i =0 ; i < rows ; i++){
            photo[i] = scan.nextLine();
        }
        int target = scan.nextInt();
        int minArea = scan.nextInt();
        Point[] p = new PlayersFinder().findPlayers(photo , target , minArea);

        Arrays.sort(p, new Comparator<java.awt.Point>() {
            public int compare(java.awt.Point a, java.awt.Point b) {
                int xComp = Integer.compare(a.x, b.x);
                if(xComp == 0)
                    return Integer.compare(a.y, b.y);
                else
                    return xComp;
            }
        });

        System.out.print("[");
        for (int i = 0; i < p.length; i++) {
            System.out.print("(" + (int)p[i].getX() + ", " + (int)p[i].getY() + ")");
            if(i != p.length - 1)
                System.out.print(", ");
        }

        System.out.print("]");
    }


    public java.awt.Point[] findPlayers(String[] photo, int team, int threshold){
        int row = photo.length;
        int col = photo[0].length();
        ArrayList<Teams> validTeams = new ArrayList<>();
        int[][] visited = new int[row][col];
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(photo[i].charAt(j) == ('0' + team) && visited[i][j] == 0){
                    visited[i][j] = 1 ;
                    Teams newTeam = new Teams(i , j);
                    check(newTeam, i , j , team , photo ,visited);
                    if(newTeam.getArea() >= threshold) {
                        validTeams.add(newTeam);
                    }
                }
            }
        }
        Point[] p = new Point[validTeams.size()];
        int i = 0;
        for (Teams t : validTeams) {
            int y = (((t.maxRow * 2 + 2) - (t.minRow * 2)) / 2) + (t.minRow * 2) ;
            int x = (((t.maxCol * 2 + 2) - (t.minCol * 2)) / 2) +  (t.minCol * 2) ;
            Point center = new Point(x, y);
            p[i] = center;
            i++;
        }
        return p;
    }


    public void check(Teams teams, int x , int y , int team , String[] photo , int[][] visited ){
        for (int i = x - 1 ; i <= x + 1 ; i ++){
            for (int j = y - 1 ; j <= y + 1 ; j++){

                if((i == x - 1 || i == x + 1) && (j == y - 1 || j == y + 1)) continue;

                if(i < 0 || i >= photo.length || j < 0 || j >= photo[0].length()) continue;

                if(photo[i].charAt(j) == ('0' + team) && visited[i][j] == 0) {
                    visited[i][j] = 1;
                    teams.count++;
                    teams.maxRow = Math.max(i, teams.maxRow);
                    teams.minRow = Math.min(i, teams.minRow);
                    teams.maxCol = Math.max(j, teams.maxCol);
                    teams.minCol = Math.min(j, teams.minCol);
                    check(teams, i , j , team , photo ,visited);
                }
            }
        }
    }

}


