from flask import Flask, render_template, request

app = Flask(__name__)

REGISTRANTS = {}

SPORTS = [
    "baseball",
    "basketball",
    "soccer"]

# in this version of the form there are coded options of the sport coded to server not to the HTML
# so it is more protected from attacs

@app.route("/")
def index():
    return render_template("index.html", sports = SPORTS)

@app.route("/register", methods=["POST"])
def register():
    name = request.form.get("Name")
    if not name:
        return render_template("fail.html")
    sport = request.form.get("Sport")
    if sport not in SPORTS:
        return render_template("fail.html")
    REGISTRANTS[name] = sport
    return render_template("info.html")

@app.route("/registrants")
def registrants():
    return render_template("registrants.html", registrants=REGISTRANTS)