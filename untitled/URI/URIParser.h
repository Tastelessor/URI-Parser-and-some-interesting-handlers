//
// Created by ERWEI LUO on 2022/6/16.
//

#ifndef UNTITLED_MYURI_H
#define UNTITLED_MYURI_H

#endif //UNTITLED_MYURI_H

#include <string>

using namespace std;

class URIParser{
    string uri;
    string scheme;
    string user;
    string host;
    string port;
    string path;
    string query;
    string fragment;

public:
    // Constructor to initialize the URI string
    URIParser(const string&);

    /*
     * @Return: true - correct URI; false - incorrect URI
     */
    bool parse();

    void printOut() const;

    const string &getUri() const;

    void setUri(const string &uri);

    const string &getScheme() const;

    void setScheme(const string &scheme);

    const string &getHost() const;

    void setHost(const string &host);

    const string &getPort() const;

    void setPort(const string &port);

    const string &getPath() const;

    void setPath(const string &path);

    const string &getQuery() const;

    void setQuery(const string &query);

    const string &getFragment() const;

    void setFragment(const string &fragment);

    const string &getUser() const;

    void setUser(const string &user);
};