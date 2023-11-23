char a[10] = {0xe8, 0x59, 0x00, 0x00, 0x00};

int main() {
    void (*f)(void) = (void (*)(void))(a);
    f();
}
