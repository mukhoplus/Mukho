package com.mukho.children;
import com.mukho.parent.ParentPouch;

public class SecondChild {
	public SecondChild() {
		
	}
	public void takeMoney(int money) {
		if(ParentPouch.money - money < 0) System.out.println("ITX Ã»ÃáÀº µ·À» ¸ø¹Þ¾Ò¾î¿ä");
		else ParentPouch.money = ParentPouch.money - money;
	}
}