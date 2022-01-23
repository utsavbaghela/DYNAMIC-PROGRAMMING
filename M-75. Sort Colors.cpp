M-75. Sort Colors

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero=0,one=0,two=nums.size()-1;
        while(one<=two)
        {
            switch(nums[one])
            {
                case 0:
                    swap(nums[zero++],nums[one++]);
                    break;
                case 1:
                    one++;
                    break;
                case 2:
                    swap(nums[one],nums[two--]);
                    break;
            }
            
        }
    }
};