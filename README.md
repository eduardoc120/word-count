# Word Frequency Counter

This is a C++ program that reads a text file, counts the frequency of each word in the file, and displays the word frequencies in descending order.

## Features

- Reads a text file and processes its contents.
- Ignores case sensitivity when counting word frequencies.
- Handles special characters and removes them from words.
- Displays the word frequencies in descending order.

## Usage

1. Clone the repository or download the source code files.

`git clone https://github.com/eduardoc120/word-count.git`

2. Navigate to the project directory:

`cd word-count`

4. Run the program from the output folder:

`./output/main`

5. Enter the name of the text file to open (input.txt is an example in the output folder).

`input.txt`

6. View the word frequencies displayed on the console.

## Example

We have a test text file named `input.txt` with the following content:
```
Hello world! This is a sample text. Hello again.
```

Running the program and providing `input.txt` as the filename would produce the following output:

```
Word Frequency:
hello: 2
again: 1
a: 1
is: 1
sample: 1
text: 1
this: 1
world: 1
```
