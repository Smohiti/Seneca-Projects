/*********************************************************************************
* INT222 – Lab 02
* I declare that this assignment is my own work in accordance with Seneca Academic Policy. No part of this
* assignment has been copied manually or electronically from any other source (including web sites) or
* distributed to other students.
**
Name: M.Saeed Mohiti Student ID: 116236159 Date: 10/11/2016
*
********************************************************************************/
/**************** 
* Step 1 
****************/ 

var e1, e2, e3, e4, e5, e6, e7;
var str;

/**************** 
* Step 2 
****************/ 

var fname = prompt("Enter your name", "Saeed");

function capFirstLetter(string) {

    return string.substr(0, 1).toUpperCase() +
        string.substr(1).toLowerCase();

}

e1 = capFirstLetter(fname);

/**************** 
* Step 3 
****************/ 


e2 = prompt("Enter Your Birth Year","1978");

var getAge = function(birthYear){

  var age = new Date();
    var thisYear = age.getFullYear();
    return thisYear - birthYear;

};


e2=getAge(e2);


/**************** 
* Step 4 
****************/  

e3 = prompt("Enter your college name","Seneca College");
var String = e3.split(" ");
e3 = capFirstLetter(String[0])+" "+capFirstLetter(String[1]);


/**************** 
* Step 5 
****************/ 

e4 =prompt("Enter your 5 favourite sports","hockey,football,basketball,tennis,golf");

e4 =e4.replace("football", "soccer");
e4 = e4.split(",");

e5 = prompt("Enter one more favourite sport ","formula 1");

e4.push(e5);


/**************** 
* Step 6 
****************/  

var Array= [];

for(var i = 0; i < e4.length; i++){
     Array.push(e4[i].toUpperCase());
 
   }
var sport=Array.sort();
e4 = sport.join("\n\t");


/**************** 
* Step 7
****************/ 

function getDateString(date){
  var d = new Date().getDate();
  if (d<10){
    d = '0'+ d;
    
  }
  
  var month =  (new Date().getMonth())+1;
  if (month<10){
   month = '0'+ month;
  }
  
  var year =  new Date().getFullYear();
  date = year + "-"+month+"-"+d;
  return date;
  
}

e6 = new Date();
e7 = getDateString(e6);


/**************** 
* Step 8 
****************/ 

str = "User info: \n\nname (e1) : "+ e1 +"\nage (e2) : "+ e2 +
  "\nschool (e3) : "+ e3 +"\nfavourate sports (e4) :\n\t"+ e4 +
  "\ncurrent date (e7) : "+ e7;

console.log(str);





