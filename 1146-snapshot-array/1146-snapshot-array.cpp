class SnapshotArray {
public:

    int snap_id;
    vector<vector<pair<int,int>>> vec;

    SnapshotArray(int length) {
        snap_id=0;
        vec.resize(length);
        for(int i=0;i<length;i++){
            vec[i].push_back({0,0}); // {snap_id , value_at_idx}
        }
    }
    
    void set(int index, int val) {
        vec[index].push_back({snap_id,val});
    }
    
    int snap() {
        return snap_id++;
    }
    
    int get(int index, int snap_id) {
        auto it = upper_bound(
            vec[index].begin(),
            vec[index].end(),
            make_pair(snap_id, INT_MAX)
        );
        return prev(it)->second;
    }
};