package com.mukho.robot;

import com.mukho.pack.iFly;
import com.mukho.pack.iKnife;
import com.mukho.pack.iMissile;
//import com.mukho.pack.FlyYes;

public abstract class Robot {
	// iFly fly = new FlyYes();
	iFly fly;
	iMissile missile;
	iKnife knife;
	
	public Robot() {
		System.out.println("Hi");
	}
	public void Walk() {
		System.out.println("°È´Â´Ù");
	}
	public void Run() {
		System.out.println("¶Ú´Ù");
	}
	public abstract void Shape();
	
	public void setFly(iFly fly) {
		this.fly = fly;
	}
	public void setMissile(iMissile missile) {
		this.missile = missile;
	}
	public void setKnife(iKnife knife) {
		this.knife = knife;
	}
	
	public void Fly() {
		this.fly.Fly();
	}
	public void Missile() {
		this.missile.Missile();
	}
	public void Knife() {
		this.knife.Knife();
	}
}
