# necessary for our docstrings containing unicode characters
# print(100*'#')
import sys
if sys.version_info[0]==2:
    sys.setdefaultencoding('utf-8')
