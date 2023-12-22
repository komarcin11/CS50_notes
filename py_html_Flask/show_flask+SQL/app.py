from flask import Flask, render_template, request
from cs50 import SQL

app = Flask(__name__)

db = SQL("sqlite:///shows2.db")

# index.html not done
@app.route("/")
def index():
    return render_template("index.html")

# search.html not done
@app.route("/search")
def search():
    shows = db.execute("select title from shows where title like ?", "%" + request.args.get("q") +"%")
    # print(shows)#just to check later commentout
    print(len(shows), " :resaults")
    return render_template("search.html", shows = shows)

