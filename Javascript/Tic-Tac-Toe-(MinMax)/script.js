var board;
const human = 'X';
const ai = 'O';
const wins = [[0,1,2], [0,3,6], [0,4,8], [3,4,5], [1,4,7], [2,4,6], [6,7,8], [2,5,8]];

const cells = document.querySelectorAll(".cell"); //define all thebox of of cell class as an array in cells
game();

function game() {
				document.querySelector(".endgame").style.display = "none";
				board = Array.from(Array(9).keys());
				for (var i = 0; i <cells.length; i++) {
								cells[i].innerText = '';
								cells[i].style.removeProperty('background-color');
								cells[i].addEventListener('click', turnClick, false); //changes the box to cross after click
				}
}

function turnClick(square) {
				//console.log(square.target.id);
				if (typeof board[square.target.id] == "number") {
								turn(square.target.id, human); //assigns whick box to put the cross in
								if (!tie()) turn(best(), ai);
				}
}

function turn(squareid, user) {
				board[squareid] = user;
				document.getElementById(squareid).innerText = user;
				let gamewon = check(board, user);
				if (gamewon) gameover(gamewon);
}

//checks if user has won
function check(gameboard, user) {
				let plays = gameboard.reduce((x,y,z) => 
								(y === user) ? x.concat(z) : x, []);
				let gamewon = null;
				for(let [index, win] of wins.entries()) {
								if (win.every(elem => plays.indexOf(elem) > -1)) {
												gamewon = {index: index, user: user};
												break;
								}
				}
				return gamewon;
}

function gameover(gamewon) {
				for (var i of wins[gamewon.index]) {
								document.getElementById(i).style.backgroundColor =
								gamewon.user == human ? "blue" : "red";
				}
				for (let i = 0; i<cells.length; i++) {
								cells[i].removeEventListener('click', turnClick, false);
				}
				declarewinner(gamewon.user == human ? "You Win!" : "You Lose...");
}

//declares winners
function declarewinner(who) {
				document.querySelector(".endgame").style.display = "block";
				document.querySelector(".endgame .text").innerText = "who";
}

//ai that checks the best spot to choose by computer

function emptysquares(canvas) {
				return canvas.filter(s => typeof s == 'number');}


function best() {
				return minimax(board, ai).index;
}

//checks for tie
function tie() {
				if (emptysquares(board).length==0) {
								for (let i = 0; i < cells.length;i++) {
												cells[i].style.backgroundColor = "green";
												cells[i].removeEventListener('click', turnClick, false)
								}
								declarewinner("Tie Game!");
								return true;
				}
				return false;
}

//creating minimax

function minimax(newBoard, player) {
	var availSpots = emptysquares(newBoard);

	if (check(newBoard, human)) {
		return {score: -10};
	} else if (check(newBoard, ai)) {
		return {score: 10};
	} else if (availSpots.length === 0) {
		return {score: 0};
	}
	var moves = [];
	for (var i = 0; i < availSpots.length; i++) {
		var move = {};
		move.index = newBoard[availSpots[i]];
		newBoard[availSpots[i]] = player;

		if (player == ai) {
			var result = minimax(newBoard, human);
			move.score = result.score;
		} else {
			var result = minimax(newBoard, ai);
			move.score = result.score;
		}

		newBoard[availSpots[i]] = move.index;

		moves.push(move);
	}

	var bestMove;
	if(player === ai) {
		var bestScore = -10000;
		for(var i = 0; i < moves.length; i++) {
			if (moves[i].score > bestScore) {
				bestScore = moves[i].score;
				bestMove = i;
			}
		}
	} else {
		var bestScore = 10000;
		for(var i = 0; i < moves.length; i++) {
			if (moves[i].score < bestScore) {
				bestScore = moves[i].score;
				bestMove = i;
			}
		}
	}

	return moves[bestMove];
}
