from bottle import route, run, static_file, post, request

@route('/hello')
def hello():
    # return "Hello World!"
    return static_file("index.html",".") #adding external file in website

@post('/login')
def do_login():
    username = request.forms.get('username')
    password = request.forms.get('password') 
    return username, password

run(host='0.0.0.0', port=8080, debug=False)

