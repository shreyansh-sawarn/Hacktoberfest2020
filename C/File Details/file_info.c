#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

void printFileProperties(struct stat stats);

int main(int argc, char *argv[3])
{
  struct stat stats;

  printf("\n");
  for(int i=1; i<argc; i++)
  {
    printf("Given file name: ");
    printf("%s", argv[i]);

    // stat() returns 0 on successful operation,
    // otherwise returns -1 if unable to get file properties.
    if (stat(argv[i], &stats) == 0)
    {
   	printFileProperties(stats);
	printf("\n\n");
    }
    else
    {
      printf("Unable to get file properties.\n");
      printf("Please check whether '%s' file exists.\n", argv[i]);
    }
  }
  return 0;
}

/**
 * Function to print file properties.
 */
void printFileProperties(struct stat stats)
{
  struct tm dt;

  // File permissions
  printf("\nFile access: ");
  if (stats.st_mode & R_OK)
    printf("read ");
  if (stats.st_mode & W_OK)
    printf("write ");
  if (stats.st_mode & X_OK)
    printf("execute");

  // File size
  printf("\nFile size: %ld", stats.st_size);

  // Get file creation time in seconds and 
  // convert seconds to date and time format
  dt = *(gmtime(&stats.st_ctime));
  printf("\nCreated on: %d-%d-%d %d:%d:%d", dt.tm_mday, dt.tm_mon, dt.tm_year + 1900, 
                                            dt.tm_hour, dt.tm_min, dt.tm_sec);

  // File modification time
  dt = *(gmtime(&stats.st_mtime));
  printf("\nModified on: %d-%d-%d %d:%d:%d", dt.tm_mday, dt.tm_mon, dt.tm_year + 1900, 
                                            dt.tm_hour, dt.tm_min, dt.tm_sec);
  
  printf("\nOwnered: %d\ngid: %d", stats.st_uid, stats.st_gid);
  printf("\nAccess Permission: %d", stats.st_mode);
  printf("\nAccess Time: %ld\n", (time(&(stats.st_atime))));
}
