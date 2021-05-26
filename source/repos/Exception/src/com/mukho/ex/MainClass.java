package com.mukho.ex;

public class MainClass {
	public static void main(String[] args) {
		int i = 10;
		int j = 0;
		System.out.println(i*j);
		try {
			System.out.println(i/j);
		} catch(Exception e) {
			System.out.println(e.getMessage());
			// e,printStackTrace();
		} finally {
			System.out.println(i+j);
		}
		System.out.println(i-j);
	}
	// ArrayIndexOutOfBoundsException: �迭 ���� �������� �ʴ� index�� ȣ��� �߻�
	// NullPointerException: �������� �ʴ� ��ü�� ����ų �� �߻�
	// NumberFormatException: ���ڸ� ���ڷ� ó���� �� �߻�
	// ClassNotFoundException: Ŭ���� �̸��� �� ã������ �߻�
	// SQLException: db url, id, pw�� �ùٸ��� ������ �߻�
	
	// try ~ catch + finally | throws
}