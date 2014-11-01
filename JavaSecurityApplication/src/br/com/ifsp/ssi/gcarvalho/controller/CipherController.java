package br.com.ifsp.ssi.gcarvalho.controller;

import java.util.ArrayList;
import java.util.List;

import javax.faces.bean.ManagedBean;
import javax.faces.bean.SessionScoped;

import br.com.ifsp.ssi.gcarvalho.model.Cipher;
import br.edu.ifsp.arq.cin.ads.ssi.HelloWorld;

@ManagedBean
@SessionScoped
public class CipherController {
	private Cipher cipher = new Cipher();
	private List<Cipher> cipherList = new ArrayList<Cipher>();
	
	public void setCipher(Cipher cipher) {
		this.cipher = cipher;
	}
	
	public Cipher getCipher() {
		return cipher;
	}
	
	public String gravar() {
		criptografar(cipher);
		cipherList.add(cipher);
		this.cipher = new Cipher();
		
		for (Cipher c : cipherList) {
			System.out.println("name " + c.getName());
			System.err.println("crypt " + c.getCryptMessage());
		}
		
		
		return "index?faces-redirect=true";
	}
	
	public List<Cipher> listar() {
		return cipherList;
	}
	
	private Cipher criptografar(Cipher cipher) {
		HelloWorld hw = new HelloWorld();
		String message;
		
		if (cipher.getName().equals("caesar")) {
		
			message = hw.caesar_crypt(cipher.getRawMessage(), cipher.getKey());
			
			cipher.setCryptMessage(message);
			
			message = hw.caesar_decrypt(message, cipher.getKey());
			
			cipher.setRawMessage(message);
			
		} else if (cipher.getName().equals("hill")) {
			
			message = hw.hill_crypt(cipher.getRawMessage(), cipher.getKey());
			
			cipher.setCryptMessage(message);
			
		} else if (cipher.getName().equals("otp")) {
			
			message = hw.otp_crypt(cipher.getRawMessage(), cipher.getKey());
			
			cipher.setCryptMessage(message);
			
			message = hw.otp_decrypt(message, cipher.getKey());
			
			cipher.setRawMessage(message);
			
		}
		
		return cipher;
	}
}
