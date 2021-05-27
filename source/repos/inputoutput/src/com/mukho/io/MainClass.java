package com.mukho.io;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

// I/O �۾����� �ݵ�� �ؾ� �ϴ� ����ó��: IOException. I/O �۾� ���������� close()�� �� ���־�� �Ѵ�.
// DataInputStream/DataOutputStream: ���ڿ� �б�/����
public class MainClass {
	public static void main(String[] args) {
		try {
			InputStream is = new FileInputStream("C:\\Users\\KoMoGoon\\Documents\\GitHub\\Mukho\\source\\repos\\inputoutput\\muk.txt");
			while(true) {
				int i = is.read();
				System.out.println("������: "+i);
				if(i == -1) break;
				is.close();
			} 
		} catch (Exception e) {
			System.out.println(e.getMessage());
		};
		
		OutputStream os = null;
		try {
			os = new FileOutputStream("C:\\Users\\KoMoGoon\\Documents\\GitHub\\Mukho\\source\\repos\\inputoutput\\ho.txt");
			String str = "�� �����";
			byte[] bs = str.getBytes();
			os.write(bs);
		} catch (Exception e) {
			System.out.println("��");
		} finally{
			try {
				if(os != null) os.close();
			} catch (IOException e) {
				System.out.println(e.getMessage());
			}
		};
	}
}