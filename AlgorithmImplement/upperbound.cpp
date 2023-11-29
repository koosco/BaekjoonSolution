int lowerBound(int* arr, int target, int size) {
	int left, right, mid;
	left = 0;
	right = size - 1;
	while(left < right) {
		mid = left + (right - left) / 2;
		if(arr[mid] <= target)
			start = mid + 1;
		else
			end = mid;
			
	}
}