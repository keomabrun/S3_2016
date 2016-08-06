from bottle import route, run, static_file, template

import pandas as pd
import matplotlib.pyplot as plt

@route('/')
def hello():
    df = pd.read_csv("test.csv")
    plt.plot(df.index,df.val)
    plt.savefig('graphs.png')
    return static_file("web_page.html",".")

@route('/<name>')
def getfile(name):
    return static_file(name,".")

run(host="localhost", port=8080, debug=True)
