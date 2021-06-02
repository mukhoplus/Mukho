package com.mukho.t3;

public class ThreadTest implements Runnable {
	
	int testNum = 0; // Synchronized(공유 데이터) - 먼저 수행되는 데이터의 작업이 모두 끝나야 접근 가능하다.
	@Override
	public void run() {
		// TODO Auto-generated method stub
		for(int i=0; i<10; ++i) {
			if(Thread.currentThread().getName().equals("A")) {
				System.out.println("============================");
				testNum++;
			}
			System.out.println("Thread Name: "+Thread.currentThread().getName()+", testNum: "+testNum);
			try {
				Thread.sleep(500);
			} catch(Exception e) {}
		}
	}

}
