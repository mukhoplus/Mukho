package com.mukho.robot;

import com.mukho.pack.FlyYes;

public class Super extends Robot {
	public Super() {
		fly = new FlyYes();
		System.out.println("ÇìÇì ³ª ½´ÆÛ");
	}
	public void Shape() {
		System.out.println("Super: ÆÈ, ´Ù¸®, ¸öÅë, ¸Ó¸®");
	}
}