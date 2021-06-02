package com.mukho.t5;

public class MainClass {
	public static void main(String[] args) {
		VoteThread vl1 = new VoteThread();
		VoteThread vl2 = new VoteThread();
		VoteThread vl3 = new VoteThread();
		
		Thread l1 = new Thread(vl1, "Location1");
		Thread l2 = new Thread(vl2, "Location2");
		Thread l3 = new Thread(vl3, "Location3");
		
		l1.start();
		l2.start();
		l3.start();
	}
}
