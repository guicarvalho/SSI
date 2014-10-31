package br.com.ifsp.ssi.gcarvalho.controller;

import javax.swing.JOptionPane;

import br.edu.ifsp.arq.cin.ads.ssi.HelloWorld;

public class Test {
	
	public Test() {
		
	}
	
	public static void main(String[] args) {
		String s = new HelloWorld().caesar_crypt("a", 3);
		String s2 = new HelloWorld().caesar_decrypt(s, 3);
		JOptionPane.showMessageDialog(null, s + "---" + s2);
		
		System.out.println(System.getProperty("java.library.path"));
	}
}
