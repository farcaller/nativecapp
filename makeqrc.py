#!/usr/bin/env python

## {{{ http://code.activestate.com/recipes/499305/ (r3)
import sys, os, fnmatch

def locate(pattern, root=os.curdir):
    '''Locate all files matching supplied filename pattern in and below
    supplied root directory.'''
    for path, dirs, files in os.walk(os.path.abspath(root), followlinks=True):
        for filename in fnmatch.filter(files, pattern):
            yield os.path.join(path, filename)
## end of http://code.activestate.com/recipes/499305/ }}}

if __name__ == '__main__':
    if len(sys.argv) != 3:
        print "Usage: %s <SOURCE DIRECTORY> <OUTPUT FILE>"
        sys.exit(2)
    
    src = os.path.abspath(sys.argv[1])
    dst = sys.argv[2]
    
    f = open(dst, 'w')
    f.write("<!DOCTYPE RCC><RCC version=\"1.0\">\n<qresource>\n")
    os.chdir(src)
    for fn in locate('*'):
        al = fn.replace(src + '/', '')
        f.write("\t<file alias=\"" + al + "\">" + fn + "</file>\n")
    f.write("</qresource>\n</RCC>")
    f.close()
