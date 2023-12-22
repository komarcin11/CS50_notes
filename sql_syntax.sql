writing everything in terminal
-- is comments
--main functions
sqlite3 -- that will open the sqlite3 program
.mode csv -- that will switch the sql to csv mode
.import favorites.csv favorites -- here you import a .csv file and puting it into a "favorites" database-- still data base hasnt been saved
.schema -- this will inform you what sql did
.mode table -- will change to an user friendly table
.timer on -- turns on the timer so you can take note how long does you querie takes time to execute

--__________________
-- SQL operators --- the following key action keywords are the essence of the language
-- CREATE, INSERT
-- SELECT 
-- UPDATE
-- DELETE, DROP
--__________________

--queries
--if you want to see what is in the data base you write as follows
SELECT * FROM favorits; -- SELECT (sql will select/show) * (from all the columns) FROM favorits (here u specify the database)
.save favorites.db -- this will save the database
.import
.open favorites.db;-- after closing sql you can open the data base with 
select name from favorites;-- will select/show you only from the name column

--__________________
-- SQL functions
-- AVG
-- COUNT
-- DISTINCTW
-- LOWER
-- MAX
-- MIN
-- UPPER and many more
--__________________

select count(*) from favorites; -- how many rows there are in the data base
select distinct(languages) from favorites; -- that will show you a list of from the "language" columen of the elements but without duplicates only distinct
select count(distinct(languages)) from favorites; -- that will show the amount of the distinct values in the "language" columen
select count(DISTINCT(language)) as number_of_languages from favorites; -- "as" will give an alias of the count(DISTINCT(language))
SELECT count(*) FROM favorites WHERE language = 'C';-- select(shoe) count(*)(the amount) FROM favorites(the database) WHERE language = 'C' (that is self explanatory)('' - in string)
SELECT count(*) as C_count from favorites where LANGUAGE = 'Python' AND name = 'Laura Lee'; -- as above it will show 

--_______________________________
-- CONDITION/FILTERS
--the following are key words thhat can help to filter and narrow down the data that you want to manipulate
--WHERE
--LIKE
--ORDER
--LIMIT
--GROUP BY 
--______________________________

SELECT language, count(*) FROM favorites GROUP BY language; -- SELECT(show) language(a column), count(*)(creata a colum that keeps count) FROM favorites(from favorites table) GROUP BY language(and show them by language)
--the above command will show you how many of the values in the language column are there of 

SELECT language, count(*) FROM favorites GROUP BY language ORDER BY COUNT(*);
-- the above command will show you the same thing but orderder, in defult in acsending order (ASC)

SELECT language, count(*) FROM favorites GROUP BY language ORDER BY COUNT(*) DESC;
-- the above command will show you the list in descending order

SELECT language, count(*) FROM favorites GROUP BY language ORDER BY COUNT(*) DESC LIMIT 3;
-- the above command will show you the list in descending order and only show 3 values, in this instance 3 of tthe highest values of the count based on languages amount

INSERT INTO favorites (language, name) VALUES('SQL', 'Gabrysia Jasiona');
-- the above command will INSERT a row INTO the favorites table in coulmns (language, name) and will give them VALUES('SQL', 'Gabrysia Jasiona')(Self-explanatory)

SELECT * FROM favorites WHERE language = 'C';
-- the above command will show you the table only where the values in the language column is equel 'C' (single quotes)

SELECT * FROM favorites WHERE language LIKE 'c';
-- the above command will show you the table only where the values in the language column is like 'c' (soo similar but will not look into capitalizations)
-- the LIKE keyword has a lot of functionalytie

UPDATE favorites SET language = 'Java' WHERE language = 'Ja';
-- the above command will UPDATE(change) from the favorites table SETing it to language = 'Java' in row WHERE in column language = 'Ja'

DELETE FROM favorites WHERE language ='';
-- the above command will delete rows from the favorites table where language in not filled in

DELETE FROM favorites;
-- will delete all of the table (do not execute witout backup)

--______________________________
-- SQL variable types
BLOB - binary lineral object (what ever that is)
INTEGER
NUMERIC - a formated number like data yyyy/mm/dd or yyyy/dd/mm
REAL - synonym to float
TEXT 
NOT NULL
--______________________________

--column specifiers
NOT NULL -- means not empty spaces
UNIQUE -- so the elements in this column are unique S
--after running .schema command will appere the overview of the database, lets focun on two tables pointed out below
--the below is the sql output from the show.db after running .schema command
CREATE TABLE shows (
                    id INTEGER,
                    title TEXT NOT NULL,
                    year NUMERIC,
                    episodes INT,
                    PRIMARY KEY(id)
                );
CREATE TABLE genres (
                    show_id INTEGER NOT NULL,
                    genre TEXT NOT NULL,
                    FOREIGN KEY(show_id) REFERENCES shows(id)
                );
CREATE TABLE stars (
                show_id INTEGER NOT NULL,
                person_id INTEGER NOT NULL,
                FOREIGN KEY(show_id) REFERENCES shows(id),
                FOREIGN KEY(person_id) REFERENCES people(id)
            );
CREATE TABLE writers (
                show_id INTEGER NOT NULL,
                person_id INTEGER NOT NULL,
                FOREIGN KEY(show_id) REFERENCES shows(id),
                FOREIGN KEY(person_id) REFERENCES people(id)
            );
CREATE TABLE ratings (
                show_id INTEGER NOT NULL,
                rating REAL NOT NULL,
                votes INTEGER NOT NULL,
                FOREIGN KEY(show_id) REFERENCES shows(id)
            );
CREATE TABLE people (
                id INTEGER,
                name TEXT NOT NULL,
                birth NUMERIC,
                PRIMARY KEY(id)
            );

--shows.db
select * from people LIMIT 10;--here we can see all the columns from the people table in the tv buisnes limited to 10 valus
SELECT * FROM stars LIMIT 10;-- now we can see all the columns from the stars table and all of them are id, that is foreign key
+---------+-----------+
| show_id | person_id |
+---------+-----------+
| 62614   | 378823    |
| 62614   | 393936    |
| 62614   | 853892    |
| 62614   | 496420    |
| 62614   | 333162    |
| 62614   | 180174    |
| 62614   | 165183    |
| 62614   | 466749    |
| 63881   | 625401    |
| 63881   | 1933      |
+---------+-----------+

select * from genres where genre = 'Comedy' Limit 10;-- so here we can see all the show id (foreign key) with the assign genres
+---------+--------+
| show_id | genre  |
+---------+--------+
| 62614   | Comedy |
| 63881   | Comedy |
| 65270   | Comedy |
| 65271   | Comedy |
| 65273   | Comedy |
| 65274   | Comedy |
| 65276   | Comedy |
| 65283   | Comedy |
| 65285   | Comedy |
| 65287   | Comedy |
+---------+--------+

Select * from shows where id = 62614;-- to find show you can do this but theres better way 
+-------+-------------+------+----------+
|  id   |    title    | year | episodes |
+-------+-------------+------+----------+
| 62614 | Zeg 'ns Aaa | 1981 | 214      |
+-------+-------------+------+----------+

SELECT show_id FROM genres WHERE genre = 'Comedy' LIMIT 10;-- as understood this will give us the show_id (foreign key)form the genres table
SELECT COUNT(show_id) FROM genres WHERE genre = 'Comedy'; -- just a remaninder of count function
+----------------+
| COUNT(show_id) |
+----------------+
| 38432          |
+----------------+

SELECT title FROM shows WHERE id IN (SELECT show_id FROM genres WHERE genre = 'Comedy' ); -- this is called nesting use one table to get valuse from another
-- in my own words u search for values from one table (with use of foreign keys) and use it to get values that are a Primary key in another

SELECT title FROM shows WHERE id IN (SELECT show_id FROM genres WHERE genre = 'Comedy' )LIMIT 10 ;/ soo in here are nested values from the genres table in shows table
+-----------------------------+
|            title            |
+-----------------------------+
| Zeg 'ns Aaa                 |
| Catweazle                   |
| The Adventures of Don Quick |
| Albert and Victoria         |
| Archie's Funhouse           |
| Arnie                       |
| Barefoot in the Park        |
| Comedy Tonight              |
| The Culture Vultures        |
| Make Room for Granddaddy    |
+-----------------------------+

SELECT title, year FROM shows WHERE year = '2013' AND id IN (SELECT show_id FROM genres WHERE genre = 'Comedy' ) ORDER BY title LIMIT 20;-- here just having fun combining filters and conditionals

-- now a idea of nesting divided in to smaller problems
select * FROM people WHERE name LIKE 'Steve Carell'; -- searching for 'Steve Carell' in people table
select id FROM people WHERE name LIKE 'Steve Carell'; -- getting only the id in person table
SELECT * FROM stars WHERE person_id IN (select id FROM people WHERE name LIKE 'Steve Carell'); -- nesting that id into the stars id
SELECT * FROM stars WHERE person_id = (select id FROM people WHERE name LIKE 'Steve Carell'); -- or with use =
SELECT show_id FROM stars WHERE person_id = (select id FROM people WHERE name LIKE 'Steve Carell'); -- geting only the show_id from the stars table
SELECT title FROM shows WHERE id IN (SELECT show_id FROM stars WHERE person_id = (select id FROM people WHERE name LIKE 'Steve Carell')); -- here we use the outputed from the stars table id to get the shows titles
+------------------------------------+
|               title                |
+------------------------------------+
| The Dana Carvey Show               |
| Over the Top                       |
| Watching Ellie                     |
| Come to Papa                       |
| The Office                         |
| Entertainers with Byron Allen      |
| The Naked Trucker and T-Bones Show |
| Made in Hollywood                  |
| ES.TV HD                           |
| Mark at the Movies                 |
| Inside Comedy                      |
| Rove LA                            |
| Metacafe Unfiltered                |
| Fabrice Fabrice Interviews         |
| Riot                               |
| Séries express                     |
| Hollywood Sessions                 |
| IMDb First Credit                  |
| First Impressions with Dana Carvey |
| The Morning Show                   |
| LA Times: The Envelope             |
+------------------------------------+

SELECT title FROM shows WHERE id IN (SELECT show_id FROM stars WHERE person_id = (select id FROM people WHERE name LIKE 'Steve Carell')) ORDER BY title;
-- the same thing but with ordering by name

--______________________________
JOIN 
--__________________

sqlite> SELECT * FROM shows LIMIT 10; -- u know that 
+-------+-----------------------------+------+----------+
|  id   |            title            | year | episodes |
+-------+-----------------------------+------+----------+
| 62614 | Zeg 'ns Aaa                 | 1981 | 214      |
| 63881 | Catweazle                   | 1970 | 26       |
| 63962 | UFO                         | 1970 | 26       |
| 65269 | Ace of Wands                | 1970 | 46       |
| 65270 | The Adventures of Don Quick | 1970 | 6        |
| 65271 | Albert and Victoria         | 1970 | 12       |
| 65272 | All My Children             | 1970 | 3914     |
| 65273 | Archie's Funhouse           | 1970 | 23       |
| 65274 | Arnie                       | 1970 | 48       |
| 65276 | Barefoot in the Park        | 1970 | 12       |
+-------+-----------------------------+------+----------+

sqlite> SELECT * FROM genres LIMIT 10;-- u know that 
+---------+-----------+
| show_id |   genre   |
+---------+-----------+
| 62614   | Comedy    |
| 63881   | Adventure |
| 63881   | Comedy    |
| 63881   | Family    |
| 63962   | Action    |
| 63962   | Sci-Fi    |
| 65269   | Family    |
| 65269   | Fantasy   |
| 65270   | Comedy    |
| 65270   | Sci-Fi    |
+---------+-----------+

-- and below it could be combines joined
sqlite> SELECT * FROM shows JOIN genres ON shows.id=genres.show_id WHERE title = 'The Office';
+---------+------------+------+----------+---------+--------+
|   id    |   title    | year | episodes | show_id | genre  |
+---------+------------+------+----------+---------+--------+
| 112108  | The Office | 1995 | 6        | 112108  | Comedy |
| 290978  | The Office | 2001 | 14       | 290978  | Comedy |
| 290978  | The Office | 2001 | 14       | 290978  | Drama  |
| 386676  | The Office | 2005 | 188      | 386676  | Comedy |
| 1791001 | The Office | 2010 | 30       | 1791001 | Comedy |
| 2186395 | The Office | 2012 | 8        | 2186395 | Comedy |
| 8305218 | The Office | 2019 | 28       | 8305218 | Comedy |
+---------+------------+------+----------+---------+--------+

-- you can use JOIN in relational db like below but as you can see it takes more time
sqlite> SELECT title FROM people
   ...> JOIN stars ON people.id=stars.person_id
   ...> JOIN shows ON stars.show_id = shows.id
   ...> WHERE name = 'Steve Carell';
+------------------------------------+
|               title                |
+------------------------------------+
| The Dana Carvey Show               |
| Over the Top                       |
| Watching Ellie                     |
| Come to Papa                       |
| The Office                         |
| Entertainers with Byron Allen      |
| The Naked Trucker and T-Bones Show |
| Made in Hollywood                  |
| ES.TV HD                           |
| Mark at the Movies                 |
| Inside Comedy                      |
| Rove LA                            |
| Metacafe Unfiltered                |
| Fabrice Fabrice Interviews         |
| Riot                               |
| Séries express                     |
| Hollywood Sessions                 |
| IMDb First Credit                  |
| First Impressions with Dana Carvey |
| The Morning Show                   |
| LA Times: The Envelope             |
+------------------------------------+
Run Time: real 9.612 user 1.046875 sys 3.859375

-- but here without using JOIN we used related db to get quicer data
sqlite> SELECT title FROM people, stars, shows
   ...> WHERE people.id = stars.person_id
   ...> AND stars.show_id = shows.id
   ...> AND name = 'Steve Carell';
+------------------------------------+
|               title                |
+------------------------------------+
| The Dana Carvey Show               |
| Over the Top                       |
| Watching Ellie                     |
| Come to Papa                       |
| The Office                         |
| Entertainers with Byron Allen      |
| The Naked Trucker and T-Bones Show |
| Made in Hollywood                  |
| ES.TV HD                           |
| Mark at the Movies                 |
| Inside Comedy                      |
| Rove LA                            |
| Metacafe Unfiltered                |
| Fabrice Fabrice Interviews         |
| Riot                               |
| Séries express                     |
| Hollywood Sessions                 |
| IMDb First Credit                  |
| First Impressions with Dana Carvey |
| The Morning Show                   |
| LA Times: The Envelope             |
+------------------------------------+
Run Time: real 4.633 user 0.937500 sys 3.671875


-- INDEXES
sqlite> SELECT * FROM shows WHERE title = 'The Office';
+---------+------------+------+----------+
|   id    |   title    | year | episodes |
+---------+------------+------+----------+
| 112108  | The Office | 1995 | 6        |
| 290978  | The Office | 2001 | 14       |
| 386676  | The Office | 2005 | 188      |
| 1791001 | The Office | 2010 | 30       |
| 2186395 | The Office | 2012 | 8        |
| 8305218 | The Office | 2019 | 28       |
+---------+------------+------+----------+
Run Time: real 0.033 user 0.031250 sys 0.000000
-- creating a B-tree by the following line
sqlite> CREATE INDEX title_index on shows (title);
Run Time: real 0.473 user 0.140625 sys 0.031250

sqlite> SELECT * FROM shows WHERE title = 'The Office';
+---------+------------+------+----------+
|   id    |   title    | year | episodes |
+---------+------------+------+----------+
| 112108  | The Office | 1995 | 6        |
| 290978  | The Office | 2001 | 14       |
| 386676  | The Office | 2005 | 188      |
| 1791001 | The Office | 2010 | 30       |
| 2186395 | The Office | 2012 | 8        |
| 8305218 | The Office | 2019 | 28       |
+---------+------------+------+----------+
Run Time: real 0.008 user 0.000000 sys 0.000000 -- here is the difference in time