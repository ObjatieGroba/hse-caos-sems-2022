struct RandomGenerator;

typedef int(*Next)(struct RandomGenerator*);

struct RandomGenerator {
    int x;  // 0 - 3  /  64bit - 0 - 3
    long long y;  // 4 - 11  /  64bit - 8 - 15
    int z;  // 12 - 15  /  64bit - 16 - 19

    int (*next)(struct RandomGenerator *rr);
    Next next2;
};

// typedef int (*Mega)(int, int) (*Mega)(int x, int y);

struct Some {
    char x;  // 0 - 0
    int y;  // 4 - 7

    struct Other {
        int x;
    } z;
};
