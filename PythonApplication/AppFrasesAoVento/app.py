# coding: utf-8

from flask import Flask, render_template, request

import algo_crypt
import datetime
import string
import ipdb
import sys

reload(sys)
sys.setdefaultencoding('utf-8')


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

@app.route('/list/<cipher>', methods=['GET'])
def list(cipher):
	# ipdb.set_trace()
	# return str(_list_messages(cipher))
	return render_template(
		'list.html',
		chiper_name=cipher,
		message_list=_list_messages(cipher),
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
	global message_list
	obj = {
		'cipher': cipher,
		'raw_msg': raw_msg,
		'crypt_msg': crypt_msg.decode('utf-8', 'replace'),
		'date_joined': str(datetime.datetime.now())
	}

	message_list.append(obj)

def _list_messages(cipher):
	cipher_message_list = []

	for obj in message_list:
		if obj['cipher'] == cipher:
			cipher_message_list.append(obj)

	return cipher_message_list

def _increment_cipher(cipher):
	total_each_cipher[cipher] += 1


if __name__ == "__main__":
	app.run(debug=True)
