package com.mukho.api;

import java.util.Random;
import java.util.Scanner;


public class MainClass {
	public static void main(String[] args) {
		double d = Math.random(); // ����
		System.out.println("Random: "+ Math.round(d*100)); // 0�̻� 100�̸�
		Random random = new Random(); // �Ž�
		System.out.println(random.nextInt(100)); // 0�̻� 100�̸�
		
		System.out.println("\n*******************\n");
		
		Scanner s = new Scanner(System.in);
		int i = s.nextInt(); // ����
		System.out.println("i: "+i);
		String str0 = s.next(); // ���ڿ�
		System.out.print("str0: "+str0+'\n'); // ���� ����
		String str1 = s.nextLine(); // '\n'�� �Էµ� �� ���� �Է¹���
		System.out.println("str1: "+str1); // �ڵ� ����
	
		System.out.println("\n*******************\n");
		
		// Wrapper Ŭ����: ���ʵ����͸� ��ü�����ͷ� ��ȯ
		Integer integer = new Integer(10);
		int j = integer.intValue();
		System.out.println("j: "+j);
		String str = "65";
		int k = Integer.parseInt(str);
		System.out.println("k: "+(k+10));
	}
}