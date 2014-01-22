native-pyext-skeleton
=====================

Skeleton code to get started writing a Python module that uses a native extension.

setup
=====

Create your virtuan environment and then run `python setup.py develop` in the
root of the module.

example
=======

>>> #!/usr/bin/env python
>>> import time
>>> from libskeleton import Skeleton
>>> def main():
>>>   s = Skeleton()
>>>   sz = 1024 * 1024 * 20
>>>   s.do_something(sz)
>>>   print 'Allocated %s many bytes...' % sz
>>>   while True:
>>>     time.sleep(1)
>>> if __name__ == '__main__':
>>>   main()

