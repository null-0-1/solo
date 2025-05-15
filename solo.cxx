#include <iostream>
#include <cstring>
#include <filesystem>
#include<cstdlib>
using std::cout,std::cin,std::string,std::endl;
using namespace std::filesystem;

void branch(int argc, char *argv[]) {
	path dirpath="projects/"+string(argv[2]);
	path destdir="projects/"+string(argv[3]);
		if(exists(dirpath)) {
			create_directory(destdir);
			copy(dirpath,destdir,copy_options::recursive);
		} else {
			cout<<"\n directory: "<<argv[2]<<" doesn't exist!\n";
		}
}

void create(int argc, char *argv[]) {
	path dirpath="projects/"+string(argv[2])+"/main";
	if(!exists(dirpath)){
		create_directories(dirpath);
	} else{
		cout<<"\n path already exist!\n";
	}
}

void compress(string pathto) {
	path dirpath ="projects/"+pathto;
	string dirpat ="projects/"+pathto;
	size_t LastIndex = dirpat.find_last_of("/");
	string output= dirpat.substr(LastIndex + 1);
	string command="7z a -t7z -m0=lzma2 -mx=9 -mfb=64 -md=32m -ms=on projects/"+output+".7z projects/"+pathto;
		if(exists(dirpath)) {
			//using system call cause ain't compiling allat!
			int result= system(command.c_str());
			cout<<"\n'"<<pathto<< "' is compressed!\n";
		} else {
			cout<<"\n directory: "<<pathto<<" doesn't exist!\n";
		}
}

void decompress(string pathto) {
	path dirpath ="projects/"+pathto;
	string dirpat ="projects/"+pathto;
	size_t LastIndex = dirpat.find_last_of("/");
	string output= dirpat.substr(LastIndex + 1);
	output.resize(0,output.length()-3);
	string command="7z x -o projects/"+output+" projects/"+pathto;
		if(exists(dirpath)) {
			//using system call cause ain't compiling allat!
			int result= system(command.c_str());
			cout<<"\n'"<<pathto<< "' is decompressed!\n";
		} else {
			cout<<"\n7z file: "<<pathto<<" doesn't exist!\n";
		}
}

int main(int argc, char *argv[]){
	
	if (argc < 2){
		cout << "\nerror: no arguments are passed!\n";
		return 0;
	} else if (strcmp(argv[1], "--branch") == 0 || strcmp(argv[1], "-b") == 0){
		if (argc < 4 || argc > 4) {
			cout << "\n error in arguments!\n";
			return 0;
		} else {
			branch(argc,argv);
			}
	} else if (strcmp(argv[1], "--new") == 0 || strcmp(argv[1], "-n") == 0) {
		if (argc < 3 || argc > 3) {
			cout << "\n error in arguments!\n";
			return 0;
		} else { 
		create(argc,argv);
		}
		
	} else if (strcmp(argv[1], "--comp") == 0 || strcmp(argv[1], "-c") == 0) {
		if (argc < 4 || argc > 4) {
			cout << "\n error in arguments!\n";
			return 0;
		} else {
			if(strcmp(argv[2],"true") == 0) {
			compress(argv[3]);
		} else if(strcmp(argv[2],"false") == 0) {
			decompress(argv[3]);
		} else {
			cout<<"\nunknown argument!\n";
		}
			}
		
	} else {
		cout << "\n error:Unknown commands\n";
	}

	return 0;
}
