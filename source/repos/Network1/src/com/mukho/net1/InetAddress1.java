package com.mukho.net1;

import java.net.InetAddress;
import java.util.Scanner;


public class InetAddress1 {
	Scanner scanner;
	
	public InetAddress1() {
		System.out.println("Hose Name: ");
		scanner = new Scanner(System.in);
		
		try {
			InetAddress inetAddress = InetAddress.getByName(scanner.next());
			
			System.out.println("Computer Name: "+inetAddress.getHostName());
			System.out.println("Computer IP: "+inetAddress.getHostAddress());
		} catch(Exception e){
			System.out.println(e.getMessage());
		}
	}
}
