package com.mukho.phone;

public class Main {
	public static void main(String[] args) {
		// APhone ap = new APhone();
		// BPhone bp = new BPhone();
		// CPhone cp = new CPhone();
		// ↑ 원래 쓰는 방법 | ↓ 다형성
		iPhone ap = new APhone();
		iPhone bp = new BPhone();
		iPhone cp = new CPhone();
		
		iPhone[] iPhones = {ap, bp, cp};
		
		System.out.println("====================");
		for(int i=0; i<iPhones.length;i++) {
			iPhones[i].getName();
			iPhones[i].getSize();
			iPhones[i].getPower();
			System.out.println("====================");
		}
	}
}