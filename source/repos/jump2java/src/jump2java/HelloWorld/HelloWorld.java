package jump2java.HelloWorld;

/*
  ... iss Crew
  ... Made By Mukho
  ... 2020-07-13 MON
  ... JAVA Practice
 */
import java.io.InputStream;
import java.util.Scanner;

public class HelloWorld {

	public static void main(String[] args) {
		InputStream in = System.in;
		
		int text;
		text = in.read();
		
		System.out.println(text);
	}

	// 초기 설정, 문법 등 외의 것들이 C와 유사하다.
	/* String
	 *  String text = "wow"; == String text = new String("wow");
	 	text.equals(str) <- text와 str이 같은지 비교
	 	text.indexOf("o") <- o가 시작되는 위치를 반환
	 	text.replaceAll("w", "i") -> wow에서 w를 i로 변환 ioi
	 	text.substring(1,2) -> index 1부터 2까지 출력
	 	toUpperCase / toLowerCase
	 */
	/* StringBuffer
	 * StringBuffer temp = new StringBuffer(); // 문자열 추가나 변경등의 작업이 많을 경우 스트링버퍼 사용에 유리
	 * temp.append("??");
	 * System.out.println(toString(temp)); -> ??
	 * temp.insert(1,"fdzz") ?fdzz?
	 * substring
	 */
	 /* Array
	  * String[] weeks = new String[7];
	  * array's length => weeks.length
	  * 
	  */
	/* List (Array, Linked, ...)
	 * ArrayList speed = new ArrayList(); // ArrayList<String> speed
	 * speed.add("100");
	 * speed.add("135");
	 * speed.add(0, "87");
	 * spped.get(1) -> 100
	 * speed.size() -> 3
	 * speed.contains("70") -> false
	 * speed.remove(0) -> 87 삭제
	 * speed.remove("87") -> 87 삭제
	 */
	/*
	 *  Generics == C++에서의 Template
	 *  Map == Python에서의 Dictionary
	 *  (간단한 맵 중 하나) HashMap<String, String> map = new HashMap<String, String>();
	 *  map.put("vip","묵 호");
	 *  map.put("무요","ITX 청춘");
	 *  map.get("무요") -> "ITX 청춘"
	 *  map.containsKey("vvip") -> false
	 *  map.remove("vip")
	 *  map.size() -> 2
	 *  
	 *  LinkedListMap -> 입력된 순서대로 데이터가 출력됨
	 *  TreeMap -> 입력된 Key의 정렬 순으로 데이터가 출력됨
	 */
	
	/* 
	 * 파이썬에서의 for item in list_ 와 같은 for each
	 * 
	 * for (String item: items) { System.out.println(item); }
	 */
	/* Object-Oriented Programming
	 * Class-Object-Method
	 * Call-by-value / Call-by-reference
	 * Interface : setName, getName, show, setName 같은 것을 메소드 오버로딩 보다 편하게 만들 수 있는?
	 * public class Lion extend Animal implements Predator{}
	 * public void feed(Predator predator){} -> 육식동물에게 밥을 준다
	 * 
	 * public interface Predator{
	 * 		public String getFood();
	 * }
	 * public class ZooKeeper {    
       public void feed(Predator predator) {
       System.out.println("feed "+predator.getFood());
    }
}
	 * 
	 * 추상 클래스 : 인터페이스의 역할도 하면서 구현체도 가지고 있는 클래스(abstract class)
	 */
	/* Scanner : next(단어), nextLine(라인), nextInt(정수)
	 * 파일 입출력 : import java.io.FileOutputStream; java.io.IOException;
	 * ...
	 * public static void main(String[] args) thorows IOException{
	 * 		FileOutputStream output = new FileOutputStream("c:/out.txt");
	 * 		output.close();
	 * }
	 * public class FileWrite {
		   public static void main(String[] args) throws IOException {
		        FileOutputStream output = new FileOutputStream("c:/out.txt");
		        for(int i=1; i<11; i++) {
		            String data = i+" 번째 줄입니다.\r\n";
		            output.write(data.getBytes());
		        }
		        output.close();
		   }
		   
		}
		public class FileWrite {
		    public static void main(String[] args) throws IOException {
		        FileWriter fw = new FileWriter("c:/out.txt");
		        for(int i=1; i<11; i++) {
		            String data = i+" 번째 줄입니다.\r\n";
		            fw.write(data);
		        }
		        fw.close();
		    }
		}
		
		
	import java.io.IOException;
	import java.io.PrintWriter;
	
	public class FileWrite {
	    public static void main(String[] args) throws IOException {
	        PrintWriter pw = new PrintWriter("c:/out.txt");
	        for(int i=1; i<11; i++) {
	            String data = i+" 번째 줄입니다.";
	            pw.println(data);
	        }
	        pw.close();
	    }
	}
	
	import java.io.FileWriter;
	import java.io.IOException;
	
	public class FileWrite {
	    public static void main(String[] args) throws IOException {
	        FileWriter fw = new FileWriter("c:/out.txt");
	        for(int i=1; i<11; i++) {
	            String data = i+" 번째 줄입니다.\r\n";
	            fw.write(data);
	        }
	        fw.close();
	
	        FileWriter fw2 = new FileWriter("c:/out.txt", true);
	        for(int i=11; i<21; i++) {
	            String data = i+" 번째 줄입니다.\r\n";
	            fw2.write(data);
	        }
	        fw2.close();
	    }
	}
	
	import java.io.FileWriter;
	import java.io.IOException;
	import java.io.PrintWriter;
	
	public class FileWrite {
	    public static void main(String[] args) throws IOException {
	        PrintWriter pw = new PrintWriter("c:/out.txt");
	        for(int i=1; i<11; i++) {
	            String data = i+" 번째 줄입니다.";
	            pw.println(data);
	        }
	        pw.close();
	
	
	        PrintWriter pw2 = new PrintWriter(new FileWriter("c:/out.txt", true));
	        for(int i=11; i<21; i++) {
	            String data = i+" 번째 줄입니다.";
	            pw2.println(data);
	        }
	        pw2.close();
	    }
	}
	
	import java.io.FileInputStream;
	import java.io.IOException;
	
	public class FileRead {
	    public static void main(String[] args) throws IOException {
	        byte[] b = new byte[1024];
	        FileInputStream input = new FileInputStream("c:/out.txt");
	        input.read(b);
	        System.out.println(new String(b));
	        input.close();
	    }
	}
	
	import java.io.BufferedReader;
	import java.io.FileReader;
	import java.io.IOException;
	
	public class FileRead {
	    public static void main(String[] args) throws IOException {
	        BufferedReader br = new BufferedReader(new FileReader("c:/out.txt"));
	        while(true) {
	            String line = br.readLine();
	            if (line==null) break;
	            System.out.println(line);
	        }
	        br.close();
	    }
	}
	 */
}
