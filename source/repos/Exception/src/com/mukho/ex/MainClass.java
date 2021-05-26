package com.mukho.ex;

public class MainClass {
	public static void main(String[] args) {
		int i = 10;
		int j = 0;
		System.out.println(i*j);
		try {
			System.out.println(i/j);
		} catch(Exception e) {
			System.out.println(e.getMessage());
			// e,printStackTrace();
		} finally {
			System.out.println(i+j);
		}
		System.out.println(i-j);
	}
	// ArrayIndexOutOfBoundsException: 배열 사용시 존재하지 않는 index값 호출시 발생
	// NullPointerException: 존재하지 않는 객체를 가리킬 때 발생
	// NumberFormatException: 문자를 숫자로 처리할 때 발생
	// ClassNotFoundException: 클래스 이름을 못 찾았을때 발생
	// SQLException: db url, id, pw가 올바르지 않을때 발생
	
	// try ~ catch + finally | throws
}