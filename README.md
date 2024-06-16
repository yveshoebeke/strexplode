<h1><img src="docs/str_explode.png" style="height:60px;width:50px;float:left;"/>&nbsp;&nbsp;String Explode</h1>

## Splitting a string in C

### General

Splits a string into an array of strings according to given delimeter.

<sup>(Note: In case you're wondering the choice of name. Once upon a long time ago I, out of necessity, was a somewhat prolific PHP programmer (hence the elephant in the room...); and I like the way this function is phrased, it sort of acurately describes it. Others will opine differently, I'm sure)</sup>

---

### Install

[rework this]

```shell
mkdir {your_directory_of_choice}
cd {your_directory_of_choice}
git clone https://github.com/yveshoebeke/strexplode
cd strexplode
make
```
<sup>Note: strexpode_test will be invoked. Alter at your whim.</sup>

Move ```strexplode.h``` to your local C library or in your project directory and act accordingly.

---

### Integration

Add ```#include "strexplode.h"``` to your source file.

In your source add something along this:

```C
char *astring = "this is a simple string";
char delimeter = ' ';
int word_count;
char** result = strexplode(astring, delimeter, &word_count);
```

---

### Signature

```C
char** = strexplode(*char, char, *int)
```

---

### Run

In the directory you placed do this:

```shell
make
```

---

### Parameters

There are 3 mandatory parameters.

They are, in order:

1. the subject string (```char*```)
1. the delimeter where to split the subject string (```char```)
1. word count (```int*```)


### More Info/Details

See [later]

___
