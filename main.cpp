#include <iostream>
#include <memory>
#include <optional>
#include <string>
#include <vector>
using namespace std;

/*
 *  This project will use ASCII art:
 *                                                                  _
 *  A box represents reserved memory (to hold a variable's value): | |
 *                                                                 |_|
 *                                                                              ?_
 *  A box with a question mark in the upper left corner represents an optional: | |
 *                                                                              |_|
 *                                                      _ _ _ _ _ _
 *  A series of consecutive boxes represents a vector: | | | | | | |
 *                                                     |_|_|_|_|_|_|
 *
 *  An arrow represents a pointer: ---->
 *
 *  An arrow with a bar represents a nullptr: -->|
 *
 *  An optional pointer set to nullptr: ?_
 *                                      | | -->|
 *                                      |_|
 */


int main() {
    /* 1. Create the following three optional integers:
     *      ?__
     *      |  |
     *      |__|
     *      ?__
     *      |42|
     *      |__|
     *      ?__?__?__?__?__?__?__?__
     *      |  |90|44|  |79|  |-5|17|
     *      |__|__|__|__|__|__|__|__|
     */

    optional<int> opt1 = nullopt;
    optional<int> opt2 = 42;
    vector <optional<int>> optVec1;
    optVec1.push_back(nullopt);
    optVec1.push_back(90);
    optVec1.push_back(44);
    optVec1.push_back(nullopt);
    optVec1.push_back(79);
    optVec1.push_back(nullopt);
    optVec1.push_back(-5);
    optVec1.push_back(17);

    /* 2. Create the following smart pointers,
     *    where each one points to a different data type:
     *      Stack           Heap
     *       __              __
     *      |  | ---------> |11|
     *      |__|            |__|
     *       __              ___
     *      |  | ---------> |0.3|
     *      |__|            |___|
     *       __              __
     *      |  | ---------> |d |
     *      |__|            |__|
     *       __              __
     *      |  | ---------> |yo|
     *      |__|            |__|
     */

    unique_ptr<int> intPtr = make_unique<int>(11);
    unique_ptr<double> doublePtr = make_unique<double>(0.3);
    unique_ptr<char> charPtr = make_unique<char>('d');
    unique_ptr<string> stringPtr = make_unique<string>("yo");

    /* 3. Use ASCII art to draw in the comments what the following code looks like in memory:
     *      Stack           Heap
     *
     *  __           _ _ _ _ _ _
     * |  | ------> |11|22|33|44|55|66|77|88|
     * |__|         |_|_|_|_|_|_|_|_|_|_|_|_|
     *
     */

    unique_ptr<vector<int>> heapVec = make_unique<vector<int>>();
    for (int n = 11; n <= 88; n += 11) {
        heapVec->push_back(n);
    }

    /* 4. Use ASCII art to draw in the comments what the following code looks like in memory:
     *      Stack      Heap
     *       __         __         ___
     *      |  | ----> |  | ----> | m |
     *      |__|       |__|       |___|
     *
     */

    unique_ptr<unique_ptr<char>> heapPtrChar = make_unique<unique_ptr<char>>();
    *heapPtrChar = make_unique<char>('m');

    /* 5. Create the following smart pointers to your choice of data type:
     *      Stack      Heap
     *       __         __
     *      |  | ----> |3 |
     *      |__|    >  |__|
     *             /
     *       __   /
     *      |  | /
     *      |__|
     */

    shared_ptr<int> sharedPtr1 = make_shared<int>();
    shared_ptr<int> sharedPtr2 = shared_ptr<int>();

    /* 6. Use ASCII art to draw in the comments what the following code looks like in memory:
     *      Stack      Heap
     *      ?__        __
     *      |  | ---> |  |
     *      |__|      |__|
     *
     *      ?__
     *      |  | ---> |
     *      |__|
     *
     */

    optional<unique_ptr<int>> opIntPtr1 = nullopt;
    optional<unique_ptr<int>> opIntPtr2 = make_optional<unique_ptr<int>>(nullptr);
    optional<unique_ptr<int>> opIntPtr3 = make_optional<unique_ptr<int>>(make_unique<int>(98));

    /* 7. Create the following smart pointers to optionals:
     *      Stack      Heap
     *       __
     *      |  | --->|
     *      |__|
     *
     *       __        ?__
     *      |  | ----> |  |
     *      |__|       |__|
     *
     *       __        ?__
     *      |  | ----> |hi|
     *      |__|       |__|
     */

     unique_ptr<optional<int>> smartPtr = nullptr;
     unique_ptr<optional<int>> smartPtr2 = make_unique<optional<int>>(nullopt);
     unique_ptr<optional<string>> smartPtr3 = make_unique<optional<string>>("hi");

    return 0;
}