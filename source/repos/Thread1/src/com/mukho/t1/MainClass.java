package com.mukho.t1;

public class MainClass {
	public static void main(String[] args) {
		ThreadTest tt = new ThreadTest();
		Thread t = new Thread(tt, "A");
		t.start(); // (2) run �޼ҵ� ����
		
		System.out.println(Thread.currentThread().getName()); // (1) main
		System.out.println("MainClass");
	}
}
// �� (1)�� �����ΰ�? -> main ������� run ������� ������