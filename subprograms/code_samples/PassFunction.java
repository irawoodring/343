public class PassFunction {
	public static void main(String[] args){
		int a = Integer.parseInt(args[0]);
		int b = Integer.parseInt(args[1]);
		int op = Integer.parseInt(args[2]);
		DoStuff doStuff = new DoStuff();
		if(op != 0){
			System.out.println(doStuff.go(a, b, new Add()));
		} else {
			System.out.println(doStuff.go(a, b, new Mult()));
		}
	}
}
