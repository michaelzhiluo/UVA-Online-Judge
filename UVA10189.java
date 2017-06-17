import java.util.*;

class UVA10189{
	static String [][] output;
	static int fieldnum=1;
	public static void main(String [] args){
		@SuppressWarnings("resource")
		Scanner s = new Scanner(System.in);
		try{
		while(true){
			int a = s.nextInt();
			int b = s.nextInt();
			if(a==0 && b==0){
				break;
			}
			output = new String[a][b];
			for(int i=0; i<a; i++){
				String temp = s.next();
				for(int j=0; j<b; j++){
					output[i][j] = temp.substring(j,  j+1);
				}
			}
			if(fieldnum!=1){
				System.out.println("\nField #" + fieldnum + ":");
			}else{
				System.out.println("Field #" + fieldnum + ":");
			}
			fieldnum++;
			for(int i=0; i<a; i++){
				for(int j=0; j<b; j++){
					String temp = output[i][j];
					if(temp.equals(".")){
						output[i][j] = "" + mineneighbors(i, j);
						System.out.print(output[i][j]);
					}
					else if(temp.equals("*")){
						System.out.print(output[i][j]);
					}
					else{
						System.exit(0);
					}
				}
				System.out.println();
			}
		} System.out.close();}catch(Exception e){}
	}
	
	public static int mineneighbors(int i, int j){
		int counter=0;
		HashMap<Integer, int[]> temp = new HashMap<Integer, int[]>();
		temp.put(1, new int [] {-1, -1}); temp.put(2, new int [] {-1, 0}); temp.put(3, new int [] {-1, 1});
		temp.put(4, new int [] {0, 1}); temp.put(5, new int [] {1, 1}); temp.put(6, new int [] {1, 0});
		temp.put(7, new int [] {1, -1}); temp.put(8, new int [] {0, -1});
		if(i==0){
			temp.get(1)[0]=0; temp.get(1)[1]=0;
			temp.get(2)[0]=0; temp.get(2)[1]=0;
			temp.get(3)[0]=0; temp.get(3)[1]=0;
		}
		else if(i==output.length-1){
			temp.get(5)[0]=0; temp.get(5)[1]=0;
			temp.get(6)[0]=0; temp.get(6)[1]=0;
			temp.get(7)[0]=0; temp.get(7)[1]=0;
		}
		
		if(j==0){
			temp.get(1)[0]=0; temp.get(1)[1]=0;
			temp.get(7)[0]=0; temp.get(7)[1]=0;
			temp.get(8)[0]=0; temp.get(8)[1]=0;
		}
		else if(j==output[0].length-1){
			temp.get(3)[0]=0; temp.get(3)[1]=0;
			temp.get(4)[0]=0; temp.get(4)[1]=0;
			temp.get(5)[0]=0; temp.get(5)[1]=0;
		}
		
		for(int[] gg: temp.values()){
			if(output[i+ gg[0]][j+gg[1]].equals("*")){
				counter++;
			}
		}
		return counter;
	}
}
