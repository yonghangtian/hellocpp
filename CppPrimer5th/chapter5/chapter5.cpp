#include "chapter5.h"

int exercise5_5()
{
    vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
    // if grade is less than 60 it's an F, otherwise compute a subscript
    vector<int> grades{59, 61, 76, 80, 91, 98};

    string lettergrade;

    for (const auto grade : grades)
    {
        if (grade < 60)
            lettergrade = scores[0];
        else
        {
            lettergrade = scores[(grade - 50) / 10];
            if (grade != 100) // add plus or minus only if not already an A++
                if (grade % 10 > 7)
                    lettergrade += '+'; // grades ending in 8 or 9 get a +
                else if (grade % 10 < 3)
                    lettergrade += '-'; // grades ending in 0, 1, or 2 get a -
        }

        cout << "grade: " << grade << " , letter grade : " << lettergrade << endl;
    }
    return 0;
}

int exercise5_6()
{
    vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
    // if grade is less than 60 it's an F, otherwise compute a subscript
    vector<int> grades{59, 61, 76, 80, 91, 98, 100};

    string lettergrade;

    for (const auto grade : grades)
    {
        lettergrade = (grade < 60) ? scores[0] : ((grade == 100) || ((grade % 10) >= 3 && (grade % 10) <= 7)) ? scores[(grade - 50) / 10]
                                             : (grade % 10 > 7)                                               ? scores[(grade - 50) / 10] + "+"
                                                                                                              : scores[(grade - 50) / 10] + "-";

        cout << "grade: " << grade << " , letter grade : " << lettergrade << endl;
    }

    return 0;
}

int exercise5_7()
{
    // // (a)
    // if (ival1 != ival2)
    //     ival1 = ival2;
    // else
    //     ival1 = ival2 = 0;

    // // (b)
    // if (ival < minval)
    // {
    //     minval = ival;
    //     occurs = 1;
    // }

    // // (c)
    // int ival = 1;
    // if (ival == get_value())
    //     cout << "ival = " << ival << endl;
    // if (!ival)
    //     cout << "ival = 0\n";

    // // (d)
    // if (ival == 0)
    //     ival = get_value();

    return 0;
}

int exercise5_8()
{
    // 悬浮的else或else if会与最近的一个if结合
    int a = 10;
    if (a >= 9)
        if (a > 11)
            cout << "a > 11" << endl;
        else if (a > 10)
            cout << "a > 10" << endl;
        else
            cout << "a == 10" << endl;

    return 0;
}

int exercise5_9()
{
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;

    char ch;
    //  (Press Ctrl + D to input EOF signal.)
    while (cin >> ch)
    {
        // if ch is a vowel, increment the appropriate counter
        if (ch == 'a')
        {
            ++aCnt;
        }
        else if (ch == 'e')
        {
            ++eCnt;
        }
        else if (ch == 'i')
        {
            ++iCnt;
        }
        else if (ch == 'o')
        {
            ++oCnt;
        }
        else if (ch == 'u')
        {
            ++uCnt;
        }
    }
    // print results
    cout << "Number of vowel a: \t" << aCnt << '\n'
         << "Number of vowel e: \t" << eCnt << '\n'
         << "Number of vowel i: \t" << iCnt << '\n'
         << "Number of vowel o: \t" << oCnt << '\n'
         << "Number of vowel u: \t" << uCnt << endl;

    return 0;
}

int exercise5_10()
{

    // initialize counters for each vowel
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;

    char ch;
    while (cin >> ch)
    {
        // if ch is a vowel, increment the appropriate counter
        switch (ch)
        {
        case 'A':
        case 'a':
            ++aCnt;
            break;
        case 'E':
        case 'e':
            ++eCnt;
            break;
        case 'I':
        case 'i':
            ++iCnt;
            break;
        case 'O':
        case 'o':
            ++oCnt;
            break;
        case 'U':
        case 'u':
            ++uCnt;
            break;
        }
    }
    // print results
    cout << "Number of vowel a: \t" << aCnt << '\n'
         << "Number of vowel e: \t" << eCnt << '\n'
         << "Number of vowel i: \t" << iCnt << '\n'
         << "Number of vowel o: \t" << oCnt << '\n'
         << "Number of vowel u: \t" << uCnt << endl;

    return 0;
}
int exercise5_11()
{
    // initialize counters for each vowel
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, spaceCnt = 0, tabCnt = 0, lineCnt = 0;

    char ch;
    // "cin >> ch" does not process space, tab and \n
    while (cin.get(ch))
    {
        // if ch is a vowel, increment the appropriate counter
        switch (ch)
        {
        case 'A':
        case 'a':
            ++aCnt;
            break;
        case 'E':
        case 'e':
            ++eCnt;
            break;
        case 'I':
        case 'i':
            ++iCnt;
            break;
        case 'O':
        case 'o':
            ++oCnt;
            break;
        case 'U':
        case 'u':
            ++uCnt;
            break;
        case ' ':
            ++spaceCnt;
            break;
        case '\t':
            ++tabCnt;
            break;
        case '\n':
            ++lineCnt;
            break;
        }
    }
    // print results
    cout << "Number of vowel a: \t" << aCnt << '\n'
         << "Number of vowel e: \t" << eCnt << '\n'
         << "Number of vowel i: \t" << iCnt << '\n'
         << "Number of vowel o: \t" << oCnt << '\n'
         << "Number of vowel u: \t" << uCnt << '\n'
         << "Number of space: \t" << spaceCnt << '\n'
         << "Number of tab: \t" << tabCnt << '\n'
         << "Number of lines: \t" << lineCnt << '\n'
         << endl;

    return 0;
}

int exercise5_12()
{

    // initialize counters for each vowel
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, ffCnt = 0, flCnt = 0, fiCnt = 0;

    char ch = 'b', prevch = 'b';
    // "cin >> ch" does not process space, tab and \n
    // "cin.get(ch)" process all character from cin. we need to use cin.get(ch) as there should be no space between ff, fl and fi

    while ((prevch = ch) && cin.get(ch))
    {
        // if ch is a vowel, increment the appropriate counter
        switch (ch)
        {
        case 'A':
        case 'a':
            ++aCnt;
            break;
        case 'E':
        case 'e':
            ++eCnt;
            break;
        case 'I':
        case 'i':
            ++iCnt;
            if (prevch == 'f' && ch == 'i')
            {
                ++fiCnt;
            }
            break;
        case 'O':
        case 'o':
            ++oCnt;
            break;
        case 'U':
        case 'u':
            ++uCnt;
            break;
        case 'f':
            if (prevch == 'f')
            {
                ++ffCnt;
            }
            break;
        case 'l':
            if (prevch == 'f')
            {
                ++flCnt;
            }
            break;
        }
    }
    // print results
    cout << "Number of vowel a: \t" << aCnt << '\n'
         << "Number of vowel e: \t" << eCnt << '\n'
         << "Number of vowel i: \t" << iCnt << '\n'
         << "Number of vowel o: \t" << oCnt << '\n'
         << "Number of vowel u: \t" << uCnt << '\n'
         << "Number of ff: \t" << ffCnt << '\n'
         << "Number of fl: \t" << flCnt << '\n'
         << "Number of fi: \t" << fiCnt << '\n'
         << endl;

    return 0;
}

int exercise5_13()
{

    // // (a)
    // unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
    // char ch = next_text();
    // switch (ch)
    // {
    // case 'a':
    //     aCnt++;
    //     break;
    // case 'e':
    //     eCnt++;
    //     break;
    // default:
    //     iouCnt++;
    //     break;
    // }
    // // (b)
    // unsigned index = some_value();
    // int ix = 0;
    // switch (index)
    // {
    // case 1:
    //     ix = get_value();
    //     ivec[ix] = index;
    //     break;
    // default:
    //     ix = ivec.size() - 1;
    //     ivec[ix] = index;
    // }
    // // (c)
    // unsigned evenCnt = 0, oddCnt = 0;
    // int digit = get_num() % 10;
    // switch (digit)
    // {
    // case 1:
    // case 3:
    // case 5:
    // case 7:
    // case 9:
    //     oddcnt++;
    //     break;
    // case 2:
    // case 4:
    // case 6:
    // case 8:
    // case 10:
    //     evencnt++;
    //     break;
    // }

    // // (d)
    // const unsigned ival = 512, jval = 1024, kval = 4096;
    // unsigned bufsize;
    // unsigned swt = get_bufCnt();
    // switch (swt)
    // {
    // case ival:
    //     bufsize = ival * sizeof(int);
    //     break;
    // case jval:
    //     bufsize = jval * sizeof(int);
    //     break;
    // case kval:
    //     bufsize = kval * sizeof(int);
    //     break;
    // }

    return 0;
}
int exercise5_14()
{
    string inStr, prevStr, maxRepeatStr;
    int repeatTime = 0, maxRepeatTime = 0;

    while (cin >> inStr)
    {
        if (prevStr == inStr)
        {
            ++repeatTime;
            if (repeatTime > maxRepeatTime)
            {
                maxRepeatTime = repeatTime;
                maxRepeatStr = inStr;
            }
        }
        else
        {
            repeatTime = 1;
            prevStr = inStr;
        }
    }

    if (maxRepeatTime >= 1)
    {
        cout << "Word " << maxRepeatStr << " repeated " << maxRepeatTime << " times" << endl;
    }
    else
    {
        cout << "No word repeat." << endl;
    }

    return 0;
}

int exercise5_15()
{
    // // (a)
    // int ix;
    // for (ix = 0; ix != sz; ++ix)
    // { /* . . . */
    // }
    // if (ix != sz)
    // {
    // }
    // //  (b)
    // int ix;
    // for (/*indicate the init part is empty*/; ix != sz; ++ix)
    // { /* . . . */
    // }
    // // (c) remove , ++sz, as this command will make the for loop never end.
    // for (int ix = 0; ix != sz; ++ix)
    // { /* . . . */
    // }

    return 0;
}

int exercise5_16()
{
    // read grades from file.
    vector<int> gradesA, gradesB;
    int grade = 0;
    string filePath = "/home/tianyh/projects/hellocpp/CppPrimer5th/chapter5/data/grades";
    ifstream fileA(filePath);

    if (!fileA.is_open())
    { // 检查文件是否成功打开
        std::cerr << "Failed to open file\n";
        return 1;
    }
    // read file using while loop
    while (fileA >> grade)
    {
        gradesA.push_back(grade);
    }

    fileA.clear();  // 清除流的状态标志
    fileA.seekg(0); // 重置文件位置到文件开头

    for (; fileA >> grade;) // read file using for loop
    {
        gradesB.push_back(grade);
    }
    cout << "range for" << endl;
    rangeForVector(gradesA);
    rangeForVector(gradesB);

    // rangeForVector is a good "for loop" example.
    // let's rewrite rangeForVector using while loop.
    cout << "range while" << endl;
    rangeWhileVector(gradesA);
    rangeWhileVector(gradesB);

    return 0;
}

int exercise5_17()
{
    vector<int> gradesA, gradesB;

    // gradesA = {11, 12, 13};
    // gradesB = {11, 12, 14};

    // gradesA = {11,12,13};
    // gradesB = {11,12,13,14};

    // gradesA = {11,12,13};
    // gradesB = {11,12,14,15};

    gradesA = {11, 12, 13};
    gradesB = {11, 12, 13};

    bool subVectorFlag = true;
    if (gradesA.size() == gradesB.size())
    {
        if (gradesA != gradesB)
            subVectorFlag = false;
    }
    else
    {
        auto smallSize = (gradesA.size() <= gradesB.size()) ? gradesA.size() : gradesB.size();

        for (int i = 0; i < smallSize; ++i)
        {
            if (gradesA[i] != gradesB[i])
            {
                subVectorFlag = false;
                break;
            }
        }
    }
    cout << subVectorFlag << endl;
    return 0;
}
int exercise5_18()
{

    // // (a)
    // do{ int v1, v2;
    // cout << "Please enter two numbers to sum:";
    // if (cin >> v1 >> v2)
    //     cout << "Sum is: " << v1 + v2 << endl;
    // }while (cin)
    //     ;
    // // (b)
    // int ival = 0;
    // do
    // {
    //     // . . .
    // }
    // while (ival = get_response());
    // // (c)
    // int ival = 0;
    // do
    // {
    //     ival = get_response();
    // }
    // while (ival);

    return 0;
}
int exercise5_19()
{
    string s1, s2;
    do
    {

        cout << "Please enter two strings to compare:";
        if (cin >> s1 >> s2)
        {
            if (s1 == s2)
                cout << "equal" << endl;
            else if (s1 < s2)
                cout << "s1 < s2" << endl;
            else
                cout << "s1 > s2" << endl;
        }
        else
            cout << "Bye." << endl;
    } while (cin);

    return 0;
}

int exercise5_20()
{

    string inStr, prevStr, maxRepeatStr;
    int repeatTime = 0;
    const unsigned maxRepeatTime = 2;

    while (cin >> inStr)
    {
        if (prevStr == inStr)
        {
            ++repeatTime;
            if (repeatTime == maxRepeatTime)
            {
                maxRepeatStr = inStr;
                break;
            }
        }
        else
        {
            repeatTime = 1;
            prevStr = inStr;
        }
    }

    if (repeatTime == maxRepeatTime)
    {
        cout << "Word " << maxRepeatStr << " repeated " << maxRepeatTime << " times" << endl;
    }
    else
    {
        cout << "No word repeat twice." << endl;
    }

    return 0;
}

int exercise5_21()
{
    string inStr, prevStr, maxRepeatStr;
    int repeatTime = 0;
    const unsigned maxRepeatTime = 2;

    while (cin >> inStr)
    {
        if (!isupper(inStr[0]))
            continue;

        if (prevStr == inStr)
        {
            ++repeatTime;
            if (repeatTime == maxRepeatTime)
            {
                maxRepeatStr = inStr;
                break;
            }
        }
        else
        {
            repeatTime = 1;
            prevStr = inStr;
        }
    }

    if (repeatTime == maxRepeatTime)
    {
        cout << "Word " << maxRepeatStr << " repeated " << maxRepeatTime << " times" << endl;
    }
    else
    {
        cout << "No word repeat twice." << endl;
    }

    return 0;
}
int exercise5_22()
{
    // int sz = 0;
    // while (sz <= 0)
    // {
    //     sz = get_size()
    // }
    return 0;
}

int exercise5_23()
{

    // Please input two ints : 1 0
    // Floating point exception
    int a = 0, b = 0;
    cout << "Please input two ints : ";
    while (cin >> a >> b)
    {
        cout << "dividend divide divisor : " << a / b << endl;
        cout << "Please input two ints : ";
    }
    return 0;
}

int exercise5_24()
{
    //     Please input two ints : 1 0
    // terminate called after throwing an instance of 'std::domain_error'
    //   what():  divisor cannot be zero.
    // Aborted
    int a = 0, b = 0;
    cout << "Please input two ints : ";
    while (cin >> a >> b)
    {
        if (b == 0)
            throw domain_error("divisor cannot be zero.");

        cout << "dividend divide divisor : " << a / b << endl;
        cout << "Please input two ints : ";
    }
    return 0;
}
int exercise5_25()
{
    try
    {
        int a = 0, b = 0;
        cout << "Please input two ints : ";
        while (cin >> a >> b)
        {
            if (b == 0)
                throw domain_error("divisor cannot be zero.");

            cout << "dividend divide divisor : " << a / b << endl;
            cout << "Please input two ints : ";
        }
    }
    catch (domain_error e)
    {
        cout << e.what() << endl;
    }
    
    return 0;
}
