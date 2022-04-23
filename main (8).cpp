// Program: photoshop program
// Purpose: Demonstrate use of bmplip for handling
//          bmp colored and grayscale images
//          Program load a gray image and store in another file
// Date:    22 April 2022
// Version: 2.0
//author1 : Rania Khaled 20210129
//author2 : Habiba Magdy Anwar 20210122
//author3 : Malak Walid Mohamed 20210404

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE],q1[SIZE/2][SIZE/2],q2[SIZE/2][SIZE/2],q3[SIZE/2][SIZE/2],q4[SIZE/2][SIZE/2],image2[SIZE][SIZE];

void loadImage ();
void saveImage ();
void black_and_white();
void invert();
void merge();
void fliping();
void rotate();
void darkenligten();
void EnlargeImage();
void makeQ1();
void makeQ2();
void dublicatepixels1();
void dublicatepixels2();
void makeQ3();
void makeQ4();
void dublicatepixels3();
void dublicatepixels4();
void shuffleImage();
void shrink();
void blur();
void mirror_image();
void detect_edges();

int main()
{
    int user_choice;
    cout<<"Ahlan ya user ya habebe what do you want to do today??"<<endl<<"1-Black&White Filter"<<endl<<"2-Invert Filter"<<endl<<"3-Merge Filter"<<endl<<"4-Flip Image"<<endl<<"5-Rotate Image"<<endl<<"6- Darken and Lighten Image"<<endl<<"7-Detect Image Edges \n8-Enlarge image \n9-Shrink Image \n10-Mirror Image \n11-Shuffle Image \n12-Blur Image \n0-Exit\n";
    cin>>user_choice;
    loadImage();
    if(user_choice==1)
        black_and_white();
    else if(user_choice==2)
        invert();
    else if(user_choice==3)
        merge();
    else if(user_choice==4)
        fliping();
    else if (user_choice == 5)
        rotate();
    else if (user_choice == 6)
        darkenligten();
    else if (user_choice==7)
        detect_edges();
    else if (user_choice==8)
        EnlargeImage();
    else if (user_choice==9)
        shrink();
    else if (user_choice==10)
        mirror_image();
    else if (user_choice==11)
        shuffleImage();
    else if (user_choice==12)
        blur();

    saveImage();
    return 0;
}

//_________________________________________
void loadImage () {
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
    readGSBMP(imageFileName, image2);
}

//_________________________________________
void saveImage () {
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}

void black_and_white(){
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {

            if (image[i][j] > 127)
                image[i][j] = 255;
            else
                image[i][j] = 0;
        }
    }
}
void invert() {
    //loop on each pixel 2d array
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
        //take the negative of the pixels value 
            image[i][j] = 255 - image[i][j];



        }
    }
}
void merge(){
    unsigned char image2[SIZE][SIZE];
    char image2FileName[100];
    //get the second image file name
    cout << "Enter the second image file name: ";
    cin >> image2FileName;
    strcat (image2FileName, ".bmp");
    readGSBMP(image2FileName, image2);
    for(int i = 0; i<SIZE ; i++){
        for(int j = 0; j<SIZE ; j++){
            //get the avg of both images
            image2[i][j] = image2[i][j]/2;
            image[i][j] = image[i][j]/2;
            //merging the two images together
            image[i][j]+=image2[i][j];
        }
    }
}
void fliping_vertically() {
    for (int i = 0; i < (SIZE / 2); i++) {
        for (int j = 0; j < SIZE; j++) {
            int temp = image[i][j];
            image[i][j] = image[255 - i][j];
            image[255 - i][j] = temp;

        }
    }
}
void fliping_horizontally(){
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < (SIZE/2); j++) {
            int temp = image[i][j];
            image[i][j] = image[i][255-j];
            image[i][255-j] = temp;

        }

    }

}
void fliping(){
    int choice;
    cout<<"enter 1 for fliping vertically and 2 for fliping horizontally:"<<endl;
    cin>>choice;
    if (choice==1){
        fliping_vertically();}

    else if (choice ==2) {
        fliping_horizontally();}
    else
        cout<<"invalid input ";
}
void rotate() {
    int choice2;
    //take the user choice to rotate 
    cout<<"which degree?? \n 1-90 \n 2-180 \n 3-270 ";
    cin>>choice2;
    if (choice2==2)
    {
        for (int i=0;i<SIZE;i++)
        {
            for (int j=1+i;j<SIZE;j++)
            {
                //rotate the image 180 degree
                swap(image[i][j],image[255-i][255-j]);



            }
        }
    }
    else if (choice2==1)
    {
        //rotate the image 90 degree
        for(int i=0;i<SIZE;i++)
        {
            for (int j=i;j<SIZE;j++)
            {
                
                swap(image[i][j],image[j][i]);




            }
        }
        for(int i=0;i<SIZE;i++)
        {
            for (int j=0;j<SIZE/2;j++)
            {

                swap(image[i][j],image[i][SIZE-j-1]);


            }
        }

    }
    else if (choice2==3)
    {
        //rotate the image 180 degree
        for(int i=0;i<SIZE;i++)
        {
            for (int j=i;j<SIZE;j++)
            {
                swap(image[i][j],image[j][i]);

            }
        }
        //rotate the image 90 degree
        for(int i=0;i<SIZE;i++)
        {
            for (int j=0;j<SIZE/2;j++)
            {


                swap(image[i][j],image[i][SIZE-j-1]);


            }
        }
        for (int i=0;i<SIZE;i++)
        {
            for (int j=1+i;j<SIZE;j++)
            {

                swap(image[i][j],image[255-i][255-j]);


            }
        }
    }
}
void darkenligten () {
    //taking the user choice
    cout << "1.Lighhten \n" << "2.Darken" << endl;
    int n;
    cin >> n;
    for(int i = 0; i<SIZE ; i++){
        for(int j = 0; j<SIZE ; j++){
            //making the picture ligter in a specefic range
            if(n ==1)
                if(image[i][j]>=200)
                    continue;
                else
                    image[i][j]+=50;
                //making the picture darker in a specefic range

            else if (n==2)
                if(image[i][j]<=70)
                    continue;
                else
                    image[i][j]-=60;
        }
    }
}
void detect_edges(){
    long avg = 0;
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j< SIZE; j++){
            avg += image[i][j];
        }
    }
    avg /= (SIZE * SIZE);
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j< SIZE; j++){
            if ( ( image[i][j] < avg ) and ( image[i][j+1] < avg ) ){
                while ( image[i][j+4] < avg){
                    if (image[i+1][j]<avg){
                        image[i][j+2]=255;
                        j+=1;
                    }
                    else{
                        j+=1;
                    }
                }
            }
            if (image[i][j]>avg){
                image[i][j] = 255;
            }
        }
    }
}

void shrink(){
    int n;
    //creating a new image
    unsigned char image2[SIZE][SIZE];
    //taking the user's input
    cout << "1-shrink to 1/2 \n2-shrink to 1/3 \n3-shrink to 1/4" << endl;
    cin >> n;
    //shrinking to the size the user chose
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if(n==1){
                //putting the pixels in the new image
                image[i/2][j/2]=image[i][j];
                image[i][j]=0;
                image2[i][j]=image[i/2][j/2];}
            else if(n==2){
                image[i/3][j/3]=image[i][j];
                image[i][j]=0;
                image2[i][j]=image[i/3][j/3];}
            else if(n==3){
                image[i/4][j/4]=image[i][j];
                image[i][j]=0;
                image2[i][j]=image[i/4][j/4];}

        }
    }
}
void mirror_image(){
    int input;
    cout<<"enter the direction of reflection\n1)Right\n2)left\n3)lower\n4)upper<<endl";
    cin>>input;
    if(input==1){
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++) {
                image[i][j] = image[i][SIZE - j];


            }
        }

    }
    if(input==2) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][255-j] = image[i][j];


            }
        }
    }

    if(input==3) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j] = image[SIZE - i][j];
            }

        }


    }
    if(input==4) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[SIZE-i][j] = image[i][j];
            }

        }


    }
}
void EnlargeImage(){
    int choice3;
    //take the user choice on which quarter he wants to enlarge
    cout<<"which Quarter?\n 1-First Quarter\n 2-Second Quarter\n 3-Third Quarter\n 4-Forth Quarter"<<endl;
    cin>>choice3;
    if (choice3==1)
    {
        //call the quarter and duplicate functions
        makeQ1();
        dublicatepixels1();
    }
    if (choice3==2)
    {
        //call the quarter and duplicate functions
        makeQ2();
        dublicatepixels2();
    }
    if(choice3==3)
    {
        //call the quarter and duplicate functions
        makeQ3();
        dublicatepixels3();
    }
    if(choice3==4)
    {
        //call the quarter and duplicate functions
        makeQ4();
        dublicatepixels4();
    }
}
void makeQ1()
{
    //take the first quarter and save it as a new image
    for (int i=0;i<SIZE/2;i++)
    {
        for(int j=0;j<SIZE/2;j++)
        {
            q1[i][j]=image[i][j];
        }
    }
}
void makeQ2()
{
    //take the second quarter and save it as a new image
    for (int i=0;i<128;i++)
    {
        for (int j=0,col=127;j<128;col++,j++)
        {
            q2[i][j]=image[i][col];
        }
    }
}
void makeQ3()
{
    //take the third quarter and save it as a new image
    for (int i=0,row=127;i<128;row++,i++)
    {
        for (int j=0;j<128;j++)
        {
            q3[i][j]=image[row][j];
        }
    }
}
void makeQ4()
{
    //take the forth quarter and save it as a new image
    for (int i=0,row=127;i<128;row++,i++)
    {
        for (int j=0,col=127;j<128;col++,j++)
        {
            q4[i][j]=image[row][col];
        }
    }

}
void dublicatepixels1()
{
    //take the first quarter and enlarge it by duplicating its pixels 4 times
    for (int x=0,i=0;i<SIZE;x++,i+=2)
    {
        for(int y=0,j=0;j<SIZE;y++,j+=2)
        {
            image[i][j]=q1[x][y];
            image[i][j+1]=q1[x][y];
            image[i+1][j]=q1[x][y];
            image[i+1][j+1]=q1[x][y];
        }
    }
}
void dublicatepixels2()
{
    //take the second quarter and enlarge it by duplicating its pixels 4 times
    for (int x=0,i=0;i<SIZE;x++,i+=2)
    {
        for(int y=0,j=0;j<SIZE;y++,j+=2)
        {
            image[i][j]=q2[x][y];
            image[i][j+1]=q2[x][y];
            image[i+1][j]=q2[x][y];
            image[i+1][j+1]=q2[x][y];
        }
    }
}
void dublicatepixels3()
{
    //take the third quarter and enlarge it by duplicating its pixels 4 times
    for (int x=0,i=0;i<SIZE;x++,i+=2)
    {
        for(int y=0,j=0;j<SIZE;y++,j+=2)
        {
            image[i][j]=q3[x][y];
            image[i][j+1]=q3[x][y];
            image[i+1][j]=q3[x][y];
            image[i+1][j+1]=q3[x][y];
        }
    }
}
void dublicatepixels4()
{
    //take the forth quarter and enlarge it by duplicating its pixels 4 times
    for (int x=0,i=0;i<SIZE;x++,i+=2)
    {
        for(int y=0,j=0;j<SIZE;y++,j+=2)
        {
            image[i][j]=q4[x][y];
            image[i][j+1]=q4[x][y];
            image[i+1][j]=q4[x][y];
            image[i+1][j+1]=q4[x][y];
        }
    }
}
void shuffleImage()
{
    //will save the image twice and take the order the user wants his pic to be
    int Quarter1,Quarter2,Quarter3,Quarter4;
    //take the user order
    cout<<"please enter first Quarter"<<endl;
    cin>>Quarter1;
    cout<<"please enter second quarter"<<endl;
    cin>>Quarter2;
    cout<<"please enter third Quarter"<<endl;
    cin>>Quarter3;
    cout<<"please enter forth Quarter"<<endl;
    cin>>Quarter4;
    for (int i=0,row=127;i<128;row++,i++)
    {
        for (int j=0,col=127;j<128;col++,j++)
        {
            //take the user choice and save it in sequence in the original image
            if (Quarter1==1)
            {
                image[i][j]=image2[i][j];
            }
            if (Quarter1==2)
            {
                image[i][j]=image2[i][col];
            }
            if (Quarter1==3)
            {
                image[i][j]=image2[row][j];
            }
            if (Quarter1==4)
            {
                image[i][j]=image2[row][col];
            }
            if (Quarter2==1)
            {
                image[i][col]=image2[i][j];
            }
            if (Quarter2==2)
            {
                image[i][col]=image2[i][col];
            }
            if (Quarter2==3)
            {
                image[i][col]=image2[row][j];
            }
            if (Quarter2==4)
            {
                image[i][col]=image2[row][col];
            }

            if (Quarter3==1)
            {
                image[row][j]=image2[i][j];
            }
            if (Quarter3==2)
            {
                image[row][j]=image2[i][col];
            }
            if (Quarter3==3)
            {
                image[row][j]=image2[row][j];
            }
            if (Quarter3==4)
            {
                image[row][j]=image2[row][col];
            }
            if (Quarter4==1)
            {
                image[row][col]=image2[i][j];
            }
            if (Quarter4==2)
            {
                image[row][col]=image2[i][col];
            }
            if (Quarter4==3)
            {
                image[row][col]=image2[row][j];
            }
            if (Quarter4==4)
            {
                image[row][col]=image2[row][col];
            }

        }

    }

}
void blur() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            //fiding the avg of the pixels around each pixel
            image[i][j] = (image[i][j] + image[i][j + 1] + image[i][j - 1] + image[i + 1][j] + image[i - 1][j] +
                        image[i - 1][j - 1] + image[i - 1][j + 1] + image[i + 1][j - 1] + image[i + 1][j + 1]) / 9;
        }
    }

}