package com.mukho.string;

public class MainClass {
	public static void main(String[] args) {
		// String 클래스는 메모리를 과소비한다. -> 초기 데이터에 변화가 생기면 기존 것을 재활용하기보다는 새 것을 찾는다.(속도가 느려짐)
		// -> 그래서 StringBuffer, StringBuilder가 등장하게 된다.
		String str1 = "abcdefg";
		String str2 = "HIJKLMN";
		String str3 = "opqrstu";
		
		System.out.println(str1.concat(str2)); // 문자열 합치기
		System.out.println(str1.substring(3)); // 위치 3부터 출력
		System.out.println(str1.length()); // 문자열 길이
		System.out.println(str1.toUpperCase()); // 대문자화
		System.out.println(str2.toLowerCase()); // 소문자화
		System.out.println(str1.charAt(3)); // 해당 위치에 있는 문자열 출력
		System.out.println(str1.indexOf('c')); // 특정 문자열의 위치
		
		String str4 = "abcdefg";
		System.out.println(str1.equals(str4)); // 문자열 비교
		
		String str5 = " abc def ghi ";
		System.out.println(str5.trim()); // 문자열 공백 제거
		
		System.out.println(str1.replace('a', 'Z')); // 특정 문자 변경
		System.out.println(str1.replaceAll("abcd", "ZZZZZZZ")); // 특정 문자열 변경
		System.out.println(str1);
		
		System.out.println("\n*********************************\n");
		
		// StringBuffer와 StringBuilder는 거의 동일하며, StringBuffer가 먼저 나왔으며 좀 더 빠르다.
		StringBuilder sb = new StringBuilder("abcdefg");
		
		sb.append("hijklmn"); // 문자열 추가
		System.out.println(sb);
		
		sb.insert(3, "AAA"); // 특정 위치에 문자열 추가
		System.out.println(sb);
		
		sb.delete(3, 5); // 문자열 삭제(start 이상 end 미만)
		System.out.println(sb);
		
		sb.deleteCharAt(10); // 특정 문자 하나 삭제
		System.out.println(sb);
	}
}
