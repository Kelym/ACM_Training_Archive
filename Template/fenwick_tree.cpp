// Aka "Binary Indexed Tree"
// Reference
//      http://www.algorithmist.com/index.php/Fenwick_tree
//      https://www.topcoder.com/community/data-science/data-science-tutorials/binary-indexed-trees/
//      http://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/
#include <vector>
using namespace std;

template<typename T>
class fenwick_tree{
public:
    vector<T> tree;
    fenwick_tree(const int& aSize){
        tree.resize(aSize + 1);
    }
    fenwick_tree(const vector<T>& baseArray){
        tree.resize(baseArray.size());
        for(int i = 0 ; i<tree.size(); i++) increase(i, baseArray[i]);
    }
    void increase(int i, T delta){
        for (; i < (int)tree.size(); i |= i + 1)
            tree[i] += delta;
    }
    inline T getSum(int left, int right){
        return sum(right) - sum(left-1);
    }
    T sum(int ind){
        T sum = 0;
        while (ind>=0){
            sum += tree[ind];
            ind &= ind + 1;
            ind--;
        }
        return sum;
    }
};

// COMMENT: In usage, notice the given size m will result in [0...m-1] valid.