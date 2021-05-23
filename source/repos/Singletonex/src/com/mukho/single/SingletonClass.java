package com.mukho.single;

public class SingletonClass {
	private static SingletonClass SINGLETON_CLASS_INSTANCE = new SingletonClass();
	private int i = 70;
	
	private SingletonClass() {
		
	}
	
	public static SingletonClass getSingletonClass() {
		if(SINGLETON_CLASS_INSTANCE == null) {
			SINGLETON_CLASS_INSTANCE = new SingletonClass();
		}
		return SINGLETON_CLASS_INSTANCE;
	}
	public int getI() {
		return i;
	}
	public void setI(int i) {
		this.i = i;
	}
}
