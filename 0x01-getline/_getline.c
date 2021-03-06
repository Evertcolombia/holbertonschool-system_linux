#include "_getline.h"

/**
 * *_getline - gets a line of chars from a file descriptor
 * @fd: the file descriptor to read
 *
 * Return: pointer to the line
 */
char *_getline(const int fd)
{
	static getlined_t head;
	getlined_t *fb = NULL, *temp;
	char *line = NULL;

	if (fd == -1)
	{
		if (head.buf)
			head.buf = (free(head.buf), NULL);
		for (fb = head.next; fb;)
		{
			if (fb->buf)
			{
				free(fb->buf);
				fb->buf = NULL;
			}
			temp = fb;
			fb = fb->next;
			free(temp);
		}
		memset(&head, 0, sizeof(head));
		return (NULL);
	}
	fb = get_df_buffer_size(&head, fd);
	if (fb)
		line = read_buff_size(fb);
	if (line && line[0] == '\n' && !line[1])
		line[0] = 0;
	return (line);
}

/**
 * read_buff_size - reads into the buffer
 * @fb: the fd buf struct
 *
 * Return: 0 on success else -1 on error.
 */
char *read_buff_size(getlined_t *fb)
{
	char buf[READ_SIZE + 1], *p, *line;
	ssize_t r = 0;

	p = _strchr(fb->buf + fb->index, '\n', fb->len - fb->index);
	if (!fb->len || fb->index >= fb->len || !p)
	{
		while (1)
		{
			r = read(fb->fd, buf, READ_SIZE);
			if (r < 0 || (r == 0 && !fb->len))
				return (fb->buf ? (free(fb->buf), NULL) : NULL);
			if (r == 0)
			{
				p = fb->buf + fb->len;
				break;
			}
			fb->buf = _realloc(fb->buf, fb->len, fb->len + r + 1);
			if (!fb->buf)
				return (NULL);
			memcpy(fb->buf + fb->len, buf, r), fb->len += r;
			p = _strchr(fb->buf + (fb->len - r), '\n', r);
			if (p)
			{
				fb->buf[fb->len] = 0;
				break;
			}
		}
	}
	*p = '\0';
	line = malloc(1 + (p - (fb->buf + fb->index)));
	if (!line)
		return (NULL);
	memcpy(line, fb->buf + fb->index, 1 + (p - (fb->buf + fb->index)));
	fb->index = (p - fb->buf) + 1;
	if (fb->index >= fb->len)
	{
		fb->index = fb->len = 0;
		fb->buf = (free(fb->buf), NULL);
	}
	return (line);
}

/**
 * get_df_buffer_size - adds a car to linked list
 * @fd: file descriptor of buffer to get
 * Return: pointer to the fd buf node
 */
getlined_t *get_df_buffer_size(getlined_t *head, const int fd)
{
	getlined_t *node;

	if (!head->buf && !head->fd && !head->next)
	{
		head->fd = fd;
		return (head);
	}
	for (; head->next && head->next->fd <= fd; head = head->next)
		;
	if (head->fd == fd)
		return (head);
	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);
	if (fd < head->fd) /* need to copy head over and replace */
	{
		memcpy(node, head, sizeof(*head));
		memset(head, 0, sizeof(*head));
		head->fd = fd;
		head->next = node;
		return (head);
	}
	memset(node, 0, sizeof(*node));
	node->fd = fd;
	node->next = head->next;
	head->next = node;
	return (node);
}

/**
 *  *_strchr - locates a character in a string
 *  @s: the string to be parsed
 *  @size: number of bytes to search
 *  Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char c, ssize_t size)
{
	if (!s)
		return (NULL);
	do {
		if (*s == c)
			return (s);
		s++;
	} while (--size > 0);
	return (NULL);
}

/**
 * _realloc - reallocates a block of memory
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}