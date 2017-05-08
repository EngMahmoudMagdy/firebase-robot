
var upButton = document.getElementById("upButton"); 
var downButton = document.getElementById("downButton"); 
var rightButton = document.getElementById("rightButton"); 
var leftButton = document.getElementById("leftButton"); 
var rootRef = firebase.database().ref();

document.getElementById("container")
    .addEventListener("keyup", function(event) {
    event.preventDefault();
    if (event.keyCode == 13) {
        document.getElementById("btnSearch").click();
    }
});
function hovered(gg) 
{
	var btn = document.getElementById(gg);
		var handler = function(event){
	switch(event.type){
		case "mouseover":
		event.target.style.backgroundColor = "#117bff";
		break;
		case "mouseout":
		event.target.style.backgroundColor = "white";
		break;
	}
};

btn.onmouseover = handler;
btn.onmouseout = handler;

}
function changeBackRed(ff)
{
	var myDiv = document.getElementById(ff);
//set the background color
	myDiv.style.backgroundColor = "red";
	 hovered(ff) ; 
}

function changeBackWhite(stringeg)
{
	var myDiv = document.getElementById(stringeg);
//set the background color
	myDiv.style.backgroundColor = "white";
	 hovered(stringeg) ; 
}
function stopped()
{ 
	rootRef.child('data').set(0);
	changeBackWhite("up");
	changeBackWhite("down");
	changeBackWhite("right");
	changeBackWhite("left");
}

function up()
{ 
	changeBackWhite("up");
	rootRef.child('data').set(1);
}

function down()
{ 
	changeBackWhite("down");
	rootRef.child('data').set(2);
}

function right()
{ 
	changeBackWhite("right");
	rootRef.child('data').set(3);
}

function left()
{ 
	changeBackWhite("left");
	rootRef.child('data').set(4);
}