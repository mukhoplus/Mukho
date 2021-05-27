package com.mukho.io;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

// I/O 작업에서 반드시 해야 하는 예외처리: IOException. I/O 작업 마지막에는 close()를 꼭 해주어야 한다.
// DataInputStream/DataOutputStream: 문자열 읽기/쓰기
public class MainClass {
	public static void main(String[] args) {
		try {
			InputStream is = new FileInputStream("C:\\Users\\KoMoGoon\\Documents\\GitHub\\Mukho\\source\\repos\\inputoutput\\muk.txt");
			while(true) {
				int i = is.read();
				System.out.println("데이터: "+i);
				if(i == -1) break;
				is.close();
			} 
		} catch (Exception e) {
			System.out.println(e.getMessage());
		};
		
		OutputStream os = null;
		try {
			os = new FileOutputStream("C:\\Users\\KoMoGoon\\Documents\\GitHub\\Mukho\\source\\repos\\inputoutput\\ho.txt");
			String str = "앙 기모찌";
			byte[] bs = str.getBytes();
			os.write(bs);
		} catch (Exception e) {
			System.out.println("ㅄ");
		} finally{
			try {
				if(os != null) os.close();
			} catch (IOException e) {
				System.out.println(e.getMessage());
			}
		};
	}
}