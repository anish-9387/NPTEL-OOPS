from typing import List, TypeVar

T=TypeVar('T')  # generic type variable

def get_first_element(lst: List[T]) -> T:
    return lst[0]

int_list=[1,2,3]
str_list=["apple","banana","cherry"]

print(get_first_element(int_list))
print(get_first_element(str_list))