class NumArray {
public:
    vector<int> nums;
    vector<int> tree;
    int n;

    NumArray(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();

        tree.resize(n + 1, 0);

        for(int i = 0; i < n; i++) {
            add(i + 1, nums[i]);
        }
    }

    void add(int index, int value) {
        while(index <= n) {
            tree[index] += value;
            index += index & (-index);
        }
    }

    void update(int index, int val) {
        int difference = val - nums[index];

        nums[index] = val;

        add(index + 1, difference);
    }

    int getSum(int index) {
        int sum = 0;

        while(index > 0) {
            sum += tree[index];
            index -= index & (-index);
        }

        return sum;
    }

    int sumRange(int left, int right) {
        return getSum(right + 1) - getSum(left);
    }
};