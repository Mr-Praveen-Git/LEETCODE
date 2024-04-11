class Solution {
public:
    int romanToInt(string s) {
        map<char, int> num;// map bana lo aur usme value dal do roman num ka 
            num['I']=1;
            num['V']=5;
            num['X']=10;
            num['L']=50;
            num['C']=100;
            num['D']=500;
            num['M']=1000;
            int ans=0;
    for(int i=0; i<s.length(); i++)// loop chalao symbols ke length  tak using length function
    {
            if(num[s[i]] < num[s[i+1]]) //num agar number symbol ke length se ek jayda bada hai to ghata do 
            {
                ans -= num[s[i]];
            }else //nhi to plus kr do
            {
                ans += num[s[i]];
            }
        }
      return ans; //return kr do ans
    }
};
