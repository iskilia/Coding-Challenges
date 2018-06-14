class Matrix{
    public:
        Matrix(){}
        vector<vector<int>> a;
        Matrix operator +(Matrix& r){
            Matrix ret;
            ret.a = vector<vector<int>>(r.a.size());
            for(auto i=0; i<r.a.size(); ++i){
                ret.a[i] = vector<int>(r.a[i].size());
                for(auto j=0; j<r.a[i].size(); ++j)
                    ret.a[i][j] = this->a[i][j] + r.a[i][j];
            }
            return ret;
        }
};
