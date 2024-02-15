#include <iostream>
#include <random>
#include <vector>
#include <ctime>


void sort(std::vector<int>&left, std::vector<int>& right, std::vector<int>& bars);
std::vector<int> getRandomVector(int size)
{
    std::random_device rd;
    std::uniform_int_distribution<int> distribution(0, 1000000000);
    std::vector<int> vec;
    for (int i = 0; i < size; i++)
    {
        vec.push_back(distribution(rd));
    }

    return vec;
}

// src - CSE431 lecture 2
void insertionSort(std::vector<int>& arr) {
    for (int i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
// src - https://codereview.stackexchange.com/questions/167680/merge-sort-implementation-with-vectors
void mergeSort(std::vector<int> & bar) 
{
    if (bar.size() <= 1) return;

    int mid = bar.size() / 2;
    std::vector<int> left;
    std::vector<int> right;

    for (size_t j = 0; j < mid;j++)
        left.push_back(bar[j]);
    for (size_t j = 0; j < (bar.size()) - mid; j++)
        right.push_back(bar[mid + j]);

    mergeSort(left);
    mergeSort(right);
    sort(left, right, bar);
}
// src - https://codereview.stackexchange.com/questions/167680/merge-sort-implementation-with-vectors
void sort(std::vector<int>&left, std::vector<int>& right, std::vector<int>& bars)
{
    int nL = left.size();
    int nR = right.size();
    int i = 0, j = 0, k = 0;

    while (j < nL && k < nR) 
    {
        if (left[j] < right[k]) {
            bars[i] = left[j];
            j++;
        }
        else {
            bars[i] = right[k];
            k++;
        }
        i++;
    }
    while (j < nL) {
        bars[i] = left[j];
        j++; i++;
    }
    while (k < nR) {
        bars[i] = right[k];
        k++; i++;
    }
}

void testSorts(int vectorSize, int repeats)
{
    std::clock_t total_time_insertion = 0, total_time_merge = 0;
    for (int i = 0; i < repeats; i++)
    {
        std::vector<int> v1 = getRandomVector(vectorSize);
        std::vector<int> v2 = v1;
        std::clock_t start_time = std::clock();
        insertionSort(v1);
        std::clock_t end_time = std::clock();
        total_time_insertion += (end_time - start_time);

        start_time = std::clock();
        mergeSort(v2);
        end_time = std::clock();
        total_time_merge += (end_time - start_time);
    }
    std::cout << "Insertion sort, " << vectorSize << " elements: " << ((double) total_time_insertion) / ((double) repeats) << " milliseconds." << std::endl;
    std::cout << "Merge sort, " << vectorSize << " elements: " << ((double) total_time_merge) / ((double) repeats) << " milliseconds." << std::endl;  
}
int main()
{
    testSorts(10, 100000);
    testSorts(20, 50000);
    testSorts(30, 40000);
    testSorts(40, 30000);
    testSorts(50, 20000);
    testSorts(60, 10000);
    testSorts(70, 1000);
    testSorts(80, 1000);
    testSorts(90, 1000);
    testSorts(100, 800);
    testSorts(150, 500);
    testSorts(200, 500);
    testSorts(300, 400);
    testSorts(400, 400);
    testSorts(500, 300);
    testSorts(750, 200);
    testSorts(1000, 100);
    testSorts(1250, 100);
    testSorts(1500, 100);
    testSorts(1750, 50);
    testSorts(2000, 50);
    testSorts(2500, 50);
    testSorts(2750, 50);
    testSorts(3000, 50);
    testSorts(3250, 50);
    testSorts(3500, 50);
    testSorts(3750, 50);
    testSorts(4000, 50);


}