double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int i=0,j=0,k=0,size=(nums1Size+nums2Size),m_size=size/2,med=0,t_med;

    while(k <= m_size){
        if(i<nums1Size && (j==nums2Size || nums1[i]<=nums2[j])){
            if(k == m_size-1 || k == m_size) {med+=t_med=nums1[i];}
            i++;k++;
        }
        if(j<nums2Size && (i==nums1Size || nums1[i]>nums2[j])) {
            if(k == m_size-1 || k == m_size) {med+=t_med=nums2[j];}
            j++;k++;
        }
    }
    if(size%2)
        return (double)t_med;
    else
        return (double)med/(double)2;
}