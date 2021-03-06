#!/usr/bin/env python3

import os
import sys
import math

sys.path.append(os.path.join(os.environ['RIOTBASE'], 'dist/tools/testrunner'))
import testrunner


def testfunc(child):
    child.expect_exact('The output should be: yield 1, snd_thread running, '
                       'yield 2, done')
    child.expect_exact('---------------------------------------------------'
                       '-------------')
    child.expect_exact('yield 1')
    child.expect_exact('snd_thread running')
    child.expect_exact('yield 2')
    child.expect_exact('done')

if __name__ == "__main__":
    sys.exit(testrunner.run(testfunc))
