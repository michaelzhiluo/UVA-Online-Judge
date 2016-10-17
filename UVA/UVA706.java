import java.util.*;

public class UVA706{
	
	// type 0: {}. type 1: {---}, type 2:{|   }, type 3: {   |}, type 4: {|     |}
	static int gg[][] = 
		{		{1, 4, 0, 4, 1}, // 0
				{0, 3, 0, 3, 0}, // 1
				{1, 3, 1, 2, 1}, //2 
				{1, 3, 1, 3, 1}, //3
				{0, 4, 1, 3, 0}, //4
				{1, 2, 1, 3, 1}, //5
				{1, 2, 1, 4, 1}, //6
				{1, 3, 0, 3, 0}, //7
				{1, 4, 1, 4, 1}, //8 
				{1, 4, 1, 3, 1}, //9
		};
	static char[][][] nums;
	
	public static void main(String [] args){
		@SuppressWarnings("resource")
		Scanner s = new Scanner(System.in);
		try{
			while(true){
				int n = s.nextInt();
				String x = s.next();
				if(n==0){
					System.exit(0);
				}
				int[] lol = new int[("" + x).length()];
				nums = new char[lol.length][2*n+3][n+3];
				// reversed b/c too lazy to change
				for(int i=0; i<lol.length; i++){
					lol[i] = Integer.parseInt(x.substring(i,  i+1));
				}
				
				for(int i=0; i<lol.length; i++){
					int temp = lol[i];
					//0th row
					switch(gg[temp][0]){
					case 0: type0(n, i,0); break;
					case 1: type1(n, i, 0); break;
					case 2: type2(n, i, 0); break;
					case 3: type3(n, i, 0); break;
					case 4: type4(n, i, 0); break;
					}
					//1st to nth row
					for(int j=1; j<=n; j++){
						switch(gg[temp][1]){
						case 0: type0(n, i,j); break;
						case 1: type1(n, i, j); break;
						case 2: type2(n, i, j); break;
						case 3: type3(n, i, j); break;
						case 4: type4(n, i, j); break;
						}
					}
					// n+1st row
					switch(gg[temp][2]){
					case 0: type0(n, i,n+1); break;
					case 1: type1(n, i, n+1); break;
					case 2: type2(n, i, n+1); break;
					case 3: type3(n, i, n+1); break;
					case 4: type4(n, i, n+1); break;
					}
					// n+2 to 2n+1
					for(int j=n+2; j<=2*n+1; j++){
						switch(gg[temp][3]){
						case 0: type0(n, i,j); break;
						case 1: type1(n, i, j); break;
						case 2: type2(n, i, j); break;
						case 3: type3(n, i, j); break;
						case 4: type4(n, i, j); break;
						}
					}
					// 2n+2 row
					switch(gg[temp][4]){
					case 0: type0(n, i,2*n+2); break;
					case 1: type1(n, i, 2*n+2); break;
					case 2: type2(n, i, 2*n+2); break;
					case 3: type3(n, i, 2*n+2); break;
					case 4: type4(n, i, 2*n+2); break;
					}		
				}
				char[][] print = new char[2*n+3][(n+3)*lol.length];
				for(int i=0; i<print.length; i++){
					for(int j=0; j<print[0].length; j++){
						print[i][j] = nums[j/(n+3)][i][j%(n+3)];
					}
				}
				for(int i=0; i<print.length; i++){
					String temp = "";
					for(int j=0; j<print[0].length-1; j++){
						temp = temp + print[i][j];
					}
					System.out.println(temp);
				}
				System.out.println();

			}
		}
		catch(Exception e){}
	}
	// i is index of number, j are the rows of the number
	public static void type0(int n,int i, int j){
		for(int k=0; k<n+3; k++){
			nums[i][j][k] = ' '; 
		}
	}
	
	public static void type1(int n, int i, int j){
		nums[i][j][0] = ' ';
		for(int k=1; k<n+1; k++){
			nums[i][j][k] = '-'; 
		}
		nums[i][j][n+1] = ' ';
		nums[i][j][n+2] = ' ';
	}	
	
	public static void type2(int n, int i, int j){
		nums[i][j][0] = '|';
		for(int k=1; k<n+3; k++){
			nums[i][j][k] = ' '; 
		}
	}
	
	public static void type3(int n, int i, int j){
		for(int k=0; k<n+3; k++){
			nums[i][j][k] = ' '; 
		}
		nums[i][j][n+1] = '|';
	}
	
	public static void type4(int n, int i, int j){
		for(int k=0; k<n+3; k++){
			nums[i][j][k] = ' '; 
		}
		nums[i][j][0] = '|';
		nums[i][j][n+1] = '|';
	}	
	
	
}
