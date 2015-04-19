#ifndef FILEIO_H_INCLUDED
#define FILEIO_H_INCLUDED



#endif // FILEIO_H_INCLUDED

bool scoredHigh=false;
int finalScore=0;
int highScore;

//Function to get previous high score
void getHighScore()
{

    // Open file for reading
    ifstream ifile("high.txt");
    if(!ifile.is_open())
    {
        cerr << "Input file couldn't be opened." << endl;

    }

    // cin >> score;
    ifile >> highScore;

    // Clear the error flags
    ifile.close();

}

//Function to check high score
void checkHighScore()
{
    if(highScore<finalScore)
    {

        // Open file for writing
        ofstream ofile("high.txt");
        if(!ofile.is_open())
        {
            cerr << "File Ouput Stream failed to open/create file." << endl;

        }

        // cout << str << endl;
        ofile << finalScore << endl;

        //To display message afterwards
        scoredHigh=true;


        // Check if the ouput was successful or not.
        if(!ofile.good())
        {
            cerr << "Error occured, while writing to output file" << endl;

        }

        //Close the output file
        ofile.close();
    }

}


