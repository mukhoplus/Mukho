package com.mukho.children;
import com.mukho.parent.ParentPouch;

public class FirstChild {
	public FirstChild() {
		
	}
	public void takeMoney(int money) {
		if(ParentPouch.money - money < 0) System.out.println("¹¬È£´Â µ·À» ¸ø¹Þ¾Ò¾î¿ä");
		else ParentPouch.money = ParentPouch.money - money;
	}
}