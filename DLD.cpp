#include <iostream>
#include <vector>
#include <string>

using namespace std;

int variables;
int rows;
int columns;

vector<vector<int>> kmap;

vector<unsigned long long> groups;
vector<int> groupLiterals;

vector<int> bestAnswer;
int bestLiterals = 1000;

int gray(int position)
{
    int grayCode[8] = {0, 1, 3, 2, 6, 7, 5, 4};

    return grayCode[position];
}

int getMinterm(int row, int column)
{
    int rowBits = variables / 2;
    int columnBits = variables - rowBits;

    int rowValue = gray(row);
    int columnValue = gray(column);

    int minterm = (rowValue << columnBits) | columnValue;

    return minterm;
}

int findLiterals(unsigned long long group)
{
    int count = 0;

    for (int bit = 0; bit < variables; bit++)
    {
        bool hasZero = false;
        bool hasOne = false;

        for (int minterm = 0; minterm < (1 << variables); minterm++)
        {
            if (group & (1ULL << minterm))
            {
                int value = (minterm >> (variables - 1 - bit)) & 1;

                if (value == 0)
                    hasZero = true;
                else
                    hasOne = true;
            }
        }

        if (!(hasZero && hasOne))
        {
            count++;
        }
    }

    return count;
}

void findGroups()
{
    groups.clear();
    groupLiterals.clear();

    // Try different group heights
    for (int height = 1; height <= rows; height = height * 2)
    {
        // Try different group widths
        for (int width = 1; width <= columns; width = width * 2)
        {
            // Try every starting row
            for (int startRow = 0; startRow < rows; startRow++)
            {
                // Try every starting column
                for (int startColumn = 0; startColumn < columns; startColumn++)
                {
                    bool valid = true;

                    unsigned long long group = 0;

                    // Check every cell inside the group
                    for (int r = 0; r < height; r++)
                    {
                        for (int c = 0; c < width; c++)
                        {
                            // % allows wrap-around
                            int row = (startRow + r) % rows;
                            int column = (startColumn + c) % columns;

                            // If any cell is 0,
                            // this group is not valid
                            if (kmap[row][column] == 0)
                            {
                                valid = false;
                            }

                            // Find minterm of this cell
                            int minterm = getMinterm(row, column);

                            // Store this minterm in the group
                            group = group | (1ULL << minterm);
                        }
                    }

                    // Store only valid groups
                    if (valid)
                    {
                        bool alreadyExists = false;

                        // Check whether this group
                        // was already found
                        for (int i = 0; i < (int)groups.size(); i++)
                        {
                            if (groups[i] == group)
                            {
                                alreadyExists = true;
                                break;
                            }
                        }

                        if (!alreadyExists)
                        {
                            groups.push_back(group);

                            groupLiterals.push_back(
                                findLiterals(group)
                            );
                        }
                    }
                }
            }
        }
    }
}

string getExpression(unsigned long long group)
{
    string answer = "";

    char variableNames[5] = {'A', 'B', 'C', 'D', 'E'};

    for (int bit = 0; bit < variables; bit++)
    {
        bool hasZero = false;
        bool hasOne = false;

        for (int minterm = 0; minterm < (1 << variables); minterm++)
        {
            if (group & (1ULL << minterm))
            {
                int value =
                    (minterm >> (variables - 1 - bit)) & 1;

                if (value == 0)
                    hasZero = true;
                else
                    hasOne = true;
            }
        }

        // Variable is always 0
        if (hasZero && !hasOne)
        {
            answer += variableNames[bit];
            answer += "'";
        }

        // Variable is always 1
        else if (!hasZero && hasOne)
        {
            answer += variableNames[bit];
        }
    }

    // No variable remains
    if (answer == "")
    {
        answer = "1";
    }

    return answer;
}

unsigned long long getAllOnes()
{
    unsigned long long allOnes = 0;

    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            if (kmap[row][column] == 1)
            {
                int minterm = getMinterm(row, column);

                allOnes =
                    allOnes | (1ULL << minterm);
            }
        }
    }

    return allOnes;
}


void findBestAnswer(
    unsigned long long covered,
    vector<int> selected,
    int totalLiterals
)
{
    unsigned long long allOnes = getAllOnes();


    // If every 1 is covered
    if (covered == allOnes)
    {
        if (totalLiterals < bestLiterals)
        {
            bestLiterals = totalLiterals;

            bestAnswer = selected;
        }

        return;
    }


    // Stop if this answer is already worse
    if (totalLiterals >= bestLiterals)
    {
        return;
    }


    // Find first uncovered 1
    int uncoveredMinterm = -1;

    for (int minterm = 0;
         minterm < (1 << variables);
         minterm++)
    {
        if (allOnes & (1ULL << minterm))
        {
            if (!(covered & (1ULL << minterm)))
            {
                uncoveredMinterm = minterm;

                break;
            }
        }
    }


    // Try every group
    for (int i = 0;
         i < (int)groups.size();
         i++)
    {
        // Does this group cover
        // the uncovered 1?
        if (groups[i] & (1ULL << uncoveredMinterm))
        {
            bool alreadySelected = false;


            // Check whether group is
            // already selected
            for (int j = 0;
                 j < (int)selected.size();
                 j++)
            {
                if (selected[j] == i)
                {
                    alreadySelected = true;

                    break;
                }
            }


            if (alreadySelected)
            {
                continue;
            }


            // Select this group
            selected.push_back(i);


            // Add the newly covered 1s
            unsigned long long newCovered =
                covered | groups[i];


            findBestAnswer(
                newCovered,
                selected,
                totalLiterals + groupLiterals[i]
            );


            selected.pop_back();
        }
    }
}


void printAnswer()
{
    cout << "\nMinimized Boolean Expression:\n";

    for (int i = 0;
         i < (int)bestAnswer.size();
         i++)
    {
        if (i > 0)
        {
            cout << " + ";
        }

        cout << getExpression(
            groups[bestAnswer[i]]
        );
    }

    cout << endl;
}


int main()
{
    cout << "Enter number of variables (2, 3, 4 or 5): ";

    cin >> variables;


    // Find K-map size
    if (variables == 2)
    {
        rows = 2;
        columns = 2;
    }
    else if (variables == 3)
    {
        rows = 2;
        columns = 4;
    }
    else if (variables == 4)
    {
        rows = 4;
        columns = 4;
    }
    else if (variables == 5)
    {
        rows = 4;
        columns = 8;
    }
    else
    {
        cout << "Only 2, 3, 4 and 5 variables are allowed.\n";

        return 0;
    }

    kmap.resize(rows);

    for (int i = 0; i < rows; i++)
    {
        kmap[i].resize(columns);
    }


    cout << "\nEnter the K-map values:\n";

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cin >> kmap[i][j];
        }
    }

    bool allZero = true;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (kmap[i][j] == 1)
            {
                allZero = false;
            }
        }
    }


    if (allZero)
    {
        cout << "\nMinimized Boolean Expression:\n";
        cout << "0\n";

        return 0;
    }

    bool allOne = true;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (kmap[i][j] == 0)
            {
                allOne = false;
            }
        }
    }


    if (allOne)
    {
        cout << "\nMinimized Boolean Expression:\n";
        cout << "1\n";

        return 0;
    }

    findGroups();

    vector<int> selected;

    findBestAnswer(
        0,
        selected,
        0
    );

    printAnswer();
    return 0;
}