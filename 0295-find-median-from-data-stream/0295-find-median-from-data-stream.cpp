class MedianFinder {
public:
    vector<int> arr;

    void addNum(int num) {

        auto it = lower_bound(arr.begin(), arr.end(), num);
        arr.insert(it, num);

    }

    double findMedian() {

        int n = arr.size();

        if (n & 1)
            return arr[n / 2];

        return (arr[n / 2] + arr[n / 2 - 1]) / 2.0;
    }
};