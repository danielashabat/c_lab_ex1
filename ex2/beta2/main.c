
#include "analyze_and_print.h"
#include "flags.h"
#include "import_data.h"
#include <stdio.h>
#include <stdlib.h>

#define MIN_ARGC 2

int main(int argc, char* argv[])
{
  FILE* stream = NULL;
  char** lines = NULL;
  int number_of_lines = 0;
  LinesData* lines_data = NULL;

  Flags flags_obj;
  Flags* flags = &flags_obj;
  char* search_word = NULL;
  char* file_name = NULL;
  int ret_val = 0;

  if (argc < MIN_ARGC) {
    fprintf(stderr, "not enough arguments\n");
    return 1;
  }
    initialize_flags(flags);
    extract_arguments(argc,argv,flags,&search_word,&file_name);
    //printf("search word is: %s, filename is: %s\n",search_word,file_name);

  if (file_name !=NULL) {
      stream = fopen(file_name, "r");
      if (stream == NULL) {
          fprintf(stderr, "file not exist\n");
          return 1;
      }
  } else {
      stream=stdin;
  }


  import_stream_to_lines_arr(stream, &lines, &number_of_lines);
  lines_data = create_lines_data(lines, number_of_lines);
  analyze_which_line_to_print(lines_data, search_word, flags);
  print_output(lines_data, flags);
  free_lines_data(lines_data);
  free(search_word);
  return 0;
}
