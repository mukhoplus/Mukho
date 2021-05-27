package com.mukho.hs;

import java.util.HashSet;

public class MainClass {
	public static void main(String[] args) {
		HashSet<Student> hashSet = new HashSet<Student>();
		
		hashSet.add(new Student("묵호", 11));
		hashSet.add(new Student("ITX 청춘", 16));
		hashSet.add(new Student("Made By Google", 19));
		System.out.println(hashSet.toString()); // [Made By Google: 19, 묵호: 11, ITX 청춘: 16]
		
		Student student = new Student("ITX 청춘", 16);
		hashSet.remove(student);
		System.out.println(hashSet.toString()); // [Made By Google: 19, 묵호: 11]
	}
}
/*
 * Iterator: 반복자. 데이터를 반복적으로 검색하는데 아주 유용한 인터페이스. iterator()
 */