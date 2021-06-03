package com.mukho.frame;

import java.awt.Dimension;

public class MainClass {
	public static void main(String[] args) {
		MakeFrame mf = new MakeFrame();
		mf.setSize(new Dimension(500, 500));
		mf.setVisible(true);
	}
}
