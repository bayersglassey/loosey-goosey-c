import sys
from setuptools import setup
from setuptools.command.install import install

class FailInstall(install):
    def run(self):
        print()
        print("****************")
        print("*** WARNING! ***")
        print("****************")
        print()
        print("This is not the package you want to install!")
        print("You should instead install loosey-goosey-c.")
        print()
        print("The reason for this `loosey` package is that `loosey` is the main")
        print("module provided by the package `loosey-goosey-c`, and I want to")
        print("avoid confusion (and package squatting).")
        print()
        print("See also:")
        print("* https://github.com/bayersglassey/loosey-goosey-c")
        print("* https://pypi.org/project/loosey-goosey-c")
        sys.exit(1)

setup(
    cmdclass={
        'install': FailInstall,
    },
)
