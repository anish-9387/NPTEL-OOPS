class Person:
    # self is same as this pointer
    def __init__(self,name,age):
        self.name=name
        self.age=age

    def greet(self):
        return f"Hello, my name is {self.name}"

# Creating an instance
p=Person("Alice", 30)
print(p.greet())