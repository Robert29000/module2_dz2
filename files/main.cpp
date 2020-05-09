//
//  main.cpp
//  files
//
//  Created by Роберт Артур Меликян on 05/05/2020.
//  Copyright © 2020 Роберт Артур Меликян. All rights reserved.
//

#include <iostream>
#include "file.h"
#include "folder.h"

int main(int argc, const char * argv[]) {
    File f;
    f.setFileName("suka");
    f.setExtension("exe");
    f.setData("Я уже заебался");
    File f1("fuck", "txt", "Ура я это сделал");
    Folder base("Files");
    base.addFile(f);
    base.addFile(f1);
    f.addData("Ебать");
    base.changeFile(f);
    std::vector<File> files = { File("boy", "doc", "info"), File("shit", "ppt", "presentation"),
        File("blyat", "zip", "fjksajf")};
    Folder base2("Sub_files");
    base2.addFiles(files);
    base.mergeFolder(base2);
    File& getF = base.getFile("fuck", "txt");
    getF.setData("Fuck you all");
    std::vector<File>& folderFiles = base.getAllFiles();
    folderFiles[0].deleteData();
    return 0;
}
