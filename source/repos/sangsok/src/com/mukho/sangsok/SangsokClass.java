package com.mukho.sangsok;

public class SangsokClass extends MainClass {
	public SangsokClass() {
		
	}
	
	@Override
	public void b() {
		super.b();
		System.out.println("b");
	}
	@Override
	public void c() {
		System.out.println("c");
	}
	public void d() {
		System.out.println("d");
	}
	
	public static void main(String[] args) {
		SangsokClass sc = new SangsokClass();
		sc.a();
		sc.b();
		sc.c();
		sc.d();
	}
}
