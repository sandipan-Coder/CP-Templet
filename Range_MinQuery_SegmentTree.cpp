class SegmentTreeMin {
    vector<int> st;
    vector<int> lazy;

    public:
        SegmentTreeMin(int n) {
            st.resize(4 * n);
            lazy.resize(4 * n);
        }

        // Build Segment Tree
        void build(int idx, int low, int high, vector<int> &arr){

            if(low == high){
                st[idx] = arr[low];
                return;
            }

            int mid = low + (high - low) / 2;
            build(2*idx+1, low, mid, arr);
            build(2*idx+2, mid+1, high, arr);

            st[idx] = min(st[2*idx+1], st[2*idx+2]);
        }

        // Update the Segment Tree
        void update(int idx, int low, int high, int l, int r, int val){

            // Update the previous remaining updates
            // Propogates downwards
            if(lazy[idx] != 0){
                st[idx] += lazy[idx];
                // Propogate the lazy update downwards
               // For the remaining nodes to get updated
               if(low != high){
                    lazy[2*idx+1] += lazy[idx];
                    lazy[2*idx+2] += lazy[idx];
                }

                lazy[idx] = 0;
            }

            // No Overlap
            // We don't do anything and return
           // [low high] [l r] or [l r] [low high]
           if(high < l or r < low)
                return;
           
          // Complete Overlap
          // [ l low high r ]
            if(low >= l && high <= r){
                st[idx] += val;

                // If it has childrens
                if(low != high){
                    lazy[2*idx+1] += val;
                    lazy[2*idx+2] += val;
                }
                return;
            }

            // Partial Overlap
            int mid = low + (high - low) / 2;
            update(2*idx+1, low, mid, l, r, val);
            update(2*idx+2, mid+1, high, l, r, val);

            st[idx] = min(st[2*idx+1], st[2*idx+2]);
        }

        // Query_Sum in range on Segment Tree
        int query(int idx, int low, int high, int l, int r){

            // Update if any updates are remaining
            // As the node will be stay fresh and updated
            if(lazy[idx] != 0){
                st[idx] += lazy[idx];
                // Propogate the lazy update downwards
               // For the remaining nodes to get updated
               if(low != high){
                    lazy[2*idx+1] += lazy[idx];
                    lazy[2*idx+2] += lazy[idx];
                }

                lazy[idx] = 0;
            }

            // No Overlap condition
            if(high < l && r < low)
                return INT_MAX;
            
            // Complete Overlap
            if(low >= l && high <= r)
                return st[idx];
            
            // Partial Overlap
            int mid = low + (high - low) / 2;
            int left = query(2*idx+1, low, mid, l, r);
            int right = query(2*idx+2, mid+1, high, l, r);
            
            return min(left, right);
        }

};