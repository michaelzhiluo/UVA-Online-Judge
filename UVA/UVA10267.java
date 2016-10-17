import java.util.*;

class UVA10267{
	static char[][] pic;
	static Scanner s = new Scanner(System.in);
	static LinkedList<int []> q = new LinkedList<int[]>();
	static boolean[][] cached;
	public static void main(String [] args){
		try{
			while(true){
				char gg = s.next().charAt(0);
				switch(gg){
				case 'I': I(); break;
				case 'C': C(); break;
				case 'L': L(); break;
				case 'V': V(); break;
				case 'H': H(); break;
				case 'K': K(); break;
				case 'F': F(); break;
				case 'S': S(); break;
				case 'X': System.exit(0); break;
				default: s.nextLine(); break;
				}
			}
		}
		catch(Exception e){}
		System.exit(0);
	}
	
	public static void I(){
		int m = s.nextInt();
		int n = s.nextInt();
		pic = new char[n][m];
		C();
	}
	public static void C(){
		for(int i=0; i<pic.length; i++){
			for(int j=0; j<pic[0].length; j++){
				pic[i][j] = 'O';
			}
		}
	}
	public static void L(){
		int x = s.nextInt();
		int y = s.nextInt();
		char color = s.next().charAt(0);
		pic[y-1][x-1] = color;
	}
	
	public static void V(){
		int x = s.nextInt();
		int y1 = s.nextInt();
		int y2 = s.nextInt();
		int min = Math.min(y1,  y2);
		int max = Math.max(y1, y2);
		char color = s.next().charAt(0);
		for(int i=min-1; i<=max-1; i++){
			pic[i][x-1] = color;
		}
	}
	
	public static void H(){
		int x1 = s.nextInt();
		int x2 = s.nextInt();
		int y = s.nextInt();
		int min = Math.min(x1,  x2);
		int max = Math.max(x1, x2);
		char color = s.next().charAt(0);
		for(int i=min-1; i<=max-1; i++){
			pic[y-1][i] = color;
		}
	}
	
	public static void K(){
		int x1 =s.nextInt();
		int y1 = s.nextInt();
		int x2 = s.nextInt();
		int y2 = s.nextInt();
		int minx = Math.min(x1,  x2);
		int maxx = Math.max(x1,  x2);
		int miny = Math.min(y1,  y2);
		int maxy = Math.max(y1, y2);
		char color = s.next().charAt(0);
		for(int i=minx-1; i<=maxx-1; i++){
			for(int j=miny-1; j<=maxy-1; j++){
				pic[j][i] = color;
			}
		}
	}
	
	public static void F(){
		int x = s.nextInt();
		int y = s.nextInt();
		char color = s.next().charAt(0);
		char oldcolor = pic[y-1][x-1];
		cached = new boolean[pic.length][pic[0].length];
		if(color == oldcolor){return;}
		//recurF(x-1, y-1, color, oldcolor);
		q.add(new int[] {x-1, y-1});
		while(!q.isEmpty()){
			int[] temp = q.remove();
			int x1 = temp[0]; int y1 = temp[1];
			pic[y1][x1]= color;
			if(cached[y1][x1]){
				continue;
			}
			cached[y1][x1] = true;
			if(x1>=1 && pic[y1][x1-1] == oldcolor){
				q.add(new int[] {x1-1, y1});
			}
			if(x1<pic[0].length-1 && pic[y1][x1+1] == oldcolor){
				q.add(new int[] {x1+1, y1});
			}
			if(y1>=1 && pic[y1-1][x1] == oldcolor){
				q.add(new int[] {x1, y1-1});
			}
			if(y1<pic.length-1 && pic[y1+1][x1] == oldcolor){
				q.add(new int[] {x1, y1+1});
			}
		}
	}
	
	// Flood-fill with Stack Memoization which has StackOverflow Error
	/*public static void recurF(int x, int y, char color, char oldcolor){
		if(y>=pic.length || y<0){
			return;
		}
		if(x>=pic[0].length || x<0){
			return;
		}
		if(cached[y][x]){
			return;
		}
		if(pic[y][x] != oldcolor){
			return;
		}
		pic[y][x] = color;
		cached[y][x] = true;
		recurF(x+1, y, color, oldcolor);
		recurF(x-1, y, color, oldcolor);
		recurF(x, y+1, color, oldcolor);
		recurF(x, y-1, color, oldcolor);
	}*/
	
	public static void S(){
		String str = s.next();
		System.out.println(str);
		for(int i=0; i<pic.length; i++){
			System.out.println(String.valueOf(pic[i]));
		}
	}
	
	
	
}