# coding: utf-8

from flask import Flask, render_template, request
import algo_crypt
import datetime
import string
import ipdb


app = Flask(__name__)

# alphabet used in hill cipher
alphabet = string.ascii_letters[:26]

# default set key for hill cipher
matrix_key = [
	[6, 2],
	[11, 3]
]

message_list = []

total_each_cipher = {
	'caesar': 0,
	'otp': 0,
	'hill': 0
}

@app.route('/', methods=['GET', 'POST'])
def index():
	# ipdb.set_trace()
	if request.method == 'POST':
		msg = request.form['message']
		key = request.form['key']
		cipher = request.form['cipher']

		crypted_message = _crypt_message(msg, key, cipher)
		_add_message(msg, crypted_message, cipher)
		_increment_cipher(cipher)

	return render_template(
		'index.html', 
		caesar=total_each_cipher['caesar'], 
		otp=total_each_cipher['otp'],
		hill=total_each_cipher['hill'],
	)

def _crypt_message(msg, key, cipher):

	message = ''

	key = int(key)

	if cipher == 'caesar':
		message = algo_crypt.caesar_crypt(msg, key)

	elif cipher == 'otp':
		message = algo_crypt.otp_crypt(msg, key)

	elif cipher == 'hill':
		message = algo_crypt.hill_crypt(msg, alphabet, matrix_key)

	return message

def _add_message(raw_msg, crypt_msg, cipher):
	obj = {
		'cipher': cipher,
		'raw_msg': raw_msg,
		'crypt_msg': crypt_msg,
		'date_joined': str(datetime.datetime.now())
	}

	message_list.append(obj)

def _increment_cipher(cipher):
	total_each_cipher[cipher] += 1


if __name__ == "__main__":
	app.run(debug=True)