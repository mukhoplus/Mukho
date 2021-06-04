package com.mukho.net2;
import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.net.URL;
import java.net.URLConnection;
import java.util.Scanner;

public class URLConnection1 {
	public URLConnection1() {
		String code = null;
		System.out.println("Enter the Web Address: ");
		Scanner scanner = new Scanner(System.in);
		String address = scanner.next();
		
		try {
			URL url = new URL(address);
			URLConnection con = url.openConnection();
			BufferedReader webData = new BufferedReader(new InputStreamReader(con.getInputStream()));
			FileWriter fw = new FileWriter("C:\\Users\\KoMoGoon\\Desktop\\file.html", false);
			
			while((code = webData.readLine()) != null) {
				fw.write(code);
			}
			System.out.println("The End");
			
			fw.close();
			webData.close();
		}catch(Exception e) {
			e.printStackTrace();
		}
	}
}