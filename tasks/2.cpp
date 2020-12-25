В реализации Microsoft C++
int	4 байта
double	8 байт
bool	1 байт
char	1 байт
wchar_t	2 байта
unsigned char	1 байт
unsigned int	4 байта
long long	8 байт

а так
1 == sizeof(char) <= sizeof(short) <= sizeof(int) <= sizeof(long) <= sizeof(long long)
