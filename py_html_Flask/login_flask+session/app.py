from flask import Flask, render_template, request, redirect, session
from flask_session import Session

#config app
app = Flask(__name__)

#config session
app.config["SESSION_PERMENENT"]= False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)


#def and html done
@app.route("/")
def index():
    if not session.get("name"):
        return redirect("/login")
    return render_template("index.html")

#def and html done
@app.route("/login", methods=["GET", "POST"])
def login():
    if request.method == "POST":
        session["name"] = request.form.get("name")
        return redirect("/")
    return render_template("login.html")


#html not done def not sure
@app.route("/logout")
def logout():
    session["name"]=None
    return redirect("/")