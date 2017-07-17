//GETTING ALL INPUT TEXT OBJECTS
var password = document.forms["signup"]["password"];
var passcon = document.forms["signup"]["passcon"];
var phone = document.forms["signup"]["phone"];
var first = document.forms["signup"]["first"];
var last = document.forms["signup"]["last"];

//GETTING ALL DISPLAY ERRORS
var password_error = document.getElementById("password_error");
var first_error = document.getElementById("first_error");
var last_error = document.getElementById("last_error");
var passcon_error = document.getElementById("passcon_error");
var phone_error = document.getElementById("phone_error");

//SETTING EVENT LISTENER FOR EVERYTHING THAT REQUIRES
passcon.addEventListener("keyup", checkBothPasswords, false);
password.addEventListener("change",checkPassword,false);
phone.addEventListener("change",checkPhone,false);
first.addEventListener("change",checkName,false);
last.addEventListener("change",checkLast,false);

//MAIN VALIDATION FUNCTION
//Function that works with the form tag
//Allows submittion
function formValidation(){

  if(checkBothPasswords()&& checkPassword()&& checkName()&& checkLast()&& checkPhone()){
   return true;
  }
  else{
  console.log("Fix Problems");
  alert('Failed Submittion. Please check both passwords, first name and last name and phone number');
  return false;

 }
}
//STEPS VALIDATION
//Validation functions for each part
//Each functions return true and false is valid or no
function checkName(){
  first.value = first.value.trim();
  var checkLetters = 0;
  var checkValues = 0;
  var final = false;


  for(var i=0;i<first.value.length;i++){
    //Acceptable values
    if(first.value[i]>='A' && first.value[i]<="Z"){checkLetters++;}
    else if(first.value[i]>='a' && first.value[i]<="z"){checkLetters++;}
    else if(first.value[i]=="'"){}
    else if(first.value[i]=='-'){}
    else{checkValues++;}

  }

  if(checkValues > 0){
    first.style.border = "1px solid red";
    first_error.innerHTML = "X Acceptable values are A-Z a-z ' - ";
    first.focus();
    final = false;
    console.log("Acceptable values are A-Z a-z ' - ");
  }
  else if(checkLetters = 0){
    first.style.border = "1px solid red";
    first_error.innerHTML = "X At least one letter needs to be included";
    first.focus();
    final = false;
    console.log("At least one letter needs to be included");
  }
  else{
    first.style.border = "";
    first_error.innerHTML = "";
    final = true;
    console.log("Name Validated");
  }
  return final;
}
function checkLast(){
  last.value = last.value.trim();
  var checkLetters = 0;
  var checkValues = 0;
  var final = false;

  for(var i=0;i<last.value.length;i++){
    //Acceptable values
    if(last.value[i]>='A' && last.value[i]<="Z"){checkLetters++;}
    else if(last.value[i]>='a' && last.value[i]<="z"){checkLetters++;}
    else if(last.value[i]=="'"){}
    else if(last.value[i]=='-'){}
    else{checkValues++;}

  }

  if(checkValues > 0){
    last.style.border = "1px solid red";
    last_error.innerHTML = "X Acceptable values are A-Z a-z ' - ";
    last.focus();
    final = false;
    console.log("Acceptable values are A-Z a-z ' - ");
  }
  else if(checkLetters = 0){
    last.style.border = "1px solid red";
    last_error.innerHTML = "X At least one letter needs to be included";
    last.focus();
    final = false;
    console.log("At least one letter needs to be included");
  }
  else{
    last.style.border = "";
    last_error.innerHTML = "";
    final = true;
    console.log("Last Name Validated");
  }
  return final;
}
function checkPhone(){

  var status;
  var checkForNumbers = 0;
  for(var i=0;i<phone.value.length;i++){
    if(phone.value[i]>="0" && phone.value[i]<="9" || phone.value[i]=="-"){

    }
    else{
      checkForNumbers++;
    }
  }
  if(checkForNumbers!=0){
    phone.style.border = "1px solid red";
    phone_error.innerHTML = "X Please only numbers";
    phone.focus();
    status = false;
    console.log("Not only numbers");
  }
  else if(phone.value.length!=12){
    phone.style.border = "1px solid red";
    phone_error.innerHTML = "X Must be 12 characters like: 999-999-9999";
    phone.focus();
    status = false;
    console.log("Format is not fine - size is wrong");
  }
  else if(phone.value[3]!="-" && phone.value[7]!="-"){
    phone.style.border = "1px solid red";
    phone_error.innerHTML = "X Check the hyphens";
    phone.focus();
    status = false;
    console.log("Format is not fine - are on place");

  }
  else if(phone.value[0]=="0" && phone.value[1]=="0" && phone.value[2]=="0"){
    phone.style.border = "1px solid red";
    phone_error.innerHTML = "X Area Code cannot be 000";
    phone.focus();
    status = false;
    console.log("000 in area code");
  }
  else if(phone.value[4]=="0" && phone.value[5]=="0" && phone.value[6]=="0" && phone.value[8]=="0" && phone.value[9]=="0" && phone.value[10]=="0" && phone.value[11]=="0"){
    phone.style.border = "1px solid red";
    phone_error.innerHTML = "X Phone Number cannot be 000-0000";
    phone.focus();
    status = false;
    console.log("000-0000 in phone code");
  }
  else{

    phone.style.border = "";
    phone_error.innerHTML = "";
    phone.focus();
    status = true;
    console.log("Phone is validated");
  }

  return status;

}
function checkPassword(){

  var status;
  var count_number = 0;

  if(password.value.length < 8 ){
    password.style.border = "1px solid red";
    password_error.innerHTML = "X Password needs to be 8+ characters";
    password.focus();
    status = false;
  }
  else{
    for(i=0;i<password.value.length;i++){
      if(password.value[i]>="0"&&password.value[i]<="9"){
        count_number++;
      }
    }
    if(count_number==0){
      password.style.border = "1px solid red";
      password_error.innerHTML = "X Password needs at least a number";
      password.focus();

      status = false;
    }
    else{
      password.style.border = "";
      password_error.innerHTML = "";
      console.log("Password validated")
      status = true;
    }
  }
  return status;
}
function checkBothPasswords(){

  var status;
  if(password.value == passcon.value){
    passcon.style.border = "";
    password.style.border = "";
    passcon_error.innerHTML = "";
    console.log("Passwords are the same");
    status = true;

  }
  else{
    passcon.style.border = "1px solid red";
    password.style.border = "1px solid red";
    passcon_error.innerHTML = "X Passwords are not the same";

    status = false;
  }
  return status;
}

function resetHandler(){
  first.style.border = "";
  first_error.innerHTML = "";
  last.style.border = "";
  last_error.innerHTML = "";
  phone.style.border = "";
  phone_error.innerHTML = "";
  password.style.border = "";
  password_error.innerHTML = "";
  passcon.style.border = "";
  passcon_error.innerHTML = "";
}
/*function checkEducation(){
  var status;
  if(document.getElementById('graduated').checked){
    status = true;
  }
  else if(document.getElementById('enrolled').checked){
    status = true;
  }
  else if(document.getElementById('notgraduate').checked){
    status = true;
  }
  else{
    status = false;
  }
}
*/
