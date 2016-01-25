# Todayfile

Command line tool to create a file with the current date as the file name 

## Install

Clone the repo 

```sh
git clone https://github.com/aeewhite/todayfile.git
```
then compile

```sh
make
```
and install

```sh
make install
```

## Usage

```sh
todayfile [extension]
```
Creates an empty file in the current directory with the name 'YYYY-MM-DD' with the extension '.md' or the extension supplied as the first argument

On OS X, you can create a new file and open it one command 

```sh
open $(todayfile [extension])
```
