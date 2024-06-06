#include<iostream>
#include<fstream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include "HashVotes.hpp"
#include "hashfile.hpp"
#include "caeser.hpp"


int main()
{
    std::string surname;
    HashVotes test;
    test.enrolled("C:\\Labs\\Lab08\\votes.txt");
    std::cin >> surname;
    while(surname != "end")
    {
        test.unenrolled(surname);
        std::cin >> surname;
    }
    test.print_voters();
    std::cout << test.get_duplicates() << "\n";
    std::cout << test.get_size() << "\n";
    //для второй задачи буду юзать тот же класс, да нейминг получается пострадал, но смысла писать по сути тот же класс не имеет
    HashVotes test2;
    test2["mefedron"] = "100";
    std::cout << test2["mefedron"] << "\n"; 
    //Согласен, реализовано криво, но как будто саму суть задания выполнил
    // Задание 3
    std::string img_path = "C:\\Labs\\Lab08\\test.jpg";
    std::string chg_img_path = "C:\\Labs\\Lab08\\changed_test.jpg";
    std::string hash1, hash2;
    cv::Mat img, img_chg;
    std::ofstream logs;
    bool is_equal;
    logs.open("..\\logs.txt", std::ios_base::app);
    logs << "-------------------------------------------------------------------\n";
    img = cv::imread(img_path);
    cv::imshow("start", img);
    hash1 =sha256_file(img_path);
    logs << "Hash of start \"" << img_path  << "\" image: " << hash1<< "\n";
    caeser(img, 0);
    imwrite(chg_img_path, img);
    hash2= sha256_file(chg_img_path);
    logs << "Hash of changed \"" << chg_img_path  << "\" image: "<< hash2<< "\n";
    is_equal = (hash1 == hash2);

    if(is_equal) logs << "Hash is equal.\n";
    else logs << "Hash is NOT equal.\n";

    img_chg =cv::imread(chg_img_path);
    logs << "-------------------------------------------------------------------\n";
    cv::imshow("final", img_chg);
    cv::waitKey(10000);
    cv::destroyWindow("123");
    cv::destroyWindow("321");


}