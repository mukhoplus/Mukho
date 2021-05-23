package com.mukho.interfacetest;

public class UsingInterface implements PartOne, PartTwo {

	@Override
	public String getStr() {
		// TODO Auto-generated method stub
		System.out.println("League: "+LEAGUE);
		return null;
	}

	@Override
	public void calcultate() {
		// TODO Auto-generated method stub
		System.out.println("Size: "+ SIZE);
	}
}
