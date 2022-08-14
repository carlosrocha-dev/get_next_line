<div align="center">

![](https://user-images.githubusercontent.com/3737837/177004007-ccfd86d9-d470-41eb-8359-1653bc9b8bb2.png)

</div>

<div align="center">

### :rocket: Working in progress :hammer_and_wrench:
 ![W.I.P.](https://progress-bar.dev/35/?scale=100&title=level&width=500&color=8AB58&suffix=%)

</div>


# Project to read content line by line.

## :clipboard: Task list:

### Mandatory part: :open_file_folder:

- [ ] Makefile
  - [x] Create macros
  - [ ] Insert max files descriptors (256)
  - [ ] Create variable MAX_FD to capture de limit to files can be open on system -> ulimit -sn
	```sh
		ulimit -sn
		-s: stack size (kbytes)             8176
		-n: file descriptors                256
	```
  - [ ] Inser in cc -D
  - [ ] Repeated calls (e.g., using a loop) to your get_next_line() function should let you read the text file pointed to by the file descriptor, one line at a time.
  - [ ] Your function should return the line that was read.
  - [x] If there is nothing else to read or if an error occurred, it should return NULL.

- [ ] get_next_line.c
  - [x] What is an static variable and where it is storage?
    - [ ] Create aux. functions
      - [x] read line
      - [ ] convert list in string
      - [x] free_mem
      - [x] Join all blocks(linked list)

- [ ] get_next_line.h

- [ ] get_next_line_utils.c
  - [ ] Create aux. functions

## Links for reference: :file_cabinet:

https://www.geeksforgeeks.org/static-variables-in-c/

https://www.scaler.com/topics/c/macros-in-c/

## Notes: :spiral_notepad:

- Static Variable: Static variables have a property of preserving their value even after they are out of their scope! Hence, static variables preserve their previous value in their previous scope and are not initialized again in the new scope.
  - Static variables are allocated memory in data segment, not stack segment.
  - ![Memory Layout of C Programs](https://media.geeksforgeeks.org/wp-content/uploads/memoryLayoutC.jpg)
  - E.g:

     ```C

			#include<stdio.h>
			int fun()
			{
			static int count = 0;
			count++;
			return count;
			}

			int main()
			{
			printf("%d ", fun());
			printf("%d ", fun());
			return 0;
			}
	```
	Output:
   ```sh
   		1 2
   ```
- Macros: The macro in C language is an piece of code which can be replaced by the macro value. The macro is defined with the help of #define preprocessor directive and the macro doesn’t end with a semicolon(;). Macro is just a name given to certain values or expressions it doesn't point to any memory location.

- READ:
		```C
			#include <unistd.h>

       		ssize_t read(int fd, void *buf, size_t count);
		```

-