// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h> 
using namespace std;
class SGTree
{
    private : 
        vector<int> seg;
    public: 
        SGTree(int  n)
        {
            seg.resize(4*n); 
        }
    void build(int ind, int low, int high, int arr[])
    {
        if(low == high)
        {
            seg[ind] = arr[low]; 
            return ; 
        }
        int mid = low + (high - low)/2; 
        build(2*ind+1, low, mid, arr);
        build(2*ind+2, mid+1, high, arr); 
        seg[ind] = min(seg[2*ind+1], seg[2*ind+2]); 
    }
    int query(int ind, int low, int high, int l, int r)
    {
        // 3 cases
        // 1-> complete overlap 
        //  [ l,  [low, high] , r ]
        if(l <= low && r >= high)
        {
            return seg[ind]; 
        }
        // No Overlap. 
        // [low, high] [l, r] or [l, r] [low, high]
        else if(high < l || r < low)
        {
            return INT_MAX; 
        }
        
        int mid = (low + high) >> 1; 
        int leftVal = query(2*ind+1, low, mid, l, r); 
        int rightVal = query(2*ind+2, mid+1, high, l, r); 
        return min(leftVal, rightVal); 
    
    }
    void update(int ind, int low, int high, int i, int val)
    {
        if(low == high)
        {
            seg[ind] = val; 
            return; 
        }
        int mid = (low + high) >> 1; 
        update(2*ind+1, low, mid, i, val); 
        update(2*ind+2, mid+1, high, i, val); 
        seg[ind] = min(seg[2*ind+1], seg[2*ind+2]); 
        
    }    
}; 


int main() {
    int n; 
    cin >> n; 
    SGTree sgt(n); 
    int arr[n]; 
    for(int i = 0;i < n; i++)
        cin >> arr[i]; 
    sgt.build(0, 0, n-1, arr); 
    int q; 
    cin >> q; 
    while( q--)
    {
        int q_type; 
        cin >> q_type; 
        if(q_type == 1)// give result in l-r range;
        {
            int l, r; 
            cin >> l >> r; 
            cout << sgt.query(0, 0, n-1, l, r) << endl; 
        }
        else 
        {
            int i, val; 
            cin >> i >> val; 
            sgt.update(0, 0, n-1, i, val); 
            cout << "Updated !!\n"; 
        }
    }
    cout << "Program Ends \n"; 
    return 0; 
    
}
