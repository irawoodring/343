public class Counter implements Runnable{
	private int c = 0;

	public int getC(){
		return c;
	}

	public void increment() {
		Thread.sleep(100);
		c++;
	}

	public void decrement() {
		c--;
	}

	public int value() {
		return c;
	}

	public void run(){
		for(int i=0; i<1000; i++){
			System.out.println("Incrementing.");
			increment();
		}
	}

	public static void main(String[] args){
		Counter c = new Counter();
		Thread one = new Thread(c);
		Thread two = new Thread(c);
		one.start();
		two.start();
		try{
			one.join();
			two.join();
		} catch(Exception ex){}
		System.out.println(c.getC());
	}

}
