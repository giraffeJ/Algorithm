#pragma once
#include<iostream>
#include<string>
#include<chrono>
#include<stdlib.h>
using namespace std;
using namespace chrono;
void print_arr(string message, int arr[], int n) {
	cout << message;
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
void make_rand_arr(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		arr[i] = rand()%100000;
	}
}