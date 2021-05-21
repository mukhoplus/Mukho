package com.mukho.sangsok;

public class SangsokClass extends MainClass {
	public SangsokClass() {
		
	}
	
	@Override
	public void b() {
		System.out.println("b");
	}
	public void c() {
		System.out.println("c");
	}
	
	public static void main(String[] args) {
		SangsokClass sc = new SangsokClass();
		sc.a();
		sc.b();
		sc.c();
	}
}
