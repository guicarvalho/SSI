# coding: utf-8

from flask import Flask, render_template, request
import algo_crypt


app = Flask(__name__)

message_list = []

total_each_cipher = {
	'caesar': 0,
	'otp': 0,
	'hill': 0
}

@app.route('/', methods=['GET', 'POST'])
def index():
	if request.method == 'POST':
		msg = request.form['message']
		key = requets.form['key']
		cipher = request.form['cipher']

		crypted_message = _crypt_message(msg, key)
		_add_message(msg, crypted_message)
		_increment_cipher(cipher)

	return render_template(
		'index.html', 
		caesar=total_each_cipher['caesar'], 
		otp=total_each_cipher['otp'],
		hill=total_each_cipher['hill'],
	)

def _crypt_message(msg, key):
	pass

def _add_message(raw_msg, crypt_msg):
	pass

def _increment_cipher(cipher):
	pass


if __name__ == "__main__":
	app.run(debug=True)