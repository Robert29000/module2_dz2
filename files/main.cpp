//
//  main.cpp
//  files
//
//  Created by Роберт Артур Меликян on 05/05/2020.
//  Copyright © 2020 Роберт Артур Меликян. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <algorithm>
#include "file.h"
#include "folder.h"

int main(int argc, const char * argv[]) {
    Folder folder("base_folder");
    File f("");
    File& currentFile = f;
    for (std::string line; getline(std::cin, line); ){
        std::istringstream is(line);
        std::string command;
        is >> command;
        if (command == "Help"){
            std::cout << "Available commads:" << std::endl;
            std::cout << "Add_New_File <Name> <Extension>" << "; " << "Get_File_By_Name_And_Extension <Name> <Extension>" << std::endl;
            std::cout << "Edit_Current_File <Name> <Extension> <Data>" << "; " << "Delete_File_By_Name_And_Extension <Name> <Extension>" << std::endl;
            std::cout << "Sort_Files_In_Folder_By_Name" << "; " << "Sort_Files_In_Folder_By_Extension" << std::endl;
            std::cout << "Sort_Files_In_Folder_By_Creation_Date" << std::endl;
            std::cout << "Print_All_Files" << std::endl;
        } else if (command == "Add_New_File"){
            std::string name,extension;
            is >> name >> extension;
            File newFile(name, extension);
            folder.addFile(newFile);
        } else if (command == "Get_File_By_Name_And_Extension"){
            std::string name,extension;
            is >> name >> extension;
            currentFile = folder.getFile(name, extension);
        } else if (command == "Edit_Current_File"){
            std::string name, extension, data;
            std::cin >> name >> extension;
            getline(is, data);
        } else if (command == "Delete_File_By_Name_And_Extension"){
            std::string name, extension;
            std::cin >> name >> extension;
            File fileToDelete(name, extension);
            folder.deleteFile(fileToDelete);
        } else if (command == "Sort_Files_In_Folder_By_Name"){
            std::vector<File>& files = folder.getAllFiles();
            std::sort(files.begin(), files.end(), [](const File& f1, const File& f2){
                return f1.getFileName() < f2.getFileName();
            });
        } else if (command == "Sort_Files_In_Folder_By_Extension"){
            std::vector<File>& files = folder.getAllFiles();
            std::sort(files.begin(), files.end(), [](const File& f1, const File& f2){
                return f1.getExtension() < f2.getExtension();
            });
        } else if (command == "Sort_Files_In_Folder_By_Creation_Date"){
            std::vector<File>& files = folder.getAllFiles();
            std::sort(files.begin(), files.end(), [](const File& f1, const File& f2){
                return f1.getDateOfCreation() < f2.getDateOfCreation();
            });
        } else if (command == "Print_All_Files"){
            std::vector<File> files = folder.getAllFiles();
            for (auto file : files){
                std::cout << file << " ";
            }
            std::cout << std::endl;
        } else {
            std::cout << "Command not supported" << std::endl;
        }
    }
    return 0;
}
