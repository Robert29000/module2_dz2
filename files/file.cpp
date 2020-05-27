//
//  file.cpp
//  files
//
//  Created by Роберт Артур Меликян on 06/05/2020.
//  Copyright © 2020 Роберт Артур Меликян. All rights reserved.
//

#include <stdio.h>
#include "file.h"

File::File(){
    fileName = "";
    baseFolderName = "";
    extension = "";
    data = "";
    dateOfCreation = std::time(nullptr);
    dateOfLastChange = std::time(nullptr);
    sizeInBytes = 0;
}

File::File(std::string fileName){
    this->fileName = fileName;
    baseFolderName = "";
    extension = "";
    data = "";
    dateOfCreation = std::time(nullptr);
    dateOfLastChange = std::time(nullptr);
    sizeInBytes = 0;
}

File::File(std::string fileName, std::string extension){
    this->fileName = fileName;
    baseFolderName = "";
    this->extension = extension;
    data = "";
    dateOfCreation = std::time(nullptr);
    dateOfLastChange = std::time(nullptr);
    sizeInBytes = 0;
}

File::File(std::string fileName, std::string extension, std::string data){
    this->fileName = fileName;
    baseFolderName = "";
    this->extension = extension;
    this->data = data;
    dateOfCreation = std::time(nullptr);
    dateOfLastChange = std::time(nullptr);
    sizeInBytes = data.size();
}

File::~File(){}

std::string File::getFileName() const{
    return fileName;
}
std::string File::getExtension() const{
    return extension;
}
std::string File::getData() const{
    return data;
}

time_t File::getDateOfCreation() const{
    return dateOfCreation;
}

int File::getSizeInBytes() const{
    return sizeInBytes;
}

void File::getAllParametres(std::string& fileName, std::string& folderName, std::string& extension, std::string& data, time_t& dateOfCreation, time_t& dateOfLastChange, int& sizeInBytes) const{
    fileName = this->fileName;
    folderName = this->baseFolderName;
    extension = this->extension;
    data = this->data;
    dateOfCreation = this->dateOfCreation;
    dateOfLastChange = this->dateOfLastChange;
    sizeInBytes = this->sizeInBytes;
}

void File::setFileName(std::string name){
    this->fileName = name;
    dateOfLastChange = std::time(nullptr);
}
void File::setExtension(std::string extension){
    this->extension = extension;
    dateOfLastChange = std::time(nullptr);
}

void File::setBaseFolderName(std::string folderName){
    this->baseFolderName = folderName;
}

void File::deleteData(){
    this->data = "";
    dateOfLastChange = std::time(nullptr);
    sizeInBytes = data.size();
}
void File::addData(std::string data){
    this->data.append(" " + data);
    dateOfLastChange = std::time(nullptr);
    sizeInBytes = data.size();
}
void File::setData(std::string data){
    this->data = data;
    dateOfLastChange = std::time(nullptr);
    sizeInBytes = data.size();
}

File& File::operator =(const File& f2){
    fileName = f2.fileName;
    baseFolderName = f2.baseFolderName;
    extension = f2.extension;
    data = f2.data;
    dateOfCreation = f2.dateOfCreation;
    dateOfLastChange = f2.dateOfLastChange;
    sizeInBytes = f2.sizeInBytes;
    return *this;
}

std::ostream& operator <<(std::ostream& out, const File& f){
    out << "File: " << f.fileName << "." << f.extension << std::endl;
    out << "Date of creation: " << std::ctime(&f.dateOfCreation) << " Last change on: " << std::ctime(&f.dateOfLastChange) << std::endl;
    out << "Data: " << std::endl;
    out << f.data << std::endl;
    out << "Total size in bytes: " << f.sizeInBytes << std::endl;
    return out;
}

bool File::operator ==(const File& f2){
    return f2.fileName == fileName && extension == f2.extension;
}
