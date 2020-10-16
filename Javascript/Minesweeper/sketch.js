let grid;
let rows, cols;
let w = 20;

let totalBomb = 50;

function setup() {

    createCanvas(401, 401);

    
    rows = floor(width / w);
    cols = floor(height / w);

    grid = array(rows, cols);


    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            grid[i][j] = new Cell(i, j, w);
        }
    }
    

    var options = []

    for(let i=0;i<rows;i++){
        for(let j=0;j<cols;j++){
            options.push([i, j]);
        }
    }

    for(let n=0;n<totalBomb;n++){
        let index = floor(random(options.length));
        let choice = options[index];
        let i = choice[0];
        let j = choice[1];
        options.splice(index, 1);
        grid[i][j].bombGenerator();
    }

    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            grid[i][j].countBomb();
        }
    }


}


function draw() {

    background(255);

    
    fill(255);
    for(let i=0;i<rows;i++){
        for(let j=0;j<cols;j++){
            grid[i][j].show();
        }
    }
}

function mousePressed() {

    for(let i =0;i<rows;i++){
        for(let j=0;j<cols;j++){
            if(grid[i][j].contains(mouseX, mouseY)){
                grid[i][j].reveals();
                
                if(grid[i][j].bomb){
                    gameOver();
                }
            }
        }
    }
    
}

function array(rows, cols) {
    let arr = []

    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            arr[i] = []
        }
    }

    return arr;
}


function gameOver(){
    
    for(let i=0;i<rows;i++){
        for(let j=0;j<cols;j++){
            
            setTimeout(() => {
                grid[i][j].revealed = true;
            }, i*0.5);
        }
    }
}