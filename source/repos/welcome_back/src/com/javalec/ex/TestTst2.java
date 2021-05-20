package com.javalec.ex;

import java.util.Scanner;

public class TestTst2 {
	static int sum(int a, int b) {
		return a+b;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int i = 5;
		int j = 9;
		int s = sum(i,j);
		System.out.println(i+" + "+j+" = "+s);
		
		Scanner scanner = new Scanner(System.in);
		int input = scanner.nextInt();
		gugu(input);
	}
	public static void gugu(int i) {
		for(int a=1;a<=9;++a) 
			System.out.println(i+" * "+a+" = "+i*a);
	}
}