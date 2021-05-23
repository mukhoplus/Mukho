package com.mukho.interfacetest;

public class Main {
	public static void main(String[] args) {
		UsingInterface ui = new UsingInterface();
		ui.calcultate();
		ui.getStr();
		
		PartOne po = new UsingInterface();
		po.calcultate();
		
		PartTwo po2 = new UsingInterface();
		po2.getStr();
	}
}