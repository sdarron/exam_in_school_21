void print_hex(int n)
{
    char arr[] = "0123456789abcdef";

    if (n >= 16)
        print_hex(n / 16);
    write(1, &arr[n % 16], 1);
}