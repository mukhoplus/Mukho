package com.mukho.btn;

import java.awt.Dimension;

public class MainClass {
	public static void main(String[] args) {
		MakeBtn btn = new MakeBtn();
		btn.pack(); // ������Ʈ�� ����� ����
		//btn.setSize(new Dimension(200, 200)); // ������Ʈ�� ����� �����ڰ� ����
		btn.setVisible(true); // ȭ�鿡 �����
		
		try{
			Thread.sleep(2000);
		} catch(Exception e) {}
		
		btn.setVisible(false);
		btn.dispose(); // �ڿ� ����
		
		try {
			Thread.sleep(2000);
		} catch(Exception e) {}
		
		System.exit(0); // App ����
	}
}
