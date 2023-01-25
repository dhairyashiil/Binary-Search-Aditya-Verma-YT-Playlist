// Question Link : https://leetcode.com/problems/find-peak-element/submissions/

class Solution {
public:
    
    int findPeakElement(vector<int>& arr) {
        
        int n = arr.size();
        if(n==1) return 0; // Index '0' will be the ans
        
        int s = 0;
        int e = n-1;
        
        while(s <= e) {
            
            int mid = s + (e-s)/2;
            
            // Mid is present between First & Last Position of arr
            if(mid > 0 && mid < n-1) {
                
                // We got the 'Peak' element
                if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) return mid;
                // move to left part
                else if(arr[mid] < arr[mid-1]) e = mid-1;
                // move to right part
                else s = mid+1;
            }
            // Mid is present at First Position of arr
            else if(mid == 0) { 
                if(arr[mid] > arr[mid+1]) return 0;
                else return 1;
            }
            // Mid is present at Last Position of arr
            else if(mid == n-1) { 
                if(arr[mid] > arr[mid-1]) return n-1;
                else return n-2;
            }
        }
        return -1;
    }
  
};
