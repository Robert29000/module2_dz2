
#include <string>
#include <ctime>
#include <vector>
#include "file.h"

#ifndef folder_h
#define folder_h

class Folder{
    std::string folderName;
    int sizeInBytes;
    int numberOfFiles;
    time_t dateOfCreation;
    time_t dateOfLastChange;
    std::vector<File> files;
public:
    Folder();
    Folder(std::string folderName);
    Folder(std::string folderName, std::vector<File> files);
    ~Folder();
    std::string getFolderName() const;
    int getSizeInBytes() const;
    int getNumberOfFiles() const;
    time_t getDateOfCreating() const;
    time_t getDateOfLastChange() const;
    File getFile(std::string fileName, std::string extension) const;
    File& getFile(std::string fileName, std::string extension);
    std::vector<File>& getAllFiles();
    std::vector<File> getAllFiles() const;
    void addFile(File& file);
    void addFiles(std::vector<File> new_files);
    void changeFile(File& file);
    void deleteFile(File& file);
    void deleteFiles(std::vector<File>& filesToDelete);
    void deleteAllFiles();
    void moveFile(File& file, Folder& destinationFolder);
    void moveFiles(std::vector<File>& file, Folder& destinationFolder);
    void setFolderName(std::string folderName);
    void mergeFolder(Folder& mergeFolder);
    Folder operator +(File& file);
};

#endif /* folder_h */
