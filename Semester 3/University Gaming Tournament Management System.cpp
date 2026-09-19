#include<iostream>
using namespace std;

void displayScores(int scores[], int size)
{
    if (size == 0)
    {
        cout << "The tournament has no active players"<<endl;
        return;
    }
    cout << "Active Scores " << size << "/10:"<<endl;
    for (int i = 0; i < size; i++)
    {
        cout << "[" << i << "]:" << scores[i] << "  ";
    }
    cout << endl;
}

void insert(int aa[],int &size)
{
    int pos,scr;
    if (size >= 10)
    {
        cout << "Error: Tournament is at full capacity...!!!<<endl";
        return;
    }
    cout << "Enter insertion Position from 0 to "<<size<<endl;
    cin>>pos;
    if (pos < 0 || pos > size)
    {
        cout << "Invalid position!"<<endl;
        return;
    }
    cout << "Enter new Score"<<endl;
    cin>>scr;

    for(int i=size ; i>pos ; i--)
    {
        aa[i]=aa[i-1];
    }
    aa[pos]=scr;
    size++;
}

void deletee(int aa[],int &size)
{
    if (size == 0)
    {
        cout << "Error: No players to delete!"<<endl;
        return;
    }

    int pos;
    cout << "Enter position to delete 0 to " << size - 1 <<" : ";
    cin >> pos;

    if (pos < 0 || pos >= size)
    {
        cout << "Invalid position!"<<endl;
        return;
    }
    for (int i = pos; i < size - 1; i++)
    {
        aa[i] = aa[i + 1];
    }

    size--;
    cout << "Player removed successfully!"<<endl;
}

void updateScore(int scores[], int size)
{
    if (size == 0)
    {
        cout << "No players available to update"<<endl;
        return;
    }
    int pos,US;
    cout << "Enter position to update 0 to " << size - 1 <<" : ";
    cin >> pos;
    if (pos < 0 || pos >= size)
    {
        cout << "Invalid position!"<<endl;
        return;
    }

    cout << "Enter new score (0 - 100): ";
    cin >> US;

    if (US < 0 || US > 100)
    {
        cout << "Invalid score!"<<endl;
        return;
    }

    scores[pos] = US;
}

void searchScore(int scores[], int size)
{
    if (size == 0)
    {
        cout << "Array is empty!"<<endl;
        return;
    }

    int target;
    cout << "Enter score to search: ";
    cin >> target;

    bool found = false;

    for (int i = 0; i < size; i++)
    {
        if (scores[i] == target)
        {
            cout << "Score " << target << " found at index " << i << endl;
            found = true;
        }
    }

    if (found != true)
    {
        cout << "Score does not exist in the array"<<endl;
    }
}

int findHighest(int scores[], int size)
{
    if (size == 0)
    {
        cout << "Array is empty!"<<endl;
        return 0;
    }

    int maxScore = scores[0];
    for (int i = 1; i < size; i++)
    {
        if (scores[i] > maxScore)
        {
            maxScore = scores[i];
        }
    }
    return maxScore;
}

int findLowest(int scores[], int size)
{
    if (size == 0)
    {
        cout << "Array is empty!"<<endl;
        return 0;
    }

    int minScore = scores[0];
    for (int i = 1; i < size; i++)
    {
        if (scores[i] < minScore)
        {
            minScore = scores[i];
        }
    }
    return minScore;
}

int calculateAverage(int scores[], int size)
{
    if (size == 0)
    {
        cout << "Array is empty!"<<endl;
        return 0;
    }

    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum =sum + scores[i];
    }
    return sum / size;
}

void sortScores(int scores[], int size)
{
    if (size == 0)
    {
        cout << "Array is empty!"<<endl;
        return;
    }

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (scores[j] > scores[j + 1])
            {
                int temp = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = temp;
            }
        }
    }
}

void reverseScores(int scores[], int size)
{
    if (size == 0)
    {
        cout << "Array is empty!"<<endl;
        return;
    }

    int start = 0;
    int end = size - 1;

    while (start < end)
    {
        int temp = scores[start];
        scores[start] = scores[end];
        scores[end] = temp;

        start++;
        end--;
    }
}

void findDuplicates(int scores[], int size)
{
    if (size == 0) return;

    bool found = false;
    for (int i = 0; i < size - 1; i++)
    {
        if (scores[i] == scores[i + 1])
        {
            cout << "Duplicate score found: " << scores[i] << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No duplicate scores found" << endl;
    }
}

void displayStatistics(int scores[], int size)
{
    cout << "Active Players    : " << size << endl;
    cout << "Available Capacity: " << (10 - size) << endl;

    if (size > 0)
    {
        cout << "Highest Score     : " << findHighest(scores, size) << endl;
        cout << "Lowest Score      : " << findLowest(scores, size) << endl;
        cout << "Average Score     : " << calculateAverage(scores, size) << endl;
    }
    else
    {
        cout << "No active statistics to report Array is empty"<<endl;
    }
}

void complexity() {
    cout << "Display: O(n)"<<endl;
    cout << "Insertion: O(n)"<<endl;
    cout << "Deletion: O(n)"<<endl;
    cout << "Update: O(1)"<<endl;
    cout << "Search: O(n)"<<endl;
    cout << "Highest/Lowest: O(n)"<<endl;
    cout << "Average: O(n)"<<endl;
    cout << "Sort: O(n^2)"<<endl;
    cout << "Reverse: O(n)"<<endl;
    cout << "Duplicates: O(n^2)"<<endl;
}

int main()
{
    int scores[10] = {78, 92, 65, 88, 71}, ocpt = 5, choice = 0;

    while (choice != 13) {

        cout << endl << "GAMING TOURNAMENT MANAGEMENT SYSTEM:" << endl;
        cout << " Current Players: " << ocpt << endl;
        cout << "1. Display All Scores" << endl;
        cout << "2. Add New Player Score" << endl;
        cout << "3. Remove Player Score" << endl;
        cout << "4. Update Player Score" << endl;
        cout << "5. Search for a Score" << endl;
        cout << "6. Find Highest Score" << endl;
        cout << "7. Find Lowest Score" << endl;
        cout << "8. Calculate Statistics (Min, Max, Avg)" << endl;
        cout << "9. Sort Scores" << endl;
        cout << "10. Reverse Scores Array" << endl;
        cout << "11. Identify Duplicate Scores" << endl;
        cout << "12. Display Operation Complexities" << endl;
        cout << "13. Exit" << endl<<endl;
        cout << "Enter your choice (1-13): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << " Displaying all current scores..." << endl;
                displayScores(scores, ocpt);
                break;

            case 2:
                cout << " Adding a new player score..." << endl;
                insert(scores, ocpt);
                break;

            case 3:
                cout << " Removing a player score..." << endl;
                deletee(scores, ocpt);
                break;

            case 4:
                cout << " Updating a player score..." << endl;
                updateScore(scores, ocpt);
                break;

            case 5:
                cout << " Searching for a score..." << endl;
                searchScore(scores, ocpt);
                break;

            case 6:
                cout << " Finding highest score..." << endl;
                cout << "Highest Score: " << findHighest(scores, ocpt) << endl;
                break;

            case 7:
                cout << " Finding lowest score..." << endl;
                cout << "Lowest Score: " << findLowest(scores, ocpt) << endl;
                break;

            case 8:
                cout << " Calculating tournament statistics..." << endl;
                displayStatistics(scores, ocpt);
                break;

            case 9:
                cout << " Sorting the scores..." << endl;
                sortScores(scores, ocpt);
                break;

            case 10:
                cout << " Reversing the array layout..." << endl;
                reverseScores(scores, ocpt);
                break;

            case 11:
                cout << " Identifying duplicate scores..." << endl;
                findDuplicates(scores, ocpt);
                break;

            case 12:
                cout << " Displaying operation complexities..." << endl;
                complexity();
                break;

            case 13:
                cout << "Exiting system. Goodbye!" << endl;
                break;

            default:
                cout << "[Error] Choice out of range. Try again." << endl;
                break;
        }
    }

    return 0;
}

