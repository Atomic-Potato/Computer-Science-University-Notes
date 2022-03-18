# Intro
`awk` is use to manipulate data that has the shape of rows and columns
![[Pasted image 20220305173245.png | 400]]

# Usage
## Syntax
```
awk [options] [script] [files]
or
awk [options] -f [scriptfile] [files]
```
**Options:**
- `-F` to change input field separator
- `-f` to name script file

# Basics
awk consist of a pattern and an action, example: *awk '/for/' testfile*

Example of an input
![[Pasted image 20220305173720.png | 600]]

to access the content of each field  at our current record we use `$1, $2, ...` with the number of the corresponding column. 
`$0` will show us the entire current record

## Some system variables
- `FS` Field separator (default=whitespace)
- `RS` Field separator (default=whitespace)
- `NF` Number of fields in current record
- `NR` Number of the current record
- `OFS` Output field separator (default=space)
- `ORS` Output record separator (default=\n)
- `FILENAME` Current file name

examples
```
awk '{print NR, $1, $2, $5}' emps
awk -F: '/Jones/{print $1, $2}' em2
```

## Arithmetic, Relational & Logical Operations 
![[Pasted image 20220305174240.png | 500]]
![[Pasted image 20220305174400.png | 500]]
![[Pasted image 20220305174417.png | 500]]

Example:
```
awk '$3 * $4 > 500 {print $0}' file
```