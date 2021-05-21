package com.javalec.manager;

import java.util.ArrayList;

public class StudentManager {
	ArrayList<Student> students = new ArrayList<Student>();
	StudentExpel studentExpel = new StudentExpel();
	
	public static void main(String[] args) {
		StudentManager studentManager = new StudentManager();
		
		studentManager.addStudent("묵호", 25, 2016104101, "컴퓨터공학");
		studentManager.addStudent("ITX 청춘", 23, 2016104101, "지리학");
		studentManager.addStudent("Made By Google", 18, 2021052111, "데이터사이언스");
		studentManager.students.get(1).updateInfo(3, "2017500923");
		System.out.println(studentManager.students.get(2).getName());
		System.out.println(studentManager.students.get(1).getAge());
		System.out.println(studentManager.students.get(0).getStudentNum());
		System.out.println(studentManager.students.get(0).getMajor());
	}
	
	private void addStudent(String name, int age, int studentNum, String major) {
		students.add(new Student(name, age, studentNum, major));
		System.out.println(name+"의 정보 입력 성공");
	}
}
