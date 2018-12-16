class Solution {
public:
    std::vector<int> f()
    {
        std::vector<int> v { 1 };
        int i2 = 0;
        int i3 = 0;
        int i5 = 0;
        while (v.size() < 1691)
        {
            int a = std::min(v[i2] * 2, std::min(v[i3] * 3, v[i5] * 5));
            v.push_back(a);
            if (a == v[i2] * 2)
                ++i2;
            if (a == v[i3] * 3)
                ++i3;
            if (a == v[i5] * 5)
                ++i5;
        }
        
        return v;
    }
    int nthUglyNumber(int n) {
        static auto vv = f();
        return vv[n - 1];                
    }
};