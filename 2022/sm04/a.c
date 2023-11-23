void func(char *str) {
    "abc\0";
}

/// int == signed int
/// unsigned == unsigned int
/// char == ???
/// signed char
/// unsigned char

void func(int x, char c);

int strcmp(char *s1, char * s2, size_t size) {
    int *p1 = s1;
    int *p2 = s2;
    size /= 4;
    for (size_t i = 0; i != size; ++i) {
        //++p1;
        //++p2;
        //*p1;
        //*p2;
        if (p1[i] != p2[i]) {
            return p2[i] - p1[i];
        }
    }
    return 0;
}

int main() {

}