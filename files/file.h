
#include <string>
#include <ctime>
#include <ostream>

#ifndef file_h
#define file_h

class File{
    std::string fileName;
    std::string baseFolderName;
    std::string extension;
    std::string data;
    time_t dateOfCreation;
    time_t dateOfLastChange;
    int sizeInBytes;
public:
    File();
    File(std::string fileName);
    File(std::string fileName, std::string extension);
    File(std::string fileName, std::string extension, std::string data);
    ~File();
    std::string getFileName() const;
    std::string getExtension() const;
    std::string getData() const;
    time_t getDateOfCreation() const;
    int getSizeInBytes() const;
    void getAllParametres(std::string& fileName, std::string& folderName, std::string& extension, std::string& data,
                          time_t& dateOfCreation, time_t& dateOfLastChange, int& sizeInBytes) const;
    void setFileName(std::string name);
    void setExtension(std::string extension);
    void setBaseFolderName(std::string folderName);
    void deleteData();
    void addData(std::string data);
    void setData(std::string data);
    File& operator =(const File& f2);
    friend std::ostream& operator <<(std::ostream& out, const File& f);
    bool operator ==(const File& f2);
};

#endif /* file_h */
