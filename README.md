Look-and-Say sequence
---------------------

This sequence (as seen [on Wikipedia](http://en.wikipedia.org/wiki/Look-and-say_sequence))
begins as follows:

- 1
- 11
- 21
- 1211
- 111221
- ...

where each member is formed by reading the member before (e.g. following 21 we
have "one 2, one 1", then "one 1, one 2, two 1", and so forth).

The `look_and_say` template, with template parameter *n*, calculates the *n*th
member of the look-and-say sequence (where 1 is the zeroth member
`look_and_say<0>::t`, so we are offset by one from [OEIS
A005150](http://oeis.org/A005150)). It encodes each member by digit in a
Lisp-like list type with typedef `t`, which affords convenient calculation. You
can print it with the `print` function of the `print_list` template. A simple
example usage can be seen in `main.cpp`.
