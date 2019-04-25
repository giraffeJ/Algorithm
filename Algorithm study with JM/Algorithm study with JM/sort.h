#pragma once
void bubble_sort(int arr[], int n, double mod) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if ((double)(arr[j + 1] - arr[j])/mod < 0) { // if(arr[j+1]*mod<arr[j]*mod){  //by LJM
				int temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
void selection_sort(int arr[], int n, int mod) {
	int temp, pos;
	for (int i = 0; i < n; i++) {
		temp = arr[i];
		pos = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] * mod < arr[i] * mod) {
				arr[i] = arr[j];
				pos = j;
			}
		}
		arr[pos] = temp;
	}
}
void insertion_sort(int arr[], int n, int mod) {
	int i, j;
	for (i = 1; i < n; i++) {
		int temp = arr[i];
		for (j = i - 1; j >= 0; j--) {
			if (arr[j] * mod > temp * mod) {
				arr[j + 1] = arr[j];
				continue;
			}
			break;
		}
		arr[j+1] = temp;
	}
}
void shell_insertion_sort(int start, int arr[], int n, int mod, int gap) {
	int i, j;
	for (i = start+gap; i < n; i+=gap) {
		int temp = arr[i];
		for (j = i - gap; j >= 0; j -= gap) {
			if (arr[j] * mod < temp*mod) break;
			arr[j + gap] = arr[j];
		}
		arr[j + gap] = temp;
	}
}
void shell_sort(int arr[], int n, int mod) {
	for (int gap = n / 2; gap > 0; gap /= 2) {
		if (gap % 2 == 0) gap++;
		for (int i = 0; i < gap; i++) {
			shell_insertion_sort(i, arr, n, mod, gap);
		}
	}
}

void quick_sort_sub(int arr[], int s, int e, int mod) {
	if (s >= e) return;
	int pivot = arr[s], pos = s, temp;
	for (int i = s + 1; i <= e; i++) {
		if (arr[i]*mod >= pivot*mod) continue;
		temp = arr[++pos];
		arr[pos] = arr[i];
		arr[i] = temp;
	}
	arr[s] = arr[pos];
	arr[pos] = pivot;
	quick_sort_sub(arr, s, pos - 1, mod);
	quick_sort_sub(arr, pos + 1, e, mod);
}
void quick_sort(int arr[], int n, int mod) {
	quick_sort_sub(arr, 0, n - 1, mod);
}

int divide_by_pivot(int arr[], int s, int e, int mod) {
	if (s >= e) return s;
	int pivot = arr[s], pos=s, temp;
	for (int i = s + 1; i <= e; i++) {
		if (arr[i] * mod > pivot*mod) continue;
		temp = arr[++pos];
		arr[pos] = arr[i];
		arr[i] = temp;
	}
	arr[s] = arr[pos];
	arr[pos] = pivot;
	return pos;
}

void non_recursion_quick_sort(int arr[], int n, int mod) {
	int *check = (int*)malloc(sizeof(int)*(n+1));
	for (int i = 0; i < n; i++) check[i] = 0;
	int s = 0, e = n - 1;
	check[divide_by_pivot(arr, s, e, mod)] = 1;
	while (1) {
		int sw = 0;
		for (int j = 0; j < n; j++) {
			if (check[j] == 1 && check[j - 1] == 0) {
				check[divide_by_pivot(arr, s, j - 1, mod)] = 1;
				s = j + 1;
				sw = 1;
			}
			if (check[j] == 1) s = j + 1;
		}
		if(check[e]==0) check[divide_by_pivot(arr, s, e, mod)] = 1;
		if (sw == 0) break;
	}
}
void merge(int arr[], int s, int m, int e, int mod) {
	int i = s, j = m + 1, pos = 0;;
	int *temp = (int*)malloc(sizeof(int)*(e - s + 2));
	while (i<m+1 || j<e+1) {
		if (i == m + 1) {
			temp[pos++] = arr[j++];
			continue;
		}
		if (j == e + 1) {
			temp[pos++] = arr[i++];
			continue;
		}
		arr[i] * mod < arr[j] * mod ? temp[pos++] = arr[i++] : temp[pos++] = arr[j++];
	}
	for (int i = s; i <= e; i++) {
		arr[i] = temp[i - s];
	}
}
void merge_sub(int arr[], int s, int e, int mod) {
	if (s == e) return;
	int m = (s + e) / 2;
	merge_sub(arr, s, m, mod);
	merge_sub(arr, m + 1, e, mod);
	merge(arr, s, m, e, mod);
}
void merge_sort(int arr[], int n, int mod) {
	merge_sub(arr, 0, n - 1, mod);
}