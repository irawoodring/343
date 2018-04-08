public class DoStuff {
	public int go(int a, int b, final Command command){
		return command.execute(a, b);
	}
}
