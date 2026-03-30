class Solution {
public:
    int binary_search(vector<int>& numbers,int left, int target){
        int right = numbers.size()-1;
        while(left<right){
            cout<<left<<" "<<right<<"\n";
            if(numbers[left] == target)
                return left;
            int mid = (left+right)/2;
            if(numbers[mid]>target){
                right = mid - 1;
            }
            else if(numbers[mid]<target){
                left = mid + 1;
            }
            else{
                return mid;
            }
            cout<<left<<" "<<right<<"\n";
        }
        return left;
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for(int i=0;i<n;++i){
                int y = binary_search(numbers,i+1,target-numbers[i]);
                if(numbers[i]+numbers[y]==target)
                    return {i+1,y+1};
 
        }
        return {-1,-1};
    }
};
