package com.mukho.children;
import com.mukho.parent.ParentPouch;

public class ThirdChild {
	public ThirdChild() {
		
	}
	public void takeMoney(int money) {
		if(ParentPouch.money - money < 0) System.out.println("�޹ٱ��� ���� ���޾Ҿ��");
		else ParentPouch.money = ParentPouch.money - money;
	}
}