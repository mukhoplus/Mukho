package com.mukho.t3;
// ��ü 1��, thread n��
public class MainClass {
	public static void main(String[] args) {
		ThreadTest tt = new ThreadTest();
		
		Thread t0 = new Thread(tt, "A");
		Thread t1 = new Thread(tt, "B");
		t0.start();
		t1.start();
		
		System.out.println(Thread.currentThread().getName());
		System.out.println("MainClass");
	}
}
