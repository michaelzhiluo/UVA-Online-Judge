// @855434:  theasura  10137  Java  "The Trip"

import java.io.*;
import java.util.*;

class UVA10137{

	public static void main(String [] args) throws IOException{
		Scanner s = new Scanner(System.in);
		try{
			while(true){
				int students = s.nextInt();
				if(students ==0){
					System.exit(0);
				}
				double total=0;
				double[] money = new double[students];
				for(int i=0; i<students; i++){
					money[i] = Double.parseDouble(s.next());
					total +=money[i];
				}
				double average = Math.round((total/students) * 100.0) / 100.0;
				double leftdev =0, rightdev=0;
				for(double i: money){
					double temp = i-average;
					if(temp<0){
						leftdev-=temp;
					}else{
						rightdev+=temp;
					}
				}
				System.out.printf("$%.2f\n",Math.min(leftdev, rightdev));
			}
		}
		catch(Exception e){}
	}
}
