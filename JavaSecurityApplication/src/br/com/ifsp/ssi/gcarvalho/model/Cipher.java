package br.com.ifsp.ssi.gcarvalho.model;

public class Cipher {
	private String rawMessage;
	private String cryptMessage;
	private String name;
	private int key;

	public Cipher() {
	}
	
	public Cipher(String rawMessage, String cryptMessage, String cipher, int key) {
		super();
		this.rawMessage = rawMessage;
		this.cryptMessage = cryptMessage;
		this.name = cipher;
		this.key = key;
	}
	
	public String getRawMessage() {
		return rawMessage;
	}
	public void setRawMessage(String rawMessage) {
		this.rawMessage = rawMessage;
	}
	public String getCryptMessage() {
		return cryptMessage;
	}
	public void setCryptMessage(String cryptMessage) {
		this.cryptMessage = cryptMessage;
	}
	public String getName() {
		return name;
	}
	public void setName(String cipher) {
		this.name = cipher;
	}
	public int getKey() {
		return key;
	}
	public void setKey(int key) {
		this.key = key;
	}
	
	
}
