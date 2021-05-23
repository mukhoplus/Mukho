package com.mukho.lol;

public class Main {
	public static void main(String[] args) {
		USER u1 = new USER();
		USER2 u2 = new USER2();
		BOT adc = new USER();
		
		u1.Thresh();
		u1.Vayne();
		u1.LeeSin();
		u1.Lulu();
		u1.Ashe();
		u1.Nidalee();
		
		System.out.println("========");
		
		u2.Thresh();
		u2.Lulu();
		u2.Vayne();
		u2.Ashe();		
		
		System.out.println("========");
		adc.Vayne();
		adc.Ashe();
	}
}
