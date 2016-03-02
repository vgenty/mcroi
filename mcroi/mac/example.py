import sys
from ROOT import gSystem
gSystem.Load("libpizeroroi_mcroi")
from ROOT import sample

try:

    print "PyROOT recognized your class %s" % str(sample)

except NameError:

    print "Failed importing mcroi..."

sys.exit(0)

