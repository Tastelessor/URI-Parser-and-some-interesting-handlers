//
// Created by ERWEI LUO on 2022/6/14.
//
#include "checkFiles/checkSSH.cpp"
#include "checkFiles/checkEncrypted.cpp"
#include "URI/URIParser.h"

int main() {
    // Q1 & Q2
    checkSSH cs("../putty.exe");
    checkEncrypted ce("../putty.exe");
    cs.checkFile();
    ce.checkFile();

    // Q3
    URIParser up("mailto:adam.blake@threatspike.com");
    up.parse();
    up.printOut();
    return 0;
}
