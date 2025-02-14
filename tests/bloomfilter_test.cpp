#include <gtest/gtest.h>
#include "../src/BloomFilter/BloomFilter.cpp"

TEST(OutputTests, emptyBlacklist)
{ 
    {
        // Arrange
        int tableSize = 8;
        const std::set<int> &hashTypes{1, 2};
        std::string url = "example.com";
        BloomFilter bloomFilter(tableSize, hashTypes);
        // Act
        bool result = bloomFilter.checkBlacklist(url);
        // Assert
        ASSERT_FALSE(result);
    }
}

TEST(OutputTests, blacklistedUrl) {
    {
        // Arrange
        int tableSize = 8;
        const std::set<int> &hashTypes{1, 2};
        std::string url = "example.com";
        BloomFilter bloomFilter(tableSize, hashTypes);
        // Act
        bloomFilter.addToBlacklist(url);
        bool result = bloomFilter.checkBlacklist(url);
        // Assert
        ASSERT_TRUE(result);
    }
}
    
TEST(OutputTests, falsePositive) {
    {
        // Arrange
        int tableSize = 8;
        const std::set<int> &hashTypes{1, 2};
        std::string url = "example.com";
        BloomFilter bloomFilter(tableSize, hashTypes);
        // Act
        bloomFilter.addToBlacklist(url);
        bloomFilter.getHashMap().erase(url);
        bool result = bloomFilter.verify(url);
        // Assert
        ASSERT_FALSE(result);
    }
}
 
TEST(OutputTests, truePositive) {
    {
        // Arrange
        int tableSize = 8;
        const std::set<int> &hashTypes{1, 2};
        std::string url = "example.com";
        BloomFilter bloomFilter(tableSize, hashTypes);
        // Act
        bloomFilter.addToBlacklist(url);
        bool result = bloomFilter.verify(url);
        // Assert
        ASSERT_TRUE(result);
    }
}

TEST(InitializationTests, validUserInitLine) {
    { // Arrange
        int expectedTableSize = 8;
        const std::set<int> &expectedHashTypes = {1, 2};
        // Act
        BloomFilter bloomFilter(expectedTableSize, expectedHashTypes);
        // Assert
        EXPECT_EQ(bloomFilter.getHashTypes(), expectedHashTypes);
        EXPECT_EQ(bloomFilter.getHashTable().size(), expectedTableSize);
    }
}

