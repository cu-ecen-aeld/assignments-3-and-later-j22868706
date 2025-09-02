#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments (2) are provided.
    // The program name itself is the first argument, so argc should be 3.
    if (argc != 3) {
        // Log an error to syslog with LOG_ERR level.
        openlog(NULL, LOG_PID, LOG_USER);
        syslog(LOG_ERR, "Error: Invalid number of arguments. Usage: %s <file> <string>", argv[0]);
        closelog();
        // Print usage message to stderr for user feedback.
        fprintf(stderr, "Error: Invalid number of arguments.\n");
        fprintf(stderr, "Usage: %s <writefile> <writestr>\n", argv[0]);
        return 1; // Return a non-zero exit code to indicate failure.
    }

    const char *writefile = argv[1];
    const char *writestr = argv[2];
    FILE *file;

    // Open a log handle for this process.
    openlog(NULL, LOG_PID | LOG_CONS, LOG_USER);

    // Log the action with LOG_DEBUG level as required by the assignment.
    syslog(LOG_DEBUG, "Writing %s to %s", writestr, writefile);

    // Open the file in write mode ("w").
    // If the file exists, its contents will be overwritten. If not, it will be created.
    file = fopen(writefile, "w");

    // Check if the file was successfully opened.
    if (file == NULL) {
        // Log an error if file opening failed.
        syslog(LOG_ERR, "Error: Failed to open file %s", writefile);
        // Print error to stderr for user feedback.
        fprintf(stderr, "Error: Failed to open file '%s'.\n", writefile);
        closelog();
        return 1; // Return a non-zero exit code.
    }

    // Write the string to the file.
    int result = fputs(writestr, file);
    if (result == EOF) {
        // Log an error if writing to the file failed.
        syslog(LOG_ERR, "Error: Failed to write to file %s", writefile);
        // Print error to stderr.
        fprintf(stderr, "Error: Failed to write to file '%s'.\n", writefile);
        // Close the file before exiting.
        fclose(file);
        closelog();
        return 1;
    }

    // Close the file.
    fclose(file);

    // Close the syslog handle.
    closelog();
    
    return 0; // Return 0 to indicate success.
}

