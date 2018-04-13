public class Counter implements Runnable {

	private int my_num;
	
	public Counter(int my_num){
		this.my_num = my_num;
	}

	public void run(){
		System.out.println("Hello from " + my_num + "!");
	}

	public static void main(String[] args){
		Thread[] threads = new Thread[10];
		for(int i=0; i<10; i++){
			threads[i] = new Thread(new Counter(i));
			threads[i].start();
		}

		for(int i=0; i<10; i++){
			try{
				threads[i].join();
			} catch (Exception ex){

			}
		}
	}

}
