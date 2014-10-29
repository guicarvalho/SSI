package br.edu.ifsp.arq.cin.ads.ssi;

public class HelloWorld {

	// Caesar cipher
	public native String caesar_crypt(String msg, int shift);
	public native String caesar_decrypt(String msg, int shift);

	// One-time-pad cipher
	public native String otp_crypt(String msg, int shift);
	public native String otp_decrypt(String msg, int shift);

	// Hill cipher
	public native String hill_crypt(String msg, char[] alphabet, int[][] matrix_key);
	public native String hill_decrypt(String msg, char[] alphabet, int[][] matrix_key);

	static {
		System.loadLibrary("helloc");
	}

	public static void main(String[] args) {
		HelloWorld hw = new HelloWorld();

		String s = hw.caesar_crypt("guilherme", 3);
		System.out.println("Crypt [CAESAR]: " + s);
		s = hw.caesar_decrypt(s, 3);
		System.out.println("Decrypt [CAESAR]: " + s);


		char[] alphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
		int[][] matrix_key = {{3, 2}, {5, 7}};

		s = hw.hill_crypt("guilherme", alphabet, matrix_key);
		System.out.println("Crypt [HILL]: " + s);

		s = hw.otp_crypt("guilherme", 3);
		System.out.println("Crypt [OTP]: " + s);
		s = hw.otp_decrypt(s, 3);
		System.out.println("Decrypt [OTP]: " + s);
	}

}

