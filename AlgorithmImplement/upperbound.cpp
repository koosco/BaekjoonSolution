int lowerBound(int* arr, int target, int size) {
	int left, right, mid;
	left = 0;
	right = size - 1;
	while(left < right) {
		mid = left + (right - left) / 2;
		if(arr[mid] <= target)
			left = mid + 1;
		else
			right = mid;
			
	}
}