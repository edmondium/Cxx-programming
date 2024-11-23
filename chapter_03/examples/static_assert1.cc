auto advance(unsigned long i) -> double
{
    static_assert(sizeof(i) >= 8, "long must be bigger than 8 bytes");
    return 0.;
}
auto main() -> int {}

