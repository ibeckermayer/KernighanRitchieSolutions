#define NULL 0
#define EOF (-1)
#define BUFSIZ 1024
#define OPEN_MAX 20
#define PERMS 0666
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

enum _flags {
  _READ = 01,
  _WRITE = 02,
  _UNBUF = 04,
  _EOF = 010,
  _ERR = 020
};

typedef struct {
  unsigned int _READ : 1;
  unsigned int _WRITE : 1;
  unsigned int _UNBUF : 1;
  unsigned int _EOF : 1;
  unsigned int _ERR : 1;
} _flag;

typedef struct _iobuf2 {
  int cnt; /* characters left */
  char *ptr; /* next character position */
  char *base; /* location of buffer */
  int flag; /* mode of file access */
  int fd;                       /*  file descriptor */
} FILE2;

typedef struct _iobuf3 {
  int cnt; /* characters left */
  char *ptr; /* next character position */
  char *base; /* location of buffer */
  _flag flag; /* mode of file access */
  int fd;                       /*  file descriptor */
} FILE3;

extern FILE2 _iob2[OPEN_MAX];
extern FILE3 _iob3[OPEN_MAX];

#define stdin2 (&_iob2[0])
#define stdout2 (&_iob2[1])
#define stderr2 (&_iob2[2])

#define stdin3 (&_iob3[0])
#define stdout3 (&_iob3[1])
#define stderr3 (&_iob3[2])

int _fillbuf(FILE2 *);
int _flushbuf(int, FILE2 *);

#define feof(p) (((p)->flag & _EOF) != 0)
#define ferror(p) (((p)->flag & _ERR) != 0)
#define fileno(p) ((p)->fd)

#define getc(p) (--(p)->cnt >= 0 ? (unsigned char) *(p)->ptr++ : _fillbuf(p))
#define putc(x,p) (--(p)->cnt >= 0 ? *(p)->ptr++ = (x) : _flushbuf((x),p))

#define getchar() getc(stdin)
#define putchar(x) putc((x), stdout)

FILE2 _iob2[OPEN_MAX] = {
  { 0, (char *) 0, (char *) 0, _READ, 0 },
  { 0, (char *) 0, (char *) 0, _WRITE, 1 },
  { 0, (char *) 0, (char *) 0, _WRITE | _UNBUF, 2 }
};

FILE3 _iob3[OPEN_MAX] = {
  { 0, (char *) 0, (char *) 0, {1,0,0,0,0}, 0 },
  { 0, (char *) 0, (char *) 0, {0,1,0,0,0}, 1 },
  { 0, (char *) 0, (char *) 0, {0,1,1,0,0}, 2 }
};

FILE2 *fopen2(char *name, char *mode)
{
  int fd;
  FILE2 *fp;

  if (*mode != 'r' && *mode != 'w' && *mode != 'a')
    return NULL;
  for (fp = _iob2; fp < _iob2 + OPEN_MAX; fp++)
    if ((fp->flag & (_READ | _WRITE)) == 0)
      break;			/* found free slot */
  if (fp >= _iob2 + OPEN_MAX)	/* no free slots */
    return NULL;

  if (*mode == 'w')
    fd = creat(name, PERMS);
  else if (*mode == 'a') {
    if ((fd = open(name, O_WRONLY, 0)) == -1)
      fd = creat(name, PERMS);
    lseek(fd, 0L, 2);
  } else
    fd = open(name, O_RDONLY, 0);
  if (fd == -1) 		/* couldn't access name */
    return NULL;
  fp->fd = fd;
  fp->cnt = 0;
  fp->base = NULL;
  fp->flag = (*mode == 'r') ? _READ : _WRITE;
  return fp;
}

FILE3 *fopen3(char *name, char *mode)
{
  int fd;
  FILE3 *fp;

  if (*mode != 'r' && *mode != 'w' && *mode != 'a')
    return NULL;
  for (fp = _iob3; fp < _iob3 + OPEN_MAX; fp++)
    if (fp->flag._READ == 0 && fp->flag._WRITE == 0)
      break;			/* found free slot */
  if (fp >= _iob3 + OPEN_MAX)	/* no free slots */
    return NULL;

  if (*mode == 'w')
    fd = creat(name, PERMS);
  else if (*mode == 'a') {
    if ((fd = open(name, O_WRONLY, 0)) == -1)
      fd = creat(name, PERMS);
    lseek(fd, 0L, 2);
  } else
    fd = open(name, O_RDONLY, 0);
  if (fd == -1) 		/* couldn't access name */
    return NULL;
  fp->fd = fd;
  fp->cnt = 0;
  fp->base = NULL;
  if (*mode == 'r')
    fp->flag._READ = 1;
  if (*mode == 'w')
    fp->flag._WRITE = 1;
  return fp;
}


int main()
{
  clock_t begin2 = clock();
  FILE2 *fp2 = fopen2("8-2.c", "r");
  clock_t end2 = clock();
  double time_spent2 = (double)(end2 - begin2) / CLOCKS_PER_SEC;

  clock_t begin3 = clock();
  FILE3 *fp3 = fopen3("8-2.c", "r");
  clock_t end3 = clock();
  double time_spent3 = (double)(end3 - begin3) / CLOCKS_PER_SEC;

  printf("time2 = %f\n", time_spent2);
  printf("time3 = %f\n", time_spent3);
}
