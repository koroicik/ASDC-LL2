void quickSort(std::vector<Item>& data, int left, int right, int& comparisons, int& swaps) {
    if (left >= right) {
        return;
    }

    int pivot = data[(left + right) / 2].key;
    int i = left;
    int j = right;
    while (i <= j) {
        while (data[i].key < pivot) {
            ++i;
            ++comparisons;
        }
        while (data[j].key > pivot) {
            --j;
            ++comparisons;
        }
        if (i <= j) {
            std::swap(data[i], data[j]);
            ++swaps;
            ++i;
            --j;
        }
    }
    quickSort(data, left, j, comparisons, swaps);
    quickSort(data, i, right, comparisons, swaps);
}

void quickSort(std::vector<Item>& data) {
    int comparisons = 0;
    int swaps = 0;
    auto start = std::chrono::high_resolution_clock::now();

    quickSort(data, 0, data.size() - 1, comparisons, swaps);

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "Quick Sort:" << std::endl;
    std::cout << "Theoretical complexity: O(n*log(n))" << std::endl;
    std::cout << "Number of comparisons: " << comparisons << std::endl;
    std::cout << "Number of swaps: " << swaps << std::endl;
    std::cout << "Time taken: " << duration.count() << " microseconds" << std::endl;
}
