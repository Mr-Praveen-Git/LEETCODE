class Solution {
public:
    // Helper function to perform DFS on the grid
    void helper(vector<vector<char>>& grid, int i, int j){
        // Base case: check for invalid indices and if the current cell is water ('0')
        if(i<0 || j<0 || i>=grid.size() || j>=grid[i].size() || grid[i][j]=='0')
          return;
        
        // Mark the current cell as visited by setting it to '0' (water)
        grid[i][j]='0';

        // Recursively call helper function for all adjacent cells
        helper(grid, i+1, j); // Down
        helper(grid, i, j+1); // Right
        helper(grid, i, j-1); // Left
        helper(grid, i-1, j); // Up
    }

    // Main function to count the number of islands in the grid
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0; // Initialize count of islands to 0
        // Iterate over each cell in the grid
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                // If the cell contains '1', it is part of an island
                if(grid[i][j] == '1') {
                    ans++; // Increment the island count
                    // Call the helper function to mark the entire island as visited
                    helper(grid, i, j);
                }
            }
        }
        return ans; // Return the total number of islands found
    }
};
