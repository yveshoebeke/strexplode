<h1><img src="docs/string_explode.png" style="height:30px;width:30px;float:left;"/>&nbsp;&nbsp;String Explode</h1>

## Splitting a string in C

### General

Splits a string into an array of elements according to given delimeter.

<sup>(Note: In case you are wondering about the choice of name. Once upon a long time ago I, out of necessity, was a somewhat prolific PHP programmer (hence the elephant in the room...); and I liked the way this function is named, it sort of acurately describes it. Others will opine differently, I'm sure)</sup>

---

### Install and Run test

```shell
mkdir {your_directory_of_choice}
cd {your_directory_of_choice}
git clone https://github.com/yveshoebeke/strexplode
cd strexplode
make compile
```

<sup>Note: ```strexpode_test``` can now be invoked. See Example, below.</sup>

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
