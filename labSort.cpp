#include <iostream>
#include <vector>
#include <cstdlib>

int binarySearch(std::vector<int> arr, int item, int low, int high) {
    if(high <= low) {
        return (item > arr[low]) ? (low + 1) : low;
    }
    int mid = (low + high) / 2;
    if(item == arr[mid]) {
        return mid + 1;
    }

    if(item > arr[mid]) {
        return binarySearch(arr,item,mid + 1,high);
    }
    return binarySearch(arr,item,low,mid - 1);
}

std::vector<int> dataVec() {
    int size;
    int num;
    std::vector<int> nums;

    std::cout << "\nEnter size: ";
    std::cin >> size;
    std::cout << "\nEnter nums: ";

    for(int i = 0; i < size; ++i) {
        std::cin >> num;
        nums.emplace_back(num);
    }
    std::cin.ignore();
    return nums;
}

void print(std::vector<int> arr) {

    for(int i : arr) {
        std::cout << i << " ";
    }
}

void bubleSort() {
    std::system("clear");

    std::vector<int> arr;
    int count = 0;

    arr = dataVec();
    std::cout<<"\nYour nums: ";

    print(arr);
    
    for(int i = 0; i < arr.size(); ++i) {
        bool flag = true;
        for(int j = 0; j < arr.size() - i - 1; ++j) {
            if(arr[j] > arr[j + 1]) {
                flag = false;
                count++;
                std::swap(arr[j], arr[j + 1]);
            }
        }
        if(flag) {
            break;
        }
    }

    std::cout << "\nSorted numbers: ";
    print(arr);
    std::cout <<"\nCount permutation: " << count;
    std::cin.ignore(); 
    arr.clear();
}

void extremum() {
    std::system("clear");

    std::vector<int> arr;
    int count = 0;

    arr = dataVec();
    std::cout << "\nYour nums: ";

    print(arr);
    
    for(int i = 0; i < arr.size() - 1; ++i) {
        int min = arr[i];
        for(int j = i + 1; j < arr.size(); ++j) {
            if(arr[j] < min) {
                min = arr[j];
                arr[j] = arr[i];
                arr[i] = min;
                count++;
            } 
        }
    } 

    std::cout << "\nSorted numbers: ";
    print(arr);
    std::cout <<"\nCount comparisons: " << count;
    std::cin.ignore(); 
    arr.clear();
}

void simpleIns() {
    std::system("clear");

    std::vector<int> arr;
    int k,loc, i, j, select;
    arr = dataVec();
    std::cout << "\nYour nums: ";
    
    print(arr);

    for(i = 1; i < arr.size(); ++i) {
        j = i - 1;
        select = arr[i];
        loc = binarySearch(arr,select,0,j);
        
        while(j >= loc) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = select;
    }

    std::cout << "\nSorted numbers: ";
    print(arr);
    std::cin.ignore(); 
    arr.clear();

}

void lab() {
   int choose = 1;
    
    do {
        std::system("clear");
        std::cout << "Select Option\n\n";
        std::cout << "1.Bubble Sort\n";
        std::cout << "2.Extremum\n";
        std::cout << "3.Simple Insert\n";
        std::cout << "0.Exit\n";
        std::cout <<"\nYour Choose: ";
        std::cin >> choose;

        switch(choose) {
            case 1:
                bubleSort();
                break;
            case 2:
                extremum();
                break;
            case 3:
                simpleIns();
                break;
            case 0:
                exit(0);
            default:
                break;
        }
    } while(choose);

}

int main() {
    lab();
    return 0;
}
