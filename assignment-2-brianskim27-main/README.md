# Assignment 2

## Provided Files
There are two files in this repository, as follows:

### assignment2solutions.c

This file is where you will be writing your code. For each function on the assignment, you will have to write the corresponding function provided in this file (be sure to edit the return statements, which are currently written to just return 0 or NULL). You may include additional helper functions to assist with the code, but do not edit the main function or either of the print functions (both of which are used by main). Reminder: All code that you write must be your own -- do not copy segments of code from other sources (code covered in class is okay).

### Makefile

We have provided a makefile with the following explicit rules:

- `test`: has dependency on the assignment2solutions executable file, and runs assignment2solutions.
- `test1`-`test6`: have dependency on the assignment2solutions executable file, and runs assignment2solutions with command line arguments that will allow only test cases from the corresponding question on the assignment, e.g. typing `make test1` will run only the test cases for question 1, etc. These will be helpful for working on individual problems in the assignment.
- `clean`: removes all files created by the Makefile.

## Completing the Assignment

1. Clone the repository on a UNIX machine using the command `git clone URL` for the URL of your repository.
2. For each question on the handout on Brightspace, write the corresponding function in the provided C file provided in this repository. You may use helper functions (like those covered in class) to write any of these functions. Do not edit the main function in this file; this is already set up to run some test cases that will be used to check your code. Make sure that your code compiles and runs properly on the LDAP machines without any errors or warnings.
3. Regularly push edits you make in your local repository using the commands `git commit -a -m "commit comment"` to commit the changes you made, and `git push` to update the master repository.
4. Once you are finished, post the 40-hex-character hash code of your final commit in the assignment link on Brightspace. You can obtain this code using the command `git rev-parse HEAD`.
