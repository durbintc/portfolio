
/*
* Java solution for the dynamic programming problem "Air Conditioned Minions" on Kattis
*/

import java.util.*;

public class airconditioned {
	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		
		//initializes amount of minions
		int minions = input.nextInt();
		
		//initializes minions and what their min
		//and max temps are
		int[][] temps= new int[minions][2];
		
		for (int i = 0; i < minions; i++) {
			temps[i][0] = input.nextInt();
			temps[i][1] = input.nextInt();
		}
		
		//sorts minions by max temp
	    int n = temps.length;
	    for (int i = 1; i < n; ++i) {
	    	int holder = temps[i][1];
	    	int holder2 = temps[i][0];
	        int j = i - 1;
	 
	        while (j >= 0 && temps[j][1] > holder) {
	        	temps[j + 1][0] = temps[j][0];
	        	temps[j + 1][1] = temps[j][1];
	            j = j - 1;
	        }
	        temps[j + 1][1] = holder;
	        temps[j + 1][0] = holder2;
	    }
	    
	    /*
	     * adds a room if curRoom == -1
	     * Sets room temp to the smallest max temp
	     * skips loop for all minions who would be comfortable
	     * in the current temp
	     */
    	int curRoom = -1;
    	int rooms = 0;
	    for (int i = 0; i < minions; i++) {
	    	if (curRoom == -1) {
	    		curRoom = temps[i][1];
	    		rooms++;
	    	}
	    	
	    	else {
	    		if (temps[i][0] <= curRoom) {
	    			continue;
	    		}
	    		else {
	    			curRoom = -1;
	    			i--;
	    		}
	    	}
	    }
	    
	    System.out.println(rooms);
	    input.close();
	}
}