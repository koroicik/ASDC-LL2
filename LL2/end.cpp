int main() {
    std::vector<Item> data;
    readDataFromFile(data, "data.txt");
    insertionSort(data);
    selectionSort(data);
    quickSort(data);
    return 0;
}
