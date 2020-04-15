#include <iostream>
using std::cin;
using std::cout;

template <class T>
class Heap {
private:
	T *heap;
	int heapSize;
public:
	Heap(int size = 12) {
		heap = new T[size];
		heapSize = 0;
	}
	void add(T elem) {
		int i, parent;
		i = heapSize;
		heap[i] = elem;
		parent = (i - 1) / 2;
		while (parent >= 0 and i > 0) {
			if (heap[i] > heap[parent]) {
				T temp = heap[parent];
				heap[parent] = heap[i];
				heap[i] = temp;
			}
			i = parent;
			parent = (i - 1) / 2;
		}
		heapSize++;
	}
	void heapify(int i) {
		int left, right;
		T max;
		left = 2 * i + 1;
		right = 2 * i + 2;
		if (left < heapSize) {
			if (heap[i] < heap[left]) {
				max = heap[i];
				heap[i] = heap[left];
				heap[left] = max;
				heapify(left);
			}
		}
		if (right < heapSize) {
			if (heap[right] > heap[i]) {
				max = heap[i];
				heap[i] = heap[right];
				heap[right] = max;
				heapify(right);
			}
		}
	}
	T get_max() {
		T versh = heap[0];
		heap[0] = heap[heapSize - 1];
		heapSize--;
		heapify(0);
		return versh;
	}
};
int main() {
	return 0;
}