package com.mukho.single;

public class FirstClass {
	public FirstClass() {
		SingletonClass sc = SingletonClass.getSingletonClass();
		System.out.println("FirstClass");
		System.out.println("i = "+sc.getI());
		sc.setI(160);
		System.out.println("i = "+sc.getI());
	}
}