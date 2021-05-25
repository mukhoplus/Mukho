package com.mukho.date;

import java.util.Calendar;

public class MainClass {
	public static void main(String[] args) {
		System.out.println(System.currentTimeMillis());
		long startNum = System.currentTimeMillis();
		
		Calendar c = Calendar.getInstance();
		
		int year = c.get(Calendar.YEAR);
		int month = c.get(Calendar.MONTH) + 1;
		int day = c.get(Calendar.DAY_OF_MONTH);
		int hour = c.get(Calendar.HOUR_OF_DAY);
		int minute = c.get(Calendar.MINUTE);
		int second = c.get(Calendar.SECOND);
		
		System.out.println(year + "�� " + month + "�� " + day + "��");
		System.out.println(hour + "�� " + minute + "��" + " " + second + "��");
		long endNum = System.currentTimeMillis();
		System.out.println("\n**************************\n");
		System.out.println("����ð�: "+ (endNum-startNum));
	}
}