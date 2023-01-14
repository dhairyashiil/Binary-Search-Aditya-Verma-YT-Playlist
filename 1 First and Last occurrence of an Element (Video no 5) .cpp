// Question Link : https://practice.geeksforgeeks.org/problems/find-first-and-last-occurrence-of-x0849/1

class Solution {
public:
    
    long long firstOcc(vector<long long> v, long long k) {
        
        long long start = 0;
        long long end = v.size()-1;
        long long index = -1;
        
        while(start <= end) {
            long long mid = start + ((end-start)/2);
            
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
    
    long long lastOcc(vector<long long> v, long long k) {
        
        long long start = 0;
        long long end = v.size()-1;
        long long index = -1;
        
        while(start <= end) {
            long long mid = start + ((end-start)/2);
            
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
    
    pair<long,long> indexes(vector<long long> v, long long k) {
        
        long long first = firstOcc(v, k);
        long long last = lastOcc(v, k);
        
        return {first, last};
    }
};
