from flask import Flask, render_template, request

app = Flask(__name__)

@app.route("/")#it will run after the / in the ulr adress
def index():
    if "name" in request.args:
        name =request.args["name"]
    else:
        name = "world"
    return render_template("index.html", _name = name)