import java.util.Scanner;

class UVA10050{
	static Scanner s = new Scanner(System.in);
	public static void main(String [] args){
		try{
			int numtimes = s.nextInt();
			while(numtimes>0){
				boolean[] days = new boolean[s.nextInt()+1];
				int[] hartal = new int[s.nextInt()];
				for(int i=0; i<hartal.length; i++){
					hartal[i] = s.nextInt();
				}
				for(int i=0; i<hartal.length; i++){
					for(int j=hartal[i]; j<days.length; j+=hartal[i]){
						days[j] = true;
					}
				}
				int counter =0;
				for(int i=1; i<days.length; i++){
					if(days[i]==true && i%7!=6 && i%7!=0){
						counter++;
					}
				}
				System.out.println(counter);
				numtimes--;
			}
		}
		catch(Exception e){}
	}
}