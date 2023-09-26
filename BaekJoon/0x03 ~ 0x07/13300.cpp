#include <iostream>

using namespace std;

int man[7] = {0};
int woman[7] = {0};

int main()
{
    int people;
    int max;
    bool gender;
    int grade;
    int room = 0;
    int needRoom;
    bool plusRoom = 0;

    cin >> people;
    cin >> max;

    for (int i = 0; i < people; i++)
    {
        cin >> gender;
        cin >> grade;
        if (gender)
        {
            man[grade] += 1;
        }
        else
        {
            woman[grade] += 1;
        }
    }

    for (int i = 1; i < 7; i++)
    {
        if (man[i] % max > 0)
        {
            plusRoom = 1;

            needRoom = man[i] / max + 1;
            room += needRoom;
        }
        else
        {
            needRoom = man[i] / max;
            room += needRoom;
        }

        if (woman[i] % max > 0)
        {
            plusRoom = 1;

            needRoom = woman[i] / max + 1;
            room += needRoom;
        }
        else
        {
            needRoom = woman[i] / max;
            room += needRoom;
        }
    }

    cout << room;
}