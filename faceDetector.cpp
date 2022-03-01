// OpenCV 4.5.3 & MSVC 2022 professional

#include <opencv2/highgui.hpp> // imshow, waitKey
#include <opencv2/imgcodecs.hpp> // imread
#include <opencv2/imgproc.hpp> //rectangle
#include <opencv2/objdetect.hpp> // CasecadeClassifier
#include <vector>

int main() {
	cv::VideoCapture video(0); // index 0 = built-in Camera device
	cv::CascadeClassifier faceDetector("Resources/haarcascade_frontalface_alt.xml"); // Intel License Agreement For Open Source Computer Vision Library

	while (true) {
		cv::Mat img;
		if (!video.read(img)) break;
		std::vector<cv::Rect> faces;
		faceDetector.detectMultiScale(img, faces);
		for (const auto& face : faces) {
			cv::rectangle(img, face, cv::Scalar(0, 0, 255), 2); // Scalar(blue, green, red)
		}
		cv::imshow("Image", img);
		cv::waitKey(1);
	}
}
