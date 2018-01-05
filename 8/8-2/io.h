#define NULL 0
#define EOF (-1)
#define BUFSIZ 1024
#define OPEN_MAX 20

typedef struct _iobuf {
  int cnt; 			/* characters left */
  char *ptr; 			/* next character position */
  char *base; 			/* location of buffer */
  int flag; 			/* mode of file access */
  int fd;                       /*  file descriptor */
} FILE2;

extern FILE2 _iob[OPEN_MAX];

#define stdin (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2])

enum _flags {
  _READ = 01,
  _WRITE = 02,
  _UNBUF = 04,
  _EOF = 010,
  _ERR = 020
};

int _fillbuf(FILE2 *);
int _flushbuf(int, FILE2 *);

#define feof(p) (((p)->flag & _EOF) != 0)
#define ferror(p) (((p)->flag & _ERR) != 0)
#define fileno(p) ((p)->fd)

#define getc(p) (--(p)->cnt >= 0 ? (unsigned char) *(p)->ptr++ : _fillbuf(p))
#define putc(x,p) (--(p)->cnt >= 0 ? *(p)->ptr++ = (x) : _flushbuf((x),p))

#define getchar() getc(stdin)
#define putchar(x) putc((x), stdout)

FILE2 _iob[OPEN_MAX] = {
  { 0, (char *) 0, (char *) 0, _READ, 0 },
  { 0, (char *) 0, (char *) 0, _WRITE, 1 },
  { 0, (char *) 0, (char *) 0, _WRITE | _UNBUF, 2 }
};

