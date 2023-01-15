// Question Link : https://practice.geeksforgeeks.org/problems/rotation4723/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

class Solution{
public:	
	
  int findKRotation(int arr[], int n) {
        
        // Base Case
	if(n==1) return 0;
        
        int start = 0;
        int end = n-1;
        
        // Index of smallest element is our answer here
        while(start <= end) {
            
            // If all elements of array are already sorted 
            if (arr[start] <= arr[end]) return start;
            
            // Calculate mid
            int mid = start + (end-start)/2;
            
            // Calculate next and previous
            int next = (mid + 1) % n; // if mid is at last position
            int prev = (mid + n - 1) % n; // if mid is at first position
            
            // If we found smallest element of array, store it's index
            if ((arr[mid] <= arr[next]) && (arr[mid] <= arr[prev])) {
                return mid;
            }
            // If left part of array is sorted, It means
	        // smallest element present in right part
            else if (arr[start] <= arr[mid]) {
                start = mid + 1;
            }
            // If right part of array is sorted, It means
	        // smallest element present in left part
            else {
                end = mid - 1;
            }
        }
        return 0;
    }
};
