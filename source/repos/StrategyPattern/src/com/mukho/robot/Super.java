package com.mukho.robot;

import com.mukho.pack.FlyYes;

public class Super extends Robot {
	public Super() {
		fly = new FlyYes();
		System.out.println("���� �� ����");
	}
	public void Shape() {
		System.out.println("Super: ��, �ٸ�, ����, �Ӹ�");
	}
}