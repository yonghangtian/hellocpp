#include "chapter7.h"

const char * p_snames[Seasons] = {"Spring", "Summer", "Fall", "Winter"};

// 编写一个程序，不断要求用户输入两个数，直到其中一个是0。
// 对于每两个数，使用如下公式计算调和平均数并返回给main函数：
// 调和平均数 = 2.0 * x * y / ( x + y )
// cpp 负数的除法中余数符号是由被除数决定的,在除法算式中，除号后面的数叫做除数，除号前面的数叫做被除数
int chapter7_1()
{
    int x, y;

    while (cin >> x >> y) 
    {
        if ((x == 0) || (y == 0)) 
        {
            break;
        }

        int a = 2.0 * x * y;
        int b = x + y;

        int result =  a / b;
        int test = a % b;
        cout << "a = " << a << ", b = " << b << endl;
        cout << "a/b = " << result << endl;
        cout << "a%b = " << test << endl;
    }

    return 0;
}

//要求用户输入最多10个高尔夫成绩(设为float型)，并将其存储在一个数组中。
// 程序允许用户提早结束输入，并在一行上显示所有成绩，然后报告平均成绩。
// 请用三个数组处理函数分别进行输入、显示和计算平均成绩
void chapter7_2_input(float * inputs, int len) 
{
    int i;
    for (i = 0 ; i < len; i ++) {
        if (!(cin >> inputs[i])){
            inputs[i] = -1.0f;
            break;
        }

        if (inputs[i] < 0.0f) {
            inputs[i] = -1.0f;
            break;
        }
    }
}

void chapter7_2_show(const float * inputs, int len)
{
    int i;
    for (i = 0 ; i < len; i ++) 
    {
        if (inputs[i] > 0.0f){
            cout << inputs[i] << "; ";
        }
        else {
            break;
        }
    }
}

float chapter7_2_avg(const float * inputs, int len)
{
    int i;
    float sum = 0.0f, avg;
    for (i = 0 ; i < len; i ++) 
    {
        if (inputs[i] > 0.0f){
            sum += inputs[i];
        } else {
            break;
        }
    }
    if (i > 0) {
        avg = sum / i;
    }
    return avg;
}

int chapter7_2()
{
    float inputs[10] = {0.0f};
    int len = 10;
    chapter7_2_input(inputs, len);
    chapter7_2_show(inputs, len);
    cout << endl << chapter7_2_avg(inputs, len) << endl;

    return 0;
}

// 使用 box这个struct
// 1, 编写一个函数，按值传递box结构，并显示每个成员的值；
// 2，编写一个函数，传递box结构的地址，并将volume成员设置为其他三维长度的乘积；
// 3， 编写一个使用这两个函数的简单程序
void chapter7_3_show(box abc)
{
    cout << "Height is " <<abc.height << "; Length is " << abc.length << "; Width is " << abc.width << endl;
    cout << "Maker is " << abc.maker << "; Volume is " << abc.volume << endl;
}

void chapter7_3_volume(box * abc)
{
    if (abc->height > 0.0f && abc->length > 0.0f && abc->width > 0.0f)
    {
        abc->volume = abc->height * abc->length * abc->width;
    } else {
        cout << "Invalid height or length or width for box!!!" << endl;
    }
}

int chapter7_3()
{
    box abc;
    abc.height = 1.0f;
    abc.width = 2.0f;
    abc.length = 3.0f;
    // struct 已经初始化了，所以要用字符串拷贝的方式
    strcpy(abc.maker, "Made in China");

    chapter7_3_volume(&abc);
    chapter7_3_show(abc);

    return 0;
}

// 计算从1-47中选取5个数字和1-27中选取1个数字，且上述6个数字与中奖数字完全一致的概率
// the following function calculates the probability of picking picks
// numbers correctly from numbers choices
// unsigned 指 unsigned int
long double probability(unsigned numbers, unsigned picks, unsigned specialnums, unsigned specialpicks)
{
    long double result = 1.0;  // here come some local variables
    long double n;
    unsigned p;

    for (n = numbers, p = picks; p > 0; n--, p--)
        result = result * n / p ; 
    
    for (n = specialnums, p = specialpicks; p > 0; n--, p--)
        result = result * n / p ; 
    
    return result;
}

int chapter7_4()
{
    double total, choices, specialnums, specialpicks;
    cout << "Enter the total number of choices on the game card and\n"
            "the number of picks allowed and the total number of special choices and the number of picks:\n";
    while ((cin >> total >> choices >> specialnums >> specialpicks) && choices <= total && specialpicks <= specialnums)
    {
        cout << "You have one chance in ";
        cout << probability(total, choices, specialnums, specialpicks);      // compute the odds
        cout << " of winning.\n";
        cout << "Next four numbers (q to quit): ";
    }
    cout << "bye\n";
    
    return 0;
}


// 定义一个递归函数，接受一个整数参数，并反馈该参数的阶乘
// 0! = 1; if n > 0; n! = n * (n-1)!
int chapter7_5_resurs(unsigned int n) 
{
    if ( n == 0) {
        return 1;
    }

    return n * chapter7_5_resurs(n-1);
}

int chapter7_5()
{
    int n;

    while(cin >> n) 
    {
        cout << chapter7_5_resurs(n) << endl;
    }

    return 0;
}

// Fill_array() 将一个double数组的名称和长度作为参数。
// 它提示用户输入double值，并将这些值存储到数组中。当数组被填满或用户输入了非数字时，输入将停止，并返回实际输入了多少个数字
// Show_array() 将一个double数组的名称和长度作为参数，并显示该数组的内容
// Reverse_array() 将一个double数组的名称和长度作为参数，并将存储在数组中的值的顺序反转
int fill_array(double * inputs, int length) 
{
    cout << "Please input at most " << length << " value of type double: " << endl;

    int i;
    for (i = 0; i < length; i ++) {
        if (!(cin >> inputs[i])){
            return i;
        }
    }
    
    // -1 表示数组被填满了
    return -1;
}

void show_array(const double * inputs, int length)
{
    for (int i = 0; i < length; i ++) {
        cout << inputs[i] << ", ";
    }

    cout << endl;
} 

void reverse_array(double * inputs, int length)
{
    double temp;

    for (int i = 0; i < length/2; i ++) {
        temp = inputs[length - 1 - i];
        inputs[length - 1 - i] = inputs[i];
        inputs[i] = temp;
    }
}

int chapter7_6()
{

    int length = 10;
    double arr[length] = {0.0};

    int real_len = fill_array(arr, length);

    if (real_len < 0) {
        real_len = length;
    } 

    show_array(arr, real_len);
    reverse_array(arr, real_len);
    show_array(arr, real_len);

    return 0;
}

// 7-7 重写Chapter7中arrfun3.cpp中的3个数组处理函数，使之使用两个指针参数来表示区间
// fill_array函数不返回实际读取了多少个数字，而是返回一个指针，将该指针指向最后被填充的位置
// 其他的函数可以将该指针作为第二个参数，以标识数据结尾
double * fill_array_7(double * ar, int limit)
{
    double * p_end = ar;
    double temp;
    int i;
    for (i = 0; i < limit; i++)
    {
        cout << "Enter value #" << (i + 1) << ": ";
        cin >> temp;
        if (!cin)    // bad input
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input; input process terminated.\n";
            break;
        }
        else if (temp < 0)     // signal to terminate
            break;
        ar[i] = temp;
    }

    p_end = ar + i - 1; // calculate p_end

    return p_end;
}

// the following function can use, but not alter,
// the array whose address is ar
void show_array(const double * ar, const double * p_end)
{
    
    for (int i = 0; (ar + i) <= p_end; i++)
    {
        cout << "Property #" << (i + 1) << ": $";
        cout << ar[i] << endl;
    }
}

// multiplies each element of ar[] by r
void revalue(double r, double * ar, const double * p_end)
{
    for (int i = 0; (ar + i) <= p_end; i++)
        ar[i] *= r;
}

int chapter7_7() 
{
    double properties[Max];
    double * p_end = fill_array_7(properties, Max);
    show_array(properties, p_end);
    if (p_end > properties)
    {
        cout << "Enter revaluation factor: ";
        double factor;
        while (!(cin >> factor))    // bad input
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
           cout << "Bad input; Please enter a number: ";
        }
        revalue(factor, properties, p_end);
        show_array(properties, p_end);
    }
    cout << "Done.\n";
    // cin.get();
    // cin.get();
    return 0;
}

// 在不使用array类的情况下完成程序清单7.15(arrobj.cpp)的工作。编写两个这样的版本:
// a. 使用 const char * 数组存储表示季度名称的字符串，并使用double数组存储开支
// b. 使用 const char * 数组存储表示季度名称的字符串，并使用一个结构，该结构只有一个成员：一个用于存储开支的double数组。
// 这种设计与使用array类的基本设计类似

void fill_a(double * pa)
{
    for (int i = 0; i < Seasons; i++)
    {
        std::cout << "Enter " << p_snames[i] << " expenses: ";
        std::cin >> pa[i];
    }
}

void show_a(double * da)
{
    double total = 0.0;
    std::cout << "\nEXPENSES\n";
    for (int i = 0; i < Seasons; i++)
    {
        std::cout << p_snames[i] << ": $" << da[i] << '\n';
        total += da[i];
    }
    std::cout << "Total: $" << total << '\n';
}

int chapter7_8_a() 
{
    
    double expenses[Seasons];
    fill_a(expenses);
    show_a(expenses);
    // std::cin.get();
    // std::cin.get();
    return 0;
}

void fill_b(season_expense * expenses)
{
    for (int i = 0; i < Seasons; i++)
    {
        std::cout << "Enter " << p_snames[i] << " expenses: ";
        std::cin >> expenses->s_expenses[i];
    }
}

void show_b(const season_expense * expenses)
{
    double total = 0.0;
    std::cout << "\nEXPENSES\n";
    for (int i = 0; i < Seasons; i++)
    {
        std::cout << p_snames[i] << ": $" << expenses->s_expenses[i] << '\n';
        total += expenses->s_expenses[i];
    }
    std::cout << "Total: $" << total << '\n';
}

int chapter7_8_b()
{
    cout << "Using struct!" << endl;
    season_expense expenses;
    fill_b(&expenses);
    show_b(&expenses);
    return 0;
}

// 录入并展示学生的信息
// 学生属于某个班级
// getinfo需要持续输入，直到数组填满或者在学生姓名中输入一个空行，程序返回该数组中具体的学生数
int getinfo(student pa[], int n) {
    
    int i = 0;

    for (i = 0; i < n; i ++) {
        cout << "Please input student " << (i+1) << "'s fullname(char string): " << endl;
        cin.get(pa[i].fullname, SLEN-1);
        cin.get();

        // break when student fullname is empty.
        if (strlen(pa[i].fullname) == 0) {
            break;
        }
        
        
        cout << "Please input student " << (i+1) << "'s hobby(char string): " << endl;
        cin.get(pa[i].hobby, SLEN-1);
        cin.get();

        cout << "Please input student " << (i+1) << "'s ooplevel(int type): " << endl;
        cin >> pa[i].ooplevel;
        cin.get();
    }
    
    return i;
}

// 展示某个学生的信息 
void display1(student st) {
    cout << "Student Name is " << st.fullname << ", hobby is " << st.hobby << ", ooplevel is " << st.ooplevel << "." << endl;
}

// 展示某个学生的信息
void display2(const student * ps) {
    cout << "Student Name is " << ps->fullname << ", hobby is " << ps->hobby << ", ooplevel is " << ps->ooplevel << "." << endl;
}

// 展示所有学生的信息
void display3(const student pa[], int n) {
    for (int i = 0; i < n; i ++) {
        display2(pa + i);
    }
}

int chapter7_9()
{
    cout << "Enter the class size : " ;
    int  class_size;
    cin >> class_size;
    while (cin.get() != '\n') {
        continue;
    }

    // allocate memory for this array
    student * ptr_stu = new student[class_size];

    int entered = getinfo(ptr_stu, class_size);

    for (int i = 0; i < entered; i ++) {
        display1(ptr_stu[i]);
        display2(&ptr_stu[i]);
    }
    display3(ptr_stu, entered);
    // free the memory
    delete [] ptr_stu; 

    cout << "Done!";
    return 0;
}

// 函数指针
// 设计一个名为calculate的函数，它接受两个double值和一个指向函数的指针，而被指向的函数接受两个double参数，并返回一个double值。
// calculate()函数的类型也是double，并返回被指向的函数使用calculate()的两个double参数计算得来的值。例如，add()函数的定义如下

double add (double x, double y) 
{
    return x + y;
}

double subtract (double x, double y) 
{
    return x - y;
}

double multiply (double x, double y) 
{
    return x * y;
}

double divide (double x, double y) 
{
    return x / y;
}

double calculate (double x, double y, double (*p_method)(double, double)) 
{
    double temp;
    temp = (*p_method)(x, y);
    return temp;
}

int chapter7_10() 
{
    double x, y;
    cout << "Please input two double number: " << endl;
    cin >> x >> y;

    // 下面的声明意义是：声明一个包含四个函数指针的数组
    double (*pf[4])(double, double) = {add, subtract, multiply, divide};

    for(int i = 0; i < 4; i++) {

        double result = calculate(x, y, pf[i]);
        switch (i)
        {
        case 0:
            cout << "Add: " << result << endl;         
            break;
        case 1:
            cout << "Subtract: " << result << endl;
            break;
        case 2:
            cout << "Multiply: " << result << endl;
            break;
        case 3:
            cout << "Divide: " << result << endl;
            break;
        default:
            break;
        }
    }

    double q1 = calculate(x, y, add);
    
    double q2 = calculate(x, y, subtract);
    
    double q3 = calculate(x, y, multiply);
    
    double q4 = calculate(x, y, divide);
    
    
    return 0;
}