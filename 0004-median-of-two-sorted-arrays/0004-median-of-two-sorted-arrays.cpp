class Solution {
public:
    double work(vector<int>& nums1, vector<int>& nums2){
       //always n<=m hi hoga
       int n=nums1.size();
       int m=nums2.size();
       int size=n+m;
       
       int Left_element=size/2;
       if(size%2) Left_element++;

       int i=0;
       int j=n;
       int l1,l2,r1,r2;
       while(i<=j){
            int mid=i+(j-i)/2; //nums1 mai itne elements liye
            l1 = (mid == 0) ? INT_MIN : nums1[mid-1];
            r1 = (mid == n) ? INT_MAX : nums1[mid];

            int cut2 = Left_element - mid;

            l2 = (cut2 == 0) ? INT_MIN : nums2[cut2-1];
            r2 = (cut2 == m) ? INT_MAX : nums2[cut2];

            if(l1<=r2 && l2<=r1) break;          
            else if(l2>r1) i=mid+1;          
            else if(l1>r2) j=mid-1;
       }

        // Calculate median
        if ((m + n) % 2 == 1) {
            return max(l1, l2);
        }

        return (max(l1, l2) + min(r1, r2)) / 2.0;

    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int n=nums1.size();
       int m=nums2.size();
       
       if(n<m) return work(nums1,nums2);
       else return work(nums2,nums1);
    }
};