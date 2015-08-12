#include <opencv2/core/core.hpp>
#include <iostream>

#include "application.hpp"

using namespace std;
using namespace cv;

int main(int argc, const char **argv)
{
    Application app;
    Application::Parameters params;

    if (app.parseArguments(argc, argv, params) != 0)
    {
        cout << "practice2 <image_name>" << endl;
        cout << "<image_name> - image name for filtering" << endl;
        return 1;
    }

    Mat src;
    if (app.getFrame(params.imgFileName, src) != 0)
    {
        cout << "Error: \'src\' image is null or empty!" << endl;
        return 2;
    }

    Mat dst;
    if (app.processFrame(src, dst) != 0)
    {
        cout << "Error: Filtering failed!" << endl;
        return 3;
    }

    const std::string caption = "OpenCV Sample";
    char key = 0;
    while(key != 27) // Esc
        key = app.show(caption, src, dst);

	return 0;
}
