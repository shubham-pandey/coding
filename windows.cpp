#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/core.hpp>
#include <iostream>
#include <chrono>   // For time calculation
#include <vector>   // For vector
#include <windows.h> // For key simulation (Windows-specific)

using namespace std;
using namespace cv;

// Function to simulate a key press for pausing/resuming media playback
void simulateKeyPress() {
    // Simulates pressing the spacebar key (key code VK_SPACE)
    INPUT input = {0};
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = VK_SPACE; // Virtual-Key Code for spacebar

    // Press the key
    SendInput(1, &input, sizeof(INPUT));

    // Release the key
    input.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(INPUT));
}

int main() {
    // Load the Haar cascade for face detection
    CascadeClassifier faceCascade;
    if (!faceCascade.load("haarcascade_frontalface_default.xml")) {
        cout << "Error loading face cascade\n";
        return -1;
    }

    // Start video capture from the webcam
    VideoCapture cap(0); // 0 is the default camera
    if (!cap.isOpened()) {
        cout << "Error opening video stream\n";
        return -1;
    }

    // Threshold for minimum face size
    const int faceSizeThreshold = 20000;

    // Timers for face detection and no face detection
    auto lastFaceDetectedTime = chrono::steady_clock::now();
    auto lastSmallFaceTime = chrono::steady_clock::now();
    auto lastNoFaceTime = chrono::steady_clock::now();
    bool faceDetected = false;
    bool mediaPaused = false;
    bool smallFaceDetected = false;

    while (true) {
        Mat frame;
        cap >> frame; // Capture the current frame

        if (frame.empty()) {
            cout << "Error capturing frame\n";
            break;
        }

        // Convert frame to grayscale
        Mat grayFrame;
        cvtColor(frame, grayFrame, COLOR_BGR2GRAY);
        equalizeHist(grayFrame, grayFrame); // Equalize histogram for better detection

        // Detect faces
        vector<Rect> faces;
        faceCascade.detectMultiScale(grayFrame, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));

        if (faces.empty()) {
            if (faceDetected) {
                lastNoFaceTime = chrono::steady_clock::now();
                faceDetected = false;
            }

            auto now = chrono::steady_clock::now();
            auto duration = chrono::duration_cast<chrono::seconds>(now - lastNoFaceTime);

            if (duration.count() >= 3 && !mediaPaused) {
                cout << "Pausing media due to no face detected...\n";
                simulateKeyPress();
                mediaPaused = true;
            }
        } else {
            // A face is detected
            if (!faceDetected) {
                lastFaceDetectedTime = chrono::steady_clock::now();
                faceDetected = true;
            }

            auto now = chrono::steady_clock::now();
            auto duration = chrono::duration_cast<chrono::seconds>(now - lastFaceDetectedTime);

            // Check the size of the first detected face
            Rect face = faces[0];
            int faceSize = face.width * face.height;

            cout << "Detected face size: " << faceSize << "\n";

            if (faceSize < faceSizeThreshold) {
                if (!smallFaceDetected) {
                    lastSmallFaceTime = chrono::steady_clock::now();
                    smallFaceDetected = true;
                }

                auto smallFaceDuration = chrono::duration_cast<chrono::seconds>(now - lastSmallFaceTime);
                if (smallFaceDuration.count() >= 2 && !mediaPaused) {
                    cout << "Pausing media due to small face size detected for 2 seconds...\n";
                    simulateKeyPress();
                    mediaPaused = true;
                }
            } else {
                smallFaceDetected = false; // Reset small face detection timer

                if (duration.count() >= 2 && mediaPaused) {
                    cout << "Resuming media as face is continuously detected with sufficient size...\n";
                    simulateKeyPress();
                    mediaPaused = false;
                }
            }

            // Draw rectangle around the face
            rectangle(frame, face, Scalar(255, 0, 0), 2);
        }

        // Show the frame with detections
        imshow("Face Detection", frame);

        // Break the loop if the user presses 'q'
        if (waitKey(10) == 'q') {
            break;
        }
    }

    cap.release(); // Release the camera
    destroyAllWindows(); // Close all OpenCV windows
    return 0;
}