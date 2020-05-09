//
//  folder.cpp
//  files
//
//  Created by Роберт Артур Меликян on 06/05/2020.
//  Copyright © 2020 Роберт Артур Меликян. All rights reserved.
//

#include <stdio.h>
#include "folder.h"
#include <algorithm>

Folder::Folder(){
    folderName = "";
    sizeInBytes = 0;
    numberOfFiles = 0;
    dateOfCreation = std::time(nullptr);
    dateOfLastChange = std::time(nullptr);
}
Folder::Folder(std::string folderName){
    this->folderName = folderName;
    sizeInBytes = 0;
    numberOfFiles = 0;
    dateOfCreation = std::time(nullptr);
    dateOfLastChange = std::time(nullptr);
}

Folder::Folder(std::string folderName, std::vector<File> files){
    this->folderName = folderName;
    dateOfCreation = std::time(nullptr);
    dateOfLastChange = std::time(nullptr);
    this->files = files;
    numberOfFiles = files.size();
    sizeInBytes = 0;
    for (auto el: files){
        sizeInBytes += el.getSizeInBytes();
    }
}

Folder::~Folder(){}

std::string Folder::getFolderName() const{
    return folderName;
}
int Folder::getSizeInBytes() const{
    return sizeInBytes;
}
int Folder::getNumberOfFiles() const{
    return numberOfFiles;
}
time_t Folder::getDateOfCreating() const{
    return dateOfCreation;
}
time_t Folder::getDateOfLastChange() const{
    return dateOfLastChange;
}

File& Folder::getFile(std::string fileName, std::string extension){
    for (File& el: files){
        if (el.getFileName() == fileName && el.getExtension() == extension){
            return el;
        }
    }
    throw std::runtime_error("No such file: " + fileName + "." + extension);
}

File Folder::getFile(std::string fileName, std::string extension) const{
    for (File el: files){
        if (el.getFileName() == fileName && el.getExtension() == extension){
            return el;
        }
    }
    throw std::runtime_error("No such file: " + fileName + "." + extension);
}

std::vector<File>& Folder::getAllFiles(){
    return files;
}
std::vector<File> Folder::getAllFiles() const{
    return files;
}

void Folder::addFile(File& file){
    if (std::find(files.begin(), files.end(), file) == files.end()){
        file.setBaseFolderName(folderName);
        files.push_back(file);
        numberOfFiles++;
        dateOfLastChange = std::time(nullptr);
        sizeInBytes += file.getSizeInBytes();
    }else{
        throw std::runtime_error("File already exists:" + file.getFileName() + "." + file.getExtension());
    }
}
void Folder::addFiles(std::vector<File> new_files){
    for (auto& el: new_files){
        addFile(el);
    }
    dateOfLastChange = std::time(nullptr);
}

void Folder::changeFile(File& file){
    auto it = std::find(files.begin(), files.end(), file);
    if (it != files.end()){
        sizeInBytes -= (*it).getSizeInBytes();
        (*it).setData(file.getData());
        dateOfLastChange = std::time(nullptr);
        sizeInBytes += (*it).getSizeInBytes();
    }else{
        throw std::runtime_error("No such file: " + file.getFileName() + "." + file.getExtension());
    }
}

void Folder::deleteFile(File& file){
    if (std::find(files.begin(), files.end(), file) != files.end()){
        auto f = std::find(files.begin(), files.end(), file);
        (*f).setBaseFolderName("");
        files.erase(std::remove(files.begin(), files.end(), file));
        numberOfFiles--;
        dateOfLastChange = std::time(nullptr);
        sizeInBytes -= file.getSizeInBytes();
    }else{
        throw std::runtime_error("No such file: " + file.getFileName() + "." + file.getExtension());
    }
}
void Folder::deleteFiles(std::vector<File>& filesToDelete){
    for(auto& el: filesToDelete){
        deleteFile(el);
    }
    dateOfLastChange = std::time(nullptr);
}

void Folder::deleteAllFiles(){
    files.resize(0);
    numberOfFiles = 0;
    sizeInBytes = 0;
    dateOfLastChange = std::time(nullptr);
}

void Folder::moveFile(File& file, Folder& destinationFolder){
    destinationFolder.addFile(file);
    deleteFile(file);
}

void Folder::moveFiles(std::vector<File>& file, Folder& destinationFolder){
    for(auto& el: files){
        destinationFolder.addFile(el);
        deleteFile(el);
    }
}

void Folder::setFolderName(std::string folderName){
    this->folderName =folderName;
    dateOfLastChange = std::time(nullptr);
}

void Folder::mergeFolder(Folder& mergeFolder){
    addFiles(mergeFolder.getAllFiles());
    mergeFolder.deleteAllFiles();
}

Folder Folder::operator +(File& file){
    addFile(file);
    return *this;
}
