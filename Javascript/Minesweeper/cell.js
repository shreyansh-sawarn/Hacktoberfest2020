class Cell {

    constructor(i, j, w) {
        this.i = i;
        this.j = j;
        this.x = i * w;
        this.y = j * w;
        this.w = w;
    }

    bomb = false;

    bombGenerator() {
        this.bomb = true;
    }

    revealed = false;

    neighbourBomb = 0;

    reveals() {
        this.revealed = true;

        if (this.neighbourBomb == 0) {

            this.showNeighbours();
        }
    }

    contains(x, y) {

        if (x > this.x && x < this.x + this.w && y > this.y && y < this.y + this.w) {
            return true;
        }
        else {
            return false;
        }
    }

    show() {

        noFill();
        rect(this.x, this.y, this.w, this.w);

        if (this.revealed == true) {
            if (this.bomb) {
                fill(127);
                ellipse(this.x + this.w / 2, this.y + this.w / 2, this.w / 2);

            }
            else {
                fill(200);
                rect(this.x, this.y, this.w, this.w);
                if (this.neighbourBomb > 0) {
                    fill(0);
                    textAlign(CENTER);
                    text(this.neighbourBomb, this.x + this.w / 2, this.y + this.w / 2);

                }

            }

        }
    }

    countBomb() {
        if (this.bomb) {
            this.neighbourBomb = -1;
            return;
        }

        let count = 0;

        for (let xoff = -1; xoff <= 1; xoff++) {
            for (let yoff = -1; yoff <= 1; yoff++) {
                let i = this.i + xoff;
                let j = this.j + yoff;
                if (i > -1 && i < rows && j > -1 && j < cols) {
                    let neighbour = grid[i][j];
                    if (neighbour.bomb) {
                        count++;
                    }
                }

            }
        }

        this.neighbourBomb = count;
    }

    showNeighbours() {

        for (let xoff = -1; xoff <= 1; xoff++) {
            for (let yoff = -1; yoff <= 1; yoff++) {
                let i = this.i + xoff;
                let j = this.j + yoff;
                if (i > -1 && i < rows && j > -1 && j < cols) {
                    let neighbour = grid[i][j];
                    if (!neighbour.bomb && !neighbour.revealed) {

                        neighbour.reveals();


                    }

                }

            }
        }

    }

}