class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end()); // deck ko short kr dena hai increasing order me
        
        int n = deck.size(); //deck size ke liye
        vector<int> result(n);
        deque<int> indices;
        
        for (int i = 0; i < n; i++) {
            indices.push_back(i); // Initialize kr dema hai deque ko yese 0, 1, 2, ..., n-1
        }
        
        for (int card : deck) {
            int idx = indices.front(); // next available index ke liye
            indices.pop_front(); // front se index ko nikalne le liye
            result[idx] = card; // card ko result array me place kr dena hai
            if (!indices.empty()) {
                indices.push_back(indices.front()); // Move kr dena hai use huye index ko
                indices.pop_front(); // Remove kr dena hai index ko front se
            }
        }
        
        return result;
    }
};
