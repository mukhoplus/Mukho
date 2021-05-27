package com.mukho.hs;

import java.util.HashSet;

public class MainClass {
	public static void main(String[] args) {
		HashSet<Student> hashSet = new HashSet<Student>();
		
		hashSet.add(new Student("��ȣ", 11));
		hashSet.add(new Student("ITX û��", 16));
		hashSet.add(new Student("Made By Google", 19));
		System.out.println(hashSet.toString()); // [Made By Google: 19, ��ȣ: 11, ITX û��: 16]
		
		Student student = new Student("ITX û��", 16);
		hashSet.remove(student);
		System.out.println(hashSet.toString()); // [Made By Google: 19, ��ȣ: 11]
	}
}
/*
 * Iterator: �ݺ���. �����͸� �ݺ������� �˻��ϴµ� ���� ������ �������̽�. iterator()
 */