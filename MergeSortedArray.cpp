#include<iostream>
using namespace std;
#include<vector>

class Solution {
private:
    void shiftandinsert(vector<int>& nums1, int size, int position, int key)
{

    int temp;
    int i = position;
    while (i <= size)
    {
        int carry = nums1[i];
        if (i == position)
        {
            nums1[i] = key;
            // nums1.push_back(key);
        }
        else
        {
            nums1[i] = temp;
            // nums1.push_back(temp);
        }
        temp = carry;
        i++;
    }
}
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
    int arr1index = 0;
    int arr2index = 0;
    int mn = (m + n)-1;
    // int size = mn;
    int k = 0;
    while (arr1index < mn && arr2index < n)
    {
        if((nums1[arr1index] == 0 && nums1[arr1index-1] > nums1[arr1index])){
            break;
        }
        if (nums2[arr2index] <= nums1[arr1index])
        {
            shiftandinsert(nums1, mn, arr1index, nums2[arr2index]);          
            arr2index++;
        }
        else
        {
            arr1index++;
            k++;
        }
        
    }

    //if second array biiger than first array
    while (arr2index < n)
    {
        nums1[k++] = nums2[arr2index++];
        arr1index++;
    }
    //if first array bigger than second array
    while (arr1index < mn)
    {
        nums1[k++] = nums1[arr1index++];
    }
            
        
    }

    void printArray(vector<int>& arr,int size){
        for (int i = 0; i < size; i++)
        {
            cout<<arr[i]<<" ";
        }
        
    }
};



int main(){
    Solution *s = new Solution;
    vector<int> arr1 = {0,2,3};
    vector<int> arr2 = {1,2,4,5,7};
    s->merge(arr1,3,arr2,5); 

    s->printArray(arr1,8);
    return 0;
}