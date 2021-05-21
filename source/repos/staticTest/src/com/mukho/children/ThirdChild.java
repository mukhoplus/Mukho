package com.mukho.children;
import com.mukho.parent.ParentPouch;

public class ThirdChild {
	public ThirdChild() {
		
	}
	public void takeMoney(int money) {
		if(ParentPouch.money - money < 0) System.out.println("메바구는 돈을 못받았어요");
		else ParentPouch.money = ParentPouch.money - money;
	}
}