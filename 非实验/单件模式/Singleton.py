# -*- coding:UTF-8 -*-

class Singleton(object):
    _instance = None

    def __new__(cls, *args, **kw):
        if not cls._instance:
            cls._instance = super(Singleton, cls).__new__(cls, *args, **kw)
        return cls._instance

singleA = Singleton()
singleB = Singleton()

print singleA == singleB
print singleA is singleB
