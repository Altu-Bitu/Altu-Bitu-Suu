import java.io.*;
import java.util.StringTokenizer;
public class Backtracking2580 {
	static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	
	static int[][] blankLocation;
	
	static int zeroCount;
	
	private static boolean probability (int[] answer, int location, int[][] sudoku) {
		int x = blankLocation[location][0];
		int y = blankLocation[location][1];

		//가로체크
		for(int i = 0 ; i < 9 ; i ++) {
			if(i==y) continue;
			if(sudoku[x][i] == answer[location])
				return false;
		}
		
		//세로체크
		for(int i = 0 ; i < 9 ; i ++) {
			if(i==x) continue;
			if(sudoku[i][y] == answer[location])
				return false;
		}
		
		int set_row = (x / 3) * 3; // value가 속한 3x3의 행의 첫 위치
		int set_col = (y / 3) * 3; // value가 속한 3x3의 열의 첫 위치
 
		for (int i = set_row; i < set_row + 3; i++) {
			for (int j = set_col; j < set_col + 3; j++) {
				if (i==x && j==y) continue;
				if (sudoku[i][j] == answer[location]) {
					return false;
				}
			}
		}

		
		return true;
	}
	
	private static void dfs(int index, int[] answer, int[][] sudoku) throws IOException { //index = 현재 단계
		if(index!=0) {
			if(!probability(answer, index-1, sudoku)) {
				return;
			}
		}

		if(index == zeroCount) {

			for(int i = 0 ; i < zeroCount ; i++) {
				sudoku[blankLocation[i][0]][blankLocation[i][1]]=answer[i];
			}
			
			//답안 출력
			for(int i = 0 ; i < 9 ; i++) {
				for(int j = 0 ; j < 8 ; j++) {
					bw.write(Integer.toString(sudoku[i][j]) + " ");
				}
				bw.write(sudoku[i][8] + "\n");
			}	

			bw.flush();
			System.exit(0);
			return;
		}
		
		for(int i = 1; i <= 9; i++) {
			answer[index] = i;
			sudoku[blankLocation[index][0]][blankLocation[index][1]]= i ;
			dfs(index+1, answer, sudoku);
			sudoku[blankLocation[index][0]][blankLocation[index][1]]= 0 ;

		}
	}
	
	public static void main(String[] args) throws IOException{
		int[][] sudoku = new int[9][9];
		
		zeroCount = 0;
		for(int i = 0 ; i < 9 ; i++) {
			String a = bf.readLine();
			StringTokenizer st = new StringTokenizer(a);
			for(int j = 0 ; j < 9 ; j++) {
				sudoku[i][j] = Integer.parseInt(st.nextToken());
				if(sudoku[i][j]==0)
					zeroCount++;
			}
		}
		
		
		blankLocation = new int[zeroCount][2]; //빈칸의 좌표 (행,열)
		int a = 0;
		for(int i = 0 ; i < 9 ; i++) {
			for(int j = 0 ; j < 9 ; j++) {
				if(sudoku[i][j]==0) {
					blankLocation[a][0] = i;
					blankLocation[a][1] = j;
					a++;
				}
			}
		}
		
		int[] answer = new int[zeroCount]; //답안을 모아놓을 배열.
		dfs(0, answer, sudoku);
		
		bw.close();
		
	}
}