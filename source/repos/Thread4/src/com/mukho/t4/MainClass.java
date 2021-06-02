package com.mukho.t4;

// °´Ã¼ 1°³, thread 1°³
public class MainClass {
	public static void main(String[] args) {
		ThreadTest tt0 = new ThreadTest();
		ThreadTest tt1 = new ThreadTest();
		
		Thread t0 = new Thread(tt0, "A");
		Thread t1 = new Thread(tt1, "B");
		t0.start();
		t1.start();
		
		System.out.println(Thread.currentThread().getName());
		System.out.println("MainClass");
	}
}
