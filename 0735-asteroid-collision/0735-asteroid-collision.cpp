class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        for(int ast: asteroids){
            while(!st.empty() && st.back()>0 && ast<0 && st.back()< abs(ast)){
                st.pop_back();
            }
            if(st.empty() || ast>0 || st.back()<0){
                st.push_back(ast);
            }
            else if(st.back() == abs(ast)){
                st.pop_back();
            }
        }
        return st;
    }
};