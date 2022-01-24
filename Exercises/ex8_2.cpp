#include <iostream>
#include <vector>

using namespace std;

template <typename T>
int nbOcc(T value, vector<T> array)
{
    int occurences = 0;
    for (size_t i = 0; i < array.size(); ++i)
    {
        if (array[i] == value)
        {
            ++occurences;
        }
    }
    return nbOcc;
}

class Time
{
    string data;
    public:
    Time(string value) : data(value){};
};

int main()
{
    vector<int> numbers = {0, 1, 0};
    vector<Time> times = {Time("07:45"), Time("09:20"), Time("12:00"), Time("21:30")};
    vector<string> names = {"Paul", "Jacques", "Paul", "Jean", "Paul"};

    cout << nbOcc(0, numbers) << endl;
    //cout << nbOcc(Time("12:00"), times) << endl;
    //cout << nbOcc("Paul", names) << endl;
}