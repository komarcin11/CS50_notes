from flask import Flask, render_template, request, redirect
from cs50 import SQL

app = Flask(__name__)

db = SQL("sqlite:///form.db")

SPORTS = [
    "baseball",
    "basketball",
    "soccer"]

# in this version of the form there are coded options of the sport coded to server not to the HTML
# we add SQL to the data bese so the data will bea saved on the server
# so it is more protected from attacs


#done
@app.route("/")
def index():
    return render_template("index.html", sports = SPORTS)


@app.route("/deregister", methods=["POST"])
def deregister():
    #delete registrants
    id = request.form.get("id")
    if id:
        db.execute("DELETE FROM registrants WHERE id = ?", id)
    return redirect("/registrants")


#done
@app.route("/register", methods=["POST"])
def register():

    #validate submission
    name = request.form.get("Name")
    sport = request.form.get("Sport")
    if not name or sport not in SPORTS:
        return render_template("fail.html")
    
    #insert the data into the db
    db.execute("INSERT INTO registrants (name, sport) VALUES(?, ?)", name, sport)
    return redirect("/registrants")

#done
@app.route("/registrants")
def registrants():
    REGISTRANTS = db.execute("SELECT * FROM registrants")
    return render_template("registrants.html", registrants=REGISTRANTS)