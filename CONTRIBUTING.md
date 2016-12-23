# Contributing

Awesome that you are reading this!

 * For questions, you can create an Issue
 * Code changes go via Pull Requests

## Branching policy

 * The `master` branch should always build successfully
 * Development happens on the `develop` branch

## Submitting code

Submitted code should follow these quality guidelines:

 * All tests pass cleanly/silently
 * Code coverage above 95%
 * OCLint must be clean

These are all checked by Travis CI when submitting
a Pull Request. 

## Coding standard

The Stroustrup/GNU style, e.g.:

 * Two spaces, no tabs
 * snake_case in variable, function and class names
 * member variables have the `m_` prefix
 * static member variables have the `sm_` prefix

```
void do_it()
{
  int some_thing;
  if (1 == 2) 
  {

  }
  else
  {

  }
}

class my_class
{
  void do_something();
  int m_some_variable;
  static int sm_count;
};
```
Then just follow OCLint

