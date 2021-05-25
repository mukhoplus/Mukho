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
		
		System.out.println(year + "년 " + month + "월 " + day + "일");
		System.out.println(hour + "시 " + minute + "분" + " " + second + "초");
		long endNum = System.currentTimeMillis();
		System.out.println("\n**************************\n");
		System.out.println("경과시간: "+ (endNum-startNum));
	}
}