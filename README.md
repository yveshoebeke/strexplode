<h1><img src="docs/string_explode.png" style="height:30px;width:30px;float:left;"/>&nbsp;&nbsp;String Explode</h1>

## Splitting a string in C

### General

Splits a string into an array of elements according to given delimeter.

Some case uses:

- Transform a comma separated string to an array.
- Put all words of a text into an array.

<sup>Note: Both these potential use cases are illustrated in the test (```strexplode_test.c```) program.</sup>

---

### Install and Run test

```shell
mkdir {your_directory_of_choice}
cd {your_directory_of_choice}
```

```shell
git clone https://github.com/yveshoebeke/strexplode
cd strexplode
make
```

<sup>Note: - ```strexpode_test``` can now be invoked. See Example, below. - To compile only: ```make compile```</sup>

Move ```strexplode.h``` to your local C library or in your project directory and indicate this to your compiler accordingly.

---

### Integration

Add ```#include "strexplode.h"``` to your source file.

In your source add something along these lines:

```C
char *astring = "this is a simple string";
char delimeter = ' ';
int word_count;
char** result = strexplode(astring, delimeter, &word_count);
```

Reference ```strexplode_test.c``` as an example.

---

### Signature

```C
char** = strexplode(*char, char, *int)
```

---

### Parameters

There are 3 mandatory parameters.

They are, in order:

1. the subject string (```char*```)
1. the delimeter where to split the subject string (```char```)
1. word count (```int*```)

---

### Run

To run the included test ```strexplode_test.c``` in the directory you cloned this in:

```shell
make compile
./strexplode_test
```

or just:

```shell
make
```

---

### Results

1. The function will return the result in an array of strings (char**).
1. The provided 3'rd argument will contain the number of elements in the resulting array.

---

### Issues

1. There are 2 open issues, see [here](https://github.com/yveshoebeke/strexplode/issues).
1. They do not impact the validity of the result.

---

### Example

Output of ```strexplode_test``` here:

```shell
./strexplode_test
Example 1:
Separate all words in a string into an array:
Given:
- Subject string: '  now the time has come for all   good   men to come to the aid of their country '
(note: starting, ending and sequential/duplicated delimiters are eliminated)
- Delimiter: ' '
- Result:
word count: 17
[0] 'now'
[1] 'the'
[2] 'time'
[3] 'has'
[4] 'come'
[5] 'for'
[6] 'all'
[7] 'good'
[8] 'men'
[9] 'to'
[10] 'come'
[11] 'to'
[12] 'the'
[13] 'aid'
[14] 'of'
[15] 'their'
[16] 'country'

Example 2:
Comma separated list to an array:
Given:
- Subject string: 'McDonnell Douglas,Airbus,Piper,Boeing,Embraer,Bombardier Aerospace,Cessna,Beechcraft,Grumman,Lockheed'
- Delimiter: ','
- Result:
array element count: 10
[0] 'McDonnell Douglas'
[1] 'Airbus'
[2] 'Piper'
[3] 'Boeing'
[4] 'Embraer'
[5] 'Bombardier Aerospace'
[6] 'Cessna'
[7] 'Beechcraft'
[8] 'Grumman'
[9] 'Lockheed'

done
```
