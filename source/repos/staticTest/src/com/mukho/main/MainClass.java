package com.mukho.main;
import com.mukho.children.*;
import com.mukho.parent.ParentPouch;

public class MainClass {	
	public static void main(String[] args) {
		FirstChild first = new FirstChild();
		SecondChild second = new SecondChild();
		ThirdChild third = new ThirdChild();
		first.takeMoney(1000);
		second.takeMoney(3000);
		third.takeMoney(1500);
		System.out.println("Parent¿« µ∑: " + ParentPouch.money);
	}
}