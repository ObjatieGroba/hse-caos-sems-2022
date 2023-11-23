int main() {
    char a[] = {0x31, 0xc0, 0xc3};
    ((void (*)(void))(void*)(a))();
}
