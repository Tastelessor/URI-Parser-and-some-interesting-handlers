//
// Created by ERWEI LUO on 2022/6/16.
//
#include "URIParser.h"
#include "iostream"

URIParser::URIParser(const string &uri) {
    this->uri = uri;
}

bool URIParser::parse() {
    size_t front;
    size_t back;

    front = uri.find(":");
    // parse scheme
    if (front != string::npos) {
        // Maybe overflow when casting size_t to int but it's fine in this program
        setScheme(uri.substr(0, front));
    } else {
        cout << "Wrong format of URI" << endl;
        return false;
    }

    //parse user
    while (uri[++front] == '/');
    back = uri.find("@", front, 1);

    // try to parse out username
    if (back != string::npos) {
        setUser(uri.substr(front, back - front));
        front = back + 1;
    }

    // try to parse out the host address
    back = uri.find(":", front, 1);
    if (back != string::npos) {
        setHost(uri.substr(front, back - front));
        front = back + 1;
    } else {
        back = uri.find_first_of("/?#", front);
        if (back != string::npos){
            setHost(uri.substr(front, back - front));
        }
        else {
            setHost(uri.substr(front, uri.length() - front));
            return true;
        }
        setPort("Default Port");
        front = back;
    }

    // try to parse out the port number
    if (getPort() != "Default Port") {
        back = uri.find_first_of("/?#", front);
        if (back != string::npos)
            setPort(uri.substr(front, back - front));
        else {
            setPort(uri.substr(front, uri.length() - front));
            return true;
        }
        front = back;
    }

    // Try to parse out one of the followings: path, query, fragment
    if(front < uri.length()) {
        back = uri.find_first_of("?#", front);
        // If there is content following the port number or host
        if(back != string::npos){
            // Set the content according to the symbol marked by front
            if(uri[front] == '/'){
                setPath(uri.substr(front, back - front));
            }
            else if(uri[front] == '?'){
                setQuery(uri.substr(front+1, back - front - 1));
            }
            else {
                setFragment(uri.substr(front+1, back - front - 1));
            }
        }else{
            if(uri[front] == '/'){
                setPath(uri.substr(front, uri.length() - front));
            }
            else if(uri[front] == '?'){
                setQuery(uri.substr(front+1, uri.length() - front - 1));
            }
            else {
                setFragment(uri.substr(front+1, uri.length() - front - 1));
            }
            return true;
        }
        front = back;
    }

    /*
     * If path exists, it must have been parsed out already by the last section
     * So there are only 4 combinations that we need to consider now: query, fragment, query + fragment, nothing
     */
    back = uri.find("#", front);
    // Combinations that include query
    if(uri[front] == '?'){
        // Query + fragment
        if(back != string::npos){
            setQuery(uri.substr(front+1, back - front - 1));
            setFragment(uri.substr(back+1, uri.length() - back - 1));
        }
        // Only query
        else{
            setQuery(uri.substr(front+1, uri.length() - front - 1));
        }
    }
    // Fragment
    else{
        if(back != string::npos)
            setFragment(uri.substr(front+1, uri.length() - front - 1));
    }

    return true;
}

void URIParser::printOut() const {
    cout <<
         "URI:" << getUri() << endl <<
         "Scheme:" << getScheme() << endl <<
         "User:" << getUser() << endl <<
         "Host:" << getHost() << endl <<
         "Port:" << getPort() << endl <<
         "Path:" << getPath() << endl <<
         "Query:" << getQuery() << endl <<
         "Fragment:" << getFragment() << endl;
}

const string &URIParser::getUri() const {
    return uri;
}

void URIParser::setUri(const string &uri) {
    URIParser::uri = uri;
}

const string &URIParser::getUser() const {
    return user;
}

void URIParser::setUser(const string &user) {
    URIParser::user = user;
}

const string &URIParser::getScheme() const {
    return scheme;
}

void URIParser::setScheme(const string &scheme) {
    URIParser::scheme = scheme;
}

const string &URIParser::getHost() const {
    return host;
}

void URIParser::setHost(const string &host) {
    URIParser::host = host;
}

const string &URIParser::getPort() const {
    return port;
}

void URIParser::setPort(const string &port) {
    URIParser::port = port;
}

const string &URIParser::getPath() const {
    return path;
}

void URIParser::setPath(const string &path) {
    URIParser::path = path;
}

const string &URIParser::getQuery() const {
    return query;
}

void URIParser::setQuery(const string &query) {
    URIParser::query = query;
}

const string &URIParser::getFragment() const {
    return fragment;
}

void URIParser::setFragment(const string &fragment) {
    URIParser::fragment = fragment;
}
