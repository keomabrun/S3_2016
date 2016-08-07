from bottle import route, run, static_file, template

import pandas as pd #importing libraries and changing their names
import matplotlib
matplotlib.use("Pdf")
import matplotlib.pyplot as plt
import datetime
import time 

@route('/')
def hello():
    # loading data
    df = pd.read_csv("/home/pi/data.csv")
    df["date"] = pd.to_datetime(df.time,unit='s')

    # plot design
    plt.ylabel('Moisture (%)', fontsize=18)
    plt.xlabel('Time', fontsize=16)
    plt.gcf().autofmt_xdate()
    axes = plt.gca()
    axes.set_ylim([0,100])

    # plotting
    plt.plot(df.date,df.val)
    plt.savefig('graphs.png')

    return static_file("web_page.html",".")

@route('/<name>')
def getfile(name):
    return static_file(name,".")

run(host="0.0.0.0", port=8080, debug=True)
