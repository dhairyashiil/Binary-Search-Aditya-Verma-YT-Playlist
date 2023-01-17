// Question Link : https://practice.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

class Solution{
public:
  
    int findFloor(vector<long long> v, long long n, long long x){
        
        if(x < v[0]) return -1;
        
        int s = 0;
        int e = n-1;
        int index;
        
        while(s <= e) {
            
            int mid = s + (e-s)/2;
            
            if(v[mid] <= x) {
                index = mid;
                s = mid + 1;
            }
            else if(v[mid] > x) {
                e = mid - 1;
            }
        }
        return index;
    }
};
