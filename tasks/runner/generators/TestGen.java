import java.io.*;
import java.util.*;

public class TestGen {

	static PrintWriter out;
	static Random rnd = new Random(42);
	static int tNumber;
	static void printTest(ArrayList<Integer> points) throws IOException {
		if (tNumber < 10)
			out = new PrintWriter("../tests/tests/0" + tNumber);
		else
			out = new PrintWriter("../tests/tests/" + tNumber);
		tNumber++;               
		out.println(points.size() / 2);
		for (int i = 0; i < points.size(); i += 2)
			out.println(points.get(i) + " " + points.get(i + 1));
		out.close();
	}
	static void genSample() throws FileNotFoundException {
		out = new PrintWriter("../tests/01");
		out.println("7\r\n2 4\r\n4 3\r\n7 2\r\n7 5\r\n9 7\r\n5 8\r\n2 7");
		out.close();
	}
	static int randFromTo(int l, int r) {
		return rnd.nextInt(r - l + 1) + l;		
	}
	static ArrayList<Integer> genPoints(int n, int maxD) {
		ArrayList<Integer> list = new ArrayList<Integer>();
		for (int i = 0; i < n; i++) {
			list.add(randFromTo(-maxD, maxD));
			list.add(randFromTo(-maxD, maxD));
		}
		return list;				
	}


	public static void main(String[] args) throws IOException {
		tNumber = 1;
		for (int i = 0; i < 5; i++) {
			int n = randFromTo(2, 20);
			printTest(genPoints(n, randFromTo(10, 15)));
		}
		for (int i = 0; i < 10; i++) {
			int n = randFromTo(20, 50);
			printTest(genPoints(n, randFromTo(20, 50)));
		}
		for (int i = 0; i < 15; i++) {
			int n = randFromTo(50, 100);
			printTest(genPoints(n, randFromTo(50, 100)));
		}
		for (int i = 0; i < 20; i++) {
			int n = randFromTo(250, 300);
			printTest(genPoints(n, randFromTo(50, 300)));
		}
	}
}
