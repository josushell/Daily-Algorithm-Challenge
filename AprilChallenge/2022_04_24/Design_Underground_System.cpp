#include <tuple>
#include <vector>

class UndergroundSystem {
private:
    vector<tuple<string, string, int, int>> v;
    vector<tuple<int, string, string, int>> vId;

public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        vId.push_back({id, stationName, "", t});
    }
    
    void checkOut(int id, string stationName, int t) {
        int time = -1;
        
        for(int i = 0;i < vId.size();i++)
        {
            if (get<0>(vId[i]) == id)
            {
                get<2>(vId[i]) = stationName;
                time = t - get<3>(vId[i]);
                
                push_vector(get<1>(vId[i]), stationName, time);
                
                vId.erase(vId.begin() + i);
                break;
            }
        }
    }
    void push_vector(string s1, string s2, int t)
    {
        int flag = 0;
        
        for(int i = 0;i < v.size();i++)
        {
            if (get<0>(v[i]) == s1 && get<1>(v[i]) == s2)
            {
                get<2>(v[i]) = get<2>(v[i]) + t;
                get<3>(v[i]) = get<3>(v[i]) + 1;
                
                flag = 1;
                break;
            }
        }
        
        if (flag == 0)
        {
            v.push_back({s1, s2, t, 1});
        }
    }
    double getAverageTime(string startStation, string endStation) {
        double result = 0;
        
        for(int i = 0;i < v.size();i++)
        {
            if (get<0>(v[i]) == startStation && get<1>(v[i]) == endStation)
            {
                result = get<2>(v[i]) / (double)get<3>(v[i]);
                break;
            }
        }
        
        return result;
    }
};
