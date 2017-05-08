$(window).keyup(function(e) {
  switch (e.keyCode) {
    case 37: // left arrow key
	stopped();
	changeBackWhite("left");
	return;
    case 38: // up arrow key
      e.preventDefault(); // avoid browser scrolling due to pressed key
      // TODO: go to previous image
	  stopped();
	  changeBackWhite("up");
      return;
    case 39: // right arrow key
	stopped();
	changeBackWhite("right");
	return;
    case 40: // down arrow key
      e.preventDefault();
      // TODO: go to next image
	  stopped();
	  changeBackWhite("down");
      return;
  }
});

$(window).keydown(function(e) {
  switch (e.keyCode) {
    
    case 38: // up arrow key
      e.preventDefault(); // avoid browser scrolling due to pressed key
      // TODO: go to previous image
	  up();
	  changeBackRed("up");
      return;
  case 37: // left arrow key
	left();
	changeBackRed("left");
	return;
    case 39: // right arrow key
	right();
	changeBackRed("right");
	return;
    case 40: // down arrow key
      e.preventDefault();
      // TODO: go to next image
	  down();
	  changeBackRed("down");
      return;
  }
});