#include <iostream>
#include <map>  //map
using namespace std;   
int main()
{
    //创建并初始化 multimap 容器
    multimap<char, int>mymultimap{  {'c',5},{'a',10},{'B',20},{'b',15} };
    //输出 mymultimap 容器存储键值对的数量
    cout << mymultimap.size() << endl;
    //输出 mymultimap 容器中存储键为 'b' 的键值对的数量
    cout << mymultimap.count('b') << endl;
    for (auto iter = mymultimap.begin(); iter != mymultimap.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }
    return 0;
}