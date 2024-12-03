#ifndef FOLDER_H
#define FOLDER_H

#include "filesystemobject.h"
#include "file.h"
#include "searchable.h"
#include "linkedlist.h"

struct Folder : public FileSystemObject, public Searchable {
private:
	LinkedList<File*> files;
	LinkedList<Folder*> folders;
public:
	//initializes list of files and list of folders inside constructor
	Folder(std::string name = "folder_name");
	Folder(const Folder& folder);
	void addFile(File* file);
	void deleteFile(File* file);
	void addFolder(Folder* folder);
	void deleteFolder(Folder* folder);
	//moves file into a folder inside current folder (same level)
	void moveFile(const std::string& fileName, const std::string& dest);
	//moves folder into another folder inside current folder (same level)
	void moveFolder(const std::string& folderName, const std::string& dest);
	//prints all files with matching name
	File* getFile(std::string query);
	//prints all folders with matching name
	Folder* getFolder(std::string query);
	int getSize() const;
	void search(std::string query)const;
	void print() const;
	bool operator==(const Folder& rhs) const;
};
#endif