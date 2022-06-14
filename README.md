# CS-210 Project 2 - Airgead Banking Calculator
Designed to provide school students with proper financial literacy skills, the Airgead Banking Savings Simulator provides an outlook on how you choose to invest. 

**DISCLAIMER: This code repo was set to the public in June 2022, this should be used as a reference only. Don't copy it and call it your own! I don't condone cheating, and you will likely be in violation of SNHU's academic integrity policy.**


### Functionality
When opened, the user is prompted to enter;
1. Opening deposit amount
2. Monthly deposit amount
3. Interest Rate
4. Number of years to calculate

![Calculator input prompt](screenshots/OpeningMenu.png)

The program will create two reports with the entered values, each displaying the year, final balance, and earned interest.

The first report simulates a recurring monthly deposit (specified from the user on the beginning prompt), while the second report simulates only the opening deposit with no future deposits.

![Investment reports](screenshots/InvestmentReports.png)

### Reflection
#### What did I do well?
For the most part, this was a very successful project for CS-210. Out of the three projects we did, this is the one I'm the proudest of.

This was my first time diving deep with C++, particularly the data handling features. Using Vectors (in a vector) and For Loops, I facilitated a standard method of transferring multiple variables of data through the various functions while keeping track of which year the set of variables belong to. 

#### What could be improved?
Some efficiencies could be added in the future. I am still a beginner in C++ and attempted to use best practices and optimize my code to ensure it's fast and efficient on memory. 

#### Any challenges?
For sure. As mentioned, I hadn't done much with C++ prior to this course, and keeping track of final balances per year (data management) was a massive bulk of the debugging work I was doing for this project, almost to the point where I was worried about running out of time. However, I prevailed and was able to get a functional method of storing data using vectors-in-vectors.

First, I tried to use arrays, but I learned quickly that it wasn't going to be adequate for this project, and I needed to use vectors, which I was less comfortable with. After finishing this project, I am much more familiar and comfortable with not just vectors but also vectors inside of vectors!

#### Real-life
I've made scripts before for my systems administration job, however usually they're not really "applications" like this project was, and they're typically only designed to do a specific, tedious task (such as logging in via SSH and sending a command to hundreds of routers and network switches), maybe with a variable or two.

This project gave me much more exposure to data manipulation, storage, and UI elements that I otherwise didn't care much for prior. 

#### Maintainability and Readability
Classes and functions were utilized as much as possible. I did use main() for some critical operations but kept its use minimal. Line comments were common throughout every code file.

A lot of it is adaptable for other uses too. I used some of my vector-in-vector code for the next project.
