from bottle import route, run, static_file, template

import numpy as np
import pandas as pd

import matplotlib.pyplot as plt

@route('/<filename>')
def hello(filename):
    #return "Hello World!"
    return static_file(filename,".")

@route('/plot/')
def graph():
    df = pd.read_csv("test.csv")
    plt.plot(df.index,df.val)
    plt.savefig('graphs.png')

    return template(
        '''<h1>Congrats!</h1>
        <div>
          <img src="../graphs.png">
        </div>
        '''
    )

run(host='localhost', port=8080, debug=True)

