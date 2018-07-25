/*
    Daily Programmer #330 [Easy] Surround the circles
    Code by Rahulminy
*/
#include <iostream>
#include <limits>
#include <cstdio>

using namespace std;

class boxCircles
{
private:
public:
    void launch()
    {
        // Turn off c sync
        ios::sync_with_stdio(false);

        int numCircle = 0;
        cout << "Please enter the number of circles: ";

        // Integer input validation, get number of circles.
        while (!(cin >> numCircle))
        {
            cin.clear();
            // Remove every single invalid input till newline
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input" << endl;
        }
        cout << "Number of circles: " << numCircle << endl;

        double arrc[numCircle * 3] = {0};
        double inputC = 0;

        // Enter values for each circle.
        for (int q=0; q < (numCircle * 3); q++)
        {
            cout << "Circle: " << (q/3) + 1 << " Point: " << (q%3) + 1 << endl;
            while (!(cin >> inputC))
            {
                cin.clear();
                // Remove every single invalid input till newline.
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input, try again" << endl;
            }
            arrc[q] = inputC;
        }

        // Arrays and var for loops.
        int arr2_size = sizeof(arrc)/sizeof(double);
        double rectCoords[4] = {0}; // Output var dec.
        double circleCoords[4] = {0};

        // Assume only one circle exists.
        rectCoords[0] = arrc[0] - arrc[2];
        rectCoords[1] = arrc[0] + arrc[2];
        rectCoords[2] = arrc[0+1] - arrc[2];
        rectCoords[3] = arrc[0+1] + arrc[2];

        // Loop through second circle and on to find rectangle coordinates.
        for (int i = 3; i < (arr2_size); i += 3)
        {
            circleCoords[0] = arrc[i] - arrc[i+2];
            circleCoords[1] = arrc[i] + arrc[i+2];
            circleCoords[2] = arrc[i+1] - arrc[i+2];
            circleCoords[3] = arrc[i+1] + arrc[i+2];

            if (circleCoords[0] < rectCoords[0]) rectCoords[0] = circleCoords[0];
            if (circleCoords[1] > rectCoords[1]) rectCoords[1] = circleCoords[1];
            if (circleCoords[2] < rectCoords[2]) rectCoords[2] = circleCoords[2];
            if (circleCoords[3] > rectCoords[3]) rectCoords[3] = circleCoords[3];
        }

        // Re-sync with cstdio just in case and print results.
        ios::sync_with_stdio(true);
        printf("(%.3f, %.3f), (%.3f, %.3f), (%.3f, %.3f), (%.3f, %.3f) \n", rectCoords[0], rectCoords[2], rectCoords[0], rectCoords[3], rectCoords[1], rectCoords[3], rectCoords[1], rectCoords[2]);

    }
};

int main()
{
    int userInput = 0;
    boxCircles obj;

    cout << "\"Box the Circles\" by Rahulminy" << endl;
    cout << "=========" << endl;
    cout << "Instructions: " << endl;
    cout << "- First enter the number of circles you would like to place. (Must be whole number)" << endl;
    cout << "- Next you will be prompted to enter 3 values for every circle." << endl;
    cout << "- These values are the x and y coordinates, and the radius respectively." << endl;
    cout << "- Note: if a radius of 0 is entered, the circle is treated as a point." << endl;
    cout << "- The result returned is the coordinates of the smallest rectangle which holds all the circles." << endl;
    cout << "=========" << endl;
    cout << "You must press ENTER after every input" << endl;
    cout << "=========" << endl;

    cout << "Press 1 to start." << endl;
    while (!(cin >> userInput) || (userInput != 1))
    {
        cin.clear();
        // Remove every single invalid input till newline
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input, enter 1 to start." << endl;
    }

    do
    {
        obj.launch();

        cout << "Input 1 to restart the program, 0 to quit" << endl;
        while (!(cin >> userInput) || (userInput < 0) || (userInput > 1))
        {
            cin.clear();
            // Remove every single invalid input till newline
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input" << endl;
        }
    }
    while (userInput == 1);

    return 0;
}