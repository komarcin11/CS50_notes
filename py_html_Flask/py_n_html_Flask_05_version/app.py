from flask import Flask, render_template, request

app = Flask(__name__)

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/greet", methods = ["POST"]) 
def greet():
    return render_template("greet.html", _name= request.args.get("_name", "World"))
#the defulst is GET but you can change to post if in index.html u use "post"