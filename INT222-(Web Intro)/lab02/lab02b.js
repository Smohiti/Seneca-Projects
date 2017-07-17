/*********************************************************************************
* INT222 – Lab 02
* I declare that this assignment is my own work in accordance with Seneca Academic Policy. No part of this
* assignment has been copied manually or electronically from any other source (including web sites) or
* distributed to other students.
**
Name: M.Saeed Mohiti Student ID: 116236159 Date: 10/11/2016
*
********************************************************************************/
// an array of course objects
var courses = [
    { code: 'APC100', name: 'Applied Professional Communications', hours: 3, url: 'http://www.senecacollege.ca/' },
    { code: 'IPC144', name: 'Introduction to Programming Using C', hours: 4, url: 'https://scs.senecac.on.ca/~ipc144/' },
    { code: 'ULI101', name: 'Introduction to Unix/Linux and the Internet', hours: 4, url: 'https://cs.senecac.on.ca/~fac/uli101/live/' },
    { code: 'IOS110', name: 'Introduction to Operating Systems Using Windows', hours: 4, url: 'https://cs.senecac.on.ca/~fac/ios110' },
    { code: 'EAC150', name: 'College English', hours: 3, url: null },
];

// prototype object for creating student objects
var student = { 
    name: "", 
    dob: new Date(),
    sid: "",
    program: "", 
    gpa: 4.0,
    toString: function () {
        return 'Student info for ' + this.name + ': born on ' + this.dob.toLocaleDateString() +
               ', student id ' + this.sid + ', progrem ' + this.program + ', current GPA ' + this.gpa; 
    }
};

/******************************************************
 * Start your code here. Do not change the code above.
 ******************************************************/
// task 1
console.log("\n*** TASK 1 ***\n")

var rmv = courses.pop();

console.log("Course " + rmv.code +" was deleted from the array(courses)" );
console.log("Adding new courses objects into the Array (courses)");

var ibc233 = {
    code: 'IBC233',
    name: 'iSeries Business Computing',
    hours: 4,
    url: 'https://scs.senecac.on.ca/~ibc233/'
};
var oop244 = {
    code: 'OOP244',
    name: 'Introduction to Object Oriented Programming',
    hours: 4,
    url: 'https://scs.senecac.on.ca/~oop244/'
};
var int222 = {
    code: 'INT222',
    name: 'Internet I - Internet Fundamentals',
    hours: 4,
    url: 'http://www.senecacollege.ca/~int222/'
};
var dbs201 = {
    code: 'DBS201',
    name: 'Introduction to Database Design and SQL',
    hours: 4,
    url: 'http://www.senecacollege.ca/~dbs201/'
};
courses.push(ibc233, oop244, int222, dbs201);
console.log("\n Course objects in the array (courses):\n");
for (var i = 0; i < courses.length ; i++){
    console.log(courses[i].code+", "+courses[i].name+", "+courses[i].hours+" hours/week, website: "+courses[i].url);
}



// task 2

console.log("\n *** TASK 2 ***\n");
console.log("Student objects in the array (students): ");

var student1 = Object . create (student);
student1.name = "John Smith";
student1.dob= new Date("1999,9,10");
student1.sid = "010456101";
student1.gpa= 4;
student1.program = "CPA";


var student2 = Object . create (student);
student2.name="Jim Carrey";
student2.dob =new Date("1992,1,17");
student2.sid = "012345678";
student2.gpa= 3.5;
student2.program = "CPD";


var student3 = Object . create (student);
student3.name="Justin Biber";
student3.dob=new Date("1994,3,1");
student3.sid ="0987654321";
student3.gpa= 3;
student3.program = "CAN";


var student4 = Object . create (student);
student4.name="Justin Trudeau";
student4.dob =new Date ("1992,1,12");
student4.sid = "123456789";
student4.gpa= 4;
student4.program = "CAN";

students = [student1,student2,student3,student4];

for (var i = 0; i < students.length; i++){
var stString=  students[i].toString();
    console.log(i + ": " + stString);
}





