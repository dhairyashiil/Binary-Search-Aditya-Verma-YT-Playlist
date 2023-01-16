// Question Link : https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    
    // refer this for below function : 
    // https://github.com/dhairyashiil/Binary-Search-Aditya-Verma-YT-Playlist/blob/main/3%20Number%20of%20Times%20a%20Sorted%20array%20is%20Rotated%20(Video%20no%207).cpp
    
    int findSmallestElement(vector<int>& arr) {
        int n = arr.size();
	    if(n==1) return 0;
        int start = 0;
        int end = n-1;
        
        while(start <= end) {
            if (arr[start] <= arr[end]) return start;
            int mid = start + (end-start)/2;
            int next = (mid + 1) % n; 
            int prev = (mid + n - 1) % n; 
            
            if ((arr[mid] <= arr[next]) && (arr[mid] <= arr[prev])) return mid;
            else if (arr[start] <= arr[mid]) start = mid + 1;
            else end = mid - 1;
        }
        return 0;
    }
    
    int binarySearch(vector<int>& nums, int target, int s, int e) {
        while(s <= e) {
            int mid = s + (e-s)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) s = mid + 1; // go to right part
            else if(nums[mid] > target) e = mid - 1; // go to left part
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        
        int pivot = findSmallestElement(nums);
        // On left as well as on right side of pivot index
        // we have sorted array
        // one in ascending order and another in descending order
        // so now apply Binary Search to find 'target' element
        
        int ans1 = binarySearch(nums, target, 0, pivot-1);
        int ans2 = binarySearch(nums, target, pivot, nums.size()-1);
        
        return max(ans1, ans2);
    }
    
};
