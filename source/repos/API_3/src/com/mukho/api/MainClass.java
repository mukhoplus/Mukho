package com.mukho.api;

import java.util.StringTokenizer;
import java.util.Timer;
import java.util.TimerTask;

public class MainClass {
	public static int count;
	public static void main(String[] args) {
		count = 0;
		Timer t = new Timer();
		TimerTask tt = new TimerTask() {
			@Override
			public void run() {
				if(count < 5) {
					System.out.println("앙");
					count++;
				}
				else {
					t.cancel();
				}
			}
		};
		// t.schedule(tt, 2000);
		t.schedule(tt, 5000, 2000);
		
		System.out.println("\n*************\n");
		
		String str1 = "와 ㅋㅋ 이게뭐야, 와우";
		String str2 = "2011-11-07";
		
		System.out.println(str1);
		System.out.println(str2);
		
		StringTokenizer t1 = new StringTokenizer(str1);
		StringTokenizer t2 = new StringTokenizer(str2, "-");
		
		System.out.println("t1 문자열 수: "+t1.countTokens());
		System.out.println("t2 문자열 수: "+t2.countTokens());
		
		while(t1.hasMoreTokens()) {
			System.out.println(t1.nextToken());
		}
		while(t2.hasMoreTokens()) {
			System.out.println(t2.nextToken());
		}
	}
}