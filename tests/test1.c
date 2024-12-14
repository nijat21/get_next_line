#include "../get_next_line.h"

static void test_get_next_line(const char *filename)
{
    int fd = open(filename, O_RDWR);
    if (fd < 0)
    {
        perror("Error opening file");
        return;
    }

    char *line;
    printf("file: %s\n", filename);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line); // Print the line read by get_next_line
        free(line);
    }
    close(fd);
}

int main(void)
{
    // test_get_next_line("texts/text.txt");

    // test_get_next_line("files/1char.txt");
    // test_get_next_line("files/empty");
    // test_get_next_line("files/nl");
    // test_get_next_line("files/41_no_nl");
    // test_get_next_line("files/41_with_nl");
    // test_get_next_line("files/42_no_nl");
    // test_get_next_line("files/42_with_nl");
    // test_get_next_line("files/43_no_nl");
    // test_get_next_line("files/43_with_nl");
    // test_get_next_line("files/multiple_nl.txt");
    test_get_next_line("files/variable_nls.txt");

    // test_get_next_line("files/one_line_no_nl.txt");
    // test_get_next_line("files/read_error.txt");

    return 0;
}
