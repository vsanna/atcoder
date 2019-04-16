#include <vector>
// #include <algorithm>
// #include <cmath>
// #include <math.h>
// #include <utility>


/*

*/

template <typename T>
class SegmentTree {
	private:
		int size;
		std::vector<T> data;
	public:
		SegmentTree(std::vector<T> v) {
			int original_size = v.size();
			// segment treeは完全二分木なので2の累乗長
			size = 1;
			while(size < original_size) {
				size = size * 2;
			}

			data.resize(2*size - 1);

			// 区間
			for(int i = 0; i < original_size; i++) {
				data[i + size - 1] = v[i];
			}
			for(int i = size - 2; i >= 0; i--) {
				data[i] = min(data[2*i+1], data[2*i+2]);
			}
		}

		update(int pos, T val) {}

		query(int from, int to) {}
}