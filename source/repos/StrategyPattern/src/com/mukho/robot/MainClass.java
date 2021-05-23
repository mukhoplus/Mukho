package com.mukho.robot;

import com.mukho.pack.FlyNo;
import com.mukho.pack.FlyYes;
import com.mukho.pack.KnifeLazer;
import com.mukho.pack.MissileYes;
// Super Class는 Fly가 default값임. - 이렇게 써라.
public class MainClass {
	public static void main(String[] args) {
		Robot sp = new Super();
		sp.Shape();
		sp.Walk();
		sp.Run();
		sp.Fly();
		sp.setFly(new FlyNo());
		sp.Fly();
		sp.setMissile(new MissileYes());
		sp.Missile();
		sp.setKnife(new KnifeLazer());
		sp.Knife();
		
		Robot sd = new Standard();
		
		Low lw = new Low();
		
	}
}