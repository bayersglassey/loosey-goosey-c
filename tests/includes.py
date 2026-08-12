
def test_includes():
    """Tests of our stdlib .h files.

        >>> from loosey.mini import MiniC; mini = MiniC()

        Making sure we get the same values I do from gcc on my local machine:
        >>> mini.eval('#include <limits.h>')
        >>> mini.eval('INT8_MIN')
        -128
        >>> mini.eval('INT8_MAX')
        127
        >>> mini.eval('CHAR_MIN')
        -128
        >>> mini.eval('CHAR_MAX')
        127

    """
