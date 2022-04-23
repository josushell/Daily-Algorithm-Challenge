#include <string>
#include <map>

class Solution {
    map<string, string> m;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string str = "http://tinyurl.com/" + to_string(longUrl.length());
        
        m.insert({str, longUrl});
        return str;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return m[shortUrl];
    }
};
