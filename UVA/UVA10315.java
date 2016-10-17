import java.util.*;

class UVA10315{
	static Scanner s = new Scanner(System.in);
	static Card[] p1, p2; 
	static int numloops =0;
	public static void main(String [] args){
		try{
			while(s.hasNext()){
				p1 = new Card[5]; p2 = new Card[5];
				for(int i=0; i<5; i++){
					String x = s.next();
					int a  = parsenumber(x.charAt(0));
					char b = x.charAt(1);
					p1[i] = new Card(a, b);
				}
				for(int i=0; i<5; i++){
					String x = s.next();
					int a  = parsenumber(x.charAt(0));
					char b = x.charAt(1);
					p2[i] = new Card(a, b);
				}
				Arrays.sort(p1); Arrays.sort(p2);
				long a = getScore(p1); long b = getScore(p2);
				if(a>b){System.out.println("Black wins.");}
				else if(a<b){System.out.println("White wins.");}
				else if(a==b){System.out.println("Tie.");}
			}
			s.close();
		}
		catch(Exception e){}
	}

	public static int parsenumber(char s){
		switch(s){
		case 'T': return 10; 
		case 'J': return 11; 
		case 'Q': return 12; 
		case 'K': return 13;
		case 'A': return 14; 
		default: return (int)(s) - 48; 
		}
	}
	
	public static long getScore(Card[] p){
		boolean straight = true;
		boolean flush = true;
		// Contains indexes of pairs and triples, there can only be at max of two such combos 
		// in five cards ([3, 2], [2,2], [2, 0], [3, 0])
		ArrayList<Integer>[] combo = new ArrayList[2];
		combo[0] = new ArrayList<Integer>();
		combo[1] = new ArrayList<Integer>();
		
		// Manages Straights and Flushes
		for(int i=0; i<p.length-1; i++){
			if(flush && p[i].suite != p[i+1].suite){
				flush = false;
			}
			if(straight && p[i+1].number  != p[i].number + 1){
				straight = false;
			}
		}
		
		// Manages pairs and triples. Bad code
		int temp =0;
		for(int i=0; i<p.length-1; i++){
			int count =1;
			if(p[i].number == p[i+1].number){
				count =2;
				for(int j=i+2; j<p.length; j++){
					if(p[i].number == p[j].number){
						count++;
					}else{
						break;
					}
				}
			}
			if(count ==2){
				combo[temp].add(i); combo[temp].add(i+1);
				temp++;
			}else if(count ==3){
				combo[temp].add(i); combo[temp].add(i+1); combo[temp].add(i+2);
				temp++;
			}else if(count ==4){
				combo[temp].add(i); combo[temp].add(i+1); combo[temp].add(i+2); combo[temp].add(i+3);
				temp++;
			}
			i+=count-1;
		}
		
		// Score Calculating Time! Base Score  + (Multiplier of all pairs/triples/flushes/etc)
		// Base Score
		long score = 0;
		for(int i=0; i<p.length; i++){
			score+=p[i].number * (long)Math.pow(10, i);
		}
		
		if(combo[0].size()==2 && combo[1].isEmpty() && !flush){
			score+= (long)Math.pow(10, 17);
			score+= (long)Math.pow(10, 7)*(p[combo[0].get(0)].number);
		}
		if(combo[0].size()==2 && combo[1].size()==2 && !flush){
			score+= 2*(long)Math.pow(10, 17);
			score+= (long)Math.pow(10, 8)*(long)Math.max(p[combo[0].get(0)].number, p[combo[1].get(0)].number);
			score+= (long)Math.pow(10, 7)*(long)Math.min(p[combo[0].get(0)].number, p[combo[1].get(0)].number);
		}
		if(combo[0].size()==3 && combo[1].isEmpty() && !flush){
			score+= 3*(long)Math.pow(10, 17);
			score+= (long)Math.pow(10, 7)*(p[combo[0].get(0)].number);
		}
		if(straight && !flush){
			score+= 4*(long)Math.pow(10, 17);
		}
		if(flush && !straight){
			score+= 5*(long)Math.pow(10, 17);
		}
		if((!flush && combo[1].size()==3 && combo[0].size()==2) || (!flush && combo[1].size()==2 && combo[0].size()==3)){
			score+= 6*(long)Math.pow(10, 17);
		}
		if(!flush && combo[0].size()==4){
			score+= 7*(long)Math.pow(10, 17);
			score+= (long)Math.pow(10, 7)*(p[combo[0].get(0)].number);
		}
		if(flush && straight){
			score+= 8*(long)Math.pow(10, 17);
		}
		return score;
	}
}

class Card implements Comparable<Card>{
	public int number;
	public char suite;
	public Card(int a, char b){
		number = a;
		suite = b;
	}

	public int compareTo(Card c) {
		return this.number-c.number;
	}
}
