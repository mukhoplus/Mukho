package com.mukho.t1;

public class MainClass {
	public static void main(String[] args) {
		ThreadTest tt = new ThreadTest();
		Thread t = new Thread(tt, "A");
		t.start(); // (2) run 메소드 실행
		
		System.out.println(Thread.currentThread().getName()); // (1) main
		System.out.println("MainClass");
	}
}
// 왜 (1)이 먼저인가? -> main 스레드와 run 스레드는 따로임