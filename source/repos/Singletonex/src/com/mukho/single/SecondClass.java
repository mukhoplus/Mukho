package com.mukho.single;

public class SecondClass {
	public SecondClass() {
		SingletonClass sc = SingletonClass.getSingletonClass();
		System.out.println("SecondClass");
		System.out.println("i = "+sc.getI());
		sc.setI(165);
		System.out.println("i = "+sc.getI());
	}
}
