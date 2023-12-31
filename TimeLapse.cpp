#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <thread>
#include <chrono>

using namespace cv;


int main(int argc, char** argv)
{

    int deviceId = 0;
    int captureWidth = 640;
    int captureHeight = 480;
    int numPhotos = 0;
    int maxLoops = 500;



   std::string errString;


    VideoCapture videoCapture(deviceId);

    if (!videoCapture.isOpened()) {

        // Log
        errString = "Open video capture failed on device id: " + std::to_string(deviceId) + "\n";
        return -1;

    }

    if (!videoCapture.set(cv::CAP_PROP_FRAME_WIDTH, captureWidth)) {

        // Log
        errString = "Failed to set frame width: " + std::to_string(captureWidth) + "\n";
    }

    if (!videoCapture.set(cv::CAP_PROP_FRAME_HEIGHT, captureHeight)) {

        // Log
        errString = "Failed to set frame height: " + std::to_string(captureHeight) + "\n";
    }

    // The captured image and its grey conversion
    Mat image, grey;

	//set up the camera loop to take photos
	
	while(numPhotos < maxLoops)
	{

	        bool result = videoCapture.read(image);

		if(result)
		{
		

		//write the timestamp on the image
		const auto now = std::chrono::system_clock::now();
	    	const std::time_t t_c = std::chrono::system_clock::to_time_t(now);
		
		putText(image,std::ctime(&t_c),Point(20, 20), FONT_HERSHEY_SIMPLEX,0.5 ,Scalar(255, 0, 0));


		//Write the image to a file
		imwrite("photo" + std::to_string(numPhotos) + ".jpg",image);
		
		std::this_thread::sleep_for(std::chrono::milliseconds(300000));

		numPhotos++;
		}	
	}


}

