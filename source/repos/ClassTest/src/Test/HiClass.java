package Test;

public class HiClass {
	private String name;
	private int age;
	
	public HiClass() {
		
	}
	public HiClass(String name, int age) {
		this.name = name;
		this.age = age;
	}
	
	// right click -> Source -> Generate Getters and Setters...
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public int getAge() {
		return age;
	}
	public void setAge(int age) {
		this.age = age;
	}
	
	public void print() {
		System.out.println("Name: "+this.name);
		System.out.println("Age: "+this.age);
	}
}
