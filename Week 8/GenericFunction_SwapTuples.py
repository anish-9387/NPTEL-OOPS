from typing import Tuple, TypeVar

T=TypeVar('T')

def swap_tuple(pair:Tuple[T,T])->Tuple[T,T]:
    return pair[1],pair[0]

int_pair=(10,20)
str_pair=("Hello","World")

print(swap_tuple(int_pair))
print(swap_tuple(str_pair))