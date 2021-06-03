package com.mukho.btn;

import java.awt.Dimension;

public class MainClass {
	public static void main(String[] args) {
		MakeBtn btn = new MakeBtn();
		btn.pack(); // 컴포넌트의 사이즈를 정함
		//btn.setSize(new Dimension(200, 200)); // 컴포넌트의 사이즈를 개발자가 정함
		btn.setVisible(true); // 화면에 출력함
		
		try{
			Thread.sleep(2000);
		} catch(Exception e) {}
		
		btn.setVisible(false);
		btn.dispose(); // 자원 해제
		
		try {
			Thread.sleep(2000);
		} catch(Exception e) {}
		
		System.exit(0); // App 종료
	}
}
