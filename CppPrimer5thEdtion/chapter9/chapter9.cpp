#include "chapter9.h"

int exercise9_1() { return 0; }
int exercise9_2()
{
    deque<int> a{1, 2, 3, 4, 6, 5};
    list<deque<int>> b{a, {7, 9, 8}};

    // First method: range for
    cout << "// First method: range for" << endl;
    for (const auto &intDeque : b)
    {
        for (const auto &num : intDeque)
        {
            cout << num;
        }
        cout << endl;
    }

    // Second method: iterator
    cout << "// Second method: iterator" << endl;
    for (auto it1 = b.begin(); it1 != b.end(); ++it1)
    {
        for (auto it2 = it1->begin(); it2 != it1->end(); ++it2)
        {
            cout << *it2;
        }
        cout << endl;
    }

    // Third method: range for and iterator
    cout << "// Third method: range for and iterator" << endl;
    for (const auto &intDeque : b)
    {
        for (auto it2 = intDeque.begin(); it2 != intDeque.end(); ++it2)
        {
            cout << *it2;
        }
        cout << endl;
    }

    return 0;
}

int exercise9_3()
{

    return 0;
}

bool findValInVector(vector<int>::iterator bi, vector<int>::iterator ei, int target)
{
    for (auto &start = bi; start != ei; ++start)
    {
        if (*start == target)
            return true;
    }

    return false;
}

int exercise9_4()
{

    vector<int> a{1, 2, 3, 4, 6, 5};
    cout << findValInVector(a.begin(), a.end(), 5) << endl;

    return 0;
}

vector<int>::iterator findInteratorInVector(vector<int>::iterator bi, vector<int>::iterator ei, int target)
{
    for (auto &start = bi; start != ei; ++start)
    {
        if (*start == target)
            return start;
    }

    return ei;
}

int exercise9_5()
{

    vector<int> a{1, 2, 3, 4, 6, 5};

    vector<int> b{5, 7};

    for (auto &num : b)
    {
        vector<int>::iterator result = findInteratorInVector(a.begin(), a.end(), num);
        if (result != a.end())
            cout << "Find num: " << num << endl;
        else
            cout << "No num: " << num << endl;
    }

    return 0;

    return 0;
}

int exercise9_6()
{
    list<int> lst1{3, 2, 1, 6, 5};
    list<int>::iterator iter1 = lst1.begin(),
                        iter2 = lst1.end();

    while (iter1 != iter2)
    {
        cout << *iter1 << endl;
        ++iter1;
    }

    return 0;
}

int exercise9_7()
{

    return 0;
}

int exercise9_8()
{
    list<string> lst1{"char", "string"};

    list<string>::value_type a = *(lst1.begin());

    cout << a << endl;

    lst1.push_back(a + "123");

    lst1.push_front("123456");

    for (const auto &val : lst1)
    {
        cout << val << endl;
    }

    return 0;
}
int exercise9_9() { return 0; }

int exercise9_10()
{
    vector<int> v1;
    const vector<int> v2;
    auto it1 = v1.begin();

    auto it2 = v2.begin();
    auto it3 = v1.cbegin(), it4 = v2.cbegin();

    return 0;
}

int exercise9_11()
{
    vector<int> vec1{3, 2, 1, 6, 5};
    vector<int> vec2(10, 0);
    vector<int> vec3;
    vector<int> vec4(vec1.begin() + 1, vec1.begin() + 4);
    vector<int> vec5(vec1);
    vector<int> vec6(11);

    return 0;
}
int exercise9_12()
{

    list<int> lst1{3, 2, 1, 6, 5};

    vector<int> vec1(lst1.begin(), lst1.end());

    rangeForVector(vec1);

    list<int>::iterator start = lst1.begin();
    ++start;
    ++start;
    vector<int> vec2(start, lst1.end());
    rangeForVector(vec2);

    list<const char *> lst2{"abc", "def", "hqe"};

    vector<string> vec3(lst2.begin(), lst2.end());

    rangeForVector(vec3);

    return 0;
}

int exercise9_13()
{

    list<int> lst1{3, 2, 1, 6, 5};
    vector<int> vec1{1, 6, 5};

    vector<double> vec2(lst1.begin(), lst1.end());
    vector<double> vec3(vec1.begin(), vec1.end());

    rangeForVector(vec2);
    rangeForVector(vec3);

    return 0;
}

int exercise9_14()
{

    list<const char *> lst2{"abc", "def", "hqe"};

    vector<string> vec3(lst2.begin(), lst2.end());

    rangeForVector(vec3);

    return 0;
}

int exercise9_15()
{

    list<int> lst1{3, 2, 1, 6, 5};
    vector<int> vec1{1, 6, 5};

    vector<double> vec2(lst1.begin(), lst1.end());
    vector<double> vec3(vec1.begin(), vec1.end());

    cout << "vec2 == vec3? " << (vec2 == vec3) << endl;

    vector<double> vec4{1, 6, 7};

    cout << "vec3 < vec4? " << (vec3 < vec4) << endl;

    vector<double> vec5{1, 6, 5};
    cout << "vec5 == vec3? " << (vec5 == vec3) << endl;

    return 0;
}

int exercise9_16()
{

    list<int> lst1{3, 2, 1, 6, 5};
    vector<int> vec1{1, 6, 5};

    // no match for ‘operator==’ (operand types are ‘std::__cxx11::list<int>’ and ‘std::vector<int>’)
    // cout << "lst1 == vec1? " << (lst1 == vec1) << endl;

    return 0;
}

int exercise9_17()
{
    return 0;
}

int exercise9_18()
{
    deque<string> strDeque;
    string temp;
    // step 1: read strings from std input
    while (getline(cin, temp))
    {
        strDeque.push_back(temp);
    }
    // step 2: iterator deque using iterator
    auto st = strDeque.cbegin(), ed = strDeque.cend();
    while (st != ed)
    {
        cout << *st;
        ++st;
    }

    return 0;
}

int exercise9_19()
{
    list<string> strList;
    string temp;
    // step 1: read strings from std input
    while (getline(cin, temp))
    {
        strList.push_back(temp);
    }
    // step 2: iterator deque using iterator
    auto st = strList.cbegin(), ed = strList.cend();
    while (st != ed)
    {
        cout << *st;
        ++st;
    }

    return 0;
}

int exercise9_20()
{
    list<int> intList;
    deque<int> oddIntDeque, evenIntDeque;

    for (int i = 0; i < 50000000; ++i)
        intList.push_back(i);

    // method 1: iterate intList and classify the item
    for (auto st = intList.cbegin(); st != intList.cend(); ++st)
    {
        if (*st % 2 == 0)
            evenIntDeque.push_back(*st);
        else
            oddIntDeque.push_back(*st);
    }

    cout << "oddIntDeque: " << oddIntDeque.size() << ", evenIntDeque: " << evenIntDeque.size() << endl;
    return 0;
}

int exercise9_21()
{
    list<int> intList{1, 2, 3, 4, 5};
    vector<int> intVec{6, 7, 8, 9, 10};
    int temp = 0;

    // For list: do insert to intList, which is equal to push_front
    // auto iter = intList.begin();
    // while (cin >> temp)
    // {
    //     iter = intList.insert(iter, temp);
    // }

    // for (auto st = intList.cbegin(); st != intList.cend(); ++st)
    //     cout << *st << ", ";

    // For vector: do insert to intVec, which is equal to push_back
    auto iter1 = intVec.end();
    while (cin >> temp)
    {
        iter1 = intVec.insert(iter1, temp);
        ++iter1; // or iter1 = iter1.end();
    }

    for (auto st = intVec.cbegin(); st != intVec.cend(); ++st)
        cout << *st << ", ";

    return 0;
}

int exercise9_22()
{
    vector<int> iv{6, 7, 5, 8, 9, 10};
    int some_val = 5;
    // The original code does not maintain iter and mid after insert element into vector.
    vector<int>::iterator iter = iv.begin(), org_mid = iv.begin() + iv.size() / 2;
    while (iter < org_mid)
    {
        if (*iter == some_val)
        {
            cout << "original mid is " << *org_mid << endl;
            cout << "original iter is " << *iter << endl;
            // insert value
            iter = iv.insert(iter, 2 * some_val);
            // maintain iterator
            iter += 2;
            org_mid = iv.begin() + iv.size() / 2 + 1;

            cout << "updated mid is " << *org_mid << endl;
            cout << "updated iter is " << *iter << endl;
        }
        else
        {
            ++iter;
        }
    }

    for (auto st = iv.cbegin(); st != iv.cend(); ++st)
        cout << *st << ", ";

    return 0;
}

void showFrontAndBack(vector<int> vec)
{
    if (!vec.empty())
    {
        auto val1 = *vec.begin(), val2 = vec.front();

        auto last = vec.end();

        auto val3 = *(--last), val4 = vec.back();

        cout << "val1: " << val1 << ", val2: " << val2 << ", val3: " << val3 << ", val4: " << val4 << endl;
    }
}

int exercise9_23()
{
    vector<int> c{10, 11};
    showFrontAndBack(c);

    vector<int> d{10};
    showFrontAndBack(d);

    return 0;
}

void showFirstElement(vector<int> vec)
{
    cout << "showFirstElement: " << endl;
    cout << "Using at : " << vec.at(0) << endl;              // when vec is empty, ERROR:  vector::_M_range_check: __n (which is 0) >= this->size() (which is 0)
    cout << "Using subscript operator : " << vec[0] << endl; // when vec is empty, ERROR: Segmentation fault
    cout << "Using at : " << vec.front() << endl;            // when vec is empty, ERROR: Segmentation fault
    cout << "Using at : " << *vec.begin() << endl;           // when vec is empty, ERROR: Segmentation fault
}

int exercise9_24()
{
    vector<int> arr1{10, 11};
    showFirstElement(arr1);

    // test func with empty vector
    vector<int> arr2;
    showFirstElement(arr2);
    return 0;
}

int exercise9_25()
{
    vector<int> slist{10, 11, 12, 13, 14, 15, 16};
    auto elem1 = slist.begin(), elem2 = slist.end();
    --elem2;
    elem1 = slist.erase(elem1, elem2);
    cout << *elem1 << endl;
    // when elem1 == elem2, then erase does nothing.
    elem1 = slist.erase(elem1, elem2);
    cout << *elem1 << endl;

    // when elem1 and elem2 are both off-the-end iterator, then erase does nothing.
    elem1 = slist.end(), elem2 = slist.end();
    elem1 = slist.erase(elem1, elem2);
    cout << *elem1 << ", " << *elem2 << endl;
    cout << slist.at(0) << endl;

    return 0;
}
int exercise9_26()
{
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> veca{std::begin(ia), std::end(ia)};
    list<int> lista{std::begin(ia), std::end(ia)};

    auto vecIt = veca.begin();
    while (vecIt != veca.end())
    {
        if (!(*vecIt % 2))
            vecIt = veca.erase(vecIt);
        else
            ++vecIt;
    }

    auto listIt = lista.begin();
    while (listIt != lista.end())
    {
        if (*listIt % 2)
            listIt = lista.erase(listIt);
        else
            ++listIt;
    }

    for (auto &a : veca)
    {
        cout << a << ",";
    }
    cout << endl;
    for (auto &b : lista)
    {
        cout << b << ",";
    }
    cout << endl;

    return 0;
}

int exercise9_27()
{
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    forward_list<int> fla{std::begin(ia), std::end(ia)};

    auto prev = fla.before_begin(), curr = fla.begin();
    while (curr != fla.end())
    {
        if (!(*curr % 2))
            curr = fla.erase_after(prev);
        else
        {
            prev = curr;
            ++curr;
        }
    }

    for (auto &b : fla)
    {
        cout << b << ",";
    }
    cout << endl;

    return 0;
}

bool insertStr2AfterStr1(forward_list<string> &a, const string &str1, const string &str2)
{
    auto curr = a.begin(), prev = a.before_begin();

    while (curr != a.end())
    {
        if (*curr == str1)
        {
            curr = a.insert_after(curr, str2);
            cout << "Curr : " << *curr << endl;
            return true;
        }
        else
        {
            prev = curr;
            ++curr;
        }
    }

    curr = a.insert_after(prev, str2);
    cout << "Curr : " << *curr << endl;
    return false;
}

int exercise9_28()
{
    forward_list<string> fla{"abc", "bcd", "edf"};

    cout << insertStr2AfterStr1(fla, "bcd", "hahahaha");

    for (auto &b : fla)
    {
        cout << b << ",";
    }
    cout << endl;

    cout << insertStr2AfterStr1(fla, "bc", "hahahaha");

    for (auto &b : fla)
    {
        cout << b << ",";
    }
    cout << endl;

    return 0;
}
int exercise9_29()
{
    int SIZE = 25;
    vector<int> vecA;

    for (int i = 0; i != SIZE; ++i)
    {
        vecA.push_back(i);
    }

    for (auto &b : vecA)
    {
        cout << b << ",";
    }
    cout << endl;

    vector<int> vecB(vecA);

    vecA.resize(30);

    for (auto &b : vecA)
    {
        cout << b << ",";
    }
    cout << endl;

    vecB.resize(10);
    for (auto &b : vecB)
    {
        cout << b << ",";
    }
    cout << endl;

    return 0;
}

int exercise9_30()
{
    return 0;
}
int exercise9_31() { return 0; }
int exercise9_32() { return 0; }
int exercise9_33() { return 0; }
int exercise9_34() { return 0; }
int exercise9_35() { return 0; }
int exercise9_36() { return 0; }
int exercise9_37() { return 0; }
int exercise9_38() { return 0; }
int exercise9_39() { return 0; }
int exercise9_40() { return 0; }
int exercise9_41() { return 0; }
int exercise9_42() { return 0; }
int exercise9_43() { return 0; }
int exercise9_44() { return 0; }
int exercise9_45() { return 0; }
int exercise9_46() { return 0; }
int exercise9_47() { return 0; }
int exercise9_48() { return 0; }
int exercise9_49() { return 0; }
int exercise9_50() { return 0; }
int exercise9_51() { return 0; }
int exercise9_52() { return 0; }
