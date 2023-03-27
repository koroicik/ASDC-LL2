void insertionSort(std::vector<Item>& data) {
    int comparisons = 0;
    int swaps = 0;
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 1; i < data.size(); ++i) {
        Item key = data[i];
        int j = i - 1;
        while (j >= 0 && data[j].key > key.key) {
            data[j + 1] = data[j];
            --j;
            ++comparisons;
            ++swaps;
        }
        data[j + 1] = key;
        ++swaps;
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "Insertion Sort:" << std::endl;
    std::cout << "Theoretical complexity: O(n^2)" << std::endl;
    std::cout << "Number of comparisons: " << comparisons << std::endl;
    std::cout << "Number of swaps: " << swaps << std::endl;
    std::cout << "Time taken: " << duration.count() << " microseconds" << std::endl;
}
