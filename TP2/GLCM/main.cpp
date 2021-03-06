#include<iostream>
#include<opencv2/highgui/highgui.hpp>
#include<cmath>
using namespace std;
using namespace cv;





void glcm(Mat &img, const int &msize);

int main()
{

    Mat img=imread("344.jpeg",CV_LOAD_IMAGE_COLOR);            //input image

    if(img.empty())
    {
        cout<<"no image";
        return 0;
    }

    glcm(img, 16);
    namedWindow("Image",CV_WINDOW_AUTOSIZE);
    imshow("Image",img);
    waitKey(0);
    return 0;

}



void glcm(Mat &img, const int &msize )
{
    cout << "The size of the GLCM " <<msize<<endl;

    float energy=0, contrast=0, homogenity=0;

    int row=img.rows,col=img.cols;

    Mat gl=Mat::zeros(msize,msize,CV_32FC1);

    //creating glcm matrix with msize levels,radius=1 and in the horizontal direction
int q,t;
    for (q = 0; q < row; q++)
        for (t = 0; t < col -1; t++)
        {
            int v0=(int)( (double)msize * (uchar)img.at<uchar>(q,t) )/256;
            int v1=(int)( (double)msize * (uchar)img.at<uchar>(q,t+1) )/256;

            gl.at<float>(v0, v1)++;
        }


    // normalizing glcm matrix for parameter determination

         gl= gl+gl.t();
         gl=gl/sum(gl)[0];
         cout << gl.t();

    // calculate mean and standard deviation using opencv function meanStdDev



    // calculate GLCM properties

    for(int i=0;i<msize;i++)
        for(int j=0;j<msize;j++)
        {


        }
    /*

    cout<<"\n\n";


    cout<<"moyenne=\t\t"<<mean0(0)<<endl;

    cout<<"standard deviation=\t"<<stdv(0)<<endl;

    cout<<"energy=\t\t\t"<<energy<<endl;

    cout<<"contrast=\t\t"<<contrast<<endl;

    cout<<"homogenity=\t\t"<<homogenity<<endl;


    cout<<"\n\n";
    */
}
