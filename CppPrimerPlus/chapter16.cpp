#include "chapter16.h"

unsigned char toUpper(unsigned char a);
int stringToUpper(string &s)
{
    // Use std::transform with std::toupper to convert to uppercase
    std::transform(s.begin(), s.end(), s.begin(), toUpper);

    std::cout << s << std::endl; // Output: HELLO, WORLD!

    return 0;
}

unsigned char toUpper(unsigned char a)
{
    return std::toupper(a);
}

unsigned char toLower(unsigned char a);
int stringToLower(string &s)
{
    // Use std::transform with std::toupper to convert to lowercase
    std::transform(s.begin(), s.end(), s.begin(), toLower);

    std::cout << s << std::endl;

    return 0;
}

unsigned char toLower(unsigned char a)
{
    return std::tolower(a);
}

bool isPalindrome(string &s);
int chapter16_1()
{
    string str = "Hello, World!";
    string str1 = "HellolleH";

    stringToLower(str);
    stringToLower(str1);

    auto lamda = [](string &s)
    { return isPalindrome(s) ? "yes" : "no"; };

    cout << "is " << str << "a Palindrome ?" << lamda(str) << endl;
    cout << "is " << str1 << " a Palindrome ?" << lamda(str1) << endl;

    return 0;
}

bool isPalindrome(string &s)
{
    string palindrome;

    for (int i = 0; i < s.size(); i++)
    {
        if (std::isalpha(s[i]))
        {
            palindrome.push_back(std::tolower(s[i]));
        }
    }
    for (int i = 0, j = palindrome.size() - 1; i < j; i++, j--)
    {
        if (palindrome[i] != palindrome[j])
        {
            return false;
        }
    }

    return true;
}

int chapter16_2()
{

    cout << "Enter a string: ";
    string s;
    getline(cin, s);

    auto lamda = [](string &s)
    { return isPalindrome(s) ? "yes" : "no"; };

    cout << "is " << s << "a Palindrome ? " << lamda(s) << endl;

    return 0;
}

int chapter16_3()
{
    const int NUM = 26;
    
	std::ifstream myfile("/home/tian/projects/helloworld/CppPrimerPlus/chapter16_3.txt");
	if (!myfile.good())
	{
		std::cerr << "Unable to open /home/tian/projects/helloworld/CppPrimerPlus/chapter16_3.txt" << endl;
		exit(EXIT_FAILURE);
	}

	std::vector<string> wordlist;
	string word;
	while (myfile >> word)
		wordlist.push_back(word);

	myfile.close();
	long num = wordlist.size();

    std::srand(std::time(0));
    char play;
    cout << "Will you play a word game? <y/n> ";
    cin >> play;
    play = tolower(play);
    while (play == 'y')
    {
        string target = wordlist[std::rand() % num];
        int length = target.length();
        string attempt(length, '-');
        string badchars;
        int guesses = 6;
        cout << "Guess my secret word. It has " << length
            << " letters, and you guess\n"
            << "one letter at a time. You get " << guesses
            << " wrong guesses.\n";
        cout << "Your word: " << attempt << endl;
        while (guesses > 0 && attempt != target)
        {
            char letter;
            cout << "Guess a letter: ";
            cin >> letter;
            if (badchars.find(letter) != string::npos
                || attempt.find(letter) != string::npos)
            {
                cout << "You already guessed that. Try again.\n";
                    continue;
            }
            int loc = target.find(letter);
            if (loc == string::npos)
            {
                cout << "Oh, bad guess!\n";
                --guesses;
                badchars += letter; // add to string
            }
            else
            {
                cout << "Good guess!\n";
                attempt[loc]=letter;
                // check if letter appears again
                loc = target.find(letter, loc + 1);
                while (loc != string::npos)
                {
                    attempt[loc]=letter;
                    loc = target.find(letter, loc + 1);
                }
           }
            cout << "Your word: " << attempt << endl;
            if (attempt != target)
            {
                if (badchars.length() > 0)
                    cout << "Bad choices: " << badchars << endl;
                cout << guesses << " bad guesses left\n";
            }
        }
        if (guesses > 0)
            cout << "That's right!\n";
        else
            cout << "Sorry, the word is " << target << ".\n";

        cout << "Will you play another? <y/n> ";
        cin >> play;
        play = tolower(play);
    }

    cout << "Bye\n";

    return 0; 
}

int reduce(long ar[], int n);
int chapter16_4()
{
    int size = 15;
    cout << "Enter up to " << size << " numbers (quit to quit):";

    long num;
	int i = 0;
	long ar[size];
	while (cin >> num && i < size)
	{
		ar[i++] = num;
	}

    if (0 == i)
	{
		cout << "No values were entered, quit." << endl;
		return 1;
	}

    cout << "You entered ";
	for (int j = 0; j < i; j++)
		cout << ar[j] << " ";
	cout << endl;

    cout << "Here's your sorted array, without duplicates: \n";
	int j = reduce(ar, i);
	for (int k = 0; k < j; k++)
		cout << ar[k] << " ";
	cout << endl;

    return 0;
}

int reduce(long ar[], int n)
{
    std::vector<long> var;
	for (int i = 0; i < n; i++)
		var.push_back(ar[i]);

	sort(var.begin(), var.end());
	std::vector<long>::iterator newEnd = unique(var.begin(), var.end());
	var.erase(newEnd, var.end());
	std::vector<long>::iterator iv = var.begin();
	for (int i = 0; iv != var.end(); iv++, i++)
		ar[i] = *iv;
	
	return var.size();
}


template <typename T>
int reduceTemplate(T ar[], int n)
{
    std::vector<T> var(n);
    std::copy(ar, ar+n, var.begin());

	sort(var.begin(), var.end());
	typename std::vector<T>::iterator newEnd = unique(var.begin(), var.end());
	var.erase(newEnd, var.end());
	typename std::vector<T>::iterator iv = var.begin();
	for (int i = 0; iv != var.end(); iv++, i++)
		ar[i] = *iv;
	
	return var.size();
}

int chapter16_5()
{
    // 1 long part
    // int size = 15;
    // cout << "Enter up to " << size << " numbers (quit to quit):";

    // long num;
	// int i = 0;
	// long ar[size];
	// while (cin >> num && i < size)
	// {
	// 	ar[i++] = num;
	// }

    // if (0 == i)
	// {
	// 	cout << "No values were entered, quit." << endl;
	// 	return 1;
	// }

    // cout << "You entered ";
	// for (int j = 0; j < i; j++)
	// 	cout << ar[j] << " ";
	// cout << endl;

    // cout << "Here's your sorted array, without duplicates: \n";
	// int j = reduceTemplate(ar, i);
	// for (int k = 0; k < j; k++)
	// 	cout << ar[k] << " ";
	// cout << endl;
    // return 0;

    // 2 string part
    std::string sar[5] = {"aa", "bb", "aa", "cc" , "bb"};
    int values = 5;

    int j = reduceTemplate(sar, values);

	for (int k = 0; k < j; k++)
		cout << sar[k] << " ";
	cout << endl;

    return 0;
}

// customer method

// when is the time at which the customer arrives
// the arrival time is set to when and the processing
// time set to a random value in the range 1 - 3
void Customer2::set(long when)
{
    processtime = std::rand() % 3 + 1;
    arrive = when; 
}

const int MIN_PER_HR = 60;
const int QUEUE_SIZE = 10;
bool newcustomer(double x); // is there a new customer?
int chapter16_6()
{ 

    // setting things up
    std::srand(std::time(0));    //  random initializing of rand()

    // cout << "Case Study: Bank of Heather Automatic Teller\n";
    // cout << "Enter maximum size of queue: ";
    int qs = 10;
    //cin >> qs;
    std::queue<Customer2> line;         // line queue holds up to qs people

    // cout << "Enter the number of simulation hours: ";
    int hours = 100;              //  hours of simulation
    //cin >> hours;
    // simulation will run 1 cycle per minute
    long cyclelimit = MIN_PER_HR * hours; // # of cycles

    // cout << "Enter the average number of customers per hour: ";
    double perhour;         //  average # of arrival per hour
    //cin >> perhour;
    double min_per_cust;    //  average time between arrivals


    for (int i = 60; i > 0; i--)
    {
        Customer2 temp; 
        // 清空上一轮模拟中残留的队列数据
        while (!line.empty())
        {
            line.pop();
        }

        //  new customer data
        long turnaways = 0;     //  turned away by full queue
        long customers = 0;     //  joined the queue
        long served = 0;        //  served during the simulation
        long sum_line1 = 0;      //  cumulative line length
        int wait_time1 = 0;      //  time until autoteller is free
        long line_wait = 0;     //  cumulative time in line

        perhour = i;    
        min_per_cust = MIN_PER_HR / perhour;
        // running the simulation
        for (int cycle = 0; cycle < cyclelimit; cycle++)
        {
            if (newcustomer(min_per_cust))  // have newcomer
            {
                if (line.size() == QUEUE_SIZE)
                    turnaways++;
                else
                {
                    customers++;
                    temp.set(cycle);    // cycle = time of arrival
                    line.push(temp); // add newcomer to line
                }
            }
            if (wait_time1 <= 0 && !line.empty())
            {
                line.push(temp);      // attend next customer
                wait_time1 = temp.ptime(); // for wait_time1 minutes
                line_wait += cycle - temp.when();
                served++;
            }
            if (wait_time1 > 0)
                wait_time1--;
            sum_line1 += line.size();
        }

        // reporting results
        if (customers > 0)
        {
            cout << "customers accepted: " << customers << endl;
            cout << "  customers served: " << served << endl;
            cout << "         turnaways: " << turnaways << endl;
            cout << "average queue size: ";
            cout.precision(2);
            cout.setf(ios_base::fixed, ios_base::floatfield);
            cout << (double) sum_line1 / cyclelimit << endl;
            cout << " average wait time: "
                << (double)line_wait / served<< " minutes\n";

            if (( (double)line_wait / served) < 1)
            {
                cout << "Average person per hour is " << perhour << ", then average wait time is less than 1 minute." << endl;
                break;
            }
        }
        else
            cout << "No customers!\n";
        cout << "Done!\n";  
    }

    // cin.get();
    // cin.get();
    return 0;

} 

//  x = average time, in minutes, between customers
//  return value is true if customer shows up this minute
bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1); 
}

std::vector<int> Lotto(int spots, int selected);
int chapter16_7()
{
    cout << "Enter the number of spots on the lottery card: ";
	int spots;
	cin >> spots;
	cout << "Enter the number of spots to be selected: ";
	int selected;
	cin >> selected;

	std::vector<int> result = Lotto(spots, selected);
	cout << "Your lucky numbers are: ";
	for (unsigned int i = 0;  i < result.size(); i++)
		cout << result[i] << " ";
	cout << endl;

	return 0;
}

std::vector<int> Lotto(int spots, int selected)
{
	if (spots < selected)
	{
		cout << "The second argument of Lotto() must be less than ";
		cout << "the first argument." << endl;
		cout << "Program abort" << endl;
		exit(EXIT_FAILURE);
	}

	if (spots < 0 || selected < 0)
	{
		cout << "Both arguments of Lotto() must be positive integers";
		cout << endl;
		cout << "Program abort" << endl;
		exit(EXIT_FAILURE);		
	}

	std::vector<int> v;
	for (int i = 1; i < spots + 1; i++)
		v.push_back(i);

	random_shuffle(v.begin(), v.end());
	std::vector<int> picks;
	for (int i = 0; i < selected; i++)
		picks.push_back(v[i]);

	return picks;
}

int chapter16_8()
{
	cout << "Mat: please enter strings (quit to quit):";
	string value;
    std::vector<string> matFriend;
    std::vector<string> patFriend;
	while (cin >> value && value != "quit" )
    {
		matFriend.push_back(value);
    }
    
    for (const string& str : matFriend) {
        cout << str << " ";
    }
    cin.get();
    cin.get();
	cout << "\n Pat: please enter strings (quit to quit):";
    while (cin >> value && value != "quit" )
    {
		patFriend.push_back(value);
    }

    for (const string& str : patFriend) {
        cout << str << " ";
    }
    cout << "\n joint Mat and Pet's friends: \n";
    std::copy(matFriend.begin(), matFriend.end(), std::back_insert_iterator< std::vector<string> >(patFriend));

    for (const string& str : patFriend) {
        cout << str << " ";
    }

    cout << "\n sort and unique: \n"; 
	sort(patFriend.begin(), patFriend.end());
	std::vector<string>::iterator newEnd = unique(patFriend.begin(), patFriend.end());
	patFriend.erase(newEnd, patFriend.end());

    for (const string& str : patFriend) {
        cout << str << " ";
    }

    return 0;
}

int chapter16_9()
{    
    const int size = 1000000; // Adjust the size as needed
    std::vector<int> vi0(size);

    for (int i = 0; i < size; ++i) {
        vi0[i] = std::rand()%1000000;
    }

    // Create vi and li and initialize them with vi0
    std::vector<int> vi(vi0);
    std::list<int> li(vi0.begin(), vi0.end());

    // Time the sorting of vi using std::sort
    clock_t start_time = clock();
    std::sort(vi.begin(), vi.end());
    clock_t end_time = clock();
    double vi_sort_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

    // Time the sorting of li using list's sort method
    start_time = clock();
    li.sort();
    end_time = clock();
    double li_sort_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

    // Reset li to unsorted contents of vi0
    std::copy(vi0.begin(), vi0.end(), li.begin());

    // Time the combined operation of copying, sorting, and copying back
    start_time = clock();
    std::copy(li.begin(), li.end(), vi.begin());
    std::sort(vi.begin(), vi.end());
    std::copy(vi.begin(), vi.end(), li.begin());
    end_time = clock();
    double combined_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

    // Output the timing results
    std::cout << "Time to sort vi using std::sort: " << vi_sort_time << " seconds" << std::endl;
    std::cout << "Time to sort li using list::sort: " << li_sort_time << " seconds" << std::endl;
    std::cout << "Time for combined operation: " << combined_time << " seconds" << std::endl;

    return 0; 
}


bool operator<(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2);
bool worseThan(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2);
bool expensiveThan(const std::shared_ptr<Review>r1, const std::shared_ptr<Review> r2);
bool FillReview(std::shared_ptr<Review> rr);
void ShowReview(const std::shared_ptr<Review> rr);
int chapter16_10()
{

    std::vector< std::shared_ptr<Review> > books;
    while (true)
    {
        std::shared_ptr<Review> sharedInt(new Review);
        if (!FillReview(sharedInt))
        {
            break;
        }

        books.push_back(sharedInt);
    }

    if (books.size() > 0)
    {
        cout << "Thank you. You entered the following "
             << books.size() << " ratings:\n"
              << "Rating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);

        sort(books.begin(), books.end());
        cout << "Sorted by title:\nRating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);

        sort(books.begin(), books.end(), worseThan);
        cout << "Sorted by rating:\nRating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);

        sort(books.begin(), books.end(), expensiveThan);
        cout << "Sorted by price:\nRating\tBook\n";
        for_each(books.begin(), books.end(), ShowReview);
    }
    else
        cout << "No entries. ";
    cout << "Bye.\n";
    // cin.get();
    return 0;
}

bool operator<(const std::shared_ptr<Review> r1, const std::shared_ptr<Review> r2)
{
    if (r1->title < r2->title)
        return true;
    else if (r1->title == r2->title && r1->rating < r2->rating)
        return true;
    else
        return false;
}

bool worseThan(const std::shared_ptr<Review>r1, const std::shared_ptr<Review> r2)
{
    if (r1->rating < r2->rating)
        return true;
    else
        return false;
}

bool expensiveThan(const std::shared_ptr<Review>r1, const std::shared_ptr<Review> r2)
{
    if (r1->price < r2->price)
        return true;
    else
        return false;
}

bool FillReview(std::shared_ptr<Review> rr)
{
    std::cout << "Enter book title (quit to quit): ";
    std::getline(std::cin, rr->title);
    if (rr->title == "quit")
        return false;
    std::cout << "Enter book rating: ";
    std::cin >> rr->rating;
    if (!std::cin)
        return false;
    std::cout << "Enter book price: ";
    std::cin >> rr->price;
    if (!std::cin)
        return false;
    // get rid of rest of input line
    while (std::cin.get() != '\n')
        continue;
    return true;
}

void ShowReview(const std::shared_ptr<Review> rr)
{
    std::cout << rr->rating << "\t" << rr->title << "\t" << rr->price << std::endl; 
}