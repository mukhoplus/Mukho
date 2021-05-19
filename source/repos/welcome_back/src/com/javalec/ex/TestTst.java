package com.javalec.ex;

import java.util.Scanner;

public class TestTst {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.println("숫자 입력: ");
		int num = scanner.nextInt();
		if(num >= 72)
			System.out.println(num + "은 72 초과");
		else if(num == 72)
			System.out.println("지리네");
		else
			System.out.println(num+"은 72 미만");
	
		int [] ary1 = {69, 74, 892};
		int [] ary2 = new int[2];
		ary2[0] = 5;
		ary2[1] = 9;
		
		int [][]ary3 = new int[2][];
		ary3[0] = new int[1];
		ary3[1] = new int[2];
		ary3[0][0] = 1;
		ary3[1][0] = 2;
		ary3[1][1] = 3;
		int [][]ary4 = new int[2][1];
		ary4[0][0] = 0;
		ary4[0][1] = 1;
	}
	// if / else if / else // switch 는 C와 C++와 문법이 같다.
	// for / while도 같음
	
}
