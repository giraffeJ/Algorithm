#include"basic.h"
#include"sort.h"

int arr[10001];
int n = 10000;
int main() {

	make_rand_arr(arr, n);
	//print_arr("prev_arr : ", arr, n);
	system_clock::time_point start = system_clock::now();
	bubble_sort(arr, n, -1); // 1 : ASC  -1 : DESC
	system_clock::time_point end = system_clock::now();
	//print_arr("bubble_sort : ", arr, n);
	duration<double> t = end - start;
	printf("Execution time : %lf\n\n", t);

	make_rand_arr(arr, n);
	//print_arr("prev_arr : ", arr, n);
	start = system_clock::now();
	selection_sort(arr, n, 1);
	end = system_clock::now();
	//print_arr("selection_sort : ", arr, n);
	t = end - start;
	printf("Execution time : %lf\n\n", t);

	make_rand_arr(arr, n);
	//print_arr("prev_arr : ", arr, n);
	start = system_clock::now();
	insertion_sort(arr, n, -1);
	end = system_clock::now();
	//print_arr("insertion_sort : ", arr, n);
	t = end - start;
	printf("Execution time : %lf\n\n", t);

	make_rand_arr(arr, n);
	//print_arr("prev_arr : ", arr, n);
	start = system_clock::now();
	shell_sort(arr, n, 1);
	end = system_clock::now();
	//print_arr("shell_sort : ", arr, n);
	t = end - start;
	printf("Execution time : %lf\n\n", t);

	make_rand_arr(arr, n);
	//print_arr("prev_arr : ", arr, n);
	start = system_clock::now();
	quick_sort(arr, n, 1);
	end = system_clock::now();
	//print_arr("quick_sort : ", arr, n);
	t = end - start;
	printf("Execution time : %lf\n\n", t);

	make_rand_arr(arr, n);
	//print_arr("prev_arr : ", arr, n);
	start = system_clock::now();
	non_recursion_quick_sort(arr, n, 1);
	end = system_clock::now();
	//print_arr("non_recursion_quick_sort : ", arr, n);
	t = end - start;
	printf("Execution time : %lf\n\n", t);

	make_rand_arr(arr, n);
	//print_arr("prev_arr : ", arr, n);
	start = system_clock::now();
	merge_sort(arr, n, 1);
	end = system_clock::now();
	//print_arr("merge_sort : ", arr, n);
	t = end - start;
	printf("Execution time : %lf\n\n", t);

}