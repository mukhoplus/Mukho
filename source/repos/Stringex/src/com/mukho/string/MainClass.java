package com.mukho.string;

public class MainClass {
	public static void main(String[] args) {
		// String Ŭ������ �޸𸮸� ���Һ��Ѵ�. -> �ʱ� �����Ϳ� ��ȭ�� ����� ���� ���� ��Ȱ���ϱ⺸�ٴ� �� ���� ã�´�.(�ӵ��� ������)
		// -> �׷��� StringBuffer, StringBuilder�� �����ϰ� �ȴ�.
		String str1 = "abcdefg";
		String str2 = "HIJKLMN";
		String str3 = "opqrstu";
		
		System.out.println(str1.concat(str2)); // ���ڿ� ��ġ��
		System.out.println(str1.substring(3)); // ��ġ 3���� ���
		System.out.println(str1.length()); // ���ڿ� ����
		System.out.println(str1.toUpperCase()); // �빮��ȭ
		System.out.println(str2.toLowerCase()); // �ҹ���ȭ
		System.out.println(str1.charAt(3)); // �ش� ��ġ�� �ִ� ���ڿ� ���
		System.out.println(str1.indexOf('c')); // Ư�� ���ڿ��� ��ġ
		
		String str4 = "abcdefg";
		System.out.println(str1.equals(str4)); // ���ڿ� ��
		
		String str5 = " abc def ghi ";
		System.out.println(str5.trim()); // ���ڿ� ���� ����
		
		System.out.println(str1.replace('a', 'Z')); // Ư�� ���� ����
		System.out.println(str1.replaceAll("abcd", "ZZZZZZZ")); // Ư�� ���ڿ� ����
		System.out.println(str1);
		
		System.out.println("\n*********************************\n");
		
		// StringBuffer�� StringBuilder�� ���� �����ϸ�, StringBuffer�� ���� �������� �� �� ������.
		StringBuilder sb = new StringBuilder("abcdefg");
		
		sb.append("hijklmn"); // ���ڿ� �߰�
		System.out.println(sb);
		
		sb.insert(3, "AAA"); // Ư�� ��ġ�� ���ڿ� �߰�
		System.out.println(sb);
		
		sb.delete(3, 5); // ���ڿ� ����(start �̻� end �̸�)
		System.out.println(sb);
		
		sb.deleteCharAt(10); // Ư�� ���� �ϳ� ����
		System.out.println(sb);
	}
}
