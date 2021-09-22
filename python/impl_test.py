import pytest
from impl import my_function

@pytest.mark.parametrize("input",[0, 1, 2, -5, 9,10])
def test_below_ten(input):
    assert input*2 == my_function(input)

@pytest.mark.parametrize("input", [11,12,500])
def test_above_ten(input):
    assert 42 == my_function(input)