# Quick Introduction #
UNIVHAC consists of a single C++ header file you can include in your projects. In this header file the class Univhac is declared, imagine it looks like this

```
class Univhac
{
   public:
      double poll() const; // returns seconds
      double reset(); // returns seconds
}
```

By calling the method poll(), the time (seconds before the decimal) passed since the last call of reset() or the constructor is returned. reset() resets the timer and also returns the amount of time passed since the last call of reset() or the constructor.

All of these methods are declared inline because this might prevent a pagefault upon calling one of the methods of Univhac.

# FAQ #
## Why the name "UNIVHAC"? ##
It's a reference to the UNIVAC computer (http://en.wikipedia.org/wiki/UNIVAC_I).

## How do I use it in my code? ##
Pull the univhac.h from SVN or use this link: http://univhac.googlecode.com/svn/trunk/univhac.h and #include it in every translation unit that needs it. If you need an example, checkout main.cpp, also in the SVN trunk.