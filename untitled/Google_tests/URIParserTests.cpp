//
// Created by ERWEI LUO on 2022/6/16.
//
#include "gtest/gtest.h"
#include "../URI/URIParser.h"

class URIParserFixture : public ::testing::Test {

};

TEST(URIParserFixture, URLTest) {
    URIParser uri = URIParser("http://www.apple.com:80/store/products?mychoice=macpro#techspecs");
    EXPECT_TRUE(uri.parse());
    EXPECT_EQ(uri.getUri(), "http://www.apple.com:80/store/products?mychoice=macpro#techspecs");
    EXPECT_EQ(uri.getScheme(), "http");
    EXPECT_EQ(uri.getUser(), "");
    EXPECT_EQ(uri.getHost(), "www.apple.com");
    EXPECT_EQ(uri.getPort(), "80");
    EXPECT_EQ(uri.getPath(), "/store/products");
    EXPECT_EQ(uri.getQuery(), "mychoice=macpro");
    EXPECT_EQ(uri.getFragment(), "techspecs");
}

TEST(URIParserFixture, URNTest) {
    URIParser uri = URIParser("mailto:adam.blake@threatspike.com");
    EXPECT_TRUE(uri.parse());
    EXPECT_EQ(uri.getUri(), "mailto:adam.blake@threatspike.com");
    EXPECT_EQ(uri.getScheme(), "mailto");
    EXPECT_EQ(uri.getUser(), "adam.blake");
    EXPECT_EQ(uri.getHost(), "threatspike.com");
    EXPECT_EQ(uri.getPort(), "");
    EXPECT_EQ(uri.getPath(), "");
    EXPECT_EQ(uri.getQuery(), "");
    EXPECT_EQ(uri.getFragment(), "");
}

TEST(URIParserFixture, FailureTest) {
    URIParser uri = URIParser("AMeaninglessString");
    EXPECT_FALSE(uri.parse());
    uri.setUri("https//www.apple.com/store/products?mychoice=macpro#techspecs");
    EXPECT_FALSE(uri.parse());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}