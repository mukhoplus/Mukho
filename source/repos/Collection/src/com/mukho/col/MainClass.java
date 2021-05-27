package com.mukho.col;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;

public class MainClass {
	public static void main(String[] args) {
		/*
		 * ArrayList: index 중요, C++과 다르게 크기 설정이 필요없음
		 * LinkedList: ArrayList와 비슷, 중간 추가+삭제+수정에 유리
		 * Vector: ArrayList와 유사
		 */
		
		ArrayList<String> al = new ArrayList<String>();
		
		al.add("str1");
		al.add("str2");
		al.add("str3");
		al.add("str4");
		System.out.println(al.toString()); // [str1, str2, str3, str4]
		
		String index3 = al.get(3);
		System.out.println("index3: "+index3);
		
		al.set(2, "str22");
		System.out.println(al.toString()); // [str1, str22, str3, str4]
	
		int size = al.size();
		System.out.println("size: "+size); // 4
		
		al.remove(2);
		System.out.println(al.toString()); // [str1, str22, str4]
	
		al.clear();
		System.out.println(al.toString()); // []
		
		al = null;
		System.out.println(al); // null
		
		
		System.out.println("\n********************\n");
		
		
		LinkedList<String> ll = new LinkedList<String>();
		
		ll.add("str1");
		ll.add("str2");
		ll.add("str3");
		ll.add("str4");
		System.out.println(ll.toString()); // [str1, str2, str3, str4]
		
		ll.add("str5");
		System.out.println(ll.toString()); // [str1, str2, str3, str4, str5]
		
		ll.add(2, "STR2");
		System.out.println(ll.toString()); // [str1, str2, STR2, str3, str4, str5]
	
		ll.set(2, "STR3");
		System.out.println(ll.toString()); // [str1, str2, STR3, str3, str4, str5]
	
		size = ll.size();
		System.out.println("size: "+size); // 6
		
		ll.remove(2);
		System.out.println(ll.toString()); // [str1, str2, str3, str4, str5]
	
		ll.clear();
		System.out.println(ll.toString()); // []
		
		ll = null;
		System.out.println(ll); // null

		
		System.out.println("\n********************\n");
		
		
		/*
		 * Map: No index, Key:Value. key만 있으면 된다.
		 * Set: 데이터의 순서는 없으나, 중복된 데이터는 허용하지 않음
		 */
		HashMap<Integer, String> hm = new HashMap<Integer, String>();
		
		hm.put(0,  "str0");
		hm.put(1,  "str1");
		hm.put(2,  "str3");
		hm.put(3,  "str2");
		System.out.println(hm.toString()); // {0=str0, 1=str1, 2=str3, 3=str2}
		
		Iterator<Integer> iterator = hm.keySet().iterator();
		while(iterator.hasNext()) {
			String string = hm.get(iterator.next());
			System.out.println(string);
		}
		
		String str = hm.get(2);
		System.out.println(str); // str3
		
		hm.remove(2);
		System.out.println(hm.toString()); // {0=str0, 1=str1, 3=str2}
	
		hm.clear();
		System.out.println(hm.toString()); // {}
		

		System.out.println("\n********************\n");
		
		
		HashSet<String> hs = new HashSet<String>();
		
		hs.add("str0");
		hs.add("str1");
		hs.add("str2");
		hs.add("str3");
		hs.add("str2");
		System.out.println(hs.toString()); // [str3, str1, str2, str0] - ?????????
		
		hs.remove("str0");
		System.out.println(hs.toString()); // [str3, str1, str2]
		
		int i = hs.size();
		System.out.println("size: "+i);
	}
}
