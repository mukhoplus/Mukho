package Test;

public class Hi {
	public static void main(String[] args) {
		HiClass hi1 = new HiClass();
		HiClass hi2 = new HiClass("ITX û��", 23);
		HiClass hi3 = new HiClass("Made By Google", 20);
		
		hi1.setName("��ȣ");
		hi1.setAge(25);
		
		hi1.print();
		hi2.print();
		hi3.print();
	}
}
