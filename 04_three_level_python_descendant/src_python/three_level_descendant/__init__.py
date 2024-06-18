# FIXME currently rpaths aren't working, so if I try to import the _three_level_descendant_pyext
# extension module directly, I get an error: 'libthree_level.so: cannot open shared object file'.
#
# As a workaround, loading the 'three_level' python module will (indirectly) load libthree_level.so .
# Then 'import _three_level_descendant_pyext' will work.

import three_level

from .three_level_descendant_pybind11 import *
