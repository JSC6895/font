#encoding:utf-8

from flask import Flask

# import file

app = Flask(__name__)

@app.route('/')
def index():
	return  'hello world'

@app.route('/')
def logs():
	return 'sssss'
if __name__ == '__main__':
	app.run(host='0.0.0.0',port=9002,debug=True)