package com.mukho.lol;

// 다중 구현-다형성(다중 상속이 안됨)
public class USER implements BOT, SUP, JUG {

	@Override
	public void LeeSin() {
		// TODO Auto-generated method stub
		System.out.println("리신 가능");
	}

	@Override
	public void Nidalee() {
		// TODO Auto-generated method stub
		System.out.println("니달리 가능");
	}

	@Override
	public void Thresh() {
		// TODO Auto-generated method stub
		System.out.println("쓰레쉬 가능");
	}

	@Override
	public void Lulu() {
		// TODO Auto-generated method stub
		System.out.println("룰루 가능");
	}

	@Override
	public void Vayne() {
		// TODO Auto-generated method stub
		System.out.println("베인 가능");
	}

	@Override
	public void Ashe() {
		// TODO Auto-generated method stub
		System.out.println("애쉬 가능");
	}

}