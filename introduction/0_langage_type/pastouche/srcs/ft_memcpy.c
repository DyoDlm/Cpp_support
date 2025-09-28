#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t dst_size)
{
	size_t			i;
	unsigned char		*d;
	const unsigned char	*s;

	i = -1;
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (!dst && !src) // ! == NULL
		return (NULL);
	while (++i < dst_size)
		d[i] = s[i];
	return (dst);
}
