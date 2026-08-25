class Solution {
public:
    vector<vector<int>> specialGrid(int n) {
        
        int size = 1 << n;
        
        vector<vector<int>> grid(size, vector<int>(size));
        
        fillGrid(grid, 0, 0, size, 0);
        
        return grid;
    }
    
    void fillGrid(vector<vector<int>>& grid, int row, int col,
                  int size, int start) {
        
        if(size == 1) {
            grid[row][col] = start;
            return;
        }
        
        int half = size / 2;
        int area = half * half;
        
        // Top-Right: smallest
        fillGrid(grid, row, col + half, half, start);
        
        // Bottom-Right
        fillGrid(grid, row + half, col + half, half, start + area);
        
        // Bottom-Left
        fillGrid(grid, row + half, col, half, start + 2 * area);
        
        // Top-Left: largest
        fillGrid(grid, row, col, half, start + 3 * area);
    }
};