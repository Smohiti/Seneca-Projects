/*********************
 * tASK 1
 *********************/

var name = 'Saeed Mohiti' ;
var course = 5;
var program = 'CPD';
var job = true ;
console.log(" My name is "+name+" and Im in "+program+" program .Im taking "+course+" courses in this semester.");

var jb;
if(job){
  jb = "have";
}
else{
  jb = 'dont have';
}
console.log(" My name is "+name+" and Im in "+program+" program .Im taking "
            +course+" courses in this semester and I "+jb+" a part-time job now.");

/*********************
 * tASK 2
 *********************/

var year = 2016;
var age = prompt("Please enter your age: ");
console.log("You were born in the year of: ", year - age);
var study = prompt("Enter the number of years you expect to study in the college: ");
console.log("You will graduate from Seneca college in the year of: ", +year + +study);

/*********************
 * tASK3
 *********************/

var ctemp = 45;
var tofar = ctemp * 9 / 5 + 32;
console.log(ctemp+"°C is " +tofar+ " °F");
var ftemp = 127;
var tocel = (ftemp - 32) * 5 / 9;
console.log(ftemp+ " °F" +tocel+"°C is " );

/*********************
 * tASK 4
 *********************/


for(var i = 0; i <= 10; i++){
  if ((i % 2) == 0){
    console.log(i+" is even");
  }else{
      console.log(i+" is odd");
  }
}

/*********************
 * tASK 5
 *********************/


function largerNum (a , b){
  
  if(a > b){
    return a;
  }else{
    return b;
  }
}


var greaterNum = function(a , b){
  
  if(a > b){
    return a;
  }else{
    return b;
  }
} 

console.log("The larger number of 5 and 12 is :" +largerNum(5,12));
console.log("The larger number of 11 and 33 is :" +largerNum(11,33));
console.log("The greater number of 4 and 9 is :" +greaterNum(4,9));
console.log("The greater number of 7 and 18 is :" +greaterNum(7,18));

/*********************
 * tASK 6
 *********************/
 var sum ;
function Evaluator(a,b,c){
  var avrage = (a + b + c) / 3;
 console.log(" the avrage is " +avrage);
  if (avrage >= 50){
    // sum = true;
    return true;
  }else{
    // sum = false;
    return false;
  }
  return avrage;
}

console.log("the function return " +Evaluator(50,60,70) );





/*********************
 * tASK 7
 *********************/

var grader = function (a){
var mark ;
  var grade ;
if (mark >= 80)
     grade = 'A';
else if (mark >= 70)
     grade = 'B';
else if (mark >= 60)
     grade = 'C';
else if (mark >= 50)
     grade = 'D';
else 
     grade = 'F';
  return grade;
}
console.log("Your grade: " + grader(30));



/*********************
 * tASK 8
 *********************/

function showMultiples(num, numMultiples){

  for(var i = 1 ; i <= numMultiples ; i++){
 
      var sum = num * i;
    console.log(num+"X"+i+"="+sum);
  }

}
showMultiples(5,4);





/*********************************************************************************
* INT222 – Lab 01
* I declare that this assignment is my own work in accordance with Seneca Academic Policy. No part of this
* assignment has been copied manually or electronically from any other source (including web sites) or
* distributed to other students.
**
Name: M.Saeed Mohiti Student ID: 116236159 Date: 09/28/2016
*
********************************************************************************/