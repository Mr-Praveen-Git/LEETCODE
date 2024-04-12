class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(); //n le lete hai height ke size ke liye
        int sum=0; // sum =0 le lete hai 
        int left=0;//left =0 le lete hai
        int right=0; //right =0 le lete hai 
        for(int i=1; i<n-1; i++)// loop ko start krte hai 1 se kyuki 1 hai max height aur size-1 tak loop chalana hai 
        {
            left=height[i]; //left height ke liye 
            for(int j=0; j<i; j++)// dusra loop chalega j jo ki i tak chalega 
            {
                left=max(left,height[j]); //left max nikl jayega height ka 
            }
            right=height[i]; // right ke liye 
            for(int j=i+1; j<n; j++) // fir se loop chalega right ke liye size of height tak
            {
                right=max(right,height[j]); //right max nikal jayega jisse
                }
                sum=sum+(min(left,right)-height[i]); // uske baaad sum me add kr dena hai min of left right ka aur height ko ghata dena hai 
        }
        return sum;// return kr dena hai sum ko
    }
};
