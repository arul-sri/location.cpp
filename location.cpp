#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using std::string;
using std::cout; using std::cin; using std::endl;
using std::sort;

long loc_to_dec(string loc){
    long total=0;
    for (auto chr: loc){
        int power = chr - 'a';
        total += pow(2,power);
        }
    return total;
}

string abbreviate(string loc){
    sort(loc.begin(), loc.end());
    int range = loc.length();
    for (int i=0;i<range; i++){
        if (loc[i] == loc[i+1]){
            loc[i] = loc[i] + 1;
            loc.erase(i+1,1);
            return abbreviate(loc);
        }
    }
    return loc;
}

string dec_to_loc(long dec){
    string location;
    int count = 0;
    while (count < dec){
        location += 'a';
        count += 1;
    }
    location = abbreviate(location);
    return location;

}

long add_loc(string loc1, string loc2){
    string loc = loc1 + loc2;
    loc = abbreviate(loc);
    long total = loc_to_dec(loc);
    return total;
}