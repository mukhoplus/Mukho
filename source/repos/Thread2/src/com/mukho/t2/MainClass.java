package com.mukho.t2;

public class MainClass {
	public static void main(String[] args) {
		ThreadTest tt = new ThreadTest();
		tt.setName("A");
		tt.start(); // (2) run �޼ҵ� ����
		
		System.out.println(Thread.currentThread().getName()); // (1) main
		System.out.println("MainClass");
	}
}
