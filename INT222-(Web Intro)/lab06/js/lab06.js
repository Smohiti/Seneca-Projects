// set a global httpRequest object
var httpRequest;

// TODO: when the page (window) has loaded, make a
// request for page 1

document.addEventListener('DOMContentLoaded', function() {
    makeRequest(1);
}, false);

function makeRequest(pageNum) {

    // TODO: create a variable "url" to store the request to
    // the current pageNum, ie:
    //
    // "http://reqres.in/api/users?page=1" // for page 1
    // "http://reqres.in/api/users?page=2" // for page 2
    // etc...

    var url = "http://reqres.in/api/users?page=" + pageNum;

    // make an HTTP request object

    httpRequest = new XMLHttpRequest();

    // show an alert if we were unable to make an XMLHttpRequest object

    if (!httpRequest) {
        alert('Cannot create an XMLHTTP instance');
        return false;
    }

    // execute the "showContents" function when
    // the httprequest.onreadystatechange event is fired

    httpRequest.onreadystatechange = showContents;

    // open a asynchronous HTTP (GET) request with the specified url

    httpRequest.open('GET', url, true);

    // send the request

    httpRequest.send();
}

// the function that handles the server response

function showContents() {

    //  check for response state
    //  0      The request is not initialized
    //  1      The request has been set up
    //  2      The request has been sent
    //  3      The request is in process
    //  4      The request is complete

    if (httpRequest.readyState === 4) {
        // check the response code

        if (httpRequest.status === 200) { // The request has succeeded
            // Javascript function JSON.parse to parse JSON data

            var jsData = JSON.parse(httpRequest.responseText);

            // TODO: use the jsData object to populate the correct
            // table cells, ie <tr><td>...</td></tr>
            // in the <tbody> element with id="data"


            var addRow = document.querySelector('#data');
            addRow.innerHTML = "";

            for (var i = 0; i < jsData.per_page; i++) {

                var row = addRow.insertRow(i);
                var myID = row.insertCell(0);
                var myName = row.insertCell(1);
                var myLast = row.insertCell(2);
                var myImg = row.insertCell(3);
                var idNum = document.createTextNode(jsData.data[i].id);
                var fName = document.createTextNode(jsData.data[i].first_name);
                var lName = document.createTextNode(jsData.data[i].last_name);
                var image = document.createElement("img");
                var imageurl = jsData.data[i].avatar;
                image.setAttribute("src" , imageurl);

                myID.appendChild(idNum);
                myName.appendChild(fName);
                myLast.appendChild(lName);
                myImg.appendChild(image);

            }

            // TODO: remove the class "active" from all elements with the class "pgbtn"

            var nonactive_elements = document.querySelectorAll(".pgbtn");

            for (var i = 0; i < nonactive_elements.length; i++) {
                nonactive_elements[i].classList.remove("active");
            }

            // TODO: add the class "active" to the button corresponding to the active page, ie:
            //
            // if jsData.page is 1, add the class "active" to button element with id pgbtn1
            // if jsData.page is 2, add the class "active" to button element with id pgbtn2
            // etc...

            var addClass = document.getElementById("pgbtn" + jsData.page);

            addClass.classList.add("active");

        } else {
            alert('There was a problem with the request.');
        }
    }
}
