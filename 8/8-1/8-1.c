#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
/* #include <syscalls.h> */

#define STDIN 0
#define STDOUT 1
#define STDERR 2

void filecopy7(FILE *ifp, FILE *ofp)
{
  int c;
  while ((c = getc(ifp)) != EOF)
    putc(c, ofp);
}

void filecopy8(int f1, int f2)
{
  int n;
  char buf[BUFSIZ];

  while ((n = read(f1, buf, BUFSIZ)) > 0)
    if (write(f2, buf, n) != n) {
      fprintf(stderr, "write error\n");
      exit(-1);
    }
}

int cat7(int argc, char *argv[])
{
  FILE *fp;
  char *prog = argv[0];

  if (argc == 1)
    filecopy7(stdin, stdout);
  else
    while (--argc > 0)
      if ((fp = fopen(*++argv, "r")) == NULL) {
	fprintf(stderr, "%s: can't open %s\n", prog, *argv);
	exit(1);
      } else {
	filecopy7(fp, stdout);
	fclose(fp);
      }
  if (ferror(stdout)) {
    fprintf(stderr, "%s: error writing stdout\n", prog);
    exit(2);
  }
  return 0;
}

int cat8(int argc, char *argv[])
{
  int fd;
  char *prog = argv[0];

  if (argc == 1)
    filecopy8(STDIN, STDOUT);
  else
    while (--argc > 0)
      if ((fd = open(*++argv, O_RDONLY, 0)) == -1) {
	fprintf(stderr, "%s: can't open %s\n", prog, *argv);
	exit(1);
      } else {
	filecopy8(fd, STDOUT);
	close(fd);
      }
  if (ferror(stdout)) {
    fprintf(stderr, "%s: error writing stdout\n", prog);
    exit(2);
  }
  return 0;
}

int main(int argc, char *argv[])
{
  clock_t begin = clock();
  cat7(argc, argv);
  clock_t end = clock();
  double time_spent7 = (double)(end - begin) / CLOCKS_PER_SEC;

  clock_t begin1 = clock();
  cat8(argc, argv);
  clock_t end1 = clock();
  double time_spent8 = (double)(end1 - begin1) / CLOCKS_PER_SEC;

  printf("standard library time: %f\n", time_spent7);
  printf("system call time: %f\n", time_spent8);

  return 0;
}

