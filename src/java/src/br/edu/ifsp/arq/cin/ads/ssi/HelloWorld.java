package br.edu.ifsp.arq.cin.ads.ssi;

public class HelloWorld {

	public native void helloFromC();

	public native String crypt(String msg);

	static {
		System.loadLibrary("helloc");
	}

	public static void main(String[] args) {
		System.out.println("Hello world!");
		
		HelloWorld hw = new HelloWorld();
		hw.helloFromC();
		String crypted = hw.crypt("Sent from Java");
		System.out.println("Received from C: " + crypted);
	}

}

