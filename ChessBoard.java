package recursion_EightQueens;

import math.grid.Grid;
import math.location.Location;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;

//xhsgerksbgb
//dshgdigbr

public class ChessBoard extends Grid<Boolean> {
    private ArrayList<Location> queens;

    public ChessBoard() {
        super(new Boolean[8][8]);
        fillBoard(getGrid());
        queens = new ArrayList<>();
    }

    public ChessBoard(Boolean[][] board) {
        super(board);
    }

    public void setQueens(ArrayList<Location> queens) {
        this.queens = queens;
    }

    public ArrayList<Location> getQueens() {
        return queens;
    }

    public boolean isValid(Location loc) {
        for (Location queen : queens) { // check if loc collides with the queens present
            if (loc.collide(queen))
                return false;
        }
        return true;
    }

    public boolean tryAddQueen(Location loc) {
        if (isValid(loc)) {
            queens.add(loc);
            setSpot(loc, true);
            return true;
        }
        return false;
    }

    private void fillBoard(Boolean[][] board) {
        for (Boolean[] booleans : board) {
            Arrays.fill(booleans, false);
        }
    }

    public ChessBoard copy() {
        ChessBoard board = new ChessBoard(getGrid().clone());
        board.setQueens((ArrayList<Location>) queens.clone());
        return board;
    }
}
