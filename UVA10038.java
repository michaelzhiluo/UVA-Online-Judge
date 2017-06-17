import java.util.ArrayList;
import java.util.Scanner;
import java.util.StringTokenizer;
class UVA10038{
	static Scanner s = new Scanner(System.in);
	static ArrayList<Integer> l;
	static boolean jolly = true;
	public static void main(String [] args){
		try{
			while(true){
				jolly = true;
				l = new ArrayList<Integer>();
				int n = s.nextInt();
				for(int i=0; i<n; i++){
					l.add(s.nextInt());
				}
				boolean[] temp1 = new boolean[3001];
				while(l.size()>=2){
					temp1[Math.abs(l.get(1)-l.get(0))] = true;
					l.remove(0);
				}
				for(int i=1; i<n; i++){
					if(!temp1[i]){
						jolly=false;
						break;
					}
				}
				if(jolly){
					System.out.println("Jolly");
				}else{
					System.out.println("Not jolly");
				}
			}
		}
		catch(Exception e){}
	}
}