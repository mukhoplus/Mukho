package com.mukho.api;

import java.util.Random;
import java.util.Scanner;


public class MainClass {
	public static void main(String[] args) {
		double d = Math.random(); // 구식
		System.out.println("Random: "+ Math.round(d*100)); // 0이상 100미만
		Random random = new Random(); // 신식
		System.out.println(random.nextInt(100)); // 0이상 100미만
		
		System.out.println("\n*******************\n");
		
		Scanner s = new Scanner(System.in);
		int i = s.nextInt(); // 정수
		System.out.println("i: "+i);
		String str0 = s.next(); // 문자열
		System.out.print("str0: "+str0+'\n'); // 개행 안함
		String str1 = s.nextLine(); // '\n'이 입력될 때 까지 입력받음
		System.out.println("str1: "+str1); // 자동 개행
	
		System.out.println("\n*******************\n");
		
		// Wrapper 클래스: 기초데이터를 객체데이터로 변환
		Integer integer = new Integer(10);
		int j = integer.intValue();
		System.out.println("j: "+j);
		String str = "65";
		int k = Integer.parseInt(str);
		System.out.println("k: "+(k+10));
	}
}