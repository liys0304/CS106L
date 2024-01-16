funcs can have four levels of exception safety:
1.no throw exception guarantee
    absolutely does not throw exceptions: destructors, swap, 
    move constructors,ect.
2.strong exception guarantee
    rolled back to the state before func call
3.basic exception guarantee
    program is in valid state after exception
4.no exception guarantee
    resource leaks, memory corruption, bad...


构造函数申请资源，析构函数释放资源
void printFile()
{
    ifstream input();
    input.open("hamlet.txt");

    string line;
    while(getline(inpyr, line)){
        cout << line << endl;
    }

    input.close();
}

void printFile()
{
    ifstream input("hamlet.txt");
    //input.open("hamlet.txt"); 

    string line;
    while(getline(inpyr, line)){
        cout << line << endl;
    }
    // no close call needed
}//stream destructor, releases access to file

void cleanDatabase(mutex& databaseLock,
            map<int,int>& database){
    lock_guard<mutex>(databaseLock);

    other threads will not modify database
    modify the database
    if exception thrown, thats fine

    //mo release call needed
} lock always unlocked when func exits