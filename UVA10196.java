import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;

class UVA10196{
	static Scanner s = new Scanner(System.in);
	static char[][] board = new char[8][8];
	static HashSet<int[]> knight = new HashSet<int[]>();
	static boolean ripblack, ripwhite;
	static int game =1;
	static boolean alldots = true;
	public static void main(String [] args){
		//Pre-constructing possible squares for knight
		knight.add(new int [] {2, 1}); knight.add(new int [] {1, 2}); knight.add(new int [] {-2, 1});
		knight.add(new int [] {1, -2}); knight.add(new int [] {2, -1}); knight.add(new int [] {-1, 2});
		knight.add(new int [] {-2, -1}); knight.add(new int [] {-1, -2});
		// Input
		try{
			while(true){
				ripwhite = false; ripblack = false;
				for(int i=0; i<8; i++){
					String temp = s.next();
					for(int j=0; j<8; j++){
						board[i][j] = temp.charAt(j);	
					}
				}
				
				for(int i=0; i<8; i++){
					for(int j=0; j<8; j++){
						char temp = board[i][j];
						if(alldots && temp!='.'){
							alldots = false;
						}
						switch(temp){
						case '.': 
						case 'k':
						case 'K':
						break;
						case 'n': knight('n', i, j); break;
						case 'N': knight('N', i, j); break;
						case 'R': rook('R', i, j); break;
						case 'r': rook('r', i, j); break;
						case 'B': bishop('B', i, j); break;
						case 'b': bishop('b', i, j); break;
						case 'Q': rook('R', i, j); bishop('B', i, j); break;
						case 'q': rook('r', i, j); bishop('b', i, j); break;
						case 'p': pawn('p', i, j); break;
						case'P': pawn('P', i, j); break;
						}
					}
				}
				if(alldots){
					System.exit(0);
				}
				if(!ripwhite && !ripblack){
					System.out.println("Game #" + game + ": no king is in check.");
				}
				else if(ripwhite){
					System.out.println("Game #" + game + ": white king is in check.");
				}
				else{
					System.out.println("Game #" + game + ": black king is in check.");
				}
				game++;
				alldots = true;
			}
		}
		catch(Exception e){}
	}
	
	public static void knight(char n, int i, int j){
		for(int[] temp: knight){
			int a = i + temp[0];
			int b = j + temp[1];
			if(a>=8 || a<0){
				continue;
			}
			else if(b>=8 || b<0){
				continue;
			}
			else{
				if(board[a][b]=='K' && n=='n'){
					ripwhite = true;
					break;
				}
				else if(board[a][b]=='k' && n=='N'){
					ripblack = true;
					break;
				}
			}
		}
	}
	
	public static void bishop(char n, int i, int j){
		boolean[] diag = new boolean[4];
		ArrayList<Character> gg = new ArrayList<Character>();
		int counter =1;
		while(!(diag[0] && diag[1] && diag[2] && diag[3])){
			if(!diag[0]){
				if(i -counter<0 || j-counter<0){
					diag[0] = true;
				}
				else if(board[i -counter][j-counter] != '.'){
					gg.add(board[i-counter][j-counter]);
					diag[0] = true;
				}
			}
			if(!diag[1]){
				if(i -counter<0 || j+counter>=8 ){
					diag[1] = true;
				}
				else if(board[i -counter][j+counter] != '.'){
					gg.add(board[i-counter][j+counter]);
					diag[1] = true;
				}
			}
			if(!diag[2]){
				if(i +counter >=8 || j-counter<0){
					diag[2] = true;
				}
				else if(board[i +counter][j-counter] != '.'){
					gg.add(board[i+counter][j-counter]);
					diag[2] = true;
				}
			}
			if(!diag[3]){
				if(i +counter >=8 || j+counter>=8 ){
					diag[3] = true;
				}
				else if(board[i +counter][j+counter] != '.'){
					gg.add(board[i+counter][j+counter]);
					diag[3] = true;
				}
			}
			counter++;
		}
		for(char c: gg){
			if(c == 'K' && n=='b'){
				ripwhite = true;
			}
			else if(c=='k' && n=='B'){
				ripblack = true;
			}
		}
	}
	
	public static void rook(char n, int i, int j){
		boolean[] row = new boolean[4];
		ArrayList<Character> gg = new ArrayList<Character>();
		int counter =1;
		while(!(row[0] && row[1] && row[2] && row[3])){
			// upwards
			if(!row[0]){
				if(i-counter<0){
					row[0] = true;
				}
				else if(board[i -counter][j] != '.'){
					gg.add(board[i-counter][j]);
					row[0] = true;
				}
			}
			//downwards
			if(!row[1]){
				if(i+counter>=8){
					row[1] = true;
				}
				else if(board[i +counter][j] != '.'){
					gg.add(board[i+counter][j]);
					row[1] = true;
				}
			}
			//leftwards
			if(!row[2]){
				if(j-counter<0){
					row[2] = true;
				}
				else if(board[i][j-counter] != '.'){
					gg.add(board[i][j-counter]);
					row[2] = true;
				}
			}
			//rightwards
			if(!row[3]){
				if(j+counter>=8 ){
					row[3] = true;
				}
				else if(board[i][j+counter] != '.'){
					gg.add(board[i][j+counter]);
					row[3] = true;
				}
			}
			counter++;
		}
		
		for(char c: gg){
			if(c == 'K' && n=='r'){
				ripwhite = true;
			}
			else if(c=='k' && n=='R'){
				ripblack = true;
			}
		}
	}
	
	public static void pawn(char n, int i, int j){
		ArrayList<int[]> gg = new ArrayList<int []>();
		if(n=='p'){
			gg.add(new int[] {1, -1});
			gg.add(new int[] {1, 1});
			
		}else if(n=='P'){
			gg.add(new int[] {-1, -1});
			gg.add(new int[] {-1, 1});
		}
		for(int ggg[] : gg){
			if(i + ggg[0] >=8 || i + ggg[0] <0 || j+ggg[1]>=8 || j+ggg[1]<0){
				continue;
			}
			if(board[i+ggg[0]][j + ggg[1]]!='.'){
				if(board[i+ggg[0]][j+ggg[1]]=='K' && n=='p'){
					ripwhite = true;
					break;
				}
				else if(board[i+ggg[0]][j+ggg[1]]=='k' && n=='P'){
					ripblack = true;
					break;
				}
			}
		}
	}	
}