#pragma once

class Hash {
public:
    virtual int calcHash(const char*) = 0;
};

class CountVowelsHash : public Hash {
public:
    int calcHash(const char*) override;
};

class CountConsonantHash : public Hash {
public:
    int calcHash(const char*) override;
};
class CountAsciiHash : public Hash {
public:
    int calcHash(const char*) override;
};
class EasyHash : public Hash {
public:
    int calcHash(const char*) override;
};


class HashManager {
    struct hash_elem {

        Hash* hash;
        char const* nume;
    }list[4];
    int count;
public:
    Hash*& operator[](const char*);
    void print_hashes(const char*);
    HashManager();
};