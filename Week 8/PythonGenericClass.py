from typing import TypeVar, Generic

T=TypeVar('T')

class Container(Generic[T]):
    def __init__(self,value:T):
        self.value=value;

    def get_value(self)->T:
        return self.value
    
int_container=Container(123)
str_container=Container("Generics in Python")

print(int_container.get_value())
print(str_container.get_value())