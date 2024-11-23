double advance(unsigned long L)
{
    static_assert(sizeof(L) >= 8, "long must be at least 8 bytes. ");
    //Bit manipulation assuming "long" is at least 8 bytes
    return static_cast<double>(L);
}
int main() {}
