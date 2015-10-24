#include <iostream>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
void biggies(vector <string> &words, vector <string > ::size_type sz)
{
    sort(words.begin(),words.end());
    auto end_unique = unique(words.begin(),words.end());
    words.erase(end_unique, words.end());
    stable_sort(words.begin(),words.end(),[ ] (const string &a, const string &b) {return a.size() < b.size();});
    auto wc = find_if(words.begin(), words.end(), [sz] (const string &a) {return a.size()  >=sz;});
    auto counts = words.end() - wc;
    auto countsb = wc - words.begin();
    cout << counts << " " << countsb << endl;
    for_each(wc,words.end(),[ ] (const string &s ){ cout << s << " ";});
    cout << endl;
}
void istreamiter(){
    ifstream inf("infotest");
    istream_iterator <int > in(inf), eof;
    cout << accumulate(in, eof, 0) << endl;
}

void ostreamiter() {
    ostream_iterator <int > out_iter(cout,",\n");
    vector <int> vec{1,2,3,4,5,6,7};
    copy(vec.begin(),vec.end(), out_iter);
    cout << "\n";
}

int main()
{
    //vector <string> words = {"the","quick","red","fox","jumps","over","the","slow","red","turtle"};
    //biggies(words,4);
    ostreamiter();
    return 0;
}
