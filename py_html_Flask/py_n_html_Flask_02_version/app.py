from flask import Flask, render_template, request

app = Flask(__name__)

@app.route("/")#it will run after the / in the ulr adress
def index():
    name = request.args.get("name", "Wrold") #it gets the values from the /?name=.... and inserts into thr HTML. If no value it will return "None" but you can specyfi a defult values
    return render_template("index.html", _name = name)