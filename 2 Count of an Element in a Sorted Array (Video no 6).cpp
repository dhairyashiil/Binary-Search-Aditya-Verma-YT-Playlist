// Question Link : https://practice.geeksforgeeks.org/problems/number-of-occurrence2259/1

class Solution{
public:	
	/* 
	if x is present in arr[] then 
	returns the count of occurrences of x, 
	otherwise returns 0. 
	*/
	
	int firstOcc(int v[], int n, int k) {
        
        int start = 0;
        int end = n-1;
        int index = -1;
        
        while(start <= end) {
            int mid = start + ((end-start)/2);
            
            if(v[mid] == k) {
                index = mid;
                end = mid-1;
            }
            else if(v[mid] < k) {
                start = mid+1;
            }
            else if(v[mid] > k) {
                end = mid-1;
            }
        }
        return index; 
    }
    
    int lastOcc(int v[], int n, int k) {
        
        int start = 0;
        int end = n-1;
        int index = -1;
        
        while(start <= end) {
            int mid = start + ((end-start)/2);
            
            if(v[mid] == k) {
                index = mid;
                start = mid+1;
            }
            else if(v[mid] < k) {
                start = mid+1;
            }
            else if(v[mid] > k) {
                end = mid-1;
            }
        }
        return index; 
    }
    
	
	int count(int v[], int n, int k) {
	    
	    int first = firstOcc(v,n,k);
        int last = lastOcc(v,n,k);
        
        if(first == -1 || last == -1) return 0;
        
        return last-first+1;
	}
};
