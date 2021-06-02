package com.mukho.t1;

public class ThreadTest implements Runnable {

	@Override
	public void run() {
		// TODO Auto-generated method stub
		System.out.println(Thread.currentThread().getName()); // A
		System.out.println("ThreadTest"); // ThreadTest
		for(int i=0;i<10;++i) {
			System.out.println(i);
			try {
				Thread.sleep(500);
			} catch(Exception e) {};
		}
	}

}
