import java.util.*;

public class Party {
	static Scanner sc = new Scanner(System.in);
	static int N = sc.nextInt();
	static int M = sc.nextInt();
	static int X = sc.nextInt();
	static int[][] weight = new int[N+1][N+1];
	
	static int distanceToS[] = new int[N+1]; //X->start까지 최단거리 
	static int distanceToX[] = new int[N+1]; //start->X까지 최단거리
	
   //start->X까지 최단거리 구하기
   public static void dijkstraToX(int start){
        boolean[] visited = new boolean[N+1]; //방문체크
        
        // 초기화
        for(int i = 0 ; i <= N ; i++){
            distanceToX[i] = 100*N;
        }
        distanceToX[start] = 0;
        visited[start] = true;
         
        //X -> start까지의 거리 초기화 
        for(int i = 1 ; i <= N ; i++){ 
            if(!visited[i] && weight[start][i] !=0){
                distanceToX[i] = weight[start][i];
            }
        }
         
        for(int i = 0 ; i < N-1 ; i++){
            int localMin = 100*N;
            int minIndex= -1;
            
            // 시작점으로부터 가장 가까운 노드 찾기
            for(int j = 1 ; j <= N ; j++){
            	if(!visited[j] && distanceToX[j] != 100*N){
                    if( distanceToX[j] < localMin ){
                        localMin = distanceToX[j];
                        minIndex = j;
                    }
                }
            }
            
            //방문표시
            visited[minIndex] = true;
            
            if(minIndex==X) {
            	distanceToS[start] += distanceToX[minIndex];
            	return;            	
            }
            
            // 거리 갱신
            for(int j = 1 ; j <= N ; j++){
                if(!visited[j] && weight[minIndex][j]!=0){
                    if(distanceToX[j] > distanceToX[minIndex] + weight[minIndex][j]){
                        distanceToX[j] = distanceToX[minIndex] + weight[minIndex][j];
                    }
                }
            }
 
        }
    }
		
   
    // X부터 Start까지 최단거리 구하기
    public static void dijkstraToS(){
        boolean[] visited = new boolean[N+1]; //방문체크

        //초기화
        for(int i = 0 ; i <= N ; i++){
            distanceToS[i] = 100*N;
        }
        distanceToS[X] = 0;
        visited[X] = true;
         
        //X -> start까지의 거리 초기화
        for(int i = 1 ; i <= N ; i++){
            if(!visited[i] && weight[X][i] !=0){
                distanceToS[i] = weight[X][i];
            }
        }
         
        for(int i = 0 ; i < N-1 ; i++){
            int localMin = 100*N;
            int minIndex= -1;
             
            for(int j = 1 ; j <= N ; j++){
            	if(!visited[j] && distanceToS[j] != 100*N){
                    if( distanceToS[j] < localMin ){
                        localMin = distanceToS[j];
                        minIndex= j;
                    }
                }
            }
            
            //방문 표시
            visited[minIndex] = true;
            
            //거리 갱신
            for(int j = 1 ; j <= N ; j++){
                if(!visited[j] && weight[minIndex][j]!=0){
                    if(distanceToS[j] > distanceToS[minIndex] + weight[minIndex][j]){
                        distanceToS[j] = distanceToS[minIndex] + weight[minIndex][j];
                    }
                }
            }
 
        }
    }
    
	public static void main(String[] args){
		//가중치 입력 받기
		for(int i = 0 ; i < M ; i++)
		{
			int a = sc.nextInt();
			int b = sc.nextInt();
			int c = sc.nextInt();
			weight[a][b] = c;
		}

		dijkstraToS();
        // X->Start까지의 최단거리에 Start->X까지 최단 거리를 더하여 답을 구한다
		for(int i = 1 ; i <= N ; i++) { 
			if(i == X)
				continue;
			dijkstraToX(i);
		}

        //각 노드로부터 X까지의 왕복 거리 중 가장 큰 값을 구하기 위해 정렬한다.
		Arrays.sort(distanceToS);
		System.out.println(distanceToS[N-1]);
		
	}
}   