package com.mukho.children;
import com.mukho.parent.ParentPouch;

public class FirstChild {
	public FirstChild() {
		
	}
	public void takeMoney(int money) {
		if(ParentPouch.money - money < 0) System.out.println("��ȣ�� ���� ���޾Ҿ��");
		else ParentPouch.money = ParentPouch.money - money;
	}
}