// @855434:  theasura  100  Java  "The 3n + 1 problem"

import java.io.*;
import java.util.*;

class UVA100{
	static int [] storage = new int[1000000];
	public static void main(String [] args){
		Scanner s = new Scanner(System.in);
		while(s.hasNextInt()){
			int a = s.nextInt();
			int b = s.nextInt();
			int max=0;	
			int min = Math.min(a, b);
			int maxint = Math.max(a, b);
			for(int i=min; i<=maxint; i++){
				int temp = cycle(i);
				if(temp>=max){
					max = temp;
				}
			}
			System.out.println(a + " " + b + " " + max);
		}
		System.exit(0);
	}
	
	public static int cycle(int n){
		if(n==1){
			return 1;
		}
		if(n<storage.length && storage[n]!=0){
			return storage[n];
		}
		int prev = n;
			
		if(n%2==0){
			n = n/2;
		}else{
			n = 3*n+1;
		}
		
		int temp = 1 + cycle(n);
		if(prev<storage.length){
			storage[prev]=temp;
		}
		return temp;
	}
}
