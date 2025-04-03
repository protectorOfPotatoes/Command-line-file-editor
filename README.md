# File Operations in C

This program allows the user to interact with files by reading, writing, and appending content.

## Features
- **Read a file** (`r`): Prints the contents of the file.
- **Write to a file** (`w`): Overwrites existing content with new input.
- **Append to a file** (`a`): Adds new content at the end of the file.

## Code Implementation

```c
#include <stdio.h>
#include <string.h>

#define LINE_SIZE 20
#define FILE_LENGTH 100 // Increased size for longer file names
#define SIZE 10

void print_file(char file_name[FILE_LENGTH])
{
    FILE* file = fopen(file_name, "r");
    char text[LINE_SIZE];
    
    if (file == NULL) {
        fprintf(stderr, "Error: File Doesn't Exist\n");
        return;
    }
    
    while (fgets(text, sizeof(text), file)) {
        printf("%s", text);
    }
    
    fclose(file);
}

void write_to_file(char file_name[FILE_LENGTH])
{
    FILE* file = fopen(file_name, "w");
    if (file == NULL) {
        printf("Error: Couldn't open file\n");
        return;
    }
    
    printf("What do you wish to write to your file?\n");
    char query[50];
    
    fgets(query, sizeof(query), stdin);
    fprintf(file, "%s", query);
    
    printf("Written to file successfully!\n");
    fclose(file);
}

void append_to_file(char file_name[FILE_LENGTH])
{
    FILE* file = fopen(file_name, "a");
    if (file == NULL) {
        printf("Error: Couldn't open file\n");
        return;
    }
    
    printf("What do you wish to append to your file?\n");
    char query[50];
    
    fgets(query, sizeof(query), stdin);
    fprintf(file, "%s", query);
    
    printf("Written to file successfully!\n");
    fclose(file);
}

int main()
{
    printf("r: print file contents\nw: write to file\na: append to file\n");

    char file_name[FILE_LENGTH];

    printf("Write the File's Name: \n");
    fgets(file_name, FILE_LENGTH, stdin);
    file_name[strcspn(file_name, "\n")] = '\0';

    printf("Write course of action for file: \n");

    char action[SIZE];
    fgets(action, sizeof(action), stdin);
    action[strcspn(action, "\n")] = '\0';

    if (strcmp(action, "r") == 0) {
        print_file(file_name);
    } else if (strcmp(action, "w") == 0) {
        write_to_file(file_name);
    } else if (strcmp(action, "a") == 0) {
        append_to_file(file_name);
    } else {
        printf("Invalid!\n");
    }

    return 0;
}
```

## Usage Instructions
1. **Compile the program**:
   ```sh
   gcc file_operations.c -o file_operations
   ```
2. **Run the program**:
   ```sh
   ./file_operations
   ```
3. **Follow the prompts**:
   - Enter the file name.
   - Choose an action (`r`, `w`, `a`).
   - Enter text when prompted for writing or appending.

## Notes
- The program **removes the newline character** from user input.
- `fprintf(file, "%s", query);` is used instead of `fprintf(file, query);` to **avoid format string vulnerabilities**.
- **File names are limited to 100 characters**, and input buffers are properly managed to prevent overflows.

## Improvements
- Add **error handling for empty input**.
- Allow **multiple operations** without restarting the program.
- Implement **file existence checks** before writing or appending.

## License
DWYW License.
